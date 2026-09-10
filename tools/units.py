"""Index the recovered-unit corpus: retail extents, shapes, and source kind.

The corpus in `config/c-units.json` is a flat list of `{image, offset, source}`.
Most of those sources are still `_asm { _emit ... }` byte dumps that were
generated *from* the retail slice, so their retail extent can be recovered
without running the compiler: rebuild the literal byte stream from the source
and lay it out against the retail image exactly the way `c_units._relocate`
lays out compiled output.

That makes coverage and shape reporting cheap and exact for dump units.
Units that no longer contain `_emit` cannot be sized without compiling; they
are reported with `extent=None` and kind `c` / `asm`.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path
from typing import Iterable

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from c_units import load_units
from identify import identify_ovl
from mz import split_exe
from retail_common import ROOT, RetailError, load_target

KIND_DUMP = "dump"  # `_asm { _emit ... }` byte dump
KIND_ASM = "asm"  # `_asm` with real mnemonics, no `_emit`
KIND_C = "c"  # no `_asm` at all

PROLOGUE = b"\x55\x8b\xec"
EPILOGUES = (b"\x8b\xe5\x5d\xcb", b"\x8b\xe5\x5d\xc3", b"\x5d\xcb", b"\x5d\xc3")
_RET = (b"\x5d\xcb", b"\x5d\xc3", b"\x8b\xe5\x5d")

_TOKEN = re.compile(r"_emit\s+0x([0-9A-Fa-f]{2})|call\s+far\s+ptr\s+([A-Za-z_]\w*)")
_ASM_BLOCK = re.compile(r"_asm\s*\{", re.S)


class UnitError(RetailError):
    """A unit cannot be laid out against the retail image."""


def image_bytes(root: Path | None = None) -> dict[str, bytes]:
    """Retail bytes for each spliced image, keyed by `c-units.json` image name."""
    root = root or ROOT
    target = load_target(root)
    exe = (root / target["executable"]["path"]).read_bytes()
    ovl = (root / target["overlay"]["path"]).read_bytes()
    _, code, _ = split_exe(exe)
    directory = identify_ovl(ovl)
    offset = directory["directory"]["terminator_offset"]
    while offset + 4 <= len(ovl) and ovl[offset : offset + 4] == b"\x00\x00\xff\xff":
        offset += 4
    return {"exe-code": code, "ovl-payload": ovl[offset:]}


def asm_body(text: str) -> str | None:
    """Return the first `_asm { ... }` body, or None when there is no block."""
    match = _ASM_BLOCK.search(text)
    if match is None:
        return None
    depth = 1
    index = match.end()
    while index < len(text) and depth:
        if text[index] == "{":
            depth += 1
        elif text[index] == "}":
            depth -= 1
        index += 1
    return text[match.end() : index - 1]


def source_kind(text: str) -> str:
    if "_emit" in text:
        return KIND_DUMP
    if "_asm" in text:
        return KIND_ASM
    return KIND_C


def dump_pattern(text: str) -> list[bytes | None] | None:
    """Bytes encoded by a dump source; `None` marks an OMF fixup slot.

    Returns None when the source is not a pure `_emit`/`call far ptr` dump.
    """
    body = asm_body(text)
    if body is None:
        return None
    pattern: list[bytes | None] = []
    cursor = 0
    while cursor < len(body):
        match = _TOKEN.search(body, cursor)
        if match is None:
            break
        cursor = match.end()
        if match.group(1) is not None:
            pattern.append(bytes.fromhex(match.group(1)))
        else:
            pattern.append(None)
    if not pattern:
        return None
    stripped = _TOKEN.sub("", body)
    if re.search(r"[A-Za-z0-9_]", stripped):
        # Real mnemonics mixed with `_emit`; not a pure byte dump.
        return None
    return pattern


def pattern_length(pattern: list[bytes | None]) -> int:
    """Encoded byte length; every far-call placeholder is a 5-byte `9A` call."""
    return sum(1 if part is not None else 5 for part in pattern)


def _matches(pattern: list[bytes | None], retail: bytes) -> bool:
    """Compare a dump pattern to retail, treating each placeholder as a wildcard."""
    if len(retail) != pattern_length(pattern):
        return False
    position = 0
    for want in pattern:
        span = 1 if want is not None else 5
        if want is not None and retail[position] != want[0]:
            return False
        position += span
    return True


def resolve_extent(text: str, image: bytes, offset: int) -> tuple[int, str] | None:
    """Retail extent of a dump unit, mirroring `c_units._relocate` trimming.

    Returns (extent, layout) or None when the source is not a resolvable dump.
    """
    pattern = dump_pattern(text)
    if pattern is None:
        return None
    length = pattern_length(pattern)
    framed = image[offset : offset + 3] == PROLOGUE
    prefix = 3 if framed else 0
    if not _matches(pattern, image[offset + prefix : offset + prefix + length]):
        return None
    if framed:
        # CL keeps its epilogue when retail already has a `pop bp; ret*` there;
        # `8b e5` survives only when retail spells it out too.
        for epilogue in EPILOGUES:
            tail = image[offset + prefix + length :][: len(epilogue)]
            if tail == epilogue:
                return prefix + length + len(epilogue), "framed"
        return prefix + length, "framed-split"
    # CL strips its own prologue; the epilogue survives only when retail
    # already resumes on a `pop bp; ret*` there.
    pos = length
    rest = image[offset + pos : offset + pos + 4]
    if rest.startswith(_RET):
        for epilogue in EPILOGUES:
            tail = image[offset + pos :][: len(epilogue)]
            if tail == epilogue:
                return pos + len(epilogue), "unframed-keep"
    return pos, "unframed"


def classify(image: bytes, offset: int, extent: int | None) -> str:
    """Shape of a unit, from its retail bytes."""
    if extent is None:
        return "unknown"
    window = image[offset : offset + extent]
    framed = window[:3] == PROLOGUE
    ends = window[-2:] in (b"\x5d\xcb", b"\x5d\xc3")
    if framed and ends:
        return "function"
    if framed:
        return "framed-fragment"
    if ends:
        return "unframed-function"
    return "fragment"


def index(root: Path | None = None) -> list[dict]:
    """Every unit with its resolved kind, extent, and shape."""
    root = root or ROOT
    images = image_bytes(root)
    rows: list[dict] = []
    for unit in load_units(root):
        image = images.get(unit.get("image"))
        if image is None:
            raise UnitError(f"unknown image in c-units.json: {unit.get('image')}")
        source = root / unit["source"]
        text = source.read_text(encoding="utf-8", errors="replace")
        kind = source_kind(text)
        resolved = resolve_extent(text, image, int(unit["offset"])) if kind == KIND_DUMP else None
        extent = resolved[0] if resolved else None
        rows.append(
            {
                "source": unit["source"],
                "image": unit["image"],
                "offset": int(unit["offset"]),
                "kind": kind,
                "extent": extent,
                "layout": resolved[1] if resolved else None,
                "shape": classify(image, int(unit["offset"]), extent),
            }
        )
    rows.sort(key=lambda row: (row["image"], row["offset"]))
    return rows


def covered_bytes(
    rows: Iterable[dict], image: str, size: int, *, kinds: set[str] | None = None
) -> int:
    """Distinct retail bytes of `image` attributed to units of the given kinds."""
    bitmap = bytearray(size)
    for row in rows:
        if row["image"] != image or row["extent"] is None:
            continue
        if kinds is not None and row["kind"] not in kinds:
            continue
        start = row["offset"]
        end = min(start + row["extent"], size)
        for position in range(start, end):
            bitmap[position] = 1
    return sum(bitmap)
