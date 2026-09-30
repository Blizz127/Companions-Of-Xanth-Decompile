"""Soak: sustained play must not fault, leak, or hit an unimplemented service.

Drives 28 verb-and-object clicks across the verb menu, the scene, the compass
and the widget buttons, with a fixed random seed so any failure is
reproducible. Roughly 1.5 billion guest instructions.

Two things make this worth its runtime. First, unimplemented host services are
fatal by default, so the soak is how a service the game only needs
occasionally gets discovered -- the DOS layer has only ever grown to fit what
this game actually calls. Second, it checks the MCB chain at exit, which
catches guest heap corruption that a short test would never provoke.

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
TRACE = PROJECT_ROOT / "tests" / "traces" / "soak.xit"
SAVES = PROJECT_ROOT / "build" / "soak_saves"

BUDGET = 4_000_000_000


class SoakTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "soak trace")):
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
            capture_output=True, text=True, timeout=1800,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode

    def _num(self, pattern: str) -> int:
        m = re.search(pattern, self.out)
        self.assertIsNotNone(m, f"missing from report: {pattern}")
        return int(m.group(1))

    def test_no_unimplemented_host_service(self) -> None:
        """The whole point of trapping loudly: if the game reaches for a
        service we have not written, the soak is where it shows up."""
        self.assertNotIn("UNIMPLEMENTED HOST SERVICE", self.out,
                         f"the game needed a service we do not provide:\n"
                         f"{self.out[-2500:]}")

    def test_no_fault(self) -> None:
        self.assertIn("fault                 : ok", self.out)
        self.assertEqual(self.rc, 0)

    def test_ran_a_substantial_workload(self) -> None:
        self.assertGreater(self._num(r"instructions executed : (\d+)"),
                           500_000_000)

    def test_the_game_stayed_interactive(self) -> None:
        """Mouse polling proves the input loop kept running rather than
        parking in a blocking read."""
        m = re.search(r"interrupts used.*?33\((\d+)\)", self.out)
        self.assertIsNotNone(m, "no INT 33h activity recorded")
        self.assertGreater(int(m.group(1)), 10_000)

    def test_guest_did_not_corrupt_its_heap(self) -> None:
        self.assertIn("MCB chain valid       : yes", self.out)

    def test_reached_the_end_of_the_trace(self) -> None:
        self.assertIn("soak_end", self.out,
                      "the soak ran out of instruction budget before "
                      "finishing; shorten the trace or raise the budget")


if __name__ == "__main__":
    unittest.main()
