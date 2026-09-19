import struct
import unittest
from e2e_tests.test_runner_common import VocArchiveParser

class TestVocAdversarial(unittest.TestCase):
    """Empirical adversarial testing of VOC speech archive parsing and clip index bounds."""

    def test_truncated_header_exceptions(self):
        """Verify headers < 2 bytes raise ValueError."""
        with self.assertRaises(ValueError):
            VocArchiveParser.parse_archive_header(b"")
        with self.assertRaises(ValueError):
            VocArchiveParser.parse_archive_header(b"\x01")

    def test_truncated_offset_table(self):
        """Header claims 1,327 clips but payload only contains 2 entries (18 bytes total)."""
        # Count = 1327 (0x052F), but only 2 entries (16 bytes) provided
        header = struct.pack("<H", 1327) + struct.pack("<II", 1000, 500) + struct.pack("<II", 1500, 600)
        entries = VocArchiveParser.parse_archive_header(header)
        # Should gracefully terminate at 2 entries rather than raising unhandled EOF or buffer overrun
        self.assertEqual(len(entries), 2)
        # Clip index 1326 or 1327 does not exist in truncated table
        with self.assertRaises(IndexError):
            _ = entries[1327]

    def test_clip_index_bounds_retail_archive(self):
        """Test clip index boundaries on a synthetic 1,327 clip archive (valid indices: 0..1326)."""
        retail_count = 1327
        table = bytearray(struct.pack("<H", retail_count))
        cur_offset = 2 + retail_count * 8
        for i in range(retail_count):
            length = 1000 + (i % 200)
            table.extend(struct.pack("<II", cur_offset, length))
            cur_offset += length

        entries = VocArchiveParser.parse_archive_header(bytes(table))
        self.assertEqual(len(entries), 1327)

        # Valid boundary indices: 0 and 1326
        self.assertEqual(entries[0][0], 2 + retail_count * 8)
        self.assertTrue(entries[1326][0] > 0)

        # Invalid clip indices:
        # Index 1327: exactly 1 beyond valid range
        with self.assertRaises(IndexError):
            _ = entries[1327]

        # Index 99999: far out-of-bounds
        with self.assertRaises(IndexError):
            _ = entries[99999]

        # In Python list indexing, negative index entries[-1] silently wraps to the last element
        # In a sound clip API, index -1 should be an invalid clip identifier!
        last_entry = entries[-1]
        self.assertEqual(last_entry, entries[1326], "Python negative indexing wraps around to last clip")

    def test_corrupted_offset_table_entries(self):
        """Table with out-of-bounds offsets and integer wrap-around values."""
        # Entry 0: valid offset 100, length 200
        # Entry 1: offset 0xFFFFFFFF, length 0x1000 (overflows 32-bit uint)
        header = (
            struct.pack("<H", 2)
            + struct.pack("<II", 100, 200)
            + struct.pack("<II", 0xFFFFFFFF, 0x1000)
        )
        entries = VocArchiveParser.parse_archive_header(header)
        self.assertEqual(len(entries), 2)
        self.assertEqual(entries[1][0], 0xFFFFFFFF)
        self.assertEqual(entries[1][1], 0x1000)
        # Sum overflows 32-bit integer
        self.assertEqual(entries[1][0] + entries[1][1], 0x100000FFF)

if __name__ == "__main__":
    unittest.main()
