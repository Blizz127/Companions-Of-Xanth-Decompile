# Constraints

Last reviewed: 2026-09-10 by the 2026-09-10 session, with the user, when
redefining the recovered-source bar.

This project's bar lives here so a later session can diff it. Tightening it is
quiet; loosening it is loud. **This file is not weakened to make a change
pass.**

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

The bar is still strict in the direction that matters: 2,376 of 2,836 units
are byte dumps today, so the gate is red and stays red until they are real
source.

## Enforced with numbers

| Dimension | Rule | Checked by | Runs at |
|---|---|---|---|
| No byte dumps | zero `_emit` in `src/**` | `tests/test_c_units.py::..._no_emit_byte_dumps` | task end |
| Unit extents | every resolved dump pattern matches retail | `tests/test_units.py` | every edit |
| Dump/unaided ratchets | see below | `tests/test_units.py` | every edit |
| Retail match | every c-unit compiles to its retail slice | `tests/test_c_units.py::test_each_c_unit_...` | task end, ~15 min |
| Whole image | `XANTH.EXE`/`XANTH.OVL` rebuild byte-identical | `python3 tools/verify.py`, `test_rebuild.py` | task end, ~10 min |

`python3 -m unittest discover -s tests` spends nearly all of its time in wine
compiling 2,811 units, so it does not belong in an edit loop. The fast half —
`python3 -m unittest discover -s tests -p "test_units.py"` — is about 5 seconds
and carries the ratchets, so a regression is caught without the long wait.

## Ratchets (measured, may not regress)

Recorded 2026-09-10 by `python3 tools/coverage.py`. These move only in the
improving direction.

| Metric | Today | Direction | Checked by |
|---|---|---|---|
| `exe-code` `_emit` dump coverage | 97.91% | must not rise | `tests/test_units.py::test_emit_dump_coverage_does_not_increase` |
| `ovl-payload` `_emit` dump coverage | 96.69% | must not rise | same |
| unaided-C unit count | 439 | must not fall | `tests/test_units.py::test_unaided_c_unit_count_does_not_fall` |
| complete far functions still in dump form | 1,145 | must not rise | `python3 tools/coverage.py` |

The 1,145 figure is a **boundary correction, not a relaxation** (2026-09-11).
The count was 1,135 because units that held two functions each were counted
once. Fourteen such glued units were found and separated, each with a
successor unit whose extent confirms `before = after + successor`, and the
covered byte totals are unchanged (187,636 / 314,821). Eight of those splits
created a new unit, so the count of *actual* function bodies rose by eight.
Nothing was recovered and nothing was lost; the denominator was wrong. This
is the first time this ratchet has moved, and it moved up only in the sense
of counting functions that were previously invisible.

A ratchet moving the *wrong* way is a finding, not a merge. If a change
genuinely needs to move one, say so in the commit with the new number and why.

## Open gates (red today, by design)

These are the work queue, not decoration. They are the only red gates.

| Gate | Today | Blocked by |
|---|---|---|
| `test_recovered_sources_have_no_emit_byte_dumps` | 2,376 dump units | function recovery |
| `test_each_c_unit_...::image_source == "cl-link"` | `listing-splice` | an EXE symbol/data map, then deleting the listing fallback |

## Exceptions

| ID | Rule | Path | Reason | Owner | Expires |
|---|---|---|---|---|---|
| E1 | `_emit` floor | `src/**` | 2,376 units still to convert; tracked by the ratchet above | 2026-09-10 session | on completion |

## Not a constraint here

- Compiler limitation is not assumed. A "CL cannot emit this" claim needs a
  controlled experiment (`tools/cl_probe.py`) recorded in `docs/STATUS.md`,
  the same way the `_asm`-forces-a-frame result was.
- The `pc-port` is out of scope and must be derived from matched source; it
  must not become a replacement implementation.
