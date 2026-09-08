# Task list

## target-pin (this session)

- [x] Pin ISO / EXE / OVL hashes and identity
- [x] Provenance tools and tests
- [x] TARGET / MATCHING / TOOLCHAIN docs

## compiler-id

- [ ] Task: Overlay-linker fingerprint from `XANTH.EXE`
  - Acceptance: overlay runtime named or explicitly left UNKNOWN with evidence
  - Verify: documented in `docs/TOOLCHAIN.md`; no compiler named without an experiment
- [ ] Task: Code-generation fingerprint (calling convention, prologue, padding)
  - Acceptance: recorded instruction patterns from the pinned MZ image
  - Verify: evidence file under `evidence/target/`
- [ ] Task: Candidate 16-bit Microsoft toolchain inventory
  - Acceptance: list of compiler builds to try; none marked proven
  - Verify: `docs/TOOLCHAIN.md` updated

## matching-pipeline

- [ ] Blocked on compiler-id
