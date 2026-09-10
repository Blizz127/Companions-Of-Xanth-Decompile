"""Pack many tiny C translation units so LINK does not hit L1049."""

from __future__ import annotations

import re
from pathlib import Path

_GLOBAL = re.compile(r"^(char|int|unsigned|long)\s+\w+\s*;\s*$")


def _has_file_scope_global(text: str) -> bool:
    for line in text.splitlines():
        if _GLOBAL.match(line.strip()):
            return True
    return False


def pack_sources(paths: list[Path], *, per_file: int = 80) -> list[tuple[str, str, list[Path]]]:
    """Return (packed_name, packed_c_text, members) groups.

    Files with file-scope globals stay in their own group so `int g;` does
    not collide. Other files are concatenated.
    """
    singles: list[Path] = []
    packable: list[Path] = []
    for path in paths:
        text = path.read_text(encoding="utf-8", errors="replace")
        if _has_file_scope_global(text):
            singles.append(path)
        else:
            packable.append(path)
    groups: list[tuple[str, str, list[Path]]] = []
    for path in singles:
        groups.append((path.stem, path.read_text(encoding="utf-8", errors="replace"), [path]))
    for index in range(0, len(packable), per_file):
        chunk = packable[index : index + per_file]
        parts = [f"/* packed from {p.as_posix()} */\n{p.read_text(encoding='utf-8', errors='replace')}\n" for p in chunk]
        name = f"pack_{index // per_file:03d}"
        groups.append((name, "\n".join(parts), chunk))
    return groups
