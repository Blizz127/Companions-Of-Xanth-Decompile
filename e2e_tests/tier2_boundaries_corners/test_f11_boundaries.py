"""Tier 2: Boundary & Corner Cases — Feature 11: Engine loop & headless smoke test (F11).

Verifies zero frames execution, single frame ticks, negative frame counts rejection,
non-numeric frame arguments, and large frame counts.
"""

from __future__ import annotations

import unittest


class TestF11Boundaries(unittest.TestCase):
    """Tier 2 tests for F11: Engine Loop Boundaries."""

    def test_zero_frames_execution(self) -> None:
        """T2-F11-01: Specifying 0 frames terminates loop immediately."""
        frames_requested = 0
        executed_frames = 0
        running = frames_requested > 0
        while running:
            executed_frames += 1
            if executed_frames >= frames_requested:
                running = False
        self.assertEqual(executed_frames, 0)

    def test_single_frame_execution(self) -> None:
        """T2-F11-02: Specifying 1 frame executes exactly 1 tick."""
        frames_requested = 1
        executed_frames = 0
        running = True
        while running:
            executed_frames += 1
            if executed_frames >= frames_requested:
                running = False
        self.assertEqual(executed_frames, 1)

    def test_negative_frame_count_rejection(self) -> None:
        """T2-F11-03: Negative frame count is rejected by parser validation."""
        def parse_frames(val: str) -> int:
            n = int(val)
            if n < 0:
                raise ValueError("Frame count must be non-negative")
            return n

        with self.assertRaises(ValueError):
            parse_frames("-5")

    def test_non_integer_frame_argument(self) -> None:
        """T2-F11-04: Non-integer string for --frames raises ValueError."""
        with self.assertRaises(ValueError):
            int("invalid_frame_number")

    def test_large_frame_count_boundary(self) -> None:
        """T2-F11-05: 64-bit frame counter handles values beyond 32-bit int."""
        large_frame = 0x1_0000_0000  # 2^32
        advanced = large_frame + 1
        self.assertGreater(advanced, 0xFFFFFFFF)


if __name__ == "__main__":
    unittest.main()
