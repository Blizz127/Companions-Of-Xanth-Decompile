# Session handoff

Date: 2026-09-07

## Done

Module `target-pin` is in place:

- ISO `XANBUD.iso` registered and hash-pinned
- `XANTH.EXE` identified as unpacked 16-bit MZ with overlay manager + 1992
  Microsoft CRT string + PKWARE DCL 1.03
- `XANTH.OVL` identified as a 62-entry Legend overlay (not MZ), load segment
  `0x30CB`
- `python3 -m unittest discover -s tests -v` — 22 tests
- `python3 tools/verify.py` — ISO, EXE, OVL VERIFIED; compiler UNKNOWN

## Not done

- Compiler identity remains UNKNOWN
- No function has been decompiled
- No matching compiler has been run
- `pc-port` does not exist and must not start as a replacement engine

## Next

Module `compiler-id`: gather overlay-linker and code-generation fingerprints
from the pinned EXE, then try historical Microsoft 16-bit toolchains against
a tiny reconstructed unit. Do not name a compiler in source until
`docs/TOOLCHAIN.md` records a controlled experiment.
