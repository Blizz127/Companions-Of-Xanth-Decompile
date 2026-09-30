#!/usr/bin/env python3
"""Retail-parity gate for the opt-in dev menu (shared spec section 8/10).

Runs the real game headless three ways for the same number of frames:
  off       - a normal launch;
  on        - --dev-menu with a scripted walk through every page, help,
              refusals and screenshots, but no fast-forward or cheat;
  disabled  - --dev-menu with XANTH_CHEATS=0 (hard disable).
Guest RAM + DAC hash, cycle count and the final guest frame must be
identical in all three.  The menu screenshots (presented frame, overlay
included) are kept as evidence and must differ from the guest frame.

Requires the retail data in game_cd/XANTH; no game data is written to git.
"""
import hashlib
import os
import re
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PORT = os.environ.get("XANTH_PORT_BIN", os.path.join(ROOT, "build", "xanth_port"))
DATA = os.environ.get("XANTH_DATA", os.path.join(ROOT, "game_cd", "XANTH"))
FRAMES = int(os.environ.get("XANTH_DEV_IDENTITY_FRAMES", "1500"))
BASE = 1000   # script starts once the title art is on screen

# Frame-stamped harness keys; screenshots land in XANTH_DEV_SHOT_DIR in order.
SCRIPT = [
    (120, "OPEN"),                                  # open: root
    (130, "DOWN"), (140, "DOWN"), (150, "DOWN"),    # to Options
    (160, "ENTER"), (170, "SHOT"),                  # shot 1: a populated group
    (180, "ESC"), (190, "UP"), (195, "UP"), (200, "UP"),
    (210, "ENTER"), (220, "SHOT"),                  # shot 2: Warp, an empty group
    (230, "ESC"), (240, "SHOT"),                    # shot 3: root
    (250, "HELP"), (260, "SHOT"),                   # shot 4: help
    (270, "HELP"), (280, "OPEN"),                   # close
    (290, "GOD"), (300, "SHOT"),                    # shot 5: refusal toast, menu closed
    (310, "QUICK_SAVE"), (320, "QUICK_LOAD"), (330, "RECORD"),
]
SHOT_NAMES = ["options", "warp-empty", "root", "help", "toast-closed"]


def run(label, workdir, extra_args, extra_env):
    saves = os.path.join(workdir, label, "saves")
    shots = os.path.join(workdir, label, "shots")
    os.makedirs(saves)
    shot = os.path.join(workdir, label, "final.bmp")
    env = {k: v for k, v in os.environ.items()
           if not k.startswith("XANTH_DEV") and k != "XANTH_CHEATS"}
    env.update({"SDL_VIDEODRIVER": "dummy", "SDL_AUDIODRIVER": "dummy",
                "XANTH_STATE_HASH": "1", "XANTH_DEV_SHOT_DIR": shots})
    env.update(extra_env)
    cmd = [PORT, "--headless", "--frames", str(FRAMES), "--data", DATA,
           "--saves", saves, "--shot", shot] + extra_args
    proc = subprocess.run(cmd, env=env, stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE, text=True, timeout=600)
    log = proc.stdout + proc.stderr
    with open(os.path.join(workdir, label, "run.log"), "w") as f:
        f.write(log)
    if proc.returncode != 0:
        raise AssertionError(f"{label}: exit {proc.returncode}\n{log[-2000:]}")
    m = re.search(r"\[state\] cycles=(\d+) fnv1a64=([0-9a-f]{16})", log)
    if not m:
        raise AssertionError(f"{label}: no state hash in log")
    with open(shot, "rb") as f:
        frame_sha = hashlib.sha256(f.read()).hexdigest()
    shots_found = sorted(os.listdir(shots)) if os.path.isdir(shots) else []
    return {"cycles": m.group(1), "hash": m.group(2), "frame": frame_sha,
            "log": log, "shots": [os.path.join(shots, s) for s in shots_found],
            "final": shot}


def main():
    if not os.path.exists(os.path.join(DATA, "XANTH.EXE")):
        if "XANTH_DATA" in os.environ:
            print("FAIL: explicitly selected owned data is missing")
            return 1
        print("SKIP: retail data not present")
        return 77
    evidence = os.environ.get("XANTH_DEV_EVIDENCE")
    with tempfile.TemporaryDirectory(prefix="xanth-devmenu-") as work:
        keys = ",".join(f"{BASE + f}:{k}" for f, k in SCRIPT)
        off = run("off", work, [], {})
        on = run("on", work, ["--dev-menu"], {"XANTH_DEV_KEYS": keys})
        dis = run("disabled", work, ["--dev-menu"],
                  {"XANTH_DEV_KEYS": keys, "XANTH_CHEATS": "0"})

        for label, r in (("on", on), ("disabled", dis)):
            for field in ("cycles", "hash", "frame"):
                if r[field] != off[field]:
                    raise AssertionError(
                        f"{label} {field} {r[field]} != off {off[field]}")
        if "[DEV_MENU]" in off["log"]:
            raise AssertionError("off run printed dev-menu output")
        if "[DEV_MENU] hard-disabled by XANTH_CHEATS=0" not in dis["log"] or \
                "[DEV_MENU] open" in dis["log"]:
            raise AssertionError("hard-disabled run was not inert")
        if dis["shots"]:
            raise AssertionError("hard-disabled run produced screenshots")
        for needle in ("[DEV_MENU] open", "[DEV_MENU] close",
                       "God mode: not available", "Quick save: not available",
                       "Quick load: not available", "Record video: not available",
                       "Screenshot saved"):
            if needle not in on["log"]:
                raise AssertionError(f"on run log lacks {needle!r}")
        if len(on["shots"]) != len(SHOT_NAMES):
            raise AssertionError(f"expected {len(SHOT_NAMES)} menu shots, got {on['shots']}")
        digests = set()
        for path in on["shots"]:
            with open(path, "rb") as f:
                digests.add(hashlib.sha256(f.read()).hexdigest())
        if len(digests) != len(SHOT_NAMES):
            raise AssertionError("menu screenshots are not all distinct")

        if evidence:
            os.makedirs(evidence, exist_ok=True)
            for name, path in zip(SHOT_NAMES, on["shots"]):
                shutil.copy(path, os.path.join(evidence, f"{name}.bmp"))
            shutil.copy(off["final"], os.path.join(evidence, "guest-final-frame.bmp"))
            with open(os.path.join(evidence, "identity.txt"), "w") as f:
                for label, r in (("off", off), ("on", on), ("disabled", dis)):
                    f.write(f"{label}: frames={FRAMES} cycles={r['cycles']} "
                            f"state_fnv1a64={r['hash']} final_frame_sha256={r['frame']}\n")
            for label in ("off", "on", "disabled"):
                shutil.copy(os.path.join(work, label, "run.log"),
                            os.path.join(evidence, f"{label}.log"))

        print(f"PASS: {FRAMES} frames, state {off['hash']}, cycles {off['cycles']}, "
              f"frame {off['frame'][:16]}; {len(on['shots'])} menu screenshots")
        return 0


if __name__ == "__main__":
    sys.exit(main())
