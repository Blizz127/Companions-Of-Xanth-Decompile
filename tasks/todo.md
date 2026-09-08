# Task list

## target-pin (this session)

- [x] Pin ISO / EXE / OVL hashes and identity
- [x] Provenance tools and tests
- [x] TARGET / MATCHING / TOOLCHAIN docs

## compiler-id

- [x] Task: Overlay-linker fingerprint from `XANTH.EXE`
- [x] Task: Code-generation fingerprint (calling convention, prologue, padding)
- [x] Task: Candidate 16-bit Microsoft toolchain inventory — MSVC 8.00c identified

## matching-pipeline

- [x] Whole-file BINARY-MATCH for EXE and OVL via listing rebuild
- [x] Splice 21 EXE + 4 OVL CL 8.00c C units (stores, far-call wrappers, inp, close, getvect)
- [x] Invoke historical LINK.EXE on those objects (Legend OVL layout stays reconstructed)
- [ ] Replace remaining listing functions with C (lds-register wrappers, outp, cli/sti)
