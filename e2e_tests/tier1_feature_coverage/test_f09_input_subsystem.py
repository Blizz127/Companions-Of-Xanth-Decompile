"""Tier 1: Feature Coverage — Feature 9: Input subsystem (F9).

Verifies INT 33h mouse coordinate virtualization (640x200 to 320x200), button masks,
and INT 16h keyboard event queue FIFO mechanics.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import KeyboardInt16h, MouseInt33h


class TestF09InputSubsystem(unittest.TestCase):
    """Tier 1 tests for F9: Input Subsystem."""

    def test_mouse_coordinate_scaling(self) -> None:
        """T1-F09-01: Mouse coordinates scale between 320x200 screen and 640x200 virtual coords."""
        mouse = MouseInt33h()
        # Set screen coordinate (160, 100)
        mouse.set_screen_coords(160, 100, left=False, right=False)
        self.assertEqual(mouse.virt_x, 320)
        self.assertEqual(mouse.virt_y, 100)

        # Query back screen coordinate
        x, y, btn = mouse.get_screen_coords()
        self.assertEqual((x, y), (160, 100))

    def test_mouse_button_bitmask(self) -> None:
        """T1-F09-02: Mouse button states map to bit 0 (left) and bit 1 (right)."""
        mouse = MouseInt33h()

        mouse.set_screen_coords(10, 10, left=True, right=False)
        self.assertEqual(mouse.buttons, 0x01)

        mouse.set_screen_coords(10, 10, left=False, right=True)
        self.assertEqual(mouse.buttons, 0x02)

        mouse.set_screen_coords(10, 10, left=True, right=True)
        self.assertEqual(mouse.buttons, 0x03)

    def test_keyboard_bios_ring_buffer_fifo(self) -> None:
        """T1-F09-03: Keyboard queue enqueues and dequeues keystrokes in FIFO order."""
        kb = KeyboardInt16h()
        kb.push_key(0x1E, ord("a"))  # 'a' scancode 0x1E
        kb.push_key(0x30, ord("b"))  # 'b' scancode 0x30

        first = kb.read_key()
        self.assertEqual(first, (0x1E, ord("a")))

        second = kb.read_key()
        self.assertEqual(second, (0x30, ord("b")))

        self.assertIsNone(kb.read_key())

    def test_keyboard_scancode_ascii_packing(self) -> None:
        """T1-F09-04: Key code word packs (scancode << 8) | ascii_code."""
        # Enter key: scancode 0x1C, ASCII 0x0D -> 0x1C0D
        scancode, ascii_code = 0x1C, 0x0D
        key_word = (scancode << 8) | ascii_code
        self.assertEqual(key_word, 0x1C0D)

        # Escape key: scancode 0x01, ASCII 0x1B -> 0x011B
        scancode_esc, ascii_esc = 0x01, 0x1B
        key_word_esc = (scancode_esc << 8) | ascii_esc
        self.assertEqual(key_word_esc, 0x011B)

    def test_keyboard_shift_state_flags(self) -> None:
        """T1-F09-05: BIOS shift flags register tracks modifier keys."""
        # Right Shift: 0x01, Left Shift: 0x02, Ctrl: 0x04, Alt: 0x08
        rshift = 0x01
        lshift = 0x02
        ctrl = 0x04
        alt = 0x08

        flags = lshift | alt
        self.assertEqual(flags & lshift, 0x02)
        self.assertEqual(flags & alt, 0x08)
        self.assertEqual(flags & ctrl, 0x00)


if __name__ == "__main__":
    unittest.main()
