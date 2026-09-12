"""Compile one C translation unit with the pinned MSVC 8.00c 16-bit compiler."""

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

from omf import ledata_and_fixups, ledata_code
from retail_common import ROOT, RetailError

MSC_BIN = ROOT / "tools/toolchain/msvc152/MSVC/BIN"
MSC_INCLUDE = ROOT / "tools/toolchain/msvc152/MSVC/INCLUDE"
DEFAULT_FLAGS = ["/c", "/f-", "/AL", "/Gs", "/Os", "/nologo", "/Zl"]
_CL_NEEDED = [
    "CL.EXE",
    "Q23.EXE",
    "C13216.EXE",
    "C23216.EXE",
    "C33216.EXE",
    "C1XX3216.EXE",
    "CL.ERR",
    "C1.ERR",
    "C23.ERR",
    "CL.MSG",
]
# Proven with leftover _asm units; keeps the Wine CL command line short.
BATCH_SIZE = 12


def toolchain_available() -> bool:
    return (MSC_BIN / "CL.EXE").is_file() and (MSC_BIN / "Q23.EXE").is_file() and shutil.which("wine") is not None


def _compile_objs(sources: list[Path], flags: list[str]) -> dict[Path, bytes]:
    """Compile C sources with one toolchain copy. Keys are resolved Paths."""
    if not sources:
        return {}
    stems = [src.stem for src in sources]
    if len(stems) != len(set(stems)):
        raise RetailError("CL.EXE batch has duplicate source stems")
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    with tempfile.TemporaryDirectory(prefix="msc800c_") as tmp:
        work = Path(tmp)
        for name in _CL_NEEDED:
            src = MSC_BIN / name
            if src.is_file():
                shutil.copy2(src, work / name)
        need_inc = False
        for source in sources:
            shutil.copy2(source, work / source.name)
            if "#include" in source.read_text(encoding="utf-8", errors="replace"):
                need_inc = True
        if need_inc and MSC_INCLUDE.is_dir():
            include = work / "include"
            shutil.copytree(MSC_INCLUDE, include, dirs_exist_ok=True)
            env["INCLUDE"] = str(include)
        proc = subprocess.run(
            ["wine", str(work / "CL.EXE"), *flags, *[src.name for src in sources]],
            cwd=work,
            env=env,
            capture_output=True,
            text=True,
            errors="replace",
        )
        out: dict[Path, bytes] = {}
        missing: list[Path] = []
        for source in sources:
            obj = work / (source.stem + ".obj")
            if obj.is_file():
                out[source] = obj.read_bytes()
            else:
                missing.append(source)
        if missing:
            if len(sources) == 1:
                raise RetailError(f"CL.EXE failed: {proc.stdout} {proc.stderr}")
            # One bad TU should not sink the rest of the batch.
            for source in missing:
                out.update(_compile_objs([source], flags))
        return out


def compile_objs_many(sources: list[Path], *, flags: list[str] | None = None) -> dict[Path, bytes]:
    """Compile many C files to raw OMF objects, batching CL invocations."""
    if not toolchain_available():
        raise RetailError("historical compiler missing: MSVC 8.00c (CL.EXE + Q23.EXE) under wine")
    flags = flags or list(DEFAULT_FLAGS)
    uniq: list[Path] = []
    seen: set[Path] = set()
    for source in sources:
        path = source.resolve()
        if path in seen:
            continue
        seen.add(path)
        uniq.append(path)
    out: dict[Path, bytes] = {}
    for index in range(0, len(uniq), BATCH_SIZE):
        out.update(_compile_objs(uniq[index : index + BATCH_SIZE], flags))
    return out


def compile_c(source: Path, *, flags: list[str] | None = None) -> bytes:
    source = source.resolve()
    obj = compile_objs_many([source], flags=flags)[source]
    return ledata_code(obj)


def compile_omf(source: Path, *, flags: list[str] | None = None) -> tuple[bytes, list[tuple[int, int]]]:
    """Compile and return LEDATA plus OMF fixup (offset, size) pairs."""
    source = source.resolve()
    obj = compile_objs_many([source], flags=flags)[source]
    return ledata_and_fixups(obj)


def compile_omf_many(
    sources: list[Path], *, flags: list[str] | None = None
) -> dict[Path, tuple[bytes, list[tuple[int, int]]]]:
    """Compile many C files to LEDATA plus OMF fixup pairs."""
    objs = compile_objs_many(sources, flags=flags)
    return {path: ledata_and_fixups(data) for path, data in objs.items()}
