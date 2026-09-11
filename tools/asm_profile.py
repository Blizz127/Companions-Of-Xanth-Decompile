#!/usr/bin/env python3
"""Check whether an assembler has the encoding profile the retail code needs.

The 577 remaining dump units cannot be spelled with the pinned MSVC 1.52
assembler. Their bytes need an assembler that

1. renders `sub sp,2` as `81 EC 02 00` (the imm16 form) rather than
   `83 EC 02`;
2. renders `mov bp,sp` / `mov sp,bp` as `8B EC` / `8B E5` rather than the
   `89 E5` / `89 EC` form NASM, GNU `as` and `llvm-mc` choose;
3. assembles `push si` / `push di` literally, with no compiler-style
   save/restore wrapper;
4. keeps `retf` immediate operands and `jmp` forms as written.

That is the MASM 5.x-generation profile (`docs/STATUS.md`, fourth pass).
Point this at a candidate assembler and it reports which facts hold:

    python3 tools/asm_profile.py --cmd 'wine ML.EXE /c /nologo {src}' --obj
    python3 tools/asm_profile.py --cmd 'nasm -f bin -o {out} {src}'

`{src}` and `{out}` are substituted with the probe source and output paths.
The probe source is MASM syntax; an assembler that cannot assemble it is
reported as such rather than silently failing a fact.
"""

from __future__ import annotations

import argparse
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from omf import OmfError, ledata_and_fixups

_FACTS = [
    (
        "imm16 stack adjust",
        (
            "sub sp,2\n    retf",
            "sub sp, strict word 2\n    retf",
        ),
        bytes.fromhex("81 ec 02 00 cb"),
    ),
    (
        "MASM-style mov bp,sp / mov sp,bp",
        (
            "mov bp,sp\n    mov sp,bp",
            "mov bp,sp\n    mov sp,bp",
        ),
        bytes.fromhex("8b ec 8b e5"),
    ),
    (
        "literal push si/di, no wrapper",
        (
            "push si\n    push di\n    nop\n    pop di\n    pop si\n    retf",
            "push si\n    push di\n    nop\n    pop di\n    pop si\n    retf",
        ),
        bytes.fromhex("56 57 90 5f 5e cb"),
    ),
]

_HEADER = "_TEXT SEGMENT BYTE PUBLIC 'CODE'\n    ASSUME CS:_TEXT\n    PUBLIC probe\nprobe:\n    "


def _source(kind: str, body: str) -> str:
    if kind == "masm":
        return _HEADER + body + "\n_TEXT ENDS\n    END\n"
    return "bits 16\norg 0\n" + body + "\n"


def _code_of(path: Path, obj: bool) -> bytes:
    data = path.read_bytes()
    if obj:
        try:
            code, _fix = ledata_and_fixups(data)
            return code
        except OmfError as exc:
            raise SystemExit(f"asm_profile: cannot read OMF object: {exc}")
    return data


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cmd", required=True, help="assembler command template")
    parser.add_argument("--obj", action="store_true", help="the command writes an OMF object")
    parser.add_argument("--keep", action="store_true", help="print each assembled probe")
    parser.add_argument(
        "--syntax", choices=("masm", "nasm"), default="masm", help="probe source syntax"
    )
    args = parser.parse_args()

    held = failed = 0
    with tempfile.TemporaryDirectory(prefix="asm_profile_") as tmp:
        work = Path(tmp)
        for name, bodies, expected in _FACTS:
            body = bodies[0] if args.syntax == "masm" else bodies[1]
            src = work / "probe.asm"
            out = work / "probe.obj" if args.obj else work / "probe.bin"
            for stale in (work / "probe.obj", work / "probe.bin"):
                stale.unlink(missing_ok=True)
            src.write_text(_source(args.syntax, body), encoding="utf-8")
            command = args.cmd.replace("{src}", str(src)).replace("{out}", str(out))
            proc = subprocess.run(
                shlex.split(command), capture_output=True, text=True
            )
            if proc.returncode != 0 or not out.is_file():
                detail = (proc.stderr or proc.stdout).strip().splitlines()
                print(f"  {name:<34} ASSEMBLE-FAIL {detail[0] if detail else ''}")
                failed += 1
                continue
            got = _code_of(out, args.obj)
            if args.keep:
                print(f"    {name}: {got.hex(' ')}")
            if got == expected:
                print(f"  {name:<34} PASS")
                held += 1
            else:
                print(f"  {name:<34} FAIL got {got.hex(' ')} want {expected.hex(' ')}")
                failed += 1
    print(f"{held}/{len(_FACTS)} profile facts hold")
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
