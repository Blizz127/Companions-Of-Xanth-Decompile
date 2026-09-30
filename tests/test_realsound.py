"""Digitized effects: the phone ring opens PHONE.RS and samples move.

MUSIC= selects the device (see test_soundblaster.py). MUSIC=adlib never opens
a .RS file. MUSIC=real does, once the kitchen phone rings, and the retail
player bit-bangs the sample through PIT channel 2 (port 0x42), not the DSP.
This test fails if that file is not opened or no PCM samples are handed to
the mixer.

XANTH_VM_TOOL explicitly selects the binary when set. Otherwise the binary
is build-audio/tool_vmboot when that tree exists and is at least
as new as build/tool_vmboot, otherwise build/tool_vmboot. build/ is left
alone while other workers link it; a later `cmake --build build --target
tool_vmboot` picks this source up.

Skips cleanly when the retail executable or the asset tree is absent.
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
TRACE = PROJECT_ROOT / "tests" / "traces" / "walkthrough_02_phone.xit"
SAVES = PROJECT_ROOT / "build" / "agent_audio" / "realsound_test"

# The ring is requested during the F1 wait just after the kitchen, ~1.88e9
# instructions into this trace. Stop once that playback has had time to run.
BUDGET = 2_000_000_000

INI = ("MOUSE=mouse\r\n"
       "GAMEDATA=C:\\XANTH\\\r\n"
       "SAVEDATA=C:\\XANTH\\\r\n"
       "MUSIC=real 7 220\r\n"
       "SOUND=real 7 220\r\n")


def tool_path() -> Path | None:
    override = os.environ.get("XANTH_VM_TOOL")
    if override:
        return Path(override)
    build = PROJECT_ROOT / "build" / "tool_vmboot"
    audio = PROJECT_ROOT / "build-audio" / "tool_vmboot"
    if audio.exists() and (not build.exists()
                           or audio.stat().st_mtime >= build.stat().st_mtime):
        return audio
    if build.exists():
        return build
    return None


def counter(text: str, label: str) -> int:
    m = re.search(rf"{re.escape(label)}\s+:\s*(\d+)", text)
    return int(m.group(1)) if m else -1


class RealSoundTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "input trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        tool = tool_path()
        if tool is None:
            raise unavailable("tool_vmboot not built (build/ or build-audio/)")

        if SAVES.exists():
            shutil.rmtree(SAVES)
        SAVES.mkdir(parents=True)
        # Author the INI before the run so the VM does not write MUSIC=adlib.
        (SAVES / "LEGEND.INI").write_text(INI, newline="")

        proc = subprocess.run(
            [str(tool), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(SAVES), "--script", str(TRACE),
             "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=900,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.tool = tool

    def test_no_fault(self) -> None:
        self.assertIn("fault                 : ok", self.out,
                      f"VM stopped early ({self.tool}):\n{self.out[-2000:]}")
        self.assertEqual(self.rc, 0)

    def test_phone_rs_opened(self) -> None:
        self.assertIn("PHONE.RS", self.out.upper(),
                      f"phone effect never opened:\n{self.out[-2000:]}")

    def test_samples_reached_the_mixer(self) -> None:
        samples = counter(self.out, "RealSound samples")
        dma = counter(self.out, "DMA bytes transferred")
        self.assertTrue(samples > 1000 or dma > 0,
                        f"no digitized samples moved (rs={samples} dma={dma})")


if __name__ == "__main__":
    unittest.main()
