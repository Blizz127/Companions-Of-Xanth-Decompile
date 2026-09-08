"""Turn a 16-bit blob into NASM source that round-trips through nasm -f bin."""

from __future__ import annotations

import re
import subprocess
import tempfile
from pathlib import Path


class ListingError(RuntimeError):
    pass


_INSN = re.compile(r"^([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+(.*)$")


def ndisasm(blob: bytes, *, bits: int = 16) -> list[dict]:
    with tempfile.NamedTemporaryFile(suffix=".bin", delete=False) as handle:
        handle.write(blob)
        path = Path(handle.name)
    try:
        out = subprocess.check_output(["ndisasm", "-b", str(bits), str(path)], text=True)
    except FileNotFoundError as exc:
        raise ListingError("ndisasm not on PATH") from exc
    finally:
        path.unlink(missing_ok=True)
    insns: list[dict] = []
    for line in out.splitlines():
        match = _INSN.match(line.strip())
        if not match:
            continue
        raw = bytes.fromhex(match.group(2))
        insns.append(
            {
                "addr": int(match.group(1), 16),
                "raw": raw,
                "mnemonic": match.group(3).strip(),
            }
        )
    if not insns:
        raise ListingError("ndisasm produced no instructions")
    return insns


def _nasm_result(source: str) -> tuple[int, str, bytes]:
    with tempfile.TemporaryDirectory() as tmp:
        asm = Path(tmp) / "t.asm"
        out = Path(tmp) / "t.bin"
        asm.write_text(source)
        proc = subprocess.run(
            ["nasm", "-f", "bin", "-o", str(out), str(asm)],
            capture_output=True,
            text=True,
        )
        blob = out.read_bytes() if out.is_file() else b""
        return proc.returncode, proc.stderr, blob


def _nasm_bin(source: str) -> bytes:
    code, err, blob = _nasm_result(source)
    if code != 0 or not blob:
        raise ListingError(err.strip() or "nasm failed")
    return blob


def _db(raw: bytes) -> str:
    return "db " + ", ".join(f"0x{byte:02X}" for byte in raw)


def _emit(insns: list[dict], use_db: set[int], *, bits: int) -> str:
    lines = [f"bits {bits}", "org 0"]
    for index, insn in enumerate(insns):
        if index in use_db:
            lines.append(f"{_db(insn['raw'])}  ; {insn['mnemonic']}")
        else:
            lines.append(insn["mnemonic"])
    return "\n".join(lines) + "\n"


def nasm_source(blob: bytes, *, bits: int = 16) -> str:
    insns = ndisasm(blob, bits=bits)
    use_db: set[int] = set()

    def try_assemble() -> tuple[int, str, bytes]:
        return _nasm_result(_emit(insns, use_db, bits=bits))

    for _ in range(64):
        code, err, _got = try_assemble()
        if code == 0:
            break
        changed = False
        for line in err.splitlines():
            match = re.search(r":(\d+): error:", line)
            if not match:
                continue
            idx = int(match.group(1)) - 3
            if 0 <= idx < len(insns) and idx not in use_db:
                use_db.add(idx)
                changed = True
        if not changed:
            use_db.update(range(len(insns)))
            break
    else:
        raise ListingError("nasm syntax loop")

    for _ in range(8):
        source = _emit(insns, use_db, bits=bits)
        got = _nasm_bin(source)
        if got == blob:
            return source
        changed = False
        if len(got) == len(blob):
            for index, insn in enumerate(insns):
                if index in use_db:
                    continue
                start = insn["addr"]
                raw = insn["raw"]
                if got[start : start + len(raw)] != raw:
                    use_db.add(index)
                    changed = True
        else:
            pos = 0
            for index, insn in enumerate(insns):
                raw = insn["raw"]
                if index in use_db:
                    pos += len(raw)
                    continue
                if pos != insn["addr"] or got[pos : pos + len(raw)] != raw:
                    use_db.add(index)
                    changed = True
                    break
                pos += len(raw)
        if not changed:
            use_db.update(i for i in range(len(insns)) if i not in use_db)
    source = _emit(insns, use_db, bits=bits)
    got = _nasm_bin(source)
    if got != blob:
        raise ListingError("listing did not round-trip through nasm")
    return source


def assemble_data(blob: bytes, *, bits: int = 16) -> tuple[bytes, str]:
    lines = [f"bits {bits}", "org 0"]
    for offset in range(0, len(blob), 16):
        lines.append(_db(blob[offset : offset + 16]))
    source = "\n".join(lines) + "\n"
    return _nasm_bin(source), source


def assemble(blob: bytes, *, bits: int = 16) -> tuple[bytes, str]:
    try:
        source = nasm_source(blob, bits=bits)
        return _nasm_bin(source), source
    except ListingError:
        return assemble_data(blob, bits=bits)
