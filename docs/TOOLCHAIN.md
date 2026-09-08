# Toolchain evidence

Inspected on 2026-09-07 from the pinned `XANTH.EXE` / `XANTH.OVL` only.

## Compiler hypothesis

The MZ tail contains `MS Run-Time Library - Copyright (c) 1992, Microsoft Corp`.
That string is a **candidate** for Microsoft C/C++ 7.0 or 16-bit Visual C++ 1.x,
not a proven exact compiler build. Header linker version is not present the
way a PE optional header would record it.

Overlay manager strings (`Cannot find overlay file "`, `XANTH.OVL`, reload
stack overflow/underflow) sit in the MZ image. They are evidence of an overlay
runtime, not yet of a specific linker (`LINK`, Blinker, or a Legend stub).

PKWARE Data Compression Library 1.03 is linked into the EXE. That is a
compression library, not an executable packer. The 5304-entry relocation
table is independent evidence the EXE is not PKLITE/EXEPACK-packed.

No historical compiler was provisioned or run. The exact compiler build,
flags, CRT object set, and overlay linker remain UNKNOWN. A modern compiler
producing similar bytes would not identify the original toolchain.

## First experiment

None. This session pins identity only. Compiler-identification experiments
belong to module `compiler-id`.
