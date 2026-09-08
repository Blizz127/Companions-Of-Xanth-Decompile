import unittest

from tools.compile_msc import compile_c, toolchain_available
from tools.compare import compare_bytes
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class CompileMscTests(unittest.TestCase):
    def test_large_model_far_pointer_store_matches_recorded_ledata(self):
        if not toolchain_available():
            self.skipTest("MSVC 8.00c under wine is not provisioned")
        source = ROOT / "src/pointer.c"
        first = compile_c(source)
        second = compile_c(source)
        self.assertEqual(compare_bytes(first, second)["result"], "BINARY-MATCH")
        self.assertGreaterEqual(len(first), 6)
        self.assertEqual(first[:3], b"\x55\x8B\xEC")
        self.assertEqual(first[-2:], b"\x5D\xCB")
