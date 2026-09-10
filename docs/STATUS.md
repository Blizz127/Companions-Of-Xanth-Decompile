# Session handoff

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

That makes **a lone `mov es/DS/SS, [mem]`** a fourth provenance signature
alongside `81 /n iw`, segment-prefixed moffs, and the inlined multi-step
`adc` chain — all checkable without a compiler. `exe_64277` stays a near
match; its control flow, cdecl argument, table scaling and call form are all
recovered and recorded.

### Test status

- `tests/test_units.py` — 9 tests, green.
- `test_target` / `test_identify` / `test_retail` / `test_compare` /
  `test_compile_msc` — green.
- Still red by design, which is the work queue:
  `test_recovered_sources_have_no_emit_byte_dumps` (2,376 dump units left),
  and `test_rebuild_path_matches_pinned_exe_and_ovl`'s
  `image_source == "cl-link"` assertion. The listing splice still
  BINARY-MATCHes both images.

### Next

1. Lift with `tools/lift.py`; pick targets with `coverage.py --list function`.
   The 1,000 complete functions containing only compiler-producible
   instructions are the tractable set; `exe_1768`, `exe_1802` and `exe_98653`
   are the recorded near-misses with the exact byte diff.
2. Convert the 60 unresolved mixed-`_asm` units so no `_emit` remains there
   (cheap, they already carry mnemonics).
3. `image_source=cl-link` needs an EXE symbol/data map, not just code; it is
   the only way to close the metric honestly.

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
