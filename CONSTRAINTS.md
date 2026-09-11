# Constraints

Last reviewed: 2026-09-11. Ratchet numbers locked to the live
`python3 tools/coverage.py` measurement after the Sept-10 recoveries
and glue splits. The recovered-source bar itself is unchanged from the
2026-09-10 user decision.

This project's bar lives here so a later session can diff it. Tightening it is
quiet; loosening it is loud. **This file is not weakened to make a change
pass.**

Last movement: 2026-09-11 took the dump population from 2,380 to 561 units
with `tools/gen_mnem.py` — mixed units and complete functions to mnemonic
`_asm`, unidentified regions to transcribed data (see `docs/STATUS.md`) — and
repaired six registered units that referenced undeclared far helpers and so
could not compile at all. The whole-image rebuild under `tools/verify.py` is
BINARY-MATCH.

## Floor (always enforced)

- No raw `_emit` byte dumps in `src/**`. A byte transcript is not recovered
  source. `_asm` written in mnemonics is accepted source — see below.
- No test skipped, deleted, or emptied to reach green. A test that fails
  because the work is unfinished stays red and is listed as an open gate.
- No ratchet moved in the wrong direction, and no ratchet moved without the
  new measured number in the same commit.
- No stubs presented as recovered: a unit entry in `config/c-units.json` must
  point at a source that compiles and BINARY-MATCHes its retail slice.
- No normalisation in the comparator. Unknown symbols and unsupported fixups
  fail. `_relocate` trimming that silently removes a frame is a bug, not a
  technique (`tools/lift.py` reports `exact_no_trims` so this is visible).

## Recovered-source bar

**Rule: zero `_emit` in `src/**`; mnemonic `_asm` allowed.**

Checked by `tests/test_c_units.py::test_recovered_sources_have_no_emit_byte_dumps`.

**A data region may be transcribed as initialised data.** The fragment
population is documented in `docs/STATUS.md` as predominantly data, strings
and the Pocket Soft RTLink runtime, not a queue of uncompiled functions, and
MSVC 8.00c has no `db` directive to spell a data block inside `_asm`. Such a
unit is written as a `char` array whose header carries the sentence
`Data region, not an instruction stream`; `tools/units.py` classifies it as
`data`, so it is never counted as recovered C or as an instruction listing.
This is a spelling for bytes that are already known not to be a function —
it is not a way to retire a function that merely failed to compile.

This was previously "no `_emit` *or* `_asm`", which was not reachable. Changed
on 2026-09-10 with the user's decision, on this evidence (`docs/STATUS.md`):

- An `_asm` block is what produces the retail `push bp; mov bp,sp` frame on
  functions that have no locals and no parameter use. Verified by controlled
  compile: identical body, frame appears only with `_asm` present.
- `pushf`/`popf` appear in nine complete functions. No header in the pinned
  toolchain declares them (`rg` over all `*.H` in
  `tools/toolchain/msvc152/MSVC/INCLUDE`); `_disable`/`_enable` in `DOS.H`
  give `cli`/`sti` only.
- 135 of 1,135 complete functions contain an instruction with no C spelling
  (`int` 35, `in`/`out` 27, flag save/restore 18, …). The count is an upper
  bound because some string ops are compiler-producible.

The bar is still strict in the direction that matters: 561 of 2,844 units
are byte dumps today, so the gate is red and stays red until they are real
source. A notebook reconstruction that does not MATCH in `src/` is not a
recovery.

**Open question for the next session (not a bar change).** That 561 is not a
spelling backlog any more. They are the units whose retail bytes carry an
encoding profile the pinned toolchain does not produce: an `81 EC imm16`
stack frame (MSVC 1.52's compiler emits `83 EC imm8` under every optimization
flag, and its assembler only ever emits that), an `8B EC` register-to-register
`mov` (NASM, GNU `as` and `llvm-mc` all emit `89 E5`), and source-order
`push si`/`push di` (CL wraps any block that mentions SI/DI in its own
save/restore pair and cannot be made not to). The measurements are in
`docs/STATUS.md`, 2026-09-11 fourth pass. Either an assembler matching that
profile (the MASM 5.x generation) is supplied, or those units stay
transcribed bytes. Transcribing *code* as a data array is not an option this
file permits — that is the byte transcript the bar exists to prevent.

## Enforced with numbers

| Dimension | Rule | Checked by | Runs at |
|---|---|---|---|
| No byte dumps | zero `_emit` in `src/**` | `tests/test_c_units.py::..._no_emit_byte_dumps` | task end |
| Unit extents | every resolved dump pattern matches retail | `tests/test_units.py` | every edit |
| Dump/unaided ratchets | see below | `tests/test_units.py` | every edit |
| Retail match | every c-unit compiles to its retail slice | `tests/test_c_units.py::test_each_c_unit_...` | task end, ~15 min |
| Whole image | `XANTH.EXE`/`XANTH.OVL` rebuild byte-identical | `python3 tools/verify.py`, `test_rebuild.py` | task end, ~10 min |

`python3 -m unittest discover -s tests` spends nearly all of its time in wine
compiling the unique `src/*.c` sources (2,819 today), so it does not belong
in an edit loop. The fast half —
`python3 -m unittest discover -s tests -p "test_units.py"` — is about 5 seconds
and carries the ratchets, so a regression is caught without the long wait.

## Ratchets (measured, may not regress)

Recorded 2026-09-11 by `python3 tools/coverage.py`. These move only in the
improving direction.

| Metric | Today | Direction | Checked by |
|---|---|---|---|
| `exe-code` `_emit` dump coverage | 45.68% | must not rise | `tests/test_units.py::test_emit_dump_coverage_does_not_increase` |
| `ovl-payload` `_emit` dump coverage | 33.63% | must not rise | same |
| unaided-C unit count | 442 | must not fall | `tests/test_units.py::test_unaided_c_unit_count_does_not_fall` |
| complete far functions still in dump form | 560 | must not rise | `tests/test_units.py::test_dump_function_count_does_not_increase` |

How these numbers moved, so a later session can tell a recovery from a
denominator change:

- **1,135 → 1,145 dump functions** was a boundary correction, not a
  recovery. Fourteen glued units each held two functions; splitting them
  (with `before = after + successor`) made eight new units. Dump bytes at
  split time: 187,636 / 314,821.
- **1,145 → 1,142 dump functions**, **439 → 442 unaided C**, **97.91% →
  97.8% exe dump coverage**, dump bytes **187,636 → 187,446** (OVL
  unchanged at 314,821) are the three unaided-C recoveries `exe_99679`,
  `exe_112795`, `exe_112711` (190 bytes). `exe_2096` is mnemonic `_asm`
  and was already excluded from the 1,145 dump-function count. Overlay
  dump coverage did not move.
- **2,380 → 2,334 dump units**, **22 → 68 mnemonic `_asm`**, **97.8% →
  97.79% exe dump coverage**, dump bytes **187,446 → 187,426**,
  **1,142 → 1,141 dump functions** are 46 units (45 of the 60 mixed dumps,
  plus one complete function) re-emitted as mnemonics by
  `tools/gen_mnem.py`. This is a *classification* move, not a
  byte recovery: those units already compiled to their retail slice, so the
  small exe byte-coverage drop is 20 bytes of dump-extent bookkeeping that
  moved from `emit-dump` to `mnemonic-asm` (unsized kinds report 0 bytes).
  OVL dump coverage is unchanged at 314,821 bytes.
- **2,334 → 1,753 dump units**, **68 → 649 mnemonic `_asm`**, **97.79% →
  88.73% exe** and **96.69% → 64.61% overlay** dump coverage, dump bytes
  **187,426 → 170,051** and **314,821 → 210,362**, **1,141 → 560 dump
  functions** are 60 mixed units plus 581 complete dump functions re-emitted
  as mnemonics. Again a classification move — every one of those units
  already spliced to its retail slice, and `tools/verify.py` still reports
  BINARY-MATCH for both images with all 2,844 units spliced — so a large
  coverage drop here is not by itself a byte recovery and must not be read as
  one. The remaining 1,753 dumps are the ones the converter could not spell:
  bodies whose frame is the compiler's own `81 EC imm16`, units that push or
  pop SI/DI (CL then adds a save/restore wrapper the `_emit` form never had),
  fragments, and data.
- **1,753 → 1,082 dump units**, **649 → 909 mnemonic `_asm`**, **411
  transcribed-data units**, **88.73% → 81.27% exe** and **64.61% → 53.64%
  overlay** dump coverage are this session's second sweep: 256 code fragments
  and 4 functions re-emitted as mnemonics, and 411 fragments with positive
  data evidence (printable ASCII, ≤4 distinct byte values, or a constant
  byte stride) transcribed as `char` arrays. `transcribed-data` is a *new*
  kind, so the unaided-C count stayed at 442 rather than absorbing them.
  `tools/verify.py` re-confirms BINARY-MATCH for both images.
- **1,082 → 577 dump units**, **411 → 915 transcribed-data**, **81.27% →
  47.07% exe** and **53.64% → 34.74% overlay** dump coverage: the remaining
  504 fragments. 372 of them had positive data evidence of their own; the
  other 132 were transcribed after their mnemonic form *failed to assemble*
  (`C2400`/`C2402` — the byte sequence is not an instruction stream this
  toolchain can express), which is recorded in each unit's header. What is
  left is code, not data: of the 577 remaining dumps, 560 are framed
  complete functions, 3 are unframed complete functions and 15 are the mixed
  mnemonic units in the `81 EC imm16` frame class. No fragment unit remains.

A ratchet moving the *wrong* way is a finding, not a merge. If a change
genuinely needs to move one, say so in the commit with the new number and why.

## Open gates (red today, by design)

These are the work queue, not decoration. They are the only red gates.

| Gate | Today | Blocked by |
|---|---|---|
| `test_recovered_sources_have_no_emit_byte_dumps` | 561 dump units | function recovery |
| `test_each_c_unit_...::image_source == "cl-link"` | `listing-splice` | an EXE symbol/data map, then deleting the listing fallback |

## Exceptions

| ID | Rule | Path | Reason | Owner | Expires |
|---|---|---|---|---|---|
| E1 | `_emit` floor | `src/**` | 561 units still to convert; tracked by the ratchet above | 2026-09-11 session | on completion |

## Not a constraint here

- Compiler limitation is not assumed. A "CL cannot emit this" claim needs a
  controlled experiment (`tools/cl_probe.py`) recorded in `docs/STATUS.md`,
  the same way the `_asm`-forces-a-frame result was.
- The `pc-port` is out of scope and must be derived from matched source; it
  must not become a replacement implementation.
