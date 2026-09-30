"""Boot regression for the 16-bit VM running the retail image.

This is the Stage 1 milestone gate. It asserts that the real XANTH.EXE runs
under the port's own CPU and DOS/BIOS shims far enough to load its overlays,
decode its own artwork, and render its first interactive dialog -- with no
unimplemented service and no CPU fault.

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

TRACE = PROJECT_ROOT / "tests" / "traces" / "boot_to_logo.xit"
BUDGET = 2_000_000_000


def parse_report(text: str) -> dict:
    out = {}
    for key, pattern in {
        "fault": r"fault\s+:\s*(.+)",
        "nonblack": r"framebuffer\s+:\s*(\d+)/64000",
        "colours": r"framebuffer\s+:.*?(\d+) distinct colours",
        "dac": r"DAC writes\s+:\s*(\d+)",
        "ticks": r"timer ticks delivered\s+:\s*(\d+)",
        "mcb": r"MCB chain valid\s+:\s*(\S+)",
        "insns": r"instructions executed\s+:\s*(\d+)",
    }.items():
        m = re.search(pattern, text)
        if m:
            out[key] = m.group(1).strip()
    return out


class VmBootTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        for path, what in ((EXE, "retail executable"), (DATA, "retail asset directory")):
            if not path.exists():
                raise unavailable(f"{what} not present: {path}")
        if not TOOL.exists():
            raise unavailable(
                f"{TOOL} not built; run scripts/build_port.sh first")

        proc = subprocess.run(
            [str(TOOL), "--exe", str(EXE), "--data", str(DATA),
             "--saves", str(PROJECT_ROOT / "build" / "saves"),
             "--script", str(TRACE), "--insns", str(BUDGET)],
            capture_output=True, text=True, timeout=600,
        )
        cls.out = proc.stdout + proc.stderr
        cls.rc = proc.returncode
        cls.report = parse_report(cls.out)

    def test_no_cpu_fault_or_unimplemented_service(self) -> None:
        """The whole run must complete without trapping.

        A non-'ok' fault here names exactly what to implement next -- that is
        the point of making unimplemented services fatal rather than silent.
        """
        self.assertEqual(self.report.get("fault"), "ok",
                         f"VM stopped early:\n{self.out[-3000:]}")
        self.assertEqual(self.rc, 0, "tool_vmboot exited non-zero")

    def test_reached_the_first_prompt(self) -> None:
        """The boot path ends at a real blocking read, not a crash or a spin."""
        self.assertGreater(int(self.report["insns"]), 500_000)
        self.assertIn("input waits", self.out)

    def test_overlay_and_assets_were_loaded_by_the_game(self) -> None:
        """RTLink and the game's own loaders must do the work, not the port."""
        # The game opens some names in lower case, so compare case-insensitively.
        out = self.out.upper()
        self.assertIn("XANTH.OVL", out,
                      "the RTLink overlay manager never opened XANTH.OVL")
        for asset in ("OBJECT.DAT", "XANTHSTR.DAT"):
            self.assertIn(asset, out, f"the game never loaded {asset}")

    def test_game_loaded_its_own_artwork(self) -> None:
        """The Legend logo, loaded and decoded by the game itself.

        The title banner and fonts come later in the boot sequence and are
        covered by tests/test_vmplay.py, which drives the game further in.
        """
        self.assertIn("XANTH_98.PIC", self.out.upper(),
                      "the game never loaded the Legend logo")

    def test_set_mode_13h(self) -> None:
        self.assertIn("INT 10h set mode 13", self.out,
                      "the game never switched to VGA mode 13h")

    def test_timer_interrupts_are_being_delivered(self) -> None:
        """The guest hooks INT 1Ch and paces everything from it; without
        ticks it spins forever having drawn nothing."""
        self.assertGreater(int(self.report["ticks"]), 0)

    def test_adlib_was_detected(self) -> None:
        """The card-detection handshake reads the OPL timer status; a card
        that always reads zero is reported absent and the game runs silent."""
        m = re.search(r"OPL register writes\s+:\s*(\d+)", self.out)
        self.assertIsNotNone(m, "no OPL counter in the report")
        self.assertGreater(int(m.group(1)), 100,
                           "the game did not program the synth")

    def test_the_game_rendered_its_own_artwork(self) -> None:
        """Real pixels, from the game's own decompressor, in its own palette."""
        self.assertGreater(int(self.report["nonblack"]), 1000,
                           "framebuffer is essentially empty")
        self.assertGreater(int(self.report["colours"]), 4,
                           "too few distinct colours to be real artwork")
        self.assertGreater(int(self.report["dac"]), 1000,
                           "no palette activity at all")

    def test_guest_did_not_corrupt_the_mcb_chain(self) -> None:
        self.assertEqual(self.report.get("mcb"), "yes")


if __name__ == "__main__":
    unittest.main()
