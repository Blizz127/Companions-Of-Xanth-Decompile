"""Run historical LINK.EXE on recovered CL 8.00c objects."""

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

from compile_msc import MSC_BIN, compile_c, toolchain_available
from retail_common import ROOT, RetailError

LINK_EXE = MSC_BIN / "LINK.EXE"


def linker_available() -> bool:
    return toolchain_available() and LINK_EXE.is_file() and shutil.which("wine") is not None


def link_objects(obj_names_and_bytes: list[tuple[str, bytes]]) -> dict:
    if not linker_available():
        raise RetailError("historical linker missing: MSVC 8.00c LINK.EXE under wine")
    if not obj_names_and_bytes:
        raise RetailError("no objects to link")
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    with tempfile.TemporaryDirectory(prefix="msclink_") as tmp:
        work = Path(tmp)
        shutil.copy2(LINK_EXE, work / "LINK.EXE")
        for extra in ("CL.ERR", "RCDLL.DLL"):
            src = MSC_BIN / extra
            if src.is_file():
                shutil.copy2(src, work / extra)
        names = []
        for name, data in obj_names_and_bytes:
            (work / name).write_bytes(data)
            names.append(name)
        spec = "+".join(names)
        # /NOI /NOD /NOE: no ignore-case change, no default libs, no extended dictionary.
        # Overlay layout for this game is Legend's .OVL, not LINK (file) overlays.
        cmd = [
            "wine",
            str(work / "LINK.EXE"),
            f"/NOI",
            "/NOD",
            "/NOE",
            f"{spec},units.exe,units.map,nul,",
        ]
        proc = subprocess.run(cmd, cwd=work, env=env, capture_output=True, text=True, input="\n")
        mz = work / "units.exe"
        return {
            "linker": "Microsoft LINK (MSVC 8.00c)",
            "objects": names,
            "overlay_layout": "legend-reconstructed",
            "returncode": proc.returncode,
            "stdout": proc.stdout[-2000:],
            "stderr": proc.stderr[-2000:],
            "produced_mz": mz.is_file() and mz.read_bytes()[:2] == b"MZ",
            "mz_size": mz.stat().st_size if mz.is_file() else 0,
        }


def compile_to_obj(source: Path) -> bytes:
    """Compile and return the raw OMF object (not just LEDATA)."""
    from compile_msc import DEFAULT_FLAGS, MSC_INCLUDE
    import tempfile as tf

    if not toolchain_available():
        raise RetailError("historical compiler missing")
    source = source.resolve()
    needed = ["CL.EXE", "Q23.EXE", "C13216.EXE", "C23216.EXE", "C33216.EXE", "C1XX3216.EXE", "CL.ERR", "C1.ERR", "C23.ERR", "CL.MSG"]
    env = os.environ.copy()
    env["WINEDEBUG"] = "-all"
    with tf.TemporaryDirectory(prefix="mscobj_") as tmp:
        work = Path(tmp)
        for name in needed:
            src = MSC_BIN / name
            if src.is_file():
                shutil.copy2(src, work / name)
        shutil.copy2(source, work / source.name)
        proc = subprocess.run(
            ["wine", str(work / "CL.EXE"), *DEFAULT_FLAGS, source.name],
            cwd=work,
            env=env,
            capture_output=True,
            text=True,
        )
        obj = work / (source.stem + ".obj")
        if proc.returncode != 0 or not obj.is_file():
            raise RetailError(f"CL.EXE failed producing OBJ: {proc.stdout} {proc.stderr}")
        return obj.read_bytes()
