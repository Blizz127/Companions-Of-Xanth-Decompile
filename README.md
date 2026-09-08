# Companions of Xanth matching decompilation

Nothing is matched yet. The target is the 1997 budget CD (ISO volume
`XANBUD`); independent hash corroboration remains unverified. This is a
target-pin, not a rebuilt game.

The retail executable and overlay are authority. Preserve behavior, bugs,
layouts, overlay placement, and calling conventions. A modern port must be
derived from this decompilation and must not become a replacement
implementation. No game data or proprietary toolchain artifacts belong in Git.

- [Intent](docs/intent/matching-decomp.md)
- [Capability map](CAPABILITY-MAP.md)
- [Target and provenance](docs/TARGET.md)
- [Reproduction](docs/REPRODUCE.md)
- [Matching definitions](docs/MATCHING.md)
- [Toolchain evidence](docs/TOOLCHAIN.md)
- [Session handoff](docs/STATUS.md)
- [License notes](LICENSE-NOTES.md)

```sh
python3 -m unittest discover -s tests -v
python3 tools/register_retail.py
python3 tools/verify.py
```

Verification requires the legally supplied disc described in the target
notes. Extracted payloads remain local and ignored. No license is asserted
over Legend Entertainment, SSI, or related materials.
