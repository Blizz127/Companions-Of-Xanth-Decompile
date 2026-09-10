# Companions of Xanth matching decompilation

`tools/verify.py` reports whole-program BINARY-MATCH for this disc’s
`XANTH.EXE` and `XANTH.OVL`. Most recovered code is still a 16-bit
listing; C replacement with MSVC 8.00c is in progress. Independent hash
corroboration of the ISO remains unverified.

The retail executable and overlay are authority. Preserve behavior, bugs,
layouts, overlay placement, and calling conventions. A modern port must be
derived from this decompilation and must not become a replacement
implementation. No game data or proprietary toolchain artifacts belong in Git.

- [Intent](docs/intent/matching-decomp.md)
- [Constraints](CONSTRAINTS.md) — the written bar; do not weaken it to make a change pass
- [Capability map](CAPABILITY-MAP.md)
- [Target and provenance](docs/TARGET.md)
- [Reproduction](docs/REPRODUCE.md)
- [Matching definitions](docs/MATCHING.md)
- [Toolchain evidence](docs/TOOLCHAIN.md)
- [Session handoff](docs/STATUS.md)
- [License notes](LICENSE-NOTES.md)

Working on the remaining functions:

```sh
python3 tools/coverage.py                 # how much of each image is still a byte dump
python3 tools/coverage.py --list function # candidate units, with retail extents
python3 tools/lift.py --show src/exe_1802.c   # retail disassembly of a unit
python3 tools/lift.py src/exe_1802.c          # compile it and byte-diff against retail
python3 tools/cl_probe.py --c '...' --compare exe-code:0x70a   # controlled experiment
```

```sh
python3 -m unittest discover -s tests -v
python3 tools/register_retail.py
python3 tools/verify.py
python3 tools/rebuild.py
```

Verification requires the legally supplied disc described in the target
notes. Extracted payloads remain local and ignored. No license is asserted
over Legend Entertainment, SSI, or related materials.
