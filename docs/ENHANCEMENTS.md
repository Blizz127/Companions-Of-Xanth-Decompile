# Optional enhancements

The preservation default stays the retail 320×200 VGA presentation, current
AdLib path, mouse/keyboard input, and unmodified guest code. Enhancements are
host-side and opt in through command-line options or an explicitly supplied
`--config <file>`. No enhancement patches the EXE, OVL, game data, or guest
state. With options omitted, the interpreter path and guest inputs are
unchanged.

The retail executable and overlay run in the 16-bit VM. Its DOS/BIOS shims use
our HAL interfaces; SDL2 handles host window presentation, audio output and
input. Display options affect composition in `hal_video`, while the guest
framebuffer and palette remain the VM's source of truth. FluidSynth is a
runtime-selected music backend; the current OPL/AdLib path remains the default.

## Available options

| Enhancement | Opt in | State / limits |
|---|---|---|
| Original aspect correction | Default | Fits the 320×200 DOS image into a 4:3 viewport, with letterbox/pillarbox bars. |
| Pixel integer scaling | `--pixel-perfect` or `pixel_perfect=true` | Uses nearest-neighbour integer scaling with square pixels. The resulting image is 16:10; use `--handheld` for a 1280×800 window on Steam Deck / Legion Go class displays. |
| Fit to display | `--fit` or `fullscreen=true` | Fullscreen desktop, fitted to 4:3. Black bars are retained. |
| Linear filter | `--linear` or `linear_filter=true` | Optional SDL linear texture sampling. Off by default. It softens pixels and is not a pixel-art reconstruction filter. |
| CRT scanlines | `--crt` or `crt=true` | Optional host-side scanline overlay. This is a lightweight overlay, not a programmable CRT shader. |
| Enhanced graphics preset | `--enhanced-graphics` or `enhanced_graphics=true` | Opts into both linear texture sampling and the CRT scanline overlay from the first presented frame. It affects only SDL presentation; the guest framebuffer, logic, and saved screenshots stay unchanged. Off by default. |
| Gamepad | `--controller` or `controller=true` | SDL GameController: left stick moves the pointer, A clicks, X right-clicks, D-pad moves with guest arrow keys, Start presses Enter. Off by default. |
| Host hotkeys | `--hotkeys` or `hotkeys=true` | Opt-in F11 fullscreen toggle and F10 scanline toggle. These host shortcuts are not sent to the guest when enabled. |
| Per-channel volume | `--volume-master`, `--volume-music`, `--volume-sfx`, `--volume-voice` | Each accepts 0–128. Existing defaults are retained when omitted. |
| Mixed audio capture | `--audio-dump <file.wav>` | Optional 44.1 kHz, 16-bit stereo WAV capture of the final SDL mixer output. Disabled by default; the file is written only when requested. |
| General MIDI soundfont | `--soundfont <user.sf2>` or `soundfont=<user.sf2>` | Opt-in FluidSynth runtime backend over the emulated MPU-401 path; selects `MUSIC=mt32` in the save-side LEGEND.INI. Requires a system FluidSynth library and user-supplied SF2. No library, ROM, or soundfont is bundled. The existing AdLib route remains default. |
| Hash-keyed asset mods | `--mods mods` or `mods=mods` | Local replacements are looked up by lowercase SHA-256 of the original asset. Sound and other non-graphics files retain existing mods behavior; graphics and fonts have separate opt-ins. Files in the directory are ignored by Git. |
| Replacement graphics | `--mods mods --replacement-graphics` or `mods=mods` plus `replacement_graphics=true` | Allows hash-keyed `.PIC` and `.RGN` art replacements from the local mods directory. Both switches are required; retail art remains active by default. Replacement files are user supplied and must retain the game's expected format and dimensions. |
| Replacement fonts | `--mods mods --replacement-fonts` or `mods=mods` plus `replacement_fonts=true` | Allows hash-keyed `.FNT` files to be replaced from the local mods directory. Both switches are required; fonts retain their retail files by default. After the game rasterizes a font into VGA pixels, SDL filters cannot change it, so this option replaces the user-supplied font asset before the guest loads it. |

Config files are simple `key=value` text. For example:

```ini
# All options are absent/off unless set here.
scale=3
fullscreen=false
pixel_perfect=false
crt=false
linear_filter=false
enhanced_graphics=false
handheld_1280x800=false
controller=false
hotkeys=false
volume_master=128
volume_music=100
volume_sfx=110
volume_voice=120
# mods=mods
# replacement_fonts=false
# replacement_graphics=false
# soundfont=/path/to/user.sf2
```

The config is only read when supplied with `--config`; command-line options
are applied afterward and override it. An explicitly requested config that
cannot be opened is a startup error. There is no in-game settings menu yet.
`--scale`, `--fullscreen`, `--headless`, and the opt-in switches are also
available on the command line.

## Not implemented / harder changes

- **xBRZ/HQx and programmable CRT shaders:** not included yet. They need a
  reviewed host-side filter implementation and comparisons that show the
  default output remains untouched. The linear sampler and scanline overlay
  are available as narrower opt-in effects.
- **MT-32/Munt emulation:** not implemented. It requires user-supplied ROMs,
  compatible runtime integration, correct MPU-401 message delivery, and
  timing/audio comparison. The current FluidSynth path accepts channel MIDI
  messages over the emulated MPU-401 UART; MT-32 SysEx tone maps and device
  quirks are not reproduced. FluidSynth General MIDI does not reproduce an
  MT-32's patches or quirks.
- **Text-speed control, more save slots, quicksave, and hotkeys:** these need
  hooks into guest timing, save selection, or input behavior. They must be
  implemented through a verified host/guest interface and compared against
  retail defaults; they are not safe to approximate by editing game logic.
- **Handheld verb cursor / touch UI:** the controller currently moves the
  ordinary guest mouse and sends normal clicks. A semantic verb/object cursor
  needs guest UI knowledge or Stage 2 hooks so it can select the game's real
  controls without inventing parser behavior.
- **Widescreen gameplay:** the guest draws fixed 320×200 screens and room art.
  Stretching reveals no additional scene and distorts the image. True widescreen
  needs new scene art or a renderer that can reconstruct the unseen world; it
  is not an exact-preservation toggle.
- **Mods menu, manifests, ordering and event hooks:** asset replacement exists
  as a local hash lookup only. A management UI and general gameplay hooks are
  future work. Every replacement remains user-provided and off by default.

## Preservation verification

Controller regression coverage uses SDL virtual devices, including a silent
Steam virtual pad beside a Lenovo-identified fixture. It checks startup hint
sanitation before SDL initializes, physical input precedence, fallback to an
active virtual pad, hotplug by instance ID, neutral input after reconnect,
shared mouse/button ownership, guest pointer bounds, and keyboard operation
after removal. Physical Deck/Legion testing remains unverified. These input
changes are available only with `--controller`; keyboard/mouse remain default.

The enhancement layer calls the existing SDL2 HAL and does not modify retail
code. The existing VM frame-hash tests remain the gate for game state and
rendered guest output. Host presentation options such as filters affect only
window composition; `--shot` and VM frame hashes are captured before those
filters. Each new option still needs an off/on route check on the same retail
asset set. No broad claim of visual/audio/timing parity should be based only on
matching hashes within the VM; see [`KNOWN_DIVERGENCES.md`](KNOWN_DIVERGENCES.md)
for the remaining DOSBox comparison work.

Focused Linux checks on 2026-09-29 compared default graphics with both the
`--enhanced-graphics` preset and `enhanced_graphics=true`; all opening BMPs had
SHA-256 `f92193b1c9673df2e6e812e00cff51caf703afbfd81eef6d0921b7b936920df3`.
The separate hash-keyed graphics replacement gate was also checked for 120
opening frames using identical user-side copies of `XANTH_00.PIC` and
`XANTH_98.PIC`: default, `--mods` alone, and `--mods ...
--replacement-graphics` all produced that same BMP hash with `fault=ok`.
Tracing showed zero replacement-path PIC opens with `--mods` alone and two
with the graphics opt-in. A config-only `mods=...` plus
`replacement_graphics=true` run also resolved both files from the local hash
directory and ended without a VM fault.
The `walkthrough_01_mundania.xit` opening also produced identical values for
all nine pinned checkpoints with the font toggle off and with it on using
hash-identical copies of `XANTH_13.FNT`, `XANTH_10.FNT`, and `XANTH_01.FNT`.
The DOS trace showed those three files resolving to the local mod hashes only
when `--replacement-fonts` was enabled. Both font runs ended `fault=ok` with a
valid MCB chain. This check covers that opening route only.

The opening picture replacement regression also exercises a visibly changed,
format-preserving local art replacement. It creates temporary hash-keyed
copies of the supplied `.PIC` files with each embedded 6-bit palette inverted,
then replays the opening through the bedroom checkpoint. Retail and
`--mods`-only runs both produce frame hash `ace8f1a3d6b858f2` and BMP SHA-256
`719c68af9d67f6d1b8d146bde9d2877799cd4ef846943f1db72692f6e2bda96e`.
With `--replacement-graphics`, the frame is `dc114d7e201b6081` and the BMP SHA-256
is `e06c402a09f35dea3d1594b9621aaa248a53d61cde1428cdfe40972c2002bfd2`.
All three runs ended `fault=ok` with a valid MCB chain; generated assets and
screenshots stayed under the system temporary directory.

`FontReplacementParityTest` also checks a visibly changed, format-preserving
local `XANTH_10.FNT` replacement at the bedroom checkpoint. The test mirrors
its eight-row glyph bitmaps within their existing advance widths, keeping the
138-byte header/width table and total file size unchanged. This is a diagnostic
sample, not an HD font pack. Retail, `--mods` alone, and
`--mods ... --replacement-graphics` produce frame `ace8f1a3d6b858f2` and BMP
SHA-256 `719c68af9d67f6d1b8d146bde9d2877799cd4ef846943f1db72692f6e2bda96e`.
With `--mods ... --replacement-fonts`, the frame is `0d7b760b986313c2` and the
BMP SHA-256 is
`f410c27ad6decb29bcb576dc5c75680476ee31d6af8fe25cf2ccdd62e8214736`.
The narrative text crop changes, while the bedroom art and verb-panel crops
remain byte-identical. All four runs finish with `fault=ok` and a valid MCB
chain. The generated font and screenshots stay in the system temporary
directory; the original retail font is never overwritten. This checks one
measured font layout and opening checkpoint, not arbitrary replacement fonts
or higher-resolution text rendering.

As of 2026-09-29, a fresh Linux Release build succeeds and all 15 registered
CTest cases pass, including the retail walkthrough/hash suite and VM soak
case. A one-frame BMP from default startup is byte-identical to one captured
with pixel-perfect scaling, CRT scanlines, linear filtering, the handheld
window preset, controller and hotkeys enabled, and changed channel volumes
(SHA-256 `f92193b1c9673df2e6e812e00cff51caf703afbfd81eef6d0921b7b936920df3`).
This confirms those presentation/input/audio controls leave that guest frame
unchanged; the full test suite separately checks established route hashes with
options omitted. These are repeatability results within this VM. No controlled
DOSBox side-by-side comparison has been recorded yet. The native MPU tests
cover reset acknowledgements, channel messages, running status, pitch bend,
and GM reset delivery to a backend; a temporary local FluidSynth API stub
also validated dynamic loading/startup, but no real FluidSynth/SF2 has been
tested.

The HAL viewport calculation is shared by rendering and an asset-free unit
check. On Linux Release, its assertions passed for 1280×800 4:3 fit
(1066×800 centered), 1280×800 integer scale (1280×800), 960×600 integer scale
(960×600), wide 1920×1080 pillarboxing, tall 800×1280 letterboxing, and
invalid zero-width output. This checks host composition geometry only; it does
not alter or establish parity for the guest-rendered scene.

Focused validation on 2026-09-30 against the current Linux Release build passed
`Stage2NativeParityTest`, `Stage2OpeningNativeParityTest` (all nine pinned
opening hashes and VM/native guest metrics), `FontReplacementParityTest`, and
the isolated `exe_103744` and `exe_100016` native fixtures. CPU conformance,
native unit/HAL/audio/DMA stress, and the 600-frame headless boot passed too.
The route tests `Vm_walkthrough_fire`, `Vm_vmplay`, `Vm_contextverbs`,
`Vm_hotspots`, `Vm_overlay`, `Vm_saveload`, `Vm_navigate`, and
`Vm_soundblaster`, plus the three older negative-hook fixtures, passed. In
total, 22 of the 24 registered CTest cases passed across the focused runs.
This is not a full CTest pass: the multi-segment `Vm_walkthrough` case was
interrupted during its cavern segment before the later 22-billion-instruction
save-anchor run, and `Vm_soak` was not run. These results are VM/native parity
checks, not a DOSBox comparison.
