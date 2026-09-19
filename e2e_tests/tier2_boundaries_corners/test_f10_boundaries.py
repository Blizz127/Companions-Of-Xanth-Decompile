"""Tier 2: Boundary & Corner Cases — Feature 10: Save/Load state persistence (F10).

Verifies handling of empty INI files, corrupted save CRC checksums, truncated saves,
invalid save magic, and slot number limits.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import LegendIniParser, SavegameState


class TestF10Boundaries(unittest.TestCase):
    """Tier 2 tests for F10: Save/Load Persistence Boundaries."""

    def test_empty_legend_ini_handling(self) -> None:
        """T2-F10-01: Parsing empty or whitespace-only INI string returns empty dict."""
        cfg = LegendIniParser.parse_ini("   \n\n; only comments\n# hash comment\n")
        self.assertEqual(cfg, {})

    def test_corrupt_savegame_crc_rejection(self) -> None:
        """T2-F10-02: Modified savegame payload trips CRC32 validation and raises ValueError."""
        state = SavegameState(slot=1, room_id=1, inventory=[10], flags={"intro": 1})
        data = bytearray(state.serialize())
        # Corrupt last byte of payload
        data[-1] ^= 0xFF
        with self.assertRaises(ValueError):
            SavegameState.deserialize(bytes(data))

    def test_truncated_savegame_header(self) -> None:
        """T2-F10-03: Save files shorter than 14 bytes header raise ValueError."""
        with self.assertRaises(ValueError):
            SavegameState.deserialize(b"XSAV\x00")

    def test_invalid_savegame_magic(self) -> None:
        """T2-F10-04: Non-XSAV magic signatures are rejected."""
        state = SavegameState(slot=1, room_id=1, inventory=[], flags={})
        data = bytearray(state.serialize())
        data[0:4] = b"BADM"
        with self.assertRaises(ValueError):
            SavegameState.deserialize(bytes(data))

    def test_slot_number_limits(self) -> None:
        """T2-F10-05: Slot numbers at boundaries (0 and 99) serialize correctly."""
        for slot in (0, 99):
            st = SavegameState(slot=slot, room_id=5, inventory=[], flags={})
            serialized = st.serialize()
            recovered = SavegameState.deserialize(serialized)
            self.assertEqual(recovered.slot, slot)


if __name__ == "__main__":
    unittest.main()
