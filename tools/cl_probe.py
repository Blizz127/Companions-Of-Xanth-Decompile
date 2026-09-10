"""Compile a C snippet with CL 8.00c and print the resulting code.

This is the controlled experiment behind every "the compiler cannot emit
that" or "the retail spelling is X" claim in `docs/`. Lifting is mostly a
sequence of these: guess the original source spelling, compile, look.

    python3 tools/cl_probe.py --c 'void far f(int a){ g = a; }'
    python3 tools/cl_probe.py --file /tmp/try.c --flags /c /f- /AL /Gs /Os /Zl
    python3 tools/cl_probe.py --compare exe-code:0x1e9 --c 'void far f(int a){...}'
"""

from __future__ import annotations

import argparse
import sys
import tempfile
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

import units as unit_index
from compile_msc import DEFAULT_FLAGS, compile_omf_many
from listing import ndisasm
from retail_common import ROOT, RetailError


def disassemble(blob: bytes) -> str:
    lines = []
    for insn in ndisasm(blob):
        raw = " ".join(f"{byte:02X}" for byte in insn["raw"])
        lines.append(f"  {insn['addr']:04X}  {raw:<20} {insn['mnemonic']}")
    return "\n".join(lines)


def compare(compiled: bytes, retail: bytes, context: int) -> str:
    if retail[: len(compiled)] == compiled:
        return "EXACT MATCH"
    for index, (a, b) in enumerate(zip(compiled, retail)):
        if a != b:
            start = max(0, index - context)
            return "\n".join(
                [
                    f"first difference at +{index}: compiled {a:02X} vs retail {b:02X}",
                    "  compiled:",
                    disassemble(compiled[start : start + 48]),
                    "  retail:",
                    disassemble(retail[start : start + 48]),
                ]
            )
    return "\n".join(
        [
            f"length differs: compiled {len(compiled)} vs retail {len(retail)}",
            "  compiled:",
            disassemble(compiled),
        ]
    )


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--c", dest="source", help="C source text")
    parser.add_argument("--file", dest="source_files", type=Path, nargs="+", help="one or more C source files")
    parser.add_argument("--name", default="probe", help="translation unit stem")
    parser.add_argument("--flags", nargs="*", default=None, help="CL flags; default pipeline flags")
    parser.add_argument("--compare", help="image:offset to diff the result against")
    parser.add_argument("--context", type=int, default=12)
    args = parser.parse_args(argv)

    if not args.source and not args.source_files:
        parser.error("give --c or --file")
    flags = list(args.flags) if args.flags else list(DEFAULT_FLAGS)
    if args.source_files:
        texts = {path: path.read_text() for path in args.source_files}
    else:
        texts = {Path(f"{args.name}.c"): args.source}

    with tempfile.TemporaryDirectory(prefix="cl_probe_") as tmp:
        work = Path(tmp)
        local = {}
        for index, (path, text) in enumerate(texts.items()):
            stem = f"probe{index:02d}"
            target = work / f"{stem}.c"
            target.write_text(text, encoding="utf-8")
            local[target] = (path, text)
        try:
            objs = compile_omf_many(list(local))
        except RetailError as exc:
            print(f"cl_probe: ERROR: {exc}", file=sys.stderr)
            return 2
        results = []
        for target, (path, text) in local.items():
            entry = objs.get(target.resolve())
            if entry is None:
                results.append((path, b"", [], "COMPILE FAILED"))
                continue
            compiled, fixups = entry
            results.append((path, compiled, fixups, None))

    print(f"flags: {' '.join(flags)}")
    images = unit_index.image_bytes(ROOT)
    retail = None
    if args.compare:
        image_name, _, raw = args.compare.partition(":")
        if image_name not in images:
            print(f"cl_probe: ERROR: unknown image {image_name}", file=sys.stderr)
            return 2
        offset = int(raw, 0)
        retail = images[image_name][offset : offset + 96]
        print(f"retail @ {image_name}:{offset:#x}: {retail.hex()}")
    failures = 0
    for path, compiled, fixups, error in results:
        print(f"--- {path}")
        if error:
            print(f"  {error}")
            failures += 1
            continue
        print(f"  code ({len(compiled)} bytes, {len(fixups)} fixups): {compiled.hex()}")
        print(disassemble(compiled))
        if retail is not None:
            verdict = compare(compiled, retail, args.context)
            print(f"  {verdict}")
            if verdict != "EXACT MATCH":
                failures += 1
    return 1 if failures else 0
    if retail[: len(compiled)] == compiled:
        print("EXACT MATCH")
        return 0
    for index, (a, b) in enumerate(zip(compiled, retail)):
        if a != b:
            print(f"first difference at +{index}: compiled {a:02X} vs retail {b:02X}")
            start = max(0, index - args.context)
            print("  compiled:")
            print(disassemble(compiled[start : start + 48]))
            print("  retail:")
            print(disassemble(retail[start : start + 48]))
            break
    else:
        print(f"length differs: compiled {len(compiled)} vs retail available")
        print("  compiled:")
        print(disassemble(compiled))
        print("  retail:")
        print(disassemble(retail[:64]))
    return 1


if __name__ == "__main__":
    raise SystemExit(_main())
