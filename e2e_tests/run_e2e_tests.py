#!/usr/bin/env python3
"""Companions of Xanth Independent Opaque-Box E2E Test Suite Runner.

Executes all 4 tiers of E2E tests:
- Tier 1: Feature Coverage (>=5 tests per feature, happy paths)
- Tier 2: Boundary & Corner Cases (>=5 tests per feature, extremes & errors)
- Tier 3: Cross-Feature Combinations (pairwise state, data, & control flow)
- Tier 4: Real-World Application Scenarios (complete game lifecycles)

Exits with code 0 when all tests pass.
"""

from __future__ import annotations

import argparse
import sys
import time
import unittest
from pathlib import Path
from typing import Dict, List, Optional, Tuple

E2E_ROOT = Path(__file__).resolve().parent
PROJECT_ROOT = E2E_ROOT.parent

if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))


class PrettyTestResult(unittest.TestResult):
    """Custom TestResult that prints per-test status with elapsed timing."""

    def __init__(self, verbose: bool = True) -> None:
        super().__init__()
        self.verbose = verbose
        self.test_records: List[Dict[str, Any]] = []
        self._test_start_time = 0.0
        self.current_tier: str = "1"

    def startTest(self, test: unittest.TestCase) -> None:
        super().startTest(test)
        self._test_start_time = time.perf_counter()

    def addSuccess(self, test: unittest.TestCase) -> None:
        super().addSuccess(test)
        elapsed = time.perf_counter() - self._test_start_time
        test_id = test.id()
        self.test_records.append({"id": test_id, "tier": self.current_tier, "status": "PASS", "time": elapsed, "err": None})
        if self.verbose:
            doc = (test.shortDescription() or "").strip()
            desc = f" - {doc}" if doc else ""
            print(f"  [PASS] {test_id}{desc} ({elapsed * 1000.0:.1f} ms)")

    def addFailure(self, test: unittest.TestCase, err) -> None:
        super().addFailure(test, err)
        elapsed = time.perf_counter() - self._test_start_time
        test_id = test.id()
        self.test_records.append({"id": test_id, "tier": self.current_tier, "status": "FAIL", "time": elapsed, "err": err})
        if self.verbose:
            print(f"  [FAIL] {test_id} ({elapsed * 1000.0:.1f} ms)")

    def addError(self, test: unittest.TestCase, err) -> None:
        super().addError(test, err)
        elapsed = time.perf_counter() - self._test_start_time
        test_id = test.id()
        self.test_records.append({"id": test_id, "tier": self.current_tier, "status": "ERROR", "time": elapsed, "err": err})
        if self.verbose:
            print(f"  [ERROR] {test_id} ({elapsed * 1000.0:.1f} ms)")

    def addSkip(self, test: unittest.TestCase, reason: str) -> None:
        super().addSkip(test, reason)
        elapsed = time.perf_counter() - self._test_start_time
        test_id = test.id()
        self.test_records.append({"id": test_id, "tier": self.current_tier, "status": "SKIP", "time": elapsed, "err": reason})
        if self.verbose:
            print(f"  [SKIP] {test_id} (Reason: {reason})")


def run_e2e_suite(
    tier_filter: Optional[str] = None,
    feature_filter: Optional[str] = None,
    verbose: bool = True,
) -> int:
    """Discovers and runs test cases, printing formatted report and returning exit code."""
    print("=" * 80)
    print("COMPANIONS OF XANTH — 4-TIER E2E TEST SUITE RUNNER")
    print(f"Root: {PROJECT_ROOT}")
    print(f"Tier: {tier_filter or 'ALL'} | Feature: {feature_filter or 'ALL'}")
    print("=" * 80)

    loader = unittest.TestLoader()
    suite = unittest.TestSuite()

    tier_dirs = {
        "1": ("Tier 1 - Feature Coverage", E2E_ROOT / "tier1_feature_coverage"),
        "2": ("Tier 2 - Boundary & Corner Cases", E2E_ROOT / "tier2_boundaries_corners"),
        "3": ("Tier 3 - Cross-Feature Combinations", E2E_ROOT / "tier3_cross_feature"),
        "4": ("Tier 4 - Real-World Application Scenarios", E2E_ROOT / "tier4_application_scenarios"),
    }

    selected_tiers = [tier_filter] if tier_filter in tier_dirs else list(tier_dirs.keys())

    total_discovered = 0
    tier_suites: Dict[str, Tuple[str, unittest.TestSuite]] = {}

    pattern = f"*f{feature_filter.lower()}*.py" if feature_filter else "test_*.py"

    for t_key in selected_tiers:
        t_label, t_path = tier_dirs[t_key]
        if not t_path.is_dir():
            continue
        discovered = loader.discover(str(t_path), pattern=pattern)
        tier_suites[t_key] = (t_label, discovered)
        total_discovered += discovered.countTestCases()

    print(f"\nDiscovered {total_discovered} test cases across {len(tier_suites)} tiers.\n")

    overall_result = PrettyTestResult(verbose=verbose)
    start_total_time = time.perf_counter()

    for t_key, (t_label, t_suite) in tier_suites.items():
        count = t_suite.countTestCases()
        if count == 0:
            continue
        print(f"\n--- Running {t_label} ({count} tests) ---")
        overall_result.current_tier = t_key
        t_suite.run(overall_result)

    total_time = time.perf_counter() - start_total_time

    # Print Summary Report
    print("\n" + "=" * 80)
    print("E2E TEST EXECUTION SUMMARY REPORT")
    print("=" * 80)

    passed_count = sum(1 for r in overall_result.test_records if r["status"] == "PASS")
    failed_count = sum(1 for r in overall_result.test_records if r["status"] == "FAIL")
    error_count = sum(1 for r in overall_result.test_records if r["status"] == "ERROR")
    skipped_count = sum(1 for r in overall_result.test_records if r["status"] == "SKIP")

    print(f"Total Tests Run:     {overall_result.testsRun}")
    print(f"Passed:              {passed_count}")
    print(f"Failed:              {failed_count}")
    print(f"Errors:              {error_count}")
    print(f"Skipped:             {skipped_count}")
    print(f"Total Elapsed Time:  {total_time:.2f} seconds")
    print("-" * 80)

    # Per-Tier breakdown
    print("TIER BREAKDOWN:")
    for t_key in selected_tiers:
        t_label, _ = tier_dirs[t_key]
        t_tests = [r for r in overall_result.test_records if r.get("tier") == t_key]
        t_pass = sum(1 for r in t_tests if r["status"] == "PASS")
        t_fail = sum(1 for r in t_tests if r["status"] == "FAIL")
        t_err = sum(1 for r in t_tests if r["status"] == "ERROR")
        t_skip = sum(1 for r in t_tests if r["status"] == "SKIP")
        pct = (t_pass / len(t_tests) * 100.0) if t_tests else 0.0
        print(f"  {t_label:42s}: {t_pass:3d} passed, {t_fail:2d} failed, {t_err:2d} err, {t_skip:2d} skip ({pct:5.1f}%)")

    print("=" * 80)

    if failed_count > 0 or error_count > 0:
        print("\n[RESULT: FAILED] Some tests encountered failures or errors.\n")
        return 1

    print("\n[RESULT: PASSED] 100% of tests passed successfully.\n")
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description="Companions of Xanth 4-Tier E2E Test Suite Runner")
    parser.add_argument(
        "--tier",
        choices=["1", "2", "3", "4", "all"],
        default="all",
        help="Filter execution to specific test tier (default: all)",
    )
    parser.add_argument(
        "--feature",
        type=str,
        default=None,
        help="Filter execution to specific feature (e.g. 01, 02.. 14)",
    )
    parser.add_argument(
        "-q",
        "--quiet",
        action="store_true",
        help="Quiet output (summary only)",
    )
    args = parser.parse_args()

    tier_filter = None if args.tier == "all" else args.tier
    return run_e2e_suite(
        tier_filter=tier_filter,
        feature_filter=args.feature,
        verbose=not args.quiet,
    )


if __name__ == "__main__":
    sys.exit(main())
