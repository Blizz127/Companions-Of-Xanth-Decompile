"""Deterministic MZ / Legend overlay identity. Never infer a SKU from a filename."""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


class IdentifyError(ValueError):
    """The buffer is not the expected executable or overlay shape."""


def _hashes(data: bytes) -> dict:
    return {
        "sha256": hashlib.sha256(data).hexdigest(),
        "sha1": hashlib.sha1(data).hexdigest(),
        "size": len(data),
    }


def identify_mz(data: bytes) -> dict:
    if len(data) < 0x1E or data[:2] != b"MZ":
        raise IdentifyError("not an MZ executable")
    (
        cblp,
        cp,
        crlc,
        cparhdr,
        minalloc,
        maxalloc,
        ss,
        sp,
        csum,
        ip,
        cs,
        lfarlc,
        ovno,
    ) = struct.unpack_from("<HHHHHHHHHHHHH", data, 2)
    if cp == 0:
        raise IdentifyError("MZ page count is zero")
    header_bytes = cparhdr * 16
    image_size = (cp - 1) * 512 + (cblp if cblp else 512)
    if header_bytes > image_size or image_size > len(data):
        raise IdentifyError("MZ image size is inconsistent with the file")
    reloc_end = lfarlc + crlc * 4
    if lfarlc < 0x1C or reloc_end > len(data):
        raise IdentifyError("MZ relocation table is outside the file")
    tail = data[image_size:]
    return {
        "schema_version": 1,
        "kind": "mz",
        **_hashes(data),
        "mz": {
            "cblp": cblp,
            "cp": cp,
            "reloc_count": crlc,
            "header_paragraphs": cparhdr,
            "header_bytes": header_bytes,
            "minalloc": minalloc,
            "maxalloc": maxalloc,
            "ss": ss,
            "sp": sp,
            "csum": csum,
            "ip": ip,
            "cs": cs,
            "reloc_offset": lfarlc,
            "overlay_number": ovno,
            "image_size": image_size,
            "tail_size": len(tail),
        },
        "tail_sha256": hashlib.sha256(tail).hexdigest(),
        "strings": {
            "microsoft_crt_1992": b"MS Run-Time Library - Copyright (c) 1992, Microsoft Corp" in data,
            "overlay_manager": b"Cannot find overlay" in data or b"Overlay Manager" in data,
            "xanth_ovl": b"XANTH.OVL" in data,
            "pkware_dcl": b"PKWARE" in data,
            "legend_entertainment": b"Legend Entertainment" in data,
        },
    }


def identify_ovl(data: bytes) -> dict:
    if len(data) < 8:
        raise IdentifyError("overlay buffer is too short")
    if data[:2] == b"MZ":
        raise IdentifyError("overlay is MZ; expected the Legend .OVL payload")
    entries = []
    offset = 0
    terminator_offset = None
    while offset + 4 <= len(data):
        size, segment = struct.unpack_from("<HH", data, offset)
        if segment == 0xFFFF:
            terminator_offset = offset
            break
        entries.append({"offset": offset, "size": size, "segment": segment})
        offset += 4
    if terminator_offset is None:
        raise IdentifyError("overlay directory has no 0xFFFF terminator")
    segments = {entry["segment"] for entry in entries}
    credits = data.find(b"Copyright (c) 1994 Legend Entertainment Company")
    return {
        "schema_version": 1,
        "kind": "legend-ovl",
        "is_mz": False,
        **_hashes(data),
        "directory": {
            "entry_count": len(entries),
            "load_segment": next(iter(segments)) if len(segments) == 1 else None,
            "segments": sorted(segments),
            "terminator_offset": terminator_offset,
            "entries": entries,
        },
        "credits_offset": credits if credits >= 0 else None,
        "strings": {
            "legend_copyright_1994": credits >= 0,
        },
    }


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("path", type=Path)
    parser.add_argument("--kind", choices=("mz", "ovl", "auto"), default="auto")
    args = parser.parse_args(argv)
    data = args.path.read_bytes()
    kind = args.kind
    if kind == "auto":
        kind = "mz" if data[:2] == b"MZ" else "ovl"
    report = identify_mz(data) if kind == "mz" else identify_ovl(data)
    print(json.dumps(report, indent=2, sort_keys=True))
    return 0


if __name__ == "__main__":
    raise SystemExit(_main())
