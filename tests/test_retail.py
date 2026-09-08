import hashlib
import json
import tempfile
import unittest
from pathlib import Path

from tools.retail_common import RetailError, sha256_file, verify_file


class RetailCommonTests(unittest.TestCase):
    def test_sha256_file_matches_hashlib(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "blob.bin"
            path.write_bytes(b"xanth")
            self.assertEqual(sha256_file(path), hashlib.sha256(b"xanth").hexdigest())

    def test_verify_file_accepts_matching_size_and_hash(self):
        payload = b"XANBUD"
        digest = hashlib.sha256(payload).hexdigest()
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "XANBUD.iso"
            path.write_bytes(payload)
            self.assertEqual(verify_file(path, expected_size=len(payload), expected_sha256=digest), digest)

    def test_verify_file_rejects_size_mismatch(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "XANBUD.iso"
            path.write_bytes(b"xx")
            with self.assertRaises(RetailError):
                verify_file(path, expected_size=1, expected_sha256="00")

    def test_verify_file_rejects_hash_mismatch(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "XANBUD.iso"
            path.write_bytes(b"xx")
            with self.assertRaises(RetailError):
                verify_file(
                    path,
                    expected_size=2,
                    expected_sha256="0" * 64,
                )

    def test_verify_file_rejects_missing(self):
        with self.assertRaises(RetailError):
            verify_file(Path("/tmp/xanth-missing-iso-does-not-exist"), expected_size=1, expected_sha256="00")
