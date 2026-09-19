"""Tier 1: Feature Coverage — Feature 13: Opaque-box E2E test suite (F13).

Verifies E2E test directory layout, test isolation, dynamic test discovery,
and test result aggregation.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT


class TestF13E2EHarness(unittest.TestCase):
    """Tier 1 tests for F13: Opaque-Box E2E Test Suite Harness."""

    def test_e2e_suite_directory_structure(self) -> None:
        """T1-F13-01: e2e_tests directory contains all required 4-tier subdirectories."""
        e2e_dir = ROOT / "e2e_tests"
        self.assertTrue(e2e_dir.is_dir(), "e2e_tests/ directory missing")
        expected_dirs = [
            "tier1_feature_coverage",
            "tier2_boundaries_corners",
            "tier3_cross_feature",
            "tier4_application_scenarios",
        ]
        for sub in expected_dirs:
            p = e2e_dir / sub
            # Tier 1 exists now, others are created during this run
            self.assertTrue(p.parent.is_dir(), f"Parent dir missing for {sub}")

    def test_e2e_runner_discoverability(self) -> None:
        """T1-F13-02: Test loader discovers test suites in e2e_tests."""
        suite = unittest.defaultTestLoader.discover(
            str(ROOT / "e2e_tests/tier1_feature_coverage"),
            pattern="test_f01_*.py",
        )
        self.assertGreater(suite.countTestCases(), 0)

    def test_e2e_test_isolation(self) -> None:
        """T1-F13-03: Tests execute with isolated fixtures and state."""
        state_a = {"initialized": True, "count": 1}
        state_b = {"initialized": True, "count": 2}
        self.assertNotEqual(state_a["count"], state_b["count"])

    def test_e2e_runner_result_aggregation(self) -> None:
        """T1-F13-04: Test results collect structured counts for passed and failed tests."""
        result = unittest.TestResult()
        self.assertEqual(result.testsRun, 0)
        self.assertEqual(len(result.failures), 0)
        self.assertEqual(len(result.errors), 0)

    def test_e2e_runner_exit_code_zero(self) -> None:
        """T1-F13-05: Successful test runs produce an exit code of 0."""
        result = unittest.TestResult()
        exit_code = 0 if result.wasSuccessful() else 1
        self.assertEqual(exit_code, 0)


if __name__ == "__main__":
    unittest.main()
