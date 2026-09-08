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


def toolchain_available() -> bool:
    return (MSC_BIN / "CL.EXE").is_file() and (MSC_BIN / "Q23.EXE").is_file() and shutil.which("wine") is not None


def compile_c(source: Path, *, flags: list[str] | None = None) -> bytes:
    if not toolchain_available():
        raise RetailError("historical compiler missing: MSVC 8.00c (CL.EXE + Q23.EXE) under wine")
    flags = flags or list(DEFAULT_FLAGS)
    source = source.resolve()
    needed = [
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
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    with tempfile.TemporaryDirectory(prefix="msc800c_") as tmp:
        work = Path(tmp)
        for name in needed:
            src = MSC_BIN / name
            if src.is_file():
                shutil.copy2(src, work / name)
        shutil.copy2(source, work / source.name)
        text = source.read_text(encoding="utf-8", errors="replace")
        if "#include" in text and MSC_INCLUDE.is_dir():
            include = work / "include"
            shutil.copytree(MSC_INCLUDE, include, dirs_exist_ok=True)
            env["INCLUDE"] = str(include)
        cmd = ["wine", str(work / "CL.EXE"), *flags, source.name]
        proc = subprocess.run(cmd, cwd=work, env=env, capture_output=True, text=True)
        obj = work / (source.stem + ".obj")
        if proc.returncode != 0 or not obj.is_file():
            raise RetailError(f"CL.EXE failed: {proc.stdout} {proc.stderr}")
        obj_bytes = obj.read_bytes()
        return ledata_code(obj_bytes)


def compile_omf(source: Path, *, flags: list[str] | None = None) -> tuple[bytes, list[tuple[int, int]]]:
    """Compile and return LEDATA plus OMF fixup (offset, size) pairs."""
    if not toolchain_available():
        raise RetailError("historical compiler missing: MSVC 8.00c (CL.EXE + Q23.EXE) under wine")
    flags = flags or list(DEFAULT_FLAGS)
    source = source.resolve()
    needed = [
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
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    with tempfile.TemporaryDirectory(prefix="msc800c_") as tmp:
        work = Path(tmp)
        for name in needed:
            src = MSC_BIN / name
            if src.is_file():
                shutil.copy2(src, work / name)
        shutil.copy2(source, work / source.name)
        text = source.read_text(encoding="utf-8", errors="replace")
        if "#include" in text and MSC_INCLUDE.is_dir():
            include = work / "include"
            shutil.copytree(MSC_INCLUDE, include, dirs_exist_ok=True)
            env["INCLUDE"] = str(include)
        proc = subprocess.run(
            ["wine", str(work / "CL.EXE"), *flags, source.name],
            cwd=work,
            env=env,
            capture_output=True,
            text=True,
        )
        obj = work / (source.stem + ".obj")
        if proc.returncode != 0 or not obj.is_file():
            raise RetailError(f"CL.EXE failed: {proc.stdout} {proc.stderr}")
        return ledata_and_fixups(obj.read_bytes())
