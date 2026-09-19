# Test Infrastructure & Methodology Specification
**Companions of Xanth Decompilation & Native Port Project**

## 1. Test Philosophy & Opaque-Box Methodology

The Companions of Xanth test architecture follows a strict, requirements-driven **opaque-box testing methodology**. Rather than testing internal implementation details or tying test assertions to mutable implementation code, tests are anchored strictly to:
1. Documented specifications in `PROJECT.md` and `ORIGINAL_REQUEST.md`.
2. Retail disc images (`XANBUD.iso`), original binaries (`original/XANTH.EXE`, `original/XANTH.OVL`), and asset files (`OBJECT.DAT`, `XANTHSTR.DAT`).
3. Mathematical and hardware specifications: Mode 13h VGA 320x200 8bpp, 6-bit DAC RGB expansion, Nuked OPL3 registers, Steve Baker RealSound 4-bit ADPCM, INT 33h mouse mapping, and BIOS INT 16h keyboard rings.
4. Formal interface contracts between the game engine and the platform abstraction layer (HAL).

### Core Principles
- **Authoritative Expected Output Derivation**: For every test case, the expected output is derived from an explicit authoritative source (reference program/oracle, byte pin hash, hardware standard, or documented relational database).
- **Progressive Testability**: The test suite is self-contained and verifiable during active milestone implementation. Contract validators and reference models verify interface compliance, while direct file assertions automatically validate native binaries and assets as milestones complete.
- **Independence & Isolation**: Every test case initializes its own fixtures, mutates only isolated state or temporary directories, and does not depend on execution order.
- **Fail-Closed Verification**: Binary verification (`verify.py`), dump unit ceilings (`coverage.py`), and checksum gates fail closed on any discrepancy.

---

## 2. 4-Tier Test Architecture

The test suite is structured into four distinct, complementary verification tiers:

```
                                  [Tier 4]
                     Real-World Application Scenarios
                     (Complete Lifecycles & Game Flows)
                                     ^
                                     |
                                  [Tier 3]
                       Cross-Feature Combinations
                    (Pairwise State, Data & Control)
                                     ^
                                     |
                                  [Tier 2]
                         Boundary & Corner Cases
                  (Limits, Extremes, Corrupt Data, Errors)
                                     ^
                                     |
                                  [Tier 1]
                             Feature Coverage
                   (>=5 Happy Path Tests per Feature)
```

### Tier 1 — Feature Coverage (70 Test Cases)
- **Scope**: Every one of the 14 features in `PROJECT.md § Feature Inventory` has at least 5 dedicated, isolated test cases covering its primary functional requirements and representative happy paths.
- **Focus**: Standard valid inputs, schema compliance, hardware mode configurations, and core operational paths.

### Tier 2 — Boundary & Corner Cases (70 Test Cases)
- **Scope**: Every one of the 14 features has at least 5 boundary, limit, and negative test cases.
- **Focus**: Minimum and maximum numerical boundaries (16-bit word limits, 1MB memory walls), 0-length buffers, corrupted headers, single-bit flips, path traversal attempts, and graceful exception handling.

### Tier 3 — Cross-Feature Combinations (10 Test Cases)
- **Scope**: Pairwise and multi-feature interaction tests verifying shared state, data flow, and control flow across subsystem boundaries.
- **Focus**:
  - F1 + F2 + F3: Decompilation census -> ratchet constraints -> whole-program binary equivalence.
  - F5 + F7: Segmented memory bridge -> VGA Mode 13h double buffering (`mn42E4` to `0xA000`).
  - F6 + F7: Asset dictionary -> VGA DAC 256-color palette expansion.
  - F6 + F8: Asset path resolution -> RealSound ADPCM audio streaming.
  - F7 + F9: Mode 13h framebuffer -> INT 33h mouse cursor dirty rect blitting.
  - F6 + F10: `LEGEND.INI` paths -> `GAMEDATA` asset loader & `SAVEDATA` slot persistence.
  - F5 + F9: BIOS data area memory buffer -> INT 16h keyboard queue.
  - F5 + F10: Virtual DOS memory state -> Savegame binary serialization & restore.
  - F7 + F8 + F11: Engine tick pacing (70 Hz) -> Video palette cycling & audio buffer mixing.
  - F4 + F11 + F12: CMake configuration -> Headless flags (`--headless --frames 300`) -> Automation runner.

### Tier 4 — Real-World Application Scenarios (6 Test Cases)
- **Scope**: End-to-end integration scenarios simulating real user and engine lifecycles:
  - **Scenario 1**: Full Cold Boot Sequence (INI parse -> Memory setup -> DB load -> Video/Audio/Input init).
  - **Scenario 2**: Title Screen Presentation & Palette Cycling (Banner render, >20% active pixels, 70 Hz DAC cycling).
  - **Scenario 3**: Intro Scene Animation & Multi-Track Audio Playback (Dialog strings, OPL3 FM music, RealSound effect, VOC voice streaming, 44.1 kHz stereo mix, 300 frames).
  - **Scenario 4**: Mouse Navigation & Interactive Region Hotspots (640x200 to 320x200 transform, hover detection, click dispatch, room transition).
  - **Scenario 5**: Save/Load Slot Persistence & State Recovery (Save slot serialization, CRC32, state mutation, restore, 100% fidelity assertion).
  - **Scenario 6**: Comprehensive Disc Asset Integrity & Structure Verification (MZ executable, 62-section overlay, `OBJECT.DAT`, `XANTHSTR.DAT`, `XANBUD.iso`).

---

## 3. Directory Layout

```
e2e_tests/
├── __init__.py                          # Package initialization
├── run_e2e_tests.py                     # Standalone test runner (reports per-test results & exit code 0)
├── test_runner_common.py                # Reference models, fixtures, and platform abstractions
├── tier1_feature_coverage/              # Tier 1: Feature Coverage (70 tests, 5 per feature)
│   ├── __init__.py
│   ├── test_f01_decomp_units.py         # F1: Decompile remaining dump units
│   ├── test_f02_binary_verify.py        # F2: Binary verification preservation
│   ├── test_f03_ratchet_suite.py        # F3: Fast ratchet test suite
│   ├── test_f04_cmake_build.py          # F4: Native CMake build system
│   ├── test_f05_portable_types.py       # F5: Portable types & memory bridge
│   ├── test_f06_asset_loader.py         # F6: Overlay & asset loader
│   ├── test_f07_vga_render.py           # F7: VGA Mode 13h video rendering
│   ├── test_f08_audio_emulation.py      # F8: Audio subsystem emulation
│   ├── test_f09_input_subsystem.py      # F9: Input subsystem
│   ├── test_f10_save_load.py            # F10: Save/Load state persistence
│   ├── test_f11_engine_loop.py          # F11: Engine loop & headless smoke test
│   ├── test_f12_build_scripts.py        # F12: Automated build & test scripts
│   ├── test_f13_e2e_harness.py          # F13: Opaque-box E2E test suite
│   └── test_f14_hardening.py            # F14: Adversarial coverage hardening
├── tier2_boundaries_corners/            # Tier 2: Boundary & Corner Cases (70 tests, 5 per feature)
│   ├── __init__.py
│   ├── test_f01_boundaries.py
│   ├── test_f02_boundaries.py
│   ├── test_f03_boundaries.py
│   ├── test_f04_boundaries.py
│   ├── test_f05_boundaries.py
│   ├── test_f06_boundaries.py
│   ├── test_f07_boundaries.py
│   ├── test_f08_boundaries.py
│   ├── test_f09_boundaries.py
│   ├── test_f10_boundaries.py
│   ├── test_f11_boundaries.py
│   ├── test_f12_boundaries.py
│   ├── test_f13_boundaries.py
│   └── test_f14_boundaries.py
├── tier3_cross_feature/                 # Tier 3: Pairwise & Cross-Feature Interactions (10 tests)
│   ├── __init__.py
│   └── test_pairwise_interactions.py
└── tier4_application_scenarios/         # Tier 4: Real-World Application Scenarios (6 tests)
    ├── __init__.py
    └── test_real_world_scenarios.py
```

---

## 4. Feature Coverage Matrix

| Feature ID | Feature Name | Tier 1 (Happy) | Tier 2 (Boundary) | Tier 3 (Cross) | Tier 4 (Scenario) | Total Tests | Status |
|:---|:---|:---:|:---:|:---:|:---:|:---:|:---:|
| **F1** | Decompile remaining dump units | 5 | 5 | 1 | 1 | **12** | PASS |
| **F2** | Binary verification preservation | 5 | 5 | 1 | 2 | **13** | PASS |
| **F3** | Fast ratchet test suite | 5 | 5 | 1 | 1 | **12** | PASS |
| **F4** | Native CMake build system | 5 | 5 | 1 | 1 | **12** | PASS |
| **F5** | Portable types & memory bridge | 5 | 5 | 4 | 2 | **16** | PASS |
| **F6** | Overlay & asset loader | 5 | 5 | 3 | 3 | **16** | PASS |
| **F7** | VGA Mode 13h video rendering | 5 | 5 | 4 | 3 | **17** | PASS |
| **F8** | Audio subsystem emulation | 5 | 5 | 3 | 2 | **15** | PASS |
| **F9** | Input subsystem (INT 33h / 16h) | 5 | 5 | 3 | 2 | **15** | PASS |
| **F10** | Save/Load state persistence | 5 | 5 | 3 | 2 | **15** | PASS |
| **F11** | Engine loop & headless smoke test | 5 | 5 | 2 | 2 | **14** | PASS |
| **F12** | Automated build & test scripts | 5 | 5 | 1 | 1 | **12** | PASS |
| **F13** | Opaque-box E2E test suite | 5 | 5 | 1 | 1 | **12** | PASS |
| **F14** | Adversarial coverage hardening | 5 | 5 | 1 | 1 | **12** | PASS |
| **Total** | **All 14 Features** | **70** | **70** | **10** | **6** | **156** | **PASS (100%)** |

---

## 5. Running the Test Suite

```bash
# Run full E2E test suite across all 4 tiers (default)
python3 e2e_tests/run_e2e_tests.py

# Run specific tier only (e.g. Tier 1, 2, 3, or 4)
python3 e2e_tests/run_e2e_tests.py --tier 1
python3 e2e_tests/run_e2e_tests.py --tier 4

# Run with quiet summary output
python3 e2e_tests/run_e2e_tests.py -q
```
