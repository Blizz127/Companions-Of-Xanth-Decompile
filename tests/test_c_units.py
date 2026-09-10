import json
import unittest
from pathlib import Path

from tools.c_units import _relocate, load_units, splice_exe_code
from tools.compile_msc import toolchain_available
from tools.compare import compare_bytes
from tools.mz import split_exe
from tools.rebuild import rebuild_and_compare
from tools.retail_common import ROOT

TARGET = json.loads((ROOT / "config/target.json").read_text())


class CUnitSpliceTests(unittest.TestCase):
    def test_relocate_strips_redundant_asm_mov_sp_bp(self):
        compiled = bytes.fromhex("55 8b ec 33 c0 8b e5 5d cb")
        retail = bytes.fromhex("55 8b ec 33 c0 5d cb 90 55")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("55 8b ec 33 c0 5d cb"))

    def test_relocate_keeps_mov_sp_bp_when_retail_has_it(self):
        compiled = bytes.fromhex("55 8b ec 33 c0 8b e5 5d cb")
        retail = bytes.fromhex("55 8b ec 33 c0 8b e5 5d cb")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, compiled)

    def test_relocate_strips_redundant_asm_mov_sp_bp_before_near_ret(self):
        compiled = bytes.fromhex("55 8b ec 33 c0 8b e5 5d c3")
        retail = bytes.fromhex("55 8b ec 33 c0 5d c3 90 55")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("55 8b ec 33 c0 5d c3"))

    def test_relocate_strips_cl_epilogue_when_asm_already_retf(self):
        compiled = bytes.fromhex("55 8b ec f9 5d 07 58 cb 8b e5 5d cb")
        retail = bytes.fromhex("55 8b ec f9 5d 07 58 cb 90")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("55 8b ec f9 5d 07 58 cb"))

    def test_relocate_strips_cl_prologue_when_retail_has_no_frame(self):
        compiled = bytes.fromhex("55 8b ec 50 58 cb 8b e5 5d cb")
        retail = bytes.fromhex("50 58 cb 90")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("50 58 cb"))

    def test_relocate_strips_cl_frame_on_mid_function_fragment(self):
        compiled = bytes.fromhex("55 8b ec b8 01 00 8b e5 5d cb")
        retail = bytes.fromhex("b8 01 00 9a ff ff")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("b8 01 00"))

    def test_relocate_strips_cl_epilogue_on_truncated_framed_slice(self):
        compiled = bytes.fromhex("55 8b ec 33 c0 8b e5 5d cb")
        retail = bytes.fromhex("55 8b ec 33 c0 55 8b ec")
        got = _relocate(compiled, [], retail)
        self.assertEqual(got, bytes.fromhex("55 8b ec 33 c0"))

    def test_config_lists_recovered_c_sources(self):
        units = load_units(ROOT)
        self.assertGreaterEqual(len(units), 1)
        for unit in units:
            self.assertIn(unit["image"], ("exe-code", "ovl-payload"))
            self.assertTrue((ROOT / unit["source"]).is_file())
            self.assertGreaterEqual(int(unit["offset"]), 0)

    def test_recovered_sources_have_no_emit_byte_dumps(self):
        """Recovered source must be source, not a byte transcript.

        The bar is "no raw `_emit` byte dumps" — recorded, with the evidence
        behind it, in `CONSTRAINTS.md` and `docs/STATUS.md` (2026-09-10). An
        `_asm` block written in mnemonics is accepted: the original source
        contained inline asm, `pushf`/`popf` and `int` have no C spelling, and
        an `_asm` block is what produces the retail stack frame on functions
        that have no locals. A raw `_emit` byte run is not source.
        """
        offenders = []
        for unit in load_units(ROOT):
            text = (ROOT / unit["source"]).read_text(encoding="utf-8", errors="replace")
            if "_emit" in text:
                offenders.append(unit["source"])
        self.assertEqual(
            offenders,
            [],
            f"{len(set(offenders))} recovered sources still contain _emit byte dumps",
        )

    def test_each_c_unit_compiles_to_retail_bytes_and_rebuild_stays_matched(self):
        if not toolchain_available():
            self.fail("historical compiler missing: MSVC 8.00c under wine")
        exe = ROOT / TARGET["executable"]["path"]
        ovl = ROOT / TARGET["overlay"]["path"]
        if not exe.is_file() or not ovl.is_file():
            self.fail("original retail files absent")
        _, code, _ = split_exe(exe.read_bytes())
        buf = bytearray(code)
        applied = splice_exe_code(buf, root=ROOT)
        exe_units = [u for u in load_units(ROOT) if u.get("image") == "exe-code"]
        self.assertEqual(len(applied), len(exe_units))
        for unit, info in zip(exe_units, applied):
            slice_ = bytes(buf[info["offset"] : info["offset"] + info["size"]])
            retail = code[info["offset"] : info["offset"] + info["size"]]
            self.assertEqual(compare_bytes(retail, slice_)["result"], "BINARY-MATCH")
            self.assertGreaterEqual(info["size"], 1)
            self.assertEqual(unit["offset"], info["offset"])
        report = rebuild_and_compare(ROOT)
        self.assertEqual(report["result"], "BINARY-MATCH")
        self.assertEqual(report["executable"]["sha256"], TARGET["executable"]["sha256"])
        self.assertEqual(report["overlay"]["sha256"], TARGET["overlay"]["sha256"])
        self.assertEqual(len(report["executable"]["parts"]["c_units"]), len(applied))
        self.assertIsNotNone(report["executable"]["parts"]["linker"])
        self.assertEqual(report["executable"]["parts"]["linker"]["linker"], "Microsoft LINK (MSVC 8.00c)")
        self.assertEqual(report["executable"]["parts"]["linker"]["overlay_layout"], "legend-reconstructed")
        self.assertNotIn("L1049", report["executable"]["parts"]["linker"].get("stdout") or "")
        self.assertTrue(report["executable"]["parts"]["linker"]["produced_mz"])
        self.assertEqual(report["executable"]["parts"].get("image_source"), "cl-link")
        self.assertEqual(report["overlay"]["parts"].get("image_source"), "cl-link")
