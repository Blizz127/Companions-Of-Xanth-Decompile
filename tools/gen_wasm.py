"""Re-emit a dump unit as a Watcom/MASM listing, verified with the vendored wasm.

The pinned MSVC 1.52 assembler cannot spell the remaining dump units: its
inline-asm path wraps any block that mentions SI/DI in its own save/restore
pair and it shrinks `sub sp,N` to the imm8 form and small displacements to
disp8, while the retail bytes carry the imm16 and disp16 forms.

The Open Watcom assembler already vendored at `tools/toolchain/watcom` has
the profile the retail bytes need, measured directly:

* `mov bp,sp` / `mov sp,bp` assemble to `8B EC` / `8B E5`;
* `push si` / `push di` are literal — no compiler wrapper;
* `sub sp, offset sym` assembles to `81 EC imm16` and `mov ax, es:[bx+sym]`
  to `26 8B 87 disp16`, i.e. the two forms MASM 8.00c cannot be made to emit;
* absolute operands (`mov ax, ds:[84Ch]`, `mov ds:[53FAh], ax`,
  `cmp word ptr ds:[53FAh],0`, `inc word ptr ds:[53FAh]`,
  `call dword ptr ds:[53F8h]`) assemble to the retail bytes exactly, with no
  redundant segment prefix;
* `-1`/`-2`/`-3` raise the CPU level, which is what the 186/286/386 opcodes
  (`insw`, `enter`, `push imm`) need.

Verification is byte-exact against the unit's retail slice, with the same
`_relocate`-style fixup substitution the splice uses. This tool is the path to
the remaining units; it is not yet wired into `c_units` (that needs the
`.asm`-unit splice support described in docs/STATUS.md).
"""
import os, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, 'tools')
import units
from listing import ndisasm
from omf import ledata_and_fixups
ROOT = Path('.')
WATCOM = (ROOT / 'tools/toolchain/watcom').resolve()
ENV = {**os.environ, 'WATCOM': str(WATCOM), 'INCLUDE': str(WATCOM / 'h'), 'WINEDEBUG': '-all'}
_HEAD = "_TEXT SEGMENT BYTE PUBLIC 'CODE'\n    ASSUME CS:_TEXT, DS:_TEXT\n    PUBLIC mnem_unit\n"
_TAIL = "_TEXT ENDS\n    END\n"

def _hexify(text):
    def repl(m):
        v = m.group(1).upper()
        if v[0] in 'ABCDEF':
            v = '0' + v
        return v + 'h'
    return re.sub(r'0x([0-9a-fA-F]+)', repl, text)

def assemble(lines, extrns, cpu='-1'):
    def decl(n):
        return f"    EXTRN {n}:" + ("FAR" if n.startswith(('mf', 'mj')) else "NEAR") + "\n"
    src = (_HEAD + ''.join(decl(n) for n in extrns) + "mnem_unit:\n"
           + "\n".join(("" if l.endswith(':') else "    ") + l for l in lines) + "\n" + _TAIL)
    with tempfile.TemporaryDirectory() as tmp:
        work = Path(tmp)
        (work / 'u.asm').write_text(src)
        p = subprocess.run(['wine', str(WATCOM / 'binnt/wasm.exe'), '-ml', cpu, '-fo=u.obj', 'u.asm'],
                           cwd=work, capture_output=True, text=True, env=ENV)
        obj = work / 'u.obj'
        if not obj.is_file():
            errs = [l for l in (p.stdout + p.stderr).splitlines() if 'rror' in l]
            return None, src, ' | '.join(errs[:2]) or 'no object'
        return ledata_and_fixups(obj.read_bytes()), src, ''

_W16 = re.compile(r'\b(ax|bx|cx|dx|si|di|bp|sp)\b')
_W8 = re.compile(r'\b(al|ah|bl|bh|cl|ch|dl|dh)\b')

def _size_for(m):
    if re.search(r'\b(word|byte|dword)\b', m):
        return None
    if _W8.search(m):
        return 'byte'
    if _W16.search(m):
        return 'word'
    return None

def _plain(m):
    t = re.sub(r'\bint\s+byte\s+0x([0-9a-f]+)', r'int \1h', m)
    t = re.sub(r'\[(cs|es|ss|ds):', r'\1:[', t)
    t = re.sub(r'\b(word|byte|dword)\s+(?:near\s+)?((?:cs|es|ss|ds):)?\[', r'\1 ptr \2[', t)
    t = re.sub(r'\b(mov)\s+(es|ds|ss|cs)\s*,\s*(?:word|byte|dword)\s+ptr\s+', r'\1 \2, ', t)
    t = re.sub(r'\b(les|lds)\s+(\w+)\s*,\s*(word|byte|dword)\s+ptr\s+', r'\1 \2, dword ptr ', t)
    t = re.sub(r'\bcall\s+word\s+far\s+', 'call far ', t)
    t = re.sub(r'\b(retf?)\s+word\s+', r'\1 ', t)
    # absolute (no base) memory operands: an explicit ds: keeps MASM happy and
    # Watcom emits the direct form without a redundant prefix
    t = re.sub(r'(?<![\w\]:])\[(0x[0-9a-f]+)\]', r'ds:[\1]', t)
    size = _size_for(m)
    if size and '[' in t and ' ptr ' not in t and 'les ' not in t and 'lds ' not in t:
        t = re.sub(r'((?:cs|es|ss|ds):)?\[', lambda mo: f"{size} ptr {mo.group(1) or ''}[", t, count=1)
    return _hexify(t)

def listing_for(unit, extend_disp, extend_imm):
    import gen_mnem
    import gen_nasm
    img = units.image_bytes()[unit['image']]
    if unit['extent']:
        blob = img[unit['offset']:unit['offset'] + unit['extent']]
    else:
        # a unit whose extent only the real splice can resolve: take the retail
        # slice of the matched length, which includes the compiler frame
        blob = gen_nasm.bytes_for(unit, ROOT)
    if not blob:
        return None, None, 'no bytes'
    insns = ndisasm(blob)
    extrns, lines = [], []
    for idx, ins in enumerate(insns):
        if ins['mnemonic'].startswith('db '):
            return None, None, f"undecodable {ins['mnemonic']}"
        # calls and jumps to an absolute target: an external label gives the
        # right opcode plus a fixup, which is what the splice then overwrites
        # with the retail bytes.
        first = ins['raw'][:1]
        if first == b'\x9a':
            name = f"mf{idx}"; extrns.append(name)
            lines.append(f"call {name}"); continue
        if first == b'\xea':
            name = f"mj{idx}"; extrns.append(name)
            lines.append(f"jmp {name}"); continue
        if first == b'\xe8':
            name = f"mn{idx}"; extrns.append(name)
            lines.append(f"call {name}"); continue
        m = re.match(r'^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$', ins['mnemonic'])
        if m:
            name_, t = m.group(1), int(m.group(2), 16)
            s = 'f' if t > ins['addr'] else 'b'
            if name_ == 'jmp':
                lines.append(f"jmp short lbl{t:02X}{s}" if ins['raw'][:1] == b'\xeb'
                             else f"jmp near ptr lbl{t:02X}{s}")
            elif name_ == 'jcxz' or name_.startswith('loop'):
                lines.append(f"{name_} lbl{t:02X}{s}")
            else:
                lines.append(f"{name_} short lbl{t:02X}{s}")
            continue
        text = _plain(ins['mnemonic'])
        if idx in extend_imm:
            name = f"mi{idx}"; extrns.append(name)
            text = re.sub(r'([^,]+),\s*(?:0x[0-9a-f]+|[0-9A-F]+h)\s*$', rf'\1, offset {name}', text)
        if idx in extend_disp:
            name = f"md{idx}"; extrns.append(name)
            text = re.sub(r'[+\-](?:0x[0-9a-f]+|[0-9A-F]+h)', '+' + name, text, count=1)
        lines.append(text)
    targets = {}
    for ins in insns:
        # calls and jumps to an absolute target: an external label gives the
        # right opcode plus a fixup, which is what the splice then overwrites
        # with the retail bytes.
        first = ins['raw'][:1]
        if first == b'\x9a':
            name = f"mf{idx}"; extrns.append(name)
            lines.append(f"call {name}"); continue
        if first == b'\xea':
            name = f"mj{idx}"; extrns.append(name)
            lines.append(f"jmp {name}"); continue
        if first == b'\xe8':
            name = f"mn{idx}"; extrns.append(name)
            lines.append(f"call {name}"); continue
        m = re.match(r'^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$', ins['mnemonic'])
        if m:
            t = int(m.group(2), 16)
            targets.setdefault(t, set()).add('f' if t > ins['addr'] else 'b')
    out = []
    for ins, line in zip(insns, lines):
        for s in sorted(targets.get(ins['addr'], ())):
            out.append(f"lbl{ins['addr']:02X}{s}:")
        out.append(line)
    for t, ss in sorted(targets.items()):
        if t >= len(blob):
            for s in sorted(ss):
                out.append(f"lbl{t:02X}{s}:")
    return out, extrns, ''

def try_unit(unit, cpu='-1'):
    ed, ei = set(), set()
    for _ in range(60):
        lines, extrns, err = listing_for(unit, ed, ei)
        if err:
            return 'FAIL', err
        res, src, err = assemble(lines, extrns, cpu)
        if res is None:
            return 'ASMFAIL', err
        code, fix = res
        img = units.image_bytes()[unit['image']]; off = unit['offset']
        rel = bytearray(code)
        for o, s in fix:
            rel[o:o+s] = img[off+o:off+o+s]
        want = img[off:off+len(code)]
        if bytes(rel) == want:
            return 'MATCH', src
        a, b = ndisasm(bytes(rel)), ndisasm(want)
        done = False
        equal_len_imm = None
        for idx, (ia, ib) in enumerate(zip(a, b)):
            if idx in ed or idx in ei:
                if ia['raw'] != ib['raw'] and len(ia['raw']) == len(ib['raw']):
                    return 'STUCK', f"extended but differs: {ia['mnemonic']} vs {ib['mnemonic']}"
                if len(ia['raw']) != len(ib['raw']):
                    return 'STUCK', f"extended, wrong length: {ia['mnemonic']} vs {ib['mnemonic']}"
                continue
            if len(ia['raw']) != len(ib['raw']):
                if len(ib['raw']) > len(ia['raw']):
                    (ed if '[' in ia['mnemonic'] else ei).add(idx)
                    done = True
                else:
                    return 'STUCK', f"retail shorter: {ia['mnemonic']} vs {ib['mnemonic']}"
                break
            if ia['raw'] != ib['raw'] and re.search(r',\s*(?:0x[0-9a-f]+|\d[0-9a-f]*h)\s*$', ia['mnemonic']):
                # same length, different bytes, with an immediate operand: the
                # AX-specific imm16 form (05/0D/... ) versus MASM's byte form.
                if equal_len_imm is None:
                    equal_len_imm = idx
        if not done:
            if equal_len_imm is not None:
                ei.add(equal_len_imm)
                done = True
            else:
                return 'STUCK', 'same lengths, bytes differ'
        if not done:
            return 'STUCK', 'same lengths, bytes differ'
    return 'LOOP', ''

if __name__ == '__main__':
    import argparse
    import json
    from retail_common import write_json_atomic

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('units', nargs='+')
    parser.add_argument('--write', action='store_true',
                        help='write src/<stem>.asm and repoint c-units.json at it')
    args = parser.parse_args()

    index = units.index()
    good = 0
    for name in args.units:
        matches = [r for r in index if name in (r['source'], Path(r['source']).stem)]
        if not matches:
            print(f"{name:<16} NO-SUCH-UNIT")
            continue
        unit = matches[0]
        st, info = try_unit(unit)
        if st != 'MATCH':
            print(f"{name:<16} {st} {info[:80]}")
            continue
        good += 1
        if not args.write:
            print(f"{name:<16} MATCH")
            continue
        source = ROOT / unit['source']
        listing = source.with_suffix('.asm')
        listing.write_text(info, encoding='utf-8')
        path = ROOT / 'config/c-units.json'
        data = json.loads(path.read_text())
        # A source can back more than one registered offset; repoint them all.
        repointed = 0
        for entry in data['units']:
            if entry['source'] == unit['source'] and entry['image'] == unit['image']:
                entry['source'] = listing.relative_to(ROOT).as_posix()
                repointed += 1
        write_json_atomic(path, data)
        if source.suffix == '.c' and source.is_file():
            source.unlink()
        print(f"{name:<16} MATCH -> {listing.relative_to(ROOT).as_posix()} ({repointed} entries)")
    print(f"{good}/{len(args.units)} MATCH")
