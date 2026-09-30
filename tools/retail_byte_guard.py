#!/usr/bin/env python3
"""Strict retail byte-run guard for release trees and binaries.

Checks every byte of the given targets against the user's own retail
Companions of Xanth files (XANTH.EXE, XANTH.OVL and every other file in the
data directory) and reports each shared run of 32 bytes or more.  The search
is exhaustive, not sampled: see tools/retail_byte_guard_core.c.

Runs that are 1..4-byte repeating fills (zeros, spaces, 0xFF...), allowing
one stray byte, are classed trivial: counted in the summary, listed with --show-trivial, and never fail
the guard.  Everything else fails it.

Targets may be files or directories (walked recursively, .git skipped) and
zip / tar(.gz/.bz2/.xz) archives, whose members are scanned too.  --git scans
the files git tracks in the current repository.  Symlinks and files that are
themselves reference data are skipped and listed.

Only reads the retail data; nothing is copied or written outside a temporary
directory and the compiled-core cache.

Exit status: 0 no non-trivial runs, 1 runs found, 2 usage/config error.

  retail_byte_guard.py [--data DIR] [--min N] [--json OUT] [--show-trivial] [--git] [TARGET...]
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import shutil
import subprocess
import sys
import tarfile
import tempfile
import zipfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CORE_SRC = HERE / "retail_byte_guard_core.c"


def default_data_dir() -> Path | None:
    candidates = []
    if os.environ.get("XANTH_DATA"):
        candidates.append(Path(os.environ["XANTH_DATA"]))
    candidates.append(Path.home() / "Games" / "companions-of-xanth" / "data")
    candidates.append(ROOT / "game_cd" / "XANTH")
    for c in candidates:
        if (c / "XANTH.EXE").is_file() and (c / "XANTH.OVL").is_file():
            return c
    return None


def build_core() -> Path:
    src = CORE_SRC.read_bytes()
    tag = hashlib.sha256(src).hexdigest()[:16]
    cache = Path(os.environ.get("XDG_CACHE_HOME", Path.home() / ".cache")) / "xanth-retail-guard" / tag
    exe = cache / ("core.exe" if os.name == "nt" else "core")
    if exe.is_file():
        return exe
    cache.mkdir(parents=True, exist_ok=True)
    cc = os.environ.get("CC", "cc")
    tmp = exe.with_suffix(".tmp")
    subprocess.run([cc, "-O2", "-o", str(tmp), str(CORE_SRC)], check=True)
    tmp.replace(exe)
    return exe


def is_archive(path: Path) -> bool:
    name = path.name.lower()
    if name.endswith((".zip", ".tar", ".tar.gz", ".tgz", ".tar.bz2", ".tbz2", ".tar.xz", ".txz")):
        return zipfile.is_zipfile(path) or tarfile.is_tarfile(path)
    return False


def extract_archive(path: Path, label: str, dest: Path, out: list, skipped: list) -> None:
    dest.mkdir(parents=True, exist_ok=True)
    if zipfile.is_zipfile(path):
        with zipfile.ZipFile(path) as z:
            for i, info in enumerate(z.infolist()):
                if info.is_dir():
                    continue
                target = dest / f"{i:06d}"
                with z.open(info) as src, open(target, "wb") as dst:
                    shutil.copyfileobj(src, dst)
                add_file(target, f"{label}!{info.filename}", dest / f"{i:06d}.x", out, skipped)
    else:
        with tarfile.open(path) as t:
            for i, member in enumerate(t.getmembers()):
                if member.issym() or member.islnk():
                    skipped.append((f"{label}!{member.name}", "link in archive"))
                    continue
                if not member.isfile():
                    continue
                src = t.extractfile(member)
                if src is None:
                    continue
                target = dest / f"{i:06d}"
                with src, open(target, "wb") as dst:
                    shutil.copyfileobj(src, dst)
                add_file(target, f"{label}!{member.name}", dest / f"{i:06d}.x", out, skipped)


def add_file(path: Path, label: str, scratch: Path, out: list, skipped: list) -> None:
    if path.stat().st_size == 0:
        return
    if is_archive(path):
        extract_archive(path, label, scratch, out, skipped)
    out.append((str(path), label))


def collect(targets, use_git: bool, ref_real: set, scratch: Path):
    files, skipped = [], []
    paths = [Path(t) for t in targets]
    if use_git:
        listing = subprocess.run(["git", "ls-files", "-z"], cwd=ROOT, check=True,
                                 stdout=subprocess.PIPE).stdout.decode().split("\0")
        paths += [ROOT / p for p in listing if p]
    counter = 0
    for p in paths:
        walk = [p] if not p.is_dir() or p.is_symlink() else None
        if walk is None:
            walk = []
            for dirpath, dirnames, filenames in os.walk(p):
                dirnames[:] = [d for d in dirnames if d != ".git"
                               and not Path(dirpath, d).is_symlink()]
                walk += [Path(dirpath, f) for f in sorted(filenames)]
                skipped += [(str(Path(dirpath, d)), "symlinked directory")
                            for d in os.listdir(dirpath)
                            if Path(dirpath, d).is_dir() and Path(dirpath, d).is_symlink()]
        for f in walk:
            if f.is_symlink():
                skipped.append((str(f), "symlink"))
                continue
            if not f.is_file():
                continue
            if os.path.realpath(f) in ref_real:
                skipped.append((str(f), "is reference data"))
                continue
            counter += 1
            add_file(f, str(f), scratch / f"a{counter:06d}", files, skipped)
    return files, skipped


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("targets", nargs="*")
    ap.add_argument("--data", help="retail data directory (default: $XANTH_DATA, "
                    "~/Games/companions-of-xanth/data, then game_cd/XANTH)")
    ap.add_argument("--min", type=int, default=32, help="minimum run length (default 32, >= 31)")
    ap.add_argument("--json", help="write every run (trivial included) as JSON here")
    ap.add_argument("--show-trivial", action="store_true", help="also list 1..4-byte fill runs")
    ap.add_argument("--git", action="store_true", help="scan the files git tracks in this repo")
    args = ap.parse_args(argv)

    if not args.targets and not args.git:
        ap.error("give TARGET paths and/or --git")
    if args.min < 31:
        ap.error("--min must be at least 31 (the index guarantees completeness from 31 bytes)")
    data = Path(args.data) if args.data else default_data_dir()
    if not data or not (data / "XANTH.EXE").is_file() or not (data / "XANTH.OVL").is_file():
        print("[retail-guard] retail data not found (need XANTH.EXE and XANTH.OVL); "
              "use --data or XANTH_DATA", file=sys.stderr)
        return 2
    refs = sorted(p for p in data.rglob("*") if p.is_file())
    ref_real = {os.path.realpath(p) for p in refs}
    ref_bytes = sum(p.stat().st_size for p in refs)

    try:
        core = build_core()
    except (OSError, subprocess.CalledProcessError) as exc:
        print(f"[retail-guard] cannot build the scanner core: {exc}", file=sys.stderr)
        return 2

    with tempfile.TemporaryDirectory(prefix="xanth-retail-guard-") as tmp:
        scratch = Path(tmp)
        files, skipped = collect(args.targets, args.git, ref_real, scratch / "x")
        for path, why in skipped:
            print(f"[retail-guard] skipped {path}: {why}", file=sys.stderr)
        if not files:
            print("[retail-guard] nothing to scan", file=sys.stderr)
            return 2
        (scratch / "refs.txt").write_text("".join(f"{p}\n" for p in refs))
        (scratch / "targets.txt").write_text("".join(f"{p}\n" for p, _ in files))
        proc = subprocess.run([str(core), "--refs", str(scratch / "refs.txt"),
                               "--targets", str(scratch / "targets.txt"), "--min", str(args.min)],
                              stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if proc.returncode != 0:
            print(proc.stderr, file=sys.stderr)
            return 2

    runs = []
    for line in proc.stdout.splitlines():
        t, toff, n, r, roff, trivial = (int(x) for x in line.split("\t"))
        runs.append({"target": files[t][1], "offset": toff, "bytes": n,
                     "ref": str(refs[r].relative_to(data)), "ref_offset": roff,
                     "trivial": bool(trivial)})
    real = [r for r in runs if not r["trivial"]]
    for r in runs:
        if r["trivial"] and not args.show_trivial:
            continue
        kind = "RETAIL-FILL" if r["trivial"] else "RETAIL-DATA"
        print(f"{kind} {r['target']}+0x{r['offset']:X}: {r['bytes']} bytes match "
              f"{r['ref']}+0x{r['ref_offset']:X}")
    if args.json:
        Path(args.json).write_text(json.dumps(runs, indent=1))
    summary = (f"{len(files)} file(s) against {len(refs)} reference file(s) "
               f"({ref_bytes} bytes); {len(runs) - len(real)} trivial fill run(s) ignored")
    if real:
        total = sum(r["bytes"] for r in real)
        print(f"[retail-guard] FAIL: {len(real)} retail run(s), {total} bytes; {summary}",
              file=sys.stderr)
        return 1
    print(f"[retail-guard] OK: no retail runs of {args.min}+ bytes; {summary}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
