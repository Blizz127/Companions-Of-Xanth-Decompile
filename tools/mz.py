"""Parse and reconstruct MS-DOS MZ images. Relocs are rebuilt from parsed tuples."""

from __future__ import annotations

import struct
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from identify import IdentifyError, identify_mz


def parse_relocs(data: bytes) -> list[tuple[int, int]]:
    report = identify_mz(data)
    offset = report["mz"]["reloc_offset"]
    count = report["mz"]["reloc_count"]
    relocs = []
    for i in range(count):
        off, seg = struct.unpack_from("<HH", data, offset + i * 4)
        relocs.append((off, seg))
    return relocs


def build_mz(*, cs: int, ip: int, ss: int, sp: int, minalloc: int, maxalloc: int, relocs: list[tuple[int, int]], load_image: bytes) -> bytes:
    reloc_offset = 0x1E
    reloc_bytes = b"".join(struct.pack("<HH", off, seg) for off, seg in relocs)
    needed = reloc_offset + len(reloc_bytes)
    header_paras = max(2, (needed + 15) // 16)
    # Match the retail 1888-paragraph header (zero padded after relocs).
    header_paras = max(header_paras, 1888)
    header_bytes = header_paras * 16
    header = bytearray(header_bytes)
    image_size = header_bytes + len(load_image)
    pages = (image_size + 511) // 512
    last = image_size % 512
    header[0:2] = b"MZ"
    struct.pack_into(
        "<HHHHHHHHHHHHH",
        header,
        2,
        last,
        pages,
        len(relocs),
        header_paras,
        minalloc,
        maxalloc,
        ss,
        sp,
        0,
        ip,
        cs,
        reloc_offset,
        0,
    )
    header[reloc_offset : reloc_offset + len(reloc_bytes)] = reloc_bytes
    built = bytes(header[:header_bytes]) + load_image
    # MZ image_size uses cblp/cp; pad to that if the page rounding needs it.
    exact = (pages - 1) * 512 + (last if last else 512)
    if len(built) < exact:
        built += b"\x00" * (exact - len(built))
    return built


def split_exe(data: bytes) -> tuple[dict, bytes, bytes]:
    report = identify_mz(data)
    mz = report["mz"]
    image = data[mz["header_bytes"] : mz["image_size"]]
    tail = data[mz["image_size"] :]
    if report["kind"] != "mz":
        raise IdentifyError("not mz")
    return report, image, tail
