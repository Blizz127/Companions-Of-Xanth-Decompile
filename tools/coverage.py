"""Report unaided-C coverage of the retail code images.

Two modes:

* default — wine-free. Unit counts and exact dump extents, resolved from the
  `_emit` stream against the retail bytes (see `units.py`).
* `--compile` — runs the real CL 8.00c splice so every unit, including the
  unaided-C ones, gets an exact verified retail extent. Slower, but it is the
  number that actually matters for "how much of the game is C".

The headline metric is `unaided_c_bytes / image_bytes`: distinct retail bytes
attributed to a unit whose source contains no `_asm`.
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
from c_units import splice_exe_code, splice_image
from compile_msc import toolchain_available
from retail_common import ROOT, RetailError

KIND_LABELS = {
    unit_index.KIND_C: "unaided-c",
    unit_index.KIND_ASM: "mnemonic-asm",
    unit_index.KIND_DATA: "transcribed-data",
    unit_index.KIND_DUMP: "emit-dump",
}

_ALL_KINDS = (
    unit_index.KIND_C,
    unit_index.KIND_ASM,
    unit_index.KIND_DATA,
    unit_index.KIND_DUMP,
)


def _compiled_extents(rows: list[dict], root: Path) -> dict[tuple[str, int], int]:
    """Retail extent of every unit, from the real splice."""
    images = unit_index.image_bytes(root)
    applied: dict[tuple[str, int], int] = {}
    exe_buf = bytearray(images["exe-code"])
    for item in splice_exe_code(exe_buf, root=root):
        applied[(item["image"], item["offset"])] = item["size"]
    ovl_buf = bytearray(images["ovl-payload"])
    for item in splice_image(ovl_buf, "ovl-payload", root=root):
        applied[(item["image"], item["offset"])] = item["size"]
    missing = [row for row in rows if (row["image"], row["offset"]) not in applied]
    if missing:
        first = missing[0]
        raise RetailError(
            f"{len(missing)} units were not spliced, first {first['source']} "
            f"at {first['image']}:{first['offset']:#x}"
        )
    return applied


def report(root: Path | None = None, *, compile_units: bool = False) -> dict:
    root = root or ROOT
    rows = unit_index.index(root)
    if compile_units:
        if not toolchain_available():
            raise RetailError("historical compiler missing: MSVC 8.00c under wine")
        applied = _compiled_extents(rows, root)
        for row in rows:
            row["extent"] = applied[(row["image"], row["offset"])]
            row["shape"] = unit_index.classify(
                unit_index.image_bytes(root)[row["image"]], row["offset"], row["extent"]
            )
    images = unit_index.image_bytes(root)
    sizes = {name: len(data) for name, data in images.items()}
    images_report = {}
    for name, size in sizes.items():
        selected = [row for row in rows if row["image"] == name]
        kinds = {kind: 0 for kind in _ALL_KINDS}
        for row in selected:
            kinds[row["kind"]] += 1
        by_kind = {
            KIND_LABELS[kind]: unit_index.covered_bytes(rows, name, size, kinds={kind})
            for kind in kinds
        }
        shapes: dict[str, int] = {}
        for row in selected:
            shapes[row["shape"]] = shapes.get(row["shape"], 0) + 1
        sized = [row for row in selected if row["extent"] is not None]
        images_report[name] = {
            "bytes": size,
            "units": len(selected),
            "sized_units": len(sized),
            "unsized_units": len(selected) - len(sized),
            "kinds": kinds,
            "shapes": shapes,
            "bytes_by_kind": by_kind,
            "unaided_c_percent": round(100 * by_kind["unaided-c"] / size, 2),
            "dump_percent": round(100 * by_kind["emit-dump"] / size, 2),
        }
    dump_functions = sum(
        1
        for row in rows
        if row["kind"] == unit_index.KIND_DUMP and row["shape"] == "function"
    )
    return {
        "compile_units": compile_units,
        "images": images_report,
        "totals": {
            "units": len(rows),
            "kinds": {
                KIND_LABELS[kind]: sum(1 for row in rows if row["kind"] == kind)
                for kind in _ALL_KINDS
            },
            "dump_functions": dump_functions,
        },
    }


def format_report(data: dict) -> str:
    lines = []
    for name, info in data["images"].items():
        lines.append(f"{name}: {info['bytes']} bytes, {info['units']} units")
        lines.append(
            "  kinds: "
            + ", ".join(f"{key}={value}" for key, value in info["kinds"].items())
        )
        lines.append(
            "  bytes by kind: "
            + ", ".join(f"{key}={value}" for key, value in info["bytes_by_kind"].items())
        )
        lines.append(
            f"  unaided C: {info['unaided_c_percent']}%   dump: {info['dump_percent']}%"
            + ("" if not info["unsized_units"] else f"   ({info['unsized_units']} unsized)")
        )
        lines.append(
            "  shapes: " + ", ".join(f"{key}={value}" for key, value in sorted(info["shapes"].items()))
        )
    totals = data["totals"]
    lines.append(f"total units: {totals['units']}")
    lines.append(
        "total kinds: " + ", ".join(f"{key}={value}" for key, value in totals["kinds"].items())
    )
    lines.append(f"dump functions still in dump form: {totals['dump_functions']}")
    return "\n".join(lines)


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compile", action="store_true", help="run the CL splice for exact extents")
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--list", choices=("function", "fragment", "framed-fragment", "unframed-function"))
    parser.add_argument("--image", choices=("exe-code", "ovl-payload"))
    parser.add_argument("--kind", choices=tuple(KIND_LABELS.values()))
    parser.add_argument("--limit", type=int, default=25)
    args = parser.parse_args(argv)
    try:
        if args.list:
            rows = unit_index.index()
            wanted = args.list
            label_of = {value: key for key, value in KIND_LABELS.items()}
            for row in rows:
                if row["shape"] != wanted:
                    continue
                if args.image and row["image"] != args.image:
                    continue
                if args.kind and row["kind"] != label_of[args.kind]:
                    continue
                print(
                    f"{row['source']:<32} {row['image']:<12} {row['offset']:#08x} "
                    f"extent={row['extent']} kind={KIND_LABELS[row['kind']]}"
                )
            return 0
        data = report(compile_units=args.compile)
    except RetailError as exc:
        print(f"coverage: ERROR: {exc}", file=sys.stderr)
        return 2
    if args.json:
        print(json.dumps(data, indent=2, sort_keys=True))
    else:
        print(format_report(data))
    return 0


if __name__ == "__main__":
    raise SystemExit(_main())
