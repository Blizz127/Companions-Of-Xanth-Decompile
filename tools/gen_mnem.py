#!/usr/bin/env python3
"""Re-emit a dump unit as mnemonic `_asm`, preserving the exact instruction bytes.

The recovered-source bar (`CONSTRAINTS.md`) forbids `_emit` byte dumps in
`src/**` but accepts `_asm` written in mnemonics. This tool turns one unit's
instruction stream into mnemonics:

* relative jumps become labelled mnemonics (`jmp short L..`, `jz L..`);
* far calls (`9A`, an OMF fixup) stay `call far ptr helperN`;
* a direct DS-relative operand (`mod=00 rm=110`, no register) becomes a
  declared `__near` symbol, so MASM emits the same 2-byte displacement that
  `_relocate` then overwrites with the retail address;
* everything else is the plain mnemonic.

The output is not accepted on faith: the caller compiles it with CL 8.00c and
byte-diffs it against the retail slice (`tools/lift.py`). A spelling MASM
cannot reproduce byte-for-byte (for example the compiler's own `81 EC imm16`
frame, which the assembler renders `83 EC imm8`) is reported, not forced.
"""

from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

import units as unit_index
from compile_msc import compile_omf
from listing import ndisasm
from retail_common import ROOT, RetailError

FRAME = b"\x55\x8b\xec"
TRAILERS = (b"\x8b\xe5\x5d\xcb", b"\x8b\xe5\x5d\xc3")

_JMP = re.compile(r"^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$")
_BARE_ABS = re.compile(r"\[(0x[0-9a-f]+)\]")
_SEG_OPEN = re.compile(r"\[(cs|es|ss|ds):")
_SIZE = re.compile(r"\b(word|byte|dword)\s+(?:near\s+)?((?:cs|es|ss|ds):)?\[")
_FAR_JMP = re.compile(r"\b(jmp)\s+word\s+far\s+")
_SEG_LOAD = re.compile(r"\b(mov)\s+(es|ds|ss|cs)\s*,\s*(?:word|byte|dword)\s+ptr\s+")
_PTR_LOAD = re.compile(r"\b(les|lds)\s+(\w+)\s*,\s*(?:word|byte|dword)\s+ptr\s+")
_FAR_CALL = re.compile(r"\bcall\s+word\s+far\s+")
_NEAR_CALL = re.compile(r"^call\s+0x([0-9a-f]+)$")
_RET_IMM = re.compile(r"\b(retf?)\s+word\s+(0x[0-9a-f]+)$")
_BIG_CONST = re.compile(r"\b0x([0-9a-f]{5,})\b")
# `81 EC iw` / `81 C4 iw`: the compiler's own stack adjust. MASM picks the
# imm8 form for a value it can fold, so the immediate is expressed as a
# relocatable symbol instead — `offset sym` forces the imm16 encoding and the
# fixup is overwritten with the retail frame size by `_relocate`.
_SP_ADJUST = {b"\x81\xec": "sub", b"\x81\xc4": "add"}
_IMM16_GROUP = re.compile(r"^(\S+)\s+(.+),\s*(0x[0-9a-f]+)$")
_INT = re.compile(r"\bint\s+byte\s+")
_ASM_OPEN = re.compile(r"_asm\s*\{")
_BYTE_REG = re.compile(r"\b(a[lh]|b[lh]|c[lh]|d[lh])\b")

SYMBOL_DECL = {1: "char", 2: "int", 4: "long"}
SYMBOL_PREFIX = {1: "mb", 2: "mn", 4: "md"}


class ConvertError(RetailError):
    pass


def _strip_nop(blob: bytes) -> bytes:
    while blob.endswith(b"\x90"):
        blob = blob[:-1]
    return blob


def _trailer(compiled: bytes) -> bytes:
    for trailer in TRAILERS:
        if compiled.endswith(trailer):
            return trailer
    return b""


def _frame_bounds(compiled: bytes) -> tuple[int, int]:
    compiled = _strip_nop(compiled)
    trailer = _trailer(compiled)
    end = len(compiled) - len(trailer)
    start = 3 if compiled[:3] == FRAME else 0
    # CL also saves SI/DI around an `_asm` block that writes them:
    #   push bp; mov bp,sp; push si; <body>; pop si; mov sp,bp; pop bp; retf
    # Those pushes/pops are the compiler's, not the block's.
    saves = 0
    while compiled[start + saves : start + saves + 1] in (b"\x56", b"\x57"):
        saves += 1
    if saves:
        tail = compiled[end - saves : end]
        if len(tail) != saves or any(byte not in (0x5E, 0x5F) for byte in tail):
            saves = 0
    return start + saves, end - saves


def body_for(unit: dict, text: str, root: Path) -> tuple[bytes, list[int]]:
    """Instruction bytes plus the addresses of any 5-byte far calls."""
    pattern = unit_index.dump_pattern(text)
    if pattern is not None:
        image = unit_index.image_bytes(root)[unit["image"]]
        offset = int(unit["offset"])
        # The `_emit` stream is exactly what the block produces: CL adds its
        # frame on top, and `_relocate` trims that. Nothing else is stripped,
        # because CL cannot see that an `_emit` touches SI/DI and so adds no
        # save/restore wrapper of its own here.
        body = bytearray()
        calls: list[int] = []
        for item in pattern:
            if item is None:
                calls.append(len(body))
                body += b"\x9a\x00\x00\x00\x00"
            else:
                body += item
        return bytes(body), calls
    # A mixed/C unit: compile it, then write the retail bytes back into every
    # OMF fixup slot so the disassembly shows real addresses, not placeholders.
    compiled, fixups = compile_omf(root / unit["source"])
    image = unit_index.image_bytes(root)[unit["image"]]
    offset = int(unit["offset"])
    relocated = bytearray(compiled)
    for fix_offset, size in fixups:
        if fix_offset + size <= len(relocated):
            relocated[fix_offset : fix_offset + size] = image[
                offset + fix_offset : offset + fix_offset + size
            ]
    start, end = _frame_bounds(bytes(relocated))
    body = bytes(relocated)[start:end]
    calls = []
    for fix_offset, size in fixups:
        local = fix_offset - start
        if (
            size == 4
            and 0 < local <= len(body) + 1
            and start <= fix_offset - 1 < end
            and bytes(relocated)[fix_offset - 1 : fix_offset] == b"\x9a"
        ):
            calls.append(local - 1)
    return body, sorted(set(calls))


def _operand_size(mnemonic: str) -> int:
    if re.search(r"\bdword\b", mnemonic):
        return 4
    if re.search(r"\bbyte\b|\bnear\b", mnemonic):
        return 1
    if re.search(r"\bword\b", mnemonic):
        return 2
    if _BYTE_REG.search(mnemonic):
        return 1
    return 2


def _masm(mnemonic: str, symgen) -> str:
    # ndisasm prints a sign-extended imm8 as a 64-bit value
    # (`cmp word [x],0xffffffffffffffff`), which MASM rejects as "constant too
    # big". Take the low 16 bits and, when the sign bit is set, write it as a
    # negative decimal so MASM picks the sign-extended imm8 form the retail
    # bytes actually use.
    def narrow(match: re.Match[str]) -> str:
        value = int(match.group(1), 16) & 0xFFFF
        return str(value - 0x10000) if value >= 0x8000 else f"0x{value:x}"

    mnemonic = _BIG_CONST.sub(narrow, mnemonic)
    text = _INT.sub("int ", mnemonic)
    # A direct DS-relative absolute operand has no base register, so MASM
    # rejects `[0x1234]` and `ds:[0x1234]` would add a `3E` prefix. A named
    # near symbol keeps the same encoding and the fixup is overwritten with
    # the retail address by `_relocate`.
    # MASM wants the segment override outside the brackets, not inside.
    text = _SEG_OPEN.sub(r"\1:[", text)
    text = _SIZE.sub(r"\1 ptr \2[", text)
    # A segment register cannot take a size specifier: ndisasm writes
    # `mov es,word [..]`, MASM wants `mov es,..`.
    text = _SEG_LOAD.sub(r"\1 \2, ", text)
    # `les`/`lds` take a dword operand; an explicit size hint is rejected, and
    # an indirect far call through memory is `call dword ptr ..`.
    text = _PTR_LOAD.sub(r"\1 \2, ", text)
    text = _FAR_CALL.sub("call dword ptr ", text)
    text = _FAR_JMP.sub(r"\1 dword ptr ", text)
    # `retf word 8` is an epilogue with a stack-pop count; MASM takes it bare.
    text = _RET_IMM.sub(r"\1 \2", text)
    size = _operand_size(mnemonic)

    def repl(match: re.Match[str]) -> str:
        address = int(match.group(1), 16)
        return symgen(address, size)

    text = _BARE_ABS.sub(repl, text)
    return text


def convert(unit: dict, root: Path | None = None) -> dict:
    """Return the new file-scope declarations, `_asm` body, and a note."""
    root = root or ROOT
    source = root / unit["source"]
    text = source.read_text(encoding="utf-8", errors="replace")
    body, calls = body_for(unit, text, root)
    if not body:
        raise ConvertError("empty instruction stream")
    insns = ndisasm(body)
    helper_names = re.findall(r"call\s+far\s+ptr\s+([A-Za-z_]\w*)", text)
    if len(helper_names) < len(calls):
        helper_names = helper_names + [
            f"mfar{index}" for index in range(len(helper_names), len(calls))
        ]

    targets: set[int] = set()
    for insn in insns:
        match = _JMP.match(insn["mnemonic"])
        if match and insn["raw"][:1] != b"\xea":
            targets.add(int(match.group(2), 16))
    outside = sorted(target for target in targets if target > len(body))
    if outside:
        raise ConvertError(
            f"jump target {outside[0]:#x} leaves the unit (extent {len(body)})"
        )

    symbols: dict[tuple[int, int], str] = {}
    decls: list[str] = []

    def symgen(address: int, size: int) -> str:
        key = (address, size)
        if key not in symbols:
            name = f"{SYMBOL_PREFIX[size]}{address:04X}"
            symbols[key] = name
            # `extern` so CL emits an OMF fixup; a symbol defined in this TU
            # has a known offset and would be encoded literally, which
            # `_relocate` cannot rewrite with the retail address.
            decls.append(f"extern {SYMBOL_DECL[size]} __near {name};")
        return symbols[key]

    lines: list[str] = []
    helper_index = 0
    near_calls: list[str] = []
    frame_syms: list[str] = []
    for insn in insns:
        addr = insn["addr"]
        if addr in targets:
            lines.append(f"lbl{addr:02X}:")
        if insn["mnemonic"].startswith("db "):
            # A byte ndisasm could not decode as an instruction. Emitting a
            # `db` here would be a byte transcript inside the source, so the
            # unit is reported instead (and it would not assemble anyway).
            raise ConvertError(f"undecodable byte {insn['mnemonic']} at {addr:#x}")
        if addr in calls:
            lines.append(f"        call far ptr {helper_names[helper_index]}")
            helper_index += 1
            continue
        adjust = _SP_ADJUST.get(insn["raw"][:2])
        if adjust is not None:
            name = f"fr{addr:02X}"
            if name not in frame_syms:
                frame_syms.append(name)
            lines.append(f"        {adjust} sp, offset {name}")
            continue
        mnemonic = insn["mnemonic"]
        near = _NEAR_CALL.match(mnemonic)
        if near is not None:
            # A near call to another unit: name an extern so CL emits the
            # self-relative fixup `_relocate` overwrites with retail's rel16.
            name = f"nc{int(near.group(1), 16):04X}"
            if name not in near_calls:
                near_calls.append(name)
            lines.append(f"        call {name}")
            continue
        match = _JMP.match(mnemonic)
        if match:
            name = match.group(1)
            target = int(match.group(2), 16)
            delta = target - addr
            offset = f"$+{delta}" if delta >= 0 else f"$-{-delta}"
            if name == "jmp":
                # MASM shortens a `jmp` whose distance is already known, so a
                # rel16 jump has to name a label it cannot resolve in pass 1.
                if insn["raw"][:1] == b"\xeb":
                    lines.append(f"        jmp short {offset}")
                else:
                    lines.append(f"        jmp lbl{target:02X}")
                continue
            # MASM expands a backward conditional jump to `inverse; jmp`, and
            # mis-resolves some forward ones; `$` pins the rel8 the retail
            # image actually uses.
            if name == "jcxz" or name.startswith("loop"):
                # `jcxz $+N` and `loop $+N` are rejected by the assembler.
                lines.append(f"        {name} lbl{target:02X}")
            else:
                lines.append(f"        {name} short {offset}")
            continue
        asm_text = _masm(mnemonic, symgen)
        if insn["raw"][:1] == b"\x81":
            # `81 /r iw`: the retail bytes carry the imm16 form. MASM shrinks
            # a small immediate to the sign-extended imm8 form, so the
            # immediate is made relocatable — `offset sym` forces imm16 and
            # `_relocate` writes the retail bytes over the fixup. The AX
            # destination is exempt because MASM emits the one-byte-opcode AX
            # form (`05`/`3D`/…) instead, which is a different instruction.
            rewritten = _imm16_group(asm_text, addr, decls)
            if rewritten is not None:
                lines.append(f"        {rewritten}")
                continue
        lines.append(f"        {asm_text}")

    for name in near_calls:
        decls.append(f"extern void __near {name}(void);")
    for name in frame_syms:
        decls.append(f"extern int __near {name};")

    for target in sorted(targets):
        if target >= len(body):
            lines.append(f"lbl{target:02X}:")

    note = ""
    if helper_index != len(calls):
        note = f"only {helper_index}/{len(calls)} far calls placed"
    def joined(candidate: list[str]) -> str:
        return "\n".join(candidate) + "\n"

    variants = [{"body": joined(lines), "decls": list(decls)}]
    wrapper = _drop_wrapper_pair(lines)
    if wrapper is not None:
        variants.append({"body": joined(wrapper), "decls": list(decls)})
    # A displacement that retail encoded as disp16 while MASM shrinks it to
    # disp8 is NOT reachable this way: `mov es:[bx+sym],al` with an extern
    # symbol assembles to the direct-address form `26 A2 iw` (MaS sees an
    # absolute address and drops the base), not `26 88 87 iw`. Recorded in
    # docs/STATUS.md rather than attempted here.
    return {
        "decls": decls,
        "variants": variants,
        "body": variants[0]["body"],
        "note": note,
        "text": text,
    }



def _imm16_group(text: str, addr: int, decls: list[str]) -> str | None:
    """Make the immediate of an `81 /r` instruction relocatable.

    Returns None for an AX destination, where MASM insists on the
    one-byte-opcode AX form rather than the ModRM form the retail bytes use.
    """
    match = _IMM16_GROUP.match(text.strip())
    if match is None:
        return None
    opcode, dest, _immediate = match.groups()
    if dest.strip().lower() == "ax":
        return None
    name = f"mn{addr:02X}I"
    decl = f"extern int __near {name};"
    if decl not in decls:
        decls.append(decl)
    return f"{opcode} {dest}, offset {name}"


def _drop_wrapper_pair(lines: list[str]) -> list[str] | None:
    """Leave an asm-authored SI/DI save pair for CL's own wrapper to emit.

    CL inserts `push di; push si` ... `pop si; pop di` around any block that
    mentions SI/DI, so a body that already spells that exact pair (in that
    order) would emit it twice. Dropping the body's pair and letting the
    wrapper provide it reproduces the retail bytes whenever the block still
    writes SI/DI somewhere else.
    """
    starts = [index for index, line in enumerate(lines) if not line.strip().endswith(":")]
    if len(starts) < 2:
        return None
    first = [lines[index].strip() for index in starts[:2]]
    last = [lines[index].strip() for index in starts[-2:]]
    if first == ["push di", "push si"] and last == ["pop si", "pop di"]:
        drop = set(starts[:2]) | set(starts[-2:])
        return [line for index, line in enumerate(lines) if index not in drop]
    single = lines[starts[0]].strip()
    if single in ("push si", "push di") and lines[starts[-1]].strip() == single.replace(
        "push", "pop"
    ):
        drop = {starts[0], starts[-1]}
        return [line for index, line in enumerate(lines) if index not in drop]
    return None


def render(source_text: str, result: dict) -> str:
    """Replace the first `_asm { ... }` block and splice in the declarations."""
    if result.get("source_text") is not None:
        return result["source_text"]
    match = _ASM_OPEN.search(source_text)
    if match is None:
        raise ConvertError("source has no `_asm {` block")
    depth = 1
    index = match.end()
    while index < len(source_text) and depth:
        if source_text[index] == "{":
            depth += 1
        elif source_text[index] == "}":
            depth -= 1
        index += 1
    head = source_text[: match.start()]
    tail = source_text[index:]
    decls = result["decls"]
    decl_text = "\n".join(decls) + ("\n" if decls else "")
    return f"{decl_text}{head}_asm {{\n{result['body']}    }}{tail}"


def data_like(blob: bytes) -> str | None:
    """Evidence that a unit's bytes are data rather than an instruction stream.

    The fragment population is documented in `docs/STATUS.md` as
    predominantly data, strings and the Pocket Soft RTLink runtime, so this
    decides only the cases with positive evidence and returns None (i.e.
    "treat as code") otherwise.
    """
    if not blob:
        return None
    printable = sum(
        1 for byte in blob if 0x20 <= byte < 0x7F or byte in (0, 9, 10, 13)
    )
    if printable / len(blob) > 0.85:
        return f"{printable}/{len(blob)} bytes are printable ASCII"
    if len(set(blob)) <= 4:
        return f"only {len(set(blob))} distinct byte values"
    for period in range(2, 9):
        if len(blob) >= period * 3 and all(
            blob[index] == blob[index % period] for index in range(len(blob))
        ):
            return f"{period}-byte repeating pattern"
    # A record table: one byte value recurring at a constant stride (the
    # overlay's `30 xx xx cb` relink records look like this). Vetoed when the
    # unit ends in a return and carries a call or port instruction, which is
    # how repetitive *code* (a port-write sequence) looks instead.
    ends_in_return = blob[-1:] in (b"\xc3", b"\xcb", b"\xca", b"\xc2")
    code_ish = any(marker in blob for marker in (b"\x9a", b"\xcd", b"\xe6", b"\xe7"))
    if ends_in_return and code_ish:
        return None
    for marker in sorted(set(blob)):
        positions = [index for index, byte in enumerate(blob) if byte == marker]
        if len(positions) >= 4:
            gaps = {positions[index + 1] - positions[index] for index in range(len(positions) - 1)}
            if len(gaps) == 1:
                stride = gaps.pop()
                if positions[0] < stride and stride >= 2:
                    return (
                        f"{len(positions)} {marker:#04x} bytes at a constant "
                        f"{stride}-byte stride"
                    )
    return None


def render_data(unit: dict, blob: bytes, reason: str, note: str) -> str:
    rows = []
    for start in range(0, len(blob), 12):
        chunk = blob[start : start + 12]
        rows.append("    " + ", ".join(f"0x{byte:02X}" for byte in chunk) + ",")
    return (
        f"/*\n"
        f" * Data region, not an instruction stream: {reason}.\n"
        f" * {unit['image']}:{int(unit['offset']):#x}, {len(blob)} bytes.\n"
        f" *\n"
        f" * {note}\n"
        f" */\n"
        f"char mnem_data[] = {{\n"
        + "\n".join(rows)
        + "\n};\n"
    )


def _main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("units", nargs="+")
    parser.add_argument("--write", action="store_true", help="replace the unit body in place")
    parser.add_argument(
        "--verify",
        action="store_true",
        help="compile each candidate with CL 8.00c and byte-diff it against retail",
    )
    parser.add_argument(
        "--write-verified",
        action="store_true",
        help="with --verify, write every candidate that byte-diffs clean",
    )
    parser.add_argument(
        "--jobs", type=int, default=1, help="parallel CL invocations during --verify"
    )
    parser.add_argument(
        "--data",
        action="store_true",
        help="emit a data region as an initialised array instead of instructions",
    )
    parser.add_argument(
        "--force-data",
        action="store_true",
        help="with --data, emit the array even without positive data evidence",
    )
    parser.add_argument(
        "--reason",
        help="with --data, the evidence sentence recorded in the unit header",
    )
    args = parser.parse_args(argv)
    root = ROOT
    try:
        rows = unit_index.index(root)
    except RetailError as exc:
        print(f"gen_mnem: ERROR: {exc}", file=sys.stderr)
        return 2
    selected: list[tuple[dict, dict]] = []
    for selector in args.units:
        matches = [
            row
            for row in rows
            if selector in (row["source"], Path(row["source"]).stem, Path(row["source"]).name)
        ]
        if not matches:
            print(f"gen_mnem: no unit {selector!r}", file=sys.stderr)
            return 2
        for unit in matches:
            try:
                if args.data:
                    task = root / unit["source"]
                    text = task.read_text(encoding="utf-8", errors="replace")
                    blob, _calls = body_for(unit, text, root)
                    # A data array carries no OMF fixups, so every byte has to
                    # be literal: take the retail slice rather than the
                    # `_emit` stream's far-call placeholders.
                    if unit["extent"]:
                        image = unit_index.image_bytes(root)[unit["image"]]
                        start = int(unit["offset"])
                        blob = image[start : start + unit["extent"]]
                    reason = data_like(blob)
                    if args.reason:
                        reason = args.reason
                    if reason is None:
                        if not args.force_data:
                            print(f"===== {unit['source']}: no data evidence; left alone")
                            continue
                        reason = "no positive evidence either way"
                    result = {
                        "decls": [],
                        "body": "",
                        "note": reason,
                        "text": text,
                        "source_text": render_data(
                            unit,
                            blob,
                            reason,
                            "Transcribed as data. This translation unit has no "
                            "PUBDEF, so the splice takes its first LEDATA, which "
                            "is this array.",
                        ),
                    }
                else:
                    result = convert(unit, root)
            except (ConvertError, RetailError) as exc:
                print(f"===== {unit['source']}: ERROR {exc}")
                continue
            selected.append((unit, result))
            if args.verify:
                continue
            print(f"===== {unit['source']} {result['note']}")
            if args.write:
                new_text = render(result["text"], result)
                (root / unit["source"]).write_text(new_text, encoding="utf-8")
                print("wrote")
            else:
                print(render(result["text"], result))
    if args.verify:
        return _verify(selected, root, write=args.write_verified, jobs=max(1, args.jobs))
    return 0


def _verify(
    selected: list[tuple[dict, dict]], root: Path, *, write: bool = False, jobs: int = 1
) -> int:
    """Compile every candidate and byte-diff it against its retail slice."""
    import tempfile
    from concurrent.futures import ThreadPoolExecutor

    from compile_msc import compile_omf
    from lift import check_compiled, summary_line

    images = unit_index.image_bytes(root)
    with tempfile.TemporaryDirectory(prefix="mnem_") as tmp:
        work = Path(tmp)

        def candidate(index: int, variant_index: int, result: dict) -> Path:
            path = work / f"cand{index:04d}_{variant_index}.c"
            attempt = dict(result)
            attempt["body"] = result["variants"][variant_index]["body"]
            attempt["decls"] = result["variants"][variant_index]["decls"]
            path.write_text(render(result["text"], attempt), encoding="utf-8")
            return path

        def build(path: Path):
            try:
                return compile_omf(path)
            except RetailError as exc:
                return exc

        def compile_all(paths: list[Path]) -> list:
            if jobs > 1:
                with ThreadPoolExecutor(max_workers=jobs) as pool:
                    return list(pool.map(build, paths))
            return [build(path) for path in paths]

        def evaluate(unit: dict, value):
            if isinstance(value, RetailError):
                return None
            compiled, fixups = value
            return check_compiled(unit, compiled, fixups, images)

        outcomes: list[dict | None] = [None] * len(selected)
        errors: list[RetailError | None] = [None] * len(selected)
        chosen: dict[int, int] = {}
        first = compile_all([candidate(i, 0, result) for i, (_u, result) in enumerate(selected)])
        for index, (unit, _result) in enumerate(selected):
            if isinstance(first[index], RetailError):
                errors[index] = first[index]
                continue
            outcomes[index] = evaluate(unit, first[index])

        # Units whose first spelling did not match get a second attempt with
        # the asm-authored SI/DI save pair left to CL's own wrapper.
        pending = [
            index
            for index, (unit, result) in enumerate(selected)
            if len(result["variants"]) > 1
            and (outcomes[index] is None or outcomes[index]["result"] != "MATCH")
        ]
        variant_index = 1
        while pending:
            tries = [
                (index, variant_index)
                for index in pending
                if len(selected[index][1]["variants"]) > variant_index
            ]
            if not tries:
                break
            retry_built = compile_all(
                [candidate(index, variant, selected[index][1]) for index, variant in tries]
            )
            still: list[int] = []
            for (index, variant), value in zip(tries, retry_built):
                outcome = None if isinstance(value, RetailError) else evaluate(
                    selected[index][0], value
                )
                if outcome is not None and outcome["result"] == "MATCH":
                    outcomes[index] = outcome
                    errors[index] = None
                    chosen[index] = variant
                else:
                    still.append(index)
            pending = still
            variant_index += 1

        good = 0
        ok: dict[str, bool] = {}
        for index, (unit, result) in enumerate(selected):
            if outcomes[index] is None:
                exc = errors[index]
                lines = (
                    [line for line in str(exc).strip().splitlines() if line.strip()]
                    if exc is not None
                    else ["no candidate assembled"]
                )
                print(f"{unit['source']:<28} COMPILE-FAIL {' | '.join(lines[:3])}")
                ok[unit["source"]] = False
                continue
            outcome = outcomes[index]
            print(summary_line(outcome))
            matched = outcome["result"] == "MATCH"
            if matched and chosen.get(index):
                # The winning spelling is the one that has to be written out.
                winner = result["variants"][chosen[index]]
                result["body"] = winner["body"]
                result["decls"] = winner["decls"]
            # A source registered at more than one offset is only replaced
            # when every one of its registrations matches.
            ok[unit["source"]] = ok.get(unit["source"], True) and matched
            if matched:
                good += 1
        if write:
            for unit, result in selected:
                if ok.get(unit["source"]):
                    (root / unit["source"]).write_text(
                        render(result["text"], result), encoding="utf-8"
                    )
        print(f"{good}/{len(selected)} MATCH")
        return 0 if good == len(selected) else 1


if __name__ == "__main__":
    raise SystemExit(_main())
