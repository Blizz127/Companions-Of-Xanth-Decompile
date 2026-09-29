"""Long retail-VM check from the Void boundary into Region of Earth.

Set XANTH_LONG_WALKTHROUGH=1 to run. The checked-in local fixture is
identified by save hash, and the live score is read from the rendered panel.
"""

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
TRACE = ROOT / "tests" / "traces" / "verify_void_score.xit"
ANCHOR = ROOT / "build" / "anchor_isthmus"
SAVES = ROOT / "build" / "agent_void_score_test"
SCORE = ROOT / "build" / "frames" / "wt10_earth_score.bmp"
BUDGET = 8_000_000_000
ANCHOR_SLOT_SHA256 = "8d975715f9a2cb9f6ba00d671fd178399d56829224b6bb8969b8c5e1b8e03157"
GOLDEN = {
    "wt10_resumed": "2f4944d38827a0e9",
    "wt10_door_shimmer": "2164a99b53cc01ce",
    "wt10_door_solidified": "0aa59233336ba407",
    # Saving at the preceding checkpoint is part of this instrumented route;
    # it changes this one post-open frame's animation timing.
    "wt10_door_opened": "2ddb9039cbdd757f",
    "wt10_stepped_through": "05f32e5dab0902a9",
    "wt10_earth_outskirts": "f347d468db3ae9ba",
    "wt10_earth_score": "560a0fd24a0b467a",
}


class VoidToEarthTests(unittest.TestCase):
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
            raise unittest.SkipTest("the hash-identified 193-point Void save is unavailable")
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

    def test_void_to_earth_frames_match(self) -> None:
        for name, expected in GOLDEN.items():
            self.assertEqual(self.marks.get(name), expected, name)

    def test_earth_outskirts_score_is_208(self) -> None:
        text = read_game_font_text(SCORE, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("208 of 1000 points", text)

    def test_game_saved_203_before_opening_the_door(self) -> None:
        data = (SAVES / "XANTH000.SAV").read_bytes()
        self.assertEqual(struct.unpack_from("<H", data, 0x347D)[0], 203)


if __name__ == "__main__":
    unittest.main()
