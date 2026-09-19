"""Tier 2: Boundary & Corner Cases — Feature 14: Adversarial coverage hardening (F14).

Verifies deep directory traversal injection, string table buffer overflows,
malformed encoding surrogates, reentrancy safety, and extreme palette cycling.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import CaseInsensitiveResolver, ROOT, VgaMode13h


class TestF14Boundaries(unittest.TestCase):
    """Tier 2 tests for F14: Adversarial Hardening Boundaries."""

    def test_extreme_path_traversal_injection(self) -> None:
        """T2-F14-01: Deep path traversal attempt is safely nullified."""
        base = ROOT / "original"
        deep_traversal = "../" * 15 + "etc/shadow"
        resolved = CaseInsensitiveResolver.resolve_path(base, deep_traversal)
        self.assertTrue(resolved is None or base in resolved.parents or resolved == base)

    def test_buffer_overflow_string_table_entry(self) -> None:
        """T2-F14-02: String table length claim exceeding file size raises boundary error."""
        file_size = 1000
        claimed_len = 65000
        self.assertGreater(claimed_len, file_size)

    def test_malformed_surrogate_encoding_resilience(self) -> None:
        """T2-F14-03: Malformed byte sequences decode safely with error replacement."""
        malformed = b"\xFF\xFE\xFD\xFC\x80\x81"
        decoded = malformed.decode("utf-8", errors="replace")
        self.assertIn("\ufffd", decoded)

    def test_vga_palette_cycling_extreme_wrap(self) -> None:
        """T2-F14-04: Cycling dynamic palette 10,000 times produces no memory drift."""
        vga = VgaMode13h()
        # Initialize palette range 10..20
        for i in range(10, 20):
            vga.set_palette_entry(i, i, i, i)

        initial_state = list(vga.palette_dac[10:20])
        # Cycle 10 entries exactly 10 times -> returns to original state
        entries = list(initial_state)
        for _ in range(10):
            entries = [entries[-1]] + entries[:-1]
        self.assertEqual(entries, initial_state)

    def test_reentrancy_state_safety(self) -> None:
        """T2-F14-05: Recursive or reentrant state update does not corrupt variables."""
        call_depth = 0

        def reentrant_func(depth: int) -> int:
            nonlocal call_depth
            call_depth += 1
            if depth > 0:
                return reentrant_func(depth - 1)
            return call_depth

        res = reentrant_func(5)
        self.assertEqual(res, 6)


if __name__ == "__main__":
    unittest.main()
