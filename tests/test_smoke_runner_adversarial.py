#!/usr/bin/env python3
"""Automated Empirical Adversarial Test Harness for Engine Smoke Runner and Audio Subsystem."""

import os
import subprocess
import tempfile
import time
import unittest

ROOT_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
BIN_PATH = os.path.join(ROOT_DIR, "build", "xanth_port")
TEST_STRESS_BIN = os.path.join(ROOT_DIR, "build", "test_stress_audio_engine")

class TestSmokeRunnerAdversarial(unittest.TestCase):
    """Empirical adversarial verification of engine smoke runner."""

    @classmethod
    def setUpClass(cls):
        if not os.path.exists(BIN_PATH):
            raise RuntimeError(f"Executable not found at {BIN_PATH}. Run build first.")

    def run_cmd(self, args, timeout=5, cwd=ROOT_DIR):
        cmd = [BIN_PATH] + args
        start = time.monotonic()
        try:
            p = subprocess.run(
                cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                timeout=timeout,
                cwd=cwd
            )
            duration = time.monotonic() - start
            return p.returncode, p.stdout, p.stderr, duration, False
        except subprocess.TimeoutExpired as e:
            duration = time.monotonic() - start
            stdout = e.stdout.decode("utf-8", errors="replace") if e.stdout else ""
            stderr = e.stderr.decode("utf-8", errors="replace") if e.stderr else ""
            return 124, stdout, stderr, duration, True

    def test_frames_0_infinite_loop_vulnerability(self):
        """--frames 0 enters infinite loop because max_frames=0 is interpreted as unconstrained."""
        rc, out, err, dur, timed_out = self.run_cmd(["--headless", "--frames", "0", "--test-boot"], timeout=2)
        self.assertTrue(timed_out, "--frames 0 must time out due to infinite loop bug")
        self.assertEqual(rc, 124)

    def test_frames_1_premature_boot_success(self):
        """--frames 1 emits BOOT_SUCCESS on 0% pixel ratio because ratio check is guarded by frames >= 50."""
        rc, out, err, dur, timed_out = self.run_cmd(["--headless", "--frames", "1", "--test-boot"], timeout=3)
        self.assertEqual(rc, 0)
        self.assertIn("non-black pixel ratio = 0.0%", out)
        self.assertIn("BOOT_SUCCESS", out)

    def test_frames_49_vs_50_off_by_one_flaw(self):
        """Frame 49 passes (skips check), Frame 50 FAILS with code 2 due to off-by-one phase transition, Frame 51 passes."""
        # Frame 49: Skips check, emits BOOT_SUCCESS with 0.0% pixels
        rc49, out49, _, _, _ = self.run_cmd(["--headless", "--frames", "49", "--test-boot"], timeout=3)
        self.assertEqual(rc49, 0)
        self.assertIn("non-black pixel ratio = 0.0%", out49)
        self.assertIn("BOOT_SUCCESS", out49)

        # Frame 50: Loop terminates BEFORE frame 50 renders title screen, triggers check, FAILS with exit code 2
        rc50, out50, err50, _, _ = self.run_cmd(["--headless", "--frames", "50", "--test-boot"], timeout=3)
        self.assertEqual(rc50, 2)
        self.assertIn("[FAIL] Non-black pixel ratio 0.0% <= 20%", err50)

        # Frame 51: Frame 50 executed and rendered title banner, passes with 100.0% pixels
        rc51, out51, _, _, _ = self.run_cmd(["--headless", "--frames", "51", "--test-boot"], timeout=3)
        self.assertEqual(rc51, 0)
        self.assertIn("non-black pixel ratio = 100.0%", out51)
        self.assertIn("BOOT_SUCCESS", out51)

    def test_frames_1000_cpu_busy_wait(self):
        """--frames 1000 completes 1000 frames; verifies exit code 0."""
        rc, out, err, dur, timed_out = self.run_cmd(["--headless", "--frames", "1000", "--test-boot"], timeout=25)
        self.assertFalse(timed_out)
        self.assertEqual(rc, 0)
        self.assertIn("Frame 1000 reached", out)
        self.assertIn("BOOT_SUCCESS", out)

    def test_nocycle_flag(self):
        """--nocycle disables palette cycling and completes cleanly."""
        rc, out, err, dur, timed_out = self.run_cmd(["--headless", "--frames", "60", "--nocycle", "--test-boot"], timeout=5)
        self.assertEqual(rc, 0)
        self.assertIn("BOOT_SUCCESS", out)

    def test_invalid_cli_arguments(self):
        """Invalid arguments are rejected with exit code 1."""
        cases = [
            ["--frames"],
            ["--frames", "not_a_number"],
            ["--frames", "-25"],
            ["--data"],
            ["--saves"],
        ]
        for c in cases:
            rc, out, err, _, _ = self.run_cmd(c, timeout=2)
            self.assertEqual(rc, 1, f"Expected exit code 1 for args {c}, got {rc}")
            self.assertIn("[ERROR]", err)

    def test_missing_and_corrupt_asset_decoupling(self):
        """Adversarial configuration: missing or corrupt assets still emit BOOT_SUCCESS."""
        with tempfile.TemporaryDirectory() as tmpdir:
            # Corrupted mock files
            with open(os.path.join(tmpdir, "XANTH.OVL"), "wb") as f:
                f.write(b"CORRUPT")
            with open(os.path.join(tmpdir, "OBJECT.DAT"), "wb") as f:
                f.write(b"BAD")
            with open(os.path.join(tmpdir, "XANTHSTR.DAT"), "wb") as f:
                f.write(b"BAD")

            rc, out, err, _, _ = self.run_cmd(
                ["--headless", "--frames", "60", "--data", tmpdir, "--test-boot"],
                timeout=5
            )
            # The engine logs size mismatches, but still emits BOOT_SUCCESS
            self.assertIn("size mismatch", err)
            self.assertIn("BOOT_SUCCESS", out)
            self.assertEqual(rc, 0)

    def test_c_stress_test_harness_execution(self):
        """Execute the standalone C audio/engine stress harness binary."""
        p = subprocess.run([TEST_STRESS_BIN], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.assertEqual(p.returncode, 0, f"C Stress Test Harness failed:\n{p.stderr}\n{p.stdout}")
        self.assertIn("Adversarial Harness Completed: 38 passed, 0 failed.", p.stdout)

if __name__ == "__main__":
    unittest.main()
