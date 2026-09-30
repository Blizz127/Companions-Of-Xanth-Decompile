"""Differential test: the port's C MZ loader vs the Python reference.

The decompilation pipeline trusts `tools/identify.py` / `tools/mz.py` to parse
and rebuild the retail MZ header byte-for-byte (`tools/verify.py` reports
BINARY-MATCH on the strength of it). The native port ships its own loader in
C. If the two ever disagree about the image size, the relocation walk, or the
entry point, one of them is wrong -- and this is how we find out which, rather
than discovering it as a mysterious crash forty minutes into a playthrough.

Skips cleanly when the retail disc or the built tool are absent, so it is safe
in asset-free CI.
"""

from __future__ import annotations

import os
import json
import struct
import subprocess
import unittest
from pathlib import Path

def unavailable(message: str) -> Exception:
    """An explicitly configured game/tool run must fail rather than skip."""
    if any(os.environ.get(key) for key in ("XANTH_DATA", "XANTH_VM_TOOL", "XANTH_MZ_TOOL")):
        return FileNotFoundError(message)
    return unittest.SkipTest(message)


PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA = Path(os.environ.get("XANTH_DATA", PROJECT_ROOT / "game_cd" / "XANTH"))
EXE = DATA / "XANTH.EXE"
TOOL = Path(os.environ.get("XANTH_MZ_TOOL", PROJECT_ROOT / "build" / "tool_mzdump"))

LOAD_SEG = 0x1000

FNV_OFFSET = 1469598103934665603
FNV_PRIME = 1099511628211
MASK64 = (1 << 64) - 1


def fnv1a64(data: bytes) -> int:
    h = FNV_OFFSET
    for b in data:
        h = ((h ^ b) * FNV_PRIME) & MASK64
    return h


def python_reference_load(raw: bytes, load_seg: int) -> dict:
    """Mirror of mz_load_file(), written straight from the header fields."""
    (cblp, cp, crlc, cparhdr, minalloc, maxalloc,
     ss, sp, csum, ip, cs, lfarlc, ovno) = struct.unpack("<13H", raw[2:28])

    header_bytes = cparhdr * 16
    image_size = (cp - 1) * 512 + (cblp if cblp else 512) - header_bytes

    image = bytearray(raw[header_bytes:header_bytes + image_size])

    applied = 0
    for i in range(crlc):
        rec = lfarlc + i * 4
        r_off, r_seg = struct.unpack("<HH", raw[rec:rec + 4])
        target = r_seg * 16 + r_off
        assert target + 2 <= image_size, f"reloc {i} outside image"
        val = (struct.unpack_from("<H", image, target)[0] + load_seg) & 0xFFFF
        struct.pack_into("<H", image, target, val)
        applied += 1

    return {
        "load_seg": load_seg,
        "cblp": cblp, "cp": cp, "crlc": crlc, "cparhdr": cparhdr,
        "minalloc": minalloc, "maxalloc": maxalloc,
        "ss": ss, "sp": sp, "ip": ip, "cs": cs, "lfarlc": lfarlc,
        "header_bytes": header_bytes,
        "image_size": image_size,
        "tail_size": len(raw) - (header_bytes + image_size),
        "relocs_applied": applied,
        "entry_cs": (cs + load_seg) & 0xFFFF,
        "entry_ip": ip,
        "entry_ss": (ss + load_seg) & 0xFFFF,
        "entry_sp": sp,
        "image_fnv1a64": f"{fnv1a64(bytes(image)):016x}",
    }


class MzLoaderDifferentialTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        if not EXE.exists():
            raise unavailable(f"retail image not present: {EXE}")
        if not TOOL.exists():
            raise unavailable(
                f"{TOOL} not built; run scripts/build_port.sh first")
        cls.raw = EXE.read_bytes()
        proc = subprocess.run(
            [str(TOOL), str(EXE), f"{LOAD_SEG:x}"],
            capture_output=True, text=True, check=True,
        )
        cls.c_result = json.loads(proc.stdout)
        cls.py_result = python_reference_load(cls.raw, LOAD_SEG)

    def test_header_fields_agree(self) -> None:
        for key in ("cblp", "cp", "crlc", "cparhdr", "minalloc", "maxalloc",
                    "ss", "sp", "ip", "cs", "lfarlc",
                    "header_bytes", "image_size", "tail_size"):
            self.assertEqual(self.c_result[key], self.py_result[key],
                             f"header field {key} differs")

    def test_all_relocations_applied(self) -> None:
        self.assertEqual(self.c_result["relocs_applied"],
                         self.py_result["relocs_applied"])
        self.assertEqual(self.c_result["relocs_applied"],
                         self.py_result["crlc"],
                         "every declared relocation must be applied")

    def test_entry_point_agrees(self) -> None:
        for key in ("entry_cs", "entry_ip", "entry_ss", "entry_sp"):
            self.assertEqual(self.c_result[key], self.py_result[key],
                             f"entry field {key} differs")

    def test_relocated_image_is_byte_identical(self) -> None:
        """The whole point: 191,656 relocated bytes must match exactly."""
        self.assertEqual(self.c_result["image_fnv1a64"],
                         self.py_result["image_fnv1a64"])

    def test_retail_shape_is_what_the_port_assumes(self) -> None:
        """Pin the facts the Stage 1 design is built on, so a different disc
        revision fails loudly here rather than somewhere subtle."""
        r = self.py_result
        self.assertEqual(r["image_size"], 191656)
        self.assertEqual(r["crlc"], 5304)
        self.assertEqual(r["tail_size"], 43193, "RTLink runtime tail")
        self.assertEqual(r["maxalloc"], 0xFFFF,
                         "maxalloc=FFFF is why an MCB manager is mandatory")


if __name__ == "__main__":
    unittest.main()
