# Companions of Xanth - Byte-Verified Decompilation & Native Port

Old 1993 game *Companions of Xanth* decompiled byte for byte, with a native modern 64-bit cross-platform port for modern Linux (including Bazzite, Fedora, Ubuntu, Arch) and Windows 11. Retail game assets are required.

`tools/verify.py` reports whole-program BINARY-MATCH for this disc’s
`XANTH.EXE` and `XANTH.OVL`. All 2,844 source units have been recovered (0 remaining byte dump units).

The retail executable and overlay are authority. Preserve behavior, bugs,
layouts, overlay placement, and calling conventions. A modern port must be
derived from this decompilation and must not become a replacement
implementation. No game data or proprietary toolchain artifacts belong in Git.

- [Intent](docs/intent/matching-decomp.md)
- [Constraints](CONSTRAINTS.md) — the written bar; do not weaken it to make a change pass
- [Capability map](CAPABILITY-MAP.md)
- [Target and provenance](docs/TARGET.md)
- [Reproduction](docs/REPRODUCE.md)
- [Matching definitions](docs/MATCHING.md)
- [Toolchain evidence](docs/TOOLCHAIN.md)
- [Session handoff](docs/STATUS.md)
- [License notes](LICENSE-NOTES.md)

---

## Native Cross-Platform Port (Linux & Windows 11)

A complete native 64-bit C11 port of *Companions of Xanth* is available in the [`port/`](port/) directory. It runs natively without requiring DOSBox, Wine, or 16-bit real-mode emulation.

### Features

- **Pure C11 / Modern Architecture**: Clean cross-platform codebase compiling with GCC, Clang, MSVC, and MinGW.
- **VGA Display Pipeline**: SDL2 Mode 13h (320x200 8bpp indexed color surface) with dynamic 256-color DAC palette cycling (registers 240..255).
- **Asset Decompression Engine**:
  - Full `.PIC` archive loader parsing 12-byte headers and decompressing images with Mark Adler's PKWare DCL `blast` decompressor.
  - Story text database (`XANTHSTR.DAT`) decoding all 80 segments and 5,542 strings using Legend's custom Huffman bitstream and 128-entry shorthand dictionary.
  - Overlay consolidation (`XANTH.OVL`) managing all 62 overlay sections across 325,595 bytes of flat RAM.
- **Audio Subsystem**:
  - Nuked OPL3 FM synthesizer model.
  - Steve Baker RealSound (`.RS`) 4-bit ADPCM decoder for original sound effects.
  - Sound Blaster speech archive (`.VOC`) playback.
  - Real-time 3-channel audio mixer (Music, SFX, Voice) outputting 44,100 Hz 16-bit stereo.
- **Interactive Gameplay & Multi-Room Navigation**:
  - Explore Mundania: Dug's Bedroom & Computer Desk, Front Hall & Foyer, and Kitchen.
  - Interactive compass navigation, verb buttons, and word-wrapped narrative story terminal with live command prompt.
- **Self-Locating Asset Discovery**: Automatically resolves game files relative to the executable path (`/proc/self/exe` on Linux, `GetModuleFileNameA` on Windows), `game_cd/XANTH/`, `original/`, or via the `XANTH_DATA` environment variable.

### Building the Native Port

#### Linux (GCC / Clang)

Prerequisites: `cmake`, `gcc` or `clang`, `libsdl2-dev`.

```bash
# Build the native executable and test harness
./scripts/build_port.sh

# Run test suite
ctest --test-dir build

# Launch the game
./build/xanth_port
```

#### Windows 11 (MSVC or MinGW)

Prerequisites: CMake 3.16+, Visual Studio 2022 (MSVC) or MinGW-w64, SDL2 development libraries.

```cmd
cmake -B build -S port
cmake --build build --config Release
cd build\Release
xanth_port.exe
```

### Supplying Game Assets

**Note: No copyrighted game assets, data files, or proprietary binaries are included in this repository.**

To run the port or verify decompilation, supply the original retail files from your legally owned CD or floppy release:
1. Place the game files in `game_cd/XANTH/` or `original/`, or specify the path at runtime:
   ```bash
   ./build/xanth_port --data /path/to/game_assets
   ```
2. Required files for full presentation:
   - `XANTH_98.PIC` (Legend logo splash)
   - `XANTH_99.PIC` (Title banner)
   - `XANTH_94.PIC`, `XANTH_91.PIC` (Cutscenes)
   - `XANTH_02.PIC` (Mundania rooms)
   - `XANTHSTR.DAT` (Story text database)
   - `OBJECT.DAT` (Object relational strings)
   - Sound effects (`THUNDER.RS`, `MAIL.RS`, `PHONE.RS`, `DOORBELL.RS`, `FRIDGE.RS`, etc.)

---

## Decompilation Verification

```sh
python3 tools/coverage.py                 # reports 0 remaining dump units
python3 -m unittest discover -s tests -v  # runs decompilation unit tests
python3 tools/verify.py                   # whole-program byte-accurate verification
```

Verification requires the legally supplied disc described in the target notes. Extracted payloads remain local and ignored. No license is asserted over Legend Entertainment, SSI, or related materials.
