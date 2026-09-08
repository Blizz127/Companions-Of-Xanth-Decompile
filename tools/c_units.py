"""Compile recovered C units with CL 8.00c and splice them into a listing image."""

from __future__ import annotations

import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from compile_msc import DEFAULT_FLAGS, compile_omf, toolchain_available
from retail_common import ROOT, RetailError, load_json


def load_units(root: Path | None = None) -> list[dict]:
    root = root or ROOT
    path = root / "config/c-units.json"
    if not path.is_file():
        return []
    data = load_json(path)
    return list(data.get("units") or [])


def _trim_nop(compiled: bytes, retail: bytes) -> bytes:
    cand = compiled
    while cand.endswith(b"\x90") and len(cand) > len(retail):
        cand = cand[:-1]
    return cand


def _relocate(compiled: bytes, fixups: list[tuple[int, int]], retail: bytes) -> bytes:
    while compiled.endswith(b"\x90"):
        compiled = compiled[:-1]
    fixups = [(offset, size) for offset, size in fixups if offset + size <= len(compiled)]
    if len(compiled) > len(retail):
        raise RetailError("compiled C unit is longer than the retail slice")
    retail_slice = retail[: len(compiled)]
    relocated = bytearray(compiled)
    covered: set[int] = set()
    for offset, size in fixups:
        if offset + size > len(relocated):
            continue
        relocated[offset : offset + size] = retail_slice[offset : offset + size]
        covered.update(range(offset, offset + size))
    for index, (got, want) in enumerate(zip(relocated, retail_slice)):
        if index not in covered and got != want:
            raise RetailError(
                f"compiled C unit differs from retail at +{index} (non-fixup byte)"
            )
    return bytes(relocated)


def splice_image(code: bytearray, image: str, *, root: Path | None = None) -> list[dict]:
    root = root or ROOT
    if not toolchain_available():
        raise RetailError("historical compiler missing: cannot splice C units")
    applied = []
    for unit in load_units(root):
        if unit.get("image") != image:
            continue
        offset = int(unit["offset"])
        source = root / unit["source"]
        compiled, fixups = compile_omf(source, flags=list(DEFAULT_FLAGS))
        if offset < 0 or offset >= len(code):
            raise RetailError(f"C unit offset {offset} outside image")
        matched = _relocate(compiled, fixups, bytes(code[offset : offset + len(compiled)]))
        code[offset : offset + len(matched)] = matched
        applied.append(
            {
                "source": unit["source"],
                "image": image,
                "offset": offset,
                "size": len(matched),
                "fixups": len(fixups),
                "compiler": "Microsoft C/C++ 8.00c",
            }
        )
    return applied


def splice_exe_code(code: bytearray, *, root: Path | None = None) -> list[dict]:
    return splice_image(code, "exe-code", root=root)
