# Optional enhancements

The preservation default stays the retail 320×200 VGA presentation, current
AdLib path, mouse/keyboard input, and unmodified guest code. Enhancements are
host-side and opt in through command-line options or an explicitly supplied
`--config <file>`. No enhancement patches the EXE, OVL, game data, or guest
state. With options omitted, the interpreter path and guest inputs are
unchanged.

## Available options

| Enhancement | Opt in | State / limits |
|---|---|---|
| Original aspect correction | Default | Fits the 320×200 DOS image into a 4:3 viewport, with letterbox/pillarbox bars. |
| Pixel integer scaling | `--pixel-perfect` or `pixel_perfect=true` | Uses nearest-neighbour integer scaling with square pixels. The resulting image is 16:10; use `--handheld` for a 1280×800 window on Steam Deck / Legion Go class displays. |
| Fit to display | `--fit` or `fullscreen=true` | Fullscreen desktop, fitted to 4:3. Black bars are retained. |
| Linear filter | `--linear` or `linear_filter=true` | Optional SDL linear texture sampling. Off by default. It softens pixels and is not a pixel-art reconstruction filter. |
| CRT scanlines | `--crt` or `crt=true` | Optional host-side scanline overlay. This is a lightweight overlay, not a programmable CRT shader. |
| Gamepad | `--controller` or `controller=true` | SDL GameController: left stick moves the pointer, A clicks, X right-clicks, D-pad moves with guest arrow keys, Start presses Enter. Off by default. |
| Host hotkeys | `--hotkeys` or `hotkeys=true` | Opt-in F11 fullscreen toggle and F10 scanline toggle. These host shortcuts are not sent to the guest when enabled. |
| Per-channel volume | `--volume-master`, `--volume-music`, `--volume-sfx`, `--volume-voice` | Each accepts 0–128. Existing defaults are retained when omitted. |
| General MIDI soundfont | `--soundfont <user.sf2>` or `soundfont=<user.sf2>` | Opt-in FluidSynth runtime backend; requires a system FluidSynth library and user-supplied SF2. No library, ROM, or soundfont is bundled. The existing AdLib route remains default. |
| Hash-keyed asset mods | `--mods mods` or `mods=mods` | Local replacements in `mods/` are looked up by lowercase SHA-256 of the original asset. No replacement is active unless explicitly configured; files in the directory are ignored by Git. |

Config files are simple `key=value` text. For example:

```ini
# All options are absent/off unless set here.
scale=3
fullscreen=false
pixel_perfect=false
crt=false
linear_filter=false
handheld_1280x800=false
controller=false
hotkeys=false
volume_master=128
volume_music=100
volume_sfx=110
volume_voice=120
# mods=mods
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
  timing/audio comparison. FluidSynth General MIDI does not reproduce an
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

The enhancement layer calls the existing SDL2 HAL and does not modify retail
code. The existing VM frame-hash tests remain the gate for game state and
rendered guest output. Host presentation options such as filters affect only
window composition; `--shot` and VM frame hashes are captured before those
filters. Each new option still needs an off/on route check on the same retail
asset set. No broad claim of visual/audio/timing parity should be based only on
matching hashes within the VM; see [`KNOWN_DIVERGENCES.md`](KNOWN_DIVERGENCES.md)
for the remaining DOSBox comparison work.
