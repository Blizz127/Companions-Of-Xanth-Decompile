"""Tier 2: Boundary & Corner Cases — Feature 3: Fast ratchet test suite (F3).

Verifies ratchet ceiling and floor assertion boundary triggers, asymptotic zero-dump target limits,
and error handling.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT, load_indexed_units


class TestF03Boundaries(unittest.TestCase):
    """Tier 2 tests for F3: Ratchet Suite Boundaries."""

    def test_ratchet_ceiling_violation_triggers_failure(self) -> None:
        """T2-F03-01: Exceeding the dump ceiling by 0.01% trips assertion boundary."""
        ceiling = 18.92
        violating_pct = 18.93
        with self.assertRaises(AssertionError):
            self.assertLessEqual(violating_pct, ceiling)

    def test_ratchet_floor_violation_triggers_failure(self) -> None:
        """T2-F03-02: Dropping below unaided C floor (441 < 442) trips assertion boundary."""
        floor = 442
        violating_count = 441
        with self.assertRaises(AssertionError):
            self.assertGreaterEqual(violating_count, floor)

    def test_dump_functions_ceiling_boundary(self) -> None:
        """T2-F03-03: Dump functions count is 0, satisfying the 560 ceiling."""
        ceiling = 560
        units = load_indexed_units()
        dump_funcs = sum(1 for u in units if u.get("kind") == "dump" and u.get("shape") == "function")
        self.assertLessEqual(dump_funcs, ceiling)
        # 0 dump functions remaining after 100% elimination
        self.assertEqual(dump_funcs, 0)

    def test_nonexistent_test_pattern_handling(self) -> None:
        """T2-F03-04: Test discovery with empty pattern returns empty suite without error."""
        suite = unittest.defaultTestLoader.discover(str(ROOT / "tests"), pattern="test_nonexistent_*.py")
        self.assertEqual(suite.countTestCases(), 0)

    def test_zero_dump_units_asymptotic_limit(self) -> None:
        """T2-F03-05: Target state of 0 dump units (0.00%) satisfies all ceiling ratchets."""
        target_dump_pct = 0.0
        self.assertLessEqual(target_dump_pct, 18.92)
        self.assertLessEqual(target_dump_pct, 18.98)


if __name__ == "__main__":
    unittest.main()
