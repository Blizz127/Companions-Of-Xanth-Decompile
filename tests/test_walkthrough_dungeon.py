"""Long retail-VM route through the barrow dungeon and its current frontier."""

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
TRACE = ROOT / "tests" / "traces" / "walkthrough_14_dungeon_items.xit"
ANCHOR = ROOT / "build" / "anchor_barrow_unmasked"
SAVES = ROOT / "build" / "agent_dungeon_test"
MOSS_SCREEN = ROOT / "build" / "frames" / "wt14_moss_center_attempt.bmp"
FIRE_SCREEN = ROOT / "build" / "frames" / "wt14_test_after_exit_north.bmp"
BUDGET = 32_000_000_000
ANCHOR_SLOT_SHA256 = "51b5ef6408a751c1d85cda264d83eefa6dc362f573931060c3f64dae9d36f6f1"
GOLDEN = {
    "wt14_jar_room": "158ebdbb374cc1fa",
    "wt14_door_ajar": "37d6a0eea6d9c4d0",
    "wt14_jar_acquired": "1699e1bb3bf3f651",
    "wt14_button_hover": "e212efd1f099f48e",
    "wt14_button_clicked": "f0da8c5de99c522b",
    "wt14_push_button": "186eb37cdef0bfb7",
    "wt14_in_dungeon": "d014180df173a8a5",
    "wt14_free_nada": "0725a127c7c9091f",
    "wt14_open_attempt": "3d51aac74453929f",
    "wt14_moss_attempt": "b56ef82679b6be6c",
    "wt14_open_center": "66755427e42be6f7",
    "wt14_moss_center_attempt": "6af64e152117aad5",
    "wt14_open_reverse": "fe588f441ceedafa",
    "wt14_moss_reverse_attempt": "e1c6a223e32eaa2f",
    "wt14_upper_room": "09306cfec7e0da4f",
    "wt14_tree_melted": "55b051791f858a08",
    "wt14_region_fire": "b885e0e22388a454",
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

    def test_moss_is_collected_in_the_open_jar(self) -> None:
        text = read_game_font_text(MOSS_SCREEN, DATA / "XANTH_10.FNT", 120, 160)
        self.assertIn("You scoop a bit of the blue moss", text)
        self.assertIn("7 points", text)

    def test_route_reaches_region_of_fire(self) -> None:
        text = read_game_font_text(FIRE_SCREEN, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("Region of Earth", text)
        self.assertIn("Region of Fire", text)


if __name__ == "__main__":
    unittest.main()
