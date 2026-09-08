import hashlib
import json
import unittest
from pathlib import Path

from tools.identify import identify_mz, identify_ovl

ROOT = Path(__file__).resolve().parents[1]


class TargetPinTests(unittest.TestCase):
    def test_config_pins_iso_exe_and_ovl(self):
        target = json.loads((ROOT / "config/target.json").read_text())
        self.assertEqual(target["game"], "Companions of Xanth")
        self.assertEqual(target["identity_status"], "LOCALLY_SUPPORTED_XANBUD")
        for key in ("iso", "executable", "overlay"):
            self.assertIn(key, target)
            self.assertEqual(len(target[key]["sha256"]), 64)
            self.assertGreater(target[key]["size"], 0)

    def test_original_exe_matches_pin_when_present(self):
        target = json.loads((ROOT / "config/target.json").read_text())
        path = ROOT / target["executable"]["path"]
        if not path.is_file():
            self.skipTest("original/XANTH.EXE not extracted")
        data = path.read_bytes()
        self.assertEqual(len(data), target["executable"]["size"])
        self.assertEqual(hashlib.sha256(data).hexdigest(), target["executable"]["sha256"])
        self.assertEqual(data[:2], b"MZ")

    def test_original_ovl_matches_pin_when_present(self):
        target = json.loads((ROOT / "config/target.json").read_text())
        path = ROOT / target["overlay"]["path"]
        if not path.is_file():
            self.skipTest("original/XANTH.OVL not extracted")
        data = path.read_bytes()
        self.assertEqual(len(data), target["overlay"]["size"])
        self.assertEqual(hashlib.sha256(data).hexdigest(), target["overlay"]["sha256"])
        self.assertNotEqual(data[:2], b"MZ")

    def test_iso_matches_pin_when_present(self):
        target = json.loads((ROOT / "config/target.json").read_text())
        path = ROOT / target["iso"]["path"]
        if not path.is_file():
            self.skipTest("XANBUD.iso not present")
        self.assertEqual(path.stat().st_size, target["iso"]["size"])
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        self.assertEqual(digest, target["iso"]["sha256"])

    def test_exe_identify_matches_committed_evidence(self):
        path = ROOT / "original/XANTH.EXE"
        evidence = ROOT / "evidence/target/mz.json"
        if not path.is_file() or not evidence.is_file():
            self.skipTest("original EXE or evidence JSON missing")
        self.assertEqual(identify_mz(path.read_bytes()), json.loads(evidence.read_text()))

    def test_ovl_identify_matches_committed_evidence(self):
        path = ROOT / "original/XANTH.OVL"
        evidence = ROOT / "evidence/target/ovl.json"
        if not path.is_file() or not evidence.is_file():
            self.skipTest("original OVL or evidence JSON missing")
        self.assertEqual(identify_ovl(path.read_bytes()), json.loads(evidence.read_text()))
