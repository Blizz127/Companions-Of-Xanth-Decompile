# Companions of Xanth

This in-progress Linux port plays through Fairy Nuff's recipe and shows
122/1000 points. The full game is not completable yet.

## About this project
This is a passion project. I'm working hard on it, but it's made for fun and for everyone's enjoyment — free, non-commercial, and made by a fan. If you enjoy it, that's the whole point.

# How to play

1. Download the Linux x86_64 release asset named
   `xanth-port-v0.1.0-alpha.2-linux-x86_64.tar.gz` from
   [Releases](https://github.com/Blizz127/Companions-Of-Xanth-Decompile/releases/tag/v0.1.0-alpha.2) and extract it
   to `~/Games/companions-of-xanth/port/`. The package contains the port and
   its SDL2 runtime/license, but no game files.
2. Supply files from your own copy: `XANTH.EXE` and the 90 runtime files listed
   in the package's `DATA_FILES.txt`, all directly in one folder. Copy them
   from an original disc or an installation you already own. GOG currently
   lists *Companions of Xanth* in its Dreamlist rather than as a store product,
   so a GOG copy is not presently offered there:
   [GOG Dreamlist](https://www.gog.com/dreamlist/game/companions-of-xanth).
   Put your files in `~/Games/companions-of-xanth/data/`. If the port cannot
   find a valid folder, Linux opens a chooser; a successful selection is
   checked against SHA-256 pins and remembered locally.
3. Double-click the package's `launch.sh`, or run:

   ```sh
   ~/Games/companions-of-xanth/port/launch.sh
   ```

   Pass a different data folder as its first argument, or set `XANTH_DATA`.

Linux requires installed SDL2 (`libSDL2-2.0.so.0`) and glibc 2.34 or newer. The verified Bazzite Alienware already provides SDL2.

## Steam Deck / Game Mode

In Desktop Mode, add `launch.sh` from the extracted package to Steam as a
non-Steam game. Set **Start In** to the package folder and Launch Options to
`/home/deck/Games/companions-of-xanth/data`, then launch it from Game Mode.
This is a native Linux app; leave Steam's Force Compatibility Tool option disabled.

Controllers are detected automatically. The left stick moves the pointer,
A clicks, X right-clicks, D-pad sends guest arrows, Start sends Enter, and Back
opens help. Alpha.2 includes reconnection and Steam/InputPlumber handheld fixes.
Use `--no-controller` or `controller=false` to disable controller input.

A playtest dev menu is on by default for now: F12, or Back+Start on the same
pad, opens it (fast-forward, screenshots, display options; warps need locally
built checkpoints). A lone Back or Start acts on release. While it is on,
fullscreen and CRT scanlines are on its Options page instead of the
`--hotkeys` F10/F11 shortcuts. The game is unchanged while the menu is closed.
Turn it off with `--no-dev-menu`, `dev_menu=0` in the config, or
`XANTH_DEV_MENU=0`; `XANTH_CHEATS=0` disables it completely. See
[docs/DEV_MENU.md](docs/DEV_MENU.md).

Optional settings include `--pixel-perfect`, `--fit`, `--crt`,
`--linear`, `--fullscreen`, `--handheld`, `--hotkeys`, `--soundfont <your.sf2>`,
per-channel `--volume-* N`, and hash-keyed `--mods <directory>` with separate
font/graphics switches. Controller input is automatic; other enhancements are off by default; see
[docs/ENHANCEMENTS.md](docs/ENHANCEMENTS.md).

### Troubleshooting and FAQ

- **Missing files:** choose the directory with `XANTH.EXE` and all 90 runtime
  files directly inside it, not the parent disc folder.
- **Hash mismatch:** the files are incomplete or from another release. This
  port currently accepts only the pinned XANBUD set; see the package's
  `DATA_FILES.txt` and select a matching installation.
- **No folder chooser:** install `kdialog` (KDE) or `zenity` (GNOME), or run
  `launch.sh /path/to/game-data` from a terminal.
- **Can I finish the game?** Not yet. The tested route reaches Fairy Nuff's
  recipe (122/1000); later regions and the ending are incomplete.

---

# Companions of Xanth - Byte-Verified Decompilation & Native Port

*Companions of Xanth* is being reconstructed from the locally supported XANBUD
release. The EXE and OVL rebuild have documented byte-match evidence; that does
not establish that every function has semantic source or that the port is 1:1.
The native port is in progress on Linux, with the Windows MSVC build currently failing its CI gate. See [known divergences](docs/KNOWN_DIVERGENCES.md) before treating
any behavior or platform as complete. Retail game assets are required.

`tools/verify.py` reports whole-program BINARY-MATCH for this disc’s
`XANTH.EXE` and `XANTH.OVL`. The source index has 2,844 units and currently
contains 0 raw `_emit` dump units. Its measured kinds are 442 unaided-C, 959
mnemonic assembly, 528 Watcom assembly, and 915 transcribed-data units. These
figures describe the source index; they are not a semantic function-completion
percentage.

The port executes the supplied retail EXE/OVL in its own VM, with a growing
set of source-backed native hooks, including partial paths. Most guest code
remains interpreted. Whole-image BINARY-MATCH is a separate
decompilation/rebuild measure; see [the current port handoff](docs/PORT.md).

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
- [Known divergences](docs/KNOWN_DIVERGENCES.md)
- [License notes](LICENSE-NOTES.md)

---

## Native Cross-Platform Port (in progress)

Experimental release packages contain the port and documentation only.
Supply your own matching game files with `--data`. See
[release setup instructions](releases/GETTING_STARTED.txt) and
[prerelease notes](releases/v0.1.0-alpha.2.md) for requirements and limits.

**Status: verified routes extend into the Region of Fire, including charcoal
collection. The full 1,000-point finale remains unverified.** The port executes the retail `XANTH.EXE` under its own 16-bit CPU and
DOS/BIOS layer. A scripted walkthrough plays Mundania, the cavern, the Isthmus
catapult, and the eye screen. At Fairy Nuff's booth the game's own status
panel reads **122 of 1000**, with the recipe in inventory. There is no
reimplemented game logic.

### What works today

- Boots the retail image: RTLink pages its own overlays, the game loads its own
  databases, art, fonts and music.
- VGA mode 13h with the game's own palette fades and the animated intro cutscene.
- Mouse and keyboard: hover highlights object names, verb-then-object clicks produce
  real parser output from `XANTHSTR.DAT`.
- AdLib music.
- Multi-room navigation via the compass.
- Save and restore through the game's own system menu, verified **byte-exact**: save,
  change the world, restore, save again, and the two save files differ only in the
  name field.
- Deterministic input traces with frame-hash checkpoints (`tests/traces/*.xit`), plus
  a soak that runs ~1.5 billion instructions of play with no faults.
- **Mundania, the cavern, the catapult, and Fairy Nuff.** Nine walkthrough
  segments: the opening chapter, Nada, the cavern, the village key, the log
  jam, the catapult, the pail, the eye screen, and Fairy Nuff's recipe. The
  status panel at his booth reads 122/1000. All of that is retail code.

Digitized sound follows `MUSIC=` in `LEGEND.INI`. `real` plays RealSound
effects (the kitchen phone opens `PHONE.RS` and 44,159 samples reach the
mixer). `blaster` also streams `XANTH_01.VOC` through DMA. `adlib`, the
default the golden frames were recorded against, plays music only.

Not yet: mixing Fairy Nuff's solution and dousing the censor-ship, then the
Void and the regions through the 1,000-point ending.

### What was replaced, and why

`port/src/engine_glue.c` was a hand-written text adventure — three hardcoded rooms with
hand-typed narration — that loaded `XANTH.OVL` and never executed a byte of it. That is
exactly what [`CONSTRAINTS.md`](CONSTRAINTS.md) forbids. An earlier audit called it
complete against a written criterion of "boots to the title screen"; its own caveats
record that no playthrough was attempted. Its overlay model was also wrong: it read the
62 directory `size` fields as a byte partition of the payload, but they sum to 43,284
against a 325,595-byte payload. `xanth_port` no longer links it.

### Where it is going

A two-stage rebuild, derived from the matched source rather than reimplemented:

- **Stage 1 — run the retail code.** A 16-bit x86 core plus DOS/BIOS/mouse shims execute
  the real `XANTH.EXE` against the existing SDL2 HAL. The RTLink/Plus overlay manager is
  ordinary 8086 code inside the EXE, so it pages its own overlays through faithful
  `INT 21h` file I/O — no overlay logic is reimplemented. The Mode 13h framebuffer is
  already mapped at `g_dos_mem + 0xA0000`, so guest VGA writes need no translation.
- **Stage 2 — statically recompile.** Retail bytes are decoded to portable C against the
  same HAL, function by function, each validated by co-simulation against the interpreter,
  until the interpreter is no longer linked into the release build.

`CONSTRAINTS.md` carries the precise definition of "100%" for the port and the ratchets
that enforce it.

### Building

Prerequisites: `cmake`, `gcc` or `clang`, `libsdl2-dev`.

```bash
./scripts/build_port.sh                                   # build
ctest --test-dir build                                    # tests
./build/xanth_port --data game_cd/XANTH --saves build/saves
```

Escape quits; `--scale N` sets the window size. See [docs/PORT.md](docs/PORT.md) for the
architecture, the input-trace format, and the current milestone state.

Hash-keyed asset replacements are opt-in: pass `--mods mods` and place each
replacement at `mods/<lowercase SHA-256 of the original asset>`. With no
`--mods` argument the replacement lookup is disabled. Cheats and a persistent
user configuration are not implemented yet.

Windows 11 (MSVC or MinGW):

```cmd
cmake -B build -S port
cmake --build build --config Release
```

Note that the Windows build has so far only been verified by static inspection, not
compiled and run. Wiring it to a CI runner that actually executes it is part of the port
work.

### Supplying Game Assets

**No copyrighted game assets, data files, or proprietary binaries are in this repository.**

Supply the runtime files from the locally supported XANBUD release in
`game_cd/XANTH/`, or point `--data` at their directory:

```bash
./build/xanth_port --data /path/to/game_assets
```

Before startup, the port checks `XANTH.EXE` and the 90 runtime files against
the recorded SHA-256 pins. Missing or changed files stop startup with a clear
message; supply the matching files with `--data`. The installer and its setup
lists are not needed at runtime. Game assets remain on your machine and are
not distributed with this project.

## Decompilation Verification

```sh
python3 tools/coverage.py                 # reports 0 remaining dump units
python3 -m unittest discover -s tests -v  # runs decompilation unit tests
python3 tools/verify.py                   # whole-program byte-accurate verification
```

Verification requires the legally supplied disc described in the target notes. Extracted payloads remain local and ignored. No license is asserted over Legend Entertainment, SSI, or related materials.
