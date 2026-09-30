"""Guest-input continuation from the verified 275-point barrow save."""
from __future__ import annotations

import hashlib
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import tempfile
import unittest

from tests.font_ocr import read_game_font_text

ROOT = Path(__file__).resolve().parent.parent
DATA = ROOT / "game_cd" / "XANTH"
ANCHOR_SHA256 = "901998237900d1665a78bfcc42cb0f067045c49806edc336efbed7bd062647df"


class FireCharcoalRouteTests(unittest.TestCase):
    def test_firewall_charcoal_is_collected_without_changing_the_anchor(self) -> None:
        tool = Path(os.environ.get("XANTH_VM_TOOL", ROOT / "build" / "tool_vmboot")).resolve()
        anchor = Path(os.environ.get("XANTH_FIRE_ANCHOR", ROOT / "build" / "agent_dungeon_test")).resolve()
        slot = anchor / "XANTH000.SAV"
        for path in (tool, ROOT / "original" / "XANTH.EXE", DATA, slot):
            if not path.exists():
                self.skipTest(f"retail walkthrough prerequisite unavailable: {path}")
        before = slot.read_bytes()
        if hashlib.sha256(before).hexdigest() != ANCHOR_SHA256:
            self.skipTest("the guest-generated, hash-identified 275-point anchor is unavailable")
        self.assertEqual(struct.unpack_from("<H", before, 0x347D)[0], 275)
        with tempfile.TemporaryDirectory(prefix="xanth-fire-charcoal-") as temporary:
            saves = Path(temporary) / "saves"
            shutil.copytree(anchor, saves)
            # Keep witnesses private to this invocation, including included traces.
            frames = Path(temporary) / "frames"
            frames.mkdir()
            traces = Path(temporary) / "traces"
            for relative in ("walkthrough_19_charcoal.xit", "walkthrough_18_firewall.xit",
                             "lib/resume_barrow_unmasked.xit", "lib/boot.xit"):
                target = traces / relative
                target.parent.mkdir(parents=True, exist_ok=True)
                source = ROOT / "tests" / "traces" / relative
                target.write_text(source.read_text().replace("shot build/frames/", f"shot {frames}/"))
            proc = subprocess.run(
                [str(tool), "--exe", str(ROOT / "original" / "XANTH.EXE"),
                 "--data", str(DATA), "--saves", str(saves),
                 "--script", str(traces / "walkthrough_19_charcoal.xit"),
                 "--insns", "6000000000"],
                capture_output=True, text=True, cwd=ROOT, timeout=600,
            )
            out = proc.stdout + proc.stderr
            self.assertEqual(proc.returncode, 0, out[-4000:])
            self.assertIn("fault                 : ok", out)
            self.assertIn("MCB chain valid       : yes", out)
            marks = dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", out))
            self.assertEqual(marks.get("wt18_firewall"), "dc10de12e2f8098d")
            self.assertEqual(marks.get("wt19_charcoal_taken"), "b65a762ada0a1483")
            text = read_game_font_text(
                frames / "wt19_charcoal_taken.bmp",
                DATA / "XANTH_10.FNT", 125, 160,
            )
            self.assertIn("You take the charred wood", text)
            self.assertIn("5 points", text)
            self.assertEqual((saves / "XANTH000.SAV").read_bytes(), before)
        self.assertEqual(slot.read_bytes(), before)


if __name__ == "__main__":
    unittest.main()
