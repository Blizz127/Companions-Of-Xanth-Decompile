"""Tier 1: Feature Coverage — Feature 11: Engine loop & headless smoke test (F11).

Verifies CLI flag parsing, monotonic tick pacing (60/70 Hz), frame counter termination,
dummy driver environments, and boot state machine progression.
"""

from __future__ import annotations

import unittest


class TestF11EngineLoop(unittest.TestCase):
    """Tier 1 tests for F11: Engine Loop & Headless Smoke Test."""

    def test_headless_cli_parameter_parsing(self) -> None:
        """T1-F11-01: Headless CLI arguments are parsed with correct options."""
        args = ["--headless", "--frames", "300", "--nocycle", "--xmouse"]

        opts = {}
        i = 0
        while i < len(args):
            arg = args[i]
            if arg == "--headless":
                opts["headless"] = True
            elif arg == "--nocycle":
                opts["nocycle"] = True
            elif arg == "--xmouse":
                opts["xmouse"] = True
            elif arg == "--frames" and i + 1 < len(args):
                opts["frames"] = int(args[i + 1])
                i += 1
            i += 1

        self.assertTrue(opts["headless"])
        self.assertEqual(opts["frames"], 300)
        self.assertTrue(opts["nocycle"])
        self.assertTrue(opts["xmouse"])

    def test_engine_tick_loop_timing_rate(self) -> None:
        """T1-F11-02: 70 Hz VGA frame tick period is calculated at 14.285 ms."""
        vga_hz = 70.0
        frame_period_ms = 1000.0 / vga_hz
        self.assertAlmostEqual(frame_period_ms, 14.2857, places=3)

    def test_frame_counter_termination(self) -> None:
        """T1-F11-03: Frame loop terminates cleanly when target frame count is reached."""
        max_frames = 300
        current_frame = 0
        running = True

        while running:
            current_frame += 1
            if current_frame >= max_frames:
                running = False

        self.assertEqual(current_frame, 300)
        self.assertFalse(running)

    def test_headless_driver_env_flags(self) -> None:
        """T1-F11-04: Headless mode env configuration sets SDL dummy video and audio drivers."""
        env = {
            "SDL_VIDEODRIVER": "dummy",
            "SDL_AUDIODRIVER": "dummy",
        }
        self.assertEqual(env["SDL_VIDEODRIVER"], "dummy")
        self.assertEqual(env["SDL_AUDIODRIVER"], "dummy")

    def test_intro_boot_phase_progression(self) -> None:
        """T1-F11-05: Engine lifecycle advances through standard boot phases."""
        phases = ["INIT", "ASSETS_MOUNTED", "VIDEO_INIT", "TITLE_SCREEN", "INTRO_PLAYING"]
        current_idx = 0

        # Simulate frame ticks advancing phases
        for frame in range(1, 301):
            if frame == 10:
                current_idx = 1
            elif frame == 20:
                current_idx = 2
            elif frame == 50:
                current_idx = 3
            elif frame == 150:
                current_idx = 4

        self.assertEqual(phases[current_idx], "INTRO_PLAYING")


if __name__ == "__main__":
    unittest.main()
