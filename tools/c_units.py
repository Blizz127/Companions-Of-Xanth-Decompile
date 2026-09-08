"""Compile recovered C units with CL 8.00c and splice them into a listing image."""

from __future__ import annotations

import json
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from compile_msc import DEFAULT_FLAGS, compile_c, toolchain_available
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
    if len(cand) <= len(retail) and retail[: len(cand)] == cand:
        return cand
    if compiled == retail[: len(compiled)]:
        return compiled
    raise RetailError("compiled C unit does not match retail bytes at the recorded offset")


def splice_exe_code(code: bytearray, *, root: Path | None = None) -> list[dict]:
    root = root or ROOT
    if not toolchain_available():
        raise RetailError("historical compiler missing: cannot splice C units")
    applied = []
    for unit in load_units(root):
        if unit.get("image") != "exe-code":
            continue
        offset = int(unit["offset"])
        source = root / unit["source"]
        compiled = compile_c(source, flags=list(DEFAULT_FLAGS))
        if offset < 0 or offset >= len(code):
            raise RetailError(f"C unit offset {offset} outside EXE code")
        matched = _trim_nop(compiled, bytes(code[offset : offset + len(compiled)]))
        code[offset : offset + len(matched)] = matched
        applied.append(
            {
                "source": unit["source"],
                "offset": offset,
                "size": len(matched),
                "compiler": "Microsoft C/C++ 8.00c",
            }
        )
    return applied
