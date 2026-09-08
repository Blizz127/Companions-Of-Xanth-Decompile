# Session handoff

Date: 2026-09-07

## Done

- Compiler identified: Microsoft C/C++ 8.00c (`/c /f- /AL /Gs /Os /Zl`) via a
  controlled Wine compile of `src/pointer.c`
- Overlay scheme: not `INT 3Fh`; 62 `{size, 0x30CB}` slots + 62 reserved
  `FFFF` slots, then 16-bit code
- `tools/rebuild.py` + `tools/verify.py` whole-program BINARY-MATCH for
  `XANTH.EXE` and `XANTH.OVL` (SHA-256 equals `config/target.json` pins)
- `python3 -m unittest discover -s tests -v` — 29 tests

## Not done

- Most recovered code is still 16-bit listing (NASM mnemonics), not C
- `LINK.EXE` is not yet producing the overlay layout; the MZ/OVL image is
  reconstructed from parsed headers plus assembled listings
- `pc-port` does not exist

## Next

Replace listing units with C compiled by CL 8.00c, function by function,
keeping whole-file BINARY-MATCH.
