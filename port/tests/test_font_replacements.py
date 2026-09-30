"""Verify visible, format-preserving font replacements and separate opt-ins."""

from __future__ import annotations

import hashlib
import os
import re
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

from test_stage2_opening import DATA, EXPECTED_HASHES, ROOT, TRACE

EXE = DATA / "XANTH.EXE"
RETAIL_BMP_SHA256 = "719c68af9d67f6d1b8d146bde9d2877799cd4ef846943f1db72692f6e2bda96e"
MIRRORED_FRAME_HASH = "0d7b760b986313c2"
MIRRORED_BMP_SHA256 = "f410c27ad6decb29bcb576dc5c75680476ee31d6af8fe25cf2ccdd62e8214736"


def mirror_ui_font(original: bytes) -> bytes:
    """Mirror only bitmap rows in the measured retail XANTH_10.FNT layout.

    The existing retail screenshot OCR uses this same 138-byte header/width
    table and 95 eight-row glyph layout. Keep advances, dimensions, character
    range, and file size intact; no font parser or retail asset is patched.
    """
    if len(original) != 138 + 95 * 8 or original[:10] != bytes(
        (1, 1, 1, 0x21, 0x7F, 0, 8, 0xFF, 0, 0)
    ):
        raise ValueError("unexpected retail UI font layout")
    changed = bytearray(original)
    for code in range(0x21, 0x80):
        width = original[10 + code]
        if not 1 <= width <= 8:
            raise ValueError(f"unexpected glyph width for {code}: {width}")
        offset = 138 + (code - 0x21) * 8
        for row in range(offset, offset + 8):
            # Preserve unused bits while mirroring within the advance width.
            mask = (0xFF << (8 - width)) & 0xFF
            bitmap = original[row]
            changed[row] = (bitmap & ~mask) | sum(
                ((bitmap >> (7 - bit)) & 1) << (8 - width + bit)
                for bit in range(width)
            )
    return bytes(changed)


def bmp_crop(bitmap: bytes, x0: int, y0: int, x1: int, y1: int) -> bytes:
    """Extract top-origin RGB24 pixels, ignoring BMP headers and row padding."""
    if bitmap[:2] != b"BM":
        raise ValueError("expected a BMP screenshot")
    offset = struct.unpack_from("<I", bitmap, 10)[0]
    width, height = struct.unpack_from("<ii", bitmap, 18)
    if (width, height, struct.unpack_from("<H", bitmap, 28)[0]) != (320, 200, 24):
        raise ValueError("unexpected guest screenshot dimensions or depth")
    stride = (width * 3 + 3) & ~3
    return b"".join(
        bitmap[offset + (height - 1 - y) * stride + x0 * 3:
               offset + (height - 1 - y) * stride + x1 * 3]
        for y in range(y0, y1)
    )


class FontReplacementTests(unittest.TestCase):
    def test_visible_ui_font_requires_font_opt_in(self) -> None:
        if not EXE.is_file() or not DATA.is_dir():
            self.fail(f"required retail files are missing: {EXE}")
        original = (DATA / "XANTH_10.FNT").read_bytes()
        self.assertEqual(hashlib.sha256(original).hexdigest(),
                         "fd202d548c4e2bdc0e4b26326b1daf05824083f1c39472aaf5d6f83a732b11de")
        changed = mirror_ui_font(original)
        self.assertEqual(changed[:138], original[:138])
        self.assertEqual(len(changed), len(original))
        self.assertNotEqual(changed, original)
        tool = Path(os.environ["XANTH_VMBOOT"])
        outputs: dict[str, tuple[dict[str, str], bytes]] = {}
        with tempfile.TemporaryDirectory(prefix="xanth-font-mod-parity-") as tmp:
            base = Path(tmp)
            mods = base / "mods"
            mods.mkdir()
            empty_mods = base / "empty-mods"
            empty_mods.mkdir()
            (mods / hashlib.sha256(original).hexdigest()).write_bytes(changed)
            modes = (
                ("retail", []),
                ("mods_disabled", ["--mods", str(mods)]),
                ("graphics_only", ["--mods", str(mods), "--replacement-graphics"]),
                ("fonts_without_mods", ["--replacement-fonts"]),
                ("missing_replacement", ["--mods", str(empty_mods), "--replacement-fonts"]),
                ("fonts_enabled", ["--mods", str(mods), "--replacement-fonts"]),
            )
            # Reuse the measured cold boot to the bedroom. Later route behavior
            # is independently pinned by the opening native parity regression.
            script = TRACE.read_text().split("checkpoint wt_bedroom", 1)[0]
            for mode, flags in modes:
                with self.subTest(mode=mode):
                    saves = base / f"saves-{mode}"
                    saves.mkdir()
                    shot = base / f"{mode}.bmp"
                    trace = base / f"{mode}.xit"
                    trace.write_text(script + f"checkpoint wt_bedroom\nshot {shot}\n",
                                     encoding="ascii")
                    proc = subprocess.run(
                        [str(tool), "--exe", str(EXE), "--data", str(DATA),
                         "--saves", str(saves), "--script", str(trace),
                         "--insns", "2000000000", *flags],
                        cwd=ROOT,
                        env={**os.environ, "SDL_VIDEODRIVER": "dummy",
                             "SDL_AUDIODRIVER": "dummy"},
                        check=False, capture_output=True, text=True, timeout=180,
                    )
                    output = proc.stdout + proc.stderr
                    self.assertEqual(proc.returncode, 0, output[-3000:])
                    self.assertIn("fault                 : ok", output)
                    self.assertIn("MCB chain valid       : yes", output)
                    hashes = dict(re.findall(
                        r"\[script\] hash (\S+) = ([0-9a-f]+)", output
                    ))
                    self.assertEqual(hashes.keys(), {"wt_bedroom"})
                    outputs[mode] = (hashes, shot.read_bytes())

            self.assertEqual(outputs["retail"][0],
                             {"wt_bedroom": EXPECTED_HASHES["wt_bedroom"]})
            self.assertEqual(outputs["retail"], outputs["mods_disabled"])
            self.assertEqual(outputs["retail"], outputs["graphics_only"])
            self.assertEqual(outputs["retail"], outputs["fonts_without_mods"])
            self.assertEqual(outputs["retail"], outputs["missing_replacement"])
            self.assertEqual(outputs["fonts_enabled"][0]["wt_bedroom"],
                             MIRRORED_FRAME_HASH)
            retail_bmp, changed_bmp = outputs["retail"][1], outputs["fonts_enabled"][1]
            self.assertEqual(hashlib.sha256(retail_bmp).hexdigest(), RETAIL_BMP_SHA256)
            self.assertEqual(hashlib.sha256(changed_bmp).hexdigest(), MIRRORED_BMP_SHA256)
            if os.environ.get("XANTH_FONT_EVIDENCE"):
                for mode, (hashes, bitmap) in outputs.items():
                    print(f"{mode}: bedroom={hashes['wt_bedroom']} "
                          f"bmp_sha256={hashlib.sha256(bitmap).hexdigest()}")
            # XANTH_10 is the narrative font; verbs use another retail font.
            self.assertTrue(bmp_crop(retail_bmp, 50, 128, 315, 148) !=
                            bmp_crop(changed_bmp, 50, 128, 315, 148),
                            "font replacement did not visibly change narrative text")
            self.assertTrue(bmp_crop(retail_bmp, 60, 20, 315, 120) ==
                            bmp_crop(changed_bmp, 60, 20, 315, 120),
                            "font replacement changed bedroom scene art")
            self.assertTrue(bmp_crop(retail_bmp, 0, 0, 49, 80) ==
                            bmp_crop(changed_bmp, 0, 0, 49, 80),
                            "font replacement changed another font's verb panel")


if __name__ == "__main__":
    unittest.main()
