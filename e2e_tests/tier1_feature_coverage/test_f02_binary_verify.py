"""Tier 1: Feature Coverage — Feature 2: Binary verification preservation (F2).

Verifies whole-program binary pin hashes, MZ executable structure, and overlay table integrity.
"""

from __future__ import annotations

import hashlib
import struct
import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT, load_target_json


class TestF02BinaryVerify(unittest.TestCase):
    """Tier 1 tests for F2: Binary Verification Preservation."""

    def setUp(self) -> None:
        self.target = load_target_json()

    def test_target_pins_integrity(self) -> None:
        """T1-F02-01: target.json contains valid pins for executable, overlay, and disc."""
        for key in ("executable", "overlay", "iso"):
            self.assertIn(key, self.target)
            pin = self.target[key]
            self.assertEqual(len(pin["sha256"]), 64)
            self.assertGreater(pin["size"], 0)

    def test_executable_pin_match(self) -> None:
        """T1-F02-02: original/XANTH.EXE matches pinned size and SHA-256 hash."""
        pin = self.target["executable"]
        path = ROOT / pin["path"]
        self.assertTrue(path.is_file(), f"Executable missing at {path}")
        data = path.read_bytes()
        self.assertEqual(len(data), pin["size"])
        self.assertEqual(hashlib.sha256(data).hexdigest(), pin["sha256"])

    def test_overlay_pin_match(self) -> None:
        """T1-F02-03: original/XANTH.OVL matches pinned size and SHA-256 hash."""
        pin = self.target["overlay"]
        path = ROOT / pin["path"]
        self.assertTrue(path.is_file(), f"Overlay missing at {path}")
        data = path.read_bytes()
        self.assertEqual(len(data), pin["size"])
        self.assertEqual(hashlib.sha256(data).hexdigest(), pin["sha256"])

    def test_mz_header_structure(self) -> None:
        """T1-F02-04: XANTH.EXE MZ header fields conform to specification."""
        path = ROOT / self.target["executable"]["path"]
        data = path.read_bytes()
        self.assertEqual(data[:2], b"MZ")
        cblp, cp, crlc, cparh = struct.unpack("<HHHH", data[2:10])
        self.assertEqual(crlc, 5304, "Relocation count must equal 5,304")
        self.assertEqual(cparh, 1888, "Header paragraphs must equal 1,888")

        # Check CS:IP entry point
        ip, cs = struct.unpack("<HH", data[20:24])
        self.assertEqual(cs, 0x1DC1, "Entry segment must be 0x1DC1")
        self.assertEqual(ip, 0x0835, "Entry offset must be 0x0835")

    def test_overlay_directory_structure(self) -> None:
        """T1-F02-05: XANTH.OVL directory contains 62 sections for segment 0x30CB."""
        path = ROOT / self.target["overlay"]["path"]
        data = path.read_bytes()
        self.assertNotEqual(data[:2], b"MZ")

        # 62 entries of {uint16 size, uint16 segment}
        entries = []
        for i in range(62):
            size, seg = struct.unpack("<HH", data[i * 4 : (i + 1) * 4])
            entries.append((size, seg))
            self.assertEqual(seg, 0x30CB, f"Overlay entry {i} segment must be 0x30CB")
            self.assertGreater(size, 0, f"Overlay entry {i} size must be non-zero")

        # Terminator 0000:FFFF at offset 248
        term_size, term_seg = struct.unpack("<HH", data[248:252])
        self.assertEqual(term_size, 0x0000, "Terminator size must be 0x0000")
        self.assertEqual(term_seg, 0xFFFF, "Terminator segment must be 0xFFFF")


if __name__ == "__main__":
    unittest.main()
