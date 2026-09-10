"""Compile one candidate translation unit and byte-diff it against retail.

This is the lifting loop. `c_units.splice_image` already fails closed, but it
fails with one line and no context, which is why iterating on a function by
hand is slow. `lift.py` shows:

* the retail disassembly of the unit (the input to writing C)
* the compiled disassembly on both sides of the first difference
* whether the match needed `_relocate` trimming or OMF fixups, so an
  accidental match on a stripped frame is never mistaken for a real one

Usage:

    python3 tools/lift.py --show src/exe_1802.c
    python3 tools/lift.py src/exe_1802.c
    python3 tools/lift.py --candidate /tmp/candidate.c src/exe_1802.c
    python3 tools/lift.py --candidate /tmp/candidate.c --register src/new_thing.c
"""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

import units as unit_index
from c_units import _relocate, load_units
from compile_msc import compile_omf, toolchain_available
from listing import ndisasm
from retail_common import ROOT, RetailError, write_json_atomic

_UNITS_PATH = Path("config/c-units.json")


def find_units(selector: str, root: Path) -> list[dict]:
    """Units whose source path or stem matches `selector`."""
    selector = selector.strip()
    prefix = ROOT
    matches = []
    for unit in load_units(root):
        source = unit["source"]
        if selector in (source, Path(source).name, Path(source).stem, str(Path(source).resolve())):
            matches.append(unit)
    if not matches:
        raise RetailError(f"no c-unit matches {selector!r} in {_UNITS_PATH}")
    return matches


def describe(blob: bytes) -> str:
    lines = []
    for insn in ndisasm(blob):
        raw = " ".join(f"{byte:02X}" for byte in insn["raw"])
        lines.append(f"  {insn['addr']:04X}  {raw:<20} {insn['mnemonic']}")
    return "\n".join(lines)


def first_difference(left: bytes, right: bytes) -> int | None:
    for index, (a, b) in enumerate(zip(left, right)):
        if a != b:
            return index
    if len(left) != len(right):
        return min(len(left), len(right))
    return None


def check_compiled(
    unit: dict, compiled: bytes, fixups: list[tuple[int, int]], images: dict[str, bytes]
) -> dict:
    image = images[unit["image"]]
    offset = int(unit["offset"])
    retail = image[offset : offset + len(compiled)]
    if len(retail) < len(compiled):
        return {
            "source": unit["source"],
            "image": unit["image"],
            "offset": offset,
            "compiled_size": len(compiled),
            "fixups": len(fixups),
            "exact_no_trims": False,
            "result": "OVERFLOW",
            "detail": f"compiled {len(compiled)} bytes past the end of {unit['image']}",
        }
    stripped = None
    try:
        matched = _relocate(compiled, list(fixups), retail)
    except RetailError as exc:
        matched = None
        stripped = str(exc)
    result = {
        "source": unit["source"],
        "image": unit["image"],
        "offset": offset,
        "compiled_size": len(compiled),
        "fixups": len(fixups),
        "exact_no_trims": compiled == retail,
    }
    if matched is None:
        index = first_difference(compiled, retail)
        result.update(
            {
                "result": "DIFF",
                "difference_at": index,
                "detail": stripped,
                "retail": retail[: len(compiled)],
                "compiled": compiled,
            }
        )
    else:
        trims = len(compiled) - len(matched)
        result.update(
            {
                "result": "MATCH",
                "matched_size": len(matched),
                "trimmed_bytes": trims,
                "retail": retail,
                "compiled": compiled,
            }
        )
    return result


def register(unit: dict, source: Path, root: Path) -> None:
    path = root / _UNITS_PATH
    data = json.loads(path.read_text())
    entry = {
        "image": unit["image"],
        "offset": unit["offset"],
        "source": source.as_posix() if not source.is_absolute() else str(source.relative_to(root)),
    }
    units = [item for item in data["units"] if not (item["image"] == entry["image"] and item["offset"] == entry["offset"])]
    units.append(entry)
    units.sort(key=lambda item: (item["image"], int(item["offset"])))
    data["units"] = units
    write_json_atomic(path, data)


def summary_line(result: dict) -> str:
    head = f"{result['source']:<34} {result['image']}:{result['offset']:#08x} {result['result']}"
    if result["result"] == "MATCH":
        extra = "" if result["exact_no_trims"] else f" (trimmed {result['trimmed_bytes']})"
        return head + f" size={result['matched_size']}{extra}"
    if result["result"] == "DIFF":
        return head + f" +{result.get('difference_at')} {result.get('detail', '')[:70]}"
    return head + f" {result.get('detail', '')[:70]}"


def render(result: dict, context: int) -> str:
    lines = [f"{result['source']} {result['image']}:{result['offset']:#x} -> {result['result']}"]
    lines.append(
        f"  compiled {result['compiled_size']} bytes, {result['fixups']} fixups, "
        f"exact={result['exact_no_trims']}"
    )
    if result["result"] == "MATCH":
        lines.append(f"  matched {result['matched_size']} bytes, trimmed {result['trimmed_bytes']}")
        if result["trimmed_bytes"]:
            lines.append("  NOTE: matched only after trimming; not a strict byte match")
        return "\n".join(lines)
    index = result.get("difference_at")
    lines.append(f"  first difference at +{index}: {result.get('detail')}")
    start = max(0, (index or 0) - context)
    lines.append("  retail:")
    lines.append(describe(result["retail"][start : start + 48]))
    lines.append("  compiled:")
    lines.append(describe(result["compiled"][start : start + 48]))
    return "\n".join(lines)


def run_batch(paths: list[str], images: dict[str, bytes], root: Path, context: int) -> int:
    """Compile every listed unit source in one CL batch and report each."""
    from compile_msc import compile_omf_many

    selected: list[tuple[dict, Path]] = []
    for path in paths:
        for unit in find_units(path, root):
            selected.append((unit, (root / unit["source"]).resolve()))
    if not selected:
        raise RetailError("no units selected")
    compiled_map = compile_omf_many([path for _, path in selected])
    results = []
    for unit, path in selected:
        entry = compiled_map.get(path)
        if entry is None:
            results.append(
                {
                    "source": unit["source"],
                    "image": unit["image"],
                    "offset": int(unit["offset"]),
                    "compiled_size": 0,
                    "fixups": 0,
                    "exact_no_trims": False,
                    "result": "COMPILE-FAIL",
                    "detail": "CL produced no object",
                }
            )
            continue
        compiled, fixups = entry
        results.append(check_compiled(unit, compiled, fixups, images))
    for result in results:
        print(summary_line(result))
    failures = [result for result in results if result["result"] != "MATCH"]
    if failures:
        print()
        for result in failures:
            print(render(result, context))
            print()
    matched = len(results) - len(failures)
    print(f"{matched}/{len(results)} MATCH")
    return 0 if not failures else 1


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("unit", nargs="*", help="source path or stem of an existing c-unit")
    parser.add_argument("--source", help="image:offset selector, e.g. exe-code:0x70a")
    parser.add_argument("--candidate", type=Path, help="C file to test instead of the unit's own source")
    parser.add_argument("--show", action="store_true", help="print the retail disassembly and stop")
    parser.add_argument("--context", type=int, default=16, help="instructions of context around a diff")
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--register", action="store_true", help="record the candidate as the unit's source on a MATCH")
    args = parser.parse_args(argv)

    root = ROOT
    images = unit_index.image_bytes(root)
    if not toolchain_available():
        print("lift: ERROR: historical compiler missing: MSVC 8.00c under wine", file=sys.stderr)
        return 2

    try:
        if len(args.unit) > 1:
            if args.show:
                parser.error("--show takes a single unit")
            return run_batch(args.unit, images, root, args.context)
        if args.source:
            image, _, raw = args.source.partition(":")
            unit = {"image": image, "offset": int(raw, 0), "source": args.unit[0] if args.unit else ""}
        else:
            if not args.unit:
                parser.error("give a unit source, or --source image:offset")
            unit = find_units(args.unit[0], root)[0]
    except RetailError as exc:
        print(f"lift: ERROR: {exc}", file=sys.stderr)
        return 2
    image = images[unit["image"]]
    offset = int(unit["offset"])

    if args.show:
        text = (root / unit["source"]).read_text(errors="replace") if unit["source"] else ""
        extent = None
        if text:
            resolved = unit_index.resolve_extent(text, image, offset)
            extent = resolved[0] if resolved else None
        if extent is None:
            blob = image[offset : offset + 64]
            print(f"{unit['image']}:{offset:#x} (extent unknown; showing 64 bytes)")
            print(f"bytes: {blob.hex()}")
            print(describe(blob))
            return 0
        blob = image[offset : offset + extent]
        print(f"{unit['source']} {unit['image']}:{offset:#x} extent={extent}")
        print(f"bytes: {blob.hex()}")
        print(describe(blob))
        return 0

    candidate = args.candidate or (root / unit["source"])
    if not candidate.is_file():
        print(f"lift: ERROR: candidate not found: {candidate}", file=sys.stderr)
        return 2
    try:
        compiled, fixups = compile_omf(candidate, flags=None)
    except RetailError as exc:
        print(f"lift: ERROR: {exc}", file=sys.stderr)
        return 2
    if not compiled:
        print(f"lift: ERROR: CL produced no code for {candidate}", file=sys.stderr)
        return 2
    result = check_compiled(unit, compiled, fixups, images)
    if args.json:
        payload = {key: value for key, value in result.items() if key not in ("retail", "compiled")}
        print(json.dumps(payload, indent=2, sort_keys=True))
    else:
        print(render(result, args.context))
    if result["result"] == "MATCH" and args.register:
        register(unit, candidate, root)
        print(f"registered {candidate} for {unit['image']}:{offset:#x}")
    return 0 if result["result"] == "MATCH" else 1


if __name__ == "__main__":
    raise SystemExit(_main())
