import json
import unittest
from pathlib import Path

from tools.c_units import load_units, splice_exe_code
from tools.compile_msc import compile_c, toolchain_available
from tools.compare import compare_bytes
from tools.mz import split_exe
from tools.rebuild import rebuild_and_compare
from tools.retail_common import ROOT

TARGET = json.loads((ROOT / "config/target.json").read_text())


class CUnitSpliceTests(unittest.TestCase):
    def test_config_lists_recovered_c_sources(self):
        units = load_units(ROOT)
        self.assertGreaterEqual(len(units), 1)
        for unit in units:
            self.assertEqual(unit["image"], "exe-code")
            self.assertTrue((ROOT / unit["source"]).is_file())
            self.assertGreaterEqual(int(unit["offset"]), 0)

    def test_each_c_unit_compiles_to_retail_bytes_and_rebuild_stays_matched(self):
        if not toolchain_available():
            self.skipTest("MSVC 8.00c under wine is not provisioned")
        exe = ROOT / TARGET["executable"]["path"]
        ovl = ROOT / TARGET["overlay"]["path"]
        if not exe.is_file() or not ovl.is_file():
            self.skipTest("original retail files absent")
        _, code, _ = split_exe(exe.read_bytes())
        buf = bytearray(code)
        applied = splice_exe_code(buf, root=ROOT)
        self.assertEqual(len(applied), len(load_units(ROOT)))
        for unit, info in zip(load_units(ROOT), applied):
            compiled = compile_c(ROOT / unit["source"])
            while compiled.endswith(b"\x90") and len(compiled) > info["size"]:
                compiled = compiled[:-1]
            slice_ = bytes(buf[info["offset"] : info["offset"] + info["size"]])
            self.assertEqual(compare_bytes(compiled, slice_)["result"], "BINARY-MATCH")
            retail = code[info["offset"] : info["offset"] + info["size"]]
            self.assertEqual(compare_bytes(retail, slice_)["result"], "BINARY-MATCH")
        report = rebuild_and_compare(ROOT)
        self.assertEqual(report["result"], "BINARY-MATCH")
        self.assertEqual(report["executable"]["sha256"], TARGET["executable"]["sha256"])
        self.assertEqual(report["overlay"]["sha256"], TARGET["overlay"]["sha256"])
        self.assertEqual(len(report["executable"]["parts"]["c_units"]), len(applied))
        self.assertIsNotNone(report["executable"]["parts"]["linker"])
        self.assertEqual(report["executable"]["parts"]["linker"]["linker"], "Microsoft LINK (MSVC 8.00c)")
        self.assertEqual(report["executable"]["parts"]["linker"]["overlay_layout"], "legend-reconstructed")
