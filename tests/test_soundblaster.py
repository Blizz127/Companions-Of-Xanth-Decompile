"""The Sound Blaster path: detection and DSP handshake actually run.

The port authors LEGEND.INI with `MUSIC=adlib`, which is the simpler and
known-good configuration and the one the other suites' golden hashes are
generated against. This test checks the *other* supported configuration --
`MUSIC=blaster` -- really drives the emulated Sound Blaster, so the DSP reset
handshake and command port are covered rather than merely implemented.

Finding worth recording, because it is not obvious: it is the **MUSIC=** line
that selects the Sound Blaster, not SOUND=. Instrumenting the game's device
init (`src/exe_79943.asm`, hooked at exe-code 79943) shows the mapping:

    MUSIC=quiet/real/noreal/mt32 -> device type 1
    MUSIC=adlib                  -> device type 2
    MUSIC=blaster                -> device type 4   <- the SB path

and that routine only stores a base port and IRQ when the type is 4. Every
value of SOUND= leaves the type unchanged, which is why an earlier round of
work concluded the SB "was never initialised": it was being configured on the
wrong line.

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
SAVES = PROJECT_ROOT / "build" / "sb_saves"

INI = ("MOUSE=mouse\r\n"
       "GAMEDATA=C:\\XANTH\\\r\n"
       "SAVEDATA=C:\\XANTH\\\r\n"
       "MUSIC=blaster 7 220\r\n"
       "SOUND=blaster 7 220\r\n")

BUDGET = 1_500_000_000


def counter(text: str, label: str) -> int:
    m = re.search(rf"{label}\s+:\s*(\d+)", text)
    return int(m.group(1)) if m else -1


class SoundBlasterTests(unittest.TestCase):
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
        # Author the INI ourselves so the VM does not write its default.
        (SAVES / "LEGEND.INI").write_text(INI, newline="")

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=900,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode

    def test_no_fault(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_the_dsp_was_actually_driven(self) -> None:
        """The reset handshake plus command traffic. Zero here would mean the
        card was never detected, which is exactly the state this test exists
        to stop us regressing into."""
        self.assertGreater(counter(self.out, "SB DSP port accesses"), 100)

    def test_music_still_plays(self) -> None:
        """A Sound Blaster carries an OPL, so selecting it must not silence
        the music."""
        self.assertGreater(counter(self.out, "OPL register writes"), 1000)

    def test_the_game_still_reaches_the_first_room(self) -> None:
        """Changing the audio device must not derail the boot."""
        out = self.out.upper()
        for asset in ("XANTH_02.PIC", "XANTH_02.RGN"):
            self.assertIn(asset, out, f"never loaded {asset}")

    def test_guest_heap_intact(self) -> None:
        self.assertIn("MCB chain valid       : yes", self.out)


if __name__ == "__main__":
    unittest.main()
