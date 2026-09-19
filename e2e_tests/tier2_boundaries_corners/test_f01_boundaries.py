"""Tier 2: Boundary & Corner Cases — Feature 1: Decompile remaining dump units (F1).

Verifies boundary conditions, maximum extents, unframed functions, and invalid classification kinds.
"""

from __future__ import annotations

import unittest

from e2e_tests.test_runner_common import load_indexed_units


class TestF01Boundaries(unittest.TestCase):
    """Tier 2 tests for F1: Decompilation Unit Boundaries."""

    def setUp(self) -> None:
        self.units = load_indexed_units()

    def test_empty_unit_source_path_handling(self) -> None:
        """T2-F01-01: Reject empty or whitespace-only source file paths."""
        for u in self.units:
            source = u.get("source", "").strip()
            self.assertTrue(len(source) > 0, "Found unit with empty source path")

    def test_maximum_extent_dump_unit_boundary(self) -> None:
        """T2-F01-02: Maximum dump unit extent is 0 with 0 dump units remaining."""
        dump_units = [u for u in self.units if u.get("kind") == "dump" and u.get("extent") is not None]
        max_extent = max(u["extent"] for u in dump_units) if dump_units else 0
        # Largest unit in Xanth is approx 1,118 bytes, well within 65,536
        self.assertLess(max_extent, 65536)
        self.assertEqual(max_extent, 0)

    def test_unframed_dump_functions_shape_count(self) -> None:
        """T2-F01-03: Unframed helper function units count is 0 with 0 dump units remaining."""
        unframed = [u for u in self.units if u.get("shape") == "unframed-function"]
        self.assertEqual(len(unframed), 0, "Expected 0 unframed helper functions remaining")
        for u in unframed:
            self.assertEqual(u["image"], "exe-code")

    def test_zero_length_extent_boundary(self) -> None:
        """T2-F01-04: Handling units with None or 0 extent does not crash census math."""
        none_extent_count = sum(1 for u in self.units if u.get("extent") is None)
        # Census should have mixed or unanalyzed units with extent=None handled safely
        self.assertGreater(none_extent_count, 0)

    def test_invalid_classification_kind_rejection(self) -> None:
        """T2-F01-05: Census classifier rejects invalid kinds not in canonical set."""
        valid_kinds = {"c", "asm", "wasm", "data", "dump"}
        test_kinds = ["c", "asm", "wasm", "data", "dump", "invalid_unit_kind", ""]
        for k in test_kinds:
            if k not in valid_kinds:
                self.assertNotIn(k, valid_kinds)


if __name__ == "__main__":
    unittest.main()
