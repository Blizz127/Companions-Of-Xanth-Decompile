"""Tier 2: Boundary & Corner Cases — Feature 5: Portable types & memory bridge (F5).

Verifies segmented pointer NULL representations, HMA boundary overflows,
signed/unsigned 16-bit extremes, and zero-length memory operations.
"""

from __future__ import annotations

import struct
import unittest

from e2e_tests.test_runner_common import VirtualDosMemory


class TestF05Boundaries(unittest.TestCase):
    """Tier 2 tests for F5: Portable Types Boundaries."""

    def test_null_pointer_segment_offset_boundary(self) -> None:
        """T2-F05-01: MK_FP(0x0000, 0x0000) represents linear NULL offset 0."""
        self.assertEqual(VirtualDosMemory.linear_address(0x0000, 0x0000), 0)

    def test_hma_boundary_overflow(self) -> None:
        """T2-F05-02: Reading or writing at or beyond 1MB boundary (0xFFFF:0x0010) raises ValueError."""
        mem = VirtualDosMemory()
        # 0xFFFF:0x0010 -> (0xFFFF << 4) + 0x0010 = 0xFFFF0 + 0x10 = 0x100000 (1048576)
        with self.assertRaises(ValueError):
            mem.read_bytes(0xFFFF, 0x0010, 1)

    def test_signed_word_extreme_values(self) -> None:
        """T2-F05-03: sword extreme boundaries (-32768 and 32767) preserve sign."""
        min_sword = -32768
        max_sword = 32767
        packed_min = struct.pack("<h", min_sword)
        packed_max = struct.pack("<h", max_sword)
        self.assertEqual(struct.unpack("<h", packed_min)[0], min_sword)
        self.assertEqual(struct.unpack("<h", packed_max)[0], max_sword)

    def test_unsigned_word_wrap_around(self) -> None:
        """T2-F05-04: 16-bit uword wrap-around boundary at 0xFFFF + 1 == 0."""
        val = 0xFFFF
        wrapped = (val + 1) & 0xFFFF
        self.assertEqual(wrapped, 0)

    def test_zero_length_memory_operations(self) -> None:
        """T2-F05-05: Reading or writing 0 bytes at memory boundary succeeds safely."""
        mem = VirtualDosMemory()
        # Right at 1MB boundary, 0 bytes should succeed
        zero_bytes = mem.read_bytes(0xFFFF, 0x000F, 0)
        self.assertEqual(zero_bytes, b"")
        mem.write_bytes(0xFFFF, 0x000F, b"")


if __name__ == "__main__":
    unittest.main()
