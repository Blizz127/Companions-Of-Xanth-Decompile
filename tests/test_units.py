import unittest

from tools import units
from tools.compile_msc import compile_omf, toolchain_available
from tools.coverage import report
from tools.lift import check_compiled, find_units, first_difference
from tools.retail_common import ROOT


class DumpExtentTests(unittest.TestCase):
    """A dump source must lay out against retail exactly like the splice does."""

    @classmethod
    def setUpClass(cls):
        cls.images = units.image_bytes(ROOT)
        cls.rows = units.index(ROOT)

    def test_unresolved_dumps_are_all_mixed_mnemonic_asm(self):
        unresolved = [
            row for row in self.rows if row["kind"] == units.KIND_DUMP and row["extent"] is None
        ]
        for row in unresolved:
            text = (ROOT / row["source"]).read_text(errors="replace")
            self.assertIsNone(
                units.dump_pattern(text),
                f"{row['source']} is a pure dump pattern but did not resolve",
            )
        # Mixed units are hand-written `_asm` that still carries a few `_emit`
        # bytes; they are known and counted, not silently ignored.
        self.assertLess(len(unresolved), 100)

    def test_resolved_pattern_matches_the_retail_slice(self):
        checked = 0
        for row in self.rows:
            if row["extent"] is None:
                continue
            text = (ROOT / row["source"]).read_text(errors="replace")
            pattern = units.dump_pattern(text)
            self.assertIsNotNone(pattern, row["source"])
            framed = self.images[row["image"]][row["offset"] : row["offset"] + 3] == units.PROLOGUE
            start = row["offset"] + (3 if framed else 0)
            blob = self.images[row["image"]][start : start + units.pattern_length(pattern)]
            position = 0
            for want in pattern:
                if want is not None:
                    self.assertEqual(
                        want[0], blob[position], f"{row['source']} differs at {position}"
                    )
                position += 1 if want is not None else 5
            checked += 1
        self.assertGreater(checked, 2000)

    def test_function_shaped_units_are_framed_and_end_with_an_epilogue(self):
        seen = 0
        for row in self.rows:
            if row["shape"] != "function":
                continue
            blob = self.images[row["image"]][row["offset"] : row["offset"] + row["extent"]]
            self.assertEqual(blob[:3], units.PROLOGUE, row["source"])
            self.assertIn(blob[-2:], (b"\x5d\xcb", b"\x5d\xc3"), row["source"])
            seen += 1
        self.assertGreater(seen, 1000)


class CoverageReportTests(unittest.TestCase):
    # Recorded 2026-09-10. See CONSTRAINTS.md: these are ratchets, not targets.
    # They may only move in the improving direction, and moving one is a
    # deliberate edit carrying the new number and its evidence.
    DUMP_PERCENT_CEILING = {"exe-code": 97.91, "ovl-payload": 96.69}
    UNAIDED_C_UNIT_FLOOR = 439

    def test_report_is_self_consistent(self):
        data = report()
        self.assertFalse(data["compile_units"])
        for name, info in data["images"].items():
            self.assertEqual(sum(info["kinds"].values()), info["units"], name)
            self.assertEqual(sum(info["shapes"].values()), info["units"], name)
            self.assertLessEqual(info["bytes_by_kind"]["emit-dump"], info["bytes"])
            self.assertGreater(info["dump_percent"], 90, name)
            self.assertLess(info["dump_percent"], 100, name)
        self.assertEqual(
            data["totals"]["units"], sum(info["units"] for info in data["images"].values())
        )

    def test_emit_dump_coverage_does_not_increase(self):
        data = report()
        for name, ceiling in self.DUMP_PERCENT_CEILING.items():
            info = data["images"][name]
            self.assertLessEqual(
                info["dump_percent"],
                ceiling,
                f"{name} `_emit` dump coverage rose to {info['dump_percent']}% "
                f"(ceiling {ceiling}%); byte dumps were added or units re-split",
            )

    def test_unaided_c_unit_count_does_not_fall(self):
        data = report()
        self.assertGreaterEqual(
            data["totals"]["kinds"]["unaided-c"],
            self.UNAIDED_C_UNIT_FLOOR,
            "unaided-C units were lost; check c-units.json before lowering this ratchet",
        )


class LiftLoopTests(unittest.TestCase):
    def test_first_difference_reports_length_mismatch(self):
        self.assertEqual(first_difference(b"\x01\x02", b"\x01\x03"), 1)
        self.assertEqual(first_difference(b"\x01", b"\x01\x02"), 1)
        self.assertIsNone(first_difference(b"\x01", b"\x01"))

    def test_a_known_good_unit_still_matches_its_retail_slice(self):
        if not toolchain_available():
            self.fail("historical compiler missing: MSVC 8.00c under wine")
        unit = find_units("cli_clear", ROOT)[0]
        compiled, fixups = compile_omf(ROOT / unit["source"])
        result = check_compiled(unit, compiled, fixups, units.image_bytes(ROOT))
        self.assertEqual(result["result"], "MATCH")

    def test_a_wrong_candidate_is_not_a_match(self):
        if not toolchain_available():
            self.fail("historical compiler missing: MSVC 8.00c under wine")
        unit = find_units("exe_1802", ROOT)[0]
        result = check_compiled(unit, bytes(32), [], units.image_bytes(ROOT))
        self.assertEqual(result["result"], "DIFF")


if __name__ == "__main__":
    unittest.main()
