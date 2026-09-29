"""Long retail-VM route through the barrow dungeon artifacts and stairs."""

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
TRACE = ROOT / "tests" / "traces" / "walkthrough_13_dungeon.xit"
ANCHOR = ROOT / "build" / "anchor_barrow_unmasked"
SAVES = ROOT / "build" / "agent_dungeon_test"
SCORE = ROOT / "build" / "frames" / "wt13_score.bmp"
BUDGET = 32_000_000_000
ANCHOR_SLOT_SHA256 = "51b5ef6408a751c1d85cda264d83eefa6dc362f573931060c3f64dae9d36f6f1"
GOLDEN = {
    "wt13_jar": "447059f60a1f04c3",
    "wt13_pestle": "a08bc76faeb1e1fd",
    "wt13_button_hover": "920c01c0a12380ad",
    "wt13_button_clicked": "c573cf635e857cbc",
    "wt13_push_button": "3d5c73bddbaee114",
    "wt13_in_dungeon": "c5ccc8e0e6b13de0",
    "wt13_free_nada": "57a1f703f5995008",
    "wt13_open_jar": "c3f7023676af0474",
    "wt13_take_moss": "dd25a0da45bf1845",
    "wt13_up": "149fd83d54bea148",
    "wt13_score": "532834cd9e30428d",
}


class DungeonRouteTests(unittest.TestCase):
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
            raise unittest.SkipTest("the hash-identified 228-point unmasked barrow save is unavailable")
        if SAVES.exists():
            shutil.rmtree(SAVES)
        shutil.copytree(ANCHOR, SAVES)
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

    def test_dungeon_route_frames_match(self) -> None:
        for name, expected in GOLDEN.items():
            self.assertEqual(self.marks.get(name), expected, name)

    def test_live_score_reaches_230(self) -> None:
        text = read_game_font_text(SCORE, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("230 of 1000 points", text)


if __name__ == "__main__":
    unittest.main()
