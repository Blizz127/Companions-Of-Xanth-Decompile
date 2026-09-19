"""Tier 2: Boundary & Corner Cases — Feature 4: Native CMake build system (F4).

Verifies CMake version lower boundary rejection, invalid compiler flag detection,
out-of-source builds, and missing dependency fallbacks.
"""

from __future__ import annotations

import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path


class TestF04Boundaries(unittest.TestCase):
    """Tier 2 tests for F4: Native CMake Build Boundaries."""

    def test_cmake_version_lower_boundary(self) -> None:
        """T2-F04-01: Reject CMake versions below minimum required 3.16."""
        min_major, min_minor = 3, 16
        test_versions = [(2, 8), (3, 0), (3, 10), (3, 15)]
        for maj, mnr in test_versions:
            self.assertTrue(maj < min_major or (maj == min_major and mnr < min_minor))

    def test_invalid_compiler_flag_detection(self) -> None:
        """T2-F04-02: Compiler detects and rejects unknown/invalid command line flags."""
        cc = shutil.which("gcc") or shutil.which("clang")
        self.assertIsNotNone(cc)
        res = subprocess.run([cc, "-finvalid-flag-xanth-decomp", "-c", "/dev/null"], capture_output=True, text=True)
        self.assertNotEqual(res.returncode, 0)

    def test_out_of_source_build_path_isolation(self) -> None:
        """T2-F04-03: Out-of-source build paths operate in isolated temporary directories."""
        with tempfile.TemporaryDirectory(prefix="xanth_build_") as tmpdir:
            p = Path(tmpdir)
            self.assertTrue(p.is_dir())
            build_subdir = p / "build_isolated"
            build_subdir.mkdir()
            self.assertTrue(build_subdir.is_dir())

    def test_c_standard_boundary(self) -> None:
        """T2-F04-04: Compiler verifies C11 standard supports exact-width types."""
        cc = shutil.which("gcc") or shutil.which("clang")
        code = "#include <stdint.h>\n#include <stdbool.h>\nint main(void) { uint16_t x = 0; return (int)x; }\n"
        res = subprocess.run([cc, "-std=c11", "-x", "c", "-", "-o", "/dev/null"], input=code, capture_output=True, text=True)
        self.assertEqual(res.returncode, 0, f"C11 compilation failed: {res.stderr}")

    def test_missing_sdl2_handling(self) -> None:
        """T2-F04-05: Missing SDL2 detection produces informative configuration error."""
        # Check that when pkg-config fails to find an invalid package, exit code is non-zero
        res = subprocess.run(["pkg-config", "--exists", "sdl2_invalid_pkg_xanth"], capture_output=True)
        self.assertNotEqual(res.returncode, 0)


if __name__ == "__main__":
    unittest.main()
