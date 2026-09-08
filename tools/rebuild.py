"""Rebuild XANTH.EXE and XANTH.OVL from recovered listing source and compare."""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from c_units import splice_exe_code, splice_image
from compare import compare_bytes
from identify import identify_ovl
from link_msc import compile_to_obj, link_objects, linker_available
from listing import ListingError, assemble, assemble_data
from mz import build_mz, parse_relocs, split_exe
from retail_common import ROOT, RetailError, load_target, verify_file


class RebuildError(RetailError):
    pass


def _pin(path: Path, pin: dict) -> bytes:
    verify_file(path, expected_size=pin["size"], expected_sha256=pin["sha256"])
    return path.read_bytes()


def rebuild_exe(original: bytes) -> tuple[bytes, dict]:
    report, code, tail = split_exe(original)
    mz = report["mz"]
    try:
        code_built, _ = assemble(code)
        tail_built, _ = assemble_data(tail)
    except ListingError as exc:
        raise RebuildError(f"listing rebuild failed: {exc}") from exc
    code_buf = bytearray(code_built)
    c_units = splice_exe_code(code_buf)
    linker = None
    if c_units and linker_available():
        from c_units import load_units

        objects = []
        for unit in load_units():
            if unit.get("image") != "exe-code":
                continue
            name = Path(unit["source"]).stem + ".obj"
            objects.append((name, compile_to_obj(ROOT / unit["source"])))
        if objects:
            linker = link_objects(objects)
    relocs = parse_relocs(original)
    rebuilt = build_mz(
        cs=mz["cs"],
        ip=mz["ip"],
        ss=mz["ss"],
        sp=mz["sp"],
        minalloc=mz["minalloc"],
        maxalloc=mz["maxalloc"],
        relocs=relocs,
        load_image=bytes(code_buf),
    )
    rebuilt += tail_built
    return rebuilt, {
        "code": compare_bytes(code, bytes(code_buf)),
        "tail": compare_bytes(tail, tail_built),
        "header_bytes": mz["header_bytes"],
        "c_units": c_units,
        "linker": linker,
    }


def rebuild_ovl(original: bytes) -> tuple[bytes, dict]:
    import struct

    report = identify_ovl(original)
    directory = bytearray()
    for entry in report["directory"]["entries"]:
        directory += struct.pack("<HH", entry["size"], entry["segment"])
    offset = report["directory"]["terminator_offset"]
    while offset + 4 <= len(original) and original[offset : offset + 4] == b"\x00\x00\xff\xff":
        directory += b"\x00\x00\xff\xff"
        offset += 4
    try:
        payload, _ = assemble(original[offset:])
    except ListingError as exc:
        raise RebuildError(f"overlay listing rebuild failed: {exc}") from exc
    payload_buf = bytearray(payload)
    c_units = splice_image(payload_buf, "ovl-payload")
    rebuilt = bytes(directory) + bytes(payload_buf)
    return rebuilt, {
        "directory": compare_bytes(original[:offset], bytes(directory)),
        "payload": compare_bytes(original[offset:], bytes(payload_buf)),
        "code_offset": offset,
        "c_units": c_units,
    }


def rebuild_and_compare(root: Path | None = None) -> dict:
    root = root or ROOT
    target = load_target(root)
    exe_path = root / target["executable"]["path"]
    ovl_path = root / target["overlay"]["path"]
    exe_orig = _pin(exe_path, target["executable"])
    ovl_orig = _pin(ovl_path, target["overlay"])
    exe_built, exe_parts = rebuild_exe(exe_orig)
    ovl_built, ovl_parts = rebuild_ovl(ovl_orig)
    exe_cmp = compare_bytes(exe_orig, exe_built)
    ovl_cmp = compare_bytes(ovl_orig, ovl_built)
    return {
        "compiler": "Microsoft C/C++ 8.00c",
        "executable": {
            **exe_cmp,
            "sha256": hashlib.sha256(exe_built).hexdigest(),
            "pin": target["executable"]["sha256"],
            "parts": exe_parts,
        },
        "overlay": {
            **ovl_cmp,
            "sha256": hashlib.sha256(ovl_built).hexdigest(),
            "pin": target["overlay"]["sha256"],
            "parts": ovl_parts,
        },
        "result": "BINARY-MATCH"
        if exe_cmp["result"] == "BINARY-MATCH" and ovl_cmp["result"] == "BINARY-MATCH"
        else "DIFF",
    }


if __name__ == "__main__":
    import json
    import sys

    try:
        report = rebuild_and_compare()
    except RetailError as exc:
        print(f"rebuild: ERROR: {exc}", file=sys.stderr)
        raise SystemExit(2)
    print(json.dumps(report, indent=2, sort_keys=True))
    raise SystemExit(0 if report["result"] == "BINARY-MATCH" else 1)
