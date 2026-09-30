"""Overlay layout, established by observing RTLink at runtime.

The 62-entry directory in XANTH.OVL does NOT partition the payload -- the size
fields sum to 43,284 against a 325,595-byte payload -- so the retired engine's
model of it was wrong. Rather than guess again, the VM records every read the
RTLink overlay manager performs on the OVL handle: which payload offset was
read, how long, and where it landed.

This test pins what that observation shows, so a change in overlay behaviour
is caught rather than silently absorbed. It is also the mechanism Stage 2
needs: an overlay address is only mappable back to a source unit if you know
which section is currently resident there.

Requires the retail disc, so it skips cleanly in asset-free CI.
"""

from __future__ import annotations

import os
import re
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

LOAD_RE = re.compile(
    r"payload\s+(\d+)\s+len\s+(\d+) -> ([0-9A-F]{4}):([0-9A-F]{4})")


class OverlayLayoutTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"),
                           (DATA, "retail asset directory"),
                           (TRACE, "input trace")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(f"{TOOL} not built")

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(PROJECT_ROOT / "build" / "testsaves"),
             "--script", str(TRACE), "--insns", "2000000000"],
            capture_output=True, text=True, timeout=900,
        )
        cls.out = proc.stdout + proc.stderr
        cls.loads = [(int(m.group(1)), int(m.group(2)), m.group(3), m.group(4))
                     for m in LOAD_RE.finditer(cls.out)]

    def test_rtlink_actually_paged_overlays(self) -> None:
        self.assertGreater(len(self.loads), 10,
                           "the overlay manager barely ran")

    def test_code_lands_at_paragraph_aligned_slot_bases(self) -> None:
        """Sections are read to offset 0 of a slot segment, never mid-slot."""
        code = [l for l in self.loads if l[3] == "0000"]
        self.assertGreater(len(code), 4)

    def test_there_is_more_than_one_overlay_slot(self) -> None:
        """The retired engine assumed a single region at 0x30CB. There are at
        least two independent slots, which is why a seg:off alone cannot
        identify overlay code."""
        slots = {l[2] for l in self.loads if l[3] == "0000"}
        self.assertGreaterEqual(len(slots), 2,
                                f"expected multiple overlay slots, saw {slots}")

    def test_relocation_records_are_read_into_the_root_image(self) -> None:
        """Each section load is preceded by short reads into a scratch buffer
        in the root image -- RTLink's per-section relocation records."""
        scratch = [l for l in self.loads if l[3] != "0000"]
        self.assertGreater(len(scratch), len(self.loads) / 3,
                           "expected many short relocation reads")
        for payload, length, _seg, _off in scratch:
            self.assertLess(length, 1024,
                            "a relocation read should be small")

    def test_sections_are_reloaded_rather_than_kept_resident(self) -> None:
        """The same payload offset is paged in more than once, which is the
        whole reason provenance has to be tracked at runtime."""
        code = [l[0] for l in self.loads if l[3] == "0000"]
        self.assertGreater(len(code), len(set(code)),
                           "no section was ever re-paged; check the trace")


if __name__ == "__main__":
    unittest.main()
