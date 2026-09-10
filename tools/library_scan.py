"""Classify units that cannot be CL 8.00c-compiled C, and say why.

Two independent, provable categories:

1. **library** — the retail body's bytes appear in one of the 82 `.LIB` files
   shipped with the pinned toolchain. The linker pulled these routines out of
   the runtime; they were never C in this project.

2. **assembled** — the body contains `81 /n iw` with an immediate below 0x80.
   CL 8.00c always encodes a small immediate with the sign-extended 8-bit form
   (`83 /n ib`), from C *and* from inline `_asm`: `_asm { sub sp, 2 }` compiles
   to `83 EC 02`, verified by probe. Retail's `81 EC 02 00` therefore came from
   a MASM-built object, not from CL.

The library test uses a random control: a 24-byte probe over 14 MB of
libraries matches 0 times in 200 random trials, so a hit is evidence.

    python3 tools/library_scan.py                 # summary
    python3 tools/library_scan.py --json          # machine readable
    python3 tools/library_scan.py --probe 32      # stricter
"""

from __future__ import annotations

import argparse
import json
import random
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

import units as unit_index
from retail_common import ROOT

LIB_DIR = Path("tools/toolchain/msvc152/MSVC/LIB")
DEFAULT_PROBE = 24

# `81 /n iw`, mod = 11 (register operand) -> ModRM E0..FF, immediate < 0x80.
# CL would have used the 8-bit immediate form for every one of these.
CL_IMPOSSIBLE = [
    bytes([0x81, modrm, imm, 0x00]) for modrm in range(0xE0, 0x100) for imm in range(0x80)
]


def load_libraries(root: Path) -> dict[str, bytes]:
    directory = root / LIB_DIR
    if not directory.is_dir():
        raise SystemExit(f"library directory missing: {directory}")
    return {path.name: path.read_bytes() for path in sorted(directory.glob("*.LIB"))}


def control_rate(libraries: dict[str, bytes], size: int, *, trials: int = 200) -> int:
    """How often a random probe of this size hits the library corpus."""
    rng = random.Random(20260910)
    blobs = list(libraries.values())
    hits = 0
    for _ in range(trials):
        probe = bytes(rng.randrange(256) for _ in range(size))
        if any(probe in blob for blob in blobs):
            hits += 1
    return hits


def find_match(body: bytes, libraries: dict[str, bytes], size: int) -> tuple[str, int] | None:
    if len(body) < size:
        return None
    for start in range(0, len(body) - size + 1, 4):
        probe = body[start : start + size]
        for name, data in libraries.items():
            if probe in data:
                return name, start
    return None


def assembled_units(rows: list[dict], images: dict[str, bytes]) -> list[dict]:
    """Units containing an encoding CL 8.00c cannot emit, so MASM built them."""
    out = []
    for row in rows:
        if row["extent"] is None:
            continue
        blob = images[row["image"]][row["offset"] : row["offset"] + row["extent"]]
        for needle in CL_IMPOSSIBLE:
            if needle in blob:
                out.append(row)
                break
    return out


def scan(root: Path | None = None, *, probe: int = DEFAULT_PROBE) -> dict:
    root = root or ROOT
    libraries = load_libraries(root)
    images = unit_index.image_bytes(root)
    rows = unit_index.index(root)
    hits = []
    for row in rows:
        if row["extent"] is None:
            continue
        blob = images[row["image"]][row["offset"] : row["offset"] + row["extent"]]
        body = blob[3:-2] if row["shape"] == "function" else blob
        found = find_match(body, libraries, probe)
        if found:
            hits.append(
                {
                    "source": row["source"],
                    "image": row["image"],
                    "offset": row["offset"],
                    "extent": row["extent"],
                    "shape": row["shape"],
                    "kind": row["kind"],
                    "library": found[0],
                    "probe_at": found[1],
                }
            )
    by_library: dict[str, int] = {}
    for hit in hits:
        by_library[hit["library"]] = by_library.get(hit["library"], 0) + 1
    assembled = assembled_units(rows, images)
    library_sources = {hit["source"] for hit in hits}
    assembled_sources = {row["source"] for row in assembled}
    functions = [row for row in rows if row["shape"] == "function"]
    not_cl = library_sources | assembled_sources
    return {
        "probe_bytes": probe,
        "libraries": len(libraries),
        "library_bytes": sum(len(data) for data in libraries.values()),
        "control_hits": control_rate(libraries, probe),
        "units_scanned": len(rows),
        "units_matched": len(hits),
        "by_library": dict(sorted(by_library.items(), key=lambda item: -item[1])),
        "units": hits,
        "assembled_units": len(assembled_sources),
        "in_both_categories": len(library_sources & assembled_sources),
        "complete_functions": len(functions),
        "complete_functions_not_cl": len(
            {row["source"] for row in functions} & not_cl
        ),
        "assembled_samples": sorted(assembled_sources)[:10],
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--probe", type=int, default=DEFAULT_PROBE)
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args(argv)
    report = scan(probe=args.probe)
    if args.json:
        print(json.dumps(report, indent=2, sort_keys=True))
        return 0
    print(
        f"{report['units_matched']} of {report['units_scanned']} units match a shipped "
        f"library ({report['libraries']} libs, {report['library_bytes']} bytes)"
    )
    print(
        f"probe {report['probe_bytes']} bytes; control {report['control_hits']}/200 "
        "random probes matched"
    )
    for library, count in report["by_library"].items():
        print(f"  {library:<16} {count}")
    print(f"assembled (CL-impossible imm16 form): {report['assembled_units']} units")
    print(
        f"in both categories: {report['in_both_categories']}; "
        f"complete functions not CL-compiled: {report['complete_functions_not_cl']} "
        f"of {report['complete_functions']}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
