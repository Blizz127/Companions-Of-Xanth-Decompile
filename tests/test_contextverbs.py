"""Object-first selection and context verbs -- the game's core mechanic.

Selecting an object extends the verb column with actions specific to it.
The computer screen exposes reading and touching actions below the standard
verbs. Reading describes its appearance; touching describes an interaction.
The two responses come from the game's story database.

This is a deeper check than "a click changed the screen": two different verbs
applied to the same object must produce two *different* results, which can
only happen if the parser, the object table and the story database are all
being driven by the real game.

Verb rows were measured from the rendered column rather than estimated --
Take 7, Put 17, Look at 27, Open 37, Close 47, Talk to 57, Look 67, then
context verbs at 87 and 97. Guessing them silently clicked the gaps.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import os
import re
import shutil
import subprocess
import unittest
from pathlib import Path

def unavailable(message: str) -> Exception:
    """An explicitly configured game/tool run must fail rather than skip."""
    if any(os.environ.get(key) for key in ("XANTH_DATA", "XANTH_VM_TOOL", "XANTH_MZ_TOOL")):
        return FileNotFoundError(message)
    return unittest.SkipTest(message)


PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA = Path(os.environ.get("XANTH_DATA", PROJECT_ROOT / "game_cd" / "XANTH"))
EXE = DATA / "XANTH.EXE"
TOOL = Path(os.environ.get("XANTH_VM_TOOL", PROJECT_ROOT / "build" / "tool_vmboot"))
TRACE = PROJECT_ROOT / "tests" / "traces" / "context_verbs.xit"
SAVES = PROJECT_ROOT / "build" / "ctx_saves"

# BIOS keyboard-status IF correction advances the retail rain clock.
# Independent old/new BMP comparison found zero pixel changes outside the
# verified rain rectangle (51,4)-(136,75) at every checkpoint below.
GOLDEN = {
    "read":    "c70ac4f600f877a9",
    "touch":   "577298e46f678b8c",
    "cd_open": "f867ea477f6c628c",
}

BUDGET = 2_000_000_000


class ContextVerbTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "input trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")

        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=900,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = {m.group(1): m.group(2) for m in
                     re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)", cls.out)}

    def test_no_fault(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_both_context_verbs_ran(self) -> None:
        for name in GOLDEN:
            self.assertIn(name, self.marks, f"checkpoint {name} never reached")

    def test_the_two_verbs_give_different_results(self) -> None:
        """The substance of the test: same object, different verb, different
        response. A single shared result would mean neither verb was really
        dispatched."""
        self.assertNotEqual(self.marks["read"], self.marks["touch"],
                            "Read and Touch produced identical screens")

    def test_object_state_changes_and_redraws(self) -> None:
        """Opening the CD-ROM drive is persistent state, not just a message.

        The game reports "You open the CD-ROM drive." and also draws an
        open-tray sprite over the closed-drive background, so the frame must
        differ from every earlier checkpoint in this run.
        """
        self.assertIn("cd_open", self.marks)
        self.assertNotIn(self.marks["cd_open"],
                         {self.marks["read"], self.marks["touch"]},
                         "opening the drive produced no visible change")

    def test_matches_golden_frames(self) -> None:
        for name, want in GOLDEN.items():
            self.assertEqual(
                self.marks[name], want,
                f"'{name}' renders differently. If intended, look at "
                f"build/frames/cv_{name}.bmp and update deliberately.")


if __name__ == "__main__":
    unittest.main()
