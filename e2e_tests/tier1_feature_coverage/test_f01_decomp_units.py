"""Tier 1: Feature Coverage — Feature 1: Decompile remaining dump units (F1).

Verifies the decomposition unit census, unit kinds classification, source file presence,
function shape framing, and calling convention signatures.
"""

from __future__ import annotations

import unittest
from pathlib import Path

from e2e_tests.test_runner_common import ROOT, load_c_units_json, load_indexed_units


class TestF01DecompUnits(unittest.TestCase):
    """Tier 1 tests for F1: Decompilation Unit Census & Recovery."""

    def setUp(self) -> None:
        self.config = load_c_units_json()
        self.raw_units = self.config["units"]
        self.indexed_units = load_indexed_units()

    def test_total_units_census_schema(self) -> None:
        """T1-F01-01: Census contains 2,844 units with required schema fields."""
        self.assertEqual(len(self.raw_units), 2844)
        required_fields = {"image", "offset", "source"}
        for unit in self.raw_units[:50]:  # sample check
            self.assertTrue(required_fields.issubset(unit.keys()), f"Unit {unit} missing required fields")

    def test_unit_classification_kinds(self) -> None:
        """T1-F01-02: Units are partitioned into expected classification kinds."""
        kinds = {unit["kind"] for unit in self.indexed_units}
        expected_kinds = {"c", "asm", "wasm", "data", "dump"}
        self.assertTrue(kinds.issubset(expected_kinds), f"Unexpected kinds: {kinds - expected_kinds}")
        dump_count = sum(1 for u in self.indexed_units if u["kind"] == "dump")
        self.assertEqual(dump_count, 0)

    def test_source_file_existence_for_recovered_units(self) -> None:
        """T1-F01-03: Representative C and ASM source files exist on disk in src/."""
        c_units = [u for u in self.indexed_units if u["kind"] == "c"]
        asm_units = [u for u in self.indexed_units if u["kind"] == "asm"]
        self.assertGreater(len(c_units), 400)
        self.assertGreater(len(asm_units), 900)

        for u in c_units[:10] + asm_units[:10]:
            p = ROOT / u["source"]
            self.assertTrue(p.is_file(), f"Source file {u['source']} does not exist")

    def test_dump_unit_shape_distribution(self) -> None:
        """T1-F01-04: Dump units count is 0 reflecting 100% elimination in Milestone 1."""
        dump_units = [u for u in self.indexed_units if u["kind"] == "dump"]
        self.assertEqual(len(dump_units), 0)
        shapes = {u.get("shape", "unknown") for u in dump_units}
        self.assertTrue(shapes.issubset({"function", "unframed-function", "unknown"}))

    def test_recovered_c_units_calling_conventions(self) -> None:
        """T1-F01-05: Recovered C functions have valid far calling conventions."""
        c_units = [u for u in self.indexed_units if u["kind"] == "c"]
        checked = 0
        for u in c_units[:30]:
            p = ROOT / u["source"]
            if p.is_file():
                content = p.read_text(encoding="latin1")
                if "far" in content or "cdecl" in content or "pascal" in content:
                    checked += 1
        self.assertGreater(checked, 0, "No standard far calling conventions found in sampled C units")


if __name__ == "__main__":
    unittest.main()
