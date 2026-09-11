# Implementation Plan: matching decomp → 100% unaided C

## Overview

`target-pin`, `compiler-id`, and the splice half of `matching-pipeline` are
done: MSVC 8.00c compiles recovered units that BINARY-MATCH retail, and the
whole `XANTH.EXE` + `XANTH.OVL` pair rebuilds byte-identically from a NASM
listing with those units spliced in. What remains is `function-decomp`
itself: the majority of the game is still recovered as `_asm { _emit … }`
byte dumps, and the compared image is still listing-splice rather than
CL + LINK. This plan carries that work forward.

Live corpus and ratchets: `CONSTRAINTS.md` and the snapshot at the top
of `docs/STATUS.md`. The table below is the 2026-09-10 reconnaissance
and is not current.

## Reconnaissance (2026-09-10)

| Fact | Value |
|---|---|
| `config/c-units.json` entries | 2836 (1245 `exe-code`, 1591 `ovl-payload`) |
| unique `src/*.c` sources | 2811 |
| sources that are `_asm`/`_emit` dumps | 2447 |
| sources that are unaided C | 364 |
| `_emit` byte lines across all dumps | 451,490 |
| far-call placeholders in dumps | 10,371 |
| dump coverage of EXE code image (191,656 B) | 98.1% |
| dump coverage of OVL payload (325,595 B) | 97.1% |

Dump-unit shapes (measured, not guessed):

| Shape | Count | Meaning |
|---|---|---|
| `55 8B EC` … `5D CB` | 1118 | complete far function |
| `55 8B EC` … `5D C3` | 17 | complete near function |
| `55 8B EC` … no `ret` | 246 | framed fragment (mid-function slice) |
| no frame at all | 1455 | unframed fragment, thunk, or data |

So the real unit of work is **≈1140 whole far functions** plus the
fragments that belong to them, not 2400 independent functions. Units
overlap in places (a later dump starts inside an earlier one), so the
counts are an upper bound on distinct code.

## Architecture Decisions

- Retail bytes stay authority. A unit only counts when CL 8.00c output
  equals the retail slice with nothing stripped that was not explicitly
  modelled as an OMF fixup.
- Progress is measured by *unaided-C byte coverage*, reported by
  `tools/coverage.py`, not by the listing splice staying green.
- Recovered source may contain mnemonic `_asm` but never `_emit`. The
  original contained inline asm — an `_asm` block is what produces the retail
  frame on functions with no locals — so a no-`_asm` bar was unreachable.
  Decided with the user 2026-09-10; recorded in `CONSTRAINTS.md`.
- Lifting is a compile-and-diff loop, so the loop gets its own tool
  (`tools/lift.py`) that prints the first differing byte with disassembly
  on both sides. Hand-editing without that loop is what made the previous
  session slow.
- `#pragma intrinsic` / `#pragma optimize` are legitimate spelling of the
  original source (they are CL 8.00c source-level knobs), not normalization
  of the comparison. The comparator still refuses non-fixup byte diffs.
- Ghidra (12.1.2, local) is available as an *analysis* aid for
  understanding a function. Its C output is not expected to byte-match and
  is never committed as a recovered unit on its own.

## Task List

### Phase 1: instrumentation
- [x] Task 1: `tools/coverage.py` — per-image unaided-C vs dump coverage, JSON + text
- [x] Task 2: `tools/lift.py` — compile one candidate TU, compare to the retail
      slice, report first mismatch with both disassemblies
- [x] Task 3: unit-shape index (`tools/units.py`) so families can be selected
      by shape instead of by filename

### Checkpoint: instrumentation
- [x] `python3 tools/coverage.py` reproduces the reconnaissance table
- [x] `python3 tools/lift.py <src>` byte-diffs a known-bad candidate

### Phase 2: function recovery
- [ ] Task 4: lift the smallest complete far functions (data/pointer stores,
      cli/sti guarded array access, far-pointer globals) and verify each
- [ ] Task 5: lift the `helper()` / `helper()==0` / `helper(a,b)` thunk families
      still in dump form `/Og` can now express
- [x] Task 6: split glued dump units so each complete function is its own unit
      with its own offset (removes the overlapping-fragment noise)

### Checkpoint: function recovery
- [ ] every lifted unit BINARY-MATCHes its retail slice
- [ ] `tools/coverage.py` unaided-C percentage strictly increased
- [ ] whole-program listing splice still BINARY-MATCHes (no regression)

### Phase 3: cl-link image
- [ ] Task 7: reconstruct the EXE symbol/data map so `rebuild_exe` can prefer
      CL objects + LINK and only fall back to listing for unmatched bytes
- [ ] Task 8: flip `image_source` to `cl-link` for both images
- [ ] Task 9: delete the `_emit` corpus and the listing fallback

### Checkpoint: complete
- [ ] `test_recovered_sources_have_no_emit_dumps` passes
- [ ] `test_rebuild_path_matches_pinned_exe_and_ovl` passes with `cl-link`
- [ ] full suite green

## Risks and Mitigations

| Risk | Impact | Mitigation |
|---|---|---|
| Each function needs CL-specific idioms; no bulk converter exists | High | Use the fast diff loop; attack one shape family at a time |
| Dump units overlap, so "unit count" overstates distinct code | Med | Task 3/6 index real function extents before counting progress |
| Compiler-limited encodings (`EB xx 90`, `==1` as `dec/jnz`, CX vs DX `MK_FP`) cannot be expressed in C | High | Record each as COMPILER-LIMITED with the controlled experiment that proves it; keep mnemonic `_asm` only there |
| A converter takes the cheap road: `_emit` dumps become `_asm` dumps and coverage looks green | Med | `CONSTRAINTS.md` ratchets: unaided-C unit count may not fall, dump byte coverage may not rise |
| `image_source=cl-link` needs a full symbol map, not just code | High | Phase 3 last; it is the only way to close the metric honestly |

## Open Questions

- Does the whole EXE tail (43,193 B) contain code that must also be recovered,
  or is it pure data/CRT?
- Are the 1455 unframed slices all belonging to already-listed functions?
