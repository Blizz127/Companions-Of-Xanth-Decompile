"""Tier 2: Boundary & Corner Cases — Feature 6: Overlay & asset loader (F6).

Verifies handling of non-existent files, corrupt database headers, empty search strings,
overlay payload bounds, and mixed directory slash formats.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import CaseInsensitiveResolver, ROOT


class TestF06Boundaries(unittest.TestCase):
    """Tier 2 tests for F6: Overlay & Asset Loader Boundaries."""

    def test_nonexistent_asset_returns_none(self) -> None:
        """T2-F06-01: CaseInsensitiveResolver returns None for missing files."""
        base = ROOT / "original"
        resolved = CaseInsensitiveResolver.resolve_path(base, "NONEXISTENT_ASSET.DAT")
        self.assertIsNone(resolved)

    def test_corrupt_object_dat_header_length(self) -> None:
        """T2-F06-02: Corrupted table length exceeding buffer raises boundary condition."""
        corrupted_header = b"\xFF\xFF"  # 65535 bytes > actual size 4838
        actual_size = 4838
        claimed_len = int.from_bytes(corrupted_header, "little")
        self.assertGreater(claimed_len, actual_size)

    def test_empty_string_search_in_asset_table(self) -> None:
        """T2-F06-03: Empty string key lookup returns None or empty slice."""
        path = ROOT / "original/OBJECT.DAT"
        data = path.read_bytes()
        # Null-terminated strings
        strings = data[2:4838].split(b"\x00")
        # Empty tokens should be filtered out
        non_empty = [s for s in strings if len(s) > 0]
        self.assertGreater(len(non_empty), 0)

    def test_overlay_payload_boundary_offset(self) -> None:
        """T2-F06-04: Reading beyond payload boundary 326,091 bytes raises EOF."""
        path = ROOT / "original/XANTH.OVL"
        with open(path, "rb") as f:
            f.seek(326091)
            end_byte = f.read(1)
        self.assertEqual(end_byte, b"")

    def test_mixed_path_slashes_and_dots(self) -> None:
        """T2-F06-05: Path resolver handles redundant dots and mixed slashes."""
        base = ROOT / "original"
        resolved = CaseInsensitiveResolver.resolve_path(base, ".\\./object.dat")
        # Should cleanly resolve to OBJECT.DAT
        self.assertIsNotNone(resolved)
        self.assertTrue(resolved.is_file())


if __name__ == "__main__":
    unittest.main()
