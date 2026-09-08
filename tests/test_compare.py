import unittest

from tools.compare import compare_bytes


class CompareTests(unittest.TestCase):
    def test_equal_buffers_are_binary_match(self):
        blob = b"\x55\x8B\xEC\xCB"
        report = compare_bytes(blob, blob)
        self.assertEqual(report["result"], "BINARY-MATCH")
        self.assertIsNone(report["first_diff"])

    def test_mismatch_reports_first_offset(self):
        report = compare_bytes(b"AAAA", b"ABAA")
        self.assertEqual(report["result"], "DIFF")
        self.assertEqual(report["first_diff"], 1)

    def test_length_mismatch_is_diff(self):
        report = compare_bytes(b"ABC", b"AB")
        self.assertEqual(report["result"], "DIFF")
        self.assertEqual(report["first_diff"], 2)

    def test_does_not_trim_padding(self):
        report = compare_bytes(b"A\x00", b"A")
        self.assertEqual(report["result"], "DIFF")
