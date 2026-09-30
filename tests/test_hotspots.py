"""Hotspots: the room is richly populated, not a flat picture.

Moving the cursor over the picture window makes the game name the object
underneath it -- "computer", "screen", and so on -- drawn along the bottom of
the viewport. That naming is driven by the region data in XANTH_02.RGN and the
object table in OBJECT.DAT, both parsed by the game itself.

The test sweeps a 9x5 grid across the picture and counts how many *distinct*
label states appear. A flat or broken hotspot layer would collapse to one or
two states; the real room produces well over a dozen.

Counting distinct states rather than reading the text keeps this robust: it
does not depend on OCR, on exact pixel positions of any one object, or on the
label wording, while still failing loudly if the hotspot layer stops working.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import os
import shutil
import struct
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
TRACE = PROJECT_ROOT / "tests" / "traces" / "hover.xit"
FRAMES = PROJECT_ROOT / "build" / "frames"
SAVES = PROJECT_ROOT / "build" / "hotspot_saves"

BUDGET = 2_500_000_000

# The label strip along the bottom of the picture window.
STRIP_X0, STRIP_X1 = 44, 316
STRIP_Y0, STRIP_Y1 = 104, 120


def label_strip(path: Path) -> bytes:
    raw = path.read_bytes()
    off = struct.unpack_from("<I", raw, 10)[0]
    w = struct.unpack_from("<i", raw, 18)[0]
    h = struct.unpack_from("<i", raw, 22)[0]
    return b"".join(
        raw[off + (h - 1 - y) * w * 3 + STRIP_X0 * 3:
            off + (h - 1 - y) * w * 3 + STRIP_X1 * 3]
        for y in range(STRIP_Y0, STRIP_Y1)
    )


class HotspotTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "hover trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")

        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
        for stale in FRAMES.glob("hv_*.bmp"):
            stale.unlink()

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=1200,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.shots = sorted(FRAMES.glob("hv_*.bmp"))
        cls.states = {label_strip(p) for p in cls.shots}

    def test_no_fault(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early:\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_the_sweep_completed(self) -> None:
        self.assertGreaterEqual(len(self.shots), 40,
                                "the hover sweep did not finish; check the "
                                "instruction budget")

    def test_the_game_loaded_the_region_data(self) -> None:
        self.assertIn("XANTH_02.RGN", self.out.upper())
        self.assertIn("OBJECT.DAT", self.out.upper())

    def test_many_distinct_hotspots(self) -> None:
        """A broken hotspot layer collapses to one or two states."""
        self.assertGreaterEqual(
            len(self.states), 10,
            f"only {len(self.states)} distinct label states across "
            f"{len(self.shots)} hover positions — the hotspot layer looks "
            f"inert")


if __name__ == "__main__":
    unittest.main()
