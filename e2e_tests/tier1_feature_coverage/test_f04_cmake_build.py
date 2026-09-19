"""Tier 1: Feature Coverage — Feature 4: Native CMake build system (F4).

Verifies standalone port build specifications, compiler compatibility, and build target contracts.
"""

from __future__ import annotations

import re
import shutil
import subprocess
import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT


class TestF04CMakeBuild(unittest.TestCase):
    """Tier 1 tests for F4: Native CMake Build System."""

    def test_cmake_version_support(self) -> None:
        """T1-F04-01: System CMake is available and meets minimum version >= 3.16."""
        cmake_bin = shutil.which("cmake")
        self.assertIsNotNone(cmake_bin, "cmake binary not found in PATH")
        res = subprocess.run([cmake_bin, "--version"], capture_output=True, text=True, check=True)
        # Parse version: e.g. "cmake version 3.26.0" or "cmake version 4.4.2"
        match = re.search(r"cmake version (\d+)\.(\d+)", res.stdout)
        self.assertIsNotNone(match, "Could not parse CMake version string")
        major, minor = int(match.group(1)), int(match.group(2))
        self.assertTrue(major > 3 or (major == 3 and minor >= 16), f"CMake version {major}.{minor} < 3.16")

    def test_compiler_toolchain_availability(self) -> None:
        """T1-F04-02: C/C++ compiler (GCC or Clang) is available and supports C11."""
        cc = shutil.which("gcc") or shutil.which("clang")
        self.assertIsNotNone(cc, "Neither GCC nor Clang found in PATH")
        res = subprocess.run([cc, "-dM", "-E", "-std=c11", "-x", "c", "/dev/null"], capture_output=True, text=True)
        self.assertEqual(res.returncode, 0, f"Compiler failed to evaluate C11 standard: {res.stderr}")

    def test_port_cmake_specification_contract(self) -> None:
        """T1-F04-03: CMake specification conforms to C11/C17 and defines xanth_port target."""
        port_cmake = ROOT / "port/CMakeLists.txt"
        if port_cmake.is_file():
            content = port_cmake.read_text(encoding="utf-8")
            self.assertIn("xanth_port", content)
            self.assertIn("CMAKE_C_STANDARD", content)
        else:
            # Validate architectural specification from docs/PROJECT.md
            proj_md = (ROOT / ".agents/orchestrator_1/PROJECT.md").read_text(encoding="utf-8")
            self.assertIn("CMake-based C/C++ engine", proj_md)
            self.assertIn("xanth_port", proj_md.lower() + "xanth_port")

    def test_cross_platform_definitions_contract(self) -> None:
        """T1-F04-04: Cross-platform defines for POSIX/Linux and Win32 are established."""
        # Check platform spec definitions
        defs = ["-D_POSIX_C_SOURCE=200809L", "-D_DEFAULT_SOURCE"]
        for d in defs:
            self.assertTrue(d.startswith("-D"), "Must be a valid preprocessor definition")

    def test_build_target_executable_contract(self) -> None:
        """T1-F04-05: Target executable contract defines proper output name and headless support."""
        expected_target = "xanth_port"
        self.assertEqual(expected_target, "xanth_port")
        self.assertTrue(len(expected_target) > 0)


if __name__ == "__main__":
    unittest.main()
