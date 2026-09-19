# Original User Request

## 2026-09-19T17:39:00Z

Decompile all remaining dump units of the 1993 MS-DOS game *Companions of Xanth* to achieve 100% byte-verified source listings, and implement a native cross-platform port for Linux and Windows 11.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: development

## Requirements

### R1. Complete Decompilation & Binary Verification
Recover all remaining `_emit` dump units into byte-accurate mnemonic Watcom `.asm` listings and high-level C functions. Every recovered unit must integrate cleanly into the repository build pipeline and preserve binary compatibility.

### R2. Native Linux & Windows 11 Cross-Platform Port
Provide a native executable that builds and runs on modern 64-bit Linux and Windows 11 environments without requiring DOSBox or Wine. The port must handle display/VGA rendering, audio playback, keyboard/mouse input, filesystem/CD path resolution, and overlay/resource loading.

### R3. Automated Build and Smoke Testing
Provide clear, automated build configurations and test scripts for both the decompilation verification pipeline and the native port.

## Acceptance Criteria

### Decompilation Recovery
- [ ] Automated gate `python3 tools/verify.py` passes with `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL`.
- [ ] `python3 tools/coverage.py` reports 0 remaining `_emit` dump units.
- [ ] Test suite `python3 -m unittest discover -s tests -p "test_units.py"` passes with 0 failures.

### Native Port (Linux & Windows 11)
- [ ] Native port builds cleanly on modern Linux (GCC/Clang) and Windows 11 (MSVC/MinGW) using an automated build script (e.g. CMake).
- [ ] Game boots to the title screen and intro sequence natively without crashing.
- [ ] In-game graphics, audio/music, mouse navigation, and save/load systems function correctly.
