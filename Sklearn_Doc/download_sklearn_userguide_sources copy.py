import os
import re
import time
import argparse
from urllib.parse import urljoin

import requests

# Optional: suppress warnings when using --insecure
try:
    import urllib3
except ImportError:
    urllib3 = None


TOCTREE_START_RE = re.compile(r"^\.\.\s+toctree::\s*$")
INDENTED_LINE_RE = re.compile(r"^(\s+)(\S.*)$")


def rst_ref_to_sources_txt(ref: str) -> str | None:
    ref = ref.strip()
    ref = ref.split("#", 1)[0].strip()

    if not ref or "://" in ref or ref.startswith(":"):
        return None

    if not ref.endswith(".rst"):
        ref = ref + ".rst"

    return ref + ".txt"


def extract_toctree_entries(rst_text: str):
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

                # skip toctree options like :maxdepth:, :numbered:, :glob:
                if content.startswith(":") or not content:
                    i += 1
                    continue

                refs.append(content)
                i += 1
        else:
            i += 1

    return refs


def save_file(output_dir: str, rel_path: str, text: str):
    path = os.path.join(output_dir, rel_path)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)


def fetch_text(session: requests.Session, url: str, timeout: int, verify_ssl: bool) -> str:
    r = session.get(url, timeout=timeout, verify=verify_ssl)
    r.raise_for_status()
    r.encoding = r.encoding or "utf-8"
    return r.text


def crawl_sources(base_sources_url: str,
                  start_file: str,
                  output_dir: str,
                  sleep_s: float,
                  max_files: int,
                  timeout: int,
                  verify_ssl: bool):
    base_sources_url = base_sources_url.rstrip("/") + "/"

    visited = set()
    queue = [start_file]
    downloaded = 0

    with requests.Session() as session:
        session.headers.update({
            "User-Agent": "rst-toctree-crawler/1.0 (polite downloader)"
        })

        while queue:
            rel = queue.pop(0).lstrip("/")

            if rel in visited:
                continue
            visited.add(rel)

            url = urljoin(base_sources_url, rel)

            try:
                text = fetch_text(session, url, timeout=timeout, verify_ssl=verify_ssl)
            except requests.RequestException as e:
                print(f"[WARN] Failed to fetch: {url} -> {e}")
                continue

            save_file(output_dir, rel, text)
            downloaded += 1
            print(f"[OK] {downloaded:4d} saved: {rel}")

            if downloaded >= max_files:
                print(f"[STOP] Reached max_files={max_files}")
                break

            refs = extract_toctree_entries(text)

            for ref in refs:
                target = rst_ref_to_sources_txt(ref)
                if not target:
                    continue

                target = target.lstrip("/")

                # skip glob patterns unless you want expansion logic
                if any(ch in target for ch in ["*", "?", "["]):
                    print(f"[WARN] Glob pattern not expanded automatically: {ref}")
                    continue

                if target not in visited:
                    queue.append(target)

            if sleep_s:
                time.sleep(sleep_s)

    print("\nDone.")
    print(f"Downloaded files: {downloaded}")
    print(f"Visited references: {len(visited)}")
    print(f"Saved under: {os.path.abspath(output_dir)}")


def main():
    parser = argparse.ArgumentParser(
        description="Recursively download Sphinx toctree .rst sources from _sources/ as .rst.txt files."
    )
    parser.add_argument("--base", default="https://scikit-learn.org/stable/_sources/",
                        help="Base _sources URL (default: scikit-learn stable _sources)")
    parser.add_argument("--start", default="user_guide.rst.txt",
                        help="Starting .rst.txt file in _sources (default: user_guide.rst.txt)")
    parser.add_argument("--out", default="sklearn_sources",
                        help="Output directory (default: sklearn_sources)")
    parser.add_argument("--sleep", type=float, default=0.2,
                        help="Sleep seconds between requests (default: 0.2)")
    parser.add_argument("--max-files", type=int, default=10000,
                        help="Safety limit for maximum downloads (default: 10000)")
    parser.add_argument("--timeout", type=int, default=30,
                        help="HTTP timeout seconds (default: 30)")
    parser.add_argument("--insecure", action="store_true",
                        help="Disable SSL certificate verification (use only if you trust your network).")

    args = parser.parse_args()

    if args.insecure and urllib3 is not None:
        urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

    crawl_sources(
        base_sources_url=args.base,
        start_file=args.start,
        output_dir=args.out,
        sleep_s=args.sleep,
        max_files=args.max_files,
        timeout=args.timeout,
        verify_ssl=not args.insecure
    )


if __name__ == "__main__":
    main()