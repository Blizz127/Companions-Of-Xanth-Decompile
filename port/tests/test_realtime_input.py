#!/usr/bin/env python3
"""Real-time input gate: Space presses must carry a fresh boot to the bedroom.

Runs xanth_port's own real-time frame loop headless with no scripted
scheduler. An LD_PRELOAD shim (sdl_key_shim.so) feeds three Space presses
through SDL at fixed frames, as a player would at the logo, the opening and
the title. The final guest frame must be the first room: the verb panel lit
and a full scene, not the logo.

Requires the retail data in game_cd/XANTH and a Linux build with the shim.
"""
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PORT = os.environ.get("XANTH_PORT_BIN", os.path.join(ROOT, "build", "xanth_port"))
SHIM = os.environ.get("XANTH_KEY_SHIM", os.path.join(ROOT, "build", "sdl_key_shim.so"))
DATA = os.path.join(ROOT, "game_cd", "XANTH")
KEYS = "300,1500,2700"
FRAMES = 3600


def frame(bmp):
    with open(bmp, "rb") as f:
        data = f.read()
    offset = int.from_bytes(data[10:14], "little")
    rows = [data[offset + (199 - y) * 960: offset + (200 - y) * 960] for y in range(200)]
    return lambda x, y: rows[y][3 * x:3 * x + 3] != b"\0\0\0"


def main():
    if not os.path.exists(os.path.join(DATA, "XANTH.EXE")):
        print("SKIP: retail data not present")
        return 0
    with tempfile.TemporaryDirectory(prefix="xanth-input-") as work:
        shot = os.path.join(work, "final.bmp")
        env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
                   SHIM_KEY_FRAMES=KEYS, LD_PRELOAD=SHIM)
        proc = subprocess.run(
            [PORT, "--headless", "--frames", str(FRAMES), "--data", DATA,
             "--saves", work, "--shot", shot],
            env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=300)
        presses = proc.stderr.count("[keyshim] Space")
        if proc.returncode != 0 or presses != 3:
            print(proc.stderr[-2000:])
            print(f"FAIL: exit {proc.returncode}, {presses} presses delivered")
            return 1
        lit = frame(shot)
        verbs = sum(lit(x, y) for x in range(2, 50) for y in range(4, 75))
        scene = sum(lit(x, y) for x in range(51, 315) for y in range(4, 126))
        if verbs < 400 or scene < 25000:
            print(f"FAIL: not in the first room (verb panel {verbs} px, scene {scene} px)")
            return 1
        print(f"PASS: bedroom reached (verb panel {verbs} px, scene {scene} px)")
        return 0


if __name__ == "__main__":
    sys.exit(main())
