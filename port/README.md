# Companions of Xanth Native Port (Linux & Windows 11)

This directory contains the standalone native 64-bit C11 port of Legend Entertainment's 1993 graphic adventure *Companions of Xanth*.

## Highlights

- **Direct Native Execution**: Runs directly on modern x86_64 Linux and Windows 11 without DOSBox, Wine, or 16-bit emulation.
- **VGA Mode 13h Emulation**: 320x200 8-bit indexed color with real-time 256-color DAC palette cycling (water and magical effects in registers 240..255).
- **Original Asset Parsers**:
  - Full `.PIC` archive decompressor powered by Mark Adler's PKWare DCL `blast` algorithm (`src/blast.c`, `src/pic_loader.c`).
  - Full Huffman + 128-entry shorthand dictionary story database decompressor for `XANTHSTR.DAT` (`src/story_loader.c`).
  - Overlay consolidation manager for `XANTH.OVL` (`src/engine_glue.c`).
- **Sound & Music Architecture**:
  - Nuked OPL3 FM synthesis emulation.
  - Steve Baker RealSound (`.RS`) 4-bit ADPCM decoder for authentic sound effects.
  - Sound Blaster voice archive (`.VOC`) support.
  - Low-latency 3-channel mixer (Music, SFX, Voice) generating 44,100 Hz 16-bit stereo.
- **Classic 3-Panel Adventure Interface**:
  - 264x122 graphic viewport with interactive hotspots.
  - Directional compass with dynamic highlighted exits.
  - Verbs: `LOOK`, `TAKE`, `TALK`, `CAST`, `INV`, `EXAM`, `USE`.
  - Non-truncating word-wrapped narrative pane with live prompt `> _`.
- **Multi-Room Mundania Exploration**:
  - Room 1: Bedroom & Computer Desk (`XANTH_02.PIC` #0)
  - Room 2: Front Hall & Foyer with Beethoven portrait (`XANTH_02.PIC` #41)
  - Room 3: Kitchen with yellow refrigerator and phone (`XANTH_02.PIC` #68)

## Quick Start

### Linux
```bash
# Build
cmake -B ../build -S .
cmake --build ../build -j$(nproc)

# Run tests
ctest --test-dir ../build

# Play
../build/xanth_port
```

### Windows 11
```cmd
cmake -B build -S port
cmake --build build --config Release
cd build\Release
xanth_port.exe
```

## CLI Options

```
Usage: xanth_port [options]

  --data <path>       Specify directory containing game assets (default: auto-discovery)
  --saves <path>      Specify directory for save game files
  --headless          Run in headless mode (no SDL window or audio output)
  --frames <N>        Execute exactly N frames and exit
  --nocycle           Disable VGA DAC palette cycling
  --xmouse            Enable alternative INT 33h mouse handling
  --test-boot         Run boot validation suite
  -h, --help          Show help message
```

## Copyright Notice

**No copyrighted game data, art files, sound samples, or binaries are included.**
Please supply your own legally acquired game files (`XANTH_*.PIC`, `XANTHSTR.DAT`, `OBJECT.DAT`, etc.) in `game_cd/XANTH/` or `original/` or via `--data`.
