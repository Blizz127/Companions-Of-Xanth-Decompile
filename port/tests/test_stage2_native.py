"""Compare the first native source hook with the interpreted retail path."""

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
CHECKPOINT = "run 200\ncheckpoint stage2_boot\n"


class NativeStage2ParityTests(unittest.TestCase):
    def test_recovered_set_int_and_zero_matches_vm_at_boot_checkpoint(self) -> None:
        tool = Path(os.environ["XANTH_VMBOOT"])
        if not EXE.is_file() or not DATA.is_dir():
            self.skipTest("matching retail game files are not installed")

        with tempfile.TemporaryDirectory(prefix="xanth-stage2-parity-") as tmp:
            base = Path(tmp)
            trace = base / "checkpoint.xit"
            trace.write_text(CHECKPOINT, encoding="ascii")
            outputs: dict[str, dict[str, str | None]] = {}

            for mode, flags in (("vm", ["--vm-only"]), ("native", [])):
                saves = base / f"saves-{mode}"
                saves.mkdir()
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
                frame = re.search(r"\[script\] hash stage2_boot = ([0-9a-f]+)", output)
                self.assertIsNotNone(frame, output[-3000:])
                hit = re.search(r"\[native\] set_int_and_zero hits: (\d+)", output)
                far_hit = re.search(r"\[native\] set_far_ptr hits: (\d+)", output)
                lift_hit = re.search(r"\[native\] exe_94712 hits: (\d+)", output)
                helper_hit = re.search(
                    r"\[native\] if0_helper_inc fast-return hits: (\d+)", output
                )
                table_hit = re.search(r"\[native\] exe_14360 hits: (\d+)", output)
                far_arr_hit = re.search(r"\[native\] set_far_arr hits: (\d+)", output)
                far_idx_hit = re.search(r"\[native\] get_far_idx hits: (\d+)", output)
                reset_hit = re.search(r"\[native\] exe_37625 hits: (\d+)", output)
                table_state_hit = re.search(r"\[native\] exe_99679 hits: (\d+)", output)
                getter_hit = re.search(r"\[native\] exe_86810 hits: (\d+)", output)
                far_getter_hit = re.search(r"\[native\] exe_84866 hits: (\d+)", output)
                metrics = {
                    "frame": frame.group(1),
                    "set_int_and_zero_hits": hit.group(1) if hit else None,
                    "set_far_ptr_hits": far_hit.group(1) if far_hit else None,
                    "exe_94712_hits": lift_hit.group(1) if lift_hit else None,
                    "if0_helper_inc_hits": helper_hit.group(1) if helper_hit else None,
                    "exe_14360_hits": table_hit.group(1) if table_hit else None,
                    "set_far_arr_hits": far_arr_hit.group(1) if far_arr_hit else None,
                    "get_far_idx_hits": far_idx_hit.group(1) if far_idx_hit else None,
                    "exe_37625_hits": reset_hit.group(1) if reset_hit else None,
                    "exe_99679_hits": table_state_hit.group(1) if table_state_hit else None,
                    "exe_86810_hits": getter_hit.group(1) if getter_hit else None,
                    "exe_84866_hits": far_getter_hit.group(1) if far_getter_hit else None,
                }
                for name, pattern in (
                    ("instructions", r"^instructions executed\s*:\s*(\d+)$"),
                    ("timer_ticks", r"^timer ticks delivered\s*:\s*(\d+)$"),
                    ("dac_writes", r"^DAC writes\s*:\s*(\d+)$"),
                    ("opl_writes", r"^OPL register writes\s*:\s*(\d+)$"),
                    ("input_waits", r"^input waits\s*:\s*(\d+)$"),
                    ("opened_files", r"^files opened\s*:\s*(.*)$"),
                ):
                    value = re.search(pattern, output, re.MULTILINE)
                    self.assertIsNotNone(value, output[-3000:])
                    metrics[name] = value.group(1)
                outputs[mode] = metrics

            self.assertEqual(
                {key: value for key, value in outputs["vm"].items()
                 if not key.endswith("_hits")},
                {key: value for key, value in outputs["native"].items()
                 if not key.endswith("_hits")},
            )
            self.assertIsNone(outputs["vm"]["set_int_and_zero_hits"])
            self.assertEqual(outputs["native"]["set_int_and_zero_hits"], "1")
            self.assertIsNone(outputs["vm"]["set_far_ptr_hits"])
            self.assertEqual(outputs["native"]["set_far_ptr_hits"], "1")
            self.assertIsNone(outputs["vm"]["exe_94712_hits"])
            self.assertGreater(int(outputs["native"]["exe_94712_hits"]), 0)
            self.assertIsNone(outputs["vm"]["if0_helper_inc_hits"])
            self.assertGreater(int(outputs["native"]["if0_helper_inc_hits"]), 0)
            self.assertIsNone(outputs["vm"]["exe_14360_hits"])
            self.assertGreater(int(outputs["native"]["exe_14360_hits"]), 0)
            self.assertIsNone(outputs["vm"]["set_far_arr_hits"])
            self.assertGreater(int(outputs["native"]["set_far_arr_hits"]), 0)
            self.assertIsNone(outputs["vm"]["get_far_idx_hits"])
            self.assertGreater(int(outputs["native"]["get_far_idx_hits"]), 0)
            self.assertIsNone(outputs["vm"]["exe_37625_hits"])
            self.assertGreater(int(outputs["native"]["exe_37625_hits"]), 0)
            self.assertIsNone(outputs["vm"]["exe_99679_hits"])
            self.assertGreater(int(outputs["native"]["exe_99679_hits"]), 0)

    def test_recovered_getters_match_during_interaction(self) -> None:
        tool = Path(os.environ["XANTH_VMBOOT"])
        interaction = ROOT / "tests" / "traces" / "interact_room.xit"
        if not EXE.is_file() or not DATA.is_dir() or not interaction.is_file():
            self.skipTest("retail files or interaction trace are not installed")

        expected_hashes = {
            "room_idle": "ace8f1a3d6b858f2",
            "verb_take": "0c26affc320f0d17",
            "took_computer": "e8ae412501bc4d7c",
        }
        source = "\n".join(
            line for line in interaction.read_text(encoding="ascii").splitlines()
            if not line.startswith("shot ")
        ) + "\n"

        with tempfile.TemporaryDirectory(prefix="xanth-stage2-interaction-") as tmp:
            base = Path(tmp)
            trace = base / "interaction_no_shot.xit"
            trace.write_text(source, encoding="ascii")
            outputs: dict[str, dict[str, object]] = {}

            for mode, flags in (("vm", ["--vm-only"]), ("native", [])):
                saves = base / f"saves-{mode}"
                saves.mkdir()
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
                hashes = dict(re.findall(
                    r"\[script\] hash (\S+) = ([0-9a-f]+)", output
                ))
                metrics: dict[str, object] = {"hashes": hashes}
                for name, pattern in (
                    ("instructions", r"^instructions executed\s*:\s*(\d+)$"),
                    ("timer_ticks", r"^timer ticks delivered\s*:\s*(\d+)$"),
                    ("dac_writes", r"^DAC writes\s*:\s*(\d+)$"),
                    ("opl_writes", r"^OPL register writes\s*:\s*(\d+)$"),
                    ("input_waits", r"^input waits\s*:\s*(\d+)$"),
                    ("opened_files", r"^files opened\s*:(.*)$"),
                ):
                    value = re.search(pattern, output, re.MULTILINE)
                    self.assertIsNotNone(value, output[-3000:])
                    metrics[name] = value.group(1)
                if mode == "native":
                    for name, label in (
                        ("exe_86810", "exe_86810"),
                        ("exe_84866", "exe_84866"),
                        ("set_int_pair_a", "set_int_pair A"),
                        ("set_int_pair_b", "set_int_pair B"),
                        ("set_int_a", "set_int A"),
                        ("set_int_b", "set_int B"),
                    ):
                        hit = re.search(rf"\[native\] {label} hits: (\d+)", output)
                        self.assertIsNotNone(hit, output[-3000:])
                        metrics[f"{name}_hits"] = hit.group(1)
                outputs[mode] = metrics

            self.assertEqual(outputs["vm"]["hashes"], expected_hashes)
            self.assertEqual(outputs["native"]["hashes"], expected_hashes)
            self.assertEqual(
                {key: value for key, value in outputs["vm"].items()
                 if not key.endswith("_hits")},
                {key: value for key, value in outputs["native"].items()
                 if not key.endswith("_hits")},
            )
            self.assertEqual(outputs["native"]["exe_86810_hits"], "517")
            self.assertEqual(outputs["native"]["exe_84866_hits"], "17")
            pair_a_hits = int(outputs["native"]["set_int_pair_a_hits"])
            pair_b_hits = int(outputs["native"]["set_int_pair_b_hits"])
            # These hooks intentionally fall back to the interpreter at timer/DMA edges.
            self.assertGreater(pair_a_hits, 0)
            self.assertLessEqual(pair_a_hits, 988)
            self.assertGreater(pair_b_hits, 0)
            self.assertLessEqual(pair_b_hits, 66)
            set_a_hits = int(outputs["native"]["set_int_a_hits"])
            set_b_hits = int(outputs["native"]["set_int_b_hits"])
            self.assertGreater(set_a_hits, 0)
            self.assertLessEqual(set_a_hits, 36)
            self.assertGreater(set_b_hits, 0)
            self.assertLessEqual(set_b_hits, 2)


if __name__ == "__main__":
    unittest.main()
