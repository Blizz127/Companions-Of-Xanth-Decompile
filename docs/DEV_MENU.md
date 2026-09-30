# Native dev menu work

The alpha release does not contain a dev menu. The shared implementation
contract is `~/release-staging/port-dev-menu/DEV_MENU_SPEC.md` (v1,
2026-09-30). The owner additionally requires Xanth checkpoints to use the
game's own save/restore path, with no host memory pokes.

The requested keyboard map is F8 menu, F11 quick save, F12 quick load,
F9 video recording, F10 screenshot, and held Backspace fast-forward. The
controller opens with Back/View + Start on the same pad. The root categories
are Warp, Finish Area, Cheats, and Options. The host overlay must leave guest
VRAM untouched, keep simulation running, consume its inputs while open, and
wait for neutral input before returning control to gameplay. The existing
optional F11 fullscreen/F10 scanline shortcuts will need collision handling
under the dev-menu opt-in. Normal launches must retain retail inputs and
frame hashes. No replacement hotkey mapping has shipped yet.

## Save/restore recovery evidence

The read-only source audit identified these guest pathways:

| Function | Source | OVL payload offset |
|---|---|---|
| Save/restore dialog | `src/ovl_18949.asm` | `0x4A05` |
| Dialog wrapper | `src/ovl_20559.c` | `0x504F` |
| Save writer, opens `wb` | `src/ovl_15682.asm` | `0x3D42` |
| Restore reader, opens `rb` | `src/ovl_16185.asm` | `0x3F39` |
| Startup restore prompt | `src/ovl_14576.asm` | `0x38F0` |

The dialog selects Save Game for argument zero and Restore Game for a nonzero
argument. Its EXE thunk is at code offset `0x2126B`. Calling these routines
requires their RTLink residency and retail calling context; identifying the
routines does not justify a direct host far-call.

`DS:18F6` counts save-list entries, `DS:189A` gates the startup restore
prompt, and `DS:18A2`/`DS:18A3` describe the undo buffer/result. None is a
proven field or modal-state predicate. Likewise, `vm.waiting_for_input` can
be true on the title screen and in dialogues.

Existing local anchors are candidates for a restore sweep. Startup restore
traces do not prove that a live field-menu restore is safe for every anchor.
The existing save/load round-trip artifacts are both 17,972 bytes and differ
only at label offsets 0–3. That proves a specific round trip, not every
checkpoint. Startup restore and mid-field restore use different UI paths.

## Remaining gates

Recover the regular gameplay input loop and the source-owned guards for
modal UI, cutscenes, and room transitions. Trace the guards across title,
field, save, dialogue, and room-change cases. Then perform a live-field
restore sweep for each proposed checkpoint, checking arrival, continued
field activity, and a subsequent transition. Only passing entries belong in
the Warp or Finish Area lists. Quick save/load also needs the verified field
predicate and the host-side slot/first-save warning from the shared spec.

The controller backend now has virtual-device regression coverage for Steam
hint sanitation, active-pad selection, removal and neutral reconnects. The
same-pad menu combo, menu input drain, menu navigation and all-off identity
remain dev-menu integration work. Physical handheld testing is separate and
has not been performed.

HD presentation fixes and font verification drafts remain queued behind the
dev-menu phase. They do not supply a higher-resolution art or font pack.
