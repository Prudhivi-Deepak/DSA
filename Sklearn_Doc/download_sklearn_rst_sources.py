import os
import re
import time
import argparse
from urllib.parse import urljoin

import requests

try:
    import urllib3
except ImportError:
    urllib3 = None


TOCTREE_DIRECTIVE_RE = re.compile(r"^\.\.\s+toctree::\s*$")
DIRECTIVE_LINE_RE = re.compile(r"^\.\.\s+(\w+)::\s*(.+?)\s*$")  # ".. include:: path"


def normalize_ref(ref: str) -> str:
    ref = ref.strip()
    ref = ref.split("#", 1)[0].strip()
    return ref


def is_external(ref: str) -> bool:
    return "://" in ref or ref.startswith("mailto:")


def to_sources_rst_txt(ref: str):
    """
    Convert:
      supervised_learning.rst    -> supervised_learning.rst.txt
      modules/svm                -> modules/svm.rst.txt
      foo.rst.txt                -> foo.rst.txt
    """
    ref = normalize_ref(ref)
    if not ref or is_external(ref) or ref.startswith(":"):
        return None

    if ref.endswith(".rst.txt"):
        return ref.lstrip("/")

    if ref.endswith(".rst"):
        return (ref + ".txt").lstrip("/")

    return (ref + ".rst.txt").lstrip("/")


def leading_spaces(s: str) -> int:
    return len(s) - len(s.lstrip(" "))


def extract_toctree_entries(rst_text: str):
    """
    Robust parser for:
      .. toctree::
         :maxdepth: 3

         a.rst
         b
         subdir/c

    Key: allows blank lines inside the indented block and only ends when dedented.
    """
    lines = rst_text.splitlines()
    i = 0
    refs = []

    while i < len(lines):
        if TOCTREE_DIRECTIVE_RE.match(lines[i].strip()):
            i += 1

            # Determine block indent: find first non-empty line that is indented
            block_indent = None
            j = i
            while j < len(lines):
                if lines[j].strip() == "":
                    j += 1
                    continue
                sp = leading_spaces(lines[j])
                if sp == 0:
                    # No indented block => empty toctree
                    break
                block_indent = sp
                break

            # If we couldn't find an indented block, continue scanning
            if block_indent is None:
                i = j
                continue

            # Now consume all lines with indent >= block_indent (blank lines allowed)
            while i < len(lines):
                line = lines[i]

                # Always allow blank lines inside block
                if line.strip() == "":
                    i += 1
                    continue

                sp = leading_spaces(line)
                if sp < block_indent:
                    # Dedent => end of this toctree block
                    break

                content = line.strip()

                # Skip options
                if content.startswith(":"):
                    i += 1
                    continue

                refs.append(content)
                i += 1

            # Continue scanning after this toctree block
            continue

        i += 1

    return refs


def extract_include_targets(rst_text: str):
    """
    Extract targets of '.. include:: something.rst'
    """
    targets = []
    for line in rst_text.splitlines():
        m = DIRECTIVE_LINE_RE.match(line.strip())
        if not m:
            continue
        name = m.group(1).lower()
        target = m.group(2).strip()
        if name == "include":
            targets.append(target)
    return targets


def save_text(output_dir: str, rel_path: str, text: str):
    rel_path = rel_path.lstrip("/").replace("\\", "/")
    full_path = os.path.join(output_dir, rel_path)
    os.makedirs(os.path.dirname(full_path), exist_ok=True)
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(text)


def fetch_text(session: requests.Session, url: str, timeout: int, verify):
    r = session.get(url, timeout=timeout, verify=verify)
    r.raise_for_status()
    r.encoding = r.encoding or "utf-8"
    return r.text


def crawl(base_sources_url: str,
          start: str,
          out_dir: str,
          sleep_s: float,
          timeout: int,
          max_files: int,
          verify,
          follow_include: bool,
          retries: int,
          backoff: float,
          debug: bool):
    base_sources_url = base_sources_url.rstrip("/") + "/"
    start = start.lstrip("/")

    visited = set()
    queue = [start]
    downloaded = 0

    with requests.Session() as session:
        session.headers.update({"User-Agent": "rst-sphinx-crawler/2.0 (polite downloader)"})

        while queue:
            rel = queue.pop(0).lstrip("/")
            if rel in visited:
                continue
            visited.add(rel)

            url = urljoin(base_sources_url, rel)

            # Retry loop
            last_err = None
            for attempt in range(retries + 1):
                try:
                    text = fetch_text(session, url, timeout=timeout, verify=verify)
                    last_err = None
                    break
                except requests.RequestException as e:
                    last_err = e
                    if attempt < retries:
                        time.sleep(backoff * (2 ** attempt))

            if last_err is not None:
                print(f"[WARN] fetch failed: {url} -> {last_err}")
                continue

            save_text(out_dir, rel, text)
            downloaded += 1

            # Extract refs
            toctree_refs = extract_toctree_entries(text)
            include_refs = extract_include_targets(text) if follow_include else []

            if debug:
                print(f"[DBG] {rel}: toctree={len(toctree_refs)}, include={len(include_refs)}")

            # Queue toctree targets
            for ref in toctree_refs:
                target = to_sources_rst_txt(ref)
                if not target:
                    continue
                # skip glob patterns (can be added later)
                if any(ch in target for ch in ["*", "?", "["]):
                    if debug:
                        print(f"[DBG] glob skipped: {ref}")
                    continue
                if target not in visited:
                    queue.append(target)

            # Queue include targets (only .rst -> .rst.txt)
            if follow_include:
                for ref in include_refs:
                    inc = normalize_ref(ref)
                    if not inc or is_external(inc) or inc.startswith(":"):
                        continue
                    if inc.endswith(".rst"):
                        target = (inc + ".txt").lstrip("/")
                        if target not in visited:
                            queue.append(target)

            print(f"[OK] {downloaded:4d} saved: {rel} | queue={len(queue)}")

            if downloaded >= max_files:
                print(f"[STOP] Reached max_files={max_files}")
                break

            if sleep_s:
                time.sleep(sleep_s)

    print("\nDONE")
    print(f"Total downloaded: {downloaded}")
    print(f"Saved in: {os.path.abspath(out_dir)}")


def main():
    parser = argparse.ArgumentParser(
        description="Recursively download scikit-learn Sphinx RST sources from _sources/*.rst.txt by following toctree/include."
    )
    parser.add_argument("--base", default="https://scikit-learn.org/stable/_sources/",
                        help="Base _sources URL")
    parser.add_argument("--start", default="user_guide.rst.txt",
                        help="Start file, e.g. user_guide.rst.txt or index.rst.txt")
    parser.add_argument("--out", default="sklearn_sources",
                        help="Output folder")

    parser.add_argument("--sleep", type=float, default=0.15,
                        help="Sleep between requests in seconds")
    parser.add_argument("--timeout", type=int, default=30,
                        help="HTTP timeout seconds")
    parser.add_argument("--max-files", type=int, default=20000,
                        help="Safety cap on downloads")

    parser.add_argument("--retries", type=int, default=3,
                        help="Retries per file")
    parser.add_argument("--backoff", type=float, default=0.6,
                        help="Backoff base seconds")

    parser.add_argument("--follow-include", action="store_true",
                        help="Also follow '.. include::' directives.")
    parser.add_argument("--debug", action="store_true",
                        help="Print debug counts for extracted refs per file.")

    parser.add_argument("--insecure", action="store_true",
                        help="Disable SSL verification (useful behind corporate SSL interception).")
    parser.add_argument("--ca-bundle", default=None,
                        help="Path to CA bundle PEM for secure SSL verification.")

    args = parser.parse_args()

    if args.insecure:
        verify = False
        if urllib3 is not None:
            urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
    elif args.ca_bundle:
        verify = args.ca_bundle
    else:
        verify = True

    crawl(
        base_sources_url=args.base,
        start=args.start,
        out_dir=args.out,
        sleep_s=args.sleep,
        timeout=args.timeout,
        max_files=args.max_files,
        verify=verify,
        follow_include=args.follow_include,
        retries=args.retries,
        backoff=args.backoff,
        debug=args.debug,
    )


if __name__ == "__main__":
    main()