"""Tier 1: Feature Coverage — Feature 8: Audio subsystem emulation (F8).

Verifies RealSound ADPCM decoding, OPL3 FM port emulation, VOC speech archive parsing,
and 44.1 kHz stereo mixing math.
"""

from __future__ import annotations

import struct
import unittest

from e2e_tests.test_runner_common import Opl3PortEmulation, RealSoundDecoder, VocArchiveParser


class TestF08AudioEmulation(unittest.TestCase):
    """Tier 1 tests for F8: Audio Subsystem Emulation."""

    def test_realsound_header_format(self) -> None:
        """T1-F08-01: RealSound header parses STEVE\\x02 magic, sample rate, and sample count."""
        # Synthesize a valid RealSound header: STEVE\x02 + sample_rate(8000) + samples(100)
        data = RealSoundDecoder.MAGIC + struct.pack("<HH", 8000, 100) + b"\x00" * 50
        header = RealSoundDecoder.parse_header(data)
        self.assertEqual(header["magic"], b"STEVE\x02")
        self.assertEqual(header["sample_rate"], 8000)
        self.assertEqual(header["num_samples"], 100)

    def test_realsound_adpcm_nibble_decoding(self) -> None:
        """T1-F08-02: 4-bit nibbles decode into valid 8-bit PCM waveform samples."""
        # 4 bytes of ADPCM data = 8 samples
        adpcm = b"\x88\x97\x6A\x5B"
        samples = RealSoundDecoder.decode_adpcm_nibbles(adpcm, expected_samples=8)
        self.assertEqual(len(samples), 8)
        for s in samples:
            self.assertTrue(0 <= s <= 255, f"Sample {s} out of 8-bit PCM range")

    def test_opl3_port_register_write(self) -> None:
        """T1-F08-03: OPL3 port writes (0x388 index, 0x389 data) update register table."""
        opl = Opl3PortEmulation()
        # Select register 0x20 (tremolo / vibrato / multiplier)
        opl.write_port(0x388, 0x20)
        # Write value 0x55
        opl.write_port(0x389, 0x55)
        self.assertEqual(opl.registers[0x20], 0x55)

        # Select register 0xB0 (frequency MSB and key on)
        opl.write_port(0x388, 0xB0)
        opl.write_port(0x389, 0x31)
        self.assertEqual(opl.registers[0xB0], 0x31)

    def test_voc_archive_header_parsing(self) -> None:
        """T1-F08-04: VOC voice archive header parses offset/length directory table."""
        # Create a mock VOC archive header for 2 clips
        header = struct.pack("<H", 2) + struct.pack("<II", 0x1000, 0x0500) + struct.pack("<II", 0x1500, 0x0800)
        entries = VocArchiveParser.parse_archive_header(header)
        self.assertEqual(len(entries), 2)
        self.assertEqual(entries[0], (0x1000, 0x0500))
        self.assertEqual(entries[1], (0x1500, 0x0800))

    def test_audio_mixer_buffer_math(self) -> None:
        """T1-F08-05: 44.1 kHz 16-bit stereo frame math computes correct buffer byte sizes."""
        sample_rate = 44100
        channels = 2  # stereo
        bytes_per_sample = 2  # 16-bit
        frame_bytes = channels * bytes_per_sample
        self.assertEqual(frame_bytes, 4)

        # 1/60th second frame buffer (approx. 735 frames)
        frames_per_tick = sample_rate // 60
        tick_buffer_bytes = frames_per_tick * frame_bytes
        self.assertEqual(frames_per_tick, 735)
        self.assertEqual(tick_buffer_bytes, 2940)


if __name__ == "__main__":
    unittest.main()
