#!/usr/bin/env python3
"""Real-time boot smoke: the Legend logo must appear with no input.

Runs xanth_port's own real-time frame loop (not tool_vmboot's scheduler)
headless for a fixed number of frames, with no keyboard, mouse or pad input,
and checks the final guest frame (written from VRAM through the DAC) is not
black. The retail logo fades in against a music clock advanced by the game's
own INT 08h handler while it polls DOS with interrupts masked; a VM that never
takes a timer tick inside a DOS service leaves the logo drawn but the palette
unlit, which is the black window players saw in alpha.1 and alpha.2.

Requires owned data via XANTH_DATA or game_cd/XANTH; nothing is written to git.
"""
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
PORT = os.environ.get("XANTH_PORT_BIN", os.path.join(ROOT, "build", "xanth_port"))
DATA = os.environ.get("XANTH_DATA", os.path.join(ROOT, "game_cd", "XANTH"))
FRAMES = int(os.environ.get("XANTH_BOOT_FRAMES", "700"))
MIN_LIT_PIXELS = 1000


def lit_pixels(bmp):
    with open(bmp, "rb") as f:
        data = f.read()
    offset = int.from_bytes(data[10:14], "little")
    pixels = data[offset:]
    return sum(1 for i in range(0, len(pixels) - 2, 3) if pixels[i] or pixels[i + 1] or pixels[i + 2])


def main():
    if not os.path.exists(os.path.join(DATA, "XANTH.EXE")):
        if "XANTH_DATA" in os.environ:
            print("FAIL: explicitly selected owned data is missing")
            return 1
        print("SKIP: retail data not present")
        return 77
    with tempfile.TemporaryDirectory(prefix="xanth-boot-") as work:
        shot = os.path.join(work, "boot.bmp")
        env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy")
        for name in ("DISPLAY", "WAYLAND_DISPLAY", "XAUTHORITY"):
            env.pop(name, None)
        proc = subprocess.run(
            [PORT, "--headless", "--frames", str(FRAMES), "--data", DATA,
             "--saves", work, "--shot", shot],
            env=env, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=300)
        if proc.returncode != 0:
            print(proc.stderr[-2000:])
            print(f"FAIL: xanth_port exited {proc.returncode}")
            return 1
        lit = lit_pixels(shot)
        ticks = [l for l in proc.stderr.splitlines() if "timer ticks delivered" in l]
        if lit < MIN_LIT_PIXELS:
            print(f"FAIL: frame {FRAMES} has {lit} lit pixels (logo not visible); {ticks}")
            return 1
        print(f"PASS: frame {FRAMES} shows the logo ({lit} lit pixels); {ticks}")
        return 0


if __name__ == "__main__":
    sys.exit(main())
