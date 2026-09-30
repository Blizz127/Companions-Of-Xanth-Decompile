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

## 2026-09-20T19:00:11Z

Complete the 100% native cross-platform port and full-game walkthrough verification of Companions of Xanth (1993) based on the byte-accurate execution architecture, passing all test gates and published-route playthroughs.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: development

## Requirements

### R1. Digitized Audio & Sound Blaster DMA Pipeline
Implement digitized audio streaming for Sound Blaster (.VOC speech, RealSound .RS SFX, and DMA transfer mechanics) in the port VM and audio HAL, ensuring voice lines and sound effects play seamlessly alongside AdLib/OPL3 music.

### R2. End-to-End Walkthrough Trace Suite
Expand deterministic input traces (`tests/traces/`) covering all chapters and segments of the published game walkthrough through to the finale, pinning reproducible checkpoints and validating story flags, inventory handling, and score increments.

### R3. Cross-Platform Build & Verification Standards
Maintain zero compilation warnings/errors across GCC/Clang on 64-bit Linux and MSVC on Windows 11. Preserve 100% binary matching on the decompilation (`tools/verify.py` producing `BINARY-MATCH`) and ensure the entire test suite passes reliably.

## Verification Resources
- Build script: `./scripts/build_port.sh` (or `cmake --build build`)
- CTest runner: `ctest --test-dir build --output-on-failure`
- Decompilation verification: `python3 tools/verify.py` and `python3 -m unittest discover -s tests -p "test_units.py"`
- Deterministic trace runner: `./build/tool_vmboot --script <trace_file>.xit`
- Test suite files: `tests/test_*.py`, `port/tests/test_*.c`

## Acceptance Criteria

### Audio & VM Subsystems
- [ ] Sound Blaster digitized audio (.VOC / .RS) triggers and streams via virtual DMA during scripted story and audio events
- [ ] Audio HAL callback handles concurrent OPL3 music synthesis and digitized audio playback without starvation or artifacts

### Gameplay & Walkthrough Verification
- [ ] All walkthrough segments execute to the endgame sequence, verifying companion logic and total score progression
- [ ] Checkpoint hashes are deterministic and reproducible across repeated runs

### Build & Test Health
- [ ] All CTest suites pass cleanly (including `CpuConformanceTests`, `NativeUnitTests`, `HeadlessBootSmokeTest`, and VM trace tests)
- [ ] Whole-image decompilation rebuild maintains `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL`
- [ ] Zero build warnings/errors on Linux GCC/Clang and Windows MSVC

## 2026-09-21T00:56:48Z

Complete the 100% native cross-platform port and full-game walkthrough verification of Companions of Xanth (1993) based on the byte-accurate execution architecture, passing all test gates and published-route playthroughs.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: development

## Requirements

### R1. Digitized Audio & Sound Blaster DMA Pipeline
Implement digitized audio streaming for Sound Blaster (.VOC speech, RealSound .RS SFX, and DMA transfer mechanics) in the port VM and audio HAL, ensuring voice lines and sound effects play seamlessly alongside AdLib/OPL3 music.

### R2. End-to-End Walkthrough Trace Suite
Expand deterministic input traces (`tests/traces/`) covering all chapters and segments of the published game walkthrough through to the finale, pinning reproducible checkpoints and validating story flags, inventory handling, companion logic, and total score progression.

### R3. Cross-Platform Build & Verification Standards
Maintain zero compilation warnings/errors across GCC/Clang on 64-bit Linux and MSVC on Windows 11. Preserve 100% binary matching on the decompilation (`tools/verify.py` producing `BINARY-MATCH`) and ensure the entire test suite passes reliably.

## Verification Resources
- Build script: `./scripts/build_port.sh` (or `cmake --build build`)
- CTest runner: `ctest --test-dir build --output-on-failure`
- Decompilation verification: `python3 tools/verify.py` and `python3 -m unittest discover -s tests -p "test_units.py"`
- Deterministic trace runner: `./build/tool_vmboot --script <trace_file>.xit`
- Test suite files: `tests/test_*.py`, `port/tests/test_*.c`

## Acceptance Criteria

### Audio & VM Subsystems
- [ ] Sound Blaster digitized audio (.VOC / .RS) triggers and streams via virtual DMA during scripted story and audio events
- [ ] Audio HAL callback handles concurrent OPL3 music synthesis and digitized audio playback without starvation or artifacts

### Gameplay & Walkthrough Verification
- [ ] All walkthrough segments execute to the endgame sequence, verifying companion logic and total score progression
- [ ] Checkpoint hashes are deterministic and reproducible across repeated runs

### Build & Test Health
- [ ] All CTest suites pass cleanly (including `CpuConformanceTests`, `NativeUnitTests`, `HeadlessBootSmokeTest`, and VM trace tests)
- [ ] Whole-image decompilation rebuild maintains `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL`
- [ ] Zero build warnings/errors on Linux GCC/Clang and Windows MSVC


## 2026-09-21T03:29:18Z

Complete the 100% native cross-platform port and full-game walkthrough verification of Companions of Xanth (1993) based on the byte-accurate execution architecture, passing all test gates and published-route playthroughs through to the 1,000 points endgame.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: benchmark

## Requirements

### R1. Digitized Audio & Sound Blaster DMA Pipeline
Implement digitized audio streaming for Sound Blaster (.VOC speech, RealSound .RS SFX, and DMA transfer mechanics) in the port VM and audio HAL, ensuring voice lines and sound effects play seamlessly alongside AdLib/OPL3 music.

### R2. End-to-End Walkthrough Trace Suite
Expand deterministic input traces (`tests/traces/`) covering all chapters and segments of the published game walkthrough through to the finale (Scenes II through XII), pinning reproducible checkpoints and validating story flags, inventory handling, companion logic, and total score progression (1,000 points).

### R3. Cross-Platform Build & Verification Standards
Maintain zero compilation warnings/errors across GCC/Clang on 64-bit Linux and MSVC on Windows 11. Preserve 100% binary matching on the decompilation (`tools/verify.py` producing `BINARY-MATCH`) and ensure the entire test suite passes reliably.

## Verification Resources
- Build script: `./scripts/build_port.sh` (or `cmake --build build`)
- CTest runner: `ctest --test-dir build --output-on-failure`
- Decompilation verification: `python3 tools/verify.py` and `python3 -m unittest discover -s tests -p "test_units.py"`
- Deterministic trace runner: `./build/tool_vmboot --script <trace_file>.xit`
- Test suite files: `tests/test_*.py`, `port/tests/test_*.c`

## Acceptance Criteria

### Audio & VM Subsystems
- [ ] Sound Blaster digitized audio (.VOC / .RS) triggers and streams via virtual DMA during scripted story and audio events
- [ ] Audio HAL callback handles concurrent OPL3 music synthesis and digitized audio playback without starvation or artifacts

### Gameplay & Walkthrough Verification
- [ ] All walkthrough segments execute to the endgame sequence, verifying companion logic and total score progression to 1,000 points
- [ ] Checkpoint hashes are deterministic and reproducible across repeated runs

### Build & Test Health
- [ ] All CTest suites pass cleanly (including `CpuConformanceTests`, `NativeUnitTests`, `HeadlessBootSmokeTest`, and VM trace tests)
- [ ] Whole-image decompilation rebuild maintains `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL`
- [ ] Zero build warnings/errors on Linux GCC/Clang and Windows MSVC

## 2026-09-23T00:18:18Z

Complete the 100% native cross-platform port and full-game walkthrough verification of Companions of Xanth (1993) based on the byte-accurate execution architecture, ensuring all subsystems are completely ported, fully accurate to retail, and verified through to the 1,000-point endgame.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: development

## Requirements

### R1. Digitized Audio & Sound Blaster DMA Pipeline
Implement and verify digitized audio streaming for Sound Blaster (.VOC speech, RealSound .RS SFX, and DMA transfer mechanics) in the port VM and audio HAL, ensuring voice lines and sound effects play seamlessly alongside AdLib/OPL3 music without audio buffer underruns, starvation, or desynchronization.

### R2. Complete Native Game Walkthrough & Retail Accuracy Verification
Execute and verify the full game walkthrough across all chapters and scenes (Scenes I through XII) through deterministic input traces, verifying that companion logic, hotspot interactions, inventory puzzles, dialog trees, save/load states, and score progression to the 1,000-point finale execute with 100% fidelity to the retail MS-DOS game.

### R3. Cross-Platform Build & Verification Standards
Maintain zero compilation warnings/errors across GCC/Clang on 64-bit Linux and MSVC on Windows 11. Preserve 100% binary matching on the decompilation (`tools/verify.py` producing `BINARY-MATCH`) and ensure the entire CTest / Python test suites pass reliably.

## Verification Resources
- Build script: `./scripts/build_port.sh` (or `cmake --build build`)
- CTest runner: `ctest --test-dir build --output-on-failure`
- Decompilation verification: `python3 tools/verify.py` and `python3 -m unittest discover -s tests -p "test_units.py"`
- Deterministic trace runner: `./build/tool_vmboot --script <trace_file>.xit`
- Test suite files: `tests/test_*.py`, `port/tests/test_*.c`

## Acceptance Criteria

### Audio & VM Subsystems
- [ ] Sound Blaster digitized audio (.VOC / .RS) triggers and streams via virtual DMA during scripted story and audio events
- [ ] Audio HAL callback handles concurrent OPL3 music synthesis and digitized audio playback without starvation or artifacts

### Gameplay & Retail Accuracy Verification
- [ ] Complete walkthrough traces execute to the 1,000-point endgame sequence without hangs, crashes, or unhandled VM traps
- [ ] Story flags, inventory handling, companion choices, and save/load round-trips match retail behavior
- [ ] Checkpoint hashes are deterministic and reproducible across repeated runs

### Build & Test Health
- [ ] All CTest suites pass cleanly (including `CpuConformanceTests`, `NativeUnitTests`, `HeadlessBootSmokeTest`, and VM trace tests)
- [ ] Whole-image decompilation rebuild maintains `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL`
- [ ] Zero build warnings/errors on Linux GCC/Clang and Windows MSVC

## User instruction update:
"make sure to use the decomp files here"
Please ensure all work directly uses the decomp files located in the repository at `/var/home/blizz/Projects/Companions of Xanth decomp` (including existing recovered C units, disassembly listings in `config/c-units.json`, `original/` binaries, and `port/` native infrastructure).


## 2026-09-27T04:59:41Z

Complete the native cross-platform port and full-game walkthrough verification of Companions of Xanth (1993) based on the byte-accurate execution architecture, passing all test gates and published-route playthroughs through to the 1,000-point endgame.

Working directory: /var/home/blizz/Projects/Companions of Xanth decomp
Integrity mode: development

## Requirements

### R1. Digitized Audio & Sound Blaster DMA Pipeline
Implement and preserve digitized audio streaming for Sound Blaster (.VOC speech, RealSound .RS SFX, and DMA transfer mechanics) in the port VM and audio HAL, ensuring seamless concurrent playback with AdLib/OPL3 music.

### R2. End-to-End Walkthrough Trace Suite & Retail Accuracy
Expand deterministic input traces (`tests/traces/`) covering all chapters and scenes of the published walkthrough (Scenes I through XII) through to the 1,000-point endgame, pinning reproducible 64-bit FNV-1a frame hashes and verifying story flags, inventory handling, companion logic, and score increments.

### R3. Cross-Platform Build & Verification Standards
Maintain zero compilation warnings/errors across GCC/Clang on 64-bit Linux and MSVC on Windows 11. Preserve 100% binary matching on the decompilation (`tools/verify.py` producing `BINARY-MATCH` for `XANTH.EXE` and `XANTH.OVL`) and ensure all CTest and Python test suites pass cleanly.

## Acceptance Criteria

### Audio & VM Subsystems
- [ ] Sound Blaster digitized audio (.VOC / .RS) triggers and streams via virtual DMA during scripted story and audio events.
- [ ] Audio HAL callback handles concurrent OPL3 music synthesis and digitized audio playback without starvation or artifacts.

### Gameplay & Walkthrough Verification
- [ ] Walkthrough traces execute to the 1,000-point endgame sequence across all scenes (Scenes I through XII).
- [ ] Checkpoint hashes are deterministic and reproducible across repeated runs.
- [ ] Multi-anchor save test suite passes cleanly in `tests/test_walkthrough.py`.

### Build & Test Health
- [ ] All CTest suites pass cleanly (`ctest --test-dir build --output-on-failure`).
- [ ] Whole-image decompilation rebuild maintains `BINARY-MATCH` for both `XANTH.EXE` and `XANTH.OVL` via `python3 tools/verify.py`.
- [ ] `python3 -m unittest discover -s tests -p "test_units.py"` passes 10/10 OK.
