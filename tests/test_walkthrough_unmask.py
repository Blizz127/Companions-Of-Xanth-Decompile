"""Long retail-VM check that defeats Metria and resumes inside the barrow."""

from __future__ import annotations

import hashlib
import os
import re
import shutil
import struct
import subprocess
import unittest
from pathlib import Path

from tests.font_ocr import read_game_font_text

ROOT = Path(__file__).resolve().parent.parent
EXE = ROOT / "original" / "XANTH.EXE"
DATA = ROOT / "game_cd" / "XANTH"
TOOL = ROOT / "build" / "tool_vmboot"
TRACE = ROOT / "tests" / "traces" / "walkthrough_12_metria.xit"
ANCHOR = ROOT / "build" / "anchor_unmask"
SAVES = ROOT / "build" / "agent_barrow_unmasked_test"
SCORE = ROOT / "build" / "frames" / "wt12_barrow_score.bmp"
BUDGET = 6_000_000_000
ANCHOR_SLOT_SHA256 = "29dd6466242c877278c6d0e8f851ea70dfe95988d3b0db6a879988394d59812b"
GOLDEN = {
    "wt12_metria_defeated": "8fcffc63d56e42cd",
    "wt12_inside_barrow": "e1d562dfc3dba172",
    "wt12_barrow_score": "9d7ae23a47de17c5",
}


class UnmaskBarrowTests(unittest.TestCase):
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
            raise unittest.SkipTest("the hash-identified 218-point spring save is unavailable")
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

    def test_metria_and_barrow_frames_match(self) -> None:
        for name, expected in GOLDEN.items():
            self.assertEqual(self.marks.get(name), expected, name)

    def test_defeated_metria_save_scores_228(self) -> None:
        data = (SAVES / "XANTH000.SAV").read_bytes()
        self.assertEqual(struct.unpack_from("<H", data, 0x347D)[0], 228)
        text = read_game_font_text(SCORE, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("228 of 1000 points", text)


if __name__ == "__main__":
    unittest.main()
