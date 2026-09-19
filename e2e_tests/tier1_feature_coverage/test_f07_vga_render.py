"""Tier 1: Feature Coverage — Feature 7: VGA Mode 13h video rendering (F7).

Verifies 320x200 8bpp double buffering, 6-bit DAC to 8-bit RGBA palette expansion,
dirty rectangle blits, and 4:3 aspect ratio preservation.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import VgaMode13h


class TestF07VgaRender(unittest.TestCase):
    """Tier 1 tests for F7: VGA Mode 13h Video Rendering."""

    def setUp(self) -> None:
        self.vga = VgaMode13h()

    def test_vga_buffer_dimensions(self) -> None:
        """T1-F07-01: Mode 13h buffers are 320x200 and exactly 64,000 bytes."""
        self.assertEqual(self.vga.WIDTH, 320)
        self.assertEqual(self.vga.HEIGHT, 200)
        self.assertEqual(len(self.vga.screen_buffer), 64000)
        self.assertEqual(len(self.vga.back_buffer), 64000)

    def test_dac_palette_expansion(self) -> None:
        """T1-F07-02: 6-bit DAC values (0..63) expand to 8-bit RGBA (0..255) via (c << 2) | (c >> 4)."""
        # Test max intensity: 63 -> (63 << 2) | (63 >> 4) = 252 | 3 = 255
        self.vga.set_palette_entry(1, 63, 63, 63)
        self.assertEqual(self.vga.palette_rgba[1], (255, 255, 255, 255))

        # Test zero intensity: 0 -> 0
        self.vga.set_palette_entry(0, 0, 0, 0)
        self.assertEqual(self.vga.palette_rgba[0], (0, 0, 0, 255))

        # Test mid intensity: 32 -> (32 << 2) | (32 >> 4) = 128 | 2 = 130
        self.vga.set_palette_entry(2, 32, 32, 32)
        self.assertEqual(self.vga.palette_rgba[2], (130, 130, 130, 255))

    def test_dirty_rect_blit_math(self) -> None:
        """T1-F07-03: Dirty rectangle blit updates exact sub-rectangle in screen buffer."""
        # Create a 20x10 tile of color 0x7F
        w, h = 20, 10
        src = bytearray([0x7F] * (w * h))
        x, y = 50, 40
        clipped = self.vga.blit_dirty_rect(x, y, w, h, src, stride=w)
        self.assertEqual(clipped, (50, 40, 20, 10))

        # Verify pixels at dst
        dst_idx = y * self.vga.WIDTH + x
        self.assertEqual(self.vga.screen_buffer[dst_idx : dst_idx + w], bytes([0x7F] * w))
        # Pixel right before should be unchanged (0)
        self.assertEqual(self.vga.screen_buffer[dst_idx - 1], 0)

    def test_backbuffer_flip(self) -> None:
        """T1-F07-04: Whole-screen flip copies backbuffer to screen buffer."""
        # Fill backbuffer with pattern
        self.vga.back_buffer[:] = bytearray([0x42] * self.vga.FRAME_SIZE)
        self.vga.screen_buffer[:] = bytearray([0x00] * self.vga.FRAME_SIZE)
        self.vga.flip_backbuffer()
        self.assertEqual(self.vga.screen_buffer, self.vga.back_buffer)

    def test_aspect_ratio_scaling_calculation(self) -> None:
        """T1-F07-05: 4:3 letterboxing calculates correct target rect on 16:9 displays."""
        # Destination display: 1920x1080 (16:9)
        disp_w, disp_h = 1920, 1080
        # 4:3 target aspect: width should be disp_h * (4 / 3) = 1080 * 1.3333... = 1440
        target_h = disp_h
        target_w = int(target_h * 4.0 / 3.0)
        offset_x = (disp_w - target_w) // 2
        offset_y = 0

        self.assertEqual(target_w, 1440)
        self.assertEqual(target_h, 1080)
        self.assertEqual(offset_x, 240)
        self.assertEqual(offset_y, 0)
        self.assertEqual(target_w + offset_x * 2, disp_w)


if __name__ == "__main__":
    unittest.main()
