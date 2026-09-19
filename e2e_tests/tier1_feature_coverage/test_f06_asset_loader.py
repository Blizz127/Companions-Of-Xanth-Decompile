"""Tier 1: Feature Coverage — Feature 6: Overlay & asset loader (F6).

Verifies loading of OBJECT.DAT, XANTHSTR.DAT, 62 overlay section consolidation,
and case-insensitive path resolution.
"""

from __future__ import annotations

import struct
import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT, CaseInsensitiveResolver


class TestF06AssetLoader(unittest.TestCase):
    """Tier 1 tests for F6: Overlay & Asset Loader."""

    def test_object_dat_table_parsing(self) -> None:
        """T1-F06-01: OBJECT.DAT parses with valid 4,836 byte length header and object strings."""
        path = ROOT / "original/OBJECT.DAT"
        self.assertTrue(path.is_file(), f"OBJECT.DAT missing at {path}")
        data = path.read_bytes()
        self.assertEqual(len(data), 4838)
        table_len = struct.unpack("<H", data[:2])[0]
        self.assertEqual(table_len, 4836)

        # Parse null-terminated strings
        strings = [s.decode("latin1") for s in data[2 : table_len + 2].split(b"\x00") if s]
        self.assertGreater(len(strings), 500)
        self.assertIn("You", strings)
        self.assertIn("Grundy", strings)
        self.assertIn("Kim", strings)

    def test_xanthstr_dat_index_parsing(self) -> None:
        """T1-F06-02: XANTHSTR.DAT index table contains 80 valid {len, offset} entry records."""
        path = ROOT / "original/XANTHSTR.DAT"
        self.assertTrue(path.is_file(), f"XANTHSTR.DAT missing at {path}")
        data = path.read_bytes()
        self.assertEqual(len(data), 210146)

        entry_count = struct.unpack("<H", data[:2])[0]
        self.assertEqual(entry_count, 80)

        for i in range(entry_count):
            entry_bytes = data[2 + i * 6 : 2 + (i + 1) * 6]
            str_len, offset = struct.unpack("<HI", entry_bytes)
            self.assertGreater(str_len, 0)
            self.assertLess(offset + str_len, len(data))

    def test_overlay_sections_consolidation(self) -> None:
        """T1-F06-03: All 62 overlay sections consolidate into a flat payload buffer."""
        path = ROOT / "original/XANTH.OVL"
        self.assertTrue(path.is_file(), f"XANTH.OVL missing at {path}")
        data = path.read_bytes()
        self.assertEqual(len(data), 326091)

        # Directory terminator 0000:FFFF at 248
        term_offset = 248
        self.assertEqual(data[term_offset : term_offset + 4], b"\x00\x00\xff\xff")
        # Payload begins at offset 496 (after 62 directory entries + padding)
        payload = data[496:]
        self.assertEqual(len(payload), 325595)

    def test_case_insensitive_path_resolver(self) -> None:
        """T1-F06-04: CaseInsensitiveResolver resolves files regardless of casing."""
        base = ROOT / "original"
        resolved_lower = CaseInsensitiveResolver.resolve_path(base, "object.dat")
        resolved_upper = CaseInsensitiveResolver.resolve_path(base, "OBJECT.DAT")
        resolved_mixed = CaseInsensitiveResolver.resolve_path(base, "ObJeCt.DaT")

        self.assertIsNotNone(resolved_lower)
        self.assertIsNotNone(resolved_upper)
        self.assertIsNotNone(resolved_mixed)
        self.assertEqual(resolved_lower.resolve(), resolved_upper.resolve())
        self.assertEqual(resolved_upper.resolve(), resolved_mixed.resolve())

    def test_disc_gamedata_assets_discovery(self) -> None:
        """T1-F06-05: Core game data files are present in the repository."""
        required = ["original/XANTH.EXE", "original/XANTH.OVL", "original/OBJECT.DAT", "original/XANTHSTR.DAT"]
        for rel in required:
            self.assertTrue((ROOT / rel).is_file(), f"Required asset missing: {rel}")


if __name__ == "__main__":
    unittest.main()
