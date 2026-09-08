import hashlib
import struct
import unittest

from tools.identify import IdentifyError, identify_mz, identify_ovl


def synthetic_mz(*, relocs=((0x0024, 0x0000),), extra=b"", ip=0x0100, cs=0x0000):
    reloc_bytes = b"".join(struct.pack("<HH", off, seg) for off, seg in relocs)
    header_payload = struct.pack("<HH", 0, 0)  # e_ovno + padding to 0x1E
    # Header layout: 0x00 MZ, 0x02 fields, relocs at 0x1E
    prefix = bytearray(0x1E)
    prefix[0:2] = b"MZ"
    header_paras = 2  # 32-byte header; relocs may spill — bump to fit
    reloc_start = 0x1E
    needed = reloc_start + len(reloc_bytes)
    header_paras = max(2, (needed + 15) // 16)
    header_bytes = header_paras * 16
    image_size = header_bytes + 16  # one paragraph of dummy code
    pages = (image_size + 511) // 512
    last = image_size % 512
    data = bytearray(pages * 512)
    data[0:2] = b"MZ"
    struct.pack_into(
        "<HHHHHHHHHHHHH",
        data,
        2,
        last,
        pages,
        len(relocs),
        header_paras,
        0,
        0xFFFF,
        0x0010,
        0x0100,
        0,
        ip,
        cs,
        reloc_start,
        0,
    )
    data[reloc_start : reloc_start + len(reloc_bytes)] = reloc_bytes
    data[header_bytes : header_bytes + 3] = b"\x90\x90\xC3"
    if extra:
        data.extend(extra)
    # trim to exact image_size + extra; MZ image_size uses cblp/cp
    exact = (pages - 1) * 512 + (last if last else 512)
    data = bytes(data[:exact] + extra)
    return data


class IdentifyMzTests(unittest.TestCase):
    def test_records_hash_header_and_reloc_count(self):
        data = synthetic_mz(relocs=((0x10, 0x1), (0x20, 0x2)))
        report = identify_mz(data)
        self.assertEqual(report["kind"], "mz")
        self.assertEqual(report["sha256"], hashlib.sha256(data).hexdigest())
        self.assertEqual(report["sha1"], hashlib.sha1(data).hexdigest())
        self.assertEqual(report["size"], len(data))
        self.assertEqual(report["mz"]["reloc_count"], 2)
        self.assertEqual(report["mz"]["reloc_offset"], 0x1E)
        self.assertEqual(report["mz"]["ip"], 0x0100)
        self.assertEqual(report["mz"]["ss"], 0x0010)
        self.assertGreaterEqual(report["mz"]["header_bytes"], 0x1E + 8)
        self.assertEqual(report["mz"]["tail_size"], 0)

    def test_splits_mz_image_from_appended_tail(self):
        data = synthetic_mz(extra=b"MS Run-Time Library - Copyright (c) 1992, Microsoft Corp")
        report = identify_mz(data)
        self.assertGreater(report["mz"]["tail_size"], 0)
        self.assertEqual(
            report["mz"]["image_size"] + report["mz"]["tail_size"],
            report["size"],
        )
        self.assertEqual(
            report["tail_sha256"],
            hashlib.sha256(data[report["mz"]["image_size"] :]).hexdigest(),
        )
        self.assertTrue(report["strings"]["microsoft_crt_1992"])

    def test_records_overlay_and_pkware_strings(self):
        extra = b'Cannot find overlay file "XANTH.OVL" PKWARE Data Compression Library(tm)'
        report = identify_mz(synthetic_mz(extra=extra))
        self.assertTrue(report["strings"]["overlay_manager"])
        self.assertTrue(report["strings"]["xanth_ovl"])
        self.assertTrue(report["strings"]["pkware_dcl"])

    def test_deterministic(self):
        data = synthetic_mz()
        self.assertEqual(identify_mz(data), identify_mz(data))

    def test_non_mz_rejected(self):
        with self.assertRaises(IdentifyError):
            identify_mz(b"not an executable")

    def test_truncated_header_rejected(self):
        with self.assertRaises(IdentifyError):
            identify_mz(b"MZ\x00\x01")


def synthetic_ovl():
    directory = struct.pack(
        "<HHHHHHHH",
        0x045E,
        0x30CB,
        0x00D6,
        0x30CB,
        0x0000,
        0xFFFF,
        0x0000,
        0xFFFF,
    )
    pad = b"\x00" * (1792 - len(directory))
    credits = b"Copyright (c) 1994 Legend Entertainment Company\x00"
    return directory + pad + credits


class IdentifyOvlTests(unittest.TestCase):
    def test_rejects_mz_interpretation(self):
        data = synthetic_ovl()
        self.assertNotEqual(data[:2], b"MZ")
        report = identify_ovl(data)
        self.assertEqual(report["kind"], "legend-ovl")
        self.assertFalse(report["is_mz"])

    def test_parses_directory_until_ffff_sentinel(self):
        report = identify_ovl(synthetic_ovl())
        self.assertEqual(report["directory"]["entry_count"], 2)
        self.assertEqual(report["directory"]["load_segment"], 0x30CB)
        self.assertEqual(report["directory"]["terminator_offset"], 8)
        self.assertEqual(report["directory"]["entries"][0]["size"], 0x045E)
        self.assertEqual(report["directory"]["entries"][1]["size"], 0x00D6)

    def test_records_credits_offset(self):
        data = synthetic_ovl()
        report = identify_ovl(data)
        self.assertEqual(report["credits_offset"], 1792)
        self.assertTrue(report["strings"]["legend_copyright_1994"])

    def test_non_table_rejected(self):
        with self.assertRaises(IdentifyError):
            identify_ovl(b"MZ this is an exe stub pretending")

    def test_deterministic(self):
        data = synthetic_ovl()
        self.assertEqual(identify_ovl(data), identify_ovl(data))
