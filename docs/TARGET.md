# Companions of Xanth target — 2026-09-07

## Starting audit

Project: `/var/home/blizz/Projects/Companions of Xanth decomp/`. Initially no
Git repository, source, or tooling. Only the user's `XANBUD.iso` (202412032
bytes) existed. The disc is the 1997 budget CD reissue (ISO 9660 volume
`XANBUD`, publisher `SSI`, PVD date 1997-06-03). Game files inside
`XANTH/` are stamped 1994-04-17.

No other SKU was supplied. The 1993 floppy release is not authority.

## Selected binaries

Both files are required. Matching is not complete if only the stub EXE
rebuilds.

| Role | ISO member | Local path | Size | SHA-256 |
|---|---|---|---|---|
| Executable | `XANTH/XANTH.EXE` | `original/XANTH.EXE` | 265057 | `3982b5f5c055a4fd84b0a4fe3b911b7393af687b623d0d00f846c5da46d26671` |
| Overlay | `XANTH/XANTH.OVL` | `original/XANTH.OVL` | 326091 | `efbf371c78169e21449b89b932e50ac7952b143c322d82192badd7a369174474` |

ISO SHA-256: `b995ed15d024566a1cff8da4df0d5ba57a33327002d315aa12422bf8bdebfefd`.

Extraction used `7z` on a MODE1/2048 ISO 9660 image. This disc is not CD-XA;
a generic ISO reader is acceptable here. Full MZ and overlay reports are in
`evidence/target/mz.json` and `evidence/target/ovl.json`. Two identify runs
produced identical JSON.

## XANTH.EXE

- Kind: 16-bit MS-DOS MZ. Not PE.
- Entry: CS:IP `0x1DC1:0x0835`. SS:SP `0x3F95:0x3000`.
- Header: 1888 paragraphs (30208 bytes) holding 5304 relocations at offset
  `0x1E`. Overlay number 0.
- MZ image size: 221864 bytes. Appended tail: 43193 bytes
  (SHA-256 `2a529a64e1be0f7da12fb7729fc5915d2a9dcf239da52bfcd3b4602e6cd910f9`).
- Relocation count and a large header imply an unpacked image; this is not
  PKLITE/EXEPACK-packed.
- Strings inside the file (not inferred from filenames):
  - `[retail bytes removed]` (in the tail)
  - Overlay manager messages (`Cannot find overlay file`, `XANTH.OVL`)
  - `[retail bytes removed]` Version 1.03, copyright 1990-92
  - `Legend Entertainment`, `Companions of Xanth`

## XANTH.OVL

- Not MZ. Treating it as an EXE is a pipeline bug.
- Directory: 62 entries of `{u16 size, u16 segment}` with a unique load
  segment `0x30CB`, terminator `0xFFFF` at offset 248.
- **The directory is not a partition of the payload** (measured 2026-09-19).
  The 62 `size` fields sum to **43,284** against a payload of **325,595**
  bytes (payload starts at file offset 496, after the terminator and a run of
  `00 00 FF FF` padding). Read as paragraphs they give 692,544 — also wrong.
  Taking the sizes as cumulative byte offsets, only 1 of 62 resulting starts
  lands on a `55 8B EC` function prologue; as paragraphs, 2 of 62. So the
  `size` field's meaning is **unknown**, and any model that assumes it slices
  the payload is wrong. `port/src/engine_glue.c` assumed exactly that.
  Resolved by observation (2026-09-20): the port's VM records every read the
  RTLink manager makes on the OVL handle. Sections load at **two or more slot
  segments** (observed `317D:0000` and `32D0:0000`), each section load is
  preceded by short reads of its **relocation records** into a scratch buffer
  in the root image at `1E73:0BAA`, and sections are **re-paged repeatedly**
  rather than kept resident. See `docs/PORT.md` and `tests/test_overlay.py`.
  The directory `size` fields themselves remain unexplained and are not
  needed to run the game.
- Section payloads are plain **uncompressed 8086**: section 0 at file offset
  `0x1F0` begins `55 8B EC 81 EC 18 03 56 57` — a textbook MSC prologue —
  followed by a `9A` far call.
- Credits string `[retail bytes removed]` at offset
  1792. Credits name Michael Lindner, Mark Poesch, and Duane Beck.

**Identity: LOCALLY_SUPPORTED_XANBUD.** Volume label, PVD date, and the two
pinned hashes support this being the budget-CD copy in hand. No independent
authoritative hash match was found. Authenticity against an external media
catalog has not been certified. This limitation stays explicit in
`config/target.json`; no later or floppy executable was substituted.

Data files (`XANTHSTR.DAT`, `OBJECT.DAT`, `.PIC`, `.VOC`, …) are not matching
authority. They are inputs the reconstructed program must consume later.
