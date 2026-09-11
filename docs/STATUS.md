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

`exe_64277` stays a near match; its control flow, cdecl argument, table
scaling and call form are all recovered and recorded.

**Correction, so this is not overstated.** A raw byte scan finds
`8E /r` with a `[disp16]` operand in **162 of 1,134** complete functions,
but that is *not* 162 units this compiler cannot produce. An ordinary far
pointer dereference compiles to exactly `mov es,[g]; mov bx,es:[disp]`
(for example `exe_5934`: `mov es,[53C0h]; mov bx,es:[2Ch]`), which is
plain C. The narrow, defensible form of the signature is: a segment
register loaded from memory while the **offset is a constant**, with no load
of the offset half. That is what `exe_64277` does
(`mov es,[5A5Eh]` then `call far [es:bx+135Ah]`) and it is what has no
C spelling here. Distinguishing the two needs the operand decode, not a
substring search, so no count of that narrowed set is claimed yet.

### Segment-load classification: 162 sites, 14 with a C route

Two more controlled experiments close the `exe_64277` question:

| source | ES load |
|---|---|
| `*(unsigned far *)MK_FP(g_seg, 0x2C)` (load) | runtime helper, then `cwd; mov bx,ax; mov es,dx; mov ax,[es:bx]` |
| `(*fp)(arg)` with `MK_FP(g_seg, const)` (call) | runtime helper, then `cwd; mov bx,ax; mov es,dx` |

So `MK_FP` with a variable segment never yields a bare `mov es,[mem]`, in
either the load or the call context.

**A checkable classification** (heuristic, rule stated): for a far pointer
variable stored at address A the offset half is at A and the segment half at
A+2, so a C-expressible dereference both loads `[A+2]` into a segment
register *and* reads `[A]`. Applying that to every complete function:

| | count |
|---|---|
| complete functions with a `mov es/ds/ss,[disp16]` site | **162** |
| the paired offset half is also read (C-expressible) | **14** |
| segment-only with a constant offset (the `exe_64277` blocker) | 148 |

The rule is a heuristic, not a proof: a function can read both halves for
unrelated reasons. Two samples were hand-verified in both directions —
`exe_5934` (`mov es,[53C0h]; mov bx,es:[2Ch]`, constant offset, no pair →
blocker) and `exe_123400` (paired, and blocked for a different reason
below). The 148 figure should be treated as an upper bound on the blocker
until more samples are hand-checked.

**`exe_123400` (exe-code:0x1e208, 131 B) is blocked by a different
mechanism.** It is a near function (`pop bp; ret`) with a full
register-save prologue (`push ax/bx/cx/dx/di/si/ds; pushf`) and a
matching epilogue, plus `test word [cs:0D27h],100h` and
`mov ax,cs; mov ds,ax`. It looks like an interrupt-callback frame. No C
spelling gives the all-register save plus `pushf`, and the CS-relative
memory operand has the same problem as `exe_489`. Recorded as blocked by
the CS-relative access and register-save mechanisms, not by the segment
load.

### Near match at one instruction: exe_2021 (exe-code:0x7e5, 30 B)

Retail is a CLI/STI guarded array store:

```
mov bx,[bp+6] ; mov ax,[bp+8]   ; pointer and value loaded first
cli
mov [bx+407Dh],ax              ; s->v = v
or ax,ax : jnz
les bx,[bx+407Fh]              ; s->p
mov word [es:bx],0FFh
sti
```

The natural reconstruction is the no-local form of the proven
`_disable`/`_enable` idiom:

```c
struct S { int v; int far *p; };
struct S g[1];

void far f(int off, int v)
{
    _disable();
    *(int *)((char *)g + off) = v;
    if (v == 0)
        **(int far **)((char *)g + off + 2) = 0xFF;
    _enable();
}
```

It compiles to **exactly 30 bytes with an identical instruction sequence**,
including the folded displacement, the branch, the far-pointer load and the
`mov word [es:bx],0FFh`. The single difference is the position of `cli`:
CL emits it before the two parameter loads, retail emits it after.

Three earlier spellings established the constraints that get to this point:
a struct array with a scaled index introduces `imul` (blocker), declaring
`struct S *s` as a local adds `sub sp,6`, and `add bx,offset g` appears
unless the base is folded into the displacement. The no-local form is the
only one that reproduces the addressing.

`cli` placement does not move under `/Od`, `/Oa` or `/Ol`: all three
still emit `cli` first. So either a construct this build does not provide
(`_asm` positioned after the loads, or a different compiler's scheduler)
produced it, or the source used inline asm for the two loads. The latter is
rejected as a mechanical transcript. Recorded as a near match: same length,
same instruction sequence, one instruction reordered.

### exe_2021 classified COMPILER-LIMITED on the cli position

The no-local reconstruction matches retail on 30 of 30 bytes with an
identical instruction sequence; only `cli` sits in a different place. Six
configurations were compiled, and every one emits `cli` before the two
parameter loads:

| configuration | result |
|---|---|
| default `/Os` | `cli` first, 30 bytes, rest byte-identical |
| `/Od` | `cli` first |
| `/Oa` | `cli` first |
| `/Ol` | `cli` first |
| `#pragma optimize("s",off)` | `cli` first |
| `#pragma optimize("g",on)` | `cli` first, 34 bytes (adds a reload) |

So the residue is a scheduling property of this compiler build, not a
missing source spelling: no configuration tried keeps `cli` after the
loads. Per `docs/MATCHING.md`, that is what COMPILER-LIMITED means —
controlled experiments demonstrate the remaining limitation of *this*
toolchain. It is not proof that no C spelling exists on some other build,
and the entry stays a dump rather than being written into `src/` with a
knowing mismatch.

Sibling `exe_2051` (exe-code:0x803, 30 B) shows the same `cli` residue *and*
a second one: retail reuses the `add`'s flags for both the `js` and the
`jnz`, while CL reloads the value (`cmp word [bx],0`) and the unit grows to
38 bytes. Same family, one extra compiler-level difference.

Three configurations for the sibling would not be a better use of the next
hour than finding a family with no residue at all.

### 30 function units contain a second prologue (glued functions)

Scanning every function-shaped unit for a `55 8B EC` after its own
prologue finds it in **30 of 1,134** units. At least one is a genuine
glue: `exe_18064` (exe-code:0x4690, 32 B) is two functions in one unit —

```
mov bx,[bp+6] ; mov ah,68h ; int 21h ; jmp far ...   <- function A tail-calls out
mov ax,[bp+6] ; mov ah,35h ; int 21h ; mov dx,es ; mov ax,bx ; ... ; retf
```

A tail-calling function has no `retf`, so the splitter's
`prologue ... retf` rule walked straight past the boundary and swallowed
function B as well. Such a unit cannot be recovered as one C function: no
single source compiles to a function that jumps away and then defines a
second function inline.

**This is not yet a verified count of glued units.** An interior
`55 8B EC` can also be data (an immediate or a jump-table entry) rather
than code. The 30 need per-unit disassembly before any boundary change is
made; only `exe_18064` is hand-verified so far. Splitting them is a
justified boundary correction under the project rules, but each split has
to be evidenced with the surrounding control flow, not just the byte
pattern, and the unit totals must not be adjusted until then.

### Glue verification: 14 confirmed, and why "ret-terminated fragments" is a trap

Verification rule: a real function boundary exists when the instruction that
**ends exactly at** the interior prologue is an unconditional transfer.
Applying it to the 30 interior-prologue units:

| outcome | count |
|---|---|
| preceded by a `ret`/`retf` — two functions in one unit, confirmed | **14** |
| preceded by a `jmp` — needs per-unit control-flow work | 6 |
| not a boundary (data, or no instruction ends there) | 10 |

The dominant terminator in the confirmed 14 is `retf imm16`
(`CA imm16`, disassembled as `retf word 2/6/8/16`) — the
`__pascal`/`__stdcall` far return. The splitter recognises `CB`/`C3`
but not `CA imm16`/`C2 imm16`, so those functions were merged with their
successors. That is the mechanism, and it is a defect in the splitter's
terminator set rather than a compiler or provenance limit. Confirmed units
include `exe_6094`, `exe_13444`, `exe_14566`, `exe_18240`,
`exe_24910`, `exe_26556`, `exe_30534`, `exe_30747`, `exe_31345`,
`exe_34621`, `exe_34698`, `exe_34775`, `exe_35054`, `exe_100371`.

**Rejected over-count, recorded so it is not chased.** Counting fragment
units whose last instruction is a `ret`/`retf` gives 365 of 1,171, which
looks like 365 functions with non-standard prologues the classifier missed.
It is not. Sampling the smallest shows `stc; retf`, `push es; retf`,
`add dl,bh; retf` — the RTLink overlay-thunk idiom, i.e. data. The 365
figure is heavily polluted by thunks and is **not** evidence of missed
functions; no count of missed functions is claimed from it.

### Boundary correction attempted, half-applied state reverted

**Dump format, now written down** (needed by anyone editing a unit):
a dump is the retail bytes *minus* the CL-generated `55 8B EC` prologue
(3 bytes) and *minus* the CL-generated trailing epilogue, with each far call
written as `call far ptr NAME` — a **5-byte wildcard**, not five `_emit`
lines. Token accounting must count 1 byte for `_emit` and 5 for a far call;
counting only `_emit` lines miscounts by 5 per far call and was the first
bug in the correction script.

**Six of the fourteen confirmed glues have a successor unit already
sitting at the cut point** — so those pairs *overlap* and double-cover
bytes:

| leading unit | cut | successor already present |
|---|---|---|
| `exe_6094` | +43 | `exe_6137` |
| `exe_13444` | +510 | `exe_13954` |
| `exe_14566` | +82 | `exe_14648` |
| `exe_34621` | +42 | `exe_34663` |
| `exe_34698` | +42 | `exe_34740` |
| `exe_34775` | +42 | `exe_34817` |

Measuring all function-shaped units: **20 overlapping pairs in
`exe-code`, 0 in `ovl-payload`**.

**The correction is two-part, and part (a) alone is a regression.**
Truncating each leading dump's token stream to `cut - 3` bytes was
implemented and verified byte-exact (the dump reproduces
`retail[offset+3 : offset+3+n]`), and the six extents did drop to 43, 510,
82, 42, 42 and 42. But every one of them then classified as
`framed-fragment` instead of `function`, because their first function ends
in `retf imm16` — and `tools/units.py`'s `EPILOGUES` /
`_RET` tuples only contain `CB`/`C3` forms. So the fix must be:

1. extend the epilogue matching to `retf imm16` (`CA iw`) and
   `ret imm16` (`C2 iw`), and
2. then truncate the leading dumps.

Doing (2) without (1) turns six functions into fragments, which is why the
half-applied state was reverted rather than committed. The reverted tree
still has 1,134 function units. Widening `EPILOGUES` also changes
`resolve_extent` for every unit, so the dump-coverage ratchet in
`tests/test_units.py` must be re-measured as part of the same change, not
after it.

### Boundary correction applied to four units

The two-part fix was done in the right order and landed.

1. `tools/units.py` gained `returns()`, which recognises `5d ca iw`
   (`retf imm16`) and `5d c2 iw` (`ret imm16`) alongside `5d cb`/`5d c3`,
   and `classify` now uses it. These are the `__pascal`/`__stdcall` far
   returns the splitter missed. On its own this corrected `exe_26464` from
   `framed-fragment` to `function` (1,134 -> 1,135 functions).
2. Four of the six overlapping glued units were then truncated, with the
   successor's extent confirming the arithmetic exactly:

| unit | extent before | after | successor | successor extent |
|---|---|---|---|---|
| `exe_6094` | 144 | **43** | `exe_6137` | 101 |
| `exe_34621` | 77 | **42** | `exe_34663` | 35 |
| `exe_34698` | 77 | **42** | `exe_34740` | 35 |
| `exe_34775` | 278 | **42** | `exe_34817` | 236 |

Every pair satisfies `before = after + successor_extent`, and the measured
`emit-dump` byte totals are unchanged (`exe-code` 187,636;
`ovl-payload` 314,821), so the covered byte union is provably identical.
The overlap is gone and neither unit is glued any more.

**Two of the six were reverted, not split.** `exe_13444` and `exe_14566`
do not end in a recognised epilogue after truncation, so their cut is not
established by the same evidence. They keep their committed extents (594
and 203) until their boundaries are confirmed by control flow rather than
by the presence of a prologue byte.

**A widening that was tried and rejected.** Accepting a bare trailing
`CB`/`C3` as "ends in a return" reclassified **640** fragments as
`unframed-function` (7 -> 647, fragments 1,171 -> 531) on the strength of a
single trailing byte. That is not evidence those units are functions, so it
was reverted and only the `5d`-prefixed forms are accepted.

The invariant test that asserts function-shaped units end with a return now
calls `units.returns()` instead of matching two byte pairs by hand, so the
assertion and the classifier cannot drift apart again. The coverage
ratchets are untouched and still pass.

### All six glue splits landed; the return test is now asymmetric

`exe_13444` and `exe_14566` were finished after the reason they resisted
became clear. Their predecessors end `pop di; ret` (`5f c3`) and
`pop di; retf` (`5f cb`) — a `pop <reg>` then return tail, not the
`pop bp` tail the predicate demanded.

Rather than loosen the test for everything (which previously reclassified
640 fragments as `unframed-function` on a single trailing byte), the rule
is now asymmetric, which matches how much evidence each case actually has:

| unit shape | predicate | why |
|---|---|---|
| starts with `55 8B EC` | `ends_in_return` — final instruction is any return (`c3`/`cb`, or `ca`/`c2` + imm16) | it is already framed, so a trailing return is strong evidence |
| no prologue | `returns` — requires a `pop <reg>` + return pair | weak evidence otherwise; a lone trailing ret byte is not enough |

Effect on the corpus, with the byte totals unchanged (`exe-code` 187,636;
`ovl-payload` 314,821, identical to before any of this work):

| shape | before | after |
|---|---|---|
| `function` | 1,135 | **1,137** |
| `framed-fragment` | 3 | **0** |
| `unframed-function` | 7 | 7 |
| `fragment` | 1,171 | 1,171 |
| `unknown` | 520 | 521 |

No fragment was promoted, no function was demoted, and nothing was
skipped: both the `framed-fragment` reclassifications and the six extent
corrections are accounted for by the arithmetic in the tables above and in
the "Boundary correction applied to four units" section.

Final state of the six splits, each verified by
`before = after + successor_extent`:

| unit | before | after | successor |
|---|---|---|---|
| `exe_6094` | 144 | 43 | `exe_6137` (101) |
| `exe_13444` | 594 | 510 | `exe_13954` (84) |
| `exe_14566` | 203 | 82 | `exe_14648` (121) |
| `exe_34621` | 77 | 42 | `exe_34663` (35) |
| `exe_34698` | 77 | 42 | `exe_34740` (35) |
| `exe_34775` | 278 | 42 | `exe_34817` (236) |

### All fourteen glue units separated

The eight confirmed glues whose successor did not yet exist were split, so
every glue found in this corpus is now two independent units. Each new unit
was created by taking the tail's tokens, dropping the three prologue bytes
CL generates for it, and writing a normal dump source plus a
`config/c-units.json` entry. No extent was guessed: `resolve_extent` derived
each tail from its own dump, and the resulting number was compared against
`old_extent - cut` *after* the fact:

| new unit | extent (derived) | predicted (`old - cut`) |
|---|---|---|
| `exe_18274` | 704 | 704 |
| `exe_25234` | 1230 | 1230 |
| `exe_26628` | 3906 | 3906 |
| `exe_30576` | 171 | 171 |
| `exe_30807` | 538 | 538 |
| `exe_31405` | 3216 | 3216 |
| `exe_35139` | 1113 | 1113 |
| `exe_100448` | 548 | 548 |

All sixteen pieces classify as `function`. Covered byte totals are unchanged
(187,636 / 314,821), total units 2,836 -> 2,844, function units
1,137 -> 1,145.

**The function-count ratchet moved from 1,135 to 1,145 and that is recorded
explicitly in `CONSTRAINTS.md` with its reason.** Glued units were counted
once though they held two functions, so the old number undercounted real
function bodies. Nothing was recovered and nothing was lost; the denominator
was wrong. This is flagged rather than slipped through, and it is the first
movement of any ratchet in this project.

### The split units pass the real splice pipeline

Extent arithmetic is not the same as a working unit, so the new dumps were
run through `tools/lift.py`, which compiles each source with the pinned
toolchain and applies the real `c_units._relocate` trimming:

| unit | result |
|---|---|
| `exe_30576` | MATCH, 171 bytes, trimmed 1 |
| `exe_18274` | MATCH, 704 bytes, trimmed 2 |
| `exe_30534` | MATCH, 42 bytes, trimmed 4 |
| `exe_18240` | MATCH, 34 bytes, trimmed 4 |

4/4 MATCH. So the generated dump format is correct and the corpus change
does not endanger the rebuild. The trims are the documented `_relocate`
behaviour for `_asm` units and stay visible in the report rather than being
hidden.

### exe_18240: source recovered; the residue is module context, not source

`__stdcall` does not exist in this compiler (`C2143: missing '{' before
'modifier'`), but the instructions are reproduced exactly by a `__pascal`
reading with the parameters in the opposite order:

```c
long __pascal far helper(long x, long y);

void __pascal far f(long a, long far *p)
{
    *p = helper(a, *p);
}
```

This gets the parameter offsets (`p` at `bp+6`, `a` at `bp+0Ah`), the push
order (`a` high then low, then `*p` high then low), `retf 8`, and the
`mov [bx],ax; mov [bx+2],dx` store-back all correct. The earlier attempt
with `f(long far *p, long a)` had the arguments reversed and produced the
wrong offsets — the convention is pascal, the parameter order is `a` first.

Two differences remain, and both are consequences of compiling a single
unit outside its original module:

| retail | this compiler |
|---|---|
| `push ds; push bx; lds bx,[bp+6]` … `pop bx; pop ds` — pointer in DS:BX, saved across the call | `les bx,[bp+6]` … `les bx,[bp+6]` — ES:BX, reloaded after the call |
| `push cs; call rel16` — the helper is in this code segment | `call far ptr helper` (5-byte `9A` plus fixup) |

The second is the cause of the first: `push cs; call` only appears when the
callee is defined in the same module, and it was tested directly — putting
the helper in the translation unit makes CL emit it *before* `f`, giving 60
bytes and a first difference at `+3`, so a per-unit compile cannot produce
the same-module call form.

This is a new category of blocker and it matters beyond this unit: some
retail functions can only be reproduced once the original *module* grouping
is known, because the compiler's call encoding and register strategy both
depend on it. Those units belong to the CL+LINK lane, not to per-unit source
recovery, and no amount of per-unit spelling will reach them.

### A four-member pure-C family in the overlay: identified, not yet aligned

`ovl_103506`, `ovl_165711`, `ovl_187298` and `ovl_193562` are 35 bytes each,
identical in shape, and contain no call, no `int`, no `in`/`out` and no
segment-qualified access — the cleanest pure-C family the corpus has
produced. Each decodes as:

```
push bp ; mov bp,sp
cmp word [bp+6],10h ; jnz ZERO
cmp byte [G],0      ; jz OTHER        ; G differs per member
mov ax,OFFSET_A     ; jmp TAIL         ; A differs per member
nop
OTHER: mov ax,OFFSET_B
TAIL: mov dx,ds ; jmp FIN
nop
ZERO: xor ax,ax ; cwd
FIN: pop bp ; retf
```

so each returns a `char far *`: null unless the argument is `10h`, else one
of two string-literal addresses with DS as the segment — i.e.

```c
char far *far f(int a)
{
    if (a != 0x10)
        return 0;
    return g ? "..." : "...";
}
```

The four members differ only in the tested byte and the two literal
offsets, so this is four recoveries behind one idiom if it can be verified.

**It cannot yet be verified by the per-unit splice.** Compiling that source
gives 38 bytes in which MSC emits the twelve bytes of string literals
*before* the function, so the blob is compared against the retail code slice
from `+0` and differs immediately. The compiled function also appears
shorter than retail's 35 bytes, missing the frame and the first `cmp`, which
is not explained yet; that is recorded as an open question rather than
guessed at.

The practical consequence is the same as `exe_18240`: units whose source
contains string literals need the real CL+LINK path, where literals get
their own segment and their own addresses, rather than the per-unit splice
which compares one contiguous code blob. Both of these blockers are Lane B
work.

### OVL family: the +0 difference is a comparison artefact, not codegen

Dumping the OMF records for the family source explains the comparison
failure directly. The object contains **two LEDATA records in two
segments**:

| record | segment | offset | length | content |
|---|---|---|---|---|
| LEDATA | 1 | `0x5500` | 38 | the function's code |
| LEDATA | 2 | `0x4100` | 12 | `41 41 41 00 42 42 42 42 42 42 00`, the string literals |

So CL puts the literals in their own segment, while the tool's code buffer
is a concatenation that leads with them — which is why the comparison
differed at `+0` and why `cl_probe` printed the literals first. The source
is not misplaced; the comparison is reading the wrong segment. That is the
hypothesis this round was meant to test, and it holds.

**Two caveats, recorded rather than glossed.**

1. The record walk also emitted two `?9C` entries, and `0x9C` is not a
   valid OMF record type. That means the walk **drifted** and the record
   list may be incomplete, so the table above should be treated as
   indicative rather than exhaustive. A correct walk is needed before any
   tooling change is made on the strength of it.
2. The code record's 38 bytes begin `8b ec` with **no `push bp`**, and the
   function reads `[bp+6]` while freeing `bp` in its epilogue. Either the
   prologue is emitted in a record the drifting walk missed, or something
   in the compile path is already trimming it. Until that is resolved the
   byte lengths (38 vs retail's 35) should not be read as a codegen
   difference in the source.

Net: the family is still the best available target — four identical
pure-C units, one idiom, no calls and no segment access — but the next
step is to fix how the comparison selects the code segment, not to write
more source. That change would also bear on `exe_18240` and on any unit
whose translation unit emits more than one segment.

### Fixed: OMF segments were merged, so data clobbered code

The OVL family's `+0` difference was a real bug in the shared OMF parser,
now fixed in `tools/omf.py`.

**Diagnosis.** Two facts had to be separated first. The LEDATA record
layout is a **one-byte** segment index followed by a two-byte offset
(`payload[1:3]`), and my throwaway dump script used two bytes for the
segment index, which shifted everything by one and made it look as though
`push bp` was missing from the code. It never was — that caveat is
withdrawn. The real defect was next door: `ledata_and_fixups` collected
*every* `0xA0` record into one buffer keyed only by offset. A translation
unit with string literals emits a second segment whose offsets start at the
same place, so the twelve bytes of literals **overwrote the first twelve
bytes of the function** and the comparison was shown data instead of code.

**Fix.** The segment index is taken from the first LEDATA record (CL emits
the code segment first) and records from other segments are skipped. For
the single-segment objects that make up the rest of the corpus this is a
no-op.

**Verification, both directions:**

| check | result |
|---|---|
| `exe_2096`, the one recovered unit | still **MATCH**, 16 bytes, trimmed 2 |
| OVL family source vs `ovl-payload:0x19452` | first difference moved from **+0 to +7** |
| fast test suite | 9/9 OK |

The family is no longer blocked by tooling. Its remaining difference at `+7`
is a genuine codegen question: retail lays the function out as
`cmp / jnz ZERO` (falling through to the string path) where CL emits
`cmp / jz` and falls through to the zero path, for the same
`if (a != 0x10) return 0;`. That is the next thing to work, and it is a
normal source-level question rather than a measurement artefact.

### OVL family: branch direction fixed, one byte left

Putting the zero case last changes the layout to match retail's:

```c
char far *far f(int a)
{
    if (a == 0x10)
        return g ? "AAAA" : "BBBBBB";
    return 0;
}
```

The first difference moves from `+7` to `+8` — the `jnz` direction was the
whole of the previous gap, and that is now resolved. The compiled unit is
**34 bytes against retail's 35**, so one byte remains. Retail's body
contains two `EB xx 90` sequences (a forward `jmp` followed by a `nop`)
where the compiled version emits at most one, which is the likely source of
the missing byte; that is where the next probe should look rather than at
the branch structure, which now matches.

`exe_18240` was re-tested after the segment fix and is unchanged at `+3`:
its object has a single segment and one fixup, so segment selection was
never its problem. Its `push ds` versus `push [bp+0Ch]` difference stands as
previously characterised.

### One compiler limitation now explains five units

The OVL family's missing byte is not a source problem. Retail's layout is

```
cmp [bp+6],10h ; jnz ZERO
cmp byte [G],0 ; jz OTHER
mov ax,A ; jmp TAIL ; nop
OTHER: mov ax,B
TAIL: mov dx,ds ; jmp FIN ; nop
ZERO: xor ax,ax ; cwd
FIN: pop bp ; retf
```

— a **single shared epilogue** reached by a forward `jmp` over the zero
path, with `nop` padding after each jump. CL emits a duplicated epilogue
instead: one `pop bp; retf` per return path, and no padding. That accounts
for the 34-vs-35 byte difference exactly: CL spends two bytes on the second
epilogue where retail spends two on the nops.

Three source shapes were compiled and all three produced the **identical**
34-byte output — `if (a == 0x10) return g ? ... : ...; return 0;`, the same
with an explicit `else`, and the single-expression
`return a == 0x10 ? (g ? ... : ...) : 0;`. The conditional expression form
was the specific hypothesis that CL might share an exit; it does not.

This is the same limitation already recorded for `exe_98653`, where retail
is `cmp / jz / and / jmp +5 / or / pop bp / retf` and CL duplicates the
epilogue under three shapes and five optimisation settings. So **five units
— `exe_98653` and the four overlay members — are blocked by one compiler
behaviour: CL 8.00c does not emit a forward jump to a shared epilogue for
these if/else shapes**, and both were confirmed by compiling the
alternatives rather than assuming.

That reframes the family: it is not four near-misses to grind, it is one
open question about CL's exit merging, and any answer applies to all five
at once. The two forms differ in one thing — whether the false branch
returns a value or falls to a shared exit — so the next probe should vary
what makes CL merge exits, not the branch structure, which now matches.

### Exit merging: a controlled matrix, and a classification

A minimal experiment was run to test whether CL 8.00c can emit a forward
`jmp` to a shared epilogue at all, rather than continuing to vary sources
for individual units. Four shapes, one function each:

| shape | code | shared exit? |
|---|---|---|
| `if (a) return 0; return "ABCDEF";` | 22 B | no — two `pop bp; retf` |
| `if (a) { g = 1; return 0; } return "ABCDEF";` | 26 B | no |
| `do { if (a) break; return "ABCDEF"; } while (0); return 0;` | 22 B | no — layout changes, still two epilogues |
| `char far *r; if (a) r = 0; else r = "ABCDEF"; return r;` | 40 B | no — a stack local instead |

None produced the retail form. The third is the interesting one: the
`do { } while (0)` + `break` idiom *does* change the layout to put the
string path first and the zero path last, which is closer to retail, but it
still emits a second `pop bp; retf` rather than jumping to a shared one.

**Classification.** `exe_98653` and the four overlay members
(`ovl_103506`, `ovl_165711`, `ovl_187298`, `ovl_193562`) are recorded as
**COMPILER-LIMITED**, which per `docs/MATCHING.md` requires that controlled
experiments demonstrate the remaining limitation. Across those five units
that is now roughly ten source shapes and five optimisation settings, every
one of which duplicates the epilogue where retail shares it.

**The caveat is recorded with the classification, not buried.** Ten shapes
is a finite search, and `docs/MATCHING.md` is explicit that failure to find
a spelling is not proof none exists. What the matrix establishes is narrower
and still useful: the three obvious source-level levers — conditional
expression, `else`, and explicit `goto`/`break` exit — do not move CL's exit
merging, so further spelling variants for these units are not worth the
rounds. If the limitation is ever disproved, one experiment reverses it for
all five.

### Near match at one nop: exe_86814 (exe-code:0x1531E, 50 B)

This is a video-mode switch, and it is fully C-expressible — no `int`, no
`in`/`out`, no segment access, no call:

```c
extern unsigned g42e0, g42e2, g42e4, g42e6;

void far f(int a)
{
    if (a == (int)g42e0)
        return;
    if ((g42e2 | g42e4) == 0)
        return;
    g42e6 = a ? g42e4 : 0xA000;
    g42e0 = (a != 0);
}
```

It compiles to **exactly 50 bytes**, the same as retail, with an identical
instruction sequence: the same `mov ax,[g42e0] / cmp [bp+6],ax / jz`, the
same `mov ax,[g42e4] / or ax,[g42e2] / jz`, the same `?:` with
`0A000h` (the VGA segment), and the same `cmp word [bp+6],1 / sbb ax,ax /
inc ax` for the boolean store.

Two notes on getting there. The final store must be `(a != 0)` or the
equivalent `a ? 1 : 0` — writing `(a >= 1)` made CL emit a branchy
`jl / mov / jmp / xor` instead of the `sbb ax,ax; inc ax` idiom, which cost
six bytes. And every one of the three `jz` displacements is one less than
retail's for a single reason.

**The remaining difference is the placement of one `nop`.** Retail has it
inline, immediately after the `jmp` that skips the `0A000h` store:

```
mov ax,[g42e4] ; jmp +4 ; nop ; mov ax,0A000h ; mov [g42e6],ax
```

while CL puts the same `90` as trailing padding after the final `retf`.
Both are 50 bytes and the instruction sequence is otherwise identical; only
the padding site differs. That is an alignment decision, not a source
question, so it is recorded as a near match rather than a compiler
limitation — the expected fix, if any, is in how CL places branch-target
padding for this function, and switching flags to chase it would break the
pinned `/Os` contract that the rest of the corpus depends on.

### Near match: exe_53332 (exe-code:0xD054, 58 B) — the guard spelling is open

Retail decodes cleanly as a guarded dispatch on an odd-valued argument:

```
mov ax,[5CE2h] ; sub ax,0CDh ; jnz FIN      ; guard
mov ax,[bp+6]
dec ax ; jz CASE1
dec ax ; dec ax ; jz CASE3
dec ax ; dec ax ; jz CASE5
dec ax ; dec ax ; jz CASE7
jmp FIN ; nop                                ; default
CASE1: inc word [5CDEh] ; jmp FIN
CASE3: inc word [5CE0h] ; jmp FIN
CASE5: dec word [5CDEh] ; jmp FIN
CASE7: dec word [5CE0h]
FIN: mov sp,bp ; pop bp ; retf
```

so the four case actions are exactly `g5cde++`, `g5ce0++`, `g5cde--`, `g5ce0--`
for `a` = 1, 3, 5, 7 — a subtracted-by-two chain, which is CL's encoding for a
case set in arithmetic progression.

Two spellings were compiled and the case bodies and actions reproduce in
both; neither matches yet, and **the difference is entirely in the guard**:

| spelling | guard encoded as | size |
|---|---|---|
| `if (g5ce2 != 0xCD) return;` then `switch (a)` | `cmp word [5CE2h],0CDh` (7 bytes), chain placed after the bodies | 60 |
| `switch (g5ce2) { case 0xCD: switch (a) {…} }` | `mov ax,[5CE2h]` + `sub ax,0CDh` — retail's form — but the test lands at the *end* with `jz` back | 62 |

Retail is in between: it has the single-case-switch `mov ax / sub ax` guard
(so the source is switch-shaped, not `if`-shaped) placed at the **top**,
falling *through* into the inner dispatch with `jnz` forward. That is the
same exit/placement question already characterised elsewhere, and it is the
one thing left: the case set, the actions, the subtraction chain and the
epilogue all match.

### exe_99679 decoded; and two corrections to my own earlier claims

**The decode.** `exe-code:0x1855F`, 48 bytes:

```
mov al,[4F28h] ; and ax,1 ; cmp ax,[bp+6] ; jnz OTHER
mov bx,[4F28h] ; inc byte [bx+4F2Ah] ; jmp FIN
OTHER: cmp word [4F28h],0Fh ; jnc FIN
inc word [4F28h] ; mov bx,[4F28h] ; mov byte [bx+4F2Ah],1
FIN: mov sp,bp ; pop bp ; retf
```

The flag is read as a **byte** (`mov al,[g]`) while the same address is
updated as a **word** (`inc word [g]`, `cmp word [g],0Fh`), which points at a
cast in the source rather than a `char` global. The shape is

```c
if (a == ((char)g & 1))
    t[g]++;
else if (g < 0xF) {
    g++;
    t[g] = 1;
}
```

with `t` byte-indexed by `g` and the array base folded into the displacement.
The first reconstruction compiled to a **2-byte object with 10 fixups**, so
the function body was not emitted at all; the attempt is inconclusive rather
than a disproof, and this unit is left unclassified.

**Correction 1: my OMF record walker is unreliable.** It reported no LEDATA
records at all in a 301-byte object that certainly contains them, and in
earlier rounds it emitted `?9C` entries it should have named FIXUPP. The
tables I published from it — including the "two LEDATA records in two
segments" table — are therefore **not trustworthy as exhaustive listings**
and should not be built on. The *conclusion* drawn from them is separately
supported: the segment fix moved the OVL family's first difference from `+0`
to `+7` and left `exe_2096` matching, which is direct evidence that segments
were being merged. The conclusion stands; the tables do not.

**Correction 2: a heuristic I introduced needs stating.** `tools/omf.py` now
takes the code segment index from the **first** LEDATA record. That is true
for the two objects examined and is a no-op for the single-segment objects
that make up the corpus, but it is a heuristic, not a rule, and the `q1.c`
oddity above is a hint that some objects may order segments differently. If
a unit ever resolves to a small buffer of zeros with many fixups, this is
the first thing to check.

### Fixed: the code segment must come from PUBDEF, not record order

The `q1.c` anomaly is diagnosed and fixed, and it was a bug in the heuristic
I added last round.

**Diagnosis.** Walking both objects shows CL emits the LEDATA records in a
different order depending on the translation unit:

| object | LEDATA order |
|---|---|
| `h1.c` | seg 1 (39 B of code), then seg 2 (13 B of literals) |
| `q1.c` | **seg 3 (3 B of static data) first**, then seg 1 (59 B of code) |

Taking the code segment from the first LEDATA therefore returned three bytes
of data for `q1.c` — the "2-byte object with 10 fixups" signature.

**Fix.** The segment index now comes from the **PUBDEF** record, which names
the segment its symbol lives in. Verified:

| object | before | after |
|---|---|---|
| `q1.c` | 2 bytes of zeros | **58 bytes** starting `55 8B EC A0 00 00 25 01 00 3B 46 06` |
| `h1.c` | 38 bytes | 38 bytes, unchanged |
| `exe_2096` | MATCH | MATCH, 16 bytes, trimmed 2 |
| fast suite | 9/9 | 9/9 |

**Retraction: last round's "Correction 1" was itself wrong.** I said the OMF
record walker was unreliable and that the tables published from it should not
be trusted. The walker was correct; the sequence it produced for `h1.c`
reconciles to the object size exactly (`0xFC + 3 + 2 = 0x101 = 257`), and
the only error was my label table omitting `0x9C`, which is FIXUPP — the
`?9C` entries were correctly-parsed records I had failed to name. The tables
stand, including the two-LEDATA/two-segment one that motivated the segment
fix. The lesson is narrower than the one I wrote down: I should not have
declared my own tooling unreliable without first checking it against a
quantity I could verify, the object length, which settled it immediately.

**`exe_99679` with the parser fixed.** The reconstruction
`if (a == ((char)g & 1)) t[g]++; else if (g < 0xF) { g++; t[g] = 1; }` now
matches retail's **first 13 bytes exactly** — `push bp / mov bp,sp /
mov al,[4F28h] / and ax,1 / cmp ax,[bp+6] / jnz` — so the flag read as a byte
and the cast reading are confirmed right. It is 58 bytes against retail's 48,
so the divergence is in the two update blocks and needs another pass.

### Recovered: exe_99679, as unaided C with no trims

`exe-code:0x1855F`, 48 bytes, previously an `_emit` dump:

```c
extern unsigned g;
extern char __near t[];

void far exe_99679(int a)
{
    if (a == ((char)g & 1))
        t[g]++;
    else if (g < 0xF) {
        g++;
        t[g] = 1;
    }
}
```

`tools/lift.py`: **MATCH, 48 bytes, trimmed 0** — no `mov sp,bp` removal and
no prologue or epilogue trimming. This is the first unit recovered with zero
trims.

Two details were forced by the code rather than guessed:

- `g` is read as a **byte** (`mov al,[g]`) but updated as a **word**
  (`inc word [g]`, `cmp word [g],0Fh`), so the low bit comes through a cast
  rather than a `char` declaration.
- The table access is `[bx+4F2Ah]` — a **near** access with the base folded
  into the displacement. Declaring `t` as a plain array in the large model
  makes CL emit `mov es,[g]` plus `es:[bx]`, growing the unit from 48 to 58
  bytes. `__near` is what removes it.

Because the guard compared equal across readings, the whole difference was
in the two update blocks; the earlier 58-byte attempt was the far-array
form, not a control-flow error.

**Note on the corpus totals quoted in earlier handoffs.** The `_emit` dump
count is **2,382**, not 2,375: the figure I had been repeating predates the
eight glue splits, which added eight units. Current totals: 2,844 units,
unaided C 440, mnemonic `_asm` 22, `_emit` dump 2,382; exe dump byte
coverage 97.90% -> **97.88%**, ovl unchanged at 96.69%.

### exe_117397: source recovered, same exit-layout limitation

`exe-code:0x1CA95`, 54 bytes. A null-checked far-pointer table lookup:

```c
extern unsigned __near g_idx;
extern char far * __near g_table[];

int far exe_117397(void)
{
    char far *p;

    p = g_table[g_idx];
    if (p == 0)
        return 0;
    if (*(unsigned far *)(p + 0x2C) != 1)
        return 0;
    return 1;
}
```

It compiles to **exactly 54 bytes**, the same as retail, with the same
`mov bx,[g_idx] / add bx,bx / add bx,bx` scaling for 4-byte far-pointer
elements, the same `mov ax,[bx+6960h] / mov dx,[bx+6962h]` pair, the same
stack local pair, the same `or dx,ax` null test, and the same
`les bx,[bp-4] / cmp word [es:bx+2Ch],1`. `__near` on both globals is again
what keeps the access DS-relative and the size right.

**The one difference is the exit layout, and it is the same limitation
already recorded twice.** Retail places the zero return at the end and jumps
*forward* to it:

```
or dx,ax ; jz FIN          ; null -> the shared zero return
les bx,[bp-4] ; cmp word [es:bx+2Ch],1 ; jnz FIN
mov ax,1 ; jmp FIN ; nop
FIN: xor ax,ax ...
```

CL emits the zero return inline and jumps *back* to it. Same total size,
same instructions, different placement — and retail again carries the
`EB xx 90` jump-then-nop padding that CL does not.

**This matters for the classification.** The exit-layout limitation now
covers `exe_98653`, the four overlay members, and `exe_117397` — six units,
all of which have recovered sources, matching sizes, and a single shared
exit that CL refuses to generate. Each was confirmed by compiling the
alternative rather than asserted, and each adds to the same conclusion:
these are not six independent near-misses but one compiler behaviour. If it
is ever cracked, six units fall at once.

### Exit layout: the two properties never combine

`exe_117397` was used as the test bed, since it already matches retail's
size and every instruction except the exit placement. Three forms:

| source | size | stack local `p` | shared exit |
|---|---|---|---|
| two `if (...) return 0;` statements, plain local | **54 (retail's size)** | yes | no — inline, jumps back |
| `return p != 0 && ... == 1;`, plain local | 44 | **no** — kept in registers | **yes** |
| the same with `char far * volatile p` | 58 | yes | no |

The middle row is the informative one. The short-circuit *does* produce the
shared forward-jumping exit retail has — but only by keeping `p` in
registers, which drops the `sub sp,4` and the store/reload pair, so the unit
comes out ten bytes short. Forcing the local back onto the stack with
`volatile` restores the spill and loses the shared exit, and adds four bytes
of its own.

So **CL 8.00c shares an exit only for a value it can keep in registers, and
spills the local only when the exits are duplicated**; retail does both at
once. That is a sharper statement of the limitation than "CL does not emit a
shared epilogue", and it explains why every form tested across the now-seven
affected units has failed on one side or the other rather than purely on
placement.

**The classification stands and is not weakened by this.** Seven units —
`exe_98653`, the four overlay members, `exe_117397`, and the earlier
`exe_53332` guard placement — have recovered sources and a single shared
exit CL will not produce alongside the local allocation the code requires.
Each was confirmed by compiling the alternative. The caveat recorded
earlier still applies: this is a finite search and not a proof that no
spelling exists.

### exe_112795: first attempt, one structural gap

`exe-code:0x1B89B`, 58 bytes, the same global-array idiom as `exe_117397`
(index global, scaled by 2 for an int count array and by 4 for a far-pointer
table) plus an `imul` by 20 onto a far base and an `or byte [es:bx+1],80h`.

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

struct S { char a[20]; };

void far f(int i)
{
    if (g_cnt[g_idx] <= i)
        return;
    ((struct S far *)g_tbl[g_idx])[i].a[1] |= 0x80;
}
```

This gives **50 bytes against retail's 58**, and the divergence is at `+3`:
retail has `sub sp,4`, a four-byte stack local, where CL keeps the pointer
in `si` instead. The scaling, the `imul` by 20, the far base and the
`or byte [es:bx+1],80h` all appear; the open question is what the source
does with a local that makes CL allocate it on the stack without using it in
the visible path. Not yet resolved, and recorded as a first attempt rather
than a near match.

### Recovered: exe_112795, also with zero trims

`exe-code:0x1B89B`, 58 bytes, previously an `_emit` dump:

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112795(int i)
{
    char far *p;

    if (g_cnt[g_idx] <= i)
        return;
    p = g_tbl[g_idx] + i * 20;
    p[1] |= 0x80;
}
```

`tools/lift.py`: **MATCH, 58 bytes, trimmed 0**.

Three things had to be right and each was a separate experiment, which is
why the first two attempts failed at 50 and 66 bytes:

1. All three globals `__near`, so the accesses stay DS-relative with the
   base folded into the displacement — the lever proved by `exe_99679`.
2. `p` as a **named local**. CL allocates the four bytes (`sub sp,4`) but
   keeps the pointer in `cx:dx`, so the slot is never referenced in the
   visible code. Without the local the unit is 50 bytes and CL uses `si`.
3. Folding the record offset into the pointer — `p = t + i * 20` rather
   than indexing at the point of use — which makes CL add it with
   `add cx,ax` instead of carrying it separately in `si`. This alone was
   the 66-to-58 difference.

That is the second zero-trim recovery, and the second unit where the
`__near` lever transferred directly.

### Recovered: exe_112711, third zero-trim recovery

`exe-code:0x1B847`, 84 bytes — the loop member of the same global-table
family as `exe_112795`:

```c
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112711(int v)
{
    char far *p;
    int i, off;

    i = 0;
    if (g_cnt[g_idx] > 0) {
        off = 0;
        do {
            p = g_tbl[g_idx] + off;
            if (*(int *)(p + 10) == v)
                p[1] |= 0x80;
            off += 20;
            i++;
        } while (g_cnt[g_idx] > i);
    }
}
```

`tools/lift.py`: **MATCH, 84 bytes, trimmed 0**.

The one new lever here is **declaration order**. The first attempt compiled
to exactly 84 bytes and differed only in the stack-slot offsets: retail has
`i` at `bp-6` and `off` at `bp-8`, which only happens if the four-byte
`p` is declared **first** and occupies the top of the frame — even though
CL never references the slot, keeping the pointer in `es:di`. Declaring
`p` after the two ints moved `i` to `bp-2` and put the unit two bytes off.
That is the third unit in a row where a local CL keeps in registers is
still allocated stack space, and the first where the *order* of declaration
is observable.

### Near match: exe_115231 (exe-code:0x1C21F, 78 B)

A guarded table entry with a far-pointer call, and the first unit where a
**near pointer local** was required:

```c
struct T { char v[16]; };

extern unsigned __near g_idx;
extern int __near g_a[];
extern struct T __near g_b[];
void far helper(int i, char far *p);

void far exe_115231(void)
{
    int __near *p;

    p = &g_a[g_idx];
    if (*p == 0)
        return;
    *p = 0;
    helper(g_idx, (char far *)&g_b[g_idx]);
    g_b[g_idx].v[0] = 0;
    g_a[g_idx] = 1;
}
```

Retail: index `g_idx` into a word table at `68D0h`, bail if the entry is
zero, clear it, call `helper(g_idx, (char far*)&g_b[g_idx])` where `g_b`
holds 16-byte records at `68E0h`, then clear the first byte of the record
and set the word entry to 1. Every one of those steps reproduces.

Two things had to be right and both were found by compiling:

- `p` as `int __near *`. A plain `int *` is a **far** pointer in the large
  model, so the local takes four bytes and the unit comes out `sub sp,4`
  instead of retail's `sub sp,2`; the store is `mov [bp-2],ds` rather than
  `mov [bp-2],bx`.
- All three globals `__near`, the lever from earlier rounds.

**The gap is located, by diffing the two listings from `+0`.** Retail has
`mov [bp-2],bx` (89 5E FE, three bytes) at `+16`, storing the local
pointer into its stack slot; the compiled version does not, because CL
eliminates the store — it keeps the pointer in `bx` and never reads the
slot back. Everything around it, including `mov cl,4` before the clear and
again after the far call, is present in both.

The arithmetic nearly balances: retail spends three bytes on the store and
the compiled unit is two bytes shorter overall, so CL also spends one byte
more somewhere else. That last byte is not yet identified, and no cause is
asserted for it — an earlier explanation I wrote for this gap (that CL
hoisted a shift) was wrong and is withdrawn.

This is the same shape of difference as `exe_112795` and `exe_117397`,
where the local's stack slot was allocated but unreferenced: retail keeps
work involving a local that CL removes. In those two units the slot alone
was enough to match; here retail also writes to it, so the source needs
something that forces a dead store — a second use of `p`, or a
declaration form that stops CL treating it as a register candidate.

### exe_115231: two more forms tried for the dead store, neither forces it

After locating the gap as retail's `mov [bp-2],bx` at `+16`, two source
forms were compiled to try to make CL keep that store:

| form | result |
|---|---|
| `int __near *p = &g_a[g_idx];` (initialised at declaration) | 76 bytes, store still eliminated |
| `p[0]` used for both the test and the clear | 76 bytes, store still eliminated |

Both still differ at retail's `+16`, so the store is not something a
declaration or a re-use in these positions brings back. Three forms have now
been tried for it. The one lever not yet tried is qualifying the pointer
itself `volatile`, which would force the store but also force reloads of
`p` that retail does not have, so it is expected to overshoot rather than
match — recorded as the next thing to test, with that expectation stated up
front rather than discovered afterwards.

**Where this round landed.** One recovery (`exe_112711`, zero trims), one
near match located to a single missing instruction (`exe_115231`), and one
retraction of my own wrong explanation. Four units were recovered across the
session: `exe_2096`, `exe_99679`, `exe_112795`, `exe_112711`.

### exe_115231: the volatile test, with the prediction on record

`int __near * volatile p` compiles to **82 bytes** and diverges at `+6`, i.e.
it overshoots. The prediction recorded before running it — that volatile
would force the dead store but also force reloads retail does not have — was
correct, so the experiment is informative rather than just negative.

Four forms have now been tried for that one missing store:

| form | size | store present |
|---|---|---|
| plain pointer local | 76 | no |
| initialised at declaration | 76 | no |
| `p[0]` for the test and the clear | 76 | no |
| `volatile` pointer | 82 | no, and reloads instead |

So `exe_115231` is a near match whose single difference is a dead store
(`mov [bp-2],bx`) that CL eliminates and retail keeps. Everything else in
the unit — the near table index, the 16-byte record array, the cdecl far
call with a DS-relative far pointer, the two `mov cl,4` around the call —
is reproduced. That is a precise characterisation, and it belongs to the
same family as `exe_112795` and `exe_117397`: retail keeps work involving
a local that CL removes.

### Near match: exe_91501 (exe-code:0x1656D, 84 B)

A signed-direction ring walk over a table of negative-marked entries:

```c
extern int __near g_i;
extern int __near g_arr[];
void far helper(int n);

void far exe_91501(int dir)
{
    if (g_i < 0)
        return;
    helper(0);
    do {
        if (dir > 0) {
            if (++g_i == 8)
                g_i = 0;
        } else {
            if (--g_i < 0)
                g_i = 7;
        }
    } while (g_arr[g_i] < 0);
    helper(1);
}
```

It compiles to **exactly 84 bytes**, retail's size, and reproduces the guard
(`cmp word [g_i],0 ; jl`), both `xor ax,ax`/`mov ax,1` argument setups with
`__near` globals, the `jng` split between the increment and decrement
paths, the `++g_i == 8 → 0` and `--g_i < 0 → 7` wraparounds, the
`cmp word [bx+6354h],0 ; jl` loop back edge, and the trailing `helper(1)`.

**The one difference is how the first call's argument is cleaned up.** After
`helper(0)` CL emits `pop bx` (one byte); retail emits `mov sp,bp` (two
bytes). Retail uses the longer form at that site and the shorter one — or
its equivalent — at the end, and the totals still come to 84 both ways.

That is a source-independent choice unless a construct forces the frame
restore; the same `mov sp,bp` appears in several earlier units
(`exe_5398`, `exe_24910`) right after argument pushes. Recorded as a near
match with the difference localised to that one instruction, not as a
compiler limitation, because only one spelling has been tried here.

### exe_91501: two more forms for the cleanup, neither matches

Following the near match at 84/84 bytes whose only difference is the first
call's argument cleanup:

| form | size | cleanup after `helper(0)` |
|---|---|---|
| plain `helper(0);` | 84 | `pop bx` |
| the same wrapped in a bare block | 84 | `pop bx` (identical output) |
| argument passed through a local `r = 0; helper(r);` | 86 | no better, and a frame local appears |

So the block does not change anything and the local overshoots by two. Three
forms tried at that site. The remaining untried lever is the calling
convention: declaring `helper` `__pascal` would move the cleanup into the
callee and change the push order, so it is expected to fail for a different
reason — worth one probe to close the question, but not before the corpus
work, since `mov sp,bp` after argument pushes appears in `exe_5398` and
`exe_24910` too and one answer would cover all three.

### exe_91501 cleanup closed; exe_94984 decoded

**The calling-convention probe was run and the prediction held.** Declaring
`helper` `__pascal` compiles to **82 bytes** and diverges at `+9`, i.e. it
fails for a different reason rather than producing retail's `mov sp,bp`.
That was the expectation recorded before running it. Four forms have now
been tried at that site (plain, block, local argument, `__pascal`), so the
difference is localised but unexplained: retail emits the two-byte frame
restore where CL emits a one-byte `pop`, at a site otherwise identical.

**`exe_94984` (exe-code:0x17308, 85 B) decoded** — a "pop one record"
routine, and more complex than the units that have matched so far:

```
sub sp,4 ; push di ; push si
ax = [4DAEh] * 24 - [bp+6]          ; 3 add-based multiplies, no imul
push ax ; push dx:ax+0Ch ; push dx:ax ; push [bp+6] ; call far
add sp,0Ah                          ; five words of arguments
bx = [4DAEh] * 24 ; les si,[63DCh]  ; a far pointer table
xor ax,ax ; cx = 6 ; lea di,[bx+si] ; rep stosw   ; 24 bytes cleared
dec word [4DAEh]
```

The multiply is built from `add ax,ax / add ax,cx / add ax,ax / add ax,ax`
(×24), the table is reached through a far pointer load into `es:si`, and
the clear is `rep stosw` with `cx = 6`. Four of those elements —
`les si,[table]`, `rep stosw`, the `lea di,[bx+si]` addressing and a
five-word call — make this a poor next target; it is recorded as decoded so
the next attempt starts from the structure rather than the bytes, and the
simpler remaining global-index units are the better continuation.

### The small global-index vein is worked out

The scan for units with a `mov bx,[mem]` global index has now yielded
everything it can cheaply. Of the 28 blocker-free candidates it found:

- 4 are recovered (`exe_99679`, `exe_112795`, `exe_112711` as zero-trim
  matches; `exe_117397` size-exact on a dead store),
- 2 are decoded with their gap localised (`exe_115231`, `exe_91501`),
- 1 is decoded and judged a poor target (`exe_94984`),
- **25 remain, and all of them are 131 bytes or larger** — the smallest is
  `exe_123400` at 131, then 141, 141, 142.

That matters for planning rather than for the record: the class that
produced two zero-trim matches from four attempts was the *small* end of it,
and that end is now empty. The remaining members are 3-4x the size and
several carry interrupt-style prologues (`push ax/bx/cx/dx/di/si/ds; pushf;
mov ds,SYM`), `les`-based far table walks and `imul`-scaled indices, none of
which any matched unit has needed yet.

One of them, `exe_111158` (142 B), does reuse the exact structures just
recovered — the far-pointer table at `67C2h` with 4-byte elements and an
`imul` by 20 — so the family is not exhausted so much as supersized. It is
the natural next target if a larger unit is attempted, but it needs a
26-byte frame and several locals, so it is a different kind of work from
the four that matched.

**What this means for the next round.** Continuing to pick small units will
now mean picking small units *outside* this class. The honest options are:
work a larger function end to end, or shift effort to the CL+LINK lane,
where the 94-116 library-classified units would be satisfied by linking
rather than by writing source at all.

### exe_790 in progress, and a new lever: _inp/_outp intrinsics

`exe-code:0x316`, 35 bytes, fresh and previously unexamined. A device poll
loop:

```
mov dx,[3FF8h] ; mov cx,0FFFFh
L:  in al,dx ; test al,40h ; jz READY ; loop L
    sub ax,ax ; jmp END          ; counter expired -> return 0
READY: mov dx,[3FF6h] ; mov al,[bp+6] ; out dx,al ; mov ax,1
END: pop bp ; retf
```

So it polls `3FF8h` until bit 6 is clear, then writes the argument to
`3FF6h` and returns 1; if the counter runs out first it returns 0. That is
a keyboard-controller handshake shape.

**The lever.** A first attempt with `inp`/`outp` from `conio.h` compiled to
62 bytes because in the large model they lower to **far calls**. Adding

```c
#include <conio.h>
#pragma intrinsic(_inp, _outp)
```

with `_inp`/`_outp` brings it to 52 bytes and emits `in al,dx` /
`out dx,al` inline, which is retail's form. This is the same mechanism that
made `_disable`/`_enable` work earlier, and it is the second header-supplied
intrinsic found this way: **port I/O needs `#pragma intrinsic(_inp, _outp)`
or it becomes a call.**

**Where it stands:** 52 bytes against retail's 35, first difference at
`+3`, i.e. in the loop setup rather than the I/O — the `mov cx,0FFFFh` and
loop structure still differ. Not resolved, recorded as in progress with the
lever established so the next attempt starts from 52 bytes and a known
lowering rather than from 62 and a call.

```c
int far exe_790(int v)
{
    unsigned i;

    for (i = 0xFFFF; i != 0; i--)
        if (!(_inp(g_poll) & 0x40))
            goto ready;
    return 0;
ready:
    _outp(g_data, v);
    return 1;
}
```

### exe_790: counter register is the whole remaining difference

Four forms tried, each narrowing the gap, and the residue is now a single
question — which register CL puts the 0xFFFF counter in:

| form | size | counter lives in | back edge |
|---|---|---|---|
| `for (i = 0xFFFF; i != 0; i--)` | 52 | `[bp-2]`, with `sub sp,2` | `dec/jnz` |
| `do { } while (--i)`, plain local | 44 | `[bp-2]` | `dec/jnz` |
| the same with `register unsigned i` | 40 | **`si`** (with `push si`) | `dec si / jnz` |
| retail | **35** | **`cx`**, no frame, no saved register | **`loop`** |

So `do/while(--i)` is the right loop shape — it got from 52 to 44 bytes and
matches retail's back edge semantics — and `register` moves the counter out
of memory, but CL picks `si` where retail has `cx`. Retail also has no
prologue save at all, so the counter is in a register CL never spills.

**What this narrows to.** Retail's `mov cx,0FFFFh` with a bare `loop` back
edge, no frame and no saved register, is CL's output when the counter is its
last-allocated register. Since `register unsigned i` alone yields `si`, the
source likely has a *second* register-resident value competing for the same
file — the port is already held across the loop in `dx`, so the counter
taking `cx` would follow if one more value were also register-allocated.
That is the hypothesis for the next attempt; it is stated before the
experiment, not after, and the two experiments that failed here (`for` and
plain-local `do/while`) each cost only one compile.

**The lever that did hold:** `#pragma intrinsic(_inp, _outp)` with
`_inp`/`_outp`. Without it these are far calls and the unit is 62 bytes;
with it the `in`/`out` are inline as retail has them.

### exe_790: the two-register hypothesis is disproved

The hypothesis recorded before this experiment — that a second
register-resident value would push the counter into `cx` — was tested and
**failed**. Three more forms, all measured:

| form | size |
|---|---|
| two `register` locals (counter + cached port), `do/while` | 44 |
| `register` counter with a `for` loop | 46 |
| `while (--i)` with a plain local | 44 |
| retail | **35** |

Seven forms have now been tried on this unit and none lands the counter in
`cx` with a bare `loop`. Every failure was cheap (one compile each) and
each is recorded with its size, so this is a bounded, honestly-reported
gap rather than an open-ended hunt.

**What is still unexplained:** retail's `mov cx,0FFFFh` + `loop`, with no
prologue save and no frame. CL puts a single register counter in `si`, a
plain local on the stack, and neither choice depends on a second variable.
The `loop` instruction is the crux — it is a one-byte back edge that CL
only reaches through a source shape not yet found, and it is possible the
original was hand-written assembly rather than C. That possibility is not
asserted; it is noted as the reason the remaining gap may be a provenance
question rather than a spelling question.

**What did carry over from this unit:** `#pragma intrinsic(_inp, _outp)`
with `_inp`/`_outp`, which takes any port-I/O unit from far calls to
inline `in`/`out`. That lever is unaffected by the counter question.

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
