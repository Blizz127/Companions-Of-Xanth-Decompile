"""Tier 1: Feature Coverage — Feature 3: Fast ratchet test suite (F3).

Verifies continuous compliance with decompilation ratchet tests, dump ceiling thresholds,
and unaided C recovery floors.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT, load_indexed_units


class TestF03RatchetSuite(unittest.TestCase):
    """Tier 1 tests for F3: Fast Ratchet Test Suite."""

    def test_ratchet_test_file_exists(self) -> None:
        """T1-F03-01: tests/test_units.py exists and is readable."""
        p = ROOT / "tests/test_units.py"
        self.assertTrue(p.is_file(), f"Ratchet test suite missing at {p}")
        content = p.read_text(encoding="utf-8")
        self.assertIn("class DumpExtentTests", content)

    def test_ratchet_suite_passes_programmatically(self) -> None:
        """T1-F03-02: Ratchet test suite executes with 0 failures and 0 errors."""
        suite = unittest.defaultTestLoader.discover(str(ROOT / "tests"), pattern="test_units.py")
        runner = unittest.TextTestRunner(verbosity=0)
        result = runner.run(suite)
        self.assertEqual(len(result.failures), 0, f"Failures: {result.failures}")
        self.assertEqual(len(result.errors), 0, f"Errors: {result.errors}")
        self.assertGreaterEqual(result.testsRun, 10, "Expected at least 10 ratchet tests to run")

    def test_exe_code_dump_percentage_ceiling(self) -> None:
        """T1-F03-03: exe-code dump percentage is <= 18.92% ceiling."""
        units = load_indexed_units()
        exe_dump = sum(1 for u in units if u.get("image") == "exe-code" and u.get("kind") == "dump")
        exe_total = sum(1 for u in units if u.get("image") == "exe-code")
        pct = (exe_dump / exe_total) * 100.0
        self.assertLessEqual(pct, 18.92, f"exe-code dump percentage {pct:.2f}% exceeds ceiling 18.92%")

    def test_ovl_payload_dump_percentage_ceiling(self) -> None:
        """T1-F03-04: ovl-payload dump percentage is <= 18.98% ceiling."""
        units = load_indexed_units()
        ovl_dump = sum(1 for u in units if u.get("image") == "ovl-payload" and u.get("kind") == "dump")
        ovl_total = sum(1 for u in units if u.get("image") == "ovl-payload")
        pct = (ovl_dump / ovl_total) * 100.0
        self.assertLessEqual(pct, 18.98, f"ovl-payload dump percentage {pct:.2f}% exceeds ceiling 18.98%")

    def test_unaided_c_floor_respected(self) -> None:
        """T1-F03-05: Unaided C units count is >= 442 floor."""
        units = load_indexed_units()
        unaided_c = sum(1 for u in units if u.get("kind") == "c")
        self.assertGreaterEqual(unaided_c, 442, f"unaided C count {unaided_c} below floor 442")


if __name__ == "__main__":
    unittest.main()
