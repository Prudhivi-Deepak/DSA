import os
import re
import time
import argparse
from urllib.parse import urljoin
import requests

TOCTREE_LINE = re.compile(r"^\.\.\s+toctree::\s*$")

def rst_ref_to_sources_txt(ref: str) -> str | None:
    ref = ref.strip()
    ref = ref.split("#", 1)[0].strip()  # remove inline comments
    if not ref or "://" in ref:
        return None
    if ref.startswith(":"):
        return None
    if not ref.endswith(".rst"):
        ref += ".rst"
    return ref + ".txt"

def extract_toctree_entries(text: str):
    lines = text.splitlines()
    refs = []
    i = 0
    while i < len(lines):
        if TOCTREE_LINE.match(lines[i].strip()):
            i += 1

            # Collect indented block after toctree
            while i < len(lines):
                line = lines[i]

                # End block on non-indented non-empty line
                if line.strip() and (len(line) == len(line.lstrip())):
                    break

                stripped = line.strip()

                # skip empty
                if not stripped:
                    i += 1
                    continue

                # skip options like :maxdepth:
                if stripped.startswith(":"):
                    i += 1
                    continue

                refs.append(stripped)
                i += 1
        else:
            i += 1
    return refs

def save_file(out_dir: str, rel_path: str, text: str):
    path = os.path.join(out_dir, rel_path)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)

def fetch_text(session: requests.Session, url: str, timeout: int):
    r = session.get(url, timeout=timeout)
    r.raise_for_status()
    r.encoding = r.encoding or "utf-8"
    return r.text

def crawl(base_sources_url: str, start: str, out: str, sleep_s: float, timeout: int, max_files: int):
    base_sources_url = base_sources_url.rstrip("/") + "/"
    visited = set()
    queue = [start.lstrip("/")]

    with requests.Session() as s:
        s.headers["User-Agent"] = "rst-toctree-crawler/1.1 (polite downloader)"

        count = 0
        while queue:
            rel = queue.pop(0)
            if rel in visited:
                continue
            visited.add(rel)

            url = urljoin(base_sources_url, rel)
            try:
                text = fetch_text(s, url, timeout)
            except Exception as e:
                print(f"[WARN] fetch failed: {url} -> {e}")
                continue

            save_file(out, rel, text)
            count += 1
            print(f"[OK] saved ({count}): {rel}")

            if count >= max_files:
                print(f"[STOP] max_files reached: {max_files}")
                break

            refs = extract_toctree_entries(text)
            if refs:
                print(f"     discovered {len(refs)} children from {rel}:")
                for r in refs[:20]:
                    print(f"       - {r}")
                if len(refs) > 20:
                    print("       - ...")

            for r in refs:
                target = rst_ref_to_sources_txt(r)
                if not target:
                    continue
                target = target.lstrip("/")
                # skip glob patterns (needs extra logic)
                if any(ch in target for ch in ["*", "?", "["]):
                    print(f"[WARN] glob not expanded automatically: {r}")
                    continue
                if target not in visited:
                    queue.append(target)

            if sleep_s:
                time.sleep(sleep_s)

    print("\nDONE")
    print(f"Total downloaded: {count}")
    print(f"Saved in: {os.path.abspath(out)}")

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", default="https://scikit-learn.org/stable/_sources/")
    ap.add_argument("--start", default="user_guide.rst.txt")
    ap.add_argument("--out", default="sklearn_sources")
    ap.add_argument("--sleep", type=float, default=0.2)
    ap.add_argument("--timeout", type=int, default=30)
    ap.add_argument("--max-files", type=int, default=10000)
    args = ap.parse_args()

    crawl(args.base, args.start, args.out, args.sleep, args.timeout, args.max_files)

if __name__ == "__main__":
    main()