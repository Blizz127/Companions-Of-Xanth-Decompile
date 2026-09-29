"""Walkthrough segment 9: the trapped pail through Fairy Nuff's recipe.

Starts from the village-center anchor, replays segment 8 (the panel
already reads 102, bucket still on the path), then Takes the pail.
The new line is the handle, the rock, and 7 points -- not 102 again.
Northeast twice to the Eye Screen, read the letter and put it back,
ask the eye for Fairy Nuff, open the screen and the door, take the
tee and the egg, and read the recipe. The status panel then reads
122 of 1000: 109 after the pail, plus the tee (3), the egg (2) and
the recipe (8). Getting past the screen did not post the published
12.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import re
import shutil
import subprocess
import unittest
from pathlib import Path

from tests.font_ocr import read_game_font_text
from tests.test_walkthrough_isthmus import prepare_village_anchor

PROJECT_ROOT = Path(__file__).resolve().parent.parent
EXE = PROJECT_ROOT / "original" / "XANTH.EXE"
DATA = PROJECT_ROOT / "game_cd" / "XANTH"
TOOL = PROJECT_ROOT / "build" / "tool_vmboot"
TRACE = PROJECT_ROOT / "tests" / "traces" / "walkthrough_09_pail.xit"
ANCHOR = PROJECT_ROOT / "build" / "anchor_isthmus_village"
SAVES = PROJECT_ROOT / "build" / "agent_pail"
PAIL = PROJECT_ROOT / "build" / "frames" / "wt9_pail.bmp"
SCORE = PROJECT_ROOT / "build" / "frames" / "wt9_score.bmp"

# Measured: segment 8 is 6.972e9 instructions and the recipe is a
# little past 8e9. A short budget truncates silently.
BUDGET = 14_000_000_000

# Checkpoint order is the order the trace reaches them. Two consecutive
# runs produced these hashes; they are pinned, not guessed.
ORDER = [
    "wt9_pail",
    "wt9_eye",
    "wt9_letter",
    "wt9_tee",
    "wt9_booth",
    "wt9_recipe",
    "wt9_score",
]

GOLDEN = {
    "wt9_pail":   "2dc2c115885abb5e",
    "wt9_eye":    "55d7fdb18c7f534c",
    "wt9_letter": "a24e59d2fae10145",
    "wt9_tee":    "9f91bab1598ac98e",
    "wt9_booth":  "45db2417767fad3c",
    "wt9_recipe": "73e6d3820f00af45",
    "wt9_score":  "532a530b96e94ea4",
}


def _band_text(path: Path, y0: int, y1: int) -> str:
    """Read a band of the frame with the game's UI font (XANTH_10.FNT)."""
    return read_game_font_text(
        path, DATA / "XANTH_10.FNT", y0, y1,
        channel_thresholds=(180, 180, 160), x_start=36,
    )


class PailRecipeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "walkthrough trace")):
            if not path.exists():
                raise unittest.SkipTest(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unittest.SkipTest(f"{TOOL} not built")
        prepare_village_anchor()
        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
        for name in ("LEGEND.INI", "RESTART.DAT", "XANTH000.SAV"):
            shutil.copy(ANCHOR / name, SAVES / name)
        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = {m.group(1): m.group(2) for m in
                     re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)",
                                 cls.out)}

    def test_segment_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_guest_heap_intact(self) -> None:
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_all_checkpoints_reached(self) -> None:
        for name in ORDER:
            self.assertIn(name, self.marks,
                          f"never reached {name} -- if the route is right, "
                          f"suspect BUDGET")

    def test_each_checkpoint_changes_the_world(self) -> None:
        for prev, name in zip(ORDER, ORDER[1:]):
            self.assertNotEqual(
                self.marks[prev], self.marks[name],
                f"{name} is the same frame as {prev}")

    def test_matches_golden_frames(self) -> None:
        for name, want in GOLDEN.items():
            self.assertEqual(
                self.marks[name], want,
                f"{name} renders differently. If intended, inspect "
                f"build/frames/wt9_recipe.bmp and update deliberately -- "
                f"never just to make this pass.")

    def test_the_recipe_is_not_still_the_meadow(self) -> None:
        self.assertNotEqual(self.marks["wt9_recipe"],
                            self.marks["wt9_pail"])
        self.assertNotEqual(self.marks["wt9_recipe"],
                            self.marks["wt9_booth"],
                            "Fairy Nuff never handed over the recipe")

    def test_taking_the_pail_prints_seven_points(self) -> None:
        """The panel was already 102. The new line is the take itself."""
        self.assertTrue(PAIL.exists(), "the pail frame was not written")
        text = _band_text(PAIL, 128, 156)
        self.assertIn("pail", text.lower(),
                      f"take line did not name the pail:\n{text}")
        self.assertIn("7", text, f"take line did not award 7:\n{text}")
        self.assertIn("points", text,
                      f"take line was not a score message:\n{text}")

    def test_score_is_one_hundred_twenty_two(self) -> None:
        """109 after the pail, then the tee, the egg and the recipe."""
        self.assertTrue(SCORE.exists(), "the score frame was not written")
        text = _band_text(SCORE, 40, 90)
        self.assertIn("122", text, f"score panel did not show 122:\n{text}")
        self.assertIn("points", text,
                      f"score panel was not the status text:\n{text}")


if __name__ == "__main__":
    unittest.main()
