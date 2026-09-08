# Capability Map: Companions of Xanth matching decomp

| Module id | Responsibility | Depends on |
|---|---|---|
| target-pin | Register the XANBUD disc, pin ISO/EXE/OVL hashes, record MZ and overlay identity | — |
| compiler-id | Identify the original compiler, linker, CRT, and overlay scheme | target-pin |
| matching-pipeline | Compile a unit with the historical toolchain and diff it against retail | compiler-id |
| function-decomp | Recover functions to BINARY-MATCH | matching-pipeline |
| pc-port | Modern port derived from matched source; never a replacement implementation | function-decomp |

Build order: target-pin → compiler-id → matching-pipeline → function-decomp → pc-port
