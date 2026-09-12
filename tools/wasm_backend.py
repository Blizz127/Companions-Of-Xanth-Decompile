"""Assemble a recovered unit listing with the vendored Open Watcom assembler.

The pinned MSVC 1.52 assembler cannot spell the remaining dump units (see
`docs/STATUS.md`, twelfth pass), but the Open Watcom assembler already
vendored at `tools/toolchain/watcom` has exactly the encoding profile the
retail bytes need. A unit recovered that way is a `.asm` listing assembled
here and spliced exactly like a `.c` unit compiled by CL: the LEDATA bytes
plus their OMF fixup offsets, which `c_units._relocate` then compares against
retail, overwriting every fixup slot with the retail bytes.
"""

from __future__ import annotations

import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

_TOOLS = Path(__file__).resolve().parent
if str(_TOOLS) not in sys.path:
    sys.path.insert(0, str(_TOOLS))

from omf import ledata_and_fixups
from retail_common import ROOT, RetailError

WATCOM = ROOT / "tools/toolchain/watcom"
WASM = WATCOM / "binnt/wasm.exe"

# 8086 by default: a listing that needs 186/286/386 opcodes says so itself
# with a `.186`/`.286`/`.386` directive, which is what the retail units do.
DEFAULT_CPU = "/0"


def toolchain_available() -> bool:
    return WASM.is_file() and shutil.which("wine") is not None


def assemble_listing(source: Path, *, cpu: str = DEFAULT_CPU) -> tuple[bytes, list[tuple[int, int]]]:
    """Assemble one `.asm` unit listing and return its code bytes and fixups."""
    if not toolchain_available():
        raise RetailError("Watcom assembler missing: tools/toolchain/watcom/binnt/wasm.exe")
    source = source.resolve()
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    env["WATCOM"] = str(WATCOM)
    env["INCLUDE"] = str(WATCOM / "h")
    with tempfile.TemporaryDirectory(prefix="wasmunit_") as tmp:
        work = Path(tmp)
        shutil.copy2(source, work / "unit.asm")
        proc = subprocess.run(
            ["wine", str(WASM), "-ml", cpu, "-fo=unit.obj", "unit.asm"],
            cwd=work,
            env=env,
            capture_output=True,
            text=True,
            errors="replace",
        )
        obj = work / "unit.obj"
        if not obj.is_file():
            detail = [line for line in (proc.stdout + proc.stderr).splitlines() if "rror" in line]
            raise RetailError(
                f"wasm failed on {source.name}: {' | '.join(detail[:3]) or 'no object'}"
            )
        return ledata_and_fixups(obj.read_bytes())


def assemble_many(sources: list[Path]) -> dict[Path, tuple[bytes, list[tuple[int, int]]]]:
    return {source.resolve(): assemble_listing(source) for source in sources}
