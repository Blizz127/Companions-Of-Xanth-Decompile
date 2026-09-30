#!/usr/bin/env python3
"""Build dev-menu warp checkpoints from the player's own game data.

Each checkpoint replays part of the published route under tool_vmboot
(optionally resuming from an earlier checkpoint through the game's own
startup Restore prompt), then saves with the game's own Save dialog under a
typeable label, exactly as a player would: F5, the label, Enter. The save
the game writes is copied to the checkpoint directory as <id>.SAV together
with a reference screenshot, and listed in checkpoints.txt as unverified.
tools/xanth_dev_warp_sweep.py then warps to each one through the dev menu
and marks it verified only if the game accepts it.

Everything is written to a user-only directory (default
~/.local/share/xanth-port/dev-checkpoints, or XANTH_DEV_CHECKPOINTS); it is
derived from the player's game and must never be committed or shipped.

  xanth_dev_checkpoints.py --vmboot build/tool_vmboot [--data DIR] [--out DIR] [--only ID ...]
"""
from __future__ import annotations

import argparse
import hashlib
import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TRACES = ROOT / "tests" / "traces"

# id, label, region, area, spot, base checkpoint (None: cold boot), route lines,
# step (order, name) or None. Labels use only a-z/0-9/space: the warp types them
# into the Restore dialog. A step checkpoint is the game's state at the END of
# that step of the published route; step names are our own short descriptions.
CHECKPOINTS = [
    ("mundania-bedroom", "dw bedroom", "Mundania", "Your house", "Bedroom (start of game)",
     None, ["include lib/boot.xit"], None),
    ("mundania-step1", "dw step one", "Mundania", "Your house", "Kitchen (first visit)",
     None, ["include walkthrough_01_mundania.xit"], (1, "Find the kitchen")),
    ("mundania-step2", "dw step two", "Mundania", "Your house", "After the phone call",
     None, ["include walkthrough_02_phone.xit",
            # The route ends with the conversation open; dismiss it as
            # walkthrough_03 does (checkmark at 125,134) before saving.
            "run 60", "move 125 134", "run 5", "click left", "run 40", "move 305 196", "run 15"],
     (2, "Take the phone call")),
    ("mundania-step3", "dw step three", "Mundania", "Your house", "Kitchen supplies taken",
     None, ["include walkthrough_03_kitchen.xit"], (3, "Gather kitchen supplies")),
    ("mundania-step4", "dw step four", "Mundania", "Your house", "Package received",
     None, ["include walkthrough_04_courier.xit"], (4, "Meet the courier")),
    ("mundania-opening-done", "dw opening", "Mundania", "Your house", "Bedroom (opening finished)",
     None, ["include walkthrough_05_cdrom.xit"], (5, "Start the game CD")),
    ("xanth-cavern", "dw cavern", "Xanth", "Cavern", "Cavern (with Nada)",
     "mundania-opening-done", ["include walkthrough_06_xanth.xit"], (6, "Arrive in Xanth")),
    ("xanth-cavern-doors", "dw doors", "Xanth", "Cavern", "Cavern (second door open)",
     "xanth-cavern", ["include walkthrough_07_cavern.xit"], (7, "Search the cavern with Nada")),
]

SCAN = {c: s for c, s in zip("1234567890", range(0x02, 0x0C))}
SCAN.update({c: s for c, s in zip("qwertyuiop", range(0x10, 0x1A))})
SCAN.update({c: s for c, s in zip("asdfghjkl", range(0x1E, 0x27))})
SCAN.update({c: s for c, s in zip("zxcvbnm", range(0x2C, 0x33))})
SCAN[" "] = 0x39


def default_out() -> Path:
    if os.environ.get("XANTH_DEV_CHECKPOINTS"):
        return Path(os.environ["XANTH_DEV_CHECKPOINTS"])
    base = os.environ.get("XDG_DATA_HOME") or str(Path.home() / ".local" / "share")
    return Path(base) / "xanth-port" / "dev-checkpoints"


def default_data() -> Path:
    for c in (os.environ.get("XANTH_DATA"), str(Path.home() / "Games/companions-of-xanth/data"),
              str(ROOT / "game_cd/XANTH")):
        if c and (Path(c) / "XANTH.EXE").is_file():
            return Path(c)
    raise SystemExit("retail data not found; pass --data")


def save_lines(label: str, ref: Path) -> list[str]:
    lines = ["run 20", "key 0 63", "run 20"]
    lines += [f"key {ord(c)} {SCAN[c]}" for c in label]
    lines += ["key 13 28", "run 40", "move 160 100", "run 20", f"shot {ref}",
              "dump 3961:0256 16",      # progress fingerprint: room DS:0256, score DS:0264
              "dump 3961:69FC 2"]       # and the inventory count DS:69FC
    return lines


def read_list(out: Path) -> dict[str, list[str]]:
    rows = {}
    path = out / "checkpoints.txt"
    if path.is_file():
        for line in path.read_text().splitlines():
            if line and not line.startswith("#"):
                parts = line.split("\t")
                if len(parts) >= 7:
                    rows[parts[0]] = parts
    return rows


def write_list(out: Path, rows: dict[str, list[str]]) -> None:
    order = [c[0] for c in CHECKPOINTS] + sorted(set(rows) - {c[0] for c in CHECKPOINTS})
    text = "# id\tlabel\tregion\tarea\tspot\tverified\tsha256\troom\tscore\tstep\tstep name\titems\n"
    text += "".join("\t".join(rows[i]) + "\n" for i in order if i in rows)
    tmp = out / "checkpoints.txt.tmp"
    tmp.write_text(text)
    os.chmod(tmp, 0o600)
    tmp.replace(out / "checkpoints.txt")


def build(cp, vmboot: Path, data: Path, out: Path, budget: int) -> list[str]:
    cid, label, region, area, spot, base, route, step = cp
    with tempfile.TemporaryDirectory(prefix=f"xanth-ck-{cid}-") as tmp:
        work = Path(tmp)
        saves = work / "saves"
        saves.mkdir()
        if base:
            src = out / f"{base}.SAV"
            if not src.is_file():
                raise SystemExit(f"{cid}: build {base} first")
            shutil.copy(src, saves / "XANTH000.SAV")
        shutil.copytree(TRACES / "lib", work / "lib")
        (work / "build" / "frames").mkdir(parents=True)
        for name in os.listdir(TRACES):
            if name.endswith(".xit"):
                shutil.copy(TRACES / name, work / name)
        ref = out / f"{cid}.ref.bmp"
        script = work / "build.xit"
        script.write_text("\n".join(route + save_lines(label, ref)) + "\n")
        before = set(saves.glob("XANTH*.SAV"))
        proc = subprocess.run(
            [str(vmboot), "--exe", str(data / "XANTH.EXE"), "--data", str(data),
             "--saves", str(saves), "--script", str(script), "--insns", str(budget)],
            cwd=work, env={**os.environ, "SDL_VIDEODRIVER": "dummy", "SDL_AUDIODRIVER": "dummy"},
            stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        log = proc.stdout + proc.stderr
        (out / f"{cid}.build.log").write_text(log[-20000:])
        os.chmod(out / f"{cid}.build.log", 0o600)
        if proc.returncode != 0 or "fault                 : ok" not in log:
            raise SystemExit(f"{cid}: route failed (see {cid}.build.log)")
        made = [p for p in saves.glob("XANTH*.SAV")
                if p.read_bytes()[:len(label)] == label.encode() and p not in before]
        if len(made) != 1:
            raise SystemExit(f"{cid}: expected one new save labelled {label!r}, found {len(made)}")
        dst = out / f"{cid}.SAV"
        shutil.copy(made[0], dst)
        os.chmod(dst, 0o600)
        if ref.exists():
            os.chmod(ref, 0o600)
        digest = hashlib.sha256(dst.read_bytes()).hexdigest()
        fp = (work / "build" / "frames" / "dump_3961_0256.bin").read_bytes()
        room, score = int.from_bytes(fp[0:2], "little"), int.from_bytes(fp[14:16], "little")
        items = int.from_bytes((work / "build" / "frames" / "dump_3961_69FC.bin").read_bytes()[:2], "little")
        print(f"[checkpoints] built {cid} ({spot}) room {room} score {score} items {items} sha256 {digest[:16]}")
        return [cid, label, region, area, spot, "0", digest, str(room), str(score),
                str(step[0]) if step else "0", step[1] if step else "-", str(items)]


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--vmboot", required=True)
    ap.add_argument("--data")
    ap.add_argument("--out")
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--insns", type=int, default=30_000_000_000)
    args = ap.parse_args(argv)
    data = (Path(args.data) if args.data else default_data()).resolve()
    out = (Path(args.out) if args.out else default_out()).resolve()
    vmboot = Path(args.vmboot).resolve()
    out.mkdir(parents=True, exist_ok=True)
    os.chmod(out, 0o700)
    rows = read_list(out)
    for cp in CHECKPOINTS:
        if args.only and cp[0] not in args.only:
            continue
        rows[cp[0]] = build(cp, vmboot, data, out, args.insns)
        write_list(out, rows)
    print(f"[checkpoints] {len(rows)} listed in {out / 'checkpoints.txt'} (unverified until swept)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
