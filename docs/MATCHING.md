# Status definitions and evidence limits

- UNKNOWN: candidate with no validated identity; boundaries may be unverified.
- IDENTIFIED: function correspondence supported by recorded binary signals.
- PROTOTYPED: interface hypothesis documented, body not reconstructed.
- DECOMPILED: source reconstruction exists without demonstrated equivalence.
- LOGIC-MATCH: behavior equivalence supported by explicit tests/analysis, not bytes.
- ASM-NEAR: recorded assembly differences remain.
- ASM-MATCH: complete instruction/operand equivalence under documented relocation.
- BINARY-MATCH: every byte of the bounded function equals retail after explicit
  MZ fixups; no skipped operands, stripped instructions, or padding trim.
- BLOCKED: required input unavailable, with concrete evidence.
- COMPILER-LIMITED: controlled experiments demonstrate the remaining compiler
  limitation. Failure with one compiler is insufficient.

BINARY-MATCH implies ASM-MATCH for the same function, but is one exclusive
inventory status. It does not prove the historical compiler, original source
spelling, whole executable layout, overlay placement, or all callers'
reconstructed behavior.

The matching units are `XANTH.EXE` and `XANTH.OVL` together. A function that
matches inside the MZ image is not a rebuilt game. Overlay bytes are not
optional.

No normalization is used by the comparator. Unknown symbols and unsupported
fixups fail. Modern compiler success does not identify the original toolchain.

## Recovered-source bar

Decided 2026-09-10 (see `CONSTRAINTS.md` for the numbers and
`docs/STATUS.md` for the experiments):

- **A recovered unit is source, not a byte transcript.** No `_emit` anywhere
  in `src/**`.
- **`_asm` in mnemonics is source.** The original contained inline asm: an
  `_asm` block is what produces the retail `push bp; mov bp,sp` frame on
  functions with no locals, and `pushf`/`popf`/`int`/`in`/`out` have no C
  spelling in this toolchain.
- The previous bar — no `_asm` at all — was not reachable and was replaced
  rather than quietly edited. The gate it protects is still red: 2,376 of
  2,836 units are byte dumps.

A unit counts as recovered only when `tools/lift.py` shows it compiling to its
retail slice, and `exact_no_trims` is reported so a match that survives
`_relocate` trimming is not mistaken for a strict one.
