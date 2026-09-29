/*
 * cpu86.c — 8086/80186 real-mode interpreter.
 *
 * Structure of a step:
 *   1. hook/breakpoint bitmap test on CS:IP
 *   2. prefix loop (segment override, REP, LOCK)
 *   3. fetch opcode
 *   4. one flat 256-way switch; the compiler emits a jump table
 *
 * A flat switch is used deliberately rather than computed goto: same jump
 * table, but -Wswitch coverage still applies and it stays debuggable.
 *
 * REP rewinds rather than loops — one iteration per step, with IP reset to
 * the prefix byte if the operation continues. That is real 8086 behaviour
 * (REP is interruptible between iterations), it keeps interrupts landing
 * correctly inside a 64 KB rep movsw, and it stops one instruction blowing
 * past the cycle budget.
 */
#include "cpu86_alu.h"
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Device hooks, defaulted so the core links without a VM (the          */
/* conformance test binary depends on this).                            */
/* ------------------------------------------------------------------ */
static uint8_t  default_in8(cpu86 *c, uint16_t p)             { (void)c; (void)p; return 0xFF; }
static uint16_t default_in16(cpu86 *c, uint16_t p)            { (void)c; (void)p; return 0xFFFF; }
static void     default_out8(cpu86 *c, uint16_t p, uint8_t v) { (void)c; (void)p; (void)v; }
static void     default_out16(cpu86 *c, uint16_t p, uint16_t v){ (void)c; (void)p; (void)v; }
static bool     default_hlt(cpu86 *c, uint32_t lin)           { (void)c; (void)lin; return false; }

uint8_t  (*cpu86_port_in8)(cpu86 *, uint16_t)            = default_in8;
uint16_t (*cpu86_port_in16)(cpu86 *, uint16_t)           = default_in16;
void     (*cpu86_port_out8)(cpu86 *, uint16_t, uint8_t)  = default_out8;
void     (*cpu86_port_out16)(cpu86 *, uint16_t, uint16_t)= default_out16;
bool     (*cpu86_on_hlt)(cpu86 *, uint32_t)              = default_hlt;

/* ------------------------------------------------------------------ */
/* Hook registry: a 1-bit-per-byte presence bitmap over the 1 MB space  */
/* plus a small open-addressed table. The bitmap test is one load and a */
/* predictable branch per instruction.                                  */
/* ------------------------------------------------------------------ */
#define HOOK_BITMAP_BYTES (DOS_MEM_SIZE / 8)
#define HOOK_SLOTS        4096u

typedef struct { uint32_t lin; cpu_hook_fn fn; void *user; uint8_t used; } hook_slot;

static uint8_t   *g_hook_bitmap;
static hook_slot  g_hooks[HOOK_SLOTS];
static uint32_t   g_hook_count;

static inline uint32_t hook_index(uint32_t lin) {
    return (lin * 2654435761u) & (HOOK_SLOTS - 1u);
}

static hook_slot *hook_find(uint32_t lin) {
    uint32_t i = hook_index(lin);
    for (uint32_t n = 0; n < HOOK_SLOTS; n++) {
        hook_slot *s = &g_hooks[(i + n) & (HOOK_SLOTS - 1u)];
        if (!s->used) return NULL;
        if (s->lin == lin) return s;
    }
    return NULL;
}

bool cpu86_hook_install(uint16_t seg, uint16_t off, cpu_hook_fn fn, void *user) {
    uint32_t lin = cpu_lin(seg, off);
    uint32_t i;
    if (g_hook_count + 1 >= HOOK_SLOTS) return false;
    if (!g_hook_bitmap) {
        g_hook_bitmap = (uint8_t *)calloc(1, HOOK_BITMAP_BYTES);
        if (!g_hook_bitmap) return false;
    }
    i = hook_index(lin);
    for (uint32_t n = 0; n < HOOK_SLOTS; n++) {
        hook_slot *s = &g_hooks[(i + n) & (HOOK_SLOTS - 1u)];
        if (!s->used || s->lin == lin) {
            if (!s->used) g_hook_count++;
            s->used = 1; s->lin = lin; s->fn = fn; s->user = user;
            g_hook_bitmap[lin >> 3] |= (uint8_t)(1u << (lin & 7u));
            return true;
        }
    }
    return false;
}

void cpu86_hook_remove(uint16_t seg, uint16_t off) {
    uint32_t lin = cpu_lin(seg, off);
    hook_slot *s = hook_find(lin);
    if (!s) return;
    /* Tombstone-free removal is not worth it here; just disable the entry
     * and clear the bitmap bit so the hot path stops testing it. */
    s->fn = NULL;
    if (g_hook_bitmap) g_hook_bitmap[lin >> 3] &= (uint8_t)~(1u << (lin & 7u));
}

void cpu86_hook_clear_all(void) {
    memset(g_hooks, 0, sizeof(g_hooks));
    g_hook_count = 0;
    if (g_hook_bitmap) memset(g_hook_bitmap, 0, HOOK_BITMAP_BYTES);
}

/* ------------------------------------------------------------------ */
/* Fetch                                                                */
/* ------------------------------------------------------------------ */
static inline uint8_t fetch8(cpu86 *c) {
    uint8_t v = seg_r8(c->s[CPU_CS], c->ip);
    c->ip = (uint16_t)(c->ip + 1);
    return v;
}

static inline uint16_t fetch16(cpu86 *c) {
    uint16_t v = seg_r16(c->s[CPU_CS], c->ip);
    c->ip = (uint16_t)(c->ip + 2);
    return v;
}

/* ------------------------------------------------------------------ */
/* Stack                                                                */
/* ------------------------------------------------------------------ */
void cpu86_push16(cpu86 *c, uint16_t v) {
    c->r[CPU_SP] = (uint16_t)(c->r[CPU_SP] - 2);
    seg_w16(c->s[CPU_SS], c->r[CPU_SP], v);
}

uint16_t cpu86_pop16(cpu86 *c) {
    uint16_t v = seg_r16(c->s[CPU_SS], c->r[CPU_SP]);
    c->r[CPU_SP] = (uint16_t)(c->r[CPU_SP] + 2);
    return v;
}

/* ------------------------------------------------------------------ */
/* ModRM                                                                */
/* ------------------------------------------------------------------ */
typedef struct { uint8_t is_reg; uint8_t reg; uint16_t seg, off; } rm_t;

/* Default segment per rm form. Forms using BP default to SS; the rest DS.
 * This table is the ONLY place the default lives, and the override is
 * applied here too — which removes the "forgot the override on one
 * instruction" bug class entirely. */
static const uint8_t rm_default_seg[8] = {
    CPU_DS, CPU_DS, CPU_SS, CPU_SS, CPU_DS, CPU_DS, CPU_SS, CPU_DS
};

static rm_t decode_modrm(cpu86 *c, uint8_t modrm, uint8_t *regfield) {
    rm_t m;
    uint8_t mod = (uint8_t)(modrm >> 6);
    uint8_t rm  = (uint8_t)(modrm & 7);
    uint16_t off = 0;
    int dseg;

    *regfield = (uint8_t)((modrm >> 3) & 7);

    if (mod == 3) {
        m.is_reg = 1; m.reg = rm; m.seg = 0; m.off = 0;
        return m;
    }

    switch (rm) {
    case 0: off = (uint16_t)(c->r[CPU_BX] + c->r[CPU_SI]); break;
    case 1: off = (uint16_t)(c->r[CPU_BX] + c->r[CPU_DI]); break;
    case 2: off = (uint16_t)(c->r[CPU_BP] + c->r[CPU_SI]); break;
    case 3: off = (uint16_t)(c->r[CPU_BP] + c->r[CPU_DI]); break;
    case 4: off = c->r[CPU_SI]; break;
    case 5: off = c->r[CPU_DI]; break;
    case 6: off = (mod == 0) ? 0 : c->r[CPU_BP]; break;
    case 7: off = c->r[CPU_BX]; break;
    default: break;
    }

    dseg = rm_default_seg[rm];
    if (mod == 0 && rm == 6) {
        off = fetch16(c);      /* direct disp16 */
        dseg = CPU_DS;
    } else if (mod == 1) {
        off = (uint16_t)(off + (int16_t)(int8_t)fetch8(c));
    } else if (mod == 2) {
        off = (uint16_t)(off + fetch16(c));
    }

    m.is_reg = 0;
    m.reg = 0;
    m.off = off;
    m.seg = c->s[(c->seg_override >= 0) ? c->seg_override : dseg];
    return m;
}

static inline uint8_t rm_r8(cpu86 *c, const rm_t *m) {
    return m->is_reg ? cpu_get_r8(c, m->reg) : seg_r8(m->seg, m->off);
}
static inline uint16_t rm_r16(cpu86 *c, const rm_t *m) {
    return m->is_reg ? c->r[m->reg] : seg_r16(m->seg, m->off);
}
static inline void rm_w8(cpu86 *c, const rm_t *m, uint8_t v) {
    if (m->is_reg) cpu_set_r8(c, m->reg, v); else seg_w8(m->seg, m->off, v);
}
static inline void rm_w16(cpu86 *c, const rm_t *m, uint16_t v) {
    if (m->is_reg) c->r[m->reg] = v; else seg_w16(m->seg, m->off, v);
}

/* Effective segment for a data reference that defaults to DS. */
static inline uint16_t data_seg(cpu86 *c) {
    return c->s[(c->seg_override >= 0) ? c->seg_override : CPU_DS];
}

/* ------------------------------------------------------------------ */
/* Control transfer                                                     */
/* ------------------------------------------------------------------ */
void cpu86_interrupt(cpu86 *c, uint8_t vec) {
    uint16_t off = seg_r16(0, (uint16_t)(vec * 4));
    uint16_t seg = seg_r16(0, (uint16_t)(vec * 4 + 2));
    cpu86_push16(c, c->flags);
    cpu86_push16(c, c->s[CPU_CS]);
    cpu86_push16(c, c->ip);
    c->flags &= (uint16_t)~(F_IF | F_TF);
    c->s[CPU_CS] = seg;
    c->ip = off;
}

void cpu86_far_call(cpu86 *c, uint16_t seg, uint16_t off) {
    cpu86_push16(c, c->s[CPU_CS]);
    cpu86_push16(c, c->ip);
    c->s[CPU_CS] = seg;
    c->ip = off;
}

void cpu86_reset(cpu86 *c) {
    memset(c, 0, sizeof(*c));
    c->flags = F_ALWAYS_SET;
    c->seg_override = -1;
    c->s[CPU_CS] = 0xFFFF;
    c->ip = 0;
}

const char *cpu86_fault_name(int fault) {
    switch (fault) {
    case CPU_OK:                return "ok";
    case CPU_FAULT_BAD_OPCODE:  return "unimplemented opcode";
    case CPU_FAULT_UNIMPL_INT:  return "unimplemented interrupt service";
    case CPU_FAULT_HOST_ABORT:  return "host abort";
    case CPU_FAULT_BREAKPOINT:  return "breakpoint";
    case CPU_FAULT_EXITED:      return "guest exited";
    default:                    return "unknown";
    }
}

/* Conditional-jump predicate for the 0x70-0x7F / 0x0F8x condition codes. */
static int cond_true(const cpu86 *c, uint8_t cc) {
    uint16_t f = c->flags;
    switch (cc >> 1) {
    case 0: return  (f & F_OF) != 0;                              /* O  */
    case 1: return  (f & F_CF) != 0;                              /* C  */
    case 2: return  (f & F_ZF) != 0;                              /* Z  */
    case 3: return ((f & F_CF) != 0) || ((f & F_ZF) != 0);        /* BE */
    case 4: return  (f & F_SF) != 0;                              /* S  */
    case 5: return  (f & F_PF) != 0;                              /* P  */
    case 6: return (((f & F_SF) != 0) != ((f & F_OF) != 0));      /* L  */
    case 7: return (((f & F_SF) != 0) != ((f & F_OF) != 0))
                   || ((f & F_ZF) != 0);                          /* LE */
    default: return 0;
    }
}

/* ------------------------------------------------------------------ */
/* String operations                                                    */
/* ------------------------------------------------------------------ */
static void string_step(cpu86 *c, uint8_t op, int w) {
    int delta = (c->flags & F_DF) ? -w / 8 : w / 8;
    uint16_t sseg = data_seg(c);          /* source: DS, overridable */
    uint16_t dseg = c->s[CPU_ES];         /* dest: ES, NOT overridable */
    uint16_t si = c->r[CPU_SI], di = c->r[CPU_DI];

    switch (op) {
    case 0xA4: case 0xA5:  /* MOVS */
        if (w == 8) seg_w8(dseg, di, seg_r8(sseg, si));
        else        seg_w16(dseg, di, seg_r16(sseg, si));
        c->r[CPU_SI] = (uint16_t)(si + delta);
        c->r[CPU_DI] = (uint16_t)(di + delta);
        break;

    case 0xA6: case 0xA7:  /* CMPS: compares source to dest */
        if (w == 8) alu_op(c, ALU_CMP, seg_r8(sseg, si), seg_r8(dseg, di), 8);
        else        alu_op(c, ALU_CMP, seg_r16(sseg, si), seg_r16(dseg, di), 16);
        c->r[CPU_SI] = (uint16_t)(si + delta);
        c->r[CPU_DI] = (uint16_t)(di + delta);
        break;

    case 0xAA: case 0xAB:  /* STOS */
        if (w == 8) seg_w8(dseg, di, cpu_get_r8(c, CPU_AL));
        else        seg_w16(dseg, di, c->r[CPU_AX]);
        c->r[CPU_DI] = (uint16_t)(di + delta);
        break;

    case 0xAC: case 0xAD:  /* LODS */
        if (w == 8) cpu_set_r8(c, CPU_AL, seg_r8(sseg, si));
        else        c->r[CPU_AX] = seg_r16(sseg, si);
        c->r[CPU_SI] = (uint16_t)(si + delta);
        break;

    case 0xAE: case 0xAF:  /* SCAS */
        if (w == 8) alu_op(c, ALU_CMP, cpu_get_r8(c, CPU_AL), seg_r8(dseg, di), 8);
        else        alu_op(c, ALU_CMP, c->r[CPU_AX], seg_r16(dseg, di), 16);
        c->r[CPU_DI] = (uint16_t)(di + delta);
        break;

    case 0x6C: case 0x6D:  /* INS */
        if (w == 8) seg_w8(dseg, di, cpu86_port_in8(c, c->r[CPU_DX]));
        else        seg_w16(dseg, di, cpu86_port_in16(c, c->r[CPU_DX]));
        c->r[CPU_DI] = (uint16_t)(di + delta);
        break;

    case 0x6E: case 0x6F:  /* OUTS */
        if (w == 8) cpu86_port_out8(c, c->r[CPU_DX], seg_r8(sseg, si));
        else        cpu86_port_out16(c, c->r[CPU_DX], seg_r16(sseg, si));
        c->r[CPU_SI] = (uint16_t)(si + delta);
        break;

    default: break;
    }
}

/* Runs one iteration and decides whether to rewind IP for another. */
static void do_string_op(cpu86 *c, uint8_t op, int w) {
    int is_cmp = (op == 0xA6 || op == 0xA7 || op == 0xAE || op == 0xAF);

    if (!c->rep) {
        string_step(c, op, w);
        return;
    }
    if (c->r[CPU_CX] == 0) return;   /* IP already past the instruction */

    string_step(c, op, w);
    c->r[CPU_CX] = (uint16_t)(c->r[CPU_CX] - 1);

    if (c->r[CPU_CX] == 0) return;
    if (is_cmp) {
        int zf = (c->flags & F_ZF) != 0;
        int want = (c->rep == 0xF3);     /* REPE wants ZF=1, REPNE ZF=0 */
        if (zf != want) return;
    }
    c->ip = c->insn_ip;                  /* rewind to the prefix byte */
}

/* ------------------------------------------------------------------ */
/* One instruction                                                      */
/* ------------------------------------------------------------------ */
void cpu86_step(cpu86 *c) {
    uint8_t op, modrm, regf;
    rm_t m;
    uint32_t lin;
    int prefix_done = 0;

    c->insn_ip = c->ip;
    c->step_guest_insns = 1;
    c->seg_override = -1;
    c->rep = 0;
    c->inhibit_irq = 0;

    /* ---- hook / breakpoint ---- */
    lin = cpu_lin(c->s[CPU_CS], c->ip);
    if (g_hook_bitmap && (g_hook_bitmap[lin >> 3] & (1u << (lin & 7u)))) {
        hook_slot *s = hook_find(lin);
        if (s && s->fn) {
            hook_result_t hr = s->fn(c, s->user);
            switch (hr) {
            case HOOK_DID_RETN:
                c->ip = cpu86_pop16(c);
                return;
            case HOOK_DID_RETF:
                c->ip = cpu86_pop16(c);
                c->s[CPU_CS] = cpu86_pop16(c);
                return;
            case HOOK_DID_SETIP:
                return;
            case HOOK_CONTINUE:
            default:
                break;
            }
        }
    }

    /* ---- prefixes ---- */
    while (!prefix_done) {
        op = fetch8(c);
        switch (op) {
        case 0x26: c->seg_override = CPU_ES; c->inhibit_irq = 1; break;
        case 0x2E: c->seg_override = CPU_CS; c->inhibit_irq = 1; break;
        case 0x36: c->seg_override = CPU_SS; c->inhibit_irq = 1; break;
        case 0x3E: c->seg_override = CPU_DS; c->inhibit_irq = 1; break;
        case 0xF0: /* LOCK: no effect on a single-threaded interpreter */ break;
        case 0xF2: c->rep = 0xF2; break;
        case 0xF3: c->rep = 0xF3; break;
        default:   prefix_done = 1; break;
        }
    }

    c->cycles += 4;   /* coarse cost model; timing precision is not needed */

    switch (op) {

    /* ---- ALU group, regular encodings ------------------------------ */
    case 0x00: case 0x08: case 0x10: case 0x18:
    case 0x20: case 0x28: case 0x30: case 0x38: { /* op rm8, r8 */
        int aop = op >> 3;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        { uint8_t r = alu_op(c, aop, rm_r8(c, &m), cpu_get_r8(c, regf), 8);
          if (aop != ALU_CMP) rm_w8(c, &m, r); }
        break;
    }
    case 0x01: case 0x09: case 0x11: case 0x19:
    case 0x21: case 0x29: case 0x31: case 0x39: { /* op rm16, r16 */
        int aop = op >> 3;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        { uint16_t r = alu_op(c, aop, rm_r16(c, &m), c->r[regf], 16);
          if (aop != ALU_CMP) rm_w16(c, &m, r); }
        break;
    }
    case 0x02: case 0x0A: case 0x12: case 0x1A:
    case 0x22: case 0x2A: case 0x32: case 0x3A: { /* op r8, rm8 */
        int aop = op >> 3;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        { uint8_t r = alu_op(c, aop, cpu_get_r8(c, regf), rm_r8(c, &m), 8);
          if (aop != ALU_CMP) cpu_set_r8(c, regf, r); }
        break;
    }
    case 0x03: case 0x0B: case 0x13: case 0x1B:
    case 0x23: case 0x2B: case 0x33: case 0x3B: { /* op r16, rm16 */
        int aop = op >> 3;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        { uint16_t r = alu_op(c, aop, c->r[regf], rm_r16(c, &m), 16);
          if (aop != ALU_CMP) c->r[regf] = r; }
        break;
    }
    case 0x04: case 0x0C: case 0x14: case 0x1C:
    case 0x24: case 0x2C: case 0x34: case 0x3C: { /* op AL, imm8 */
        int aop = op >> 3;
        uint8_t r = alu_op(c, aop, cpu_get_r8(c, CPU_AL), fetch8(c), 8);
        if (aop != ALU_CMP) cpu_set_r8(c, CPU_AL, r);
        break;
    }
    case 0x05: case 0x0D: case 0x15: case 0x1D:
    case 0x25: case 0x2D: case 0x35: case 0x3D: { /* op AX, imm16 */
        int aop = op >> 3;
        uint16_t r = alu_op(c, aop, c->r[CPU_AX], fetch16(c), 16);
        if (aop != ALU_CMP) c->r[CPU_AX] = r;
        break;
    }

    /* ---- segment push/pop ------------------------------------------ */
    case 0x06: cpu86_push16(c, c->s[CPU_ES]); break;
    case 0x0E: cpu86_push16(c, c->s[CPU_CS]); break;
    case 0x16: cpu86_push16(c, c->s[CPU_SS]); break;
    case 0x1E: cpu86_push16(c, c->s[CPU_DS]); break;
    case 0x07: c->s[CPU_ES] = cpu86_pop16(c); c->inhibit_irq = 1; break;
    case 0x17: c->s[CPU_SS] = cpu86_pop16(c); c->inhibit_irq = 1; break;
    case 0x1F: c->s[CPU_DS] = cpu86_pop16(c); c->inhibit_irq = 1; break;

    /* ---- BCD -------------------------------------------------------- */
    case 0x27: alu_daa(c); break;
    case 0x2F: alu_das(c); break;
    case 0x37: alu_aaa(c); break;
    case 0x3F: alu_aas(c); break;

    /* ---- INC/DEC/PUSH/POP r16 --------------------------------------- */
    case 0x40: case 0x41: case 0x42: case 0x43:
    case 0x44: case 0x45: case 0x46: case 0x47:
        c->r[op & 7] = alu_inc(c, c->r[op & 7], 16); break;
    case 0x48: case 0x49: case 0x4A: case 0x4B:
    case 0x4C: case 0x4D: case 0x4E: case 0x4F:
        c->r[op & 7] = alu_dec(c, c->r[op & 7], 16); break;
    case 0x50: case 0x51: case 0x52: case 0x53:
    case 0x54: case 0x55: case 0x56: case 0x57:
        cpu86_push16(c, c->r[op & 7]); break;
    case 0x58: case 0x59: case 0x5A: case 0x5B:
    case 0x5C: case 0x5D: case 0x5E: case 0x5F:
        c->r[op & 7] = cpu86_pop16(c); break;

    /* ---- 80186 ------------------------------------------------------ */
    case 0x60: { /* PUSHA */
        uint16_t sp = c->r[CPU_SP];
        cpu86_push16(c, c->r[CPU_AX]); cpu86_push16(c, c->r[CPU_CX]);
        cpu86_push16(c, c->r[CPU_DX]); cpu86_push16(c, c->r[CPU_BX]);
        cpu86_push16(c, sp);
        cpu86_push16(c, c->r[CPU_BP]); cpu86_push16(c, c->r[CPU_SI]);
        cpu86_push16(c, c->r[CPU_DI]);
        break;
    }
    case 0x61: { /* POPA — the pushed SP is discarded */
        c->r[CPU_DI] = cpu86_pop16(c); c->r[CPU_SI] = cpu86_pop16(c);
        c->r[CPU_BP] = cpu86_pop16(c); (void)cpu86_pop16(c);
        c->r[CPU_BX] = cpu86_pop16(c); c->r[CPU_DX] = cpu86_pop16(c);
        c->r[CPU_CX] = cpu86_pop16(c); c->r[CPU_AX] = cpu86_pop16(c);
        break;
    }
    case 0x62: { /* BOUND */
        int16_t idx, lo, hi;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        idx = (int16_t)c->r[regf];
        lo  = (int16_t)seg_r16(m.seg, m.off);
        hi  = (int16_t)seg_r16(m.seg, (uint16_t)(m.off + 2));
        if (idx < lo || idx > hi) { cpu86_interrupt(c, 5); }
        break;
    }
    case 0x68: cpu86_push16(c, fetch16(c)); break;              /* PUSH imm16 */
    case 0x6A: cpu86_push16(c, (uint16_t)(int16_t)(int8_t)fetch8(c)); break;
    case 0x69: { /* IMUL r16, rm16, imm16 */
        uint16_t src, imm;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        src = rm_r16(c, &m); imm = fetch16(c);
        c->r[regf] = alu_imul16_imm(c, src, imm);
        break;
    }
    case 0x6B: { /* IMUL r16, rm16, imm8 (sign-extended) */
        uint16_t src, imm;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        src = rm_r16(c, &m); imm = (uint16_t)(int16_t)(int8_t)fetch8(c);
        c->r[regf] = alu_imul16_imm(c, src, imm);
        break;
    }
    case 0x6C: do_string_op(c, 0x6C, 8);  break;
    case 0x6D: do_string_op(c, 0x6D, 16); break;
    case 0x6E: do_string_op(c, 0x6E, 8);  break;
    case 0x6F: do_string_op(c, 0x6F, 16); break;

    /* ---- Jcc rel8 ---------------------------------------------------- */
    case 0x70: case 0x71: case 0x72: case 0x73:
    case 0x74: case 0x75: case 0x76: case 0x77:
    case 0x78: case 0x79: case 0x7A: case 0x7B:
    case 0x7C: case 0x7D: case 0x7E: case 0x7F: {
        int8_t rel = (int8_t)fetch8(c);
        int take = cond_true(c, (uint8_t)(op & 0x0F));
        if (op & 1) take = !take;       /* odd opcodes are the negated form */
        if (take) c->ip = (uint16_t)(c->ip + rel);
        break;
    }

    /* ---- group 1: op rm, imm ---------------------------------------- */
    case 0x80: case 0x82: { /* 0x82 is an undocumented alias of 0x80 */
        uint8_t imm, r;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        imm = fetch8(c);
        r = alu_op(c, regf, rm_r8(c, &m), imm, 8);
        if (regf != ALU_CMP) rm_w8(c, &m, r);
        break;
    }
    case 0x81: {
        uint16_t imm, r;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        imm = fetch16(c);
        r = alu_op(c, regf, rm_r16(c, &m), imm, 16);
        if (regf != ALU_CMP) rm_w16(c, &m, r);
        break;
    }
    case 0x83: {
        uint16_t imm, r;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        imm = (uint16_t)(int16_t)(int8_t)fetch8(c);
        r = alu_op(c, regf, rm_r16(c, &m), imm, 16);
        if (regf != ALU_CMP) rm_w16(c, &m, r);
        break;
    }

    /* ---- TEST / XCHG / MOV ------------------------------------------ */
    case 0x84:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        alu_op(c, ALU_AND, rm_r8(c, &m), cpu_get_r8(c, regf), 8);
        break;
    case 0x85:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        alu_op(c, ALU_AND, rm_r16(c, &m), c->r[regf], 16);
        break;
    case 0x86: {
        uint8_t a, b;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        a = rm_r8(c, &m); b = cpu_get_r8(c, regf);
        rm_w8(c, &m, b); cpu_set_r8(c, regf, a);
        break;
    }
    case 0x87: {
        uint16_t a, b;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        a = rm_r16(c, &m); b = c->r[regf];
        rm_w16(c, &m, b); c->r[regf] = a;
        break;
    }
    case 0x88:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w8(c, &m, cpu_get_r8(c, regf));
        break;
    case 0x89:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, c->r[regf]);
        break;
    case 0x8A:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        cpu_set_r8(c, regf, rm_r8(c, &m));
        break;
    case 0x8B:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        c->r[regf] = rm_r16(c, &m);
        break;
    case 0x8C:  /* MOV rm16, Sreg */
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, c->s[regf & 3]);
        break;
    case 0x8D: { /* LEA — address only, no memory access, no segment */
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        c->r[regf] = m.off;
        break;
    }
    case 0x8E:  /* MOV Sreg, rm16 */
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        c->s[regf & 3] = rm_r16(c, &m);
        c->inhibit_irq = 1;
        break;
    case 0x8F:  /* POP rm16 */
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, cpu86_pop16(c));
        break;

    /* ---- XCHG AX, r16 ------------------------------------------------ */
    case 0x90: break;   /* NOP */
    case 0x91: case 0x92: case 0x93:
    case 0x94: case 0x95: case 0x96: case 0x97: {
        uint16_t t = c->r[CPU_AX];
        c->r[CPU_AX] = c->r[op & 7];
        c->r[op & 7] = t;
        break;
    }

    case 0x98: /* CBW */
        c->r[CPU_AX] = (uint16_t)(int16_t)(int8_t)cpu_get_r8(c, CPU_AL);
        break;
    case 0x99: /* CWD */
        c->r[CPU_DX] = (c->r[CPU_AX] & 0x8000) ? 0xFFFF : 0x0000;
        break;
    case 0x9A: { /* CALL far imm */
        uint16_t off = fetch16(c), seg = fetch16(c);
        cpu86_far_call(c, seg, off);
        break;
    }
    case 0x9B: break; /* WAIT — no coprocessor, so a no-op */
    case 0x9C: cpu86_push16(c, (uint16_t)(c->flags | F_ALWAYS_SET)); break;
    case 0x9D:
        c->flags = (uint16_t)((cpu86_pop16(c) & F_MODIFIABLE) | F_ALWAYS_SET);
        break;
    case 0x9E: /* SAHF */
        c->flags = (uint16_t)((c->flags & 0xFF00u)
                 | (cpu_get_r8(c, CPU_AH) & (F_CF|F_PF|F_AF|F_ZF|F_SF))
                 | 0x02u);
        break;
    case 0x9F: /* LAHF */
        cpu_set_r8(c, CPU_AH, (uint8_t)((c->flags & 0xFF) | 0x02u));
        break;

    /* ---- MOV accumulator <-> moffs ----------------------------------- */
    case 0xA0: cpu_set_r8(c, CPU_AL, seg_r8(data_seg(c), fetch16(c))); break;
    case 0xA1: c->r[CPU_AX] = seg_r16(data_seg(c), fetch16(c)); break;
    case 0xA2: { uint16_t o = fetch16(c); seg_w8(data_seg(c), o, cpu_get_r8(c, CPU_AL)); break; }
    case 0xA3: { uint16_t o = fetch16(c); seg_w16(data_seg(c), o, c->r[CPU_AX]); break; }

    /* ---- string ops --------------------------------------------------- */
    case 0xA4: do_string_op(c, 0xA4, 8);  break;
    case 0xA5: do_string_op(c, 0xA5, 16); break;
    case 0xA6: do_string_op(c, 0xA6, 8);  break;
    case 0xA7: do_string_op(c, 0xA7, 16); break;
    case 0xAA: do_string_op(c, 0xAA, 8);  break;
    case 0xAB: do_string_op(c, 0xAB, 16); break;
    case 0xAC: do_string_op(c, 0xAC, 8);  break;
    case 0xAD: do_string_op(c, 0xAD, 16); break;
    case 0xAE: do_string_op(c, 0xAE, 8);  break;
    case 0xAF: do_string_op(c, 0xAF, 16); break;

    case 0xA8: alu_op(c, ALU_AND, cpu_get_r8(c, CPU_AL), fetch8(c), 8); break;
    case 0xA9: alu_op(c, ALU_AND, c->r[CPU_AX], fetch16(c), 16); break;

    /* ---- MOV r, imm ---------------------------------------------------- */
    case 0xB0: case 0xB1: case 0xB2: case 0xB3:
    case 0xB4: case 0xB5: case 0xB6: case 0xB7:
        cpu_set_r8(c, op & 7, fetch8(c)); break;
    case 0xB8: case 0xB9: case 0xBA: case 0xBB:
    case 0xBC: case 0xBD: case 0xBE: case 0xBF:
        c->r[op & 7] = fetch16(c); break;

    /* ---- shift groups --------------------------------------------------- */
    case 0xC0: { /* 186: shift rm8, imm8 */
        uint8_t cnt;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        cnt = fetch8(c);
        rm_w8(c, &m, (uint8_t)alu_shift(c, regf, rm_r8(c, &m), cnt, 8));
        break;
    }
    case 0xC1: {
        uint8_t cnt;
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        cnt = fetch8(c);
        rm_w16(c, &m, alu_shift(c, regf, rm_r16(c, &m), cnt, 16));
        break;
    }
    case 0xD0:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w8(c, &m, (uint8_t)alu_shift(c, regf, rm_r8(c, &m), 1, 8));
        break;
    case 0xD1:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, alu_shift(c, regf, rm_r16(c, &m), 1, 16));
        break;
    case 0xD2:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w8(c, &m, (uint8_t)alu_shift(c, regf, rm_r8(c, &m),
                                        cpu_get_r8(c, CPU_CL), 8));
        break;
    case 0xD3:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, alu_shift(c, regf, rm_r16(c, &m),
                                cpu_get_r8(c, CPU_CL), 16));
        break;

    /* ---- returns -------------------------------------------------------- */
    case 0xC2: { uint16_t n = fetch16(c);
                 c->ip = cpu86_pop16(c);
                 c->r[CPU_SP] = (uint16_t)(c->r[CPU_SP] + n); break; }
    case 0xC3:   c->ip = cpu86_pop16(c); break;
    case 0xCA: { uint16_t n = fetch16(c);
                 c->ip = cpu86_pop16(c);
                 c->s[CPU_CS] = cpu86_pop16(c);
                 c->r[CPU_SP] = (uint16_t)(c->r[CPU_SP] + n); break; }
    case 0xCB:   c->ip = cpu86_pop16(c);
                 c->s[CPU_CS] = cpu86_pop16(c); break;

    /* ---- LES / LDS ------------------------------------------------------- */
    case 0xC4:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        c->r[regf]   = seg_r16(m.seg, m.off);
        c->s[CPU_ES] = seg_r16(m.seg, (uint16_t)(m.off + 2));
        c->inhibit_irq = 1;
        break;
    case 0xC5:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        c->r[regf]   = seg_r16(m.seg, m.off);
        c->s[CPU_DS] = seg_r16(m.seg, (uint16_t)(m.off + 2));
        c->inhibit_irq = 1;
        break;

    case 0xC6:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w8(c, &m, fetch8(c));
        break;
    case 0xC7:
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        rm_w16(c, &m, fetch16(c));
        break;

    case 0xC8: { /* ENTER imm16, imm8 */
        uint16_t alloc = fetch16(c);
        uint8_t  level = (uint8_t)(fetch8(c) & 0x1F);
        uint16_t frame;
        cpu86_push16(c, c->r[CPU_BP]);
        frame = c->r[CPU_SP];
        for (uint8_t i = 1; i < level; i++) {
            c->r[CPU_BP] = (uint16_t)(c->r[CPU_BP] - 2);
            cpu86_push16(c, seg_r16(c->s[CPU_SS], c->r[CPU_BP]));
        }
        if (level > 0) cpu86_push16(c, frame);
        c->r[CPU_BP] = frame;
        c->r[CPU_SP] = (uint16_t)(c->r[CPU_SP] - alloc);
        break;
    }
    case 0xC9: /* LEAVE */
        c->r[CPU_SP] = c->r[CPU_BP];
        c->r[CPU_BP] = cpu86_pop16(c);
        break;

    /* ---- interrupts ------------------------------------------------------- */
    case 0xCC: cpu86_interrupt(c, 3); break;
    case 0xCD:
        c->last_int_cs = c->s[CPU_CS];
        c->last_int_ip = c->insn_ip;
        cpu86_interrupt(c, fetch8(c));
        break;
    case 0xCE: if (c->flags & F_OF) cpu86_interrupt(c, 4); break;
    case 0xCF: /* IRET */
        c->ip        = cpu86_pop16(c);
        c->s[CPU_CS] = cpu86_pop16(c);
        c->flags     = (uint16_t)((cpu86_pop16(c) & F_MODIFIABLE) | F_ALWAYS_SET);
        break;

    case 0xD4: { /* AAM */
        uint8_t base = fetch8(c);
        if (base == 0) { cpu86_interrupt(c, 0); break; }
        alu_aam(c, base);
        break;
    }
    case 0xD5: alu_aad(c, fetch8(c)); break;
    case 0xD6: /* SALC, undocumented: AL = CF ? 0xFF : 0x00 */
        cpu_set_r8(c, CPU_AL, (c->flags & F_CF) ? 0xFF : 0x00);
        break;
    case 0xD7: /* XLAT */
        cpu_set_r8(c, CPU_AL,
                   seg_r8(data_seg(c),
                          (uint16_t)(c->r[CPU_BX] + cpu_get_r8(c, CPU_AL))));
        break;

    /* ---- loops ------------------------------------------------------------ */
    case 0xE0: case 0xE1: case 0xE2: {
        int8_t rel = (int8_t)fetch8(c);
        uint16_t cx = (uint16_t)(c->r[CPU_CX] - 1);
        int take;
        c->r[CPU_CX] = cx;
        if      (op == 0xE0) take = (cx != 0) && !(c->flags & F_ZF);  /* LOOPNZ */
        else if (op == 0xE1) take = (cx != 0) &&  (c->flags & F_ZF);  /* LOOPZ  */
        else                 take = (cx != 0);                        /* LOOP   */
        if (take) c->ip = (uint16_t)(c->ip + rel);
        break;
    }
    case 0xE3: { /* JCXZ */
        int8_t rel = (int8_t)fetch8(c);
        if (c->r[CPU_CX] == 0) c->ip = (uint16_t)(c->ip + rel);
        break;
    }

    /* ---- port I/O ---------------------------------------------------------- */
    case 0xE4: cpu_set_r8(c, CPU_AL, cpu86_port_in8(c, fetch8(c))); break;
    case 0xE5: c->r[CPU_AX] = cpu86_port_in16(c, fetch8(c)); break;
    case 0xE6: { uint16_t p = fetch8(c); cpu86_port_out8(c, p, cpu_get_r8(c, CPU_AL)); break; }
    case 0xE7: { uint16_t p = fetch8(c); cpu86_port_out16(c, p, c->r[CPU_AX]); break; }
    case 0xEC: cpu_set_r8(c, CPU_AL, cpu86_port_in8(c, c->r[CPU_DX])); break;
    case 0xED: c->r[CPU_AX] = cpu86_port_in16(c, c->r[CPU_DX]); break;
    case 0xEE: cpu86_port_out8(c, c->r[CPU_DX], cpu_get_r8(c, CPU_AL)); break;
    case 0xEF: cpu86_port_out16(c, c->r[CPU_DX], c->r[CPU_AX]); break;

    /* ---- jumps and calls ---------------------------------------------------- */
    case 0xE8: { int16_t rel = (int16_t)fetch16(c);
                 cpu86_push16(c, c->ip);
                 c->ip = (uint16_t)(c->ip + rel); break; }
    case 0xE9: { int16_t rel = (int16_t)fetch16(c);
                 c->ip = (uint16_t)(c->ip + rel); break; }
    case 0xEA: { uint16_t off = fetch16(c), seg = fetch16(c);
                 c->ip = off; c->s[CPU_CS] = seg; break; }
    case 0xEB: { int8_t rel = (int8_t)fetch8(c);
                 c->ip = (uint16_t)(c->ip + rel); break; }

    /* ---- flag ops and HLT ---------------------------------------------------- */
    case 0xF4: /* HLT */
        if (!cpu86_on_hlt(c, cpu_lin(c->s[CPU_CS], (uint16_t)(c->ip - 1)))) {
            c->halted = 1;
        }
        break;
    case 0xF5: c->flags ^= F_CF; break;
    case 0xF8: c->flags &= (uint16_t)~F_CF; break;
    case 0xF9: c->flags |= F_CF; break;
    case 0xFA: c->flags &= (uint16_t)~F_IF; break;
    case 0xFB: c->flags |= F_IF; c->inhibit_irq = 1; break;
    case 0xFC: c->flags &= (uint16_t)~F_DF; break;
    case 0xFD: c->flags |= F_DF; break;

    /* ---- group 3 ------------------------------------------------------------- */
    case 0xF6: {
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        switch (regf) {
        case 0: case 1: alu_op(c, ALU_AND, rm_r8(c, &m), fetch8(c), 8); break; /* TEST */
        case 2: rm_w8(c, &m, (uint8_t)~rm_r8(c, &m)); break;                   /* NOT */
        case 3: { uint8_t v = rm_r8(c, &m);
                  rm_w8(c, &m, alu_op(c, ALU_SUB, 0, v, 8)); break; }          /* NEG */
        case 4: alu_mul8(c, rm_r8(c, &m)); break;
        case 5: alu_imul8(c, rm_r8(c, &m)); break;
        case 6: if (!alu_div8(c, rm_r8(c, &m)))  cpu86_interrupt(c, 0); break;
        case 7: if (!alu_idiv8(c, rm_r8(c, &m))) cpu86_interrupt(c, 0); break;
        default: break;
        }
        break;
    }
    case 0xF7: {
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        switch (regf) {
        case 0: case 1: alu_op(c, ALU_AND, rm_r16(c, &m), fetch16(c), 16); break;
        case 2: rm_w16(c, &m, (uint16_t)~rm_r16(c, &m)); break;
        case 3: { uint16_t v = rm_r16(c, &m);
                  rm_w16(c, &m, alu_op(c, ALU_SUB, 0, v, 16)); break; }
        case 4: alu_mul16(c, rm_r16(c, &m)); break;
        case 5: alu_imul16(c, rm_r16(c, &m)); break;
        case 6: if (!alu_div16(c, rm_r16(c, &m)))  cpu86_interrupt(c, 0); break;
        case 7: if (!alu_idiv16(c, rm_r16(c, &m))) cpu86_interrupt(c, 0); break;
        default: break;
        }
        break;
    }

    /* ---- group 4 / 5 ---------------------------------------------------------- */
    case 0xFE: {
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        if (regf == 0)      rm_w8(c, &m, (uint8_t)alu_inc(c, rm_r8(c, &m), 8));
        else if (regf == 1) rm_w8(c, &m, (uint8_t)alu_dec(c, rm_r8(c, &m), 8));
        else { c->fault = CPU_FAULT_BAD_OPCODE; c->fault_addr = lin; }
        break;
    }
    case 0xFF: {
        modrm = fetch8(c); m = decode_modrm(c, modrm, &regf);
        switch (regf) {
        case 0: rm_w16(c, &m, alu_inc(c, rm_r16(c, &m), 16)); break;
        case 1: rm_w16(c, &m, alu_dec(c, rm_r16(c, &m), 16)); break;
        case 2: { uint16_t t = rm_r16(c, &m);                    /* CALL near rm */
                  cpu86_push16(c, c->ip); c->ip = t; break; }
        case 3: { uint16_t o, s;                                  /* CALL far [mem] */
                  if (m.is_reg) { c->fault = CPU_FAULT_BAD_OPCODE; c->fault_addr = lin; break; }
                  o = seg_r16(m.seg, m.off);
                  s = seg_r16(m.seg, (uint16_t)(m.off + 2));
                  cpu86_far_call(c, s, o); break; }
        case 4: c->ip = rm_r16(c, &m); break;                     /* JMP near rm */
        case 5: { uint16_t o, s;                                  /* JMP far [mem] */
                  if (m.is_reg) { c->fault = CPU_FAULT_BAD_OPCODE; c->fault_addr = lin; break; }
                  o = seg_r16(m.seg, m.off);
                  s = seg_r16(m.seg, (uint16_t)(m.off + 2));
                  c->ip = o; c->s[CPU_CS] = s; break; }
        case 6: cpu86_push16(c, rm_r16(c, &m)); break;            /* PUSH rm16 */
        default: c->fault = CPU_FAULT_BAD_OPCODE; c->fault_addr = lin; break;
        }
        break;
    }

    /* ---- everything else is loud ----------------------------------------------- */
    default:
        c->fault = CPU_FAULT_BAD_OPCODE;
        c->fault_addr = lin;
        c->ip = c->insn_ip;   /* leave IP at the offending instruction */
        break;
    }
}

/* ------------------------------------------------------------------ */
/* Run loop                                                            */
/* ------------------------------------------------------------------ */
uint64_t cpu86_run(cpu86 *c, uint64_t cycles) {
    uint64_t start = c->cycles;
    c->budget = c->cycles + cycles;

    while (c->cycles < c->budget) {
        if (c->fault || c->halted || c->yield_request) break;
        cpu86_step(c);
    }
    return c->cycles - start;
}
