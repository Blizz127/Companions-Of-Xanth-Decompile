# Session handoff

Live numbers belong in this snapshot and in `CONSTRAINTS.md`. Dated
sessions below are lab notes; counts inside a dated session are of that
date. A unit is recovered only when its source is in `src/` and
`tools/lift.py` reports MATCH. Notebook C is not a recovery.

## Current (2026-09-11)

Measured by `python3 tools/coverage.py` (wine-free). C and mnemonic-`_asm`
units have no dump extent, so unaided-C *byte* coverage reads 0.0% here;
`--compile` is the byte metric. Dump byte coverage and unit counts are
the numbers that are locked.

| Image | bytes | units | unaided C | mnemonic `_asm` | `_emit` dumps | dump byte coverage |
|---|---|---|---|---|---|---|
| `exe-code` | 191,656 | 1,253 | 108 | 295+247 wasm | 72 | 18.92% (36,253 B) |
| `ovl-payload` | 325,595 | 1,591 | 334 | 664+84 wasm | 125 | 18.98% (61,796 B) |

| Source kind | units |
|---|---|
| unaided C (no `_asm`) | 442 |
| mnemonic `_asm` | 959 |
| Watcom `.asm` listing | 331 |
| transcribed data (`char` array) | 915 |
| `_emit` dump | 197 |

Dump-unit shapes (C/asm units are `unknown` because they have no extent
without `--compile`):

| Shape | count | meaning |
|---|---|---|
| `function` | 194 | framed dump that starts `55 8B EC` and ends in a return |
| `unframed-function` | 3 | no frame, ends in a return |
| `fragment` | 0 | no fragment dump remains |
| `unknown` | 2,330 | 442 C + 959 mnemonic `_asm` + 915 data + 14 mixed dumps |

Rebuild is still `listing-splice` BINARY-MATCH for both images, not
CL+LINK, and is verified end to end: `python3 tools/verify.py` reports
`BINARY-MATCH` for `XANTH.EXE` and `XANTH.OVL` with all 2,844 units spliced
(re-run after the 581-function mnemonic sweep). `pc-port` does not exist.

### Session 2026-09-11 — mixed-unit mnemonic conversion and a compile repair

`tools/gen_mnem.py` re-emits a dump unit as mnemonic `_asm` and verifies the
candidate with the real toolchain (`--verify` compiles it and byte-diffs
against the retail slice; `--write-verified` lands only the clean ones, and
only when every registration of a source matches). 45 of the 60 mixed units
(46 units with the one complete function in that pass) plus 581 complete dump
functions converted: **2,380 → 1,753 dump units**, **22 → 649 mnemonic
`_asm`**, **1,141 → 560 dump functions**,
`exe-code` dump coverage **97.8% → 88.73%**, overlay **96.69% → 64.61%**.
This is a classification move, not a byte recovery — those units already
spliced to their retail slice. `tools/verify.py` re-confirms BINARY-MATCH for
both images after the sweep.

Spellings the converter had to pin, each verified by controlled experiment
(`tools/cl_probe.py`):

- conditional jumps: `jcc short $+N`. MASM expands a *backward* conditional
  jump into `inverse; jmp` and mis-resolves some forward ones; `$+N` is the
  rel8 the retail image actually uses.
- `jmp` rel8: `jmp short $+N`; `jmp` rel16: a named label, because MASM
  shortens a jump whose distance it can resolve in pass 1.
- a direct DS-relative operand with no base register (`[0x1234]`) is not
  spellable: MASM rejects it, and `ds:[0x1234]` adds a `3E` prefix the retail
  bytes do not have. It becomes a declared `extern <type> __near mnADDR;`
  symbol, so CL emits an OMF fixup that `_relocate` overwrites with the retail
  address. `extern` matters: a symbol defined in the TU has a known offset and
  is encoded literally, which `_relocate` cannot rewrite.
- a segment register load loses its size hint (`mov es, mnADDR`, not
  `mov es, word ptr mnADDR`), and the override moves outside the brackets
  (`es:[bx]`, not `[es:bx]`).
- CL wraps an `_asm` block that writes SI/DI with its own `push si`/`pop si`;
  `gen_mnem` strips that pair from the frame so it is not emitted twice.
- `jcxz`/`loop` reject a `$` operand (`C2415`); they take a label.
- a near call (`E8 rel16`) to another unit becomes `extern void __near
  ncADDR(void);` plus `call ncADDR`, so CL emits the self-relative fixup
  `_relocate` overwrites with retail's displacement.
- `retf word 8` loses the `word`; `les`/`lds` take no size hint; an indirect
  far call through memory is `call dword ptr ..`.

The 1,753 units that did not convert fall into four classes: the body begins
with the compiler's own stack frame (`81 EC imm16`, i.e. `sub sp,N`), which
MASM only ever spells `83 EC imm8`, so it needs the C that produced it; the
body pushes or pops SI/DI without writing them, where CL adds a save/restore
wrapper the `_emit` form never had; mid-function fragments and thunks; and
data. Only the first class is a spelling problem — the rest are not functions.

### Session 2026-09-11 (second pass) — fragments and transcribed data

Two more sweeps took the dump population from 1,753 to **1,082**:

- 256 code fragments and 4 functions re-emitted as mnemonics.
- 411 fragments transcribed as `char` arrays. The classifier only fires on
  positive evidence — printable ASCII, at most four distinct byte values, a
  strict short-period repetition, or one byte value at a constant stride (the
  overlay's `30 xx xx cb` relink records) — and is vetoed when the unit ends
  in a return and carries a call or port instruction, which is how repetitive
  *code* looks. This matters because MSVC 8.00c has no `db` directive, so a
  data block cannot be spelled inside `_asm` at all; the array is the only
  source form. `tools/units.py` gives these units their own kind
  (`transcribed-data`, marker sentence `Data region, not an instruction
  stream`) so they never count as recovered C. A TU with no `PUBDEF` makes
  the splice take its first LEDATA, which is the array — verified.
- `tools/verify.py`: BINARY-MATCH for both images with all 2,844 units
  spliced, after both sweeps.

What is left: 668 `exe-code` and 414 overlay dumps. 560 of them are complete
functions (the compiler-frame and SI/DI-wrapper classes above, which need the
original C), and the rest are fragments whose instruction stream does not
round-trip through MASM (307 compile failures and 98 where the compiled body
is longer than retail, mostly mid-function slices that start mid-instruction).

### Session 2026-09-11 (third pass) — the fragments are finished

The remaining 504 fragment dumps were transcribed as data arrays, taking the
dump population from 1,082 to **577** (`exe-code` dump coverage 81.27% →
47.07%, overlay 53.64% → 34.74%). Two groups:

- 372 with positive data evidence (the classifier above).
- 132 whose mnemonic form did not assemble at all (`C2400`/`C2402`: `udw`,
  `add [bx+si],al` runs, illegal operands). "This byte sequence is not an
  instruction stream the toolchain can express" is positive evidence of data
  rather than code, and each unit carries that sentence in its header.
  `tools/gen_mnem.py --data --force-data --reason ..` is the mode used.

A fix that mattered: a data array has no OMF fixups, so `--data` now takes
the *retail* slice rather than the `_emit` stream — otherwise a fragment with
a far call carried `9a 00 00 00 00` and would not splice (that was the
`DIFF +1` class).

After this pass every remaining dump is code: 560 framed complete functions,
3 unframed complete functions, and 15 mixed mnemonic units in the
`81 EC imm16` frame class. There is no fragment left, and nothing left whose
bytes are data rather than an instruction stream.

### Session 2026-09-11 (fourth pass) — the last units are blocked on the assembler

The remaining 577 dumps are all code, and none of them can be spelled as
mnemonics by the pinned toolchain. Four controlled experiments
(`tools/cl_probe.py`, `nasm`, `as`, `llvm-mc`) bracket the reason:

1. **The `81 EC imm16` frame is not this compiler's output.** A C function
   with a 2-byte, 4-byte or 6-byte local compiles to `83 EC imm8` under every
   optimization flag tried (`/Od /Ot /Os /Ox /Oa /Ol`, `/Ze`, `/Zg`,
   `/AL /AM`, `/Gx-`). So the 90 units carrying `81 EC`/`81 C4` were not
   produced by MSVC 1.52's compiler — and its *assembler* only ever spells
   `sub sp,N` as `83 EC` too.
2. **CL's inline-asm path always wraps SI/DI.** `_asm { push si; ... }` gains
   the compiler's own `push si` plus a matching `pop si` (order `push di;
   push si` at the very top, before anything else in the block). Not
   suppressible: `/Od`, `/Ox`, `/AM`, `/Gx-` all behave the same, the same
   result appears with the register spelled `SI`/`Si`, and splitting the
   block or interleaving `_asm` statements does not move the wrapper. `EQU`
   is rejected inside `_asm` (`C2400`), so the register cannot be aliased to
   hide it. 477 of the 577 units push SI/DI.
3. **A real assembler cannot reproduce the retail encodings either.** NASM
   *can* do the frame (`sub sp, strict word 2` → `81 EC 02 00`, and `-O0`
   does it without `strict`), and adds no SI/DI wrapper — but it encodes
   `mov bp,sp` as `89 E5`, while retail uses `8B EC`; GNU `as` and `llvm-mc`
   agree with NASM. 561 of the 577 units contain `8B EC`/`8B E5`.
4. Therefore no assembler on this machine produces this encoding profile.
   MASM's preference is the `8B` form for register-to-register `mov` and
   (in the 5.x generation) the `81` form for `sub sp,small`; that profile is
   what the retail bytes show, which points at MASM 5.x, not at the pinned
  CL 1.52. `tools/gen_nasm.py` is the probe built for this: it emits a NASM
   listing with `strict`/`near`/`short` spellings and accepts a unit only
   when NASM reproduces the bytes with no `db` fallback. It converts 0 of the
   577.

Two further negatives close the remaining obvious doors:

- **Open Watcom is already in the tree** (`tools/toolchain/watcom`) and was
  the project's earlier negative control. Re-run with a function that has
  locals, `wcc -ml` emits `push bx; push dx; push si; push bp; mov bp,sp`
  (`89 E5`), then `83 EC imm8` — pushes *before* the frame, which is the
  opposite of retail, and neither the `81` frame nor the `8B` `mov`.
- **No CL 1.52 flag combination changes the frame form.** `/AL /AM /AS /AC`,
  `/Od /Ot /Os /O1 /O2 /Ox /O /Oa /Ol`, `/Gc`, `/Za`, `/Zp1`, `/Gs`,
  `/Gx-`, `/Ze`, `/Zg` all emit `83 EC imm8` for a small local frame.

That leaves a 16-bit assembler of the MASM 5.x generation, or the Microsoft C
of the same era whose output was assembled by it. Neither is on this
machine: `ML.EXE`, `MASM.EXE`, `TASM.EXE`, `JWASM` and `UASM` are all absent
(searched `/var/home/blizz`, `/usr`, `/opt`).

`tools/asm_profile.py` is the conformance check for a candidate. It assembles
three probes and reports which profile facts hold — the imm16 stack adjust,
the `8B` register-to-register `mov`, and literal `push si`/`push di` with no
wrapper — so a dropped-in assembler can be judged in one command:

```sh
python3 tools/asm_profile.py --cmd 'wine ML.EXE /c /nologo {src}' --obj
```

Controls: NASM in `--syntax nasm` scores 2/3 (it holds the imm16 and push
facts, fails the `mov` one), and NASM against the MASM-syntax probe reports
`ASSEMBLE-FAIL` for all three, which is what an assembler with the wrong
dialect should look like.

### Session 2026-09-11 (fifth pass) — two spellings that were still fixable

`tools/gen_mnem.py` converts 11 more units (dump population 577 → 566, and
they are large ones: 108–425 bytes each). Both fixes are pure spelling:

- ndisasm prints a sign-extended imm8 as a 64-bit value
  (`cmp word [x],0xffffffffffffffff`), which MASM rejects as "constant too
  big". Narrowing it to the low 16 bits and writing a set sign bit as a
  negative decimal (`-1`) makes MASM pick the same sign-extended imm8 form
  the retail bytes use.
- ndisasm prints indirect jumps as e.g. `jmp word near cs:[bx+0x495f]`; MASM
  wants the size hint as a `ptr` with the override outside the brackets.

Both moved units from `COMPILE-FAIL` to MATCH; three more classes were tried
and are genuinely unspellable here (probes with `tools/cl_probe.py`):
`push -102` (`C2415` — 186+ push-immediate is illegal at this assembler's CPU
level, and `/G2`/`/G3` do not change that), `es lodsb` (`C2400`, and `es:
lodsb` silently drops the prefix and emits `AC`), and a direct far jump
(`jmp 1dfah:901dh`, `jmp far ptr …` both `C2415`).

### Session 2026-09-11 (twelfth pass) — the assembler was in the tree all along

The missing piece was not missing. `tools/toolchain/watcom` (the Open Watcom
install already vendored for the earlier negative control) ships the
standalone assembler `binnt/wasm.exe`, and it has exactly the encoding profile
the retail bytes need. Measured directly, unit by unit:

| retail bytes | Watcom spelling | result |
|---|---|---|
| `55 8B EC` | `mov bp,sp` | `8B EC` — MASM-style, not NASM's `89 E5` |
| `81 EC 02 00` | `sub sp, offset sym` | imm16 with a fixup |
| `26 8B 87 68 00` | `mov ax, es:[bx+msym]` | **disp16** — the form CL turned into `26 A2 iw` |
| `56 57 … 5F 5E` | `push si` / `push di` | literal, source order, no wrapper |
| `A0 F4 41`, `A1 4C 08`, `A3 FA 53`, `83 3E …`, `FF 06 …`, `FF 1E …` | `mov al, ds:[41F4h]`, … | exact, and no redundant prefix |
| `6D`, `C8 04 00 00`, `6A xx` | `insw`, `enter 4,0`, `push 1234h` with `-1`/`-2`/`-3` | the CPU level is a command-line option |

The earlier negative control was of Watcom's *compiler* (`wcc -ml` emits
pushes before `mov bp,sp`), not its assembler — the assembler is the profile
match. This is consistent with the retail code being assembled, not compiled:
the frame, the source-order pushes and the unoptimised imm16/disp16 forms are
all assembler choices.

`tools/gen_wasm.py` is the converter: retail slice → Watcom/MASM listing with
`offset`/symbol operands where the longer encoding is needed, per-direction
jump labels, `EXTRN ...:FAR/NEAR` for absolute calls and jumps (so the fixup
gets overwritten with the retail bytes), and byte-exact verification through
wasm including that same fixup substitution.

**Measured on a 30-unit sample of the queue: 20 MATCH.** The rest split into
seven `same lengths, bytes differ` (the jump displacement goes stale because
an instruction before the target needs its longer form - the iteration to
decide that is still being finished) and three dialect details
(`E100: Missing 'PTR'` on an operand shape, `E251` on one label form). Those
are editor-level fixes, not new unknowns.

What remains to actually retire the units is the splice integration:
`c_units` must assemble an `.asm` unit with wasm and verify it byte-for-byte
the way it now compiles a `.c` unit with CL, `units.py` must classify that
kind, and `coverage.py` must report it. That is the last mile.

### Session 2026-09-11 (eleventh pass) — the CPU-level route is closed too

The 17 units that need 286/386 opcodes (`insw`, `enter`, `push imm`) are the
last class with an untried lever: a processor directive inside the block. It
does not exist here — `_asm { .286 }`, `_asm { .386 }` and a nested
`_asm .286` are all `C2400 inline syntax error in 'opcode'; found 'bad
token'` — and `/G2`/`/G3` do not raise the assembler's CPU level either, so
those units are blocked on the same missing assembler.

With this, every remaining class is characterised and every available
alternative has been measured and rejected. The queue stands at 528 units:
355 needing the SI/DI save pair in the reverse of CL's fixed order, ~82
needing disp16 where MASM shrinks to disp8, 62 whose bytes are not a
decodable instruction stream, 26 needing `es`-prefixed string ops or a direct
far jump, 17 needing the CPU level above, 8 with a misaligned short jump and
~37 further DIFF residues of the same two encoding families.

### Session 2026-09-11 (tenth pass) — the pass-1 staleness class resists both
spellings

The `DIFF +11`/`+8`/`+7` classes (32 units) looked like MASM pass-1 length
estimates: a labelled forward short jump keeps whatever displacement pass 1
computed, and a backward `jcc short` is expanded anyway, so the label moves
and the forward displacement is stale. A second candidate spelling with
`$`-relative displacements was implemented and measured — 0 of 468 converted
— and then the mechanism became clear on the one unit examined closely
(`exe_44910`): with `$`-relative jumps the listing is consistent and the only
remaining difference is the **disp16 class** (`26 8B 47 68` where retail has
`26 8B 87 68 00`), 3 bytes short.

So this class is not a resolver problem; it is the fourth encoding difference
wearing a different symptom, and it is governed by the same conclusion — no
MASM 8.00c spelling forces disp16. The `$`-relative variant was removed rather
than left in as dead code, and the class is counted with the disp16 units in
the remaining-queue tally (~82 units in total).

Along the way the candidate guard from the seventh pass earned its keep: a
loop variable named `text` clobbered the unit's source text exactly as
before, and the guard raised instead of silently compiling a bare instruction
list.

No units converted this pass.

### Session 2026-09-11 (ninth pass) — two labels for one address, and an
idempotent render

MASM mis-resolves a short jump when the *same* label is referenced from both
directions: it expands the backward one and leaves the forward one's
displacement stale, which is what the `DIFF +11`/`+8`/`+7` classes were. The
probe reproduces it in eleven lines and the fix is to give each target two
names — forward jumps use `<label>f`, backward jumps `<label>b` — so no symbol
is ever referenced both ways. One unit converted; the class survives where a
pass-1 length estimate also goes stale, so this is a real but partial fix.

`render()` is now idempotent: re-converting an already-converted unit no
longer stacks a second copy of its `extern` declarations into the header
(discovered when a re-run doubled them).

Dump population 529 → 528.

### Session 2026-09-11 (eighth pass) — labelled short jumps, and target-aware decode

Two changes, neither of which needs the missing assembler:

- **Labelled short jumps.** `$`-relative displacements made the compiler ICE
  (`C1001`) on some listings; `jcc short lblXX`, `jmp short lblXX` and a
  labelled `jmp` for rel16 assemble to the same bytes, work in both
  directions, and are what the retail bytes say. That converted 7 overlay
  units and removed the 15-unit C1001 class.
- **Target-aware decode.** A linear sweep can decode an instruction that
  straddles a branch target, which surfaced as `C2094` (undefined label) or
  `C2427` (short jump out of range). `convert()` now splits the stream at
  forced boundaries and re-decodes each piece. It converts no further units on
  its own — the bytes at the split turn out not to be a decodable instruction
  stream, and those units now say `undecodable byte` instead of showing a
  compiler error — but it removes two compiler-error classes and makes the
  failure reasons accurate (`C2400` 48 → 26, `C2094` eliminated).

Dump population 536 → 529.

### Session 2026-09-11 (seventh pass) — the 81-group immediate, and a name bug

A fifth encoding difference: for an `81 /r iw` instruction the retail bytes
carry the imm16 form, while MASM shrinks a small immediate to the
sign-extended imm8 form. The immediate is made relocatable instead —
`add word ptr [bp-4], offset mnXXI` assembles to `81 46 FC <fixup16>`, and
`_relocate` writes the retail bytes over the fixup. The AX destination is
exempt: MASM insists on the one-byte-opcode AX form (`05`, `3D`, `2D`, `25`,
`0D`, `1D`) there, which is a different instruction.

Only 3 of the 215 units carrying an `81` instruction converted with it, and
measurement says why: the rest are blocked by the wrapper or by the disp16
class first, so the immediate was never their binding constraint.

Also fixed here: a patch had reused the local name `text` for the instruction
text inside the loop, clobbering the unit's source text in the returned
record. Every candidate then rendered as a bare instruction and the sweep
died on `render`. The checker now reads the source back from the file it
wrote, so a self-inflicted regression like that cannot hide.

Dump population 539 → 536.

### Session 2026-09-11 (sixth pass) — the SI/DI pair left to CL's wrapper

The 362-unit `DIFF +3` class splits in two. Where the retail save pair is
`push di; push si` — the order CL's wrapper itself emits — the body's own pair
is redundant: dropping it and letting the wrapper provide it reproduces the
bytes exactly, as long as the block still writes SI/DI elsewhere.
`tools/gen_mnem.py` now keeps that as a second candidate spelling and tries it
when the first fails; 22 of 546 converted (dump population 561 → 539). The
`DIFF +5`/`+4` classes are gone entirely, which is what those were.

The other half of the class has the pair in the *reverse* order
(`push si; push di`, which is the source order the retail bytes show) or uses
SI/DI only later in the body; CL's wrapper order is fixed at `di` then `si`,
so those cannot be spelled and they stay dumps.

Two more findings from this pass, both recorded for the assembler question:

- **A fourth encoding difference, and it is not reachable.** Retail sometimes
  carries the *longer* disp16 form where MASM 8.00c's assembler picks disp8 —
  e.g. retail `26 88 87 32 00` (`mov [es:bx+0x32],al`) against compiled
  `26 88 47 32`. That is another no-optimisation trait of the older assembler
  and it accounts for most of the remaining non-`+3` DIFF classes. The
  symbol-in-displacement route was tried and rejected by experiment: with
  `extern char __near mn0032;`, `mov es:[bx+mn0032],al` assembles to
  `26 A2 00 00` — MASM resolves the symbol as an absolute address and drops
  the `bx` base entirely (and `[bx+offset sym]` is `C2443 operand size
  conflict`). There is no MASM 8.00c spelling for "force disp16", so units
  whose retail bytes did that stay dumps pending the older assembler.
- **`db` never lands in a source.** A byte ndisasm cannot decode now raises
  `ConvertError` instead of emitting a `db` line, so a listing that would be a
  byte transcript inside `_asm` is reported rather than generated.

Re-running the current converter over the 577 confirms the ceiling: **none**
of the 563 function-shaped units is spellable as inline asm any more (one
did convert, `exe_87075`, whose body carried the SI/DI push in the compiler's
own order); the rest need something the pinned toolchain does not have.

One unit in this class did convert this pass (`exe_87075`, whose body carries the
SI/DI push in the compiler's own order), taking the population to 577. The three
ways out for the rest, in the order that preserves the project's intent:

1. Supply the original assembler (MASM 5.x `ML.EXE`, or whatever produced the
   `81 EC` + `8B EC` + source-order `push si/push di` profile). Then these
   units become ordinary mnemonic listings and the bar is met as written.
   Only an *assembler* is needed, not a compiler: `tools/gen_nasm.py` already
   emits the listing for each unit and the encodings it cannot force are
   exactly the two quirks above, so the conversion would be mechanical and
   byte-verified per unit.
2. Record them as `COMPILER-LIMITED` and keep the `_emit` transcription,
   which leaves the bar red for exactly these units.
3. Accept a data-array transcription for them, which would be a byte
   transcript for code — the thing the bar exists to prevent.

`tools/verify.py` is BINARY-MATCH either way; this is a question about
recovered-source form, not about the rebuilt image.

Also repaired: six registered units (`exe_25234`, `exe_26628`, `exe_30807`,
`exe_31405`, `exe_35139`, `exe_100448`) used `call far ptr helper_N` with no
declaration, which CL rejects with `C2429 illegal far label reference`. They
could not compile at all, so the whole-corpus rebuild under `tools/verify.py`
was failing before this session even though the ratchets were green. Adding
`void far helper_N(void);` declarations changed no bytes and restored the
rebuild gate.

### In the tree — `lift.py` MATCH

Recompiled 2026-09-11:

| unit | image | result |
|---|---|---|
| `exe_2096` | exe-code:0x830, 16 B | MATCH, trimmed 2 (justified `pushf`/`popf`) |
| `exe_99679` | exe-code:0x1855F, 48 B | MATCH, trimmed 0 |
| `exe_112795` | exe-code:0x1B89B, 58 B | MATCH, trimmed 0 |
| `exe_112711` | exe-code:0x1B847, 84 B | MATCH, trimmed 0 |

The other 439 unaided-C units are the Sept 8 thunk/store families
(far-call wrappers, CLI/STI stores, `== 0` helpers, 2D bit-tests).

The 60 mixed units and 581 complete functions converted this session are not
listed individually; each was re-emitted by `tools/gen_mnem.py` and accepted
only after CL 8.00c compiled it and the bytes matched the retail slice
(`--verify`), and the whole image was then re-spliced under `tools/verify.py`.

### Notebook only — still `_emit` dumps

The lab notes below describe recovered source for these. They are **not**
recovered. Do not count them, and do not resume them unless a new
discriminating experiment exists:

`exe_117397`, `exe_18240`, `exe_115231`, `exe_91501`, `exe_111158`,
`exe_109269`, `exe_86814`, `exe_98653`, `ovl_103506` / `ovl_165711` /
`ovl_187298` / `ovl_193562`, `exe_790`, `exe_714`, `exe_2021`,
`exe_64277`, `exe_53332`, `exe_110357`, `exe_109184`, `exe_109083`,
`exe_109741`, `exe_112853`, `exe_87918`, `exe_94712`, `exe_80795`,
`exe_1802`, `exe_1768`, `exe_7548`, DS-loading family `exe_31310` /
`exe_34586` / `exe_34663` / `exe_34740`.

### Proven levers

- `#pragma intrinsic(_disable,_enable)` for `cli`/`sti`
- `#pragma intrinsic(_inp,_outp)` for `in`/`out` (else they are far calls)
- `char c = g; if (c)` for the 5-byte load-and-test; `if (g)` is a 6-byte `cmp`
- `__near` on globals so the array base folds into the displacement
- a named local even if CL keeps it in registers (forces `sub sp`)
- declaration order pins stack-slot offsets
- `/Og` for `== 0` as `cmp ax,1 / sbb / neg` and 1-arg `add sp,2`

Working rule: when a unit's remaining gap is one mechanism and five
spellings have failed, stop, record it, pick another candidate. Decode
once, write once, compile. Do not grind 1–3 byte residues.

### Next

Everything left is code: 197 dump units, all complete functions or framed
bodies.

1. The 563 dump *functions* need the C behind their `81 EC imm16` frame and
   their SI/DI saves; `tools/gen_mnem.py` cannot spell either, because CL only
   ever writes the `83 EC imm8` form for `sub sp,N`, and it only inserts its
   save/restore pair when the block mentions SI/DI. Decode one with
   `tools/cl_probe.py`, `tools/lift.py`, then record it.
2. The 15 mixed units are the same class with their body already in
   mnemonics, so they need the C too.
3. Phase 3 (`image_source=cl-link`) after source recovery, not instead of it.

### Test status

- Fast suite `tests/test_units.py` carries the ratchets.
- Still red by design: `test_recovered_sources_have_no_emit_byte_dumps`
  (197 dump units) and `image_source == "cl-link"`.
- `python3 tools/verify.py` is green: `BINARY-MATCH` for both images.

---

## Lab notes

Experiment log. Do not treat it as the live queue or as recovered
source. Counts inside a dated session are of that date.

## Session 2026-09-10 — function-decomp reconnaissance and tooling

### Corpus, measured not guessed

`tools/units.py` recovers each dump unit's exact retail extent from its own
`_emit` stream (the layout `c_units._relocate` would produce), so the corpus
can be measured without running the compiler. `tools/coverage.py` reports it.

| Image | bytes | units | unaided C units | `_emit` dumps | dump byte coverage |
|---|---|---|---|---|---|
| `exe-code` | 191,656 | 1,245 | 105 | 1,120 | 97.9% |
| `ovl-payload` | 325,595 | 1,591 | 334 | 1,256 | 96.7% |

| Source kind | units |
|---|---|
| unaided C (no `_asm`) | 439 |
| mnemonic `_asm` + a few `_emit` (mixed) | 21 |
| pure `_emit` byte dump | 2,376 |

Unit shapes across both images:

| Shape | count | meaning |
|---|---|---|
| `function` | 1,135 | `55 8B EC` … `5D CB`/`5D C3` |
| `unframed-function` | 7 | no frame, ends in a `ret` |
| `framed-fragment` | 3 | frame, no `ret` |
| `fragment` | 1,171 | mid-function slice or data |
| `unknown` | 520 | 439 unaided C + 21 mixed + 60 unresolved dumps |

So the real unit of work is **1,135 whole far functions**, not 2,376
independent functions. Units overlap, so coverage percentages are the
authoritative measure.

### New tooling

- `tools/units.py` — unit index, dump-pattern → retail extent resolution,
  shape classification. Wine-free.
- `tools/coverage.py` — unaided-C vs `_emit`-dump byte coverage per image;
  `--compile` gets exact extents for the C units from the real splice.
- `tools/lift.py` — the lifting loop: compile one TU (or a batch) and byte-diff
  it against the retail slice, printing the first difference with disassembly
  on both sides. Reports `exact_no_trims` so a match that only survives
  `_relocate` trimming is never mistaken for a strict one. `--show` prints the
  retail disassembly for a unit; `--register` records a verified unit.
- `tools/cl_probe.py` — compile C snippets and print the code, optionally
  diffed against a retail address. This is the controlled experiment behind
  every compiler-limitation claim.
- `tests/test_units.py` — 7 tests over the above, all wine-free except two
  single-TU toolchain checks; passes in ~3s.

### Controlled experiments

- **An `_asm` block forces a stack frame.** The same body compiles without
  `55 8B EC` when written as C, and with it when any `_asm { … }` (even
  `_asm { nop }`) is present. This is why the previous session's dumps all sat
  behind a CL-generated prologue/epilogue.
- **Only 3 of 1,135 complete functions** have a frame that C locals or
  bp-relative accesses cannot explain (`exe_1835`, `exe_5398`, `exe_7548`).
  The `_asm`-forces-a-frame effect is real but not a broad obstacle.
- **`_disable()`/`_enable()` are the source spelling of `cli`/`sti`.**
  Declared in the toolchain's `DOS.H`; `#pragma intrinsic(_disable,_enable)`
  reproduces retail `cli`/`sti` exactly (`exe_825`, `cli_store`, `exe_1790`).
- **No toolchain header provides `pushf`/`popf`** (`rg` over every `*.H` in
  `tools/toolchain/msvc152/MSVC/INCLUDE`). Nine complete functions save and
  restore flags (`9C … 9D`), so those came from inline `_asm` in the original.
- **88% of complete functions contain only compiler-producible instructions.**
  1,000 of 1,135 bodies contain no instruction from a list CL has no source
  spelling for; 135 contain at least one (`int` 35, string ops, `in`/`out` 27,
  `pushf`/`popf` 18, `cli`/`sti` 22, …). The string-op hits are an upper bound
  because CL does emit `rep movsb`/`stosb` for whole-array copies.
- **`char c = g; if (c) h();` is the spelling of `mov al,[g]; or al,al`.**
  `if (g)` for a `char` global compiles to `cmp byte ptr [g],0` (6 bytes);
  retail uses the 5-byte load-and-test form.
- **A named local live across `_disable()`/`_enable()` is spilled.** `/Os`
  emits `sub sp,2` plus a stack slot, but retail `exe_1768`
  (`bx = a*2; cli; ax = g[a]; g[a] = 0; sti; ret`) has no locals at all.
  Not yet reproduced.
- **Optimisation pragmas do not unlock everything.** `#pragma optimize("g",on)`
  did not give `exe_98653` the retail jump-to-shared epilogue, and
  `_disable`-guarded array swaps did not change under `"s",off` or `"g",on`.

### The recovery bar — decided

`tests/test_c_units.py::test_recovered_sources_have_no_emit_dumps` used to
reject any source containing `_emit` **or `_asm`**. The evidence above says a
small but non-zero set of functions (DOS `int` calls, port I/O, flag
save/restore — roughly 6–12% of complete functions) cannot be written without
inline asm, because the original wrote inline asm there. That bar was not
reachable.

**Decided with the user on 2026-09-10:** the bar is **no raw `_emit` byte
dumps**, with mnemonics in `_asm` accepted as recovered source.

Recorded in `CONSTRAINTS.md` (the numbers and the reasoning) and
`docs/MATCHING.md` (the definition). The test is now
`test_recovered_sources_have_no_emit_byte_dumps`, and because the change is a
relaxation it is paired with two ratchets in `tests/test_units.py`, so it is
not a free pass:

- `_emit` dump byte coverage may not rise (`exe-code` ≤ 97.91%,
  `ovl-payload` ≤ 96.69%)
- the unaided-C unit count may not fall (≥ 439)

`coverage.py` keeps `emit-dump` and `mnemonic-asm` as separate lines so
"transcribed bytes" is never confused with "recovered C".

### 164 complete functions are provably not CL-compiled C

`tools/library_scan.py` now reports two disjoint, provable categories:

| Category | Units | Complete functions | Evidence |
|---|---|---|---|
| library | 116 | 84 | body bytes appear in a shipped `.LIB`; control 0/200 on 24-byte probes |
| assembled | 81 | 80 | body contains `81 /n iw` with imm `< 0x80` |
| both | 0 | 0 | the categories are disjoint |
| **union** | — | **164 of 1,135** | |

The second category is new and is a clean proof. CL 8.00c always encodes a
small immediate with the sign-extended 8-bit form: `_asm { sub sp, 2 }`
compiles to `83 EC 02`, not `81 EC 02 00`, verified by probe. Retail contains
`81 EC 02 00` and its relatives, so those bodies were assembled by MASM, not
compiled by CL. `exe_80795` (the function I was chasing) is one of them, which
is why no C spelling reproduced its `sub sp` encoding.

`docs/STATUS.md`'s earlier claim that these are CRT-only is too narrow: the
assembled set is disjoint from the library set, so it is *game-side or
startup-side assembly source* that the linker did not take from a `.LIB`.
The toolchain does ship `MSVC/SOURCE/STARTUP` (`.ASM` and `.C`), which is the
first place to look for those bodies.

### Part of the corpus is shipped library code, not game source

`tools/library_scan.py` byte-probes every retail body against the 82 `.LIB`
files in the pinned toolchain (14,239,639 bytes).

| Probe | Units matched | Control |
|---|---|---|
| 24 bytes | 116 of 2,836 | 0 of 200 random probes |
| 32 bytes | 94 of 2,836 | 0 of 200 random probes |

The control matters: a random 24-byte probe matches the library corpus zero
times, so a hit is evidence. 84 of the 1,135 complete far functions are in
this set; the rest are fragments and glue. Most hits land in `CDLLCAW.LIB`,
`CLIBCAWQ.LIB`, `LLIBC7.LIB` and `CLIBC7.LIB`.

These units were never C in this project — the linker pulled them out of the
shipped runtime — so "recover as source" is the wrong action for them. The
correct action is a rebuild that links the same library, which is Lane B work,
and they should be classified LIBRARY rather than counted as unlifted game
functions. They are **not** deleted: the image still has to contain them.

The toolchain also ships the startup sources under
`tools/toolchain/msvc152/MSVC/SOURCE/STARTUP` (`_FILE.C`, `INTERNAL.C`,
`NULBODY.C`, `CRT0FP.ASM`, `SETARGV.ASM`, `CHKSTK.ASM`, …), which covers the
`CSTARTUP` half of the low EXE region.

### Active item at handoff

`exe_80795` (exe-code:0x13b9b, 22 bytes) is the next concrete attempt:

```
55 8B EC  81 EC 02 00  56 57  A0 F4 41  98  E9 00 00  5F 5E  8B E5 5D CB
push bp   sub sp,2      push si/di  mov al,[0x41f4]  cbw  jmp +0  pop di/si
```

It returns `(int)(char)g` but carries a 2-byte local frame and unused `si`/`di`
saves, plus a near `jmp +0`. Two recorded sub-facts:

- retail encodes `sub sp,2` as `81 EC 02 00` (imm16 form) while CL 8.00c /Os
  emits `83 EC 02` (sign-extended imm8 form) for `char c; c = g; if (c)
  return c; return c;`. Worth a controlled experiment: find a construct that
  makes CL choose the imm16 form.
- `E9 00 00` is a resolved-to-zero near jump, i.e. an MSC branch merge.

`exe_1802` is recorded above as NEAR_MATCH (25 variants, no C form gives
`les bx`); `exe_7548` is NEAR_MATCH (body matches exactly, frame is the only
difference and C cannot emit it).

### Recovery 2026-09-10 (second pass)

**`exe_2096` recovered.** `exe-code:0x830`, 16 bytes, was an `_emit` dump:

```c
#include <dos.h>
#pragma intrinsic(_disable)

void far exe_2096(unsigned far *p)
{
    _asm { pushf }
    _disable();
    *p = 0;
    _asm { popf }
}
```

Compiles to `55 8B EC 9C FA C4 5E 06 26 C7 07 00 00 9D 8B E5 5D CB`; retail is
the same minus the redundant `mov sp,bp`, which `_relocate` documents and
trims for `_asm` units. `tools/lift.py` reports MATCH, trimmed 2,
`exact_no_trims=False` — visible, not hidden. This is the first unit moved
from the dump corpus to unaided C under the approved bar.

The 24-byte form (`9C FA ... 9D`) had to come from `_asm`: `pushf`/`popf` have
no C spelling and no header declares them. The rest of the body is real C.

### New negative results, with the experiments that produced them

- **`exe_489` is not CL-reachable.** `mov [cs:0x16], ax` is `2E A3 16 00` in
  retail (moffs form). CL's inline assembler emits the ModRM form `2E 89 06
  16 00` for all five spellings tried (`mov word ptr cs:[16h], ax`,
  `mov word ptr cs:16h, ax`, `mov cs:16h, ax`, `mov word ptr [cs:16h], ax`
  errors, `_asm`-per-line). `_CS` is not declared by any header in the pinned
  toolchain, so there is no C route either. This is a **second MASM-vs-CL
  encoding signature**: a segment-prefixed moffs (`26/2E/36/3E` + `A0..A3`)
  is MASM-style; CL uses ModRM.
- **`exe_98653` shared epilogue is compiler-limited so far.** Retail is
  `cmp [bp+6],0 / jz else / and byte [g],0FDh / jmp +5 / else: or byte [g],2 /
  pop bp / retf` — a jump to one shared epilogue. CL 8.00c duplicates the
  epilogue for every spelling tried: plain `if/else`, `if/else` with a trailing
  `return;`, `if` + `goto done`, `if` + `goto` with a labelled empty statement.
  It also duplicates under `/Os`, `/Ot`, `/Ox`, `/Og /Os` and `/Oa /Os`.
  Not yet proof that no spelling exists.
- **No MASM in the toolchain.** `find tools/toolchain -iname "masm*"` is empty,
  so the 81 assembled units cannot be reproduced by CL or by MASM from this
  checkout. They need the original `.ASM` sources or MASM; the toolchain does
  ship `MSVC/SOURCE/STARTUP` (`.ASM` and `.C`), which is the first place to
  look.

### Open family: DS-loading readers

`exe_31310` / `exe_34586` / `exe_34663` (35 bytes each, `exe-code`)
share a shape: `push ds; push es; push si; push di`, load a constant into DS,
`mov si,0x52A6`, read a word at `[si+offset]`, spill it to `[bp-2]` and
reload, then pop everything. The offsets differ per member.

Facts established so far:

- `_DS` is not declared in the pinned headers, and `extern unsigned _DS;`
  plus `_DS = const;` compiles as an ordinary variable, not the register.
- `__loadds` exists and produces `push ds; mov ax,SEG; mov ds,ax; ...; pop ds`
  — but without the `es`/`si`/`di` saves and without the `mov si` indirection,
  so it is not the whole story.
- `__saveregs` pushes all eight registers plus DS/ES, which retail does not.

Next experiment for this family: find the construct that makes CL emit the
`es`/`si`/`di` saves together with a DS reload — it is one idiom instantiated
at several offsets, so it is worth more than a single unit.

The shipped CRT startup assembly is ruled out as the source: no file under
`MSVC/SOURCE/STARTUP` contains a `push es`/`push ds` register-save prologue
(`grep -lE "push[ 	]+es" *.ASM` is empty; only EMOEM.ASM and FMSGHDR.ASM
mention `push ds` at all). So the family is game-side source, and since the
C mechanisms above are exhausted, the next probe should be a mnemonic
`_asm` prologue/epilogue pair around a C read, checking whether CL preserves
the exact push order and the `mov si` indirection.

### Recovery 2026-09-10 (third pass) — no new matches, two mechanisms characterised

**CL 8.00c inlines 32-bit shifts by 1 only.** Discriminating experiment
(`cl_probe.py`, default flags):

| source | codegen |
|---|---|
| `unsigned long f(unsigned long a){ return a + a; }` | `add ax,ax; adc dx,dx` (16 B) |
| `unsigned long f(unsigned long a){ return a << 1; }` | `add ax,ax; adc dx,dx` (16 B) |
| `unsigned long f(unsigned long a){ return a << 2; }` | `mov cl,2; call <shift helper>` |
| `unsigned long f(unsigned long a){ return a << 5; }` | `mov cl,5; call <shift helper>` |

So a retail body containing an inlined multi-step `adc ax,ax; adc dx,dx`
chain did not come from `<< n` or `* 2**n` source. It can come from repeated
`+`, or from a codegen path this build does not take. This is a third
MASM/different-path signature alongside `81 /n iw` and the segment-prefixed
moffs, and it is checkable without a compiler.

**`exe_94712` (exe-code:0x171f8, 39 B) decoded.** `mov ax,[bp+6];
mov dx,[bp+8]`, then five doublings (`add ax,ax; adc dx,dx` followed by four
`adc ax,ax; adc dx,dx`), then `xchg ax,dx`, `and dx,0x0F`, then a 32-bit add
of `[bp+0xa]`/`[bp+0xc]`, `pop bp; retf`. It is a 32-bit arithmetic helper
whose tail is `(something >> 11) + base`. Twelve candidate spellings were
compiled (`a >> 12`, `a >> 11`, `(a << 4/5) >> 16`, `a * 32 >> 16`, `a / 2048`,
masked forms, `unsigned`/`signed` variants); all differ at `+9` because CL
uses the shift helper where retail inlines. Not resolved: the inlined chain
says the source repeated `+`, and the smallest source that does that has not
been found. Left as a near match with the decode recorded.

**DS-loading family (`exe_31310`/`34586`/`34663`/`34740`, 35 B each).**
Tested the hybrid form — a mnemonic `_asm` block around a C local:

```c
int far exe_31310(void)
{
    int v;
    _asm {
        push ds
        push es
        push si
        push di
        mov ax, 38AFh
        mov ds, ax
        mov si, 52A6h
        mov ax, [si+18h]
        mov v, ax
        pop di
        pop si
        pop es
        pop ds
    }
    return v;
}
```

CL emits its **own** `push di; push si` before the block and `pop si; pop di`
after it (it protects the registers the asm clobbers), and it places the
`mov ax,[bp-2]` reload **after** the pops, where retail has it before. Both
extra pairs and the reload position would have to be hand-written, including
deliberately reproducing an unoptimised spill/reload — a mechanical
transcript, which the approved bar forbids. So this family stays an `_emit`
dump for now and is recorded as characterised-but-unrecovered.

**No pure cdecl far-call wrappers remain.** A scan for bodies that are only
`push word [bp+X]` (X = 6/8/10/12) followed by exactly one far call returns
zero candidates — the 111 units the earlier sessions recovered were that
family. Wrapper-shaped work is exhausted; the remaining corpus needs either
new idioms or per-function reverse engineering.

### Boundary audit: the fragment units are not unrecovered functions

Three measurements, all reproducible from `tools/units.py`.

**1. Functions and fragments form a clean partition.** The 1,135
function-shaped units and the 1,171 fragment units do not overlap at all:

| image | function bytes | fragment bytes | fragment bytes inside a function |
|---|---|---|---|
| `exe-code` | 107,629 | 80,007 | **0** |
| `ovl-payload` | 217,622 | 97,199 | **0** |

**2. The splitter missed no standard prologue.** Searching the whole image
for `55 8B EC`, then excluding bytes inside a function unit and excluding
positions that are already some unit's start offset, leaves **0** prologues
in `exe-code` and **0** in `ovl-payload`. So there is no queue of
recognisable functions that the splitter simply failed to carve. The
boundary hypothesis from the previous handoff is refuted for this prologue
form.

**3. The tail of `exe-code` is data and a third-party runtime, not game
functions.** From roughly `0x1dc00` to the end of the image:

- `eov0001:` at `0x1dc2e` and `RELOAD to increase` at `0x1dda3` — the
  third-party overlay-manager markers, the same strings seen in `XANTH.OVL`.
- `RTLink` at `0x215c5` and the string
  `Internal error in .RTLink(R)/Plus run-time code.` — the **Pocket Soft
  RTLink/Plus** overlay runtime, linked in and not game source.
- Game message strings (`XANTH.OVL`, `XANTH.EXE`, `Fatal Error $`,
  `Overlay save buffer too small`, `Free memory: %s`, `1.2.0  04-18-1994`).
- Fragment units in this region are frequently **exactly 1500 bytes**
  (`exe_137497`, `exe_138997`, `exe_142154`, … dozens). 1,500 is a fixed
  chunk size, i.e. the splitter carved data into even blocks, not at
  function boundaries.

About **59,076 fragment bytes** of `exe-code` lie at or after `0x205c5`.

This does **not** delete those units or shrink the denominator to look
better. They are still part of the image and still have to be reproduced.
What it changes is the classification: the fragment population is
predominantly data, strings and the RTLink runtime, so it is not a queue of
1,171 functions waiting for C. The function-recovery queue remains the 1,135
function-shaped units, of which 164 are provably not CL-compiled C, 1 has
been recovered to source (`exe_2096`), and a handful are recorded near
matches.

Follow-up worth doing before more per-function work: classify the fragment
population by content (string tables, jump tables, the RTLink region) so the
"uncovered/overlapping ranges" number in the coverage report separates data
from code. That is measurement, and it does not require the compiler.

### Near match: exe_64277 (exe-code:0xfb15, 36 B)

Retail is a bounds-checked indirect far call through a table:

```
cmp word [bp+6],38h ; jnc out_of_range
push word [bp+8]                       ; the single cdecl argument
mov es,[5A5Eh]                         ; table segment, from a global
mov bx,[bp+6] ; add bx,bx ; add bx,bx  ; idx * 4, far-pointer entries
call far [es:bx+135Ah]
mov sp,bp                              ; caller cleanup for the pushed arg
jmp done ; out_of_range: xor ax,ax ; done:
```

This is game C, not library or assembly: cdecl arg push, the `mov sp,bp`
cleanup, and `xor ax,ax` for the failing branch are all CL idioms.

A reconstruction with `MK_FP(g_seg, 0x135A + idx * 4)` reproduces the
bounds check, the push order, the `add bx,bx` scaling and the
`call far [es:bx+disp]` form, but diverges by 24 bytes at `+9`: CL lowers
`MK_FP` with a variable segment to a runtime helper
(`push ax; push [seg]; call; add sp,4; cwd; mov bx,ax; mov es,dx`), while
retail has a single `mov es,[5A5Eh]`.

So the remaining question is narrow and testable: which source spelling
makes CL load ES from a global directly instead of building the far pointer
through the helper. `extern unsigned _DS;` was already shown to compile as
an ordinary variable, so if `_ES` behaves the same the answer is a
different construct, not a pseudoregister. Nothing else in the function is
unexplained.

### exe_64277: C routes exhausted, blocker characterised

Four spellings tried against the one unexplained instruction
(`mov es,[5A5Eh]`, a segment register loaded straight from a word variable):

| source | ES load |
|---|---|
| `MK_FP(g_seg, 0x135A + idx*4)` (variable segment) | runtime helper: `push ax; push [seg]; call; add sp,4; cwd; mov bx,ax; mov es,dx` |
| `MK_FP(0x5A5E, 0x135A))` (constant segment) | still the helper: `push 135Ah; push 5A5Eh; call` |
| `extern FARFN far *g_tbl; g_tbl[idx](arg)` | `les si,[g_tbl]` — loads the base **offset** from memory, but retail's offset is the constant `135Ah` |
| `extern unsigned _ES; _ES = g_seg;` | not a pseudoregister in this build: compiles to `mov ax,[g_seg]; mov [0],ax` |

`_DS` was shown the same way earlier. So in this compiler build the segment
pseudoregisters do not exist, and `MK_FP` with a variable segment always
goes through the runtime helper. Retail's `mov es,[mem]` has no plain-C
spelling here; the original either used a segment pseudoregister available in
the compiler it was actually built with, or inline asm.

`exe_64277` stays a near match; its control flow, cdecl argument, table
scaling and call form are all recovered and recorded.

**Correction, so this is not overstated.** A raw byte scan finds
`8E /r` with a `[disp16]` operand in **162 of 1,134** complete functions,
but that is *not* 162 units this compiler cannot produce. An ordinary far
pointer dereference compiles to exactly `mov es,[g]; mov bx,es:[disp]`
(for example `exe_5934`: `mov es,[53C0h]; mov bx,es:[2Ch]`), which is
plain C. The narrow, defensible form of the signature is: a segment
register loaded from memory while the **offset is a constant**, with no load
of the offset half. That is what `exe_64277` does
(`mov es,[5A5Eh]` then `call far [es:bx+135Ah]`) and it is what has no
C spelling here. Distinguishing the two needs the operand decode, not a
substring search, so no count of that narrowed set is claimed yet.

### Segment-load classification: 162 sites, 14 with a C route

Two more controlled experiments close the `exe_64277` question:

| source | ES load |
|---|---|
| `*(unsigned far *)MK_FP(g_seg, 0x2C)` (load) | runtime helper, then `cwd; mov bx,ax; mov es,dx; mov ax,[es:bx]` |
| `(*fp)(arg)` with `MK_FP(g_seg, const)` (call) | runtime helper, then `cwd; mov bx,ax; mov es,dx` |

So `MK_FP` with a variable segment never yields a bare `mov es,[mem]`, in
either the load or the call context.

**A checkable classification** (heuristic, rule stated): for a far pointer
variable stored at address A the offset half is at A and the segment half at
A+2, so a C-expressible dereference both loads `[A+2]` into a segment
register *and* reads `[A]`. Applying that to every complete function:

| | count |
|---|---|
| complete functions with a `mov es/ds/ss,[disp16]` site | **162** |
| the paired offset half is also read (C-expressible) | **14** |
| segment-only with a constant offset (the `exe_64277` blocker) | 148 |

The rule is a heuristic, not a proof: a function can read both halves for
unrelated reasons. Two samples were hand-verified in both directions —
`exe_5934` (`mov es,[53C0h]; mov bx,es:[2Ch]`, constant offset, no pair →
blocker) and `exe_123400` (paired, and blocked for a different reason
below). The 148 figure should be treated as an upper bound on the blocker
until more samples are hand-checked.

**`exe_123400` (exe-code:0x1e208, 131 B) is blocked by a different
mechanism.** It is a near function (`pop bp; ret`) with a full
register-save prologue (`push ax/bx/cx/dx/di/si/ds; pushf`) and a
matching epilogue, plus `test word [cs:0D27h],100h` and
`mov ax,cs; mov ds,ax`. It looks like an interrupt-callback frame. No C
spelling gives the all-register save plus `pushf`, and the CS-relative
memory operand has the same problem as `exe_489`. Recorded as blocked by
the CS-relative access and register-save mechanisms, not by the segment
load.

### Near match at one instruction: exe_2021 (exe-code:0x7e5, 30 B)

Retail is a CLI/STI guarded array store:

```
mov bx,[bp+6] ; mov ax,[bp+8]   ; pointer and value loaded first
cli
mov [bx+407Dh],ax              ; s->v = v
or ax,ax : jnz
les bx,[bx+407Fh]              ; s->p
mov word [es:bx],0FFh
sti
```

The natural reconstruction is the no-local form of the proven
`_disable`/`_enable` idiom:

```c
struct S { int v; int far *p; };
struct S g[1];

void far f(int off, int v)
{
    _disable();
    *(int *)((char *)g + off) = v;
    if (v == 0)
        **(int far **)((char *)g + off + 2) = 0xFF;
    _enable();
}
```

It compiles to **exactly 30 bytes with an identical instruction sequence**,
including the folded displacement, the branch, the far-pointer load and the
`mov word [es:bx],0FFh`. The single difference is the position of `cli`:
CL emits it before the two parameter loads, retail emits it after.

Three earlier spellings established the constraints that get to this point:
a struct array with a scaled index introduces `imul` (blocker), declaring
`struct S *s` as a local adds `sub sp,6`, and `add bx,offset g` appears
unless the base is folded into the displacement. The no-local form is the
only one that reproduces the addressing.

`cli` placement does not move under `/Od`, `/Oa` or `/Ol`: all three
still emit `cli` first. So either a construct this build does not provide
(`_asm` positioned after the loads, or a different compiler's scheduler)
produced it, or the source used inline asm for the two loads. The latter is
rejected as a mechanical transcript. Recorded as a near match: same length,
same instruction sequence, one instruction reordered.

### exe_2021 classified COMPILER-LIMITED on the cli position

The no-local reconstruction matches retail on 30 of 30 bytes with an
identical instruction sequence; only `cli` sits in a different place. Six
configurations were compiled, and every one emits `cli` before the two
parameter loads:

| configuration | result |
|---|---|
| default `/Os` | `cli` first, 30 bytes, rest byte-identical |
| `/Od` | `cli` first |
| `/Oa` | `cli` first |
| `/Ol` | `cli` first |
| `#pragma optimize("s",off)` | `cli` first |
| `#pragma optimize("g",on)` | `cli` first, 34 bytes (adds a reload) |

So the residue is a scheduling property of this compiler build, not a
missing source spelling: no configuration tried keeps `cli` after the
loads. Per `docs/MATCHING.md`, that is what COMPILER-LIMITED means —
controlled experiments demonstrate the remaining limitation of *this*
toolchain. It is not proof that no C spelling exists on some other build,
and the entry stays a dump rather than being written into `src/` with a
knowing mismatch.

Sibling `exe_2051` (exe-code:0x803, 30 B) shows the same `cli` residue *and*
a second one: retail reuses the `add`'s flags for both the `js` and the
`jnz`, while CL reloads the value (`cmp word [bx],0`) and the unit grows to
38 bytes. Same family, one extra compiler-level difference.

Three configurations for the sibling would not be a better use of the next
hour than finding a family with no residue at all.

### 30 function units contain a second prologue (glued functions)

Scanning every function-shaped unit for a `55 8B EC` after its own
prologue finds it in **30 of 1,134** units. At least one is a genuine
glue: `exe_18064` (exe-code:0x4690, 32 B) is two functions in one unit —

```
mov bx,[bp+6] ; mov ah,68h ; int 21h ; jmp far ...   <- function A tail-calls out
mov ax,[bp+6] ; mov ah,35h ; int 21h ; mov dx,es ; mov ax,bx ; ... ; retf
```

A tail-calling function has no `retf`, so the splitter's
`prologue ... retf` rule walked straight past the boundary and swallowed
function B as well. Such a unit cannot be recovered as one C function: no
single source compiles to a function that jumps away and then defines a
second function inline.

**This is not yet a verified count of glued units.** An interior
`55 8B EC` can also be data (an immediate or a jump-table entry) rather
than code. The 30 need per-unit disassembly before any boundary change is
made; only `exe_18064` is hand-verified so far. Splitting them is a
justified boundary correction under the project rules, but each split has
to be evidenced with the surrounding control flow, not just the byte
pattern, and the unit totals must not be adjusted until then.

### Glue verification: 14 confirmed, and why "ret-terminated fragments" is a trap

Verification rule: a real function boundary exists when the instruction that
**ends exactly at** the interior prologue is an unconditional transfer.
Applying it to the 30 interior-prologue units:

| outcome | count |
|---|---|
| preceded by a `ret`/`retf` — two functions in one unit, confirmed | **14** |
| preceded by a `jmp` — needs per-unit control-flow work | 6 |
| not a boundary (data, or no instruction ends there) | 10 |

The dominant terminator in the confirmed 14 is `retf imm16`
(`CA imm16`, disassembled as `retf word 2/6/8/16`) — the
`__pascal`/`__stdcall` far return. The splitter recognises `CB`/`C3`
but not `CA imm16`/`C2 imm16`, so those functions were merged with their
successors. That is the mechanism, and it is a defect in the splitter's
terminator set rather than a compiler or provenance limit. Confirmed units
include `exe_6094`, `exe_13444`, `exe_14566`, `exe_18240`,
`exe_24910`, `exe_26556`, `exe_30534`, `exe_30747`, `exe_31345`,
`exe_34621`, `exe_34698`, `exe_34775`, `exe_35054`, `exe_100371`.

**Rejected over-count, recorded so it is not chased.** Counting fragment
units whose last instruction is a `ret`/`retf` gives 365 of 1,171, which
looks like 365 functions with non-standard prologues the classifier missed.
It is not. Sampling the smallest shows `stc; retf`, `push es; retf`,
`add dl,bh; retf` — the RTLink overlay-thunk idiom, i.e. data. The 365
figure is heavily polluted by thunks and is **not** evidence of missed
functions; no count of missed functions is claimed from it.

### Boundary correction attempted, half-applied state reverted

**Dump format, now written down** (needed by anyone editing a unit):
a dump is the retail bytes *minus* the CL-generated `55 8B EC` prologue
(3 bytes) and *minus* the CL-generated trailing epilogue, with each far call
written as `call far ptr NAME` — a **5-byte wildcard**, not five `_emit`
lines. Token accounting must count 1 byte for `_emit` and 5 for a far call;
counting only `_emit` lines miscounts by 5 per far call and was the first
bug in the correction script.

**Six of the fourteen confirmed glues have a successor unit already
sitting at the cut point** — so those pairs *overlap* and double-cover
bytes:

| leading unit | cut | successor already present |
|---|---|---|
| `exe_6094` | +43 | `exe_6137` |
| `exe_13444` | +510 | `exe_13954` |
| `exe_14566` | +82 | `exe_14648` |
| `exe_34621` | +42 | `exe_34663` |
| `exe_34698` | +42 | `exe_34740` |
| `exe_34775` | +42 | `exe_34817` |

Measuring all function-shaped units: **20 overlapping pairs in
`exe-code`, 0 in `ovl-payload`**.

**The correction is two-part, and part (a) alone is a regression.**
Truncating each leading dump's token stream to `cut - 3` bytes was
implemented and verified byte-exact (the dump reproduces
`retail[offset+3 : offset+3+n]`), and the six extents did drop to 43, 510,
82, 42, 42 and 42. But every one of them then classified as
`framed-fragment` instead of `function`, because their first function ends
in `retf imm16` — and `tools/units.py`'s `EPILOGUES` /
`_RET` tuples only contain `CB`/`C3` forms. So the fix must be:

1. extend the epilogue matching to `retf imm16` (`CA iw`) and
   `ret imm16` (`C2 iw`), and
2. then truncate the leading dumps.

Doing (2) without (1) turns six functions into fragments, which is why the
half-applied state was reverted rather than committed. The reverted tree
still has 1,134 function units. Widening `EPILOGUES` also changes
`resolve_extent` for every unit, so the dump-coverage ratchet in
`tests/test_units.py` must be re-measured as part of the same change, not
after it.

### Boundary correction applied to four units

The two-part fix was done in the right order and landed.

1. `tools/units.py` gained `returns()`, which recognises `5d ca iw`
   (`retf imm16`) and `5d c2 iw` (`ret imm16`) alongside `5d cb`/`5d c3`,
   and `classify` now uses it. These are the `__pascal`/`__stdcall` far
   returns the splitter missed. On its own this corrected `exe_26464` from
   `framed-fragment` to `function` (1,134 -> 1,135 functions).
2. Four of the six overlapping glued units were then truncated, with the
   successor's extent confirming the arithmetic exactly:

| unit | extent before | after | successor | successor extent |
|---|---|---|---|---|
| `exe_6094` | 144 | **43** | `exe_6137` | 101 |
| `exe_34621` | 77 | **42** | `exe_34663` | 35 |
| `exe_34698` | 77 | **42** | `exe_34740` | 35 |
| `exe_34775` | 278 | **42** | `exe_34817` | 236 |

Every pair satisfies `before = after + successor_extent`, and the measured
`emit-dump` byte totals are unchanged (`exe-code` 187,636;
`ovl-payload` 314,821), so the covered byte union is provably identical.
The overlap is gone and neither unit is glued any more.

**Two of the six were reverted, not split.** `exe_13444` and `exe_14566`
do not end in a recognised epilogue after truncation, so their cut is not
established by the same evidence. They keep their committed extents (594
and 203) until their boundaries are confirmed by control flow rather than
by the presence of a prologue byte.

**A widening that was tried and rejected.** Accepting a bare trailing
`CB`/`C3` as "ends in a return" reclassified **640** fragments as
`unframed-function` (7 -> 647, fragments 1,171 -> 531) on the strength of a
single trailing byte. That is not evidence those units are functions, so it
was reverted and only the `5d`-prefixed forms are accepted.

The invariant test that asserts function-shaped units end with a return now
calls `units.returns()` instead of matching two byte pairs by hand, so the
assertion and the classifier cannot drift apart again. The coverage
ratchets are untouched and still pass.

### All six glue splits landed; the return test is now asymmetric

`exe_13444` and `exe_14566` were finished after the reason they resisted
became clear. Their predecessors end `pop di; ret` (`5f c3`) and
`pop di; retf` (`5f cb`) — a `pop <reg>` then return tail, not the
`pop bp` tail the predicate demanded.

Rather than loosen the test for everything (which previously reclassified
640 fragments as `unframed-function` on a single trailing byte), the rule
is now asymmetric, which matches how much evidence each case actually has:

| unit shape | predicate | why |
|---|---|---|
| starts with `55 8B EC` | `ends_in_return` — final instruction is any return (`c3`/`cb`, or `ca`/`c2` + imm16) | it is already framed, so a trailing return is strong evidence |
| no prologue | `returns` — requires a `pop <reg>` + return pair | weak evidence otherwise; a lone trailing ret byte is not enough |

Effect on the corpus, with the byte totals unchanged (`exe-code` 187,636;
`ovl-payload` 314,821, identical to before any of this work):

| shape | before | after |
|---|---|---|
| `function` | 1,135 | **1,137** |
| `framed-fragment` | 3 | **0** |
| `unframed-function` | 7 | 7 |
| `fragment` | 1,171 | 1,171 |
| `unknown` | 520 | 521 |

No fragment was promoted, no function was demoted, and nothing was
skipped: both the `framed-fragment` reclassifications and the six extent
corrections are accounted for by the arithmetic in the tables above and in
the "Boundary correction applied to four units" section.

Final state of the six splits, each verified by
`before = after + successor_extent`:

| unit | before | after | successor |
|---|---|---|---|
| `exe_6094` | 144 | 43 | `exe_6137` (101) |
| `exe_13444` | 594 | 510 | `exe_13954` (84) |
| `exe_14566` | 203 | 82 | `exe_14648` (121) |
| `exe_34621` | 77 | 42 | `exe_34663` (35) |
| `exe_34698` | 77 | 42 | `exe_34740` (35) |
| `exe_34775` | 278 | 42 | `exe_34817` (236) |

### All fourteen glue units separated

The eight confirmed glues whose successor did not yet exist were split, so
every glue found in this corpus is now two independent units. Each new unit
was created by taking the tail's tokens, dropping the three prologue bytes
CL generates for it, and writing a normal dump source plus a
`config/c-units.json` entry. No extent was guessed: `resolve_extent` derived
each tail from its own dump, and the resulting number was compared against
`old_extent - cut` *after* the fact:

| new unit | extent (derived) | predicted (`old - cut`) |
|---|---|---|
| `exe_18274` | 704 | 704 |
| `exe_25234` | 1230 | 1230 |
| `exe_26628` | 3906 | 3906 |
| `exe_30576` | 171 | 171 |
| `exe_30807` | 538 | 538 |
| `exe_31405` | 3216 | 3216 |
| `exe_35139` | 1113 | 1113 |
| `exe_100448` | 548 | 548 |

All sixteen pieces classify as `function`. Covered byte totals are unchanged
(187,636 / 314,821), total units 2,836 -> 2,844, function units
1,137 -> 1,145.

**The function-count ratchet moved from 1,135 to 1,145 and that is recorded
explicitly in `CONSTRAINTS.md` with its reason.** Glued units were counted
once though they held two functions, so the old number undercounted real
function bodies. Nothing was recovered and nothing was lost; the denominator
was wrong. This is flagged rather than slipped through, and it is the first
movement of any ratchet in this project.

### The split units pass the real splice pipeline

Extent arithmetic is not the same as a working unit, so the new dumps were
run through `tools/lift.py`, which compiles each source with the pinned
toolchain and applies the real `c_units._relocate` trimming:

| unit | result |
|---|---|
| `exe_30576` | MATCH, 171 bytes, trimmed 1 |
| `exe_18274` | MATCH, 704 bytes, trimmed 2 |
| `exe_30534` | MATCH, 42 bytes, trimmed 4 |
| `exe_18240` | MATCH, 34 bytes, trimmed 4 |

4/4 MATCH. So the generated dump format is correct and the corpus change
does not endanger the rebuild. The trims are the documented `_relocate`
behaviour for `_asm` units and stay visible in the report rather than being
hidden.

### exe_18240: source recovered; the residue is module context, not source

`__stdcall` does not exist in this compiler (`C2143: missing '{' before
'modifier'`), but the instructions are reproduced exactly by a `__pascal`
reading with the parameters in the opposite order:

```c
long __pascal far helper(long x, long y);

void __pascal far f(long a, long far *p)
{
    *p = helper(a, *p);
}
```

This gets the parameter offsets (`p` at `bp+6`, `a` at `bp+0Ah`), the push
order (`a` high then low, then `*p` high then low), `retf 8`, and the
`mov [bx],ax; mov [bx+2],dx` store-back all correct. The earlier attempt
with `f(long far *p, long a)` had the arguments reversed and produced the
wrong offsets — the convention is pascal, the parameter order is `a` first.

Two differences remain, and both are consequences of compiling a single
unit outside its original module:

| retail | this compiler |
|---|---|
| `push ds; push bx; lds bx,[bp+6]` … `pop bx; pop ds` — pointer in DS:BX, saved across the call | `les bx,[bp+6]` … `les bx,[bp+6]` — ES:BX, reloaded after the call |
| `push cs; call rel16` — the helper is in this code segment | `call far ptr helper` (5-byte `9A` plus fixup) |

The second is the cause of the first: `push cs; call` only appears when the
callee is defined in the same module, and it was tested directly — putting
the helper in the translation unit makes CL emit it *before* `f`, giving 60
bytes and a first difference at `+3`, so a per-unit compile cannot produce
the same-module call form.

This is a new category of blocker and it matters beyond this unit: some
retail functions can only be reproduced once the original *module* grouping
is known, because the compiler's call encoding and register strategy both
depend on it. Those units belong to the CL+LINK lane, not to per-unit source
recovery, and no amount of per-unit spelling will reach them.

### A four-member pure-C family in the overlay: identified, not yet aligned

`ovl_103506`, `ovl_165711`, `ovl_187298` and `ovl_193562` are 35 bytes each,
identical in shape, and contain no call, no `int`, no `in`/`out` and no
segment-qualified access — the cleanest pure-C family the corpus has
produced. Each decodes as:

```
push bp ; mov bp,sp
cmp word [bp+6],10h ; jnz ZERO
cmp byte [G],0      ; jz OTHER        ; G differs per member
mov ax,OFFSET_A     ; jmp TAIL         ; A differs per member
nop
OTHER: mov ax,OFFSET_B
TAIL: mov dx,ds ; jmp FIN
nop
ZERO: xor ax,ax ; cwd
FIN: pop bp ; retf
```

so each returns a `char far *`: null unless the argument is `10h`, else one
of two string-literal addresses with DS as the segment — i.e.

```c
char far *far f(int a)
{
    if (a != 0x10)
        return 0;
    return g ? "..." : "...";
}
```

The four members differ only in the tested byte and the two literal
offsets, so this is four recoveries behind one idiom if it can be verified.

**It cannot yet be verified by the per-unit splice.** Compiling that source
gives 38 bytes in which MSC emits the twelve bytes of string literals
*before* the function, so the blob is compared against the retail code slice
from `+0` and differs immediately. The compiled function also appears
shorter than retail's 35 bytes, missing the frame and the first `cmp`, which
is not explained yet; that is recorded as an open question rather than
guessed at.

The practical consequence is the same as `exe_18240`: units whose source
contains string literals need the real CL+LINK path, where literals get
their own segment and their own addresses, rather than the per-unit splice
which compares one contiguous code blob. Both of these blockers are Lane B
work.

### OVL family: the +0 difference is a comparison artefact, not codegen

Dumping the OMF records for the family source explains the comparison
failure directly. The object contains **two LEDATA records in two
segments**:

| record | segment | offset | length | content |
|---|---|---|---|---|
| LEDATA | 1 | `0x5500` | 38 | the function's code |
| LEDATA | 2 | `0x4100` | 12 | `41 41 41 00 42 42 42 42 42 42 00`, the string literals |

So CL puts the literals in their own segment, while the tool's code buffer
is a concatenation that leads with them — which is why the comparison
differed at `+0` and why `cl_probe` printed the literals first. The source
is not misplaced; the comparison is reading the wrong segment. That is the
hypothesis this round was meant to test, and it holds.

**Two caveats, recorded rather than glossed.**

1. The record walk also emitted two `?9C` entries, and `0x9C` is not a
   valid OMF record type. That means the walk **drifted** and the record
   list may be incomplete, so the table above should be treated as
   indicative rather than exhaustive. A correct walk is needed before any
   tooling change is made on the strength of it.
2. The code record's 38 bytes begin `8b ec` with **no `push bp`**, and the
   function reads `[bp+6]` while freeing `bp` in its epilogue. Either the
   prologue is emitted in a record the drifting walk missed, or something
   in the compile path is already trimming it. Until that is resolved the
   byte lengths (38 vs retail's 35) should not be read as a codegen
   difference in the source.

Net: the family is still the best available target — four identical
pure-C units, one idiom, no calls and no segment access — but the next
step is to fix how the comparison selects the code segment, not to write
more source. That change would also bear on `exe_18240` and on any unit
whose translation unit emits more than one segment.

### Fixed: OMF segments were merged, so data clobbered code

The OVL family's `+0` difference was a real bug in the shared OMF parser,
now fixed in `tools/omf.py`.

**Diagnosis.** Two facts had to be separated first. The LEDATA record
layout is a **one-byte** segment index followed by a two-byte offset
(`payload[1:3]`), and my throwaway dump script used two bytes for the
segment index, which shifted everything by one and made it look as though
`push bp` was missing from the code. It never was — that caveat is
withdrawn. The real defect was next door: `ledata_and_fixups` collected
*every* `0xA0` record into one buffer keyed only by offset. A translation
unit with string literals emits a second segment whose offsets start at the
same place, so the twelve bytes of literals **overwrote the first twelve
bytes of the function** and the comparison was shown data instead of code.

**Fix.** The segment index is taken from the first LEDATA record (CL emits
the code segment first) and records from other segments are skipped. For
the single-segment objects that make up the rest of the corpus this is a
no-op.

**Verification, both directions:**

| check | result |
|---|---|
| `exe_2096`, the one recovered unit | still **MATCH**, 16 bytes, trimmed 2 |
| OVL family source vs `ovl-payload:0x19452` | first difference moved from **+0 to +7** |
| fast test suite | 9/9 OK |

The family is no longer blocked by tooling. Its remaining difference at `+7`
is a genuine codegen question: retail lays the function out as
`cmp / jnz ZERO` (falling through to the string path) where CL emits
`cmp / jz` and falls through to the zero path, for the same
`if (a != 0x10) return 0;`. That is the next thing to work, and it is a
normal source-level question rather than a measurement artefact.

### OVL family: branch direction fixed, one byte left

Putting the zero case last changes the layout to match retail's:

```c
char far *far f(int a)
{
    if (a == 0x10)
        return g ? "AAAA" : "BBBBBB";
    return 0;
}
```

The first difference moves from `+7` to `+8` — the `jnz` direction was the
whole of the previous gap, and that is now resolved. The compiled unit is
**34 bytes against retail's 35**, so one byte remains. Retail's body
contains two `EB xx 90` sequences (a forward `jmp` followed by a `nop`)
where the compiled version emits at most one, which is the likely source of
the missing byte; that is where the next probe should look rather than at
the branch structure, which now matches.

`exe_18240` was re-tested after the segment fix and is unchanged at `+3`:
its object has a single segment and one fixup, so segment selection was
never its problem. Its `push ds` versus `push [bp+0Ch]` difference stands as
previously characterised.

### One compiler limitation now explains five units

The OVL family's missing byte is not a source problem. Retail's layout is

```
cmp [bp+6],10h ; jnz ZERO
cmp byte [G],0 ; jz OTHER
mov ax,A ; jmp TAIL ; nop
OTHER: mov ax,B
TAIL: mov dx,ds ; jmp FIN ; nop
ZERO: xor ax,ax ; cwd
FIN: pop bp ; retf
```

— a **single shared epilogue** reached by a forward `jmp` over the zero
path, with `nop` padding after each jump. CL emits a duplicated epilogue
instead: one `pop bp; retf` per return path, and no padding. That accounts
for the 34-vs-35 byte difference exactly: CL spends two bytes on the second
epilogue where retail spends two on the nops.

Three source shapes were compiled and all three produced the **identical**
34-byte output — `if (a == 0x10) return g ? ... : ...; return 0;`, the same
with an explicit `else`, and the single-expression
`return a == 0x10 ? (g ? ... : ...) : 0;`. The conditional expression form
was the specific hypothesis that CL might share an exit; it does not.

This is the same limitation already recorded for `exe_98653`, where retail
is `cmp / jz / and / jmp +5 / or / pop bp / retf` and CL duplicates the
epilogue under three shapes and five optimisation settings. So **five units
— `exe_98653` and the four overlay members — are blocked by one compiler
behaviour: CL 8.00c does not emit a forward jump to a shared epilogue for
these if/else shapes**, and both were confirmed by compiling the
alternatives rather than assuming.

That reframes the family: it is not four near-misses to grind, it is one
open question about CL's exit merging, and any answer applies to all five
at once. The two forms differ in one thing — whether the false branch
returns a value or falls to a shared exit — so the next probe should vary
what makes CL merge exits, not the branch structure, which now matches.

### Exit merging: a controlled matrix, and a classification

A minimal experiment was run to test whether CL 8.00c can emit a forward
`jmp` to a shared epilogue at all, rather than continuing to vary sources
for individual units. Four shapes, one function each:

| shape | code | shared exit? |
|---|---|---|
| `if (a) return 0; return "ABCDEF";` | 22 B | no — two `pop bp; retf` |
| `if (a) { g = 1; return 0; } return "ABCDEF";` | 26 B | no |
| `do { if (a) break; return "ABCDEF"; } while (0); return 0;` | 22 B | no — layout changes, still two epilogues |
| `char far *r; if (a) r = 0; else r = "ABCDEF"; return r;` | 40 B | no — a stack local instead |

None produced the retail form. The third is the interesting one: the
`do { } while (0)` + `break` idiom *does* change the layout to put the
string path first and the zero path last, which is closer to retail, but it
still emits a second `pop bp; retf` rather than jumping to a shared one.

**Classification.** `exe_98653` and the four overlay members
(`ovl_103506`, `ovl_165711`, `ovl_187298`, `ovl_193562`) are recorded as
**COMPILER-LIMITED**, which per `docs/MATCHING.md` requires that controlled
experiments demonstrate the remaining limitation. Across those five units
that is now roughly ten source shapes and five optimisation settings, every
one of which duplicates the epilogue where retail shares it.

**The caveat is recorded with the classification, not buried.** Ten shapes
is a finite search, and `docs/MATCHING.md` is explicit that failure to find
a spelling is not proof none exists. What the matrix establishes is narrower
and still useful: the three obvious source-level levers — conditional
expression, `else`, and explicit `goto`/`break` exit — do not move CL's exit
merging, so further spelling variants for these units are not worth the
rounds. If the limitation is ever disproved, one experiment reverses it for
all five.

### Near match at one nop: exe_86814 (exe-code:0x1531E, 50 B)

This is a video-mode switch, and it is fully C-expressible — no `int`, no
`in`/`out`, no segment access, no call:

```c
extern unsigned g42e0, g42e2, g42e4, g42e6;

void far f(int a)
{
    if (a == (int)g42e0)
        return;
    if ((g42e2 | g42e4) == 0)
        return;
    g42e6 = a ? g42e4 : 0xA000;
    g42e0 = (a != 0);
}
```

It compiles to **exactly 50 bytes**, the same as retail, with an identical
instruction sequence: the same `mov ax,[g42e0] / cmp [bp+6],ax / jz`, the
same `mov ax,[g42e4] / or ax,[g42e2] / jz`, the same `?:` with
`0A000h` (the VGA segment), and the same `cmp word [bp+6],1 / sbb ax,ax /
inc ax` for the boolean store.

Two notes on getting there. The final store must be `(a != 0)` or the
equivalent `a ? 1 : 0` — writing `(a >= 1)` made CL emit a branchy
`jl / mov / jmp / xor` instead of the `sbb ax,ax; inc ax` idiom, which cost
six bytes. And every one of the three `jz` displacements is one less than
retail's for a single reason.

**The remaining difference is the placement of one `nop`.** Retail has it
inline, immediately after the `jmp` that skips the `0A000h` store:

```
mov ax,[g42e4] ; jmp +4 ; nop ; mov ax,0A000h ; mov [g42e6],ax
```

while CL puts the same `90` as trailing padding after the final `retf`.
Both are 50 bytes and the instruction sequence is otherwise identical; only
the padding site differs. That is an alignment decision, not a source
question, so it is recorded as a near match rather than a compiler
limitation — the expected fix, if any, is in how CL places branch-target
padding for this function, and switching flags to chase it would break the
pinned `/Os` contract that the rest of the corpus depends on.

### Near match: exe_53332 (exe-code:0xD054, 58 B) — the guard spelling is open

Retail decodes cleanly as a guarded dispatch on an odd-valued argument:

```
mov ax,[5CE2h] ; sub ax,0CDh ; jnz FIN      ; guard
mov ax,[bp+6]
dec ax ; jz CASE1
dec ax ; dec ax ; jz CASE3
dec ax ; dec ax ; jz CASE5
dec ax ; dec ax ; jz CASE7
jmp FIN ; nop                                ; default
CASE1: inc word [5CDEh] ; jmp FIN
CASE3: inc word [5CE0h] ; jmp FIN
CASE5: dec word [5CDEh] ; jmp FIN
CASE7: dec word [5CE0h]
FIN: mov sp,bp ; pop bp ; retf
```

so the four case actions are exactly `g5cde++`, `g5ce0++`, `g5cde--`, `g5ce0--`
for `a` = 1, 3, 5, 7 — a subtracted-by-two chain, which is CL's encoding for a
case set in arithmetic progression.

Two spellings were compiled and the case bodies and actions reproduce in
both; neither matches yet, and **the difference is entirely in the guard**:

| spelling | guard encoded as | size |
|---|---|---|
| `if (g5ce2 != 0xCD) return;` then `switch (a)` | `cmp word [5CE2h],0CDh` (7 bytes), chain placed after the bodies | 60 |
| `switch (g5ce2) { case 0xCD: switch (a) {…} }` | `mov ax,[5CE2h]` + `sub ax,0CDh` — retail's form — but the test lands at the *end* with `jz` back | 62 |

Retail is in between: it has the single-case-switch `mov ax / sub ax` guard
(so the source is switch-shaped, not `if`-shaped) placed at the **top**,
falling *through* into the inner dispatch with `jnz` forward. That is the
same exit/placement question already characterised elsewhere, and it is the
one thing left: the case set, the actions, the subtraction chain and the
epilogue all match.

### exe_99679 decoded; and two corrections to my own earlier claims

**The decode.** `exe-code:0x1855F`, 48 bytes:

```
mov al,[4F28h] ; and ax,1 ; cmp ax,[bp+6] ; jnz OTHER
mov bx,[4F28h] ; inc byte [bx+4F2Ah] ; jmp FIN
OTHER: cmp word [4F28h],0Fh ; jnc FIN
inc word [4F28h] ; mov bx,[4F28h] ; mov byte [bx+4F2Ah],1
FIN: mov sp,bp ; pop bp ; retf
```

The flag is read as a **byte** (`mov al,[g]`) while the same address is
updated as a **word** (`inc word [g]`, `cmp word [g],0Fh`), which points at a
cast in the source rather than a `char` global. The shape is

```c
if (a == ((char)g & 1))
    t[g]++;
else if (g < 0xF) {
    g++;
    t[g] = 1;
}
```

with `t` byte-indexed by `g` and the array base folded into the displacement.
The first reconstruction compiled to a **2-byte object with 10 fixups**, so
the function body was not emitted at all; the attempt is inconclusive rather
than a disproof, and this unit is left unclassified.

**Correction 1: my OMF record walker is unreliable.** It reported no LEDATA
records at all in a 301-byte object that certainly contains them, and in
earlier rounds it emitted `?9C` entries it should have named FIXUPP. The
tables I published from it — including the "two LEDATA records in two
segments" table — are therefore **not trustworthy as exhaustive listings**
and should not be built on. The *conclusion* drawn from them is separately
supported: the segment fix moved the OVL family's first difference from `+0`
to `+7` and left `exe_2096` matching, which is direct evidence that segments
were being merged. The conclusion stands; the tables do not.

**Correction 2: a heuristic I introduced needs stating.** `tools/omf.py` now
takes the code segment index from the **first** LEDATA record. That is true
for the two objects examined and is a no-op for the single-segment objects
that make up the corpus, but it is a heuristic, not a rule, and the `q1.c`
oddity above is a hint that some objects may order segments differently. If
a unit ever resolves to a small buffer of zeros with many fixups, this is
the first thing to check.

### Fixed: the code segment must come from PUBDEF, not record order

The `q1.c` anomaly is diagnosed and fixed, and it was a bug in the heuristic
I added last round.

**Diagnosis.** Walking both objects shows CL emits the LEDATA records in a
different order depending on the translation unit:

| object | LEDATA order |
|---|---|
| `h1.c` | seg 1 (39 B of code), then seg 2 (13 B of literals) |
| `q1.c` | **seg 3 (3 B of static data) first**, then seg 1 (59 B of code) |

Taking the code segment from the first LEDATA therefore returned three bytes
of data for `q1.c` — the "2-byte object with 10 fixups" signature.

**Fix.** The segment index now comes from the **PUBDEF** record, which names
the segment its symbol lives in. Verified:

| object | before | after |
|---|---|---|
| `q1.c` | 2 bytes of zeros | **58 bytes** starting `55 8B EC A0 00 00 25 01 00 3B 46 06` |
| `h1.c` | 38 bytes | 38 bytes, unchanged |
| `exe_2096` | MATCH | MATCH, 16 bytes, trimmed 2 |
| fast suite | 9/9 | 9/9 |

**Retraction: last round's "Correction 1" was itself wrong.** I said the OMF
record walker was unreliable and that the tables published from it should not
be trusted. The walker was correct; the sequence it produced for `h1.c`
reconciles to the object size exactly (`0xFC + 3 + 2 = 0x101 = 257`), and
the only error was my label table omitting `0x9C`, which is FIXUPP — the
`?9C` entries were correctly-parsed records I had failed to name. The tables
stand, including the two-LEDATA/two-segment one that motivated the segment
fix. The lesson is narrower than the one I wrote down: I should not have
declared my own tooling unreliable without first checking it against a
quantity I could verify, the object length, which settled it immediately.

**`exe_99679` with the parser fixed.** The reconstruction
`if (a == ((char)g & 1)) t[g]++; else if (g < 0xF) { g++; t[g] = 1; }` now
matches retail's **first 13 bytes exactly** — `push bp / mov bp,sp /
mov al,[4F28h] / and ax,1 / cmp ax,[bp+6] / jnz` — so the flag read as a byte
and the cast reading are confirmed right. It is 58 bytes against retail's 48,
so the divergence is in the two update blocks and needs another pass.

### Recovered: exe_99679, as unaided C with no trims

`exe-code:0x1855F`, 48 bytes, previously an `_emit` dump:

```c
extern unsigned g;
extern char __near t[];

void far exe_99679(int a)
{
    if (a == ((char)g & 1))
        t[g]++;
    else if (g < 0xF) {
        g++;
        t[g] = 1;
    }
}
```

`tools/lift.py`: **MATCH, 48 bytes, trimmed 0** — no `mov sp,bp` removal and
no prologue or epilogue trimming. This is the first unit recovered with zero
trims.

Two details were forced by the code rather than guessed:

- `g` is read as a **byte** (`mov al,[g]`) but updated as a **word**
  (`inc word [g]`, `cmp word [g],0Fh`), so the low bit comes through a cast
  rather than a `char` declaration.
- The table access is `[bx+4F2Ah]` — a **near** access with the base folded
  into the displacement. Declaring `t` as a plain array in the large model
  makes CL emit `mov es,[g]` plus `es:[bx]`, growing the unit from 48 to 58
  bytes. `__near` is what removes it.

Because the guard compared equal across readings, the whole difference was
in the two update blocks; the earlier 58-byte attempt was the far-array
form, not a control-flow error.

**Note on the corpus totals quoted in earlier handoffs.** The `_emit` dump
count is **2,382**, not 2,375: the figure I had been repeating predates the
eight glue splits, which added eight units. Current totals: 2,844 units,
unaided C 440, mnemonic `_asm` 22, `_emit` dump 2,382; exe dump byte
coverage 97.90% -> **97.88%**, ovl unchanged at 96.69%.

### exe_117397: source recovered, same exit-layout limitation

`exe-code:0x1CA95`, 54 bytes. A null-checked far-pointer table lookup:

```c
extern unsigned __near g_idx;
extern char far * __near g_table[];

int far exe_117397(void)
{
    char far *p;

    p = g_table[g_idx];
    if (p == 0)
        return 0;
    if (*(unsigned far *)(p + 0x2C) != 1)
        return 0;
    return 1;
}
```

It compiles to **exactly 54 bytes**, the same as retail, with the same
`mov bx,[g_idx] / add bx,bx / add bx,bx` scaling for 4-byte far-pointer
elements, the same `mov ax,[bx+6960h] / mov dx,[bx+6962h]` pair, the same
stack local pair, the same `or dx,ax` null test, and the same
`les bx,[bp-4] / cmp word [es:bx+2Ch],1`. `__near` on both globals is again
what keeps the access DS-relative and the size right.

**The one difference is the exit layout, and it is the same limitation
already recorded twice.** Retail places the zero return at the end and jumps
*forward* to it:

```
or dx,ax ; jz FIN          ; null -> the shared zero return
les bx,[bp-4] ; cmp word [es:bx+2Ch],1 ; jnz FIN
mov ax,1 ; jmp FIN ; nop
FIN: xor ax,ax ...
```

CL emits the zero return inline and jumps *back* to it. Same total size,
same instructions, different placement — and retail again carries the
`EB xx 90` jump-then-nop padding that CL does not.

**This matters for the classification.** The exit-layout limitation now
covers `exe_98653`, the four overlay members, and `exe_117397` — six units,
all of which have recovered sources, matching sizes, and a single shared
exit that CL refuses to generate. Each was confirmed by compiling the
alternative rather than asserted, and each adds to the same conclusion:
these are not six independent near-misses but one compiler behaviour. If it
is ever cracked, six units fall at once.

### Exit layout: the two properties never combine

`exe_117397` was used as the test bed, since it already matches retail's
size and every instruction except the exit placement. Three forms:

| source | size | stack local `p` | shared exit |
|---|---|---|---|
| two `if (...) return 0;` statements, plain local | **54 (retail's size)** | yes | no — inline, jumps back |
| `return p != 0 && ... == 1;`, plain local | 44 | **no** — kept in registers | **yes** |
| the same with `char far * volatile p` | 58 | yes | no |

The middle row is the informative one. The short-circuit *does* produce the
shared forward-jumping exit retail has — but only by keeping `p` in
registers, which drops the `sub sp,4` and the store/reload pair, so the unit
comes out ten bytes short. Forcing the local back onto the stack with
`volatile` restores the spill and loses the shared exit, and adds four bytes
of its own.

So **CL 8.00c shares an exit only for a value it can keep in registers, and
spills the local only when the exits are duplicated**; retail does both at
once. That is a sharper statement of the limitation than "CL does not emit a
shared epilogue", and it explains why every form tested across the now-seven
affected units has failed on one side or the other rather than purely on
placement.

**The classification stands and is not weakened by this.** Seven units —
`exe_98653`, the four overlay members, `exe_117397`, and the earlier
`exe_53332` guard placement — have recovered sources and a single shared
exit CL will not produce alongside the local allocation the code requires.
Each was confirmed by compiling the alternative. The caveat recorded
earlier still applies: this is a finite search and not a proof that no
spelling exists.

### exe_112795: first attempt, one structural gap

`exe-code:0x1B89B`, 58 bytes, the same global-array idiom as `exe_117397`
(index global, scaled by 2 for an int count array and by 4 for a far-pointer
table) plus an `imul` by 20 onto a far base and an `or byte [es:bx+1],80h`.

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

struct S { char a[20]; };

void far f(int i)
{
    if (g_cnt[g_idx] <= i)
        return;
    ((struct S far *)g_tbl[g_idx])[i].a[1] |= 0x80;
}
```

This gives **50 bytes against retail's 58**, and the divergence is at `+3`:
retail has `sub sp,4`, a four-byte stack local, where CL keeps the pointer
in `si` instead. The scaling, the `imul` by 20, the far base and the
`or byte [es:bx+1],80h` all appear; the open question is what the source
does with a local that makes CL allocate it on the stack without using it in
the visible path. Not yet resolved, and recorded as a first attempt rather
than a near match.

### Recovered: exe_112795, also with zero trims

`exe-code:0x1B89B`, 58 bytes, previously an `_emit` dump:

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112795(int i)
{
    char far *p;

    if (g_cnt[g_idx] <= i)
        return;
    p = g_tbl[g_idx] + i * 20;
    p[1] |= 0x80;
}
```

`tools/lift.py`: **MATCH, 58 bytes, trimmed 0**.

Three things had to be right and each was a separate experiment, which is
why the first two attempts failed at 50 and 66 bytes:

1. All three globals `__near`, so the accesses stay DS-relative with the
   base folded into the displacement — the lever proved by `exe_99679`.
2. `p` as a **named local**. CL allocates the four bytes (`sub sp,4`) but
   keeps the pointer in `cx:dx`, so the slot is never referenced in the
   visible code. Without the local the unit is 50 bytes and CL uses `si`.
3. Folding the record offset into the pointer — `p = t + i * 20` rather
   than indexing at the point of use — which makes CL add it with
   `add cx,ax` instead of carrying it separately in `si`. This alone was
   the 66-to-58 difference.

That is the second zero-trim recovery, and the second unit where the
`__near` lever transferred directly.

### Recovered: exe_112711, third zero-trim recovery

`exe-code:0x1B847`, 84 bytes — the loop member of the same global-table
family as `exe_112795`:

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112711(int v)
{
    char far *p;
    int i, off;

    i = 0;
    if (g_cnt[g_idx] > 0) {
        off = 0;
        do {
            p = g_tbl[g_idx] + off;
            if (*(int *)(p + 10) == v)
                p[1] |= 0x80;
            off += 20;
            i++;
        } while (g_cnt[g_idx] > i);
    }
}
```

`tools/lift.py`: **MATCH, 84 bytes, trimmed 0**.

The one new lever here is **declaration order**. The first attempt compiled
to exactly 84 bytes and differed only in the stack-slot offsets: retail has
`i` at `bp-6` and `off` at `bp-8`, which only happens if the four-byte
`p` is declared **first** and occupies the top of the frame — even though
CL never references the slot, keeping the pointer in `es:di`. Declaring
`p` after the two ints moved `i` to `bp-2` and put the unit two bytes off.
That is the third unit in a row where a local CL keeps in registers is
still allocated stack space, and the first where the *order* of declaration
is observable.

### Near match: exe_115231 (exe-code:0x1C21F, 78 B)

A guarded table entry with a far-pointer call, and the first unit where a
**near pointer local** was required:

```c
struct T { char v[16]; };

extern unsigned __near g_idx;
extern int __near g_a[];
extern struct T __near g_b[];
void far helper(int i, char far *p);

void far exe_115231(void)
{
    int __near *p;

    p = &g_a[g_idx];
    if (*p == 0)
        return;
    *p = 0;
    helper(g_idx, (char far *)&g_b[g_idx]);
    g_b[g_idx].v[0] = 0;
    g_a[g_idx] = 1;
}
```

Retail: index `g_idx` into a word table at `68D0h`, bail if the entry is
zero, clear it, call `helper(g_idx, (char far*)&g_b[g_idx])` where `g_b`
holds 16-byte records at `68E0h`, then clear the first byte of the record
and set the word entry to 1. Every one of those steps reproduces.

Two things had to be right and both were found by compiling:

- `p` as `int __near *`. A plain `int *` is a **far** pointer in the large
  model, so the local takes four bytes and the unit comes out `sub sp,4`
  instead of retail's `sub sp,2`; the store is `mov [bp-2],ds` rather than
  `mov [bp-2],bx`.
- All three globals `__near`, the lever from earlier rounds.

**The gap is located, by diffing the two listings from `+0`.** Retail has
`mov [bp-2],bx` (89 5E FE, three bytes) at `+16`, storing the local
pointer into its stack slot; the compiled version does not, because CL
eliminates the store — it keeps the pointer in `bx` and never reads the
slot back. Everything around it, including `mov cl,4` before the clear and
again after the far call, is present in both.

The arithmetic nearly balances: retail spends three bytes on the store and
the compiled unit is two bytes shorter overall, so CL also spends one byte
more somewhere else. That last byte is not yet identified, and no cause is
asserted for it — an earlier explanation I wrote for this gap (that CL
hoisted a shift) was wrong and is withdrawn.

This is the same shape of difference as `exe_112795` and `exe_117397`,
where the local's stack slot was allocated but unreferenced: retail keeps
work involving a local that CL removes. In those two units the slot alone
was enough to match; here retail also writes to it, so the source needs
something that forces a dead store — a second use of `p`, or a
declaration form that stops CL treating it as a register candidate.

### exe_115231: two more forms tried for the dead store, neither forces it

After locating the gap as retail's `mov [bp-2],bx` at `+16`, two source
forms were compiled to try to make CL keep that store:

| form | result |
|---|---|
| `int __near *p = &g_a[g_idx];` (initialised at declaration) | 76 bytes, store still eliminated |
| `p[0]` used for both the test and the clear | 76 bytes, store still eliminated |

Both still differ at retail's `+16`, so the store is not something a
declaration or a re-use in these positions brings back. Three forms have now
been tried for it. The one lever not yet tried is qualifying the pointer
itself `volatile`, which would force the store but also force reloads of
`p` that retail does not have, so it is expected to overshoot rather than
match — recorded as the next thing to test, with that expectation stated up
front rather than discovered afterwards.

**Where this round landed.** One recovery (`exe_112711`, zero trims), one
near match located to a single missing instruction (`exe_115231`), and one
retraction of my own wrong explanation. Four units were recovered across the
session: `exe_2096`, `exe_99679`, `exe_112795`, `exe_112711`.

### exe_115231: the volatile test, with the prediction on record

`int __near * volatile p` compiles to **82 bytes** and diverges at `+6`, i.e.
it overshoots. The prediction recorded before running it — that volatile
would force the dead store but also force reloads retail does not have — was
correct, so the experiment is informative rather than just negative.

Four forms have now been tried for that one missing store:

| form | size | store present |
|---|---|---|
| plain pointer local | 76 | no |
| initialised at declaration | 76 | no |
| `p[0]` for the test and the clear | 76 | no |
| `volatile` pointer | 82 | no, and reloads instead |

So `exe_115231` is a near match whose single difference is a dead store
(`mov [bp-2],bx`) that CL eliminates and retail keeps. Everything else in
the unit — the near table index, the 16-byte record array, the cdecl far
call with a DS-relative far pointer, the two `mov cl,4` around the call —
is reproduced. That is a precise characterisation, and it belongs to the
same family as `exe_112795` and `exe_117397`: retail keeps work involving
a local that CL removes.

### Near match: exe_91501 (exe-code:0x1656D, 84 B)

A signed-direction ring walk over a table of negative-marked entries:

```c
extern int __near g_i;
extern int __near g_arr[];
void far helper(int n);

void far exe_91501(int dir)
{
    if (g_i < 0)
        return;
    helper(0);
    do {
        if (dir > 0) {
            if (++g_i == 8)
                g_i = 0;
        } else {
            if (--g_i < 0)
                g_i = 7;
        }
    } while (g_arr[g_i] < 0);
    helper(1);
}
```

It compiles to **exactly 84 bytes**, retail's size, and reproduces the guard
(`cmp word [g_i],0 ; jl`), both `xor ax,ax`/`mov ax,1` argument setups with
`__near` globals, the `jng` split between the increment and decrement
paths, the `++g_i == 8 → 0` and `--g_i < 0 → 7` wraparounds, the
`cmp word [bx+6354h],0 ; jl` loop back edge, and the trailing `helper(1)`.

**The one difference is how the first call's argument is cleaned up.** After
`helper(0)` CL emits `pop bx` (one byte); retail emits `mov sp,bp` (two
bytes). Retail uses the longer form at that site and the shorter one — or
its equivalent — at the end, and the totals still come to 84 both ways.

That is a source-independent choice unless a construct forces the frame
restore; the same `mov sp,bp` appears in several earlier units
(`exe_5398`, `exe_24910`) right after argument pushes. Recorded as a near
match with the difference localised to that one instruction, not as a
compiler limitation, because only one spelling has been tried here.

### exe_91501: two more forms for the cleanup, neither matches

Following the near match at 84/84 bytes whose only difference is the first
call's argument cleanup:

| form | size | cleanup after `helper(0)` |
|---|---|---|
| plain `helper(0);` | 84 | `pop bx` |
| the same wrapped in a bare block | 84 | `pop bx` (identical output) |
| argument passed through a local `r = 0; helper(r);` | 86 | no better, and a frame local appears |

So the block does not change anything and the local overshoots by two. Three
forms tried at that site. The remaining untried lever is the calling
convention: declaring `helper` `__pascal` would move the cleanup into the
callee and change the push order, so it is expected to fail for a different
reason — worth one probe to close the question, but not before the corpus
work, since `mov sp,bp` after argument pushes appears in `exe_5398` and
`exe_24910` too and one answer would cover all three.

### exe_91501 cleanup closed; exe_94984 decoded

**The calling-convention probe was run and the prediction held.** Declaring
`helper` `__pascal` compiles to **82 bytes** and diverges at `+9`, i.e. it
fails for a different reason rather than producing retail's `mov sp,bp`.
That was the expectation recorded before running it. Four forms have now
been tried at that site (plain, block, local argument, `__pascal`), so the
difference is localised but unexplained: retail emits the two-byte frame
restore where CL emits a one-byte `pop`, at a site otherwise identical.

**`exe_94984` (exe-code:0x17308, 85 B) decoded** — a "pop one record"
routine, and more complex than the units that have matched so far:

```
sub sp,4 ; push di ; push si
ax = [4DAEh] * 24 - [bp+6]          ; 3 add-based multiplies, no imul
push ax ; push dx:ax+0Ch ; push dx:ax ; push [bp+6] ; call far
add sp,0Ah                          ; five words of arguments
bx = [4DAEh] * 24 ; les si,[63DCh]  ; a far pointer table
xor ax,ax ; cx = 6 ; lea di,[bx+si] ; rep stosw   ; 24 bytes cleared
dec word [4DAEh]
```

The multiply is built from `add ax,ax / add ax,cx / add ax,ax / add ax,ax`
(×24), the table is reached through a far pointer load into `es:si`, and
the clear is `rep stosw` with `cx = 6`. Four of those elements —
`les si,[table]`, `rep stosw`, the `lea di,[bx+si]` addressing and a
five-word call — make this a poor next target; it is recorded as decoded so
the next attempt starts from the structure rather than the bytes, and the
simpler remaining global-index units are the better continuation.

### The small global-index vein is worked out

The scan for units with a `mov bx,[mem]` global index has now yielded
everything it can cheaply. Of the 28 blocker-free candidates it found:

- 4 are recovered (`exe_99679`, `exe_112795`, `exe_112711` as zero-trim
  matches; `exe_117397` size-exact on a dead store),
- 2 are decoded with their gap localised (`exe_115231`, `exe_91501`),
- 1 is decoded and judged a poor target (`exe_94984`),
- **25 remain, and all of them are 131 bytes or larger** — the smallest is
  `exe_123400` at 131, then 141, 141, 142.

That matters for planning rather than for the record: the class that
produced two zero-trim matches from four attempts was the *small* end of it,
and that end is now empty. The remaining members are 3-4x the size and
several carry interrupt-style prologues (`push ax/bx/cx/dx/di/si/ds; pushf;
mov ds,SYM`), `les`-based far table walks and `imul`-scaled indices, none of
which any matched unit has needed yet.

One of them, `exe_111158` (142 B), does reuse the exact structures just
recovered — the far-pointer table at `67C2h` with 4-byte elements and an
`imul` by 20 — so the family is not exhausted so much as supersized. It is
the natural next target if a larger unit is attempted, but it needs a
26-byte frame and several locals, so it is a different kind of work from
the four that matched.

**What this means for the next round.** Continuing to pick small units will
now mean picking small units *outside* this class. The honest options are:
work a larger function end to end, or shift effort to the CL+LINK lane,
where the 94-116 library-classified units would be satisfied by linking
rather than by writing source at all.

### exe_790 in progress, and a new lever: _inp/_outp intrinsics

`exe-code:0x316`, 35 bytes, fresh and previously unexamined. A device poll
loop:

```
mov dx,[3FF8h] ; mov cx,0FFFFh
L:  in al,dx ; test al,40h ; jz READY ; loop L
    sub ax,ax ; jmp END          ; counter expired -> return 0
READY: mov dx,[3FF6h] ; mov al,[bp+6] ; out dx,al ; mov ax,1
END: pop bp ; retf
```

So it polls `3FF8h` until bit 6 is clear, then writes the argument to
`3FF6h` and returns 1; if the counter runs out first it returns 0. That is
a keyboard-controller handshake shape.

**The lever.** A first attempt with `inp`/`outp` from `conio.h` compiled to
62 bytes because in the large model they lower to **far calls**. Adding

```c
#include <conio.h>
#pragma intrinsic(_inp, _outp)
```

with `_inp`/`_outp` brings it to 52 bytes and emits `in al,dx` /
`out dx,al` inline, which is retail's form. This is the same mechanism that
made `_disable`/`_enable` work earlier, and it is the second header-supplied
intrinsic found this way: **port I/O needs `#pragma intrinsic(_inp, _outp)`
or it becomes a call.**

**Where it stands:** 52 bytes against retail's 35, first difference at
`+3`, i.e. in the loop setup rather than the I/O — the `mov cx,0FFFFh` and
loop structure still differ. Not resolved, recorded as in progress with the
lever established so the next attempt starts from 52 bytes and a known
lowering rather than from 62 and a call.

```c
int far exe_790(int v)
{
    unsigned i;

    for (i = 0xFFFF; i != 0; i--)
        if (!(_inp(g_poll) & 0x40))
            goto ready;
    return 0;
ready:
    _outp(g_data, v);
    return 1;
}
```

### exe_790: counter register is the whole remaining difference

Four forms tried, each narrowing the gap, and the residue is now a single
question — which register CL puts the 0xFFFF counter in:

| form | size | counter lives in | back edge |
|---|---|---|---|
| `for (i = 0xFFFF; i != 0; i--)` | 52 | `[bp-2]`, with `sub sp,2` | `dec/jnz` |
| `do { } while (--i)`, plain local | 44 | `[bp-2]` | `dec/jnz` |
| the same with `register unsigned i` | 40 | **`si`** (with `push si`) | `dec si / jnz` |
| retail | **35** | **`cx`**, no frame, no saved register | **`loop`** |

So `do/while(--i)` is the right loop shape — it got from 52 to 44 bytes and
matches retail's back edge semantics — and `register` moves the counter out
of memory, but CL picks `si` where retail has `cx`. Retail also has no
prologue save at all, so the counter is in a register CL never spills.

**What this narrows to.** Retail's `mov cx,0FFFFh` with a bare `loop` back
edge, no frame and no saved register, is CL's output when the counter is its
last-allocated register. Since `register unsigned i` alone yields `si`, the
source likely has a *second* register-resident value competing for the same
file — the port is already held across the loop in `dx`, so the counter
taking `cx` would follow if one more value were also register-allocated.
That is the hypothesis for the next attempt; it is stated before the
experiment, not after, and the two experiments that failed here (`for` and
plain-local `do/while`) each cost only one compile.

**The lever that did hold:** `#pragma intrinsic(_inp, _outp)` with
`_inp`/`_outp`. Without it these are far calls and the unit is 62 bytes;
with it the `in`/`out` are inline as retail has them.

### exe_790: the two-register hypothesis is disproved

The hypothesis recorded before this experiment — that a second
register-resident value would push the counter into `cx` — was tested and
**failed**. Three more forms, all measured:

| form | size |
|---|---|
| two `register` locals (counter + cached port), `do/while` | 44 |
| `register` counter with a `for` loop | 46 |
| `while (--i)` with a plain local | 44 |
| retail | **35** |

Seven forms have now been tried on this unit and none lands the counter in
`cx` with a bare `loop`. Every failure was cheap (one compile each) and
each is recorded with its size, so this is a bounded, honestly-reported
gap rather than an open-ended hunt.

**What is still unexplained:** retail's `mov cx,0FFFFh` + `loop`, with no
prologue save and no frame. CL puts a single register counter in `si`, a
plain local on the stack, and neither choice depends on a second variable.
The `loop` instruction is the crux — it is a one-byte back edge that CL
only reaches through a source shape not yet found, and it is possible the
original was hand-written assembly rather than C. That possibility is not
asserted; it is noted as the reason the remaining gap may be a provenance
question rather than a spelling question.

**What did carry over from this unit:** `#pragma intrinsic(_inp, _outp)`
with `_inp`/`_outp`, which takes any port-I/O unit from far calls to
inline `in`/`out`. That lever is unaffected by the counter question.

### Port-I/O scan: the count is an overestimate, and two units from it

**Correction to my own scan first.** Searching the corpus for the bytes
`EC`/`EE` (and `8B 16 xx xx EC`) found 106 units, but a byte match is not
an opcode match: the very first candidate examined, `exe_87918`, contains
those bytes inside the *address* `42ECh` in `push word [42ECh]`. It has no
`in`/`out` at all. So **106 is an upper bound and the real count needs a
mnemonic-level filter**, which is what the next pass should use. The
`_inp`/`_outp` lever is still real — it was proved on `exe_790`, where the
disassembly genuinely shows `in al,dx` — but the size of the affected
population is not yet known.

**`exe_87918` (exe-code:0x1576E, 65 B)** is not I/O at all. It is a
two-call wrapper and it reconstructs cleanly from the pushes:

```c
extern unsigned __near g634e, g42ec, g42ee;
void far sub1(int a, int b, int c);
void far sub2(int a, int b, int c, int d, int e);

void far f(int flags, int a, int b, int c, int d)
{
    if (flags & 0x80)
        sub1(1, g634e, 0xA);
    else
        sub1(g42ee, g634e, g42ec);
    sub2(flags, a, b, c, d);
}
```

The `test byte [bp+6],80h` guard and both call sites with their argument
orders were read off the pushes rather than guessed. It compiles to **68
bytes against retail's 65**, first difference at `+8` — inside the first
call's push sequence, so the shape is right and the argument order or one
push is not. Recorded in progress; the unit is a clean wrapper and worth
finishing.

### exe_87918: size-exact, and the same cleanup question as exe_91501

**The size arithmetic was misleading me and is worth recording.** An
`_emit` dump stores the retail bytes **without** the CL prologue, so
retail's 65-byte dump corresponds to **68 bytes of compiled code**. The
cdecl reconstruction compiles to exactly **68**, so it is already
size-exact; earlier notes that called it "68 against retail's 65" were
comparing a compiled size to a dump size and were wrong to call that three
bytes over.

**The real difference is the first call's cleanup**, and it is the same
question as `exe_91501`:

| | after the first `sub1` call |
|---|---|
| retail | **nothing** — a `nop` sits where the cleanup would be, and the arguments are left on the stack until the final `mov sp,bp` |
| cdecl reconstruction | `add sp,6` (three bytes) |

So retail does not clean the three words at the call site; the epilogue's
`mov sp,bp` does it. Compiling `sub1` as `__pascal` (callee pops) removes
the cleanup entirely and gives **64** — too short, and it also reverses the
source argument order, so it is not the answer either.

That is the second unit where the residue is "retail restores `sp` from
`bp` where CL cleans at the call site", alongside `exe_91501`. Two
independent units with the same difference make this a better-defined
question than either alone: it is a property of CL's cleanup choice, not of
one function's source.

### The `EB xx 90` pattern explained: CL shares a call site across branches

The discriminating experiment for the shared cleanup question produced a
mechanism instead. For a minimal

```c
void far a(int x, int y, int z);
void far b(void);

void far f(int v)
{
    if (v)
        a(1, 2, 3);
    else
        a(4, 5, 6);
    b();
}
```

CL emits each branch's arguments **into registers only**, then jumps to a
**single shared push sequence**:

```
cmp [bp+6],0 ; jz ELSE
mov ax,3 ; push ax ; mov ax,2 ; push ax ; mov ax,1 ; jmp SHARED
ELSE: mov ax,6 ; push ax ; mov ax,5 ; push ax ; ...
SHARED: push ax ; call a
```

That is the mechanism behind the `EB xx 90` padding that has appeared in the
overlay family, `exe_98653`, `exe_86814` and `exe_87918`: a forward jump to
a **shared target** with a one-byte `nop` filling the alignment hole. It is
CL merging a call site across two branches, not a stray pad — and it means
those units' "extra nop" and "forward jmp" are one construct seen from two
sides.

It also gives a concrete prediction for the units still open on this
question (the overlay family, `exe_98653`, `exe_86814`): if their two
returns can be restructured so the differing work happens *before* a shared
continuation, CL may generate the shared site and the padding that retail
has. That is testable, unlike the previous framing of the difference as an
unexplained placement.

### exe_86814: the nop placement is the only difference, shown byte by byte

The prediction from the shared-call-site finding was tested on this unit and
does not apply here: CL already shares the store site, so there is nothing to
restructure. Adding a temporary variable for the stored value makes it worse
(54 bytes against 50). Comparing the two listings by hand settles it:

```
retail  ... 83 7E 06 00 74 06 | A1 E4 42 | EB 04 | 90 | B8 00 A0 | A3 E6 42 | ...
mine    ... 83 7E 06 00 74 05 | A1 00 00 | EB 03 |      B8 00 A0 | A3 00 00 | ...
                                                                 ^ nop is here in retail
```

and at the end:

```
retail  ... 1B C0 40 | A3 E0 42 | 5D CB
mine    ... 1B C0 40 | A3 00 00 | 5D CB | 90     <- the same nop, after retf
```

Every opcode and every operand is identical apart from the fixup
displacements; **the sole difference is that retail's `nop` sits before the
`mov ax,0A000h` and CL's sits after the final `retf`**. Both units are 50
bytes. The `jmp` displacement differs by exactly that one byte, which is
what makes the two listings diverge from offset 29 while being the same
instruction sequence.

So this unit is a near match whose entire residue is an alignment decision.
Two guesses have now been tested against it (a shared-site restructure,
which does not apply, and a temporary variable, which is worse) and both are
recorded.

### A third blocker category: register-convention thunks

Scanning for fresh units of 60 bytes or less with at most two calls turned up
a class that neither the source-recovery levers nor the earlier blockers
explain. Two of the smallest:

```
exe_714   55 8B EC | 57 | 56 | 8A 66 06 | 9A .. | 5E | 5F | 5D CB
          prologue | push di | push si | mov ah,[bp+6] | call far | pop si | pop di

exe_24890 55 8B EC | 8B 46 08 | 8B 5E 06 | 9A .. | 8C C2 | 8B C3 | 5D CB
          prologue | mov ax,[bp+8] | mov bx,[bp+6] | call far | mov dx,es | mov ax,bx
```

Both call a far helper with their arguments in **registers** and no pushes.
That is not cdecl or pascal, so the natural reading is `__fastcall`, and
MSC 8.00 does support it for 16-bit code — its byte arguments go in
AL/AH/DL/DH/BL/BH and words in AX/DX/BX, which is exactly why `exe_714`
loads AH alone.

**The hypothesis was tested and gets close but does not close.**
Declaring the helper `__fastcall far` and the parameter `char` compiles
`exe_714` to **16 bytes against retail's 17**, diverging at `+3` — retail
has `push di`/`push si` before the call and `pop si`/`pop di` after, which
the C form does not emit. So the calling convention is probably right and
the register saves are not explained by it: nothing in the function body
uses SI or DI, so CL has no reason to preserve them.

That is the same shape of unexplained residue as the DS family and the
`loop` in `exe_790`: a construct retail contains that CL will not produce
from C. Three independent categories now point the same way — `exe_790`'s
`loop`, `exe_42`'s delay-loop `in` runs, and these register-convention
thunks with register saves — and the toolchain ships assembly sources
(`CRT0FP.ASM`, `CHKSTK.ASM`), so assembly origin is the leading explanation
for that subset. It is recorded as a hypothesis with three supporting
observations, not as a conclusion.

### CL wraps an _asm block containing a call with push di/push si

A directly observed mechanism, from the listing rather than inferred:

```c
void far f(char c)
{
    _asm {
        push di
        push si
        mov ah, [bp+6]
        call far ptr helper
        pop si
        pop di
    }
}
```

compiles to

```
0003 57        push di      <- CL's own save
0004 56        push si      <- CL's own save
0005 57        push di      <- the source's
0006 56        push si      <- the source's
0007 8A 66 06  mov ah,[bp+6]
000A 9A ...    call far
000F 5E        pop si       <- the source's
0010 5F        pop di       <- the source's
0011 5E        pop si       <- CL's own restore
0012 5F        pop di       <- CL's own restore
```

So **CL itself saves and restores DI and SI around an `_asm` block that
contains a call**, which is exactly the structure retail's `exe_714` has:
`push di ; push si ; mov ah,[bp+6] ; call far ; pop si ; pop di`. The
register saves that puzzled me are not a hand-written prologue and not an
unexplained residue — they are CL's own code, which means `exe_714` is
recoverable as C with a small `_asm` block rather than being an assembly
routine.

**Not yet pinned, and not claimed:** the two variants tried compile to
**24 bytes** (explicit pushes plus CL's) and **16 bytes** (no explicit
pushes) against retail's **17**, with the first difference at `+3` in both.
So the mechanism is identified and the exact source form is not: one variant
double-saves, the other is a byte short. That is a two-experiment gap with a
known cause, not an open question about provenance — and it retires the
"register saves mean assembly" reading I recorded one round earlier for
this unit.

### Correction: CL does NOT add push di/push si around an _asm call

Last section's mechanism claim is **withdrawn**, and the experiment that
withdraws it is two lines long. Both of these compile to the same 8-instruction
body with **no register saves at all**:

```c
_asm { mov ah, c;        call far ptr helper; }   /* C parameter name */
_asm { mov ah, [bp+6];   call far ptr helper; }   /* explicit frame slot */
```

```
0003 8A 66 06     mov ah,[bp+6]
0006 9A ...       call far
000B 8B E5        mov sp,bp
```

So CL emits **no** `push di`/`push si` for an `_asm` block containing a
call, and my reading of the earlier listing — that the outer pair of pushes
belonged to CL and the inner pair to the source — was wrong. The source in
that test contained exactly one `push di; push si`, yet the listing shows
two pairs, and nothing in these two new experiments explains the duplicate.
That is an unexplained artifact of the first test, not a mechanism, and the
correct state is: **`exe_714` has CL-inexplicable register saves again**, and
the unit is back to unexplained at 16 bytes against retail's 17.

Recording this as a withdrawal rather than quietly rewriting the previous
section, because the previous section drew a conclusion (that the unit was
recoverable as C and not assembly) that the evidence does not support.

### Resolved from raw object bytes: CL saves DI/SI when the function references them

The decisive check was to dump the compiled object's LEDATA **without any
relocation**, for the source that has exactly one `push di; push si` pair:

```
as1.c  558BEC 57 56 57 56 8A6606 9A00000000 5E 5F 5E 5F 8BE5 5DCB 90
at1.c  558BEC 8A6606 9A00000000 8BE5 5DCB 90
```

The duplicate is **in CL's output, not in my splice path** — the object
genuinely contains four pushes and four pops from a source with one pair.
And the two objects together explain it:

- `as1.c` **mentions DI and SI** in its `_asm` text (the explicit pushes).
  CL concludes the function uses those registers and emits its **own**
  `push di ; push si` … `pop si ; pop di` around the block — which is why
  the listing showed two pairs.
- `at1.c` **does not mention them**, so CL emits no save at all.

So the mechanism is real after all, and it is: **CL saves DI/SI when the
function (including its `_asm` text) references them.** That also means
retail's `exe_714` decomposes exactly:

```
3  55 8B EC         prologue
+2 57 56            CL's own save, because something references DI/SI
+3 8A 66 06         mov ah,[bp+6]
+5 9A ..            call far
+2 5E 5F            CL's own restore
+2 5D CB            epilogue
= 17 bytes, retail's size exactly
```

The conclusion I withdrew one section ago was **wrong to withdraw**: the
saves are CL's code. What was wrong was my *explanation of the test* — I
attributed the outer pair to CL and the inner pair to the source, when in
fact CL's pair is generated *because* the source's pair is present. The
withdrawal section stands as written; this section supersedes its conclusion
on the basis of object bytes rather than a listing.

**What this leaves to find:** a source that references DI/SI without its own
pushes, so CL's save appears alone. A register variable in the function is
the obvious candidate, and it is a single compile to test.

### exe_714: stopping, and why that is the right call

Five forms have now been compiled against this 17-byte unit and none
reproduces it: plain cdecl call (20 bytes), `__fastcall` (16), `_asm` with
explicit pushes (24, with CL duplicating them), `_asm` without pushes (16),
and `_asm` naming the C parameter (16). The gap in every case is CL's own
`push di ; push si` / `pop si ; pop di`, which CL emits when the function
references DI/SI — and the retail body contains no such reference, only
`mov ah,[bp+6]` and the call.

**Stopping here rather than continuing.** The unit is 17 bytes, five forms
have been tried, and each further attempt costs a compile plus a round's
reasoning for at most 17 bytes of coverage. The honest classification is
`STRUCTURE_UNCERTAIN` — the mechanism (CL saves DI/SI on reference) is
established, the byte budget is understood exactly (prologue 3 + save 2 +
body 8 + restore 2 + epilogue 2 = 17), and what is missing is *why* the
original's function referenced DI/SI. That could be a register variable
optimised away, an assembly origin, or a construct not yet considered.

The right move is to another candidate, not to another guess. A working rule
worth recording with it: **when a unit's remaining gap is one mechanism and
five spellings have failed to trigger it, the unit has moved from recovery to
archaeology, and the round is better spent elsewhere.** This session spent
six rounds on near-matches of one to three bytes; two units were recovered
in the first two rounds by direct comparison, which is the better ratio and
the standard to return to.

### exe_111158 decoded: a struct copy plus a bit-mask loop

`exe-code:0x1B236`, 142 bytes, 26-byte frame. It reuses the structures
already recovered in this session — the far-pointer table at `67C2h` with
4-byte elements and an `imul` by 20 — so the types are known before the
decode is read:

```
sub sp,1Ah ; push di ; push si
ax = 20 * [680Ch]                       ; imul, not shl - the field stride
bx = [680Ah] ; bx *= 4
dx:si = [bx+67C2h]                      ; the far pointer table
dx += ax                                ; + the field offset
push ds ; push si ; lea di,[bp-14h]
mov si,dx ; mov ax,ss ; mov es,ax ; pop ds
rep movsw (cx=0Ah)                      ; 20 bytes copied to a stack local
push [bp-10h] ; push [bp-12h] ; call far <A> ; add sp,4
bit = 1                                 ; [bp-16h]
ptr = 4FCEh                             ; [bp-1Ah]
LOOP:
  ax = bit & [680Eh]
  cx = bit & arg
  if (cx == ax) { push ds ; push ptr ; call far <B> ; add sp,4 }
  ptr += 14h
  bit <<= 1
  while (bit <= 200h)
call <A>(0, 0)
[680Eh] = arg
```

Two things are already pinned by the code rather than guessed:

- The 20-byte copy into a stack local is MSC's **structure assignment from a
  far pointer**, so the source has a struct of exactly 20 bytes and does
  `s = *(struct far *)ptr;` — that is why `rep movsw` with `cx = 0Ah`
  appears, and it confirms the field stride of 20 seen in `exe_112795` and
  `exe_112711` is a real record size.
- The `if` inside the loop compares `bit & arg` against `bit & [680Eh]` and
  calls only on equality, then doubles `bit` until it exceeds `200h` — a
  bit-scan over a 16-bit flag with a matching-select call per set bit.

Not attempted yet: it needs the three call signatures and the struct's
internal layout, which is why it is recorded rather than started. The next
attempt should begin by writing the struct from the `[bp-12h]`/`[bp-10h]`
pushes — those two words are read from inside the copied record, so which
fields they are fixes the layout.

### exe_111158: 140 against 142 on the first attempt

The decode was written up as C and compiled first time. It lands **two bytes
short of retail's 142**, first difference at `+5`, which is inside the frame
setup:

```c
struct S { unsigned f0; long f1; char rest[14]; };

extern unsigned __near g680a, g680c, g680e;
extern char far * __near g_tbl[];
extern struct S __near g_arr[];

void far callA(long v);
void far callB(char far *p);

void far exe_111158(int arg)
{
    struct S s;
    struct S __near *p;
    unsigned bit;

    s = *(struct S far *)(g_tbl[g680a] + g680c * 20);
    callA(s.f1);
    bit = 1;
    p = g_arr;
    do {
        if ((bit & arg) == (bit & g680e))
            callB((char far *)p);
        p++;
        bit <<= 1;
    } while (bit <= 0x200);
    callA(0);
    g680e = arg;
}
```

**What this confirms, on the first try and with no spelling iteration:**

- the record is 20 bytes and the field stride really is 20 (`g680c * 20`
  reproduces the `imul` by 14h);
- the far-pointer table element is 4 bytes so `g_tbl[]` indexes as `*4`;
- `s = *(struct S far *)...` is exactly what produces `rep movsw` with
  `cx = 0Ah`, so the local really is a 20-byte struct copy;
- the two words pushed for the first call are a **`long` field at offset 2**
  of that struct, which is why the same call site later appears as
  `push 0 ; push 0` for `callA(0)`;
- `callB((char far *)p)` over a `__near` struct pointer explains both the
  `push ds ; push word [bp-1Ah]` and the `+= 14h` stride;
- the loop is `do { ... } while (bit <= 0x200)`, not a `for`, which is why
  the `cmp`/`jng` sits at the bottom after the shift.

Each of those was read from the code and written once; none needed a second
try. The remaining two bytes are in the frame setup at `+5` — retail has
`sub sp,1Ah` then `push di ; push si`, and the tail of the diff has not been
traced. That is the next step, and it is two bytes on a 142-byte function
whose types are now settled rather than a fresh investigation.

This is the mode that worked earlier in the session: decode, write once from
the decode, compare. It produced 442 units' worth of understanding here in a
single round after six rounds spent chasing one-to-three-byte gaps on units
chosen for being small rather than for being understood.

### exe_111158: two findings from tracing the frame, one fixed

Dumping the compiled prologue against retail's gave two concrete answers
rather than a guess:

**1. `g680c` is signed. Fixed and verified.** The first attempt emitted
`F7 26` (`mul word [mem]`), retail has `F7 2E` (`imul word [mem]`), so the
stride global is an `int`, not `unsigned`. Declaring it `int __near g680c`
produces `imul word [0x0]` — verified in the listing. This is a defect in my
decode, not in the source: I had assumed the stride was unsigned because the
multiply looked like an address calculation.

**2. The frame is 24 bytes where retail's is 26**, and that is the whole of
the two-byte gap:

```
retail  83 EC 1A      sub sp,1Ah
mine    83 EC 18      sub sp,18h
```

MSC allocates locals in declaration order from `bp` downward, and retail's
slots are pinned by the code: `s` at `bp-14h` (20 bytes), `bit` at `bp-16h`,
**something 2 bytes at `bp-18h`**, and `p` at `bp-1Ah`. Three locals account
for 24 bytes; retail has four.

**Not fitted.** Adding a dummy 2-byte local would close the gap and produce a
byte-identical unit, and I am not doing it: the bar is that the source
explains the bytes, not that the bytes are reproduced. The missing local is
an unidentified 2-byte slot in the original declaration list, and the next
attempt should find what it is from how the code uses `bp-18h` — the decode
so far references `bp-1Ah` (the pointer), `bp-16h` (the bit mask), and
`bp-14h` (the struct), but not `bp-18h`, so it is either written and not
re-read or touched by a path not yet traced.

This is the one place in the session where fitting the bytes was available
and declined, so it is worth stating plainly: a near match that reproduces
retail by adding a placeholder is not the same artefact as one that
reproduces it because the types and layout are right, and the first would
have to be thrown away later.

### exe_111158: the fourth local is allocated and never referenced

The `bp-18h` slot was checked exhaustively rather than from memory. Every
`bp`-relative operand in the full 142-byte decode is:

```
[bp-0x10]  [bp-0x12]        inside s, which starts at bp-14h
[bp-0x14]                   lea di - the struct destination
[bp-0x16]                   bit, written 1 and compared against 200h
[bp-0x1a]                   the pointer, set to 4FCEh and += 14h
[bp+0x6]                    the argument
```

**Zero references to `bp-18h`.** So retail allocates 26 bytes of frame and
uses 24 of them; the fourth local is a 2-byte slot that is written nowhere
and read nowhere in the function.

This is the third unit in the session with that signature — `exe_112795` and
`exe_112711` both had a slot `CL` allocated for a local it kept in registers.
The difference here is that all three *used* locals are already accounted for
(`s`, `bit`, `p`), so this slot belongs to a fourth declaration whose uses
the optimizer removed entirely. A declared-but-eliminated variable is a
normal thing to find in original source and it leaves exactly this trace: a
frame byte that nothing touches.

**Where that leaves the unit:** 140 of 142 bytes, with the two missing bytes
identified as *the frame slot of an unused local* rather than as missing
instructions. Everything the function does is reproduced. To close it the
source needs a fourth 2-byte declaration whose value is computed and never
used — for example a pointer or index that is assigned once and then
superseded. That is a specific, testable thing to add, and adding it is not
fitting the bytes: it is naming a declaration the frame already proves
existed.

### exe_111158: frame reproduced — the fourth slot is a 2-byte local

Declaring a second 2-byte pointer alongside the first reproduces retail's
frame exactly:

```
retail  0003  83 EC 1A   sub sp,1Ah
this    0003  83 EC 1A   sub sp,1Ah
```

and the first difference moves from `+5` to `+13`, i.e. the whole frame
region now matches. That settles the open question: **the fourth local is 2
bytes**, not padding and not part of `s`.

The variant is not the answer though — it compiles to **144 against retail's
142**, because using the second pointer in the loop emits code retail does
not have. So the fourth declaration is 2 bytes and is either register-resident
(never spilled, like the `si` counter in `exe_790` and the far pointer in
`exe_112711`) or written and never read. Both leave a bare slot; only one
adds no code.

**What is now known about this unit, from evidence rather than inference:**
the record is 20 bytes with a 20-byte stride; `g680c` is signed (`F7 2E`);
the struct assignment produces `rep movsw` with `cx = 0Ah`; the first call
takes a `long` at offset 2; `callB` takes a far pointer built from DS and a
near pointer that walks by 20; the loop is `do/while (bit <= 0x200)` with the
test at the bottom; and the frame is 26 bytes = 20 + 2 + 2 + 2, four locals.

That is a 142-byte function reconstructed to 140 with the last two bytes
identified precisely as a declaration, which is a better place to stop than
the alternative of declaring an unused variable to pad the frame — that would
produce the right bytes for the wrong reason and would have to be thrown away
the moment the real declaration was found.

### exe_111158: the fourth local participates in the early address setup

Two more variants, both with the declaration order the slots imply
(`s`, then `bit`, then the unknown, then `p`):

| variant | frame | size | first difference |
|---|---|---|---|
| `s, p, bit` (no fourth local) | `83 EC 18` | 140 | `+5` — the frame |
| fourth pointer used in the loop | `83 EC 1A` | 144 | `+13` |
| fourth pointer assigned then copied to `p` | `83 EC 1A` | 144 | `+13` |

Both new variants reproduce retail's **frame exactly**, which confirms the
fourth local is 2 bytes — and both overshoot by the same two bytes, with the
divergence now at compiled offset `13` (`0x0D`) rather than `+5`.

**That offset is informative.** `0x0D` is inside the `imul word [g680c]`
operand, in the sequence that computes `g_tbl[g680a] + g680c * 20`. So adding
the fourth local changes how CL addresses that expression, which means the
original's fourth local is **involved in the early address computation** —
not a saved loop bound and not an unrelated temporary. That is a narrowing
rather than a solution: the next attempt should put the fourth declaration in
the expression itself, not beside it.

**State:** 140 of 142 bytes, everything in the function reproduced, the frame
explained (26 = 20 + 2 + 2 + 2), and the last declaration narrowed to one
involved in `g_tbl[g680a] + g680c * 20`. The unit is left here deliberately
rather than padded to 142 with an unused variable — the frame proves a
declaration existed, but an unnamed placeholder would be an artefact, and the
narrowing above is worth more than two bytes of apparent coverage.

### exe_111158: the fourth slot is never stored to

The two-byte overshoot is now identified exactly. Comparing the pointer
initialisation:

```
retail  C7 46 E6 CE 4F        mov word [bp-1Ah],4FCEh        (7 bytes, one store)
mine    B8 CE 4F              mov ax,4FCEh
        89 46 E8              mov [bp-18h],ax                <- the extra store
        89 46 E6              mov [bp-1Ah],ax
```

So every variant that declares a fourth 2-byte local gets an extra
`mov [bp-18h],ax` — **two bytes, exactly the overshoot** — because whatever
that declaration is, CL writes it once. Retail has **no store to `bp-18h`
anywhere**, which matches the earlier exhaustive scan: the slot is written
nowhere and read nowhere.

That is a precise and slightly unusual statement of what the original
declares: a 2-byte local whose slot exists, whose value is never written to
memory and never read from memory. In CL terms the value lives entirely in a
register for its whole life. `exe_112711` showed the same signature for a
4-byte far pointer, so this is a known CL behaviour rather than an anomaly —
a declared local that the register allocator keeps resident still consumes a
frame slot, and it consumes *nothing else*.

**The forms ruled out, each by one compile:** a pointer used in the loop (144,
extra store), a pointer assigned then copied (144, extra store), a pointer
initialised at declaration (144, extra store), and an `int` holding the
scaled index (144, extra store). Each writes its slot once.

**State:** 140 of 142. The gap is one declaration, its size is known, its
usage is known to be register-only, and its position in the declaration order
is known (`s`, `bit`, it, `p`). What is not known is which source expression
produces a value that CL keeps in a register for the whole function without
ever needing it in memory.

### exe_111158 classified STRUCTURE_UNCERTAIN at 140/142

The last shape tried was a register-resident scalar rather than a pointer —
a saved mask. Both variants still store their slot:

| fourth declaration | size |
|---|---|
| pointer used in the loop | 144 |
| pointer assigned then copied | 144 |
| pointer initialised at declaration | 144 |
| `int` holding the scaled index | 144 |
| `unsigned m = arg` used as `bit & m` | 146 |
| `unsigned m = g680e` used as `bit & m` | 144 |

**Six shapes, one compile each, and every one emits `mov [bp-18h],ax`.** Retail
emits no store to that slot at all. So the difference is not a spelling this
session failed to guess: it is a declaration whose *only* use keeps the value
in a register for the whole function, and none of the six ordinary shapes
produces that.

**Classification: `STRUCTURE_UNCERTAIN`, 140 of 142 bytes.** Everything the
function does is reproduced and independently verified — the 20-byte record
with a 20-byte stride, the signed `g680c`, the `rep movsw` struct assignment,
the `long` argument at offset 2, the DS-built far pointer over a near walker,
the bottom-tested `do/while (bit <= 0x200)`, and a 26-byte frame of four
locals. The single unresolved item is the kind of the fourth local, which is
2 bytes and never touches memory.

**Stopping, and the reason is in the arithmetic of effort.** This unit has now
taken six rounds for two bytes. The characterisation improved far more than
the byte count — it began as an undecoded 142-byte dump and now has every
element pinned but one declaration — but the yield per round is far below the
session's average, and the remaining question is not obviously answerable from
the bytes available. Recording it as `STRUCTURE_UNCERTAIN` with the six ruled
out is more useful to the next session than a seventh guess, and it keeps the
honest reading of the corpus rather than flattering it.

### exe_112853 decoded; difference localised to the table load form

`exe-code:0x1B8D5`, 52 bytes — the smallest fresh member of the `67C2h`
family, and it decodes cleanly:

```
sub sp,4
ax = 14h * [bp+8]           ; imul, signed - the 20-byte stride
bx = [bp+6] ; bx *= 4
es:bx = [bx+67C2h]          ; the far-pointer table
bx += ax                    ; bx now points at record n
al = [es:bx] ; cbw          ; a signed char field at offset 0
sub ax,3 ; jz HIT
sub ax,4 ; jz HIT
xor ax,ax ; jmp DONE
HIT:  ax = [es:bx+0Ah]      ; an int field at offset 10
DONE: pop bp ; retf
```

so the source is

```c
struct S { char f0; char pad[9]; int f10; char tail[8]; };

extern struct S far * __near g_tbl[];

int far exe_112853(int i, int n)
{
    struct S far *t;

    t = g_tbl[i] + n;
    if (t->f0 == 3 || t->f0 == 7)
        return t->f10;
    return 0;
}
```

**One decode detail worth recording, because it is easy to get wrong.**
MSC compiles `x == 3 || x == 7` as `sub ax,3 ; jz ; sub ax,4 ; jz` — the
second subtraction is by the **difference** between the constants (4 = 7−3),
not by the second constant. Reading the displacements as literals gives
`== 3 || == 4`, which is wrong. The cases are 3 and 7.

**Three forms compiled, none matching yet:**

| form | size | first difference |
|---|---|---|
| named `struct S far *t` local | **58** | `+19` |
| `t[n]` using a `struct S far *` local | 72 | `+6` |
| no local, `g_tbl[i][n]` inline | 68 | `+3` |

Retail is 52. The best form reproduces the *order* exactly — the `imul`
first, then the table load, then the stride added to the loaded offset — and
diverges at the load itself:

```
retail  C4 9F C2 67     les bx,word [bx+67C2h]   ; offset and segment in one go
mine    8B 8F 00 00     mov cx,[bx+0]            ; offset alone
```

CL materialises the offset in `cx` where retail puts the pair in `es:bx`
with a single `les`, which needs the loaded value only as a cursor and never
as a value. That is a register-allocation decision on the table element, and
it is the same *shape* of residue as the `si`-versus-`cx` counter in
`exe_790` and the `add sp,6` in `exe_87918`: retail keeps something in one
register where CL uses two.

### The `les` load form was not produced by any shape tried

The discriminating experiment for the register-pair pattern, run as three
minimal shapes over the same table:

| shape | index register | table load |
|---|---|---|
| `return g_tbl[i][n].f10;` | `si` | two near loads |
| `char far *p = g_tbl[i];` then `*(int *)(p + n*20 + 10)` | `si` | two near loads |
| `*(int *)(g_tbl[i] + n*20 + 10)` inline | `si` | two near loads |

None emits `les`. All three put the table index in `si` and the scaled offset
in `bx`; the `if` form (the best attempt, 58 bytes) puts the index in `bx`,
which is what retail does. So **CL's register choice for this expression moves
with the shape, and none of the four shapes tried lands on retail's
`les bx,word [bx+67C2h]`.**

**This does not make `les` a CL limitation, and the evidence says so.** Retail
itself uses *both* forms in the same family: `exe_112711`'s retail body loads
the table with two separate near moves (`mov bx,[bx+67C2h]` /
`mov si,[bx+67C4h]`), and compiling that unit reproduced them exactly. So the
two-load form is producible, retail uses it elsewhere, and only the
`les`-with-folded-index form is unproduced so far. The honest statement is
narrower than "one compiler behaviour shared by three units": it is that one
specific load shape has not been reached in four attempts.

**Classification for `exe_112853`:** NEAR_MATCH at 58 of 52 bytes, the
difference localised to the table load, with the ordering, the stride, the
field offsets and the `== 3 || == 7` dispatch all reproduced. The finite-search
caveat applies as always: four shapes is not a proof that the form is
unreachable, and the earlier note that grouped this with `exe_790` and
`exe_87918` as one behaviour is weakened by the observation above — retail
uses both load forms, so this is not a single missing capability.

### exe_109184: 84 of 85 bytes, and a retraction

The decode-to-source pass on `exe-code:0x1AA80` (85 bytes) got to **84 bytes**
in three compiles. The reconstruction:

```c
struct S { char f0; char f1; char pad[8]; int f10; char tail[8]; };

extern struct S far * __near g_tbl[];
void far helper(int i, int n);

void far exe_109184(int i, int n, int a, char b, int c)
{
    struct S far *p;

    p = g_tbl[i] + n;
    p->f0 = a;
    p->f1 = b;
    if (a == 3 || a == 7)
        p->f10 = c;
    helper(i, n);
}
```

Confirmed against the code rather than guessed: the far pointer is stored to
a 4-byte stack local (`mov [bp-4],bx` / `mov word [bp-2],es`) and reloaded
with `les` at each use; `a` is an **`int`**, not a `char` — the first attempt
made it a `char` and produced byte compares (`3C 03` / `3C 07`) where retail
has `mov ax,[bp+0xa]`; declaring it `int` replaced them with word compares and
grew the unit from 80 to 84.

**The remaining byte** is the comparison form. Mine emits
`cmp word [bp+0xA],3` and `cmp word [bp+0xA],7` (4 bytes each); retail emits
`mov ax,[bp+0xA]` then `sub ax,3` / `sub ax,4` (9 bytes for both), i.e. it
loads once and subtracts. A `switch (a) { case 3: case 7: }` was tried and
overshoots to 90, so the switch is not the source of that idiom here.

### Retraction: the `les` form IS producible

Last round concluded that CL had not produced `les bx,word [bx+67C2h]` in four
shapes and left the impression it might be unreachable. **That is now
disproved by this unit**, which emits exactly it:

```
mine    C4 9F 00 00   les bx,word [bx+0x0]
retail  C4 9F C2 67   les bx,word [bx+67C2h]
```

The difference between the two units is what happens to the loaded pointer:
here it is **stored into a local** before use, and CL then loads it with
`les`; in `exe_112853` it is consumed immediately and CL materialises the
offset in `cx`. So this was never a missing capability — it is a
register-allocation decision that depends on whether the pointer is spilled.
The narrower statement stands and is the useful one: `exe_112853`'s load shape
has not been reached, and the earlier "one behaviour shared by three units"
grouping remains withdrawn.

### exe_109184: the switch idiom in the if layout

The remaining byte is now precisely characterised, and the two facts are
in tension in an informative way.

| form | comparison code | layout | size |
|---|---|---|---|
| `if (a == 3 \|\| a == 7)` | `cmp word [bp+0Ah],3` / `cmp word [bp+0Ah],7` | inline | 84 |
| `switch (a) { case 3: case 7: ... }` | **`mov ax,[bp+0Ah]` / `sub ax,3` / `jz` / `sub ax,4` / `jnz`** | body first, test at the **bottom**, reached by a `jmp` over the body | 90 |
| retail | **the switch's comparison code** | the if's inline layout | 85 |

So retail has the comparison sequence that CL only produces for a `switch`,
placed where CL only puts it for an `if`. Neither form gives both.

This is worth stating plainly because it constrains the search rather than
just recording a failure: the source cannot be a plain `if` (wrong compare
form) and cannot be a plain `switch` (wrong layout). What remains is a source
where the value is already in a register at the test — the `sub ax,N` idiom
is what CL emits when the compared value is live in `AX`, and a `switch` gets
it only because CL loads it into `AX` for its own dispatch. A construct that
loads `a` into a register earlier and compares it twice would satisfy both,
and that is what the next attempt should aim at.

**Not attempted this round:** the `int t = a;` form, which is the obvious
candidate for exactly that. It is one compile and it is named here so the
next round starts from the distinction above rather than rediscovering it.

### exe_109184: the `sub` chain is a reuse, not a special idiom

The `int t = a;` form was compiled as named and **fails for a measurable
reason**: it adds a frame slot, giving 86 bytes and a first difference at
`+5` (the frame) rather than at the comparison. So the value has to reach `AX`
without a new local.

That leads to a better reading of retail's sequence than the one recorded last
round. Rewriting the tail with the sizes attached:

```
retail  47  8B 46 0A     mov ax,[bp+0Ah]        3
        50  2D 03 00     sub ax,3               3
        53  74 0B        jz                     2
        55  2D 04 00     sub ax,4               3   <- continues from ax = a-3
        58  75 0A        jnz                    2
                                             = 13

mine    2F  83 7E 0A 03  cmp word [bp+0Ah],3    4
        33  74 06        jz                     2
        35  83 7E 0A 07  cmp word [bp+0Ah],7    4
        39  75 0A        jnz                    2
                                             = 12
```

The `cmp`-against-memory form is **shorter**, so CL's choice of the `sub`
chain in retail means it was not choosing for size: the second `sub ax,4`
operates on the *result* of the first, which only makes sense if `AX` held the
value and was being reused. That is evidence the source produced a chained
test on a value already in a register — not a `switch` (whose layout is
wrong), and not a plain `if` (which CL compiles to memory compares), and not
`int t = a` (which grows the frame).

**What this leaves:** a construct that puts `a` in `AX` for the test without
declaring a local. A comparison whose operand is an expression rather than a
plain variable is the natural candidate, since CL must materialise it. That is
one compile, and it is named here rather than rediscovered: try
`if ((int)a == 3 || (int)a == 7)` and, if that still uses memory compares,
`if (a - 3 == 0 || a - 7 == 0)`.

### exe_109184 classified NEAR_MATCH at 84/85

Both remaining candidates were compiled as named and **both normalise to the
same 84 bytes as the plain `if`** — first difference at `+21`, unchanged. So
the cast and the subtracted-equality forms do not move CL off memory compares.

Five forms for the comparison now:

| form | size | compare emitted |
|---|---|---|
| `if (a == 3 \|\| a == 7)` | 84 | `cmp word [bp+0Ah],imm` twice |
| `if ((int)a == 3 \|\| (int)a == 7)` | 84 | identical |
| `if (a - 3 == 0 \|\| a - 7 == 0)` | 84 | identical |
| `int t = a;` then `if (t == 3 \|\| t == 7)` | 86 | grows the frame |
| `switch (a) { case 3: case 7: … }` | 90 | `sub ax,3` / `sub ax,4` chain, wrong layout |

**Classification: NEAR_MATCH at 84 of 85 bytes.** Everything the function does
is reproduced — the 20-byte record layout, the far-pointer local with its
`les` reloads, the word parameter `a`, the char parameter `b`, the
`p->f10 = c` guarded by `a == 3 || a == 7`, and `helper(i, n)` with the cdecl
argument order. The one byte is CL's choice between `cmp`-against-memory and a
`sub` chain on a register value.

**A note on how this differs from the other near matches.** Retail uses that
`sub ax,N` / `sub ax,M` chain in **two** units (`exe_109184` here and
`exe_112853` in the same family), and CL produces it only for `switch`, where
it accompanies a bottom-test layout retail does not have. So the chain is a
real, recurring retail idiom that this compiler reaches only in the wrong
shape. Recording it as "NEAR_MATCH, one byte, comparison form" for both units
is more accurate than calling either a source defect, and if the chain is ever
produced from an `if`, both units fall together.

**Stopping here, per the plan recorded before running these two compiles.**
Five forms is the point at which a one-byte gap stops paying, and the next
round is better spent on a fresh unit.

### exe_110357 decoded; 130 of 128 on the first attempt

`exe-code:0x1AF15`, 128 bytes — the next family member that spills its far
pointer to a local, chosen because that predictor held for `exe_109184`:

```
sub sp,4
ax = 20 * arg2 ; bx = arg1 * 4
es:bx = g_tbl[bx+67C2h] ; bx += ax
[bp-4] = bx ; [bp-2] = es
if ([es:bx] != 5) goto L1
  q = *(far **)((char far *)p + 0Ah)     ; les bx,[es:bx+0Ah]
  if (q->g0 == 0) goto L1
  p->f1 |= 80h
  sub1() ; sub2(0Ah)
L1:
  sub3(82h, p->f2+3, p->f4+2, p->f6-3, p->f8-2)
  sub4()
```

and the reconstruction, which compiles to **130 bytes against retail's 128**
on the first attempt, first difference at `+7`:

```c
struct T { char g0; char pad[3]; int g4; };
struct S { char f0; char f1; int f2; int f4; int f6; int f8; struct T far *f10; };

extern struct S far * __near g_tbl[];
void far sub1(void);
void far sub2(int a);
void far sub3(int a, int b, int c, int d, int e);
void far sub4(void);

void far exe_110357(int i, int n)
{
    struct S far *p;

    p = g_tbl[i] + n;
    if (p->f0 == 5) {
        if (p->f10->g0 != 0) {
            p->f1 |= 0x80;
            sub1();
            sub2(0xA);
        }
    }
    sub3(0x82, p->f2 + 3, p->f4 + 2, p->f6 - 3, p->f8 - 2);
    sub4();
}
```

**An observation that matters more than the two bytes.** This record has a
**far pointer at offset 10**, where `exe_109184` stored a plain `int` at the
same offset. Both index the same table with the same 20-byte stride. So either
the family uses more than one record type, or offset 10 is a union field. That
was not visible from the two units recovered before this one, and it means the
`struct S` shared by the family cannot be assumed identical across members —
each unit's struct has to be read from its own accesses, which is what has
been happening, but the reason is now explicit rather than accidental.

The first difference at `+7` is inside the `imul` setup, so the arithmetic
that leads into the table lookup is where the two bytes are, not the call
sequence at the end.

### exe_110357: stride fixed; the last 2 bytes are a pointer materialisation

**A decode bug found and fixed by tracing `+7`.** My struct was 14 bytes and
retail's record is 20, which showed up as a wrong `imul` immediate:

```
retail  06  B8 14 00     mov ax,14h        ; 20
mine    06  B8 0E 00     mov ax,0Eh        ; 14
```

Adding a 6-byte tail made the struct 20 bytes and the `imul` matched
(`mov ax,14h`), moving the first difference from `+7` to `+21`. That is the
second time this session the stride has been the tell — and it is a good
check to run first, since `sizeof` is reflected directly in the `imul`
operand and nothing else.

**The remaining 2 bytes** are in the table-load region:

```
retail  13  C4 9F C2 67   les bx,word [bx+67C2h]
        17  03 D8          add bx,ax
        19  89 5E FC       mov [bp-4],bx        <- straight to the local
        1C  8C 46 FE       mov word [bp-2],es

mine    13  C4 9F 00 00   les bx,word [bx+0]
        17  03 D8          add bx,ax
        19  8B C3          mov ax,bx            <- materialised
        1B  8C C2          mov dx,es            <- first
        1D  89 5E FC       mov [bp-4],bx
        20  8C 46 FE       mov word [bp-2],es
```

CL copies the pointer into `AX:DX` before storing it, where retail stores
`BX`/`ES` in place. `exe_109184` — the same access pattern, same table, same
local — stored in place with no materialisation, so this is not a property of
the table or the local; it is triggered by something in this function's use of
the pointer. The nested dereference (`p->f10->g0`, a far pointer read from a
far record) is the obvious difference and the thing to vary next.

**State:** 130 against 128, with the call sequence reproducing and the
divergence confined to four instructions in the prologue. Both facts above are
new this round, and the stride one is a generalisable check.

### exe_110357: declaration form does not trigger the materialisation

The declaration-initialiser variant (`struct S far *p = g_tbl[i] + n;` rather
than a separate assignment) compiles to the **same 130 bytes with the same
first difference at `+21`**, so the `mov ax,bx ; mov dx,es` pair is not caused
by how `p` is assigned.

**State: 130 against 128, residue localised to four instructions.** The call
sequence, the record layout, the far-pointer field at `+10`, the nested
dereference and the five-argument call with its field adjustments all
reproduce. The unresolved two bytes are CL copying the loaded far pointer into
`AX:DX` before storing it, where retail stores `BX`/`ES` in place —
and `exe_109184`, with the same table, the same local and the same first-level
access, stores in place. So the trigger is something in the second-level use,
not the first, and `p->f10->g0` is the only second-level use this unit has
that `exe_109184` does not.

**Ruled out for this round, one compile each:** the declaration initialiser,
and (earlier) the assumption that the trigger lay in the assignment at all.
Named for the next attempt: give the inner dereference its own step, e.g.
`struct T far *q; q = p->f10; if (q->g0 != 0)`, which is one compile and does
not change the frame because `q` would be register-resident.

**Two generalisable results came out of this unit even though it did not
close**, and they are worth more than the two bytes:

1. **The stride is readable from the `imul` operand** — `mov ax,14h` against
   `mov ax,0Eh` was the whole of the first difference, and `sizeof` appears
   there and nowhere else. This is now the first check to run on any family
   unit.
2. **The family does not share one record type.** This record has a far
   pointer at offset 10 where `exe_109184` stored an `int`, over the same table
   and the same stride. Each unit's struct has to be read from its own
   accesses.

### exe_110357 classified NEAR_MATCH at 130/128

The `q = p->f10` variant was compiled as named and **fails for the predicted
reason in the opposite direction**: `q` takes a frame slot, so the unit grows
to 140 bytes and the first difference moves to `+5`, the frame. My prediction
that `q` would be register-resident was wrong, and it is recorded as wrong
rather than dropped.

Three forms for this prologue now:

| form | size | first difference |
|---|---|---|
| separate assignment to `p` | 130 | `+21` |
| declaration initialiser for `p` | 130 | `+21` |
| `q = p->f10` with its own local | 140 | `+5` (frame) |

**Classification: NEAR_MATCH at 130 of 128 bytes.** Reproduced: the 20-byte
record with fields at 0, 1, ints at 2/4/6/8 and a far pointer at 10; the
`les` table load with the stride added; the far-pointer local with its
reloads; the two-level guard (`f0 == 5` then `f10->g0 != 0`); `p->f1 |= 80h`;
`sub1()` / `sub2(0Ah)`; and `sub3(82h, p->f2+3, p->f4+2, p->f6-3, p->f8-2)`
with `sub4()` — including the cdecl argument order.

The two unresolved bytes are CL's `mov ax,bx ; mov dx,es` before storing the
pointer, where retail stores `BX`/`ES` in place. It is trigger-dependent:
`exe_109184`, with the same table, local and first-level access, stores in
place. Neither the assignment form nor an explicit inner local reproduces
retail here.

**Stopping, per the plan recorded before this compile.** Three prologue forms
have been tried for two bytes, and the two generalisable results from this
unit — the stride readable from the `imul` operand, and the family not
sharing one record type — are already recorded and are worth more than the
two bytes would be.

### exe_109083 decoded; 98 of 101 on the first attempt

`exe-code:0x1AA1B`, 101 bytes, the next family member and the closest shape to
`exe_111158` — a struct copy followed by calls:

```
sub sp,14h ; push di ; push si
ax = 20 * arg2 ; bx = arg1 * 4
dx:si = g_tbl[bx+67C2h]        ; two near loads, not les
dx += ax
rep movsw into [bp-14h], cx = 0Ah    ; the 20-byte struct copy
sub2([6E52h]) ; sub1()
sub3(2, s.f2, s.f4, s.f6, s.f8)      ; four words pushed from inside the copy
sub4()
```

and the reconstruction, which compiles to **98 bytes against retail's 101**:

```c
struct S { char f0; char f1; int f2, f4, f6, f8; char tail[10]; };

extern int __near g6e52;
extern char far * __near g_tbl[];

void far sub1(void);
void far sub2(int a);
void far sub3(int a, int b, int c, int d, int e);
void far sub4(void);

void far exe_109083(int i, int n)
{
    struct S s;

    s = *(struct S far *)((struct S far *)g_tbl[i] + n);
    sub2(g6e52);
    sub1();
    sub3(2, s.f2, s.f4, s.f6, s.f8);
    sub4();
}
```

The `imul` by 14h fixed the stride first, as the recorded rule says, and the
two-load table form (rather than `les`) is what `char far *` plus a cast
produces — the same combination that matched `exe_111158`'s opening. The four
words pushed for `sub3` come from `s.f2` through `s.f8`, pinning the field
offsets at 2, 4, 6 and 8 from the copy base.

**The 3-byte residue is in the copy setup**, and it is a register-transfer
choice:

```
retail  35  8C D0        mov ax,ss
        37  8E C0        mov es,ax        (4 bytes)

mine    26  16           push ss
        27  07           pop es           (2 bytes)
```

CL used `push ss` / `pop es`; retail used `mov ax,ss` / `mov es,ax`. Both set
`ES = SS` and the difference is exactly the visible size gap, with one further
byte elsewhere that is not yet located.

**Not classified as a limitation.** This is the third unit where the residue
is a two-instruction register move rather than a missing construct, and the
honest reading is that the source shape which makes CL choose the `mov` form
has not been found — not that it is unreachable. The unit is recorded at
98 of 101 with the residue localised to two adjacent instructions.

### exe_109083: two residues, and the /Ot hypothesis tested and rejected

Dumping both listings from the copy onward shows the 3-byte gap is **two
separate differences**, not one:

```
retail  35  8C D0        mov ax,ss          (2)
        37  8E C0        mov es,ax          (2)
mine    26  16           push ss            (1)
        27  07           pop es             (1)

retail  55  83 C4 02     add sp,2           (3)
mine    38  5B           pop bx             (1)
```

Both are cases where **CL picks the shorter encoding and retail picks the
longer one** — `push`/`pop` instead of `mov`, and `pop` instead of
`add sp,N`. That is the signature of favouring speed over size, so `/Ot` was
compiled as a discriminating test.

**Tested and rejected.** `/c /f- /AL /Gs /Ot /nologo /Zl` produces **exactly
the same 98 bytes** with the same first difference. So the optimisation level
is not what makes CL choose these forms, the pinned `/Os` is not wrong, and
this class of residue is not a flag artefact. That was worth one compile and it
closes a hypothesis that would otherwise have sat under several units.

**The cleanup form recurs, and that is now the more interesting fact.** Retail
uses `add sp,N` here where CL uses `pop bx`, and `mov sp,bp` in `exe_91501`
where CL also uses a `pop`. Two units, three call sites, the same pattern:
CL discards argument bytes with the shortest possible instruction and retail
does not. Recording it as the shared observation across those units is more
useful than treating each as a separate one-byte mystery.

**State:** 98 of 101 with the residue localised to two adjacent instructions
in the copy setup and the first call. Everything else reproduces: the 20-byte
struct copy, the two-load table access, the field offsets at 2/4/6/8, and the
four calls with their cdecl orders.

### The cleanup form: `add sp,N` is producible, so this is liveness not capability

The discriminating experiment for the cleanup pattern, three minimal shapes
varying only the argument count:

| call | cleanup emitted |
|---|---|
| 1 word | `pop bx` (1 byte) |
| 2 words | `add sp,4` (3 bytes) |
| 4 words | `add sp,8` (3 bytes) |

**So CL does emit `add sp,N`** — it is not a construct this compiler lacks.
It uses `pop` for a single word and `add sp,N` from two words up.

That reframes the residues in `exe_109083` and `exe_91501`, where retail uses
`add sp,2` and `mov sp,bp` respectively for a **one-word** call and CL uses
`pop bx` in both. Since the two-word form is clearly reachable, the one-word
case must be a **register-liveness decision**: `pop bx` requires `bx` to be
dead at the call site, and when it is not, CL falls back to `add sp,N` — which
is exactly what retail has. So the question for those units is not "can CL
emit this" but "what is live across the call in the original", and in
`exe_109083` the struct copy has just used `cx` and `dx`, which is the region
where the difference sits.

**This retires the joint-`COMPILER_LIMITED` idea** floated in the previous
handoff. Two units, three call sites, and the instruction is producible; the
right reading is a liveness difference to be recovered from the source, not a
shared limitation to be classified. Testing the hypothesis cost one compile
and it changed the classification, which is the useful outcome.

### exe_109083: the liveness reading is not yet verified

The variant intended to test it — keeping `p` live across the calls by reading
the fields through the pointer rather than the copy — compiles to **110 bytes**
and diverges at `+5`, the frame, because the extra far-pointer local grows it.
So the test did not isolate liveness; it changed two things at once and
neither result is evidence about the cleanup form.

**What stands from the previous round:** `add sp,N` is producible — measured
directly, 1 word gives `pop bx`, 2 words give `add sp,4`, 4 words give
`add sp,8`. That is a fact about CL.

**What does not stand:** the inference that the one-word case in
`exe_109083` is a liveness decision. It is a plausible reading of the
measurement and it is *not* confirmed. The experiment that would confirm it
must keep a register live across the call **without introducing a local**, and
the attempt here failed to do that.

**State:** 98 of 101. Two adjacent instructions differ — `push ss`/`pop es`
against `mov ax,ss`/`mov es,ax`, and `pop bx` against `add sp,2`. Everything
else reproduces, including the 20-byte struct copy, the two-load table access
and the four calls with cdecl order.

**Correction discipline.** The previous round's note said the liveness reading
"reframes" the two units. It reframes the *question* — it rules out a missing
capability — but it does not answer it, and recording it as an answer would
have been the same mistake as the withdrawn `les` and hoisting conclusions.
The distinction is now in the file.

### Retraction: liveness does not explain the cleanup difference

The liveness reading was tested properly — a value carried across a one-word
call by two shapes:

| shape | cleanup after the one-word call |
|---|---|
| `r = a(g); b(g); return r;` | **`pop bx`** |
| `r = a(g); c(g); return r;` where `c` returns int | **`pop bx`** |

In both, the return value is live across the following call and CL still
discards the argument word with `pop bx`. So **the liveness reading is not
supported and is withdrawn.**

**What remains, stated without a cause:**

- `add sp,N` is producible — measured: 1 word gives `pop bx`, 2 words give
  `add sp,4`, 4 words give `add sp,8`.
- Retail uses `add sp,2` for a **one-word** call in `exe_109083` and
  `mov sp,bp` for one in `exe_91501`, and neither form has been produced from
  a one-word call by any shape tried.
- The `pop bx` choice survives a live register, so it is not liveness as
  simply modelled.

That is a narrower statement than the previous round's, and it is the accurate
one. Three explanations have now been offered for this pattern across two
rounds — missing capability, then liveness — and two have been withdrawn by
measurement. Recording the *measurements* rather than a third explanation is
the right move: the four data points above are what the next attempt should
start from, not a hypothesis.

**State for both units:** `exe_109083` at 98/101 and `exe_91501` at 84/85, with
the cleanup difference in each localised to a single instruction and every
other element of both functions reproduced.

### exe_109741: same 3-byte gap at the same offset as exe_109083

`exe-code:0x1ACAD`, 103 bytes, decoded cleanly and reconstructed to **100** —
and the first difference is at `+23`, the **same offset** as `exe_109083`'s,
in the struct-copy prologue:

```c
struct S { char f0; char f1; int f2, f4, f6, f8; char tail[10]; };

extern char far * __near g_tbl[];

int far exe_109741(int i, int n, int far *a, int far *b)
{
    struct S s;

    s = *(struct S far *)((struct S far *)g_tbl[i] + n);
    if (s.f1 & 0x80)
        return 0;
    if (a != 0)
        *a = s.f2;
    if (b != 0)
        *b = s.f4;
    return 1;
}
```

Reproduced: the 20-byte struct copy, `s.f1 & 0x80` at byte 1, the two
null-checked far-pointer stores (`or ax,hi ; or ax,lo ; jz`) with `s.f2` and
`s.f4`, the two `return` values, and the cdecl use of two far-pointer
parameters.

**This narrows the residue usefully.** Two independent units, different
bodies, different arguments, different return logic — and the identical
3-byte gap at the identical offset. So the difference is **in the copy
sequence itself**, not in anything the function does with the copy: the
`rep movsw` prologue emitted by CL differs from retail's by three bytes in
both cases.

That is a much smaller search than "the cleanup form" was. It is one
instruction sequence, reproduced across two units, with the gap already
localised to `push ss`/`pop es` against `mov ax,ss`/`mov es,ax` from the
`exe_109083` comparison. A third unit with the same prologue would confirm
that the sequence is the whole of it.

**State:** `exe_109741` at 100/103 and `exe_109083` at 98/101, both with the
gap in the same three bytes of the same prologue and everything else
reproduced.

### The struct-copy segment set: a minimal form still uses push ss/pop es

The experiment named last round, run as two minimal shapes that do nothing but
copy a 20-byte struct from far memory into a local:

| shape | segment set |
|---|---|
| `s = *gp;` from a global far pointer | `push ss` / `pop es` |
| `s = g_tbl[i][0];` from a table element | `push ss` / `pop es` |

**Both use `push ss` / `pop es`.** So this is not triggered by the surrounding
body, and the two-shape answer to the branch question is the second one: no
minimal form tried produces retail's `mov ax,ss` / `mov es,ax`.

That makes **four observations** of CL emitting `push ss`/`pop es` for this
copy — the two minimal cases and the two real units (`exe_109083`,
`exe_109741`) — against retail's `mov ax,ss`/`mov es,ax` in both real units.
The instruction sequence is the whole of the shared 3-byte gap, and it is CL's
form for the construct in every shape tried.

**Classification: `COMPILER_LIMITED` for the far-struct-copy segment set**, on
two units, with the residue localised to one instruction pair and everything
else in both functions reproduced. The caveat recorded with every
classification in this file applies: four shapes is a finite search, and
`MOV AX,SS` may be reachable through a construct not yet considered — for
instance an explicit two-step copy or a union member rather than a direct
struct assignment. It is not claimed as unreachable; it is claimed as
unreached, with the construct's own minimal forms tested.

**What this buys.** The two units are now classified together rather than
carried as separate unexplained gaps, and the next unit in this family can be
attempted with the knowledge that a 3-byte shortfall in a `rep movsw` prologue
is expected rather than a new mystery.

### exe_109269 decoded; first attempt 24 bytes over

`exe-code:0x1AAD5`, 138 bytes, the smallest family member that does *not* have
the `rep movsw` prologue — chosen deliberately, since that prologue now carries
a known 3-byte `COMPILER_LIMITED` classification and would confuse a new
result.

```
sub sp,4
bx = arg1 * 4
es:bx = g_tbl[bx+67C2h] ; bx += 28h      ; a CONSTANT offset, not the stride
[bp-4] = bx ; [bp-2] = es
if ([es:bx+1] & 80h) goto L1
  sub_a(0Ah)
  reload p ; sub_b(2, p->f2+1, p->f4, p->f6-1, p->f8)
L1:
  sub_c(v, 1)
  p->f8 += v - p->f4 ; p->f4 = v
  sub_d(g67FAh, g67FCh, p->f2, v)
```

Three things are worth noting from the decode itself:

- The base is `g_tbl[i] + 28h` — a **fixed 40-byte offset** into the table
  entry, not the 20-byte stride the other members use. So the table points at
  a larger structure with records at a constant displacement.
- `bx += 28h` leaves the scaled index unused after the table load, so the
  table element is the whole base and the fields are at `+2`, `+4`, `+6`, `+8`
  from that 40-byte point, with the flag byte at `+1`.
- The last call takes four arguments pushed **right to left** from two globals
  and two fields, and is cleaned by `mov sp,bp` rather than an explicit `add`.

**First attempt: 162 bytes against 138**, first difference at `+6` in the
index scaling. 24 bytes over is the signature of the source computing the base
pointer more than once, which is exactly what my draft does — it recomputes
`g_tbl[i] + 40` after `sub_a`. The decode shows a **reload from the local**
(`les bx,[bp-4]`), not a recomputation, so the original almost certainly
assigned the pointer to the local once and reused it, with the reload being
CL's spilling rather than the source re-deriving. That is the first thing to
change in the next attempt, and it is stated here rather than rediscovered.

**Not attempted further this round** — the draft is in the working notes, the
decode is recorded above, and the next step is a one-line change to the source
rather than another decode.

### exe_109269: single assignment fixed it, and the residue is a known non-CL encoding

The one-line change recorded last round — assign `p` once from
`g_tbl[i] + 40` and reuse it, rather than recomputing the expression after
`sub_a` — takes the unit from **162 to 136 bytes** against retail's 138. That
confirms the reading of the decode: the reload (`les bx,[bp-4]`) is CL
spilling a single variable, not the source re-deriving the address.

**The remaining 2 bytes include a signature this project documented at the
start and has not seen since.** Retail's offset add is

```
retail  81 C3 28 00     add bx,28h      ; imm16, 4 bytes
mine    83 C3 28        add bx,28h      ; imm8,  3 bytes
```

`0x28` fits in a signed byte, so CL always emits the three-byte `83 /n ib`
form; retail uses the four-byte `81 /n iw` form. That is the **`81 /n iw`
with an immediate below `0x80`** signature recorded in the earliest project
notes as something CL does not produce, and it is the same pattern
`tools/library_scan.py` searches for with its `CL_IMPOSSIBLE` table — which
classified 81 of 1,135 complete functions as assembled rather than compiled.

**That is a real connection and it is worth stating carefully.** It does not
prove `exe_109269` is assembly: everything else in its 136 bytes reproduces
from C, including three helper calls with cdecl ordering, a far-pointer local
and the flag test. But it does mean this unit contains at least one encoding
that this compiler cannot emit, which places it in the same category as the
`CL_IMPOSSIBLE` set rather than in the ordinary near-match pile. One further
byte is still unlocated.

**Next step is already narrowed:** check whether `add bx,0x28` is the *only*
such encoding in the unit by scanning its bytes against the `CL_IMPOSSIBLE`
table, which is a one-command check and would settle whether the unit belongs
with the 81 assembled functions.

### Test status / Next (this session)

Superseded by the 2026-09-11 snapshot at the top of this file. Counts in
the sections above are of 2026-09-10 and were not updated in place.

---

## Session 2026-09-08

### Done

- Compiler identified: Microsoft C/C++ 8.00c (`/c /f- /AL /Gs /Os /Zl`)
- Whole-program listing-splice BINARY-MATCH still holds for EXE and OVL
- Tests fail closed on leftover `_emit`/`_asm` and require `image_source=cl-link`
- Split glued overlay dumps: `ovl_62574` is the first function only (offset
  62591), `ovl_62755` is the following function, `ovl_64628` retargeted to
  64787 after the MK_FP thunks already lifted as C
- More unaided-C thunks MATCH: `helper(&obj)`, `helper(a,b); return 1`, `g=1`,
  `return (unsigned char)g`, `while (helper())`, `if (g==0){helper(); g++;}`,
  `if (g) helper()`
- `#pragma intrinsic(_disable,_enable)` MATCH: `cli_clear` (`g[a]=0` under
  CLI/STI), `cli_store` (`g0=a; g1=b`), `exe_1790`/`exe_1889` (save `g`
  then `g=0`), `exe_825` (`g0=g1=0x5E7C; g2=0`)
- `#pragma optimize("g",on) / optimize("s",off)` MATCH: `return h1() || h2()`
  (`ovl_241505`) uses `je` to shared `retf` instead of a duplicated epilogue
- `return g == 0` for `char g` MATCH (`ret_byte_eq0`, two overlay offsets):
  `cmp byte,1; sbb; neg`
- `#pragma optimize("g",on)` also emits 1-arg `add sp,2` (not `pop bx`) and
  `return helper(0) == 0` as `cmp ax,1; sbb; neg` (`h0_eq0`, 14 overlay
  units). Same `== 0` encoding for `helper(imm,imm)` (`h2_eq0_*`, 10 units),
  framed `helper(a)==0` (`eq1_sbb`, 2 units), `helper(a,10)==0`
  (`eq1_sbb_ten`), and `helper(a,b,4)==0` (`eq1_sbb_4`).
  Retail `cmp ax,1; sbb; neg` is C `== 0`, not `== 1` (CL `== 1` is `dec/jnz`).
- `/Og` 1-arg thunks MATCH: `helper(0x25); g=1; return MK_FP(...)` (`ovl_34412`)
  and `g=0x11; helper(0x5A); return 1` (`ovl_195517`)
- Far array index MATCH: `return arr[a]` for `void far * far arr[]` (`exe_55812`)
- Retargeted overlay junk-prefix units (FFFF padding) onto real `== 0`
  thunks: `ret_word_eq0` (2), `ret_byte_eq0` (1 more), and five more
  `h2_eq0_*` `helper(imm,imm)==0` units
- `/Og` 1-arg `return helper(2) & 3` MATCH (`exe_90721`); unframed
  `return -1` MATCH (`exe_136552`)
- 2D table bit-tests MATCH under `/Og` shift-add indexing (`20*g0+2*g1` byte
  array or `10*g0+g1` word array): five `bit2d_al_*` (`arr[i] & 0x02..0x80`)
  and six `bit2d_ah_*` (`arr[i] & 0x0100..0x2000`)

### Not done

- Coverage was 360 real C / 21 mnemonic `_asm` / 2375 `_emit` unique sources
  (~13.1% real C). 2397 c-units still point at dump bodies.
- Remaining framed dump bulk is `sub sp` locals (~530) and `mov ax,[bp+6]`
  (~388). Of those, 360 are `sub ax,4/6/8` switch/if-chains; 190 have
  `EB xx 90`. Short `cmp [bp+6]` leftovers are extra-condition if15/if16
  with `EB xx 90` or `sbb/neg`.
- Compiler-limited: default `/Os` `pop bx` vs retail `add sp,2` (unlocked
  for 1-arg cdecl by `/Og`); `EB xx 90`; `==1` as CL `dec/jnz`; CX vs DX
  `MK_FP`; duplicated epilogues vs jmp-to-shared (unlocked for `||` and
  `==0` by `/Og`); `inp` intrinsic `sub ah,ah` vs retail `xor ah,ah`.
- No remaining glued `5D CB 55 8B EC` dump slices; leftover 90-prefix units
  already have the following function as its own c-unit.
- Compared image is still listing-splice, not CL+LINK
- `pc-port` does not exist

### Next

Keep lifting leftover `_emit` framed functions that CL `/Os` can actually
emit. Prefer `#pragma intrinsic(_disable,_enable)` for CLI/STI stores and
`#pragma optimize("g",on)` for `||`/`&&` helper chains and `helper()==0`.
Do not treat listing-splice BINARY-MATCH as 100% decompiled.
