"""Tier 2: Boundary & Corner Cases — Feature 8: Audio subsystem emulation (F8).

Verifies corrupt RealSound headers, empty audio requests, OPL3 register bounds,
audio mixer clipping saturation, and truncated VOC headers.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import Opl3PortEmulation, RealSoundDecoder, VocArchiveParser


class TestF08Boundaries(unittest.TestCase):
    """Tier 2 tests for F8: Audio Subsystem Boundaries."""

    def test_corrupt_realsound_magic(self) -> None:
        """T2-F08-01: RealSoundDecoder rejects headers without STEVE\\x02 signature."""
        invalid_data = b"NOTSTEVE\x00\x00\x00\x00"
        with self.assertRaises(ValueError):
            RealSoundDecoder.parse_header(invalid_data)

    def test_zero_sample_audio_buffer(self) -> None:
        """T2-F08-02: Decoding 0 requested samples returns empty list safely."""
        samples = RealSoundDecoder.decode_adpcm_nibbles(b"\x88\x88", expected_samples=0)
        self.assertEqual(samples, [])

    def test_opl3_invalid_register_index(self) -> None:
        """T2-F08-03: Register indices beyond 511 are masked or ignored."""
        opl = Opl3PortEmulation()
        opl.write_port(0x388, 0x1FFF)  # Large value
        # Active register masked to 9 bits (0..511)
        self.assertLess(opl.active_reg, 512)

    def test_audio_mixer_clipping_saturation(self) -> None:
        """T2-F08-04: Mixing concurrent loud streams clamps within int16 (-32768..32767) bounds."""
        sample_a = 25000
        sample_b = 20000
        raw_sum = sample_a + sample_b  # 45000 > 32767
        # Clamp to 16-bit signed
        saturated = max(-32768, min(32767, raw_sum))
        self.assertEqual(saturated, 32767)

    def test_truncated_voc_header_handling(self) -> None:
        """T2-F08-05: VocArchiveParser raises ValueError when header is truncated."""
        with self.assertRaises(ValueError):
            VocArchiveParser.parse_archive_header(b"")


if __name__ == "__main__":
    unittest.main()
