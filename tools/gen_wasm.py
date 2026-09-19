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
`_relocate`-style fixup substitution the splice uses.
"""
import os, re, subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, 'tools')
import units
from listing import ndisasm
from omf import ledata_and_fixups, _index
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
    t = re.sub(r'\bint3\b', 'int 3', t)
    t = re.sub(r'\bsalc\b', 'db 0D6h', t)
    t = re.sub(r'\b(in)\s+([a-z]+)\s*,\s*(?:byte|word)\s+(0x[0-9a-f]+|[0-9a-fA-F]+h?)', r'\1 \2, \3', t)
    t = re.sub(r'\b(out)\s+(?:byte|word)\s+(0x[0-9a-f]+|[0-9a-fA-F]+h?)\s*,\s*([a-z]+)', r'\1 \2, \3', t)
    t = re.sub(r'\bpush\s+(?:word|byte)\s+(0x[0-9a-f]+|[0-9a-fA-F]+h?)', r'push \1', t)
    t = re.sub(r'\b(jmp|call)\s+(?:word|dword)?\s*far\s+', r'\1 dword ptr ', t)
    t = re.sub(r'\[(cs|es|ss|ds):', r'\1:[', t)
    t = re.sub(r'\b(word|byte|dword|qword|tbyte)\s+(?:near\s+|far\s+)?((?:cs|es|ss|ds):)?\[', r'\1 ptr \2[', t)
    t = re.sub(r'\b(mov)\s+(es|ds|ss|cs)\s*,\s*(?:word|byte|dword)\s+ptr\s+', r'\1 \2, ', t)
    t = re.sub(r'\b(les|lds)\s+(\w+)\s*,\s*(?:word|byte|dword)\s+ptr\s+', r'\1 \2, dword ptr ', t)
    t = re.sub(r'\b(retf?)\s+word\s+', r'\1 ', t)
    t = re.sub(r'(?<![\w\]:])\[(0x[0-9a-f]+)\]', r'ds:[\1]', t)
    size = _size_for(m)
    if size and '[' in t and ' ptr ' not in t and 'les ' not in t and 'lds ' not in t:
        t = re.sub(r'((?:cs|es|ss|ds):)?\[', lambda mo: f"{size} ptr {mo.group(1) or ''}[", t, count=1)
    return _hexify(t)

def find_jump_tables(blob):
    tables = []
    pos = 0
    while True:
        idx = -1
        pat_len = 0
        for pat in [b'\x2e\xff\xa7', b'\x2e\xff\x27', b'\x2e\xff\x24']:
            p = blob.find(pat, pos)
            if p != -1 and (idx == -1 or p < idx):
                idx = p
                pat_len = len(pat) + (2 if pat.endswith(b'\xa7') else 0)
        if idx == -1:
            break
        table_start = idx + pat_len
        if table_start < len(blob) and blob[table_start] == 0x90:
            table_start += 1
        pre = blob[max(0, idx-40):idx]
        insns = ndisasm(pre)
        cmp_n = None
        for ins in reversed(insns):
            m = re.match(r'^cmp\s+.*,\s*(?:0x([0-9a-f]+)|(\d+))$', ins['mnemonic'])
            if m:
                cmp_n = int(m.group(1), 16) if m.group(1) else int(m.group(2))
                break
        if cmp_n is not None and 1 <= cmp_n <= 300:
            table_len = (cmp_n + 1) * 2
            table_end = table_start + table_len
            if table_end <= len(blob):
                tables.append((table_start, table_end))
                pos = table_end
                continue
        pos = idx + 1
    return tables

def get_clean_insns(blob):
    tables = find_jump_tables(blob)
    segs = []
    cur = 0
    for t_start, t_end in tables:
        if t_start > cur:
            segs.append((cur, t_start, False))
        segs.append((t_start, t_end, True))
        cur = t_end
    if cur < len(blob):
        segs.append((cur, len(blob), False))
    
    if len(segs) > 0 and not segs[0][2] and segs[0][0] == 0 and len(blob) > 4 and blob[0] == 0x81 and blob[1] in (0x55, 0x56, 0x57):
        segs[0] = (1, segs[0][1], False)
        segs.insert(0, (0, 1, 'byte'))
    
    split_points = set()
    for s_start, s_end, is_table in segs:
        if not is_table and is_table != 'byte':
            for ins in ndisasm(blob[s_start:s_end], origin=s_start):
                m = re.match(r'^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$', ins['mnemonic'])
                if m:
                    t = int(m.group(2), 16)
                    if 0 <= t < len(blob):
                        split_points.add(t)
    
    for _ in range(5):
        new_splits = set()
        for s_start, s_end, is_table in segs:
            if is_table: continue
            insns = ndisasm(blob[s_start:s_end], origin=s_start)
            addrs = {ins['addr'] for ins in insns}
            for t in split_points:
                if s_start < t < s_end and t not in addrs:
                    new_splits.add(t)
        if not new_splits:
            break
        refined = []
        for s_start, s_end, is_table in segs:
            if is_table:
                refined.append((s_start, s_end, is_table))
            else:
                pts = sorted(pt for pt in new_splits if s_start < pt < s_end)
                cur_pt = s_start
                for pt in pts:
                    refined.append((cur_pt, pt, False))
                    cur_pt = pt
                refined.append((cur_pt, s_end, False))
        segs = refined
    
    all_insns = []
    for s_start, s_end, is_table in segs:
        if is_table == True:
            all_insns.append({'addr': s_start, 'raw': blob[s_start:s_end], 'mnemonic': 'TABLE', 'table': blob[s_start:s_end]})
        elif is_table == 'byte':
            b = blob[s_start]
            h = f'0{b:02X}h' if b >= 0xA0 else f'{b:02X}h'
            all_insns.append({'addr': s_start, 'raw': blob[s_start:s_end], 'mnemonic': f'db {h}'})
        else:
            if s_start < s_end:
                for ins in ndisasm(blob[s_start:s_end], origin=s_start):
                    all_insns.append(ins)
    return all_insns

def needs_extend_imm(ins):
    raw = ins['raw']
    i = 0
    while i < len(raw) and raw[i] in (0x26, 0x2E, 0x36, 0x3E, 0x64, 0x65, 0x66, 0x67, 0xF0, 0xF2, 0xF3):
        i += 1
    if i >= len(raw):
        return False
    op = raw[i]
    if op == 0x81 or op in (0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x35, 0x3D, 0x69, 0xC7):
        return True
    return False

def needs_extend_disp(ins):
    raw = ins['raw']
    i = 0
    while i < len(raw) and raw[i] in (0x26, 0x2E, 0x36, 0x3E, 0x64, 0x65, 0x66, 0x67, 0xF0, 0xF2, 0xF3):
        i += 1
    if i >= len(raw):
        return False
    i += 1
    if i < len(raw) and raw[i-1] == 0x0F:
        i += 1
    if i >= len(raw):
        return False
    modrm = raw[i]
    return ((modrm >> 6) & 3) == 2

def generate_listing(blob, insns, extend_disp_addrs, extend_imm_addrs, db_overrides, track_symbols=False):
    targets = {}
    for ins in insns:
        if ins['mnemonic'] == 'TABLE': continue
        m = re.match(r'^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$', ins['mnemonic'])
        if m:
            t = int(m.group(2), 16)
            targets.setdefault(t, set()).add('f' if t > ins['addr'] else 'b')

    extrns = []
    out = []
    pubdefs = []
    for idx, ins in enumerate(insns):
        addr = ins['addr']
        for s in sorted(targets.get(addr, ())):
            out.append(f'lbl{addr:02X}{s}:')
        if track_symbols:
            sym_name = f's_{idx}'
            pubdefs.append(sym_name)
            out.append(f'{sym_name}:')
        if addr in db_overrides:
            b_list = db_overrides[addr]
            db_str = ', '.join(f'0{b:02X}h' if b >= 0xA0 else f'{b:02X}h' for b in b_list)
            out.append(f'db {db_str} ; override')
            continue
        if ins['mnemonic'] == 'TABLE':
            tbl = ins['table']
            for c_start in range(0, len(tbl), 16):
                chunk = tbl[c_start:c_start+16]
                db_str = ', '.join(f'0{b:02X}h' if b >= 0xA0 else f'{b:02X}h' for b in chunk)
                out.append(f'db {db_str}')
            continue
        if ins['mnemonic'].startswith('db '):
            out.append(_hexify(ins['mnemonic']))
            continue
        first = ins['raw'][:1]
        if first == b'\x9a':
            name = f'mf{addr:x}'; extrns.append(name); out.append(f'call {name}'); continue
        if first == b'\xea':
            name = f'mj{addr:x}'; extrns.append(name); out.append(f'jmp {name}'); continue
        if first == b'\xe8':
            name = f'mn{addr:x}'; extrns.append(name); out.append(f'call {name}'); continue
        if first == b'\xe9':
            m = re.match(r'^jmp\s+0x([0-9a-f]+)$', ins['mnemonic'])
            t = int(m.group(1), 16) if m else -1
            if t < 0 or t >= len(blob):
                name = f'mjn{addr:x}'; extrns.append(name); out.append(f'jmp {name}'); continue
        m = re.match(r'^(j[a-z]+|loop[a-z]*)\s+0x([0-9a-f]+)$', ins['mnemonic'])
        if m:
            name_, t = m.group(1), int(m.group(2), 16)
            s = 'f' if t > ins['addr'] else 'b'
            if name_ == 'jmp':
                out.append(f'jmp short lbl{t:02X}{s}' if ins['raw'][:1] == b'\xeb' else f'jmp near ptr lbl{t:02X}{s}')
            elif name_ == 'jcxz' or name_.startswith('loop'):
                out.append(f'{name_} lbl{t:02X}{s}')
            else:
                out.append(f'{name_} short lbl{t:02X}{s}')
            continue
        text = _plain(ins['mnemonic'])
        if addr in extend_imm_addrs:
            name = f'mi{addr:x}'; extrns.append(name)
            text = re.sub(r'([^,]+),\s*(?:0x[0-9a-f]+|[0-9A-F]+h)\s*$', rf'\1, offset {name}', text)
        if addr in extend_disp_addrs:
            name = f'md{addr:x}'; extrns.append(name)
            text = re.sub(r'[+\\-](?:0x[0-9a-f]+|[0-9A-F]+h)', '+' + name, text, count=1)
        out.append(text)

    if track_symbols:
        last_sym = f's_{len(insns)}'
        pubdefs.append(last_sym)
        out.append(f'{last_sym}:')

    for t, ss in sorted(targets.items()):
        if t >= len(blob):
            for s in sorted(ss):
                out.append(f'lbl{t:02X}{s}:')
    return out, extrns, pubdefs

def assemble_with_pubdefs(lines, extrns, pubdefs, cpu='-1'):
    def decl(n):
        return f'    EXTRN {n}:' + ('FAR' if (n.startswith(('mf', 'mj')) and not n.startswith('mjn')) else 'NEAR') + '\n'
    pub_line = ''
    for i in range(0, len(pubdefs), 10):
        pub_line += '    PUBLIC ' + ', '.join(pubdefs[i:i+10]) + '\n'
    src = (_HEAD + pub_line + ''.join(decl(n) for n in set(extrns)) + 'mnem_unit:\n'
           + '\n'.join(('' if l.endswith(':') else '    ') + l for l in lines) + '\n' + _TAIL)
    with tempfile.TemporaryDirectory() as tmp:
        work = Path(tmp)
        (work / 'u.asm').write_text(src)
        p = subprocess.run(['wine', str(WATCOM / 'binnt/wasm.exe'), '-ml', cpu, '-fo=u.obj', 'u.asm'],
                           cwd=work, capture_output=True, text=True, env=ENV)
        obj_path = work / 'u.obj'
        if not obj_path.is_file():
            errs = [l for l in (p.stdout + p.stderr).splitlines() if 'rror' in l]
            return None, None, src, ' | '.join(errs[:2]) or 'no object'
        obj_bytes = obj_path.read_bytes()
        (code, fix) = ledata_and_fixups(obj_bytes)
        symbols = {}
        i = 0
        while i + 3 <= len(obj_bytes):
            typ = obj_bytes[i]
            length = int.from_bytes(obj_bytes[i+1:i+3], 'little')
            rec = obj_bytes[i+3:i+3+length]
            i += 3 + length
            payload = rec[:-1]
            if typ == 0x90:
                _, cursor = _index(payload, 0)
                segment, cursor = _index(payload, cursor)
                if segment == 0:
                    cursor += 2
                while cursor < len(payload):
                    nlen = payload[cursor]
                    cursor += 1
                    name = payload[cursor:cursor+nlen].decode('latin1')
                    cursor += nlen
                    offset = int.from_bytes(payload[cursor:cursor+2], 'little')
                    cursor += 2
                    _, cursor = _index(payload, cursor)
                    symbols[name] = offset
        return (code, fix), symbols, src, ''

def try_unit(unit):
    img = units.image_bytes()[unit['image']]; off = unit['offset']
    extent = unit.get('extent')
    if not extent:
        import gen_nasm
        blob = gen_nasm.bytes_for(unit, ROOT)
    else:
        blob = img[off:off+extent]
    if not blob:
        return 'FAIL', 'no bytes'
    insns = get_clean_insns(blob)
    ed_addrs, ei_addrs = set(), set()
    db_overrides = {}
    
    for cpu in ['-1', '-2', '-3']:
        for step in range(25):
            lines, extrns, pubdefs = generate_listing(blob, insns, ed_addrs, ei_addrs, db_overrides, track_symbols=True)
            res, syms, src, err = assemble_with_pubdefs(lines, extrns, pubdefs, cpu=cpu)
            if res is None:
                if ('Invalid instruction' in err or 'E003' in err or 'E043' in err) and cpu != '-3':
                    break
                return 'ASMFAIL', err
            code, fix = res
            rel = bytearray(code)
            for o, s in fix:
                if o + s <= len(blob) and o + s <= len(rel):
                    rel[o:o+s] = blob[o:o+s]
            if bytes(rel) == blob:
                clines, cextrns, _ = generate_listing(blob, insns, ed_addrs, ei_addrs, db_overrides, track_symbols=False)
                cdecl = lambda n: f'    EXTRN {n}:' + ('FAR' if (n.startswith(('mf', 'mj')) and not n.startswith('mjn')) else 'NEAR') + '\n'
                final_src = (_HEAD + ''.join(cdecl(n) for n in set(cextrns)) + 'mnem_unit:\n'
                             + '\n'.join(('' if l.endswith(':') else '    ') + l for l in clines) + '\n' + _TAIL)
                return 'MATCH', final_src
            
            changed = False
            for idx, ins in enumerate(insns):
                s_name = f's_{idx}'
                s_next = f's_{idx+1}'
                if s_name not in syms or s_next not in syms:
                    continue
                asm_start = syms[s_name]
                asm_end = syms[s_next]
                asm_len = asm_end - asm_start
                raw_len = len(ins['raw'])
                addr = ins['addr']
                if addr in db_overrides:
                    continue
                if asm_len != raw_len:
                    if addr in ed_addrs or addr in ei_addrs:
                        db_overrides[addr] = ins['raw']
                        changed = True
                        break
                    if asm_len < raw_len:
                        if needs_extend_disp(ins):
                            ed_addrs.add(addr)
                            changed = True
                        if needs_extend_imm(ins):
                            ei_addrs.add(addr)
                            changed = True
                        if not changed:
                            db_overrides[addr] = ins['raw']
                            changed = True
                    else:
                        db_overrides[addr] = ins['raw']
                        changed = True
                    break
                else:
                    asm_bytes = bytearray(code[syms[s_name]:syms[s_next]])
                    for o, s in fix:
                        if syms[s_name] <= o and o + s <= syms[s_next]:
                            ro = o - syms[s_name]
                            asm_bytes[ro:ro+s] = ins['raw'][ro:ro+s]
                    if bytes(asm_bytes) != ins['raw']:
                        if needs_extend_imm(ins) and addr not in ei_addrs:
                            ei_addrs.add(addr)
                            changed = True
                        else:
                            db_overrides[addr] = ins['raw']
                            changed = True
            if not changed:
                break
        if bytes(rel) == blob:
            clines, cextrns, _ = generate_listing(blob, insns, ed_addrs, ei_addrs, db_overrides, track_symbols=False)
            cdecl = lambda n: f'    EXTRN {n}:' + ('FAR' if (n.startswith(('mf', 'mj')) and not n.startswith('mjn')) else 'NEAR') + '\n'
            final_src = (_HEAD + ''.join(cdecl(n) for n in set(cextrns)) + 'mnem_unit:\n'
                         + '\n'.join(('' if l.endswith(':') else '    ') + l for l in clines) + '\n' + _TAIL)
            return 'MATCH', final_src
    return 'STUCK', f'len {len(code)} vs {len(blob)}'

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
    if args.units in (['all'], ['all-dumps']):
        target_units = [u for u in index if u['kind'] == 'dump']
    else:
        target_units = []
        for name in args.units:
            matches = [r for r in index if name in (r['source'], Path(r['source']).stem)]
            if matches:
                target_units.append(matches[0])
            else:
                print(f"{name:<16} NO-SUCH-UNIT")

    good = 0
    total = len(target_units)
    for unit in target_units:
        name = Path(unit['source']).stem
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
        repointed = 0
        for entry in data['units']:
            if entry['source'] == unit['source'] and entry['image'] == unit['image']:
                entry['source'] = listing.relative_to(ROOT).as_posix()
                repointed += 1
        write_json_atomic(path, data)
        if source.suffix == '.c' and source.is_file():
            source.unlink()
        print(f"{name:<16} MATCH -> {listing.relative_to(ROOT).as_posix()} ({repointed} entries)")
    print(f"{good}/{total} MATCH")
