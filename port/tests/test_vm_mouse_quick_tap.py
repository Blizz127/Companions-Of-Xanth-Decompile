"""Prove actual SDL quick taps reach retail input through the HAL bridge."""
import os
import re
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
DATA = Path(os.environ.get("XANTH_DATA", ROOT / "game_cd/XANTH"))


class RetailMouseQuickTapTests(unittest.TestCase):
    def test_same_poll_down_up_takes_envelope(self):
        tool = Path(os.environ["XANTH_VMCLICK"])
        with tempfile.TemporaryDirectory(prefix="xanth-sdl-quick-tap-") as tmp:
            proc = subprocess.run(
                [str(tool), "--exe", str(DATA / "XANTH.EXE"),
                 "--data", str(DATA), "--saves", tmp,
                 "--script", str(ROOT / "tests/traces/mouse_quick_tap.xit"),
                 "--insns", "700000000", "--vm-only"],
                cwd=ROOT, text=True, capture_output=True, timeout=300,
                env={**os.environ, "SDL_VIDEODRIVER": "dummy",
                     "SDL_AUDIODRIVER": "dummy"}, check=False,
            )
        output = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, output[-3000:])
        hashes = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", output))
        self.assertEqual(hashes, {
            "mouse_bedroom": "ace8f1a3d6b858f2",
            # Rendered result: the envelope is now in the guest inventory.
            "mouse_envelope_taken": "ad4549a362779925",
        }, output[-3000:])
        self.assertIn("fault                 : ok", output)
        self.assertIn("MCB chain valid       : yes", output)
        frames = re.search(r"\[SDL bridge\] guest frames=(\d+) button edges=(\d+)", output)
        self.assertIsNotNone(frames, output[-3000:])
        self.assertGreaterEqual(int(frames[1]), 1200)
        self.assertEqual(int(frames[2]), 4)
        observed = re.findall(r"\[SDL bridge\] state (\d+) observed after (\d+) frames", output)
        self.assertEqual([state for state, _ in observed], ["1", "0", "1", "0"])
        self.assertTrue(all(int(count) >= 1 for _, count in observed))


if __name__ == "__main__":
    unittest.main()
