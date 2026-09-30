# Guest UI semantics: pointer, hotspots, verbs and input

This document records how the retail game itself describes its adventure
interface: which object is under the pointer, where the verb rows and
buttons live, how clicks and keys become commands, and which guest state
says the game is idle in the field. It exists so host features (controller
hotspot snap, verb cycling, the dev menu's safe-state check) can read the
game's own state instead of hard-coding coordinates.

Each claim is tagged:
- **Code:** read in the retail code (the repo's `src/` units or the retail image).
- **Live:** observed in a headless run of the real game.
- **Hypothesis:** consistent with the evidence but not proven.

## Conventions

- "exe N" is the load-image offset N, as in the `src/exe_<N>` unit names.
  The EXE loads at segment `00B2`, so image offset = linear address − `0xB20`.
  The main code segment is image `08A7`, which is runtime `0959`.
- DS offsets are DGROUP offsets. DGROUP was runtime segment `3961` in every
  run below. Use it explicitly for `dump` in `tool_vmboot`; the DS register at
  a slice boundary is sometimes not DGROUP.
- Screen coordinates are the 320x200 mode-13h pixels that `vm_post_mouse_move`
  and trace `move X Y` use.

Live evidence came from `tool_vmboot` runs on two states:
- **Anchor:** the end-of-opening save (`build/walkthrough_saves/_anchor`, the
  bedroom after the opening), resumed with `lib/resume_after_opening.xit`.
- **Cold boot:** `lib/boot.xit` from an empty saves directory.

A scratch-only copy of the VM with a write watchpoint recorded the exact
CS:IP of each state write. That patch was never committed.

## 1. The region table is the game's own hotspot list

Every clickable area, including picture objects, inventory slots, verb rows,
buttons, compass and scroll arrows, is a 20-byte record in a live table.

**Code:** `exe_109530` is `hit(x, y, &group, &index, &type)`:
- It walks groups `0 .. DS:51DE-1`.
- Group *g* has a far pointer to its records at `DS:67C2 + 4g` and a record
  count at `DS:67E2 + 2g`.
- The last matching record wins; there is no break on a hit.
- Records whose flag byte has bit 7 set are skipped.
- The inclusion test is `exe_112178`. It checks the rectangle inclusively. For
  type 3 with a nonzero vertex count, it also runs a point-in-polygon test.

Record layout (**Code**, plus **Live** decode of every record in the anchor state):

| Offset | Size | Meaning |
|---|---|---|
| +0x00 | byte | type (below) |
| +0x01 | byte | flags; bit 7 = disabled (skipped by the hit test) |
| +0x02 | 4 words | rectangle x0, y0, x1, y1 (inclusive) |
| +0x0A | word | object id (types 3 and 7) |
| +0x0C | word | (unknown; equals the vertex count in every polygon seen) |
| +0x0E | word | polygon vertex count (type 3; 0 = rectangle only) |
| +0x10 | far ptr | polygon vertex list |

Types (**Code**, from the hover and click dispatch):

| Type | Meaning |
|---|---|
| 1 | panel background or generic element (text pane, scroll arrows, map) |
| 3 | picture object; the rectangle, refined by the polygon when present |
| 5 | button (WAIT, system, MAP, UNDO) |
| 6 | compass |
| 7 | inventory or HUD item slot (object with slot highlight) |
| 8 | verb list |

### Groups in the field

**Live**, anchor state: `DS:51DE` = 6.

| Group | Records | Contents |
|---|---|---|
| 0 | 7 | Interface. The record list is below. |
| 1 | 19 | Picture hotspots, all type 3. Record 0 is the whole picture; later records override it. Several carry flag 0x80 (alternate states). |
| 2 | 1 | Text pane, type 1: (51,128)-(314,151) |
| 3 | 1 | Companion portrait box, type 1: (51,152)-(82,195) |
| 4 | 13 | Inventory. Record 0 is the box (88,152)-(287,195), type 1. Records 1–12 are type-7 slots: 24x20 each, pitch 28, x from 92, rows at y 152 and 174. |
| 5 | 3 | Scroll area (293,152)-(314,195). Record 1 is up (…,152)-(…,173); record 2 is down (…,173)-(…,195). |

Group 0 records:
- 0: the whole screen, type 1.
- 1: compass (4,129)-(45,167), type 6.
- 2–5: four type-5 buttons:
  - WAIT (4,168)-(24,181)
  - system (25,168)-(45,181)
  - MAP (4,182)-(24,195)
  - UNDO (25,182)-(45,195)
- 6: the verb list (2,4)-(49,74), type 8.

Examples tying records to the hover state (**Live**, anchor state):

| Pointer | Record hit | DS:0062 |
|---|---|---|
| (200,55) | group 1 rec 7, (182,5)-(290,74), object 0x28 "computer" | 0x28 |
| (140,78) | group 1 rec 4, (128,71)-(156,100), object 0x2E "pen holder" | 0x2E |
| (95,35) | group 1 rec 2, (51,4)-(136,75), object 0x2D (window) | 0x2D |
| (100,165) | group 4 rec 1, (92,152)-(115,171), object 0x54 | 0x54 |

The table changes with game state. In the cold-boot bedroom the computer is
group 1 record 6, object 0x27 with a 15-vertex polygon; after the opening it
is object 0x28. Always read the live table; never cache ids or rectangles
across rooms or states.

### Snap guidance

- **Candidates:** enabled records (flag bit 7 clear) of type 3 or 7, plus
  type 5/6/8 for the interface.
- **Precedence:** a record's rectangle centre can hit a *later* record, and
  concave polygons can exclude their own centre. Choose a snap point that
  the game's hit test (`exe_109530`) maps back to the same group and record.
  For example, sample the rectangle and keep points where the last match is
  that record.
- **Map view:** when `DS:0056 == 1`, group 1 holds type-1 map regions rather
  than objects (**Code**).

## 2. Hover: object under the pointer and verb highlight

`exe_41423` is the hover handler. The main loop calls it for motion and
idle events.

**Code** (`src/exe_41423.c`):
1. It reads the pointer from `DS:69E4` (x) and `DS:69E6` (y).
2. It hit-tests with `exe_109530`.
3. For type 3 or 7, the hovered object is `exe_112853(group, index)`. It is
   0 for record 0 when no verb or object is pending.
4. When the hovered object changes, it redraws the sentence strip through
   `exe_36868` and stores it in **DS:0062**.
5. For type 8, the hovered verb is `exe_36771(index, &y)`. If no verb is
   selected (`DS:0050 == 0`), it highlights the row through
   `exe_36416(verb, y)` and stores it in **DS:0060**.

**Live** writers:
- DS:0062 is written at `0959:189A` (image 41738) and DS:0060 at `0959:1894`
  (image 41732), both inside `exe_41423`.
- `exe_36416` stores the highlighted verb in **DS:0068** (`0959:0473`) and
  its row's top y in **DS:006A** (`0959:0479`).
- Over the text pane, compass and buttons, DS:0060 and DS:0062 are both 0.

Visible feedback (**Live**, screenshots):
- The hovered object's name is drawn centred under the pointer, near the
  bottom of the picture.
- The hovered verb row turns yellow: colour index 0x10, against 0x0F for a
  normal row (**Code**, `exe_36416`).

## 3. Verbs

**Code** (`exe_36771`): row = (y − region y0) / `DS:5C32`, and the returned y
is snapped to the row top. `DS:5C32` is the row height; it is copied from
the font line height `DS:69F8` (10) when the list is drawn.

Which list a verb region reads:
- Group 0 record 6 uses the standard list (via `exe_52687`).
- Any other type-8 region uses the context list at the far pointer
  **DS:5C34/5C36**.

The default standard list is the zero-terminated word array at **DS:04BA**,
installed by `exe_56851`.

Standard verbs (**Live**, hovering each row, anchor state):

| Row top y | Verb id | Label |
|---|---|---|
| 4 | 0x44 | Take |
| 14 | 0x38 | Put |
| 24 | 0x13 | Look at |
| 34 | 0x2C | Open |
| 44 | 0x08 | Close |
| 54 | 0x45 | Talk to |
| 64 | 0x26 | Look |

WAIT uses verb 0x50 (**Code**, `exe_42720`).

Context verbs:
- When an object is selected, the game builds that object's verb list
  (`exe_47086` → `DS:5C34`) and draws it below a blank row.
- **DS:005A** is the y where the context area starts (84), and **DS:005C**
  is the list bottom.
- **Live:** clicking the computer in the anchor state set DS:005C = 0x68
  (`0959:1BA0`); from cold boot the value was 0x72 for three context verbs.
- Traces click context rows at y 87, 97 and 107.

Right-click on a standard verb (**Code**): it assigns that verb to
**DS:005E**, the right-click default verb. For example, Look 0x26 becomes
Look at 0x13.

## 4. Clicks and the command being built

`exe_41745` is the click handler. It dispatches through a jump table on the
hit type.

**Code**, with **Live** confirmation of the verb and object writes:

- **Type 8 (verb):**
  - Clicking the already selected verb deselects it.
  - Otherwise it highlights the row and sets **DS:0050** (the selected verb).
    **Live:** Put wrote 0x38 at `0959:1B59`.
  - Then it calls the sentence builder `exe_36868`.
- **Type 3 or 7 (object):**
  - If no verb is selected and the right button was used, the verb comes from
    DS:005E.
  - If the sentence builder reports the command complete, it executes.
  - Otherwise it shows the object's context verbs and sets **DS:0052** (the
    first object). If DS:0052 already holds a different object, it sets
    **DS:0054** (the second object) instead.
  - **Live:** clicking the computer wrote DS:0052 = 0x28 at `0959:1BBE`.
  - Either click order works: verb then object, or object then verb.
- **Type 5 (button):** draws the press, then posts UI command event
  `0x100 | index`.
- **Type 6 (compass):** maps the click to a direction and posts a "go"
  command.
- **Type 1, group 5:** scrolls the inventory, back or forward. The scroll
  offset is **DS:0064**, in steps of 7; the inventory count is **DS:69FC**.

The sentence builder `exe_36868(execute, verb, obj1, obj2, hover_verb, hover_obj)`
draws the sentence strip. When `execute` is set and the command is
complete, it posts event 0x200. The main loop then runs the turn
(`exe_51355`), which copies the command from `DS:69FA / 6A08 / 6A0A` into
`DS:6A02..6A06`.

After execution the game clears DS:0060 and DS:0062 (`exe_41745`, around
line 404). Its other checks read DS:0050/0052/0054.

## 5. Input loop, events and keys

### Low-level input (**Code**)

- **Mouse:** INT 33h via `exe_98020` (init, flags in DS:4E9E), `exe_100086`
  (position and buttons) and `exe_99939` (set position, clamped to the
  screen).
- **Keyboard:** `exe_90449` reads keys through DOS. An extended key is
  returned as `0x100 | scancode`: F1 = 0x13B … F10 = 0x144, Up = 0x148,
  Left = 0x14B, Right = 0x14D, Down = 0x150, Alt-F10 = 0x171.

### Events (**Code**)

`exe_39607` is `get_event(mask, &event)`. It fills an 8-byte
`{type, x, y, code}` record (the main loop uses DS:69E2..69E8). Sources, in
priority order:
1. a 4-entry synthetic ring: read index DS:0072, write index DS:0074;
   `post_event` is `exe_39372`/`exe_39404`;
2. recorded-input playback, while DS:07E4 == 1;
3. key (type 1);
4. button press (type 4, edge-triggered against DS:0076);
5. motion (type 2);
6. idle (type 8).

### Main loop

The main loop is image `08A7:0000` (exe 35440). It has no unit yet; it sits
between `src/set_byte_one.c` and `src/exe_36030.c`.

**Code:** each iteration updates, animates (only when DS:0042 == 0 and
DS:0056 ≠ 1), then calls `get_event(0x3FF, DS:69E2)` from `08A7:01A0`. It
dispatches on the event type:

| Type | Handler |
|---|---|
| 1 (key) | `exe_39905` |
| 2 / 8 (motion / idle) | `exe_41423` |
| 4 (press) | `exe_41745` |
| 0x10 / 0x20 / 0x40 | `exe_37916` (redraw) |
| 0x80 | `exe_37537` (view mode) |
| 0x100 | `exe_42720` (UI command) |
| 0x200 | `exe_51355` (turn) |

**Live:** the key, click and command handlers were called from these
dispatch sites.

### Retail keys

**Code** (`exe_39905`), with **Live** where marked:

| Key | Action |
|---|---|
| F1, Z | WAIT (UI command 2). **Live:** also verified by field probe. |
| F2 | system menu (UI command 3) |
| F3 | MAP/compass view toggle (UI command 4) |
| F4, U | UNDO (UI command 5) |
| F5, S | Save Game dialog (**Live**) |
| F6, R | restore (Hypothesis) |
| F7 | animation toggle, DS:0042 |
| F8–F10 | not in the field key map. The overlay code compares an input value to F7–F9 and passes F10 as an argument (`ovl_199652`, `ovl_200735`, `ovl_286192`, `ovl_258975`), so treat them as game keys. |
| Alt-F10 | retail developer menu (details below) |
| G, P, O, C, T, L | verbs Take, Put, Open, Close, Talk to, Look. Case-folded; each acts on the object under the pointer (it hit-tests the current pointer). |
| Home, Up, PgUp, Left, Right, End, Down, PgDn, Ins, Del | go, with direction codes 8, 1, 2, 7, 3, 6, 5, 4, 9, 10 |
| Esc, Ctrl-C, Q | quit |
| H, ?, / | help |

**Field probe (Live):** from the anchor, F1–F7 each changed the screen
within 120 slices. F8–F10 had no field effect.

**Alt-F10 (Code):** an unguarded retail developer menu. It shows five
choices through `exe_42821` and calls `exe_59560(n)` with room-like
arguments, range-checked against the room count at DS:084C.
**Hypothesis:** a warp. It is a candidate source-owned warp for the dev menu,
not yet exercised live.

Controller note: the verb letter keys act on the hovered object without a
click. So "verb X on the object under the pointer" can be driven through
the game's own key handler.

## 6. Modal state and the idle-field signal

- **Idle field (Live):** the game is idle in the field when its most recent
  `get_event` came from the main loop's call site `08A7:01A0` (runtime
  `0959:01A0`) and the synthetic queue is empty (DS:0072 == DS:0074).
- **Other poll sites:** every modal state polls `get_event` from a different
  site:
  - title and boot loop: overlay code at runtime 32D0:0326 and 0351;
  - timed or any-key waits: `exe_39464`, called from about 150 overlay sites;
  - event flush: `exe_39576`;
  - Save/Restore dialog: overlay at runtime 317D:0764;
  - message and menu boxes: `exe_42821`'s own loop.
- **Turns (Code):** a turn (event 0x200 → `exe_51355`) runs outside the main
  poll. Room changes, narration and scheduled events happen inside it.
- **Guards (Code):**
  - DS:0058 is set during a view-mode switch;
  - DS:07E4 == 1 means input playback;
  - DS:0056 == 1 means the map view.
- **Hypothesis:** the conversation UI is `ovl_52501` (it has its own
  get_event and mouse calls). Not yet verified live.

`port/src/emu/guest_state.c` implements this as a read-only observer with
two observe-only CPU hooks:
- **get_event's entry** records the caller and the arguments from the
  stack (mask, event record). Every entry invalidates idle.
- **The main loop's return site** (08A7:01A0) marks the field idle only
  when the verified main-loop call (mask 0x3FF, record DGROUP:69E2)
  returned an idle event (type 8).

Classification then adds the queue and guard checks above:
- **Before any key, the classification is `field-idle`.**
- **While the game acts on an event, it is `busy-event`.** This includes the
  full-page L description, which waits without polling from another site.
- **When the last poll came from another site, it is `busy-modal`.** Live
  runs saw this at the boot gates (32D0:0351, 0959:103C), the system menu
  (0959:1FA2) and the Restore dialog (317D:0764).
- **The map view is `map-idle`.**

Tests:
- `GuestStateModalTest` checks the L-page case against the real game.
- With and without the observer, a boot-plus-L run gives the same frame
  hash, instruction count and timer ticks.
- `tool_vmboot --guest-state` logs the classification after every script
  step.

## Open items

- Polygon vertex lists (+0x10) have not been dumped yet. Snap must re-test
  points with the game's hit test rather than trust rectangle centres.
- Conversation option regions and the checkmark are unverified live.
- Alt-F10 menu entries and their effect are unverified live.
- F6 (restore) and UNDO's exact effect are unverified live.
- The overlay units behind the title loop and the save-dialog poll need
  section-base mapping to name them exactly.
