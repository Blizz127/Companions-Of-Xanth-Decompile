# Task list

Target: 100% unaided C for `XANTH.EXE` + `XANTH.OVL`, compared via CL + LINK.

## target-pin

- [x] Pin ISO / EXE / OVL hashes and identity
- [x] Provenance tools and tests
- [x] TARGET / MATCHING / TOOLCHAIN docs

## compiler-id

- [x] Task: Overlay-linker fingerprint from `XANTH.EXE`
- [x] Task: Code-generation fingerprint (calling convention, prologue, padding)
- [x] Task: Candidate 16-bit Microsoft toolchain inventory — MSVC 8.00c identified

## matching-pipeline

- [x] Whole-file BINARY-MATCH for EXE and OVL via listing rebuild
- [x] Splice 55 EXE + 56 OVL CL 8.00c C units (stores, far-call wrappers, DOS, MK_FP)
- [x] Invoke historical LINK.EXE on those objects (Legend OVL layout stays reconstructed)

## function-decomp

Corpus as measured on 2026-09-10 by `tools/coverage.py`: 2,836 units
(1,245 `exe-code`, 1,591 `ovl-payload`); 2,376 `_emit` dumps covering 97.9% of
the EXE code image and 96.7% of the OVL payload; 439 unaided-C units; 21 mixed
mnemonic-`_asm` units. 1,135 units are complete framed far functions.

### Phase 1 — instrumentation

- [x] Task 1: `tools/units.py` — unit index, dump → retail extent, shape
- [x] Task 2: `tools/coverage.py` — unaided-C vs dump byte coverage
- [x] Task 3: `tools/lift.py` — compile-and-diff loop for one unit or a batch
- [x] Task 4: `tools/cl_probe.py` — controlled-experiment harness
- [x] Task 5: `tests/test_units.py` — 7 tests over the above

### Checkpoint: instrumentation

- [x] `coverage.py` reports the corpus table (97.9% / 96.7% dump)
- [x] `lift.py` byte-diffs a deliberately wrong candidate
- [x] new tests green

### Decided — the recovery bar

- [x] Bar is **no raw `_emit` byte dumps**; mnemonic `_asm` is source.
      Decided with the user 2026-09-10 on the evidence in `docs/STATUS.md`.
      Recorded in `CONSTRAINTS.md` and `docs/MATCHING.md`.
- [x] Applied to `test_recovered_sources_have_no_emit_byte_dumps`, plus two
      ratchets in `tests/test_units.py` (dump coverage may not rise, unaided-C
      unit count may not fall) so the relaxation is not a free pass.

### Phase 2 — function recovery

- [ ] Task 6: lift frames whose body is ordinary C first (`coverage.py --list function`)
      Known-good idioms: `#pragma intrinsic(_disable,_enable)` for CLI/STI
      stores and `char c = g; if (c) h();` for the 5-byte load-and-test.
- [ ] Task 7: resolve the outstanding MISMATCH cases
      `exe_1768` (value held across a cli/sti guarded swap with no local),
      `exe_1802` (`les bx` far-pointer store register choice),
      `exe_98653` (jump to a shared epilogue from an if/else).
- [ ] Task 8: convert the 60 unresolved mixed-`_asm` dumps so no `_emit` remains
- [ ] Task 9: split glued dump units so each complete function is one unit

### Checkpoint: function recovery

- [ ] every lifted unit BINARY-MATCHes its retail slice
- [ ] unaided-C coverage strictly increased
- [ ] whole-program listing splice still BINARY-MATCHes

### Phase 3 — CL + LINK image

- [ ] Task 10: reconstruct the EXE symbol/data map
- [ ] Task 11: flip `image_source` to `cl-link` for both images
- [ ] Task 12: delete the `_emit` corpus and the listing fallback

### Checkpoint: complete

- [ ] `test_recovered_sources_have_no_emit_dumps` passes under the decided bar
- [ ] `test_rebuild_path_matches_pinned_exe_and_ovl` passes with `cl-link`
- [ ] full suite green

## Known compiler-limited encodings

Each needs the controlled experiment (`tools/cl_probe.py`) before it can be
called COMPILER-LIMITED rather than unlifted.

- default `/Os` `pop bx` vs retail `add sp,2` (unlocked for 1-arg cdecl by `/Og`)
- `EB xx 90` padding
- `== 1` spelled `dec/jnz`
- CX vs DX register choice in `MK_FP`
- duplicated epilogues vs jmp-to-shared (unlocked for `||` and `== 0` by `/Og`,
  **not** for the `if/else` in `exe_98653`)
- `inp` intrinsic `sub ah,ah` vs retail `xor ah,ah`
- a named local live across `_disable()`/`_enable()` is spilled to the stack

## Out of scope here

- `pc-port` — does not exist yet; must be derived from matched source
