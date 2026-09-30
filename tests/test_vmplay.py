"""Gameplay regression: the retail game reaches its first room under the VM.

This is the milestone that separates "boots" from "runs the game". It drives
the real XANTH.EXE through the Legend logo, the title, and the Restore prompt,
into the first Mundania room, and checks the result by frame hash.

Golden values are hashes of the framebuffer plus the DAC palette -- never
pixels, because a golden screenshot would be shipping copyrighted artwork.

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
TRACE = PROJECT_ROOT / "tests" / "traces" / "reach_first_room.xit"

# Hash of the first room (Dug's computer desk), framebuffer + palette.
# Regenerate deliberately, never to make a red test pass: a change here means
# the game is rendering something different.
GOLDEN_FIRST_ROOM = "3ec4adf60ff311da"

BUDGET = 2_000_000_000


# A private, freshly emptied save directory.
#
# Not tidiness: the game reads RESTART.DAT and globs *.SAV at boot, so
# leftovers from a previous run change what it loads and therefore change the
# frame hashes. Sharing a save directory with an interactive session is enough
# to make these tests flap.
SAVES = PROJECT_ROOT / "build" / "vmplay_saves"


def run_trace(trace: Path, fresh: bool = True) -> tuple[str, int]:
    if fresh:
        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
    proc = subprocess.run(
        [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
         "--saves", str(SAVES),
         "--script", str(trace), "--insns", str(BUDGET)],
        capture_output=True, text=True, timeout=900,
    )
    return proc.stdout + proc.stderr, proc.returncode


def checkpoints(text: str) -> dict:
    return {m.group(1): m.group(2)
            for m in re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)", text)}


class FirstRoomTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "input trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(
                f"{TOOL} not built; run scripts/build_port.sh first")
        cls.out, cls.rc = run_trace(TRACE)
        cls.marks = checkpoints(cls.out)

    def test_run_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-3000:]}")
        self.assertEqual(self.rc, 0)

    def test_loaded_the_room_assets(self) -> None:
        """The room art and its hotspot regions, loaded by the game itself."""
        out = self.out.upper()
        for asset in ("XANTH_02.PIC", "XANTH_02.RGN"):
            self.assertIn(asset, out, f"the game never loaded {asset}")

    def test_reached_the_first_room(self) -> None:
        self.assertIn("first_room", self.marks, "checkpoint never reached")
        self.assertEqual(
            self.marks["first_room"], GOLDEN_FIRST_ROOM,
            "the first room no longer renders identically. If this change is "
            "intended, look at build/frames/first_room.bmp and update the "
            "golden hash deliberately -- do not just paste the new value.")

    def test_is_deterministic(self) -> None:
        """Same trace twice must produce identical hashes.

        Non-determinism silently invalidates every golden hash downstream, and
        the historical failure mode is to 'fix' the resulting flake by
        loosening the assertion. It is a release blocker instead.
        """
        out2, _ = run_trace(TRACE)
        self.assertEqual(checkpoints(out2), self.marks,
                         "two identical runs produced different frames")


class InteractionTests(unittest.TestCase):
    """The game responds to verb-then-object clicks with real parser output.

    This is the gate that separates "renders a room" from "is playable". It
    depends on DOS services returning status in the FLAGS image on the stack
    rather than the live flags register -- without that the retail keyboard
    check misreads ZF, calls the blocking read with an empty queue, and the
    game never reaches its input loop at all.
    """

    TRACE = PROJECT_ROOT / "tests" / "traces" / "interact_room.xit"

    # Selecting a verb and clicking an object must each change the screen.
    GOLDEN = {
        "room_idle": "ace8f1a3d6b858f2",
        "verb_take": "0c26affc320f0d17",
        "took_computer": "e8ae412501bc4d7c",
    }

    @classmethod
    def setUpClass(cls) -> None:
        for path in (EXE, DATA, cls.TRACE):
            if not path.exists():
                raise unavailable(f"not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")
        cls.out, cls.rc = run_trace(cls.TRACE)
        cls.marks = checkpoints(cls.out)

    def test_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out)

    def test_all_checkpoints_reached(self) -> None:
        for name in self.GOLDEN:
            self.assertIn(name, self.marks, f"checkpoint {name} never reached")

    def test_selecting_a_verb_changes_the_screen(self) -> None:
        self.assertNotEqual(self.marks["verb_take"], self.marks["room_idle"],
                            "clicking the Take verb had no effect")

    def test_clicking_an_object_changes_the_screen(self) -> None:
        self.assertNotEqual(self.marks["took_computer"], self.marks["verb_take"],
                            "clicking the computer produced no response")

    def test_matches_golden_frames(self) -> None:
        for name, want in self.GOLDEN.items():
            self.assertEqual(
                self.marks[name], want,
                f"{name} renders differently. If intended, inspect "
                f"build/frames/interact_result.bmp and update deliberately.")


if __name__ == "__main__":
    unittest.main()
