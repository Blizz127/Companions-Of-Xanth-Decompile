"""Save / restore round trip, verified by comparing save files.

The test drives the retail game's own system menu: Save the game, change the
world (WAIT), Restore, then Save again. If the restore truly reproduced the
saved state, the second save file must be byte-identical to the first apart
from the name the player typed.

That is deliberately a stronger check than comparing screenshots. Two frames
can look identical while the underlying game state differs; two save files
cannot.

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
TRACE = PROJECT_ROOT / "tests" / "traces" / "saveload.xit"
SAVES = PROJECT_ROOT / "build" / "saveload_test"

# The trace types a four-character name into the save dialog; that name is
# stored at the head of the file and is the one legitimate difference.
NAME_FIELD_LEN = 4

BUDGET = 4_000_000_000


class SaveLoadTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "input trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")

        # A clean save directory is required, not tidiness: leftover saves and
        # RESTART.DAT change what the game reads at boot, which changes the
        # frame hashes and makes the run non-reproducible.
        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=1800,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.marks = {m.group(1): m.group(2) for m in
                     re.finditer(r"\[script\] hash (\S+) = ([0-9a-f]+)", cls.out)}
        cls.saves = sorted(SAVES.glob("*.SAV"))

    def test_run_completed_without_faulting(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_two_saves_were_written(self) -> None:
        self.assertEqual(len(self.saves), 2,
                         f"expected two save files, got {[p.name for p in self.saves]}")

    def test_saves_are_the_same_size(self) -> None:
        a, b = (p.read_bytes() for p in self.saves)
        self.assertEqual(len(a), len(b))
        self.assertGreater(len(a), 1000, "a save this small cannot hold game state")

    def test_restore_reproduced_the_saved_state_exactly(self) -> None:
        """The heart of it: only the name field may differ."""
        a, b = (p.read_bytes() for p in self.saves)
        differing = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
        self.assertTrue(differing, "the two saves are identical, including the "
                                   "name field — the second save probably did "
                                   "not happen")
        self.assertLess(max(differing), NAME_FIELD_LEN,
                        f"game state differs after restore at byte offsets "
                        f"{differing[:16]}; only the leading name field "
                        f"(0..{NAME_FIELD_LEN - 1}) may differ")

    def test_the_world_actually_changed_before_restoring(self) -> None:
        """Guard against a vacuous pass: if WAIT did nothing, the round trip
        would succeed trivially."""
        self.assertIn("after_wait", self.marks)
        self.assertIn("after_save", self.marks)
        self.assertNotEqual(self.marks["after_wait"], self.marks["after_save"],
                            "WAIT did not change the screen, so this test "
                            "would prove nothing")

    def test_restore_undid_the_change(self) -> None:
        self.assertIn("after_restore", self.marks)
        self.assertNotEqual(self.marks["after_restore"], self.marks["after_wait"],
                            "the screen after restoring still matches the "
                            "changed state")


if __name__ == "__main__":
    unittest.main()
