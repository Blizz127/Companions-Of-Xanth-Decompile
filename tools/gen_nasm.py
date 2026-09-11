#!/usr/bin/env python3
"""Re-emit a dump unit as a NASM mnemonic listing, round-tripped byte-exact.

The pinned MSVC 1.52 assembler cannot spell some of the retail code: its
inline-asm path always wraps a block that mentions SI/DI in its own
save/restore pair, and it renders `sub sp,N` as `83 EC imm8` while the retail
frame is the imm16 form. A real assembler has neither behaviour, and the
project already rebuilds the whole image through NASM (`tools/listing.py`),
so a unit the historical toolchain provably cannot spell can still be
recovered as mnemonics:

* `sub sp, strict word N` / `add sp, strict word N` for the imm16 frame;
* `jmp short $+N` vs `jmp near $+N` per the retail opcode;
* everything else is the plain mnemonic, with the unit's own image offset as
  the assembly origin so absolute operands stay literal.

The listing is only accepted when NASM reproduces the unit's retail slice
byte for byte with no `db` fallback. A unit that needs a byte directive is
reported, not written.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

import units as unit_index
from listing import ndisasm
from retail_common import ROOT, RetailError

_JUMP = re.compile(r"^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$")
_INT = re.compile(r"\bint\s+byte\s+")
_SEG_OPEN = re.compile(r"\[(cs|es|ss|ds):")
_SEG_LOAD = re.compile(r"\b(mov)\s+(es|ds|ss|cs)\s*,\s*(?:word|byte|dword)\s+")
_PTR_LOAD = re.compile(r"\b(les|lds)\s+(\w+)\s*,\s*(?:word|byte|dword)\s+")
_FAR_CALL = re.compile(r"\bcall\s+word\s+far\s+")
_FAR_DIRECT = re.compile(r"\bcall\s+word\s+(0x[0-9a-f]+):word\s+(0x[0-9a-f]+)")
_RET_IMM = re.compile(r"\b(retf?)\s+word\s+(0x[0-9a-f]+)$")
_IMM16 = re.compile(r"\b(0x[0-9a-f]{3,4})\b")


class NasmError(RetailError):
    pass


def _assemble(source: str, size: int) -> bytes:
    with tempfile.TemporaryDirectory(prefix="nasm_unit_") as tmp:
        asm = Path(tmp) / "u.asm"
        out = Path(tmp) / "u.bin"
        asm.write_text(source, encoding="utf-8")
        proc = subprocess.run(
            ["nasm", "-f", "bin", "-o", str(out), str(asm)],
            capture_output=True,
            text=True,
        )
        if proc.returncode != 0 or not out.is_file():
            raise NasmError(proc.stderr.strip().splitlines()[0] if proc.stderr else "nasm failed")
        return out.read_bytes()


def _plain(mnemonic: str, addr: int) -> str:
    text = _INT.sub("int ", mnemonic)
    text = _SEG_OPEN.sub(r"\1:[", text)
    text = _SEG_LOAD.sub(r"\1 \2, ", text)
    text = _PTR_LOAD.sub(r"\1 \2, ", text)
    text = _FAR_CALL.sub("call far ", text)
    text = _FAR_DIRECT.sub(r"call \1:\2", text)
    text = _RET_IMM.sub(r"\1 \2", text)
    return text


def _variant(mnemonic: str, addr: int, raw: bytes) -> str:
    """A spelling that forces the encoding the retail bytes actually use."""
    text = mnemonic
    if raw[:2] in (b"\x81\xec", b"\x81\xc4"):
        op = "sub" if raw[:2] == b"\x81\xec" else "add"
        return f"{op} sp, strict word 0x{int.from_bytes(raw[2:4], 'little'):x}"
    match = _JUMP.match(mnemonic)
    if match:
        target = int(match.group(2), 16)
        delta = target - addr
        offset = f"$+{delta}" if delta >= 0 else f"$-{-delta}"
        name = match.group(1)
        if name == "jmp":
            name = "jmp short" if raw[:1] == b"\xeb" else "jmp near"
        return f"{name} {offset}"
    if raw[:1] in (b"\x81", b"\x83") and len(raw) >= 3:
        # An arithmetic instruction with an immediate: force the operand size
        # the retail bytes use (imm16 vs sign-extended imm8).
        size = "word" if raw[0] == 0x81 else "byte"
        return _strict_immediate(mnemonic, size)
    return text


def _strict_immediate(mnemonic: str, size: str) -> str:
    parts = mnemonic.split(None, 1)
    if len(parts) != 2:
        return mnemonic
    opcode, rest = parts
    operands = rest.rsplit(",", 1)
    if len(operands) != 2 or not operands[1].strip().startswith("0x"):
        return mnemonic
    return f"{opcode} {operands[0]}, strict {size} {operands[1].strip()}"


def bytes_for(unit: dict, root: Path) -> bytes:
    """The unit's retail slice.

    A resolved dump gives its extent directly. A mixed unit (mnemonics plus a
    few `_emit` bytes) has no resolved extent, so its length comes from the
    real splice: compile it and let `_relocate` trim the compiler's frame.
    """
    image = unit_index.image_bytes(root)[unit["image"]]
    offset = int(unit["offset"])
    extent = unit["extent"]
    if extent:
        return image[offset : offset + extent]
    from c_units import _relocate
    from compile_msc import compile_omf

    compiled, fixups = compile_omf(root / unit["source"])
    matched = _relocate(compiled, fixups, bytes(image[offset:]))
    return image[offset : offset + len(matched)]


def convert(unit: dict, root: Path | None = None) -> str:
    root = root or ROOT
    blob = bytes_for(unit, root)
    if not blob:
        raise NasmError("unit has no resolved bytes")
    insns = ndisasm(blob)
    # Start from the forced spellings; fall back to the plain mnemonic only
    # where the forced form does not assemble.
    lines = []
    for insn in insns:
        if insn["mnemonic"].startswith("db "):
            raise NasmError(f"undecodable byte at {insn['addr']:#x}")
        lines.append("    " + _variant(insn["mnemonic"], insn["addr"], insn["raw"]))
    source = "bits 16\norg 0\n" + "\n".join(lines) + "\n"
    try:
        got = _assemble(source, len(blob))
        if got == blob:
            return source
    except NasmError:
        pass

    # Iterate: find the first instruction whose bytes differ and swap it back
    # to the plain spelling or to a per-operand `strict` form.
    for _ in range(64):
        try:
            got = _assemble(source, len(blob))
        except NasmError as exc:
            raise NasmError(str(exc)) from exc
        if got == blob:
            return source
        position = 0
        changed = False
        for index, insn in enumerate(insns):
            raw = insn["raw"]
            if got[position : position + len(raw)] != raw and not changed:
                plain = _plain(insn["mnemonic"], insn["addr"])
                strict = _strict_immediate(_plain(insn["mnemonic"], insn["addr"]), "word")
                current = lines[index].strip()
                for candidate in (plain, strict, _variant(insn["mnemonic"], insn["addr"], raw)):
                    lines[index] = "    " + candidate
                    try:
                        probe = _assemble(
                            "bits 16\norg 0\n" + "\n".join(lines) + "\n",
                            len(blob),
                        )
                    except NasmError:
                        continue
                    if probe[position : position + len(raw)] == raw:
                        changed = True
                        break
                else:
                    lines[index] = "    " + current
                    raise NasmError(f"cannot spell {insn['mnemonic']} at {insn['addr']:#x}")
            position += len(raw)
        source = "bits 16\norg 0\n" + "\n".join(lines) + "\n"
        if not changed:
            raise NasmError("listing does not round-trip")
    raise NasmError("no stable spelling found")


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("units", nargs="+")
    parser.add_argument("--write", action="store_true", help="write <stem>.asm next to the unit")
    args = parser.parse_args(argv)
    root = ROOT
    rows = unit_index.index(root)
    ok = failed = 0
    for selector in args.units:
        for unit in rows:
            if selector not in (unit["source"], Path(unit["source"]).stem, Path(unit["source"]).name):
                continue
            try:
                source = convert(unit, root)
            except (NasmError, RetailError) as exc:
                print(f"{unit['source']:<30} FAIL {exc}")
                failed += 1
                continue
            ok += 1
            if args.write:
                target = Path(unit["source"]).with_suffix(".asm")
                (root / target).write_text(source, encoding="utf-8")
                print(f"{unit['source']:<30} -> {target}")
            else:
                print(f"{unit['source']:<30} OK ({len(source.splitlines())} lines)")
    print(f"{ok} converted, {failed} failed")
    return 0 if failed == 0 else 1


if __name__ == "__main__":
    raise SystemExit(_main())
