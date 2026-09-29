# Native port: architecture and state

The EXE and OVL have documented byte-exact rebuild results. This verifies the
image reconstruction, not semantic recovery of every function or 1:1 behavior
of the port. See [`KNOWN_DIVERGENCES.md`](KNOWN_DIVERGENCES.md) for the open
parity, completeness, platform and asset-validation gaps. The port currently
executes the supplied retail binaries in an 8086/DOS VM, with thirty-four verified
source-backed entries dispatched natively through guest-ABI adapters (one
entry accelerates only a branch and leaves its helper-call path interpreted).

## Why the port was restarted

`port/src/engine_glue.c` was a hand-written text adventure: three hardcoded rooms,
hand-typed narration, a bespoke parser. It loaded `XANTH.OVL` as 325,595 flat bytes and
never executed one of them. That is what `CONSTRAINTS.md` calls a replacement
implementation, and it cannot ever become the game.

Its overlay model was also provably wrong. `engine_glue.c:78-88` accumulated the 62
directory `size` fields as a byte partition of the payload, but they sum to **43,284**
against a **325,595**-byte payload; as paragraphs they give 692,544. Taking them as
cumulative byte offsets, 1 of 62 resulting starts lands on a `55 8B EC` prologue.
The field's meaning remains unknown and must be settled by observing what RTLink
actually reads at runtime — see "Open questions".

## Architecture

Two stages, both derived from the retail bytes rather than reimplemented.

### Preservation layers (target)

```text
recovered game units / guest adapter
                 │ meaning-level interfaces
        render · audio · input · files · timing · mods
                 │ selected backend
      SDL2 now; other platform backends later
```

Game logic must not call SDL or host OS APIs directly. Backends implement the
meaning-level interfaces and can be changed without changing game logic.
Mod loading and asset replacement are separate opt-in services; the default
configuration has no mods or cheats active and must preserve retail behavior.

**Current implementation status:** Stage 1 runs the supplied retail EXE and
OVL in the custom 8086/DOS VM. VM services reach host facilities through the
HAL and DOS shims. Stage 2 has thirty-four active entries: the exact recovered bodies in
`src/set_int_and_zero.c` and `src/set_far_ptr.c` are compiled into the port;
the 16-bit arithmetic in `src/exe_94712.c` is lowered through the VM's
8086 flag-accurate ALU. The nonzero fast-return branch from
`src/if0_helper_inc.c` also dispatches natively; its zero/helper-call branch
falls back to the VM. The `src/exe_14360.c` table-bit transform is lowered
through the flag-accurate ALU. The `src/set_far_arr.c` indexed far-pointer
store is lowered into guest DS memory, and `src/get_far_idx.c` looks up its
far-pointer array in guest memory. `src/exe_37625.c` clears guest DS words at offsets 37,625, 52,680, 52,713, 99,835 and 99,897; `exe_99679` is at
offset 99,679. The short global getters `src/exe_86810.c` and
`src/exe_84866.c` return a DS word and far pointer, respectively. These entries
are installed at verified EXE offsets 17,806, 17,820, 28,365, 29,169, 30,199, 31,178, 32,631, 35,386, 37,625, 52,680, 52,713, 83,182, 94,712, 16,216, 14,360,
83,200, 102,352, 99,835, 99,897, 99,679, 86,810, 84,866, 85,166, 94,589, 85,189, 90,625, 103,757,
85,206, 112,665, 106,736, 108,184, 114,942 and 115,346; the nonzero `arr_set_one` branch is at 115,161. `src/clear_byte.c` clears a guest byte through its
far pointer. `src/swap_int.c` replaces and returns a guest DS word; `src/exe_115346.c` stores -1 in its indexed DS table; the nonzero branch of `src/arr_set_one.c` stores 1; and the nonnegative branch of `src/exe_114942.c` copies two indexed table values to guest far pointers. Six `set_byte_one` entries write 1 to distinct guest DS bytes. Their partial branches stay interpreted. Two `src/set_int_pair.c` entries store two arguments into guest DS,
and `src/set_int.c` entries at 85,206 and 112,665 store one argument.
The counter/table update in
`src/exe_99679.c` is lowered with guest DS reads, writes and 8086 flag rules.
Adapters map the far-call
stack, DS globals, result registers, far returns, flags, and guest instruction/cycle
budgets. The interaction trace exercises all thirty-four; setter hooks retain
interpreter fallback at timer/DMA boundaries. A 100-frame production run calls
`exe_94712` 18,880 times and takes the native fast return 90 times. The boot
checkpoint hash and guest instruction, timer, audio and file-open metrics
match with hooks disabled or enabled. This is 34/2,844 indexed units (1.20%),
including one partial-path dispatch, not proof of whole-route source coverage.
The full renderer/audio/input/files/timing interface boundary is also not yet
complete. Further units need the same per-path byte evidence and VM/native
co-simulation before they are dispatched. See
[`KNOWN_DIVERGENCES.md`](KNOWN_DIVERGENCES.md) for open evidence gates.

Hash-keyed replacements are available by explicitly passing `--mods mods`.
Put a replacement file in that directory under the lowercase SHA-256 of the
original asset. The base XANBUD files are validated first and remain untouched.
With `--mods` omitted, the mod lookup is disabled. A mod manifest/load order,
event hooks, cheats and persistent user configuration are not implemented yet.
`--scale` is the current scaling option; fullscreen and headless modes are also
available.

### Stage 1 — run the retail code (in progress)

A 16-bit x86 core plus DOS/BIOS shims execute the real `XANTH.EXE`.

```
port/include/emu/   cpu86.h cpu86_alu.h mzload.h dos_mcb.h vm.h
port/src/emu/       cpu86.c cpu86_alu.c mzload.c dos_mcb.c vm.c
port/tests/         test_cpu86.c tool_mzdump.c tool_vmboot.c
```

Three decisions carry most of the weight:

**The VM is architectural, not behavioural.** `INT n` is implemented purely as "push
FLAGS, clear IF/TF, push CS:IP, vector through the IVT". Nothing special-cases an
interrupt number. Host services are reached because the VM installs handlers in the IVT,
as a page of `HLT; IRET` slots at segment `0xF100`. This is not stylistic: the guest
hooks `INT 1Ch` through DOS `AH=25h` and paces the entire game from it, and it chains to
the previous handler. Intercepting `CD 21` at the opcode level would break that. The
payoff shows in the `INT 08h` stub, which chains to the guest's timer handler by simply
*containing* the three bytes `F4 CD 1C` — no mechanism required.

**Flags are eager.** Lazy flags are the standard optimisation and the wrong trade here:
the game needs ~4M instructions/sec against 50-150M available, while lazy flags are the
richest source of bugs whose symptom is "hangs forty minutes in". Undefined flags are
pinned to documented 8086 behaviour, notably shift-by-`CL==0` leaving all flags
untouched. See the rationale block in `cpu86_alu.h`.

**Unimplemented services are fatal and loud.** The trap report prints the call site,
registers, and surrounding code bytes, so each run names exactly what to write next.
The DOS kernel has therefore only ever grown to fit what this game actually calls.
`--permissive` downgrades to a warning for exploration.

`RTLink/Plus needs no reverse engineering on this route.` The overlay manager is
ordinary 8086 code in the EXE's 43,193-byte appended tail. The core executes it and it
pages its own sections via ordinary `INT 21h` reads.

### Stage 2 — static recompilation (twenty-two entries active)

Decode the retail bytes to portable C against the same HAL, function by function, each
validated by co-simulation against the interpreter, until the interpreter is no longer
linked into the release build. `cpu86_hook_install()` already exists for this: a
bitmap plus hash that lets execution at a given CS:IP divert to a native function. Three
consumers share it — native replacements, debugger breakpoints, and profiling counters.

## State reached

**The game runs through the currently verified route.** `xanth_port` boots the retail
image, plays the Legend logo and title with AdLib music, answers the Restore prompt,
reaches the first Mundania room, and follows the published route through Fairy Nuff's
recipe for 122 points. The route is not yet complete: Scene II's published endpoint is
200 points and the full game is 1,000 points. The rendered narration, room art and
hotspots come from retail code and retail data.

Gated on every run by `tests/test_vmboot.py` and `tests/test_vmplay.py`:

| | |
|---|---|
| Faults / unimplemented services | **zero** |
| Files the game opened itself | `XANTH.EXE`, `XANTH.OVL`, `LEGEND.INI`, `OBJECT.DAT`, `XANTHSTR.DAT`, `XANTH_00/01/98/99.PIC`, `XANTH_01/10/13.FNT`, `XANTH_01/03.MUS`, `XANTH_02.PIC`, `XANTH_02.RGN`, `RESTART.DAT` |
| Video | `INT 10h` mode 13h; 181,248 DAC writes; 99.1% of the screen drawn, palette fully lit |
| Audio | AdLib detected via the OPL timer handshake; 1,132 register writes; `.MUS` files loaded |
| Timer | PIT channel 0 modelled, including counter reads; guest's own `INT 1Ch` handler drives pacing |
| Mouse | `INT 33h` event handler installed by the game and called back by the driver |
| Memory | MCB chain intact at exit |
| Determinism | the same trace twice yields an identical frame hash |

Milestones from the plan: **M0-M11 reached** — boot, overlays, mouse, mode 13h,
artwork, title, menu, first room interactive, save/load round-trip, and a soak.
Digitized speech is the outstanding subsystem; see below.

### Three bugs worth remembering

Each of these presented as "the game hangs" and was found by measurement, not guesswork:

1. **A wait that burned the budget.** The first blocking-read implementation neither
   advanced the clock nor yielded, and spun 26 million times at the title screen. A
   blocked read now advances the virtual clock to the next tick and ends the slice —
   which also matches real DOS, where the timer keeps firing while a read blocks.
2. **A clock that did not move.** `AH=2Ch` was pinned to a constant "for determinism".
   The game polls it and spins in the C runtime's long-division and `localtime` helpers
   until it changes, so the game hung with a black screen. Determinism does not require
   a *frozen* clock, only a *reproducible* one — it is now derived from the virtual cycle
   counter.
3. **A PIT that did not count.** Enabling music hung the game in a calibration loop that
   programs PIT channel 0, then latches and reads the counter twice to measure elapsed
   time. Returning a constant made the measured delta zero. Note the calibration routine
   lives at `exe-code:0xa40`, in a unit currently classified `transcribed-data` — more
   evidence for the correction recorded in `docs/STATUS.md`.

The profiler earned its keep on all three: `vm_report` prints the hottest paragraphs, and
because the decompilation exists, an address maps straight back to a unit in `src/`.

## The bug that made the game look unplayable

For a long stretch the port rendered the first room but ignored every mouse
click, and the intro cutscene never played. The cause was not the mouse.

**DOS and BIOS services were returning status in the live FLAGS register, but
the trampoline ends in `IRET`, which restores FLAGS from the stack.** Every CF
and ZF a service set was discarded the moment it returned. Real handlers modify
the FLAGS *image on the stack*; ours did not.

The retail keyboard check is `call peek; jz no_key; call getkey`
(`src/exe_18028.c` and `src/exe_90416.c`). With ZF lost it read whatever the
interrupted code happened to leave there, concluded a key was waiting, and
called the **blocking** `getkey` against an empty queue. The game parked in a
modal wait and never reached its input loop — which is why `INT 33h` was called
18 times in a whole run instead of millions.

The fix merges the service's status bits into the stacked FLAGS image, leaving
IF, TF and DF alone (clobbering IF there would disable interrupts on return).
Measured effect: `INT 16h` and `INT 33h` polls went from ~18 to **6,062,627**,
matching one-for-one. With that:

- the animated intro cutscene plays,
- the game labels objects under the cursor as you hover,
- verb-then-object clicks produce real parser output,
- save and restore work.

Worth remembering as a debugging lesson: the investigation spent a long time
inside the game's mouse driver on the assumption that the host service layer
was correct. The decisive step was reading the retail `kbhit` and noticing it
branches on a flag the host was throwing away.

## The core mechanic: object-first selection

The game's tutorial explains the interaction model: "There is no TURN ON verb
[retail bytes removed]
verbs we can find." Clicking an object selects it and **extends the verb
column with verbs specific to that object**.

Selecting the computer screen adds `Read` and `Touch` below the seven standard
verbs, and each produces its own line from the story database:

- `Read` -> "The computer screen is a dark rectangle of glass."
- `Touch` -> "You touch the computer screen and put a fingerprint on it."

`tests/test_contextverbs.py` gates this, and asserts the two verbs give
*different* results — same object, different verb, different response is only
possible if the parser, the object table and the story database are all being
driven by the real game.

**Verb rows, measured from the rendered column** (guessing them silently
clicks the gaps between entries, which looks exactly like "the click did
nothing"):

| Take | Put | Look at | Open | Close | Talk to | Look | *context 1* | *context 2* |
|---|---|---|---|---|---|---|---|---|
| y=7 | 17 | 27 | 37 | 47 | 57 | 67 | 87 | 97 |

### Object state and sprite overlays

Selecting the **CD-ROM drive** (a real hotspot on the computer) and choosing
`Open` reports "You open the CD-ROM drive." *and* redraws the drive: the game
composites an open-tray sprite over the closed-drive background. So object
state is persistent and drives the artwork, not just the text pane.
`tests/test_contextverbs.py` asserts the resulting frame differs from every
earlier checkpoint in the same run.

Objects named by the hotspot layer in the opening room include: window,
screen, shelf, pencils, pen holder, computer, porch, desk and CD-ROM drive.

### Hotspots

Hovering the cursor over the picture makes the game name the object underneath
it, driven by the region data in `XANTH_02.RGN` and the object table in
`OBJECT.DAT`. A 9x5 sweep across the picture window produces **17 distinct
label states**, so the hotspot layer is genuinely populated rather than inert.
`tests/test_hotspots.py` counts distinct states rather than reading the text,
which keeps it robust against wording and exact object positions while still
failing loudly if the layer stops working.

## Walkthrough progress

`tests/traces/walkthrough_*.xit` follow the published solution, kept short and
independent so a failure localises — a single long trace would be invalidated
wholesale by one divergence near the start.

**Segment 1, Mundania opening** (`tests/test_walkthrough.py`):

1. Boot through the Legend logo, the demon cutscene and the title.
2. Take the **envelope** from the desk (hotspot at 105,103).
3. Open it: *"You carefully open the envelope and a letter and a bracelet
   fall into your hands."* One inventory item becomes three.
4. Read the **letter** — the game renders Pia's handwritten page
   **full-screen** as retail artwork, and awards **`[5 points]`**, exactly
   the score the published route gives for this action.
5. Take the **Post-It** off the monitor (238,66); reading it shows
   `Ed 388-5288 / Pia 385-8677 / Weather 936-8267`.
6. NW to the front hall, which starts dark.
7. Select the light switch (310,52) — the game offers the context verb
   **Push** — and push it: *"You push the switch and the room becomes
   brightly lit."*
8. West into the kitchen.

That exercises the room graph, hotspot layer, object table, inventory,
containers, context-verb dispatch, **scoring**, full-screen document
rendering, parser and story database — all retail code.

Inventory ordering is not stable across container operations: the envelope
occupies slot 1 until it is opened, after which the slots read letter (92),
bracelet (132), envelope (152). Traces select by measured slot position, so
this is called out in the trace header.

**Segment 2, the phone call and Edsel's bet**
(`tests/test_walkthrough.py::PhoneCallTests`):

The call is **time-gated** — the phone is not ringing when you first reach
the kitchen, and waiting (F1) advances the clock until it rings. Answering
opens the **conversation UI**: a telephone illustration, Edsel's line, and
the player's selectable replies.

Following the published dialogue path — *"Hi, Edsel. Things are going pretty
well. What's up?"*, then 1, 2, 2, 3 — walks a real branching tree:

- *"I've been fooling around with this new computer game. I know how much you
  hate them and I was thinking of making you a bet about this one."*
- … ending at *"Smart boy, Dug. I'll send the package to you by courier as
  soon as I hang up. Bye."*

That is the story event that unblocks the rest of the game (15 points).
Picking different rows lands on different branches, so reaching that exact
line is evidence the tree is being navigated rather than clicked through.

Dialogue option rows sit at **y = 114, 123, 131, 139, 147, 156**.

Note the dialogue offered depends on prior progress: before Pia's letter is
read, the only reply available is *"Hi Ed. I've got an important letter to
read. Call me back later."* The game gates the branch on story state.

**Segment 3, stocking up in the kitchen**
(`tests/test_walkthrough.py::KitchenTests`):

Two mechanics appear here that no earlier segment reaches.

**The conversation layer is modal, and it does not close itself.** Edsel's
closing line stays on screen with a checkmark button at **(125,134)**; until
that is clicked every click on the room is swallowed. An attempt to click the
teabag straight after the call looked *exactly* like a dead hotspot — the
hover label named the object correctly but no pending command appeared. Worth
knowing, because "the hotspot doesn't work" and "a modal layer is eating the
click" are indistinguishable from a screenshot.

**The icebox is a container in the room rather than in the inventory.**
Opening it changes the artwork (the door swings open) *and* publishes three
hotspots that did not exist a moment earlier: *"You open the icebox and
discover some mustard, a sandwich and a heart-shaped box."* Taking one of
them — *"You snag the yellow bottle from the icebox."* — exercises a path the
desk envelope never does.

Also established here: **either click order works.** Object-then-verb and
verb-then-object both dispatch. Clicking an object alone pre-selects the
default verb, which is why the pending command reads "Take the teabag"
before any verb is clicked, and why a context verb (**Smell**) joins the
column at the same moment.

**Segment 4, the courier's package**
(`tests/test_walkthrough.py::CourierTests`):

This closes the loop segment 2 opened, and it is the strongest evidence in
the suite that the story machinery is real. Edsel promised to send the game
"by courier as soon as I hang up", and the delivery arrives through the
*same* scheduler that made the phone ring: the first WAIT after returning to
the front hall reports *"Time passes. You hear the doorbell sound."*, and
every later WAIT reports only *"Time passes."* — a one-shot scheduled event,
not a poll.

The doorbell does not fire because the player walked into the hall. It fires
because a conversation several minutes of game time earlier set a story flag
that armed it. A port with a broken clock, a broken event queue or a broken
story database reaches this room and waits forever.

The parcel is left on the stoop rather than handed over, so it is only
reachable once the door is open — *"You open the front door and immediately
feel the force of the storm building outside."* — and then
*"You take the package from the front stoop. `[2 points]`"*, matching the
published route's score for this action.

The package region sits right at the bottom edge of the picture window, where
the cursor sprite overlaps the label strip. The sweep that found it reads the
label *text* rather than treating the strip as an opaque hash, which is the
general fix for hotspots below y≈95.

**Segment 5, booting the game-within-the-game**
(`tests/test_walkthrough.py::CdRomTests`):

This finishes the Mundania opening at **31/31 points**, and it is where the
story proper begins — the final frame has Grundy Golem drawn on the monitor.

Two nested containers in a row. The courier's parcel holds a game box
(*"You find a game box entitled 'Companions of Xanth'."*), and the box holds
five more objects (*"You find a game manual, a CD-ROM, a warranty card, a red
book, and a pair of 3D glasses."*). One take becomes seven inventory items,
and the bar grows a scroll control to hold them.

Selecting the computer publishes the context verbs **Read** (y 87),
**Turn on** (97) and **Turn off** (107) and pre-selects "Turn on the
computer": *"You flip the power switch and the computer screen lights up."*

Inserting the disc is a three-verb sequence on one hotspot — Open the drive,
**Put** the CD in it, Close it — which is the first point in the route where
an inventory item is the *indirect* object of a command rather than the
direct one. *"`[9 points]` You close the CD-ROM drive."*

Inventory slots are 20px apart from x=92 at y=162. After the box is opened
they read: 92 glasses, 112 glasses, 132 tome, 152 plastic, 172 –, 192 game,
212 CD-ROM, 232 card, 252 card, 272 manual. Selecting by measured slot is the
only reliable way in, since the ordering is not stable across container
operations.

**Segment 6, into Xanth with Nada Naga**
(`tests/test_walkthrough.py::IntoXanthTests`):

The opening ends with the game booted but not entered. Looking at the monitor
zooms into it — a full-screen view of a figure the narration pointedly will
not name yet (*"A strange male figure studies you expectantly"*, hotspot
**tiny man** at (88,48)) — and talking to him introduces the guide:

> *"Hi, I'm Grundy Golem. Welcome to the Game. It's my job to answer any
> questions you may have about Xanth, the Game, or your potential
> Companions."*

with a six-option menu at y = 130, 138, 146, 154, 162, 170. Taking the last
option gets his warning — *"Pick wisely, young man. Xanth's a dangerous place
and the Companion you pick could mean the difference between success and
failure."* — and then the **companion gallery**: four selectable portraits,
Jenny (113,100), Che (158,100), and Nada (248,100).

Choosing Nada, per the published route, enters Xanth: *"You're in a dimly lit
cavern. Nada stands beside you, getting her bearings."*

Worth recording because it is good evidence the choice is threaded into story
state rather than cosmetic: the narration is **per-companion and correctly
gendered** — Che gets "getting *his* bearings", Jenny and Nada "*her*".

### Save-anchored segments, and why they start at 6

Segments are cumulative, so segment 6 would have replayed ~20 billion
instructions before reaching anything new — about eight minutes per run, and
growing with every segment added. Exploration at that turnaround is
unworkable, and a test suite on that curve stops being runnable well before
the game is finished.

From segment 6 on, a segment boots and restores a save instead:
`tests/traces/anchor_after_opening.xit` plays the opening once and saves, and
`tests/traces/lib/resume_after_opening.xit` boots and restores it. That is
**~1.2 billion instructions, flat** — measured at 37 seconds against roughly
eight minutes, so exploration probes now take about a minute each.

Segments 1–5 deliberately keep replaying from a cold boot, because "the route
works from a cold start" is precisely what they assert, and `CONSTRAINTS.md`
carries a ratchet on how many segments are allowed to be anchored so the
optimisation cannot be used to hide a regression.

One thing this uncovered: **restoring at boot is a different path from
restoring mid-game.** When a `*.SAV` is present the game offers to restore it
during startup, with its own "Restore?" Yes/No box at (160,95)/(160,110) that
the system-menu route never shows. Missing that click leaves the confirmation
on screen and every later click goes nowhere — which looks exactly like a
restore that silently did nothing.

### Traces `include` their predecessor

Segments are cumulative: segment 5 replays 1–4 before reaching its own
material. They used to hold *copies* of that prefix, which meant a coordinate
corrected in segment 1 had to be corrected in five files that could silently
drift apart. `tool_vmboot` now understands

```
include walkthrough_04_courier.xit
```

resolved relative to the including trace, depth-limited to catch cycles. The
refactor was verified behaviour-preserving: all 21 checkpoint hashes across
segments 1–4 were bit-identical before and after.

Budgets grow with the route and are sized from measured runs, held per test
class. Worth knowing: **a budget that is merely too small does not fail
loudly** — it truncates the trace, and the checkpoints simply never appear.
`test_all_checkpoints_reached` names the budget in its failure message for
that reason.

### Evidence the game logic is genuinely running

The game **refuses invalid actions correctly**. Answering the kitchen phone
before the story has made it ring returns *"That might make sense if the phone
were ringing."* A port that merely replayed canned responses could not produce
a state-dependent refusal like that.

### Objects found so far

| Room | Hotspots |
|---|---|
| Bedroom | window, **screen** (240,35), **shelf** (300,35), pencils, pen holder, porch, disks, **post-it** (240,68), light (264,68), **computer** (192,79), disk drive (240,90), **CD-ROM drive** (270,100) |
| Front hall | kitchen, painting, light, mirror, **door** (270,42), flowers (230,51), **switch** (310,51), plant, table (230,80) |
| Front hall, door open | front yard (280,40), stoop (280,90), **package** (280,100) |
| Kitchen | window, freezer (x160–220, y22–38), **icebox** (x160–250, y46–86), foyer, **phone** (275,32), sink (72,46), dishes, cabinets, towel, chair, table, **teabag** (62,85) |
| Kitchen, icebox open | **mustard** (208,55), heart (204,73), sandwich (202,88) |
| Game close-up | **tiny man** (88,48) — Grundy Golem, before he introduces himself |
| Xanth, dimly lit cavern | four **door** groups around x 105–127, 160–182, 204–237 and 259, all at y 33–78; **bars** (270,42) |

Rows marked "open" only exist after a world change: those hotspots are
published by the game when the container or door opens, and hover-sweeping
before the change finds nothing there.

Small hotspots need a fine sweep to find — the light switch and the post-it
were both missed by a coarse grid. Note the port's own `rgn_loader.c` was
*not* used to shortcut this: it comes from the retired hand-written effort
whose overlay model was provably wrong, so the game's own hit-testing is
treated as the only ground truth.

### Remainder of the published route

The Mundania opening is **complete at 31/31 points**: Pia's letter (5),
Edsel's bet (15), the teabag and mustard, the courier's package (2), and
booting the game on Dug's computer (9). Segment 6 leaves Mundania with Nada
Naga. Segment 7 (`CavernTests`) wears the 3D glasses, waits while Nada opens
the second door, answers "No. This can't be real.", and lands on the clearing:

> [9 points] Nada has successfully extricated you from the cavern. You're
> finally in Xanth.

That is **40 points**. The segment restores `build/anchor_xanth`, not the
post-opening anchor. Three WAITs open the door; a fourth is a different speech.

Segment 8 (`tests/test_walkthrough_isthmus.py`) restores the village-center
save and plays through the pier, the log jam, and the catapult. The meadow
panel reads **102 of 1000** with the bucket still on the path.

Segment 9 (`tests/test_walkthrough_pail.py`) takes that pail (`[7 points]`),
reads and returns the mailbox letter, gets past the eye, picks up the tee
and the egg, and reads Fairy Nuff's recipe. The panel at his booth reads
**122 of 1000**. The published 12 points for passing the eye did not appear
on the panel. Next is two dashes of eye scream into the pail, then the rest
of the recipe, then the censor-ship. The experimental continuation through
Crossroads (two eye screams and Nada's cough drops) was exercised in the retail
VM, but its score panel still read 122/1000. From the existing 193-point Void
save, the verified route saves 203 after the shimmering door solidifies, shows
206 after opening it (+3), and reaches the Region of Earth outskirts at
208/1000. This crosses the 200-point threshold; the exact action that crosses
it remains unisolated. The next verified route reaches the unlocked barrow
interior at 208; defeating Metria then saves a 228-point state inside the
barrow. The item-route trace retrieves the small jar from the earlier barrow
map room, frees Nada, opens the jar by targeting its centered inventory icon,
and collects agony moss for 7 points. It shows the upper room after choosing
the stairs' context action, melts the ironwood tree, enters a dialogue
identifying the Region of Fire, and advances to dialogue about heading south
toward the Gap, the chasm dividing Xanth, and the Water/Air sequence. The game's
save routine captures a 275-point state after the dialogue is dismissed. A
follow-up retail-VM replay restores that save, moves south twice, and reaches a
second Barrow chamber whose description says flapping wings are audible nearby;
the replay pins framebuffer hash `8083725b37faaaa2` and preserves the save. A
separate continuation travels east into the lava-lake entry, where OCR reads
“You stand before a bubbling lake of lava” and the southeast-path prompt at
frame hash `5d6d67ae69300dd3`. Southeast reaches the Fireman and hot dog at hash
`c22b2662b3ab3f89`. The bun/mustard interaction makes the dog melt into the lake
for **15 points**; the subsequent Fireman dialogue records Mack’s explosive
device cracking the firewall. A direct northeast move after the Mack clue
reaches the firewall at hash
`dc10de12e2f8098d`; the retail description says a piece of charcoal lies on the
ground. This checkpoint also preserves the 275-point save. The charcoal pickup
and remaining Region of Fire puzzles, Gap, and 1,000-point ending remain
unverified.

Digitized effects are covered in the audio section. `MUSIC=adlib` still
plays no `.RS` and no `.VOC`; that is the game's device choice, and it is
the configuration the golden frames were recorded against.

## Multi-room navigation

The compass is a 3x3 arrow grid at x 4..44, y 128..168 (centres x 11/24/37,
y 135/148/161). The game's own tutorial in `XANTH_00.HLP` states "the Bedroom
is southeast from the Foyer", and that is exactly what the port does: NW from
the opening bedroom reaches the Foyer -- a hallway with a painting, chandelier
and potted plant, narrated "It's too dark to make out much in this room." --
and SE returns.

`tests/test_navigate.py` gates the round trip. Note that a room change here
does **not** open a new file: several Mundania rooms live inside
`XANTH_02.PIC`, so the evidence of a transition is the scene changing, not an
asset load.

## Save and restore

Driven through the game's own system menu (the house icon beside WAIT).
`tests/test_saveload.py` saves, changes the world with WAIT, restores, and
saves again, then requires the two save files to be **byte-identical apart
from the name field**. They are: 17,972 bytes each, differing only at offsets
0-3. That is a far stronger statement than comparing screenshots, which can
match while the underlying state differs.

System menu item centres, measured from the rendered menu rather than guessed
(an early attempt clicked a border row and silently did nothing):

| Help | Save | Restore | Restart | Music/Voice | Status/Score | Quit | Cancel |
|---|---|---|---|---|---|---|---|
| y=40 | y=56 | y=72 | y=88 | y=104 | y=120 | y=136 | y=152 |

## Overlay layout, resolved by observation

The 62-entry directory does not partition the payload, so rather than guess again
the VM now **records every read RTLink performs on the `XANTH.OVL` handle** — which
payload offset, how long, and where it landed — and keeps a per-paragraph provenance
map. `tests/test_overlay.py` pins the result. What a boot-to-first-room run shows:

- **There is more than one overlay slot.** Sections load at `317D:0000` *and*
  `32D0:0000`. The retired engine assumed a single region at `0x30CB`; that is why a
  bare `seg:off` cannot identify overlay code, and why Stage 2 needs provenance-keyed
  dispatch rather than an address table.
- Slot bases are 0x153 paragraphs (5,424 bytes) apart — exactly the largest section
  observed in the first slot.
- **Each section load is preceded by two short reads into `1E73:0BAA`**, a scratch
  buffer inside the root image. Those are RTLink's per-section relocation records,
  read and applied before the code is entered. Layout per section is therefore
  *relocations, then code* — e.g. code at payload 8512 (1,888 bytes) with its
  relocation records at 7952 (352) and 8304 (196).
- **Sections are re-paged, not kept resident.** The same payload offset is loaded
  repeatedly, which is precisely why provenance has to be tracked at runtime instead
  of computed once.

Use `vm_overlay_payload_at(vm, seg, off)` to map a live overlay address back to a
payload offset, and from there to a unit in `config/c-units.json`.

## Audio: what selects the device

Music works and is verified. The device selection turned out to be the
opposite of what it looks like, and the mistake is worth recording because it
cost a round of investigation.

**It is the `MUSIC=` line that selects the Sound Blaster, not `SOUND=`.**
Instrumenting the game's own device init (`src/exe_79943.asm`, hooked at
`exe-code` offset 79943 with `--hook-at`) gives the mapping directly:

| `MUSIC=` value | device type passed |
|---|---|
| `quiet`, `real`, `noreal`, `mt32` | 1 |
| `adlib` | 2 |
| `blaster` | **4** — with the base port and IRQ from the INI |

That routine only stores a Sound Blaster base and IRQ when the type is 4:

```asm
cmp word ptr [bp+6h],4h
jz  short store_base          ; ds:[421Fh] = base, ds:[4221h] = irq
```

Every value of `SOUND=` leaves the type unchanged. An earlier round of this
work concluded the Sound Blaster "is never initialised" — it was being
configured on the wrong line. With `MUSIC=blaster 7 220` the guest performs
**520 DSP port accesses**: the reset handshake and command traffic really run.
`tests/test_soundblaster.py` gates that path, and also checks music still
plays (a Sound Blaster carries an OPL) and that the boot still reaches the
first room.

The authored default remains `MUSIC=adlib`, because it is the simpler
configuration and the other suites' golden hashes are generated against it.

**Digitized sound is selected by `MUSIC=`, and it does play.** Measured with
the INI written into the save directory before boot:

| `MUSIC=` | What opens | Samples |
|---|---|---|
| `adlib` | nothing digitized | DMA 0, RealSound 0 |
| `real` | `PHONE.RS` when the kitchen phone rings | 44,159 PIT channel-2 writes, one per payload byte |
| `blaster` | `XANTH_01.VOC` during boot, then `PHONE.RS` | DMA bytes in the millions, plus the effect |

RealSound does not use the DSP. The guest enables the PC speaker (port
`0x61`, bits 0 and 1) and writes each pulse-width byte to port `0x42`. Those
widths sit in 0..61; the host expands them and queues PCM. `tests/test_realsound.py`
gates the phone ring. Speech stays on the `blaster` path: one bank,
`XANTH_01.VOC`, streamed with DSP command `0x14`.

Channel 1 uses the 8237's 16-bit address plus its separate page register. When a
transfer crosses offset `0xFFFF`, the address wraps to zero without carrying into
the page register. `sb_dma_stream()` preserves that split both for a fresh DSP
transfer and for auto-init replay; `test_adversarial_dma` and
`NativeDmaPipelineTests` verify the sample bytes on each side of the boundary.

## Deliberate deviations from strict DOS

Each of these is a judgement call, recorded so it can be revisited:

- **A write-open of a missing file creates it** (in the save directory). Strict DOS
  fails. On a real installation `RESTART.DAT` already exists in a writable install
  directory; we ship a read-only asset tree. Without this the first write-open fails and
  the game — which does not check CF — takes the DOS error code in AX as a file handle
  and writes 512-byte blocks to handle 2.
- **`LEGEND.INI` is authored by the VM** into the save directory rather than shipped.
  `INSTALL.EXE` produced it originally. This is a lever: the game reads its hardware
  configuration from it, so we choose which devices the shim must emulate.
- **Non-8.3 filenames do not participate in wildcard matching.** Real DOS truncates;
  our host can hold names DOS never could, and truncating means a stray `XANTH01.SAVE`
  would be picked up by the game's `*.SAV` save-slot glob.
- **The clock is virtual, not fixed.** `AH=2Ah`/`2Ch` are derived from the virtual cycle
  counter, never from the host clock, and find-first results are **sorted**. Both exist
  so replay is deterministic — a prerequisite for the golden-frame-hash suite. Note that
  an earlier attempt to get determinism by *freezing* the clock hung the game outright;
  reproducible is the requirement, not motionless.

## Playing it

```sh
./scripts/build_port.sh
./build/xanth_port --data game_cd/XANTH --saves build/saves
```

Escape quits. `--scale N` sets the window size, `--headless` runs without a window,
`--cpu-speed N` changes the virtual CPU rate (useful when a timing-calibrated loop
misbehaves), and `--shot FILE` dumps the final frame.

## Input traces

`tests/traces/*.xit` drive the game deterministically. The format is an ordered list of
steps, not timestamps — timestamps were the obvious first design and the wrong one,
because any change to interpreter speed shifts every instruction count:

```
run 150          # N scheduler slices: one tick of game time, or a chunk of compute
waitinput        # run until the guest actually blocks asking for input
key 110          # queue an ASCII code
move 163 112     # move the mouse in 320x200 coordinates
click left       # press, hold across several polls, release
checkpoint name  # hash framebuffer + palette
shot path.bmp    # dump a frame (gitignored: it contains retail artwork)
```

A click is *held*, because code that polls button state via `INT 33h AX=0003` cannot see
an instantaneous press-and-release.

## Debugging tools worth knowing about

- `--watch` reports whenever the amount of drawn screen or the number of lit
  palette entries changes materially. Far better than guessing when to take a
  screenshot.
- The end-of-run report lists every distinct file the guest opened, the
  hottest code paragraphs (sampled), interrupt and DOS-function histograms,
  overlay loads, and MCB health.
- `--hook-at <exe-code offset>` installs a breakpoint through
  `cpu86_hook_install()` and logs registers and stack arguments each time it is
  hit. This is the **same mechanism Stage 2 will use** to divert execution into
  recompiled C, so running it against real code now proves the path works
  before anything depends on it. It is what identified the sound-device
  problem above.
- `scripts/bmp2png.py` converts frame dumps for inspection. Frame dumps
  contain retail artwork and are gitignored.

This also explains a trap for anyone debugging here: **an overlay address dumped at
one moment may hold different code a moment later.** An earlier attempt to read the
game's main loop produced nonsense for exactly that reason.

## Verification

```sh
./build/xanth_cpu_tests                                      # 123 checks, no SDL, no assets
ctest --test-dir build                                       # all targets
python3 -m unittest discover -s tests -p "test_mzload.py"    # C loader vs Python reference
python3 -m unittest discover -s tests -p "test_vmboot.py"    # boot gate
python3 -m unittest discover -s tests -p "test_vmplay.py"    # reaches the first room
python3 -m unittest discover -s tests -p "test_*.py"         # everything (needs the disc)
./build/tool_vmboot --script tests/traces/reach_first_room.xit --watch --insns 2000000000
python3 scripts/bmp2png.py build/frames/*.bmp                # look at what it drew
```

`test_mzload.py` is the one worth understanding: it loads `XANTH.EXE` with both the C
loader the port ships and a Python reference written from the header fields, then asserts
the 191,656 relocated bytes are **byte-identical** and all 5,304 relocations were applied.
The decompilation pipeline already trusts `tools/mz.py`; this keeps the port from drifting
away from it silently.

Both Python tests skip cleanly without the retail disc, so they are safe in public CI.

## Open questions

1. **Resolved: digitized sound follows `MUSIC=`.** `real` and `blaster` open
   `.RS` effects; only `blaster` also opens `XANTH_01.VOC`. `adlib` is music
   only. The earlier "never initialised" result was an `adlib` run.
2. **What the 62 OVL directory `size` fields mean.** Runtime observation gave us
   the true load behaviour, but the directory's own fields remain unexplained. They
   are not needed to run the game.
3. **The PIT divisor the music driver settles on.** Channel 0 is modelled including
   counter reads and the game's calibration passes, but the final rate has not been
   characterised — worth knowing before the digitized-audio timing work.

## Next

- Isolate the action that crosses 200 on the verified Void-to-Earth route, then
  continue through the full 1,000-point finale. The whole-game completion gate
  remains open.
- Verify the Windows job on a real runner. The workflow exists and executes the
  conformance suite and CTest; it has not yet been observed passing.
- Expand Stage 2 from the first thirty-four source-backed entries: generate address/extent/ABI
  metadata for recovered functions, prioritize units measured on real routes,
  and keep VM/native frame, save, audio and timing comparisons as gates. The
  first hook is at EXE code offset 17,820; `tests/test_stage2_native.py` checks
  its one observed call and boot-frame parity against VM-only execution.

## A note on how this was debugged

Four of the hardest problems here — the 26-million-iteration wait, the frozen
clock, the uncounted PIT, and the discarded status flags — all presented
identically as "the game hangs", and none were solved by reading the port's own
code. They were solved by measuring what the guest actually did: the sampled
profiler turning a hang into an address, the decompilation turning that address
into a source unit, and `--hook-at` turning a suspicion into logged arguments.

The recurring mistake worth naming: assuming the host service layer was correct
and looking for the fault in the game. The status-flag bug wore a mouse-driver
disguise for a long time for exactly that reason.
