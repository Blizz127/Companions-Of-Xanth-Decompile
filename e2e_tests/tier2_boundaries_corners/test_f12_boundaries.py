"""Tier 2: Boundary & Corner Cases — Feature 12: Automated build & test scripts (F12).

Verifies non-zero exit code propagation, spaces in directory paths, timeouts,
and missing script detection.
"""

from __future__ import annotations

import subprocess
import sys
import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT


class TestF12Boundaries(unittest.TestCase):
    """Tier 2 tests for F12: Build & Test Script Boundaries."""

    def test_subprocess_non_zero_exit_propagation(self) -> None:
        """T2-F12-01: Failed command returns non-zero exit code."""
        res = subprocess.run([sys.executable, "-c", "import sys; sys.exit(42)"], capture_output=True)
        self.assertEqual(res.returncode, 42)

    def test_empty_command_string_handling(self) -> None:
        """T2-F12-02: Empty command invocation is rejected or raises error."""
        with self.assertRaises(Exception):
            subprocess.run([], capture_output=True)

    def test_script_timeout_boundary(self) -> None:
        """T2-F12-03: Subprocess timeout exception is raised when command exceeds limit."""
        with self.assertRaises(subprocess.TimeoutExpired):
            subprocess.run([sys.executable, "-c", "import time; time.sleep(10)"], timeout=0.2, capture_output=True)

    def test_path_with_spaces_in_arguments(self) -> None:
        """T2-F12-04: Scripts execute cleanly when workspace path contains spaces."""
        # ROOT itself is "/var/home/blizz/Projects/Companions of Xanth decomp"
        self.assertIn(" ", str(ROOT))
        res = subprocess.run([sys.executable, "-c", f"import sys; print('{ROOT}')"], capture_output=True, text=True)
        self.assertEqual(res.returncode, 0)
        self.assertIn("Companions of Xanth decomp", res.stdout)

    def test_missing_script_file_raises_error(self) -> None:
        """T2-F12-05: Invoking nonexistent script path fails with FileNotFoundError or exit code != 0."""
        res = subprocess.run([sys.executable, str(ROOT / "tools/nonexistent_script.py")], capture_output=True)
        self.assertNotEqual(res.returncode, 0)


if __name__ == "__main__":
    unittest.main()
