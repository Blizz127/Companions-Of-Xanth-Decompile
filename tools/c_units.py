"""Compile recovered C units with CL 8.00c and splice them into a listing image."""

from __future__ import annotations

import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from compile_msc import DEFAULT_FLAGS, compile_omf_many, toolchain_available
from retail_common import ROOT, RetailError, load_json
from wasm_backend import assemble_many, toolchain_available as wasm_available


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
    # `_asm` that already contains `retf`/`ret` still gets CL's extra
    # `mov sp,bp; pop bp; retf/ret`. Drop that whole trailer.
    for ret in (b"\xcb", b"\xc3"):
        extra = b"\x8b\xe5\x5d" + ret
        if compiled.endswith(ret + extra):
            compiled = compiled[: -len(extra)]
            break
    # Non-frame thunks: CL still prefixes `push bp; mov bp,sp`. Drop it
    # when retail at this offset is not a C frame, and shift OMF fixups.
    if compiled.startswith(b"\x55\x8b\xec") and (len(retail) < 3 or retail[:3] != b"\x55\x8b\xec"):
        stripped = compiled[3:]
        if len(stripped) <= len(retail) or compiled.endswith((b"\x8b\xe5\x5d\xcb", b"\x8b\xe5\x5d\xc3")):
            compiled = stripped
            fixups = [(offset - 3, size) for offset, size in fixups if offset >= 3]
    # Mid-function fragments have no ret; CL still appends a full epilogue.
    # Drop it when retail at the trimmed length is not itself `pop bp; ret`.
    for epi in (b"\x8b\xe5\x5d\xcb", b"\x8b\xe5\x5d\xc3"):
        if compiled.endswith(epi):
            cand = compiled[: -len(epi)]
            pos = len(cand)
            rest = retail[pos : pos + 4]
            if cand and pos <= len(retail) and not (
                rest.startswith(b"\x5d\xcb")
                or rest.startswith(b"\x5d\xc3")
                or rest.startswith(b"\x8b\xe5\x5d")
            ):
                compiled = cand
            break
    # CL 8.00c always emits `mov sp,bp` (`8b e5`) immediately before
    # `pop bp; retf/ret` on `_asm` units. Retail omits it when the frame is
    # already clean. Drop that redundant word only when retail's epilogue
    # at the trimmed length is already `5d cb`/`5d c3` without a preceding `8b e5`.
    for ret in (b"\x5d\xcb", b"\x5d\xc3"):
        if compiled.endswith(b"\x8b\xe5" + ret):
            stripped = compiled[:-4] + compiled[-2:]
            pos = len(stripped) - 2
            if (
                len(stripped) <= len(retail)
                and pos >= 0
                and retail[pos : pos + 2] == ret
                and (pos < 2 or retail[pos - 2 : pos] != b"\x8b\xe5")
            ):
                compiled = stripped
            break
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
    units = [unit for unit in load_units(root) if unit.get("image") == image]
    paths: list[Path] = []
    listings: list[Path] = []
    seen: set[Path] = set()
    for unit in units:
        path = (root / unit["source"]).resolve()
        if path in seen:
            continue
        seen.add(path)
        (listings if path.suffix == ".asm" else paths).append(path)
    if listings and not wasm_available():
        raise RetailError("Watcom assembler missing: cannot splice .asm units")
    compiled_map = compile_omf_many(paths, flags=list(DEFAULT_FLAGS)) if paths else {}
    compiled_map.update(assemble_many(listings))
    applied = []
    for unit in units:
        offset = int(unit["offset"])
        source = root / unit["source"]
        compiled, fixups = compiled_map[source.resolve()]
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
                "compiler": (
                    "Open Watcom WASM"
                    if source.suffix == ".asm"
                    else "Microsoft C/C++ 8.00c"
                ),
            }
        )
    return applied


def splice_exe_code(code: bytearray, *, root: Path | None = None) -> list[dict]:
    return splice_image(code, "exe-code", root=root)
