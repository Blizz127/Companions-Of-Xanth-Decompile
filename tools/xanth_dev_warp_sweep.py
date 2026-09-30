#!/usr/bin/env python3
"""Verify dev-menu warp checkpoints with live runs (shared spec section 6).

For every checkpoint in <checkpoint dir>/checkpoints.txt this starts a
fresh game in xanth_port's own real-time loop (no scheduler, no save
loaded), presses Space through the logo, opening and title, opens the dev
menu with its harness keys, walks Warp > region > area > spot, and lets the
warp drive the game's own Restore dialog. A target passes when:
  - the menu reports "Warped to <spot>" and never a refusal or failure;
  - the final guest frame matches the checkpoint's reference screenshot in
    the picture and inventory areas (animation allowed: <= 3% of pixels);
  - the game-state observer reports field-idle at the end of the run.
Per-target JSON, logs and frames go to <checkpoint dir>/sweep/, and the
summary prints VERIFIED n/m. Passing entries are marked verified in
checkpoints.txt (unless --dry-run); failing ones are marked unverified.

  xanth_dev_warp_sweep.py --port build/xanth_port [--data DIR] [--checkpoints DIR] [--only ID ...]
"""
from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
from xanth_dev_checkpoints import default_data, default_out, read_list, write_list  # noqa: E402

BOOT_KEYS = [300, 1500, 2700]          # logo, opening, title
MENU_AT = 3200
FRAMES = 5200
PICTURE = (51, 4, 314, 110)            # room picture, above the hover label band
INVENTORY = (88, 152, 287, 195)
MAX_DIFF = 0.03


def pixels(path: Path):
    data = path.read_bytes()
    off = int.from_bytes(data[10:14], "little")
    return data[off:]


def diff_fraction(a: bytes, b: bytes, box) -> float:
    x0, y0, x1, y1 = box
    total = changed = 0
    for y in range(y0, y1 + 1):
        row = (199 - y) * 960
        for x in range(x0, x1 + 1):
            i = row + 3 * x
            total += 1
            changed += a[i:i + 3] != b[i:i + 3]
    return changed / total


def menu_keys(rows, target) -> list[str]:
    """Harness keys that walk the dev menu to `target` in list order."""
    order = [r for r in rows.values()]
    regions, areas, spots = [], [], []
    for r in order:
        if r[2] not in regions:
            regions.append(r[2])
    for r in order:
        if r[2] == target[2] and r[3] not in areas:
            areas.append(r[3])
    for r in order:
        if r[2] == target[2] and r[3] == target[3]:
            spots.append(r[0])
    keys, frame = [], MENU_AT
    def press(name):
        nonlocal frame
        keys.append(f"{frame}:{name}")
        frame += 10
    press("OPEN")
    press("ENTER")                                   # root row 0: Warp
    for _ in range(regions.index(target[2])): press("DOWN")
    press("ENTER")
    for _ in range(areas.index(target[3])): press("DOWN")
    press("ENTER")
    for _ in range(spots.index(target[0])): press("DOWN")
    press("ENTER")
    return keys


FINISH_AT = 4600
STEP_FRAMES = 6800


def step_keys(rows, row) -> list[str]:
    """Reach step N's start (warp to step N-1's end, or a fresh game for step 1),
    then Finish Current Step through the menu: Finish Area is root row 1 and
    Finish Current Step is its first row."""
    order = int(row[9])
    keys = []
    if order > 1:
        prev = next(r for r in rows.values() if len(r) > 9 and r[9] == str(order - 1))
        keys.append(f"{MENU_AT}:WARP:{prev[0]}")
    at = FINISH_AT if order > 1 else MENU_AT
    for i, name in enumerate(("OPEN", "DOWN", "ENTER", "ENTER")):
        keys.append(f"{at + 10 * i}:{name}")
    return keys


def sweep_one(port: Path, data: Path, ckdir: Path, rows, row, evidence: Path, steps=False) -> dict:
    cid, spot = row[0], row[4]
    result = {"id": cid, "spot": spot, "passed": False, "mode": "step" if steps else "warp"}
    with tempfile.TemporaryDirectory(prefix=f"xanth-sweep-{cid}-") as tmp:
        saves = Path(tmp) / "saves"
        saves.mkdir()
        final = evidence / f"{cid}.{'step' if steps else 'final'}.bmp"
        keys = [f"{f}:GAME_SPACE" for f in BOOT_KEYS] + (step_keys(rows, row) if steps else menu_keys(rows, row))
        env = {**os.environ, "SDL_VIDEODRIVER": "dummy", "SDL_AUDIODRIVER": "dummy",
               "XANTH_DEV_CHECKPOINTS": str(ckdir), "XANTH_DEV_WARP_UNVERIFIED": "1",
               "XANTH_DEV_KEYS": ",".join(keys)}
        proc = subprocess.run(
            [str(port), "--headless", "--dev-menu", "--frames", str(STEP_FRAMES if steps else FRAMES),
             "--data", str(data),
             "--saves", str(saves), "--shot", str(final)],
            env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=900)
        log = proc.stdout + proc.stderr
        (evidence / f"{cid}.{'step.' if steps else ''}log").write_text(log[-30000:])
        leftover = sorted(p.name for p in saves.glob("XANTH*.SAV"))
    warped = f"Warped to {spot}" in log
    refused = "Warp refused" in log or "Warp failed" in log
    idle = "guest state at exit: field-idle" in log
    import re as _re
    m = _re.search(r"progress at exit: room (\d+) score (\d+)", log)
    progress = (int(m.group(1)), int(m.group(2))) if m else None
    expected = (int(row[7]), int(row[8])) if len(row) > 8 else None
    finished = (not steps) or f"finish step {row[9]} (" in log
    ref = ckdir / f"{cid}.ref.bmp"
    pic = inv = 1.0
    if final.exists() and ref.exists():
        a, b = pixels(final), pixels(ref)
        pic, inv = diff_fraction(a, b, PICTURE), diff_fraction(a, b, INVENTORY)
    result.update({
        "exit": proc.returncode, "warped": warped, "refused": refused, "field_idle_at_exit": idle,
        "picture_diff": round(pic, 4), "inventory_diff": round(inv, 4),
        "temporary_slot_left": leftover, "menu_keys": keys,
        "progress_at_exit": progress, "expected_progress": expected, "finish_requested": finished,
    })
    result["passed"] = (proc.returncode == 0 and warped and not refused and idle and finished
                        and pic <= MAX_DIFF and inv <= MAX_DIFF and not leftover
                        and (expected is None or progress == expected))
    (evidence / f"{cid}.{'step.' if steps else ''}json").write_text(json.dumps(result, indent=1))
    return result


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--port", required=True)
    ap.add_argument("--data")
    ap.add_argument("--checkpoints")
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--steps", action="store_true",
                    help="verify Finish Current Step for every step checkpoint instead of warps")
    args = ap.parse_args(argv)
    port = Path(args.port).resolve()
    data = (Path(args.data) if args.data else default_data()).resolve()
    ckdir = (Path(args.checkpoints) if args.checkpoints else default_out()).resolve()
    rows = read_list(ckdir)
    if not rows:
        print(f"no checkpoints in {ckdir}; run tools/xanth_dev_checkpoints.py first")
        return 2
    evidence = ckdir / "sweep"
    evidence.mkdir(exist_ok=True)
    os.chmod(evidence, 0o700)
    results = []
    for cid, row in rows.items():
        if args.only and cid not in args.only:
            continue
        if args.steps and (len(row) < 10 or row[9] in ("0", "")):
            continue
        r = sweep_one(port, data, ckdir, rows, row, evidence, args.steps)
        results.append(r)
        print(f"{'VERIFIED' if r['passed'] else 'FAILED  '} {cid}: warped={r['warped']} "
              f"idle={r['field_idle_at_exit']} picture={r['picture_diff']:.2%} "
              f"inventory={r['inventory_diff']:.2%} progress={r['progress_at_exit']}"
              f"{' expected ' + str(r['expected_progress']) if args.steps else ''}")
        if not args.dry_run and not args.steps:
            row[5] = "1" if r["passed"] else "0"
            write_list(ckdir, rows)
    n = sum(r["passed"] for r in results)
    print(f"VERIFIED {n}/{len(results)} (evidence in {evidence})")
    return 0 if n == len(results) else 1


if __name__ == "__main__":
    sys.exit(main())
