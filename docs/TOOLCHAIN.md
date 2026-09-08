# Toolchain evidence

Inspected on 2026-09-07 from the pinned `XANTH.EXE` / `XANTH.OVL` and a
controlled compile with Microsoft C/C++ 8.00c.

## Identified compiler

**Microsoft C/C++ Optimizing Compiler Version 8.00c** (Visual C++ 1.52,
16-bit, Phar Lap TNT hosted `CL.EXE`). Banner:

```
Microsoft (R) C/C++ Optimizing Compiler Version 8.00c
Copyright (c) Microsoft Corp 1984-1993. All rights reserved.
@(#)Microsoft C Compiler 8.00c  - Copyright (C) 1986-1992 Microsoft Corp.
Oct  7 1993 02:01:41
```

This is the compiler on the locally provisioned MSVC 1.52 ISO. It is not
inferred from the CRT copyright string alone.

## Controlled experiment

Host: Wine 8 + `MSVC/BIN/CL.EXE` + `Q23.EXE` (optimizing C2). Flags that
emit the retail prologue family (`push bp` / `mov bp,sp` = `55 8B EC`):

```
CL.EXE /c /f- /AL /Gs /Os /Zl
```

Source:

```c
void far foo(char far *p)
{
    p[0] = 1;
}
```

Object LEDATA (hex): `55 8B EC C4 5E 06 26 C6 07 01 5D CB`

Retail functions use the same `55 8B EC` … `5D CB` far-frame shape, large
model (`/AL`), and `lds`/`les` of `[bp+6]` for the first far pointer
argument. `/Os` without `/f-` selects the fast compiler and does **not**
match this encoding. `/Gc` (Pascal) emits `retf n` (`CA`) which is present
in retail but is not the default.

Empty `void far foo(void) {}` under `/Os` is a single `retf` (`CB`). A
far call wrapper under `/Os` is `9A … CB`. Overlay manager strings
(`eov0001:`, `$$RTL_TERMINATE`, `use RELOAD to increase size`) are **not**
Microsoft `INT 3Fh` LINK overlays; they are a third-party/Legend overlay
runtime. `XANTH.OVL` is a 62-entry table of `{size, load_segment=0x30CB}`
plus 62 `0000:FFFF` reserved slots (496 bytes), then 16-bit code.

## Whole-program rebuild

`tools/rebuild.py` reconstructs:

- MZ header from parsed fields and the reloc tuple list (header tail is
  zero-padded to 1888 paragraphs, matching retail)
- Load image from a 16-bit NASM listing of ndisasm mnemonics (exact
  encodings forced with `db` only when NASM’s encoding differs)
- EXE tail as a data listing
- OVL directory from parsed entries + `FFFF` reserved slots, payload as
  a 16-bit listing

C translation units compiled with CL 8.00c are spliced in when they
BINARY-MATCH a bounded function. The historical compiler is required for
those units; NASM is the assembler for listing-form recovered code.

Open Watcom `wcc -ml` was run as a negative control: empty far function
is `CB` only and is not used as the matching compiler.
