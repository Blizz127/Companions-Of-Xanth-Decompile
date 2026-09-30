"""Pin VM/native parity across the measured opening walkthrough."""

from __future__ import annotations

# BIOS-status fix goldens: old/new pixels independently audited on 2026-09-30;
# all differences are inside the live bedroom rain bounds (56,4)-(135,58).
# verb_take779px, took_computer658px; retail/mirrored-font opening834px each.
# Evidence: release-staging/xanth-work/alpha4-review (task940bcebbfcda).

import os
import hashlib
import re
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
DATA = Path(os.environ.get("XANTH_DATA", ROOT / "game_cd" / "XANTH"))
EXE = DATA / "XANTH.EXE"
TRACE = ROOT / "tests" / "traces" / "walkthrough_01_mundania.xit"
EXPECTED_HASHES = {
    "wt_bedroom": "fc53131750c9cb17",
    "wt_envelope_taken": "3d1d3d0cc740a586",
    "wt_envelope_opened": "a50c05cbb541c80c",
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
            self.fail(f"required retail files are missing: {EXE}")
        if not TRACE.is_file():
            self.fail(f"required opening walkthrough trace is missing: {TRACE}")

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
                hits = {
                    name: re.search(rf"\[native\] {name} hits: (\d+)", output)
                    for name in ("exe_112711", "exe_34775")
                }
                outputs[mode] = {
                    "hashes": hashes,
                    "metrics": metrics,
                    "hits": {
                        name: result.group(1) if result else None
                        for name, result in hits.items()
                    },
                }

        self.assertEqual(outputs["vm"]["hashes"], EXPECTED_HASHES)
        self.assertEqual(outputs["native"]["hashes"], EXPECTED_HASHES)
        self.assertEqual(outputs["vm"]["metrics"], outputs["native"]["metrics"])
        for name in ("exe_112711", "exe_34775"):
            self.assertGreater(int(outputs["native"]["hits"][name] or 0), 0)

    def test_picture_replacement_is_independent_and_opt_in(self) -> None:
        """A local palette mod changes pixels only with the graphics switch."""
        if not EXE.is_file() or not DATA.is_dir():
            self.fail(f"required retail files are missing: {EXE}")

        tool = Path(os.environ["XANTH_VMBOOT"])
        with tempfile.TemporaryDirectory(prefix="xanth-picture-mod-parity-") as tmp:
            base = Path(tmp)
            mods = base / "mods"
            mods.mkdir()
            replacements = 0
            for source in sorted(DATA.glob("*.PIC")):
                original = source.read_bytes()
                changed = bytearray(original)
                pos = 4
                entry_offset = struct.unpack_from("<I", changed, 0)[0]
                while entry_offset and pos + 8 <= len(changed):
                    flags = struct.unpack_from("<H", changed, pos)[0]
                    pos += 8
                    next_offset = (
                        struct.unpack_from("<I", changed, pos)[0]
                        if pos + 4 <= len(changed) else 0
                    )
                    pos += 4
                    if flags & 0x1000:
                        palette = entry_offset + (4 if flags & 1 else 0)
                        end = next_offset or len(changed)
                        self.assertLessEqual(palette + 768, end, source.name)
                        for index in range(palette, palette + 768):
                            self.assertLessEqual(changed[index], 63, source.name)
                            changed[index] = 63 - changed[index]
                    entry_offset = next_offset
                if changed != original:
                    (mods / hashlib.sha256(original).hexdigest()).write_bytes(changed)
                    replacements += 1
            self.assertGreater(replacements, 0)

            trace = base / "opening.xit"
            trace_template = (
                "run 60\nkey 32\nrun 40\nkey 32\nrun 40\nkey 32\n"
                "run 60\nmove 305 196\nrun 15\n"
                "checkpoint mod_opening\nshot {shot}\n"
            )
            outputs: dict[str, tuple[str, bytes]] = {}
            modes = (
                ("retail", []),
                ("mods_disabled", ["--mods", str(mods)]),
                ("graphics_enabled", ["--mods", str(mods), "--replacement-graphics"]),
            )
            for mode, flags in modes:
                saves = base / f"saves-{mode}"
                saves.mkdir()
                shot = base / f"{mode}.bmp"
                trace.write_text(trace_template.replace("{shot}", str(shot)), encoding="ascii")
                proc = subprocess.run(
                    [
                        str(tool), "--exe", str(EXE), "--data", str(DATA),
                        "--saves", str(saves), "--script", str(trace),
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
                    timeout=180,
                )
                output = proc.stdout + proc.stderr
                self.assertEqual(proc.returncode, 0, output[-3000:])
                self.assertIn("fault                 : ok", output)
                self.assertIn("MCB chain valid       : yes", output)
                match = re.search(
                    r"\[script\] hash mod_opening = ([0-9a-f]+)", output
                )
                self.assertIsNotNone(match, output[-3000:])
                self.assertTrue(shot.is_file())
                outputs[mode] = (match.group(1), shot.read_bytes())

            self.assertEqual(outputs["retail"], outputs["mods_disabled"])
            self.assertNotEqual(outputs["retail"], outputs["graphics_enabled"])


if __name__ == "__main__":
    unittest.main()
