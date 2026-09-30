"""SDL-only blackbox gestures against the production xanth_port binary.

Requires XANTH_PORT, XANTH_CONTROLLER_SHIM and XANTH_GAME_DATA. Uses dummy
video/audio and isolated saves; screenshots exist only in temporary directories.
Every process has a 59-second budget. No memory introspection or VM hooks.
"""
import hashlib
import os
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

REQUIRED = ("XANTH_PORT", "XANTH_CONTROLLER_SHIM", "XANTH_GAME_DATA")


@unittest.skipUnless(all(os.environ.get(k) for k in REQUIRED),
                     "requires production binary, SDL shim, and external retail data")
class ControllerBlackboxTests(unittest.TestCase):
    def run_port(self, script, frames, flags=(), trace=True):
        with tempfile.TemporaryDirectory(prefix="xanth-pad-blackbox-") as tmp:
            base = Path(tmp)
            events = base / "events.txt"
            events.write_text(script)
            saves = base / "saves"
            saves.mkdir()
            shot = base / "final.bmp"
            env = {k: v for k, v in os.environ.items()
                   if k not in ("DISPLAY", "WAYLAND_DISPLAY", "XAUTHORITY")}
            env.update(SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
                       LD_PRELOAD=os.environ["XANTH_CONTROLLER_SHIM"],
                       XANTH_PAD_SCRIPT=str(events), XANTH_TRACE_INPUT="1" if trace else "0",
                       XDG_CONFIG_HOME=str(base / "config"), XDG_DATA_HOME=str(base / "data"),
                       XDG_STATE_HOME=str(base / "state"), XDG_CACHE_HOME=str(base / "cache"))
            proc = subprocess.run([os.environ["XANTH_PORT"], "--data",
                                   os.environ["XANTH_GAME_DATA"], "--saves", str(saves),
                                   "--scale", "1", "--frames", str(frames),
                                   "--shot", str(shot), *flags], env=env, text=True,
                                  stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=59)
            self.assertEqual(proc.returncode, 0, proc.stdout[-12000:])
            self.assertTrue(shot.is_file(), proc.stdout[-12000:])
            return proc.stdout, hashlib.sha256(shot.read_bytes()).hexdigest()

    def test_actual_field_gestures(self):
        script = "".join(f"{f} K 1\n{f + 4} K 0\n"
                         for f in (300, 900, 1500, 1800, 2100, 2400, 2700))
        script += ("2800 M 200 55\n2860 B 3 1\n2864 B 3 0\n"
                   "2900 B 10 1\n2904 B 10 0\n2930 B 10 1\n2934 B 10 0\n"
                   "2960 B 9 1\n2964 B 9 0\n")
        log, _ = self.run_port(script, 3000)
        self.assertIn("neutral attach index=0 success=1", log)
        actions = re.findall(r"\[controller\] action=(\d+) frame=(\d+) target=(\d+),(\d+) field=([^\s]+)", log)
        # Fail explicitly if even the first single Y gesture was dropped. A
        # phase-scanning diagnostic must never count as this functional test.
        self.assertEqual([(a, f, x, y) for a, f, x, y, _ in actions],
                         [("1", "2860", "236", "39"), ("3", "2900", "25", "9"),
                          ("3", "2930", "25", "19"), ("2", "2960", "25", "9")],
                         log[-16000:])
        print("[blackbox] first Y and RB/RB/LB gestures reached exact production targets")

    def test_disabled_controller_and_observer_preserve_frame(self):
        plain, plain_hash = self.run_port("", 240, ("--no-controller",), trace=False)
        observed, observed_hash = self.run_port("30 B 3 1\n34 B 3 0\n", 240,
                                                ("--no-controller",), trace=True)
        self.assertIn("neutral attach index=0 success=1", plain)
        self.assertIn("neutral attach index=0 success=1", observed)
        self.assertNotIn("[controller] action=", plain + observed)
        self.assertEqual(plain_hash, observed_hash)
        print(f"[blackbox] --no-controller observer/input parity SHA256 {plain_hash}")


if __name__ == "__main__":
    unittest.main()
