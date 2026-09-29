"""Pin VM/native parity across the measured opening walkthrough."""

from __future__ import annotations

import os
import re
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / "original" / "XANTH.EXE"
DATA = ROOT / "game_cd" / "XANTH"
TRACE = ROOT / "tests" / "traces" / "walkthrough_01_mundania.xit"
EXPECTED_HASHES = {
    "wt_bedroom": "ace8f1a3d6b858f2",
    "wt_envelope_taken": "3d1d3d0cc740a586",
    "wt_envelope_opened": "960b3613f65c7a7b",
    "wt_letter_read": "d42f3bbea8fba840",
    "wt_postit_taken": "c8b44c4bf818789a",
    "wt_hall_dark": "e588dc6d2b9310d3",
    "wt_switch_selected": "e2d143f236ce01fd",
    "wt_hall_lit": "97f9e701c6e4caeb",
    "wt_kitchen": "9bf28b959bf3425b",
}
METRIC_PATTERNS = {
    "instructions": r"^instructions executed\s*:\s*(\d+)$",
    "timer_ticks": r"^timer ticks delivered\s*:\s*(\d+)$",
    "dac_writes": r"^DAC writes\s*:\s*(\d+)$",
    "opl_writes": r"^OPL register writes\s*:\s*(\d+)$",
    "input_waits": r"^input waits\s*:\s*(\d+)$",
    "opened_files": r"^files opened\s*:(.*)$",
}


class OpeningNativeParityTests(unittest.TestCase):
    def test_opening_route_matches_vm_and_dispatches_recovered_record_walk(self) -> None:
        if not EXE.is_file() or not DATA.is_dir():
            self.skipTest("matching retail game files are not installed")
        if not TRACE.is_file():
            self.skipTest("opening walkthrough trace is not installed")

        tool = Path(os.environ["XANTH_VMBOOT"])
        outputs: dict[str, dict[str, object]] = {}
        with tempfile.TemporaryDirectory(prefix="xanth-stage2-opening-") as tmp:
            base = Path(tmp)
            for mode, flags in (("vm", ["--vm-only"]), ("native", [])):
                saves = base / f"saves-{mode}"
                saves.mkdir()
                proc = subprocess.run(
                    [
                        str(tool), "--exe", str(EXE), "--data", str(DATA),
                        "--saves", str(saves), "--script", str(TRACE),
                        "--insns", "2000000000", *flags,
                    ],
                    cwd=ROOT,
                    env={
                        **os.environ,
                        "SDL_VIDEODRIVER": "dummy",
                        "SDL_AUDIODRIVER": "dummy",
                    },
                    check=False,
                    capture_output=True,
                    text=True,
                    timeout=300,
                )
                output = proc.stdout + proc.stderr
                self.assertEqual(proc.returncode, 0, output[-3000:])
                self.assertIn("fault                 : ok", output)
                self.assertIn("MCB chain valid       : yes", output)
                hashes = dict(re.findall(
                    r"\[script\] hash (\S+) = ([0-9a-f]+)", output
                ))
                metrics = {
                    name: re.search(pattern, output, re.MULTILINE).group(1)
                    if re.search(pattern, output, re.MULTILINE) else None
                    for name, pattern in METRIC_PATTERNS.items()
                }
                hits = re.search(r"\[native\] exe_112711 hits: (\d+)", output)
                outputs[mode] = {
                    "hashes": hashes,
                    "metrics": metrics,
                    "hits": hits.group(1) if hits else None,
                }

        self.assertEqual(outputs["vm"]["hashes"], EXPECTED_HASHES)
        self.assertEqual(outputs["native"]["hashes"], EXPECTED_HASHES)
        self.assertEqual(outputs["vm"]["metrics"], outputs["native"]["metrics"])
        self.assertGreater(int(outputs["native"]["hits"] or 0), 0)


if __name__ == "__main__":
    unittest.main()
