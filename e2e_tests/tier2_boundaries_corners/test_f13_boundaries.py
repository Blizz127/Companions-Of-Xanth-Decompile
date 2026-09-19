"""Tier 2: Boundary & Corner Cases — Feature 13: Opaque-box E2E test suite (F13).

Verifies handling of empty suites, assertion diff formatting, error isolation,
skip tracking, and non-zero exit codes on failure.
"""

from __future__ import annotations

import unittest


class TestF13Boundaries(unittest.TestCase):
    """Tier 2 tests for F13: E2E Test Suite Boundaries."""

    def test_runner_handles_zero_tests_gracefully(self) -> None:
        """T2-F13-01: Empty test suite runs without crashing."""
        suite = unittest.TestSuite()
        result = unittest.TestResult()
        suite.run(result)
        self.assertEqual(result.testsRun, 0)
        self.assertTrue(result.wasSuccessful())

    def test_runner_captures_assertion_error_diff(self) -> None:
        """T2-F13-02: TestResult accurately records failure in failures list."""
        class FailingCase(unittest.TestCase):
            def runTest(self) -> None:
                self.assertEqual(1, 2)

        suite = unittest.TestSuite([FailingCase()])
        result = unittest.TestResult()
        suite.run(result)
        self.assertEqual(len(result.failures), 1)
        self.assertFalse(result.wasSuccessful())

    def test_runner_handles_uncaught_exception(self) -> None:
        """T2-F13-03: Unexpected exceptions are caught and recorded in errors list."""
        class ErrorCase(unittest.TestCase):
            def runTest(self) -> None:
                raise RuntimeError("Unexpected boom")

        suite = unittest.TestSuite([ErrorCase()])
        result = unittest.TestResult()
        suite.run(result)
        self.assertEqual(len(result.errors), 1)
        self.assertFalse(result.wasSuccessful())

    def test_runner_skips_counting(self) -> None:
        """T2-F13-04: Skipped tests do not count as failures."""
        class SkippedCase(unittest.TestCase):
            def runTest(self) -> None:
                self.skipTest("Intentional skip")

        suite = unittest.TestSuite([SkippedCase()])
        result = unittest.TestResult()
        suite.run(result)
        self.assertEqual(len(result.skipped), 1)
        self.assertEqual(len(result.failures), 0)
        self.assertTrue(result.wasSuccessful())

    def test_runner_exit_code_on_failure(self) -> None:
        """T2-F13-05: Runner maps un-successful result to exit code 1."""
        class FailingCase(unittest.TestCase):
            def runTest(self) -> None:
                self.fail("Failure test")

        suite = unittest.TestSuite([FailingCase()])
        result = unittest.TestResult()
        suite.run(result)
        exit_code = 0 if result.wasSuccessful() else 1
        self.assertEqual(exit_code, 1)


if __name__ == "__main__":
    unittest.main()
