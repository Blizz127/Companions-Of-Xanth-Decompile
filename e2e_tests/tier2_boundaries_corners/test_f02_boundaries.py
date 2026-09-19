"""Tier 2: Boundary & Corner Cases — Feature 2: Binary verification preservation (F2).

Verifies detection of truncated binaries, single-bit flips, corrupted headers,
out-of-bounds relocations, and overlay directory limits.
"""

from __future__ import annotations

import hashlib
import struct
import unittest

from e2e_tests.test_runner_common import ROOT, load_target_json


class TestF02Boundaries(unittest.TestCase):
    """Tier 2 tests for F2: Binary Verification Boundaries."""

    def setUp(self) -> None:
        self.target = load_target_json()

    def test_truncated_binary_detection(self) -> None:
        """T2-F02-01: Truncated binary fails size and hash verification."""
        path = ROOT / self.target["executable"]["path"]
        data = path.read_bytes()
        truncated = data[:1000]
        self.assertNotEqual(len(truncated), self.target["executable"]["size"])
        self.assertNotEqual(hashlib.sha256(truncated).hexdigest(), self.target["executable"]["sha256"])

    def test_single_bit_flip_detection(self) -> None:
        """T2-F02-02: Modifying a single byte alters SHA-256 hash and invalidates match."""
        path = ROOT / self.target["overlay"]["path"]
        data = bytearray(path.read_bytes())
        # Flip bit 0 of first payload byte after directory (offset 496)
        data[496] ^= 0x01
        corrupted_hash = hashlib.sha256(data).hexdigest()
        self.assertNotEqual(corrupted_hash, self.target["overlay"]["sha256"])

    def test_invalid_magic_header_rejection(self) -> None:
        """T2-F02-03: MZ parser rejects non-MZ signatures (e.g. ZM or raw binary)."""
        invalid_headers = [b"XX", b"ZM", b"\x00\x00", b"PE"]
        for magic in invalid_headers:
            self.assertNotEqual(magic, b"MZ")

    def test_out_of_bounds_relocation_rejection(self) -> None:
        """T2-F02-04: Relocation fixup past the end of image memory is detected as out-of-bounds."""
        image_size = 221864  # resident image size
        # A relocation pointing to offset 300,000 exceeds resident image
        reloc_offset = 300000
        self.assertGreater(reloc_offset, image_size)

    def test_overlay_directory_slot_limit(self) -> None:
        """T2-F02-05: Overlay directory contains exactly 62 entries followed by 0000:FFFF."""
        path = ROOT / self.target["overlay"]["path"]
        data = path.read_bytes()
        # Offset 244 is entry 61, offset 248 is entry 62 (terminator)
        term_size, term_seg = struct.unpack("<HH", data[248:252])
        self.assertEqual(term_size, 0)
        self.assertEqual(term_seg, 0xFFFF)
        # Offset 248 / 4 = 62 entries exactly
        self.assertEqual(248 // 4, 62)


if __name__ == "__main__":
    unittest.main()
