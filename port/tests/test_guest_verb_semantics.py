"""Retail keys and pointer-only verb cycling, pinned by rendered results."""
import os
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
# BIOS keyboard IF correction shifts rain animation phase. Old/new replays
# were pixel-audited at all 17 checkpoints: no differences outside the rain
# rectangle (51,4)-(136,75), including unchanged verb/text/inventory pixels.
KEY_HASHES = {
    "key_g_take": "c66da11afc1ab5ea", "key_o_open": "a07b6fc1662f992a",
    "key_c_close": "83690ab14bff6e8b", "key_t_talk": "523f6818f6f2182d",
    "key_l_look": "4c48e145df8a198e", "key_p_put": "f6af6e7867cf32a8",
}
CONTEXT_HASHES = {
    "context_computer": "2824febf16eb5715",
    **dict(zip((f"context_hover_{y}" for y in [7,17,27,37,47,57,67,87,97,107]), [
        "912c2da57fa00221", "c7e0547a000309ee", "2c9d889add312aad",
        "2e637db0ae042ff4", "ed49bf3cac9497bd", "7cbf89d0c20fd67c",
        "49d9f8d252225348", "c4595761b21e54be", "0627b8e21d56f1ca",
        "aabd13ebdd1c69f8",
    ])),
}

def yellow_pixels(path, top):
    """Count the actual yellow retail glyph pixels in one verb row."""
    bmp = path.read_bytes()
    offset = struct.unpack_from("<I", bmp, 10)[0]
    width, height = struct.unpack_from("<ii", bmp, 18)
    assert (width, height) == (320, 200)
    assert struct.unpack_from("<H", bmp, 28)[0] == 24
    stride = (width*3+3) & ~3
    return sum(bmp[offset+(height-1-y)*stride+x*3:offset+(height-1-y)*stride+x*3+3]
               == b"\x00\xff\xff"
               for y in range(top, top+10) for x in range(2,49))


class GuestVerbSemanticsTests(unittest.TestCase):
    def replay(self, trace, expected, budget, directory):
        data = Path(os.environ["XANTH_DATA"])
        script = (ROOT / "tests/traces" / trace).read_text()
        script = re.sub(r"(?m)^shot (.+)$",
                        lambda match: "shot " + str(directory / Path(match[1]).name), script)
        local_trace = directory / "trace.xit"
        local_trace.write_text(script)
        saves = directory / "saves"
        saves.mkdir()
        proc = subprocess.run([
            os.environ["XANTH_VMBOOT"], "--exe", str(data / "XANTH.EXE"),
            "--data", str(data), "--saves", str(saves), "--script", str(local_trace),
            "--insns", str(budget), "--vm-only",
        ], cwd=ROOT, capture_output=True, text=True, timeout=300,
            env={**os.environ,"SDL_VIDEODRIVER":"dummy","SDL_AUDIODRIVER":"dummy"})
        output = proc.stdout + proc.stderr
        self.assertEqual(proc.returncode, 0, output[-3000:])
        self.assertIn("fault                 : ok", output)
        self.assertIn("MCB chain valid       : yes", output)
        self.assertEqual(dict(re.findall(r"\[script\] hash (\S+) = ([0-9a-f]+)", output)), expected)

    def test_letter_keys_act_on_hovered_object(self):
        with tempfile.TemporaryDirectory(prefix="xanth-verb-keys-") as tmp:
            directory = Path(tmp)
            self.replay("guest_verb_keys_probe.xit", KEY_HASHES, 1500000000, directory)
            # P builds 'Put the bracelet on'. The key shortcut does not render
            # a yellow verb-row highlight; pointer cycling is checked separately.
            for top in [4,14,24,34,44,54,64]:
                self.assertEqual(yellow_pixels(directory/"p_put.bmp", top), 0)

    def test_pointer_motion_cycles_exact_standard_and_context_highlights(self):
        with tempfile.TemporaryDirectory(prefix="xanth-verb-context-") as tmp:
            directory = Path(tmp)
            self.replay("guest_verb_context_probe.xit", CONTEXT_HASHES, 1200000000, directory)
            tops = [4,14,24,34,44,54,64,84,94]
            for y in [7,17,27,37,47,57,67,87,97,107]:
                for top in tops:
                    count = yellow_pixels(directory/f"context_row_{y}.bmp", top)
                    if top == y-3:
                        self.assertGreater(count, 30, (y,top,count))
                    else:
                        self.assertEqual(count, 0, (y,top,count))
            # y107 is past the actual two-row context list; it must not highlight.


if __name__ == "__main__":
    unittest.main()
