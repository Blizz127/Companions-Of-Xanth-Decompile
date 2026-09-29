"""Long retail-VM probe of the current extended Isthmus route.

Set XANTH_LONG_WALKTHROUGH=1 to run. This deliberately records the measured
score instead of trusting the trace's historical "200 pts" comment.
"""

from __future__ import annotations

import os
import re
import shutil
import subprocess
import unittest
from pathlib import Path

from tests.font_ocr import read_game_font_text
from tests.test_walkthrough_isthmus import prepare_village_anchor

ROOT = Path(__file__).resolve().parent.parent
EXE = ROOT / "original" / "XANTH.EXE"
DATA = ROOT / "game_cd" / "XANTH"
TOOL = ROOT / "build" / "tool_vmboot"
TRACE = ROOT / "tests" / "traces" / "verify_crossroads_score.xit"
ANCHOR = ROOT / "build" / "anchor_isthmus_village"
SAVES = ROOT / "build" / "agent_scene2_test"
SCORE = ROOT / "build" / "frames" / "wt10_score.bmp"
BUDGET = 32_000_000_000

GOLDEN = {
    "wt10_at_crossroads": "203bb70c7b77ba89",
    "wt10_score": "352158e4942eb4b9",
}


class SceneIICrossroadsTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        if os.environ.get("XANTH_LONG_WALKTHROUGH") != "1":
            raise unittest.SkipTest("set XANTH_LONG_WALKTHROUGH=1 for the ~12-minute route")
        for path, label in ((EXE, "retail executable"), (DATA, "retail assets"),
                            (TRACE, "route trace"), (TOOL, "VM tool")):
            if not path.exists():
                raise unittest.SkipTest(f"{label} unavailable: {path}")
        prepare_village_anchor()
        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
        for name in ("LEGEND.INI", "RESTART.DAT", "XANTH000.SAV"):
            shutil.copy2(ANCHOR / name, SAVES / name)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE), "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=1800,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", cls.out))

    def test_vm_and_guest_heap_remain_healthy(self) -> None:
        self.assertEqual(self.rc, 0)
        self.assertIn("fault                 : ok", self.out)
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_crossroads_and_score_frames_match(self) -> None:
        for name, expected in GOLDEN.items():
            self.assertEqual(self.marks.get(name), expected, name)

    def test_measured_score_is_still_122(self) -> None:
        text = read_game_font_text(SCORE, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("122 of 1000 points", text)


if __name__ == "__main__":
    unittest.main()
