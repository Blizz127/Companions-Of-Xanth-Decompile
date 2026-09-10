"""Classify recovered units as toolchain library code by byte-probing the libs.

A large part of the low region of `XANTH.EXE` is not game source: it is the
Microsoft C 8.00c startup and runtime routines that the linker pulled out of
the shipped `.LIB` files. Those units cannot be "recovered as C" because they
never were C in this project — a matching rebuild links the library instead.

The test is a byte probe of the retail body against every `.LIB` in the pinned
toolchain, with a random control so a match means something. A 24-byte probe
over 14 MB of libraries has a collision rate below the control threshold
(200 random probes match 0 times), so a hit is evidence, not coincidence.

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
    return {
        "probe_bytes": probe,
        "libraries": len(libraries),
        "library_bytes": sum(len(data) for data in libraries.values()),
        "control_hits": control_rate(libraries, probe),
        "units_scanned": len(rows),
        "units_matched": len(hits),
        "by_library": dict(sorted(by_library.items(), key=lambda item: -item[1])),
        "units": hits,
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
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
