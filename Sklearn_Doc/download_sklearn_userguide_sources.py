import os
import re
import time
import argparse
from urllib.parse import urljoin, urlparse

import requests

try:
    import urllib3
except ImportError:
    urllib3 = None


# --- Regex patterns ---
TOCTREE_START_RE = re.compile(r"^\.\.\s+toctree::\s*$")
DIRECTIVE_LINE_RE = re.compile(r"^\.\.\s+(\w+)::\s*(.+?)\s*$")  # e.g. ".. include:: path"
INDENTED_LINE_RE = re.compile(r"^(\s+)(\S.*)$")


def normalize_ref(ref: str) -> str:
    """Remove inline comments and surrounding whitespace."""
    ref = ref.strip()
    ref = ref.split("#", 1)[0].strip()
    return ref


def is_external(ref: str) -> bool:
    return "://" in ref or ref.startswith("mailto:")


def to_sources_rst_txt(ref: str) -> str | None:
    """
    Convert a Sphinx ref (like 'supervised_learning.rst' or 'modules/svm')
    into '_sources/..../something.rst.txt' relative path.
    """
    ref = normalize_ref(ref)
    if not ref or is_external(ref) or ref.startswith(":"):
        return None

    # If it already looks like a .rst.txt source path, keep it
    if ref.endswith(".rst.txt"):
        return ref.lstrip("/")

    # If it is a .rst, convert to .rst.txt
    if ref.endswith(".rst"):
        return (ref + ".txt").lstrip("/")

    # Many toctree entries omit extension; assume .rst
    return (ref + ".rst.txt").lstrip("/")


def to_sources_asset_txt(ref: str) -> str | None:
    """
    For include/literalinclude, ref can be relative path to .rst or other assets.
    We'll try:
      - if endswith .rst -> .rst.txt (under _sources)
      - else: keep as-is as a path under _sources (often not available).
    """
    ref = normalize_ref(ref)
    if not ref or is_external(ref) or ref.startswith(":"):
        return None

    if ref.endswith(".rst"):
        return (ref + ".txt").lstrip("/")

    # Many literalinclude target files are not under _sources; they can be in repo.
    # For scikit-learn website _sources, only .rst sources are usually there.
    # We'll still return it as-is so user can see warnings if not found.
    return ref.lstrip("/")


def extract_toctree_entries(rst_text: str):
    """
    Parse all '.. toctree::' blocks and return toctree entry refs.
    """
    lines = rst_text.splitlines()
    i = 0
    refs = []

    while i < len(lines):
        if TOCTREE_START_RE.match(lines[i].strip()):
            i += 1
            while i < len(lines):
                m = INDENTED_LINE_RE.match(lines[i])
                if not m:
                    break

                content = m.group(2).strip()

                # Skip toctree options (:maxdepth:, :caption:, :numbered:, :glob:, etc.)
                if not content or content.startswith(":"):
                    i += 1
                    continue

                refs.append(content)
                i += 1
        else:
            i += 1

    return refs


def extract_directive_targets(rst_text: str, directive_names=("include",)):
    """
    Extract targets of directives like:
      .. include:: some_file.rst
      .. literalinclude:: ../path/code.py
    Returns list of raw targets.
    """
    targets = []
    for line in rst_text.splitlines():
        m = DIRECTIVE_LINE_RE.match(line.strip())
        if not m:
            continue
        name = m.group(1).lower()
        target = m.group(2).strip()
        if name in directive_names:
            targets.append(target)
    return targets


def ensure_parent_dir(path: str):
    os.makedirs(os.path.dirname(path), exist_ok=True)


def save_text(output_dir: str, rel_path: str, text: str):
    rel_path = rel_path.lstrip("/").replace("\\", "/")
    full_path = os.path.join(output_dir, rel_path)
    ensure_parent_dir(full_path)
    with open(full_path, "w", encoding="utf-8") as f:
        f.write(text)


def fetch_text(session: requests.Session, url: str, timeout: int, verify):
    r = session.get(url, timeout=timeout, verify=verify)
    r.raise_for_status()
    r.encoding = r.encoding or "utf-8"
    return r.text


def crawl(
    base_sources_url: str,
    start: str,
    out_dir: str,
    sleep_s: float,
    timeout: int,
    max_files: int,
    verify,
    follow_include: bool,
    follow_literalinclude: bool,
    retries: int,
    backoff: float,
):
    base_sources_url = base_sources_url.rstrip("/") + "/"
    start = start.lstrip("/")

    visited = set()
    queue = [start]
    downloaded = 0

    with requests.Session() as session:
        session.headers.update({"User-Agent": "rst-sphinx-crawler/1.1 (polite downloader)"})

        while queue:
            rel = queue.pop(0).lstrip("/")
            if rel in visited:
                continue
            visited.add(rel)

            url = urljoin(base_sources_url, rel)

            # Retry loop for transient failures
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
                    else:
                        break

            if last_err is not None:
                print(f"[WARN] fetch failed: {url} -> {last_err}")
                continue

            save_text(out_dir, rel, text)
            downloaded += 1
            print(f"[OK] {downloaded:4d} saved: {rel}")

            if downloaded >= max_files:
                print(f"[STOP] Reached max_files={max_files}")
                break

            # --- toctree recursion ---
            for ref in extract_toctree_entries(text):
                target = to_sources_rst_txt(ref)
                if not target:
                    continue
                if any(ch in target for ch in ["*", "?", "["]):  # glob patterns not expanded
                    print(f"[WARN] glob pattern not expanded automatically (skipped): {ref}")
                    continue
                if target not in visited:
                    queue.append(target)

            # --- include recursion (optional) ---
            if follow_include:
                for ref in extract_directive_targets(text, directive_names=("include",)):
                    target = to_sources_asset_txt(ref)
                    if not target:
                        continue
                    # include usually points to .rst, so convert to .rst.txt if needed
                    if target.endswith(".rst"):
                        target = (target + ".txt")
                    if target.endswith(".rst.txt") and target not in visited:
                        queue.append(target)

            # --- literalinclude (optional) ---
            if follow_literalinclude:
                for ref in extract_directive_targets(text, directive_names=("literalinclude",)):
                    # These often won't exist under _sources/ on the website.
                    target = to_sources_asset_txt(ref)
                    if not target:
                        continue
                    # We'll attempt anyway; most will warn 404, but you asked "everything".
                    if target not in visited:
                        queue.append(target)

            if sleep_s:
                time.sleep(sleep_s)

    print("\nDONE")
    print(f"Total downloaded: {downloaded}")
    print(f"Saved in: {os.path.abspath(out_dir)}")


def main():
    parser = argparse.ArgumentParser(
        description="Recursively download scikit-learn Sphinx RST sources from _sources/*.rst.txt by following toctree/include directives."
    )
    parser.add_argument("--base", default="https://scikit-learn.org/stable/_sources/",
                        help="Base _sources URL (default: https://scikit-learn.org/stable/_sources/)")
    parser.add_argument("--start", default="user_guide.rst.txt",
                        help="Start file (default: user_guide.rst.txt)")
    parser.add_argument("--out", default="sklearn_sources",
                        help="Output folder (default: sklearn_sources)")

    # SSL / Proxy controls
    parser.add_argument("--insecure", action="store_true",
                        help="Disable SSL verification (works behind SSL interception; less secure).")
    parser.add_argument("--ca-bundle", default=None,
                        help="Path to a CA bundle PEM file for SSL verification (best for corp networks).")
    parser.add_argument("--proxy", default=None,
                        help="Proxy URL, e.g. http://user:pass@proxy:port (optional).")

    # Crawl controls
    parser.add_argument("--sleep", type=float, default=0.15,
                        help="Sleep between requests in seconds (default: 0.15)")
    parser.add_argument("--timeout", type=int, default=30,
                        help="HTTP timeout seconds (default: 30)")
    parser.add_argument("--max-files", type=int, default=20000,
                        help="Safety cap on downloads (default: 20000)")
    parser.add_argument("--retries", type=int, default=3,
                        help="Retries per file (default: 3)")
    parser.add_argument("--backoff", type=float, default=0.6,
                        help="Backoff base seconds for retries (default: 0.6)")

    # Directive following
    parser.add_argument("--follow-include", action="store_true",
                        help="Also follow '.. include::' directives (recommended).")
    parser.add_argument("--follow-literalinclude", action="store_true",
                        help="Also follow '.. literalinclude::' directives (may 404 on website).")

    args = parser.parse_args()

    # Decide verify mode
    if args.insecure:
        verify = False
        if urllib3 is not None:
            urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)
    elif args.ca_bundle:
        verify = args.ca_bundle
    else:
        verify = True

    # Proxy support
    if args.proxy:
        os.environ["HTTPS_PROXY"] = args.proxy
        os.environ["HTTP_PROXY"] = args.proxy

    crawl(
        base_sources_url=args.base,
        start=args.start,
        out_dir=args.out,
        sleep_s=args.sleep,
        timeout=args.timeout,
        max_files=args.max_files,
        verify=verify,
        follow_include=args.follow_include,
        follow_literalinclude=args.follow_literalinclude,
        retries=args.retries,
        backoff=args.backoff,
    )


if __name__ == "__main__":
    main()