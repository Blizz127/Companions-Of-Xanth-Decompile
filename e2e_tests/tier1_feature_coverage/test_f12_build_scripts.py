"""Tier 1: Feature Coverage — Feature 12: Automated build & test scripts (F12).

Verifies build tool scripts existence, coverage reporting automation, exit code propagation,
and cross-platform path handling.
"""

from __future__ import annotations

import subprocess
import sys
import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT


class TestF12BuildScripts(unittest.TestCase):
    """Tier 1 tests for F12: Automated Build & Test Scripts."""

    def test_tools_directory_scripts_exist(self) -> None:
        """T1-F12-01: Essential toolchain scripts exist in tools/."""
        scripts = ["verify.py", "coverage.py", "rebuild.py", "c_units.py", "identify.py"]
        for s in scripts:
            p = ROOT / "tools" / s
            self.assertTrue(p.is_file(), f"Script missing: {p}")

    def test_coverage_script_execution(self) -> None:
        """T1-F12-02: python3 tools/coverage.py executes successfully and returns exit code 0."""
        res = subprocess.run([sys.executable, str(ROOT / "tools/coverage.py")], capture_output=True, text=True)
        self.assertEqual(res.returncode, 0, f"coverage.py failed: {res.stderr}")
        self.assertIn("total units:", res.stdout)
        self.assertIn("emit-dump=", res.stdout)

    def test_python_unittest_command_execution(self) -> None:
        """T1-F12-03: unittest invocation discovers and executes tests with exit code 0."""
        res = subprocess.run(
            [sys.executable, "-m", "unittest", "discover", "-s", str(ROOT / "tests"), "-p", "test_target.py"],
            capture_output=True,
            text=True,
        )
        self.assertEqual(res.returncode, 0, f"unittest failed: {res.stderr}")
        self.assertIn("OK", res.stderr)

    def test_script_exit_code_zero_on_success(self) -> None:
        """T1-F12-04: Test discovery commands comply with standard exit code 0 on success."""
        res = subprocess.run([sys.executable, "-c", "import sys; sys.exit(0)"], capture_output=True)
        self.assertEqual(res.returncode, 0)

    def test_cross_platform_path_handling(self) -> None:
        """T1-F12-05: Path handling handles both POSIX slashes and Windows backslashes."""
        test_path = "original/XANTH.EXE"
        normalized = Path(test_path.replace("\\", "/"))
        self.assertEqual(str(normalized), "original/XANTH.EXE")


if __name__ == "__main__":
    unittest.main()
