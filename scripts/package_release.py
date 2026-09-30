#!/usr/bin/env python3
"""Package only the native executable, host DLLs and user documentation."""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path
import re
import shutil
import tarfile
import tempfile
import zipfile

ROOT = Path(__file__).resolve().parents[1]


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--binary", required=True, type=Path)
    parser.add_argument("--version", required=True)
    parser.add_argument("--platform", required=True,
                        choices=("linux-x86_64", "windows-x86_64"))
    parser.add_argument("--sdl-runtime", type=Path, help="Linux SDL2 shared library to bundle")
    parser.add_argument("--sdl-license", type=Path, help="Copyright/license for the bundled SDL2 library")
    parser.add_argument("--output", default=Path("dist"), type=Path)
    args = parser.parse_args()
    if not re.fullmatch(r"v[0-9]+\.[0-9]+\.[0-9]+(?:-[a-z0-9.]+)?", args.version):
        parser.error("version must be a release tag such as v0.1.0-alpha.1")
    binary = args.binary.resolve()
    windows = args.platform.startswith("windows")
    expected = "xanth_port.exe" if windows else "xanth_port"
    if binary.name != expected or not binary.is_file():
        parser.error(f"expected an existing {expected} executable")
    dlls = sorted(binary.parent.glob("*.dll")) if windows else []
    if windows and not any(p.name.lower() == "sdl2.dll" for p in dlls):
        parser.error("Windows package requires SDL2.dll beside xanth_port.exe")
    if not windows and (args.sdl_runtime is None or args.sdl_license is None):
        parser.error("Linux packaging requires --sdl-runtime and --sdl-license")
    stem = f"xanth-port-{args.version}-{args.platform}"
    args.output.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="xanth-release-") as temporary:
        package = Path(temporary) / stem
        package.mkdir()
        shutil.copy2(binary, package / expected)
        if not windows:
            (package / "lib").mkdir()
            (package / "licenses").mkdir()
            shutil.copy2(args.sdl_runtime, package / "lib" / "libSDL2-2.0.so.0")
            shutil.copy2(args.sdl_license, package / "licenses" / "SDL2-copyright")
            shutil.copy2(ROOT / "scripts" / "launch.sh", package / "launch.sh")
            (package / "launch.sh").chmod(0o755)
        pins = (ROOT / "port" / "include" / "retail_asset_manifest.h").read_text()
        names = re.findall(r'\{"([^"/]+)", "[0-9a-f]{64}"\}', pins)
        if len(names) != 90:
            raise ValueError("Unexpected retail asset manifest; inspect the required file list")
        (package / "DATA_FILES.txt").write_text(
            "Supply your own matching XANBUD files, all directly in one directory.\n"
            "No game data is included. SHA-256 pins are checked at startup.\n\n"
            + "XANTH.EXE\n" + "\n".join(names) + "\n", encoding="utf-8")
        for dll in dlls:
            shutil.copy2(dll, package / dll.name)
        for source, target in (
            (ROOT / "LICENSE", "LICENSE"),
            (ROOT / "LICENSE-NOTES.md", "LICENSE-NOTES.md"),
            (ROOT / "releases" / "GETTING_STARTED.txt", "GETTING_STARTED.txt"),
            (ROOT / "releases" / f"{args.version}.md", "RELEASE-NOTES.md"),
            (ROOT / "docs" / "ENHANCEMENTS.md", "ENHANCEMENTS.md"),
        ):
            shutil.copy2(source, package / target)
        manifest = "".join(
            f"{hashlib.sha256(p.read_bytes()).hexdigest()}  {p.relative_to(package).as_posix()}\n"
            for p in sorted(package.rglob("*")) if p.is_file()
        )
        (package / "FILES.sha256").write_text(manifest, encoding="utf-8")
        if windows:
            archive = args.output / f"{stem}.zip"
            with zipfile.ZipFile(archive, "w", zipfile.ZIP_DEFLATED) as output:
                for path in sorted(package.iterdir()):
                    output.write(path, f"{stem}/{path.name}")
        else:
            archive = args.output / f"{stem}.tar.gz"
            with tarfile.open(archive, "w:gz") as output:
                output.add(package, arcname=stem)
    checksum = hashlib.sha256(archive.read_bytes()).hexdigest()
    archive.with_name(archive.name + ".sha256").write_text(
        f"{checksum}  {archive.name}\n", encoding="ascii"
    )
    print(f"Packaged {archive} (SHA-256 {checksum})")


if __name__ == "__main__":
    main()
