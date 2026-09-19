"""Tier 2: Boundary & Corner Cases — Feature 7: VGA Mode 13h video rendering (F7).

Verifies out-of-bounds dirty rect clipping, zero-sized blits, palette index limits,
color clamping, and screen corner pixel blits.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import VgaMode13h


class TestF07Boundaries(unittest.TestCase):
    """Tier 2 tests for F7: VGA Mode 13h Boundaries."""

    def setUp(self) -> None:
        self.vga = VgaMode13h()

    def test_out_of_bounds_dirty_rect_clipping(self) -> None:
        """T2-F07-01: Dirty rect completely outside (320x200) clips to empty region."""
        dummy_src = b"\xFF" * 100
        # Completely off-screen right/bottom
        res = self.vga.blit_dirty_rect(350, 250, 10, 10, dummy_src, stride=10)
        self.assertEqual(res, (0, 0, 0, 0))

        # Completely off-screen left/top
        res_neg = self.vga.blit_dirty_rect(-50, -50, 10, 10, dummy_src, stride=10)
        self.assertEqual(res_neg, (0, 0, 0, 0))

    def test_zero_width_height_blit(self) -> None:
        """T2-F07-02: Zero-width or zero-height blit returns (0, 0, 0, 0) safely."""
        dummy_src = b"\xFF" * 10
        self.assertEqual(self.vga.blit_dirty_rect(10, 10, 0, 10, dummy_src, stride=10), (0, 0, 0, 0))
        self.assertEqual(self.vga.blit_dirty_rect(10, 10, 10, 0, dummy_src, stride=10), (0, 0, 0, 0))

    def test_palette_index_boundaries(self) -> None:
        """T2-F07-03: Palette indices 0 and 255 are valid; index 256 raises IndexError."""
        self.vga.set_palette_entry(0, 10, 20, 30)
        self.vga.set_palette_entry(255, 63, 63, 63)
        with self.assertRaises(IndexError):
            self.vga.set_palette_entry(256, 0, 0, 0)
        with self.assertRaises(IndexError):
            self.vga.set_palette_entry(-1, 0, 0, 0)

    def test_palette_color_clamping_to_6bit(self) -> None:
        """T2-F07-04: DAC color values > 63 are masked to 6-bit range (0..63)."""
        # Value 255 (0xFF) masked to 0x3F == 63
        self.vga.set_palette_entry(5, 255, 128, 64)
        r, g, b = self.vga.palette_dac[5]
        self.assertEqual(r, 63)
        self.assertEqual(g, 0)
        self.assertEqual(b, 0)

    def test_single_pixel_blit_corner(self) -> None:
        """T2-F07-05: 1x1 pixel blit updates exact screen corners without overflow."""
        pixel = b"\x99"
        corners = [(0, 0), (319, 0), (0, 199), (319, 199)]
        for cx, cy in corners:
            clipped = self.vga.blit_dirty_rect(cx, cy, 1, 1, pixel, stride=1)
            self.assertEqual(clipped, (cx, cy, 1, 1))
            dst_idx = cy * self.vga.WIDTH + cx
            self.assertEqual(self.vga.screen_buffer[dst_idx], 0x99)


if __name__ == "__main__":
    unittest.main()
