#!/usr/bin/env python3
"""Fail if retail game assets or known retail binary payloads are Git indexed."""

from __future__ import annotations

import hashlib
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BLOCKED_ROOTS = {
    "game_cd", "original", "extracted", "evidence/local",
    "tools/toolchain", "third_party/proprietary",
}
BLOCKED_SUFFIXES = {
    ".exe", ".ovl", ".iso", ".cue", ".bin", ".com", ".dat", ".pic",
    ".rgn", ".mus", ".fnt", ".hlp", ".voc", ".rs",
}


def indexed_paths() -> list[str]:
    result = subprocess.run(
        ["git", "ls-files", "--cached", "-z"], cwd=ROOT,
        check=True, stdout=subprocess.PIPE,
    )
    return [p.decode("utf-8", "surrogateescape")
            for p in result.stdout.split(b"\0") if p]


def is_protected_path(name: str) -> bool:
    path = Path(name)
    normalized = path.as_posix().lower()
    if any(normalized == root or normalized.startswith(root + "/")
           for root in BLOCKED_ROOTS):
        return not (path.name.lower() in {"readme.md", ".gitignore"})
    return path.suffix.lower() in BLOCKED_SUFFIXES


def known_retail_hashes() -> set[str]:
    target = json.loads((ROOT / "config/target.json").read_text())
    return {
        record["sha256"].lower()
        for record in (target["executable"], target["overlay"])
        if record.get("sha256")
    }


def main() -> int:
    paths = indexed_paths()
    offenders = [name for name in paths if is_protected_path(name)]
    hashes = known_retail_hashes()
    for name in paths:
        path = ROOT / name
        if path.is_file() and hashlib.sha256(path.read_bytes()).hexdigest() in hashes:
            offenders.append(name + " (matches pinned retail binary hash)")
    if offenders:
        print("Refusing indexed retail game data:", file=sys.stderr)
        for name in sorted(set(offenders)):
            print(f"  {name}", file=sys.stderr)
        print("Keep user-supplied game files outside Git.", file=sys.stderr)
        return 1
    print(f"No retail game data found in {len(paths)} indexed paths.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
