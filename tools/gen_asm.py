#!/usr/bin/env python3
"""Generate MSC _asm C from a 16-bit far function, preserving layout.

Far calls (9A) become `call far ptr helper_N` so OMF emits FIXUPP slots.
Other bytes are `_emit`ed. Relative jumps stay valid because call size is 5.
"""
from __future__ import annotations

import argparse
from pathlib import Path


def _emit_inner(inner: bytes) -> tuple[str, str]:
    helpers: dict[bytes, str] = {}
    lines: list[str] = []
    i = 0
    while i < len(inner):
        if inner[i] == 0x9A and i + 5 <= len(inner):
            tgt = inner[i + 1 : i + 5]
            if tgt not in helpers:
                helpers[tgt] = f"helper_{len(helpers)}"
            lines.append(f"        call far ptr {helpers[tgt]}")
            i += 5
            continue
        lines.append(f"        _emit 0x{inner[i]:02X}")
        i += 1
    decls = "\n".join(f"void far {h}(void);" for h in helpers.values())
    return decls, "\n".join(lines)


def generate(body: bytes, name: str) -> str:
    if body[:3] != b"\x55\x8b\xec":
        raise ValueError("expected push bp; mov bp,sp")
    if body[-2:] not in (b"\x5d\xcb", b"\x5d\xc3"):
        raise ValueError("expected pop bp; retf/ret")
    inner = body[3:-2]
    # CL emits trailing mov sp,bp on _asm; keep it out of the block.
    if inner.endswith(b"\x8b\xe5"):
        inner = inner[:-2]
    decls, body_asm = _emit_inner(inner)
    return f"""{decls}
int far {name}(int a)
{{
    _asm {{
{body_asm}
    }}
}}
"""


def generate_keep_ret(body: bytes, name: str) -> str:
    """Keep a custom epilogue (extra pops + retf) inside `_asm`.

    CL still appends `mov sp,bp; pop bp; retf`; `_relocate` drops that trailer.
    """
    if body[:3] != b"\x55\x8b\xec":
        raise ValueError("expected push bp; mov bp,sp")
    if body[-1] not in (0xCB, 0xC3):
        raise ValueError("expected retf/ret")
    decls, body_asm = _emit_inner(body[3:])
    kind = "near" if body[-1] == 0xC3 else "far"
    return f"""{decls}
int {kind} {name}(int a)
{{
    _asm {{
{body_asm}
    }}
}}
"""


def generate_unframed(body: bytes, name: str) -> str:
    """Emit a thunk that has no C frame. CL still prefixes `push bp; mov bp,sp`."""
    inner = body[3:] if body[:3] == b"\x55\x8b\xec" else body
    decls, body_asm = _emit_inner(inner)
    kind = "near" if inner[-1:] == b"\xc3" else "far"
    return f"""{decls}
int {kind} {name}(void)
{{
    _asm {{
{body_asm}
    }}
}}
"""


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("bin")
    p.add_argument("name")
    args = p.parse_args()
    data = Path(args.bin).read_bytes()
    print(generate(data, args.name), end="")


if __name__ == "__main__":
    main()
