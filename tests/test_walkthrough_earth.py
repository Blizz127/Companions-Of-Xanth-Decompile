"""Long retail-VM route from Earth outskirts to the unlocked barrow."""

from __future__ import annotations

import hashlib
import os
import re
import shutil
import subprocess
import unittest
from pathlib import Path

from tests.font_ocr import read_game_font_text

ROOT = Path(__file__).resolve().parent.parent
EXE = ROOT / "original" / "XANTH.EXE"
DATA = ROOT / "game_cd" / "XANTH"
TOOL = ROOT / "build" / "tool_vmboot"
TRACE = ROOT / "tests" / "traces" / "walkthrough_11_barrow.xit"
ANCHOR = ROOT / "build" / "anchor_earth_start"
SAVES = ROOT / "build" / "agent_earth_barrow_test"
SCORE = ROOT / "build" / "frames" / "wt11_barrow_score.bmp"
BUDGET = 6_000_000_000
ANCHOR_SLOT_SHA256 = "7d5c4e5e3cc11d5f0c35ccf36acbd29b0af28e3e573b7dfe5a1063422fe74b90"
GOLDEN = {
    "wt11_spring_arrived": "5610c75710b8ba08",
    "wt11_barrow_unlocked": "84329288ed9ddbdd",
    "wt11_outskirts_returned": "533d08649657bba9",
    "wt11_barrow_exterior": "2dccfb1a38ebec66",
    "wt11_barrow_door_open": "086fcec4ccf1a545",
    "wt11_inside_barrow": "6d283a5ebab07091",
    "wt11_barrow_score": "3454bbeb7fe2ff14",
}


class EarthBarrowTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        if os.environ.get("XANTH_LONG_WALKTHROUGH") != "1":
            raise unittest.SkipTest("set XANTH_LONG_WALKTHROUGH=1 for the long route")
        for path, label in ((EXE, "retail executable"), (DATA, "retail assets"),
                            (TRACE, "route trace"), (TOOL, "VM tool")):
            if not path.exists():
                raise unittest.SkipTest(f"{label} unavailable: {path}")
        slot = ANCHOR / "XANTH000.SAV"
        if not slot.is_file() or hashlib.sha256(slot.read_bytes()).hexdigest() != ANCHOR_SLOT_SHA256:
            raise unittest.SkipTest("the hash-identified Earth outskirts save is unavailable")
        if SAVES.exists():
            shutil.rmtree(SAVES)
        shutil.copytree(ANCHOR, SAVES)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE), "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=1200,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", cls.out))

    def test_vm_and_guest_heap_remain_healthy(self) -> None:
        self.assertEqual(self.rc, 0)
        self.assertIn("fault                 : ok", self.out)
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_spring_to_barrow_frames_match(self) -> None:
        for name, expected in GOLDEN.items():
            self.assertEqual(self.marks.get(name), expected, name)

    def test_barrow_entry_score_remains_208(self) -> None:
        text = read_game_font_text(SCORE, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("208 of 1000 points", text)


if __name__ == "__main__":
    unittest.main()
