"""Long retail-VM route through the barrow dungeon and its current frontier."""

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
TRACE = ROOT / "tests" / "traces" / "walkthrough_14_dungeon_items.xit"
CONTINUATION_TRACE = ROOT / "tests" / "traces" / "walkthrough_15_barrow_wings.xit"
FIRE_TRACE = ROOT / "tests" / "traces" / "walkthrough_16_fire_lake_entry.xit"
FIREMAN_TRACE = ROOT / "tests" / "traces" / "walkthrough_17_fireman_story.xit"
FIREWALL_TRACE = ROOT / "tests" / "traces" / "walkthrough_18_firewall.xit"
ANCHOR = ROOT / "build" / "anchor_barrow_unmasked"
SAVES = ROOT / "build" / "agent_dungeon_test"
MOSS_SCREEN = ROOT / "build" / "frames" / "wt14_moss_center_attempt.bmp"
FIRE_SCREEN = ROOT / "build" / "frames" / "wt14_test_after_exit_north.bmp"
DIALOGUE_SCREEN = ROOT / "build" / "frames" / "wt14_fire_dialogue_response.bmp"
GAP_SCREEN = ROOT / "build" / "frames" / "wt14_gap_dialogue_next.bmp"
GAP_ANSWER_SCREEN = ROOT / "build" / "frames" / "wt14_gap_dialogue_answer.bmp"
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
    "wt14_fire_dialogue_response": "b2adda8b152dc608",
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

    def test_fire_dialogue_points_toward_the_gap(self) -> None:
        text = read_game_font_text(DIALOGUE_SCREEN, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("heading south toward the Gap", text)
        self.assertIn("wt14_gap_dialogue_next", self.marks)

    def test_gap_dialogue_advances_to_chasm_scene(self) -> None:
        text = read_game_font_text(GAP_SCREEN, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("A gigantic chasm divides northern and southern Xanth", text)
        self.assertIn("wt14_gap_dialogue_answer", self.marks)
        answer = read_game_font_text(GAP_ANSWER_SCREEN, DATA / "XANTH_10.FNT", 30, 110)
        self.assertIn("Water", answer)
        self.assertIn("Air", answer)

    def test_game_save_overwrites_the_anchor(self) -> None:
        data = (SAVES / "XANTH000.SAV").read_bytes()
        self.assertNotEqual(hashlib.sha256(data).hexdigest(), ANCHOR_SLOT_SHA256)
        self.assertEqual(struct.unpack_from("<H", data, 0x347D)[0], 275)

    def test_275_point_save_continues_to_flapping_wings_chamber(self) -> None:
        slot = SAVES / "XANTH000.SAV"
        before = hashlib.sha256(slot.read_bytes()).hexdigest()
        self.assertEqual(struct.unpack_from("<H", slot.read_bytes(), 0x347D)[0], 275)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(CONTINUATION_TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        out = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, out[-4000:])
        self.assertIn("fault                 : ok", out)
        self.assertIn("MCB chain valid       : yes", out)
        marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", out))
        self.assertEqual(marks.get("wt15_flapping_wings"), "8083725b37faaaa2")
        room = read_game_font_text(
            ROOT / "build" / "frames" / "wt15_flapping_wings.bmp",
            DATA / "XANTH_10.FNT", 130, 160,
        )
        self.assertIn("You're in a dimly lit chamber within an ancient barrow", room)
        self.assertIn("sound like that of flapping wings", room)
        self.assertEqual(hashlib.sha256(slot.read_bytes()).hexdigest(), before)

    def test_275_point_save_enters_fire_lake(self) -> None:
        slot = SAVES / "XANTH000.SAV"
        save_data = slot.read_bytes()
        before = hashlib.sha256(save_data).hexdigest()
        self.assertEqual(before, "901998237900d1665a78bfcc42cb0f067045c49806edc336efbed7bd062647df")
        self.assertEqual(struct.unpack_from("<H", save_data, 0x347D)[0], 275)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(FIRE_TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        out = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, out[-4000:])
        self.assertIn("fault                 : ok", out)
        self.assertIn("MCB chain valid       : yes", out)
        marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", out))
        self.assertEqual(marks.get("wt16_fire_lake"), "5d6d67ae69300dd3")
        text = read_game_font_text(
            ROOT / "build" / "frames" / "wt16_fire_lake.bmp",
            DATA / "XANTH_10.FNT", 125, 160,
        )
        self.assertIn("You stand before a bubbling lake of lava", text)
        self.assertIn("narrow path", text)
        self.assertIn("southeast", text)
        self.assertEqual(hashlib.sha256(slot.read_bytes()).hexdigest(), before)

    def test_275_point_save_reaches_firewall_after_mack_clue(self) -> None:
        slot = SAVES / "XANTH000.SAV"
        save_data = slot.read_bytes()
        before = hashlib.sha256(save_data).hexdigest()
        self.assertEqual(before, "901998237900d1665a78bfcc42cb0f067045c49806edc336efbed7bd062647df")
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(FIREWALL_TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        out = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, out[-4000:])
        self.assertIn("fault                 : ok", out)
        self.assertIn("MCB chain valid       : yes", out)
        marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", out))
        self.assertEqual(marks.get("wt18_firewall"), "dc10de12e2f8098d")
        text = read_game_font_text(
            ROOT / "build" / "frames" / "wt18_firewall.bmp",
            DATA / "XANTH_10.FNT", 20, 160,
        )
        self.assertIn("impenetrable wall of fire", text)
        self.assertIn("piece of charcoal lies on the ground", text)
        self.assertEqual(hashlib.sha256(slot.read_bytes()).hexdigest(), before)

    def test_275_point_save_resolves_fireman_hotdog_and_mack_clue(self) -> None:
        slot = SAVES / "XANTH000.SAV"
        save_data = slot.read_bytes()
        before = hashlib.sha256(save_data).hexdigest()
        self.assertEqual(before, "901998237900d1665a78bfcc42cb0f067045c49806edc336efbed7bd062647df")
        self.assertEqual(struct.unpack_from("<H", save_data, 0x347D)[0], 275)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(FIREMAN_TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        out = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, out[-4000:])
        self.assertIn("fault                 : ok", out)
        self.assertIn("MCB chain valid       : yes", out)
        marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", out))
        self.assertEqual(marks.get("wt17_fireman_scene"), "c22b2662b3ab3f89")
        self.assertEqual(marks.get("wt17_hotdog"), "45b9ee7358e095a8")
        self.assertEqual(marks.get("wt17_mack_escape"), "81735b74d7458209")
        hotdog = read_game_font_text(
            ROOT / "build" / "frames" / "wt17_hotdog.bmp",
            DATA / "XANTH_10.FNT", 100, 180,
        )
        self.assertIn("You squirt a healthy serving of mustard onto the bun", hotdog)
        self.assertIn("yelping in distress", hotdog)
        self.assertIn("15 points", hotdog)
        mack = read_game_font_text(
            ROOT / "build" / "frames" / "wt17_mack_escape.bmp",
            DATA / "XANTH_10.FNT", 20, 120,
        )
        self.assertIn("Some say that Mack hurled an explosive device", mack)
        self.assertIn("actually cracked the firewall", mack)
        self.assertEqual(hashlib.sha256(slot.read_bytes()).hexdigest(), before)


if __name__ == "__main__":
    unittest.main()
