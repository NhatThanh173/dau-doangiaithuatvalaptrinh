"""
Đổi tên file dạng cũ sang đúng format LeetCode trên Windows:

  bai{stt}_{id}.cpp  ->  "{id}. {Tiêu đề bài}.cpp"

- {stt}: số thứ tự nội bộ của bạn (không còn trong tên mới).
- {id}:  frontend_question_id trên LeetCode (ví dụ 200 = Number of Islands).

Tên bài lấy từ API công khai của LeetCode. Nếu hai file cùng một {id},
tên mới thêm hậu tố: "{id}. {Title} - {tên_file_cũ_không_đuôi}.cpp"
để không ghi đè nhau (ví dụ hai bản Plus One 66).

Chạy từ thư mục gốc repo:

  python tools/rename_leetcode_files.py

Các file bai1.cpp ... bai9.cpp (không có _{id}) không bị đổi tên.
"""
from __future__ import annotations

import json
import re
import urllib.request
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PATTERN = re.compile(r"^bai(\d+)_(\d+)\.cpp$")

# Windows reserved names and invalid filename chars
INVALID_CHARS = r'<>:"/\\|?*'


def sanitize_title(title: str) -> str:
    t = title.strip()
    for ch in INVALID_CHARS:
        t = t.replace(ch, "")
    t = re.sub(r"\s+", " ", t)
    return t


def fetch_titles_by_frontend_id() -> dict[int, str]:
    url = "https://leetcode.com/api/problems/all/"
    req = urllib.request.Request(
        url,
        headers={"User-Agent": "Mozilla/5.0 (compatible; rename-script/1.0)"},
    )
    with urllib.request.urlopen(req, timeout=60) as resp:
        data = json.load(resp)

    out: dict[int, str] = {}
    for p in data.get("stat_status_pairs", []):
        stat = p.get("stat", {})
        fid = stat.get("frontend_question_id")
        title = stat.get("question__title")
        if fid is None or not title:
            continue
        try:
            out[int(fid)] = str(title)
        except (TypeError, ValueError):
            continue
    return out


def main() -> None:
    id_to_files: dict[int, list[Path]] = defaultdict(list)
    for path in sorted(ROOT.glob("bai*_*.cpp")):
        m = PATTERN.match(path.name)
        if not m:
            continue
        lc_id = int(m.group(2))
        id_to_files[lc_id].append(path)

    titles = fetch_titles_by_frontend_id()

    renames: list[tuple[Path, Path]] = []
    for lc_id, paths in sorted(id_to_files.items()):
        title = titles.get(lc_id, f"Problem {lc_id}")
        safe_title = sanitize_title(title)
        base = f"{lc_id}. {safe_title}.cpp"

        if len(paths) == 1:
            src = paths[0]
            dst = ROOT / base
            if dst.resolve() != src.resolve():
                renames.append((src, dst))
            continue

        for src in sorted(paths, key=lambda p: p.name):
            stem = src.stem  # bai14_66
            dst = ROOT / f"{lc_id}. {safe_title} - {stem}.cpp"
            if dst.resolve() != src.resolve():
                renames.append((src, dst))

    # Resolve collisions (same target from different sources — should not happen)
    used: set[str] = set()
    final: list[tuple[Path, Path]] = []
    for src, dst in renames:
        name = dst.name
        if name not in used:
            used.add(name)
            final.append((src, dst))
            continue
        i = 2
        while True:
            alt = dst.with_name(dst.stem + f" ({i})" + dst.suffix)
            if alt.name not in used:
                used.add(alt.name)
                final.append((src, alt))
                break
            i += 1

    for src, dst in final:
        if dst.exists() and dst.resolve() != src.resolve():
            raise SystemExit(f"Target exists, abort: {dst}")
        print(f"{src.name} -> {dst.name}")

    if not final:
        print("No files matching bai{stt}_{id}.cpp found; nothing to do.")
        return

    for src, dst in final:
        src.rename(dst)

    print(f"Renamed {len(final)} file(s).")


if __name__ == "__main__":
    main()
