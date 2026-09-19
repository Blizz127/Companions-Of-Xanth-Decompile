"""Tier 2: Boundary & Corner Cases — Feature 9: Input subsystem (F9).

Verifies mouse coordinate clamping, virtual coordinate limits, keyboard buffer overflow/underflow,
and simultaneous button states.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import KeyboardInt16h, MouseInt33h


class TestF09Boundaries(unittest.TestCase):
    """Tier 2 tests for F9: Input Subsystem Boundaries."""

    def test_mouse_coordinate_clamping(self) -> None:
        """T2-F09-01: Out-of-bounds mouse coordinates clamp to [0..319, 0..199]."""
        mouse = MouseInt33h()
        # Set negative coordinates
        mouse.set_screen_coords(-100, -50, left=False, right=False)
        self.assertEqual(mouse.get_screen_coords(), (0, 0, 0))

        # Set overly large coordinates
        mouse.set_screen_coords(500, 400, left=False, right=False)
        self.assertEqual(mouse.get_screen_coords(), (319, 199, 0))

    def test_mouse_virtual_coords_limits(self) -> None:
        """T2-F09-02: Maximum screen X (319) maps to virtual X (638)."""
        mouse = MouseInt33h()
        mouse.set_screen_coords(319, 199, left=False, right=False)
        self.assertEqual(mouse.virt_x, 638)
        self.assertEqual(mouse.virt_y, 199)

    def test_keyboard_queue_overflow_boundary(self) -> None:
        """T2-F09-03: Pushing more than 16 keys drops excess keys and returns False."""
        kb = KeyboardInt16h()
        for i in range(16):
            self.assertTrue(kb.push_key(i, i))
        # 17th push should fail
        self.assertFalse(kb.push_key(99, 99))
        self.assertEqual(len(kb.queue), 16)

    def test_keyboard_queue_underflow_boundary(self) -> None:
        """T2-F09-04: Polling or reading an empty keyboard queue returns None safely."""
        kb = KeyboardInt16h()
        self.assertIsNone(kb.poll_key())
        self.assertIsNone(kb.read_key())

    def test_simultaneous_mouse_buttons(self) -> None:
        """T2-F09-05: Transitioning buttons from both pressed (0x03) to single button."""
        mouse = MouseInt33h()
        mouse.set_screen_coords(100, 100, left=True, right=True)
        self.assertEqual(mouse.buttons, 3)

        # Release right button
        mouse.set_screen_coords(100, 100, left=True, right=False)
        self.assertEqual(mouse.buttons, 1)

        # Release all buttons
        mouse.set_screen_coords(100, 100, left=False, right=False)
        self.assertEqual(mouse.buttons, 0)


if __name__ == "__main__":
    unittest.main()
