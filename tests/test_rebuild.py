import json
import unittest
from pathlib import Path

from tools.compare import compare_bytes
from tools.listing import assemble
from tools.rebuild import rebuild_and_compare
from tools.retail_common import ROOT, RetailError


class ListingRoundTripTests(unittest.TestCase):
    def test_nasm_round_trip_of_known_thunk_bytes(self):
        original = bytes.fromhex("559aef09c11d5dcb")
        rebuilt, source = assemble(original)
        self.assertIn("push bp", source)
        self.assertEqual(rebuilt, original)
        self.assertEqual(compare_bytes(original, rebuilt)["result"], "BINARY-MATCH")


class RebuildAgainstRetailTests(unittest.TestCase):
    def test_rebuild_path_matches_pinned_exe_and_ovl(self):
        target = json.loads((ROOT / "config/target.json").read_text())
        exe = ROOT / target["executable"]["path"]
        ovl = ROOT / target["overlay"]["path"]
        if not exe.is_file() or not ovl.is_file():
            with self.assertRaises(RetailError):
                rebuild_and_compare(ROOT)
            return
        report = rebuild_and_compare(ROOT)
        self.assertEqual(report["executable"]["sha256"], target["executable"]["sha256"])
        self.assertEqual(report["overlay"]["sha256"], target["overlay"]["sha256"])
        self.assertEqual(report["executable"]["result"], "BINARY-MATCH")
        self.assertEqual(report["overlay"]["result"], "BINARY-MATCH")
        self.assertEqual(report["result"], "BINARY-MATCH")
        self.assertEqual(report["executable"]["parts"].get("image_source"), "cl-link")
        self.assertEqual(report["overlay"]["parts"].get("image_source"), "cl-link")
