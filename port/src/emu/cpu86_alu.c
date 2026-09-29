/*
 * cpu86_alu.c — flag-producing arithmetic for the 8086 core.
 * See cpu86_alu.h for why flags are eager.
 */
#include "cpu86_alu.h"

/* Parity of the LOW BYTE only — that is what the 8086 computes, for both
 * 8- and 16-bit results. */
const uint8_t cpu_parity_table[256] = {
    1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1, 0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0,
    0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0, 1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1,
    0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0, 1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1,
    1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1, 0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0,
    0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0, 1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1,
    1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1, 0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0,
    1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1, 0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0,
    0,1,1,0,1,0,0,1, 1,0,0,1,0,1,1,0, 1,0,0,1,0,1,1,0, 0,1,1,0,1,0,0,1,
};

#define SIGN_BIT(w)  ((w) == 8 ? 0x80u   : 0x8000u)
#define MASK(w)      ((w) == 8 ? 0xFFu   : 0xFFFFu)

static inline void set_flag(cpu86 *c, uint16_t f, int on) {
    if (on) c->flags |= f; else c->flags &= (uint16_t)~f;
}

void alu_set_szp(cpu86 *c, uint32_t r, int w) {
    uint32_t m = MASK(w);
    set_flag(c, F_ZF, (r & m) == 0);
    set_flag(c, F_SF, (r & SIGN_BIT(w)) != 0);
    set_flag(c, F_PF, cpu_parity_table[r & 0xFF]);
}

uint16_t alu_op(cpu86 *c, int op, uint16_t a, uint16_t b, int w) {
    uint32_t m = MASK(w), sb = SIGN_BIT(w);
    uint32_t r = 0;
    uint32_t carry_in;

    switch (op) {
    case ALU_ADD:
    case ALU_ADC:
        carry_in = (op == ALU_ADC && (c->flags & F_CF)) ? 1u : 0u;
        r = (uint32_t)a + (uint32_t)b + carry_in;
        set_flag(c, F_CF, (r & ~m) != 0);
        set_flag(c, F_AF, (((a ^ b ^ r) & 0x10u) != 0));
        set_flag(c, F_OF, ((~(a ^ b) & (a ^ r) & sb) != 0));
        alu_set_szp(c, r, w);
        break;

    case ALU_SUB:
    case ALU_SBB:
    case ALU_CMP:
        carry_in = (op == ALU_SBB && (c->flags & F_CF)) ? 1u : 0u;
        r = (uint32_t)a - (uint32_t)b - carry_in;
        set_flag(c, F_CF, (r & ~m) != 0);
        set_flag(c, F_AF, (((a ^ b ^ r) & 0x10u) != 0));
        set_flag(c, F_OF, (((a ^ b) & (a ^ r) & sb) != 0));
        alu_set_szp(c, r, w);
        break;

    case ALU_OR:  r = (uint32_t)a | b; goto logic;
    case ALU_AND: r = (uint32_t)a & b; goto logic;
    case ALU_XOR: r = (uint32_t)a ^ b; goto logic;
    logic:
        /* Logic ops clear CF and OF; AF is documented undefined and the
         * 8086 clears it in practice. */
        c->flags &= (uint16_t)~(F_CF | F_OF | F_AF);
        alu_set_szp(c, r, w);
        break;

    default:
        break;
    }
    return (uint16_t)(r & m);
}

uint16_t alu_inc(cpu86 *c, uint16_t a, int w) {
    uint32_t m = MASK(w), sb = SIGN_BIT(w);
    uint32_t r = (uint32_t)a + 1u;
    /* CF is deliberately preserved — that is the whole point of INC. */
    set_flag(c, F_AF, ((a & 0x0Fu) == 0x0Fu));
    set_flag(c, F_OF, ((uint32_t)a & m) == (sb - 1u));
    alu_set_szp(c, r, w);
    return (uint16_t)(r & m);
}

uint16_t alu_dec(cpu86 *c, uint16_t a, int w) {
    uint32_t m = MASK(w), sb = SIGN_BIT(w);
    uint32_t r = (uint32_t)a - 1u;
    set_flag(c, F_AF, ((a & 0x0Fu) == 0u));
    set_flag(c, F_OF, ((uint32_t)a & m) == sb);
    alu_set_szp(c, r, w);
    return (uint16_t)(r & m);
}

uint16_t alu_shift(cpu86 *c, int op, uint16_t v, uint8_t count, int w) {
    uint32_t m = MASK(w), sb = SIGN_BIT(w);
    uint32_t bits = (w == 8) ? 8u : 16u;
    uint32_t r = v & m;
    uint32_t cf;
    uint8_t n;

    /*
     * The 80186 and later mask the count to 5 bits; the 8086 does not. We
     * mask, both because we implement the 186 set and because it makes a
     * pathological `shl ax, 200` bounded. Counts in this game are small, so
     * the distinction is not observable.
     */
    n = (uint8_t)(count & 0x1Fu);

    /* A zero count leaves EVERY flag unchanged. This is real, observable
     * 8086 behaviour and a classic source of bugs. */
    if (n == 0) return (uint16_t)r;

    switch (op) {
    case SH_ROL:
        for (uint8_t i = 0; i < n; i++) {
            cf = (r & sb) ? 1u : 0u;
            r = ((r << 1) | cf) & m;
        }
        set_flag(c, F_CF, (r & 1u) != 0);
        set_flag(c, F_OF, (((r & sb) != 0) ^ ((c->flags & F_CF) != 0)));
        break;

    case SH_ROR:
        for (uint8_t i = 0; i < n; i++) {
            cf = r & 1u;
            r = ((r >> 1) | (cf ? sb : 0u)) & m;
        }
        set_flag(c, F_CF, (r & sb) != 0);
        /* OF = xor of the top two result bits. */
        set_flag(c, F_OF, (((r & sb) != 0) ^ ((r & (sb >> 1)) != 0)));
        break;

    case SH_RCL:
        for (uint8_t i = 0; i < n; i++) {
            cf = (c->flags & F_CF) ? 1u : 0u;
            set_flag(c, F_CF, (r & sb) != 0);
            r = ((r << 1) | cf) & m;
        }
        set_flag(c, F_OF, (((r & sb) != 0) ^ ((c->flags & F_CF) != 0)));
        break;

    case SH_RCR:
        for (uint8_t i = 0; i < n; i++) {
            cf = (c->flags & F_CF) ? 1u : 0u;
            set_flag(c, F_CF, (r & 1u) != 0);
            r = ((r >> 1) | (cf ? sb : 0u)) & m;
        }
        set_flag(c, F_OF, (((r & sb) != 0) ^ ((r & (sb >> 1)) != 0)));
        break;

    case SH_SHL:
    case SH_SAL6:  /* reg field 6 is an undocumented alias for SHL */
        if (n <= bits) {
            cf = (n == 0) ? 0u : ((r >> (bits - n)) & 1u);
            set_flag(c, F_CF, cf != 0);
        } else {
            set_flag(c, F_CF, 0);
        }
        r = (r << n) & m;
        set_flag(c, F_OF, (((r & sb) != 0) ^ ((c->flags & F_CF) != 0)));
        set_flag(c, F_AF, 0);
        alu_set_szp(c, r, w);
        break;

    case SH_SHR:
        if (n <= bits) {
            cf = (r >> (n - 1)) & 1u;
            set_flag(c, F_CF, cf != 0);
        } else {
            set_flag(c, F_CF, 0);
        }
        /* OF after SHR is the sign of the ORIGINAL operand. */
        set_flag(c, F_OF, ((v & sb) != 0));
        r = (n >= bits) ? 0u : ((r >> n) & m);
        set_flag(c, F_AF, 0);
        alu_set_szp(c, r, w);
        break;

    case SH_SAR: {
        uint32_t sign = (r & sb) ? 1u : 0u;
        if (n >= bits) {
            set_flag(c, F_CF, sign != 0);
            r = sign ? m : 0u;
        } else {
            set_flag(c, F_CF, ((r >> (n - 1)) & 1u) != 0);
            r = (r >> n) & m;
            if (sign) r |= (m << (bits - n)) & m;
        }
        set_flag(c, F_OF, 0);
        set_flag(c, F_AF, 0);
        alu_set_szp(c, r, w);
        break;
    }
    default:
        break;
    }
    return (uint16_t)(r & m);
}

/* ------------------------------------------------------------------ */
/* Multiply / divide                                                    */
/* ------------------------------------------------------------------ */

void alu_mul8(cpu86 *c, uint8_t src) {
    uint16_t res = (uint16_t)(cpu_get_r8(c, CPU_AL) * (uint16_t)src);
    c->r[CPU_AX] = res;
    /* SF/ZF/AF/PF are documented undefined; the 8086 sets SZP from the
     * result, which some code relies on. */
    set_flag(c, F_CF, (res >> 8) != 0);
    set_flag(c, F_OF, (res >> 8) != 0);
    alu_set_szp(c, res, 16);
}

void alu_mul16(cpu86 *c, uint16_t src) {
    uint32_t res = (uint32_t)c->r[CPU_AX] * (uint32_t)src;
    c->r[CPU_AX] = (uint16_t)(res & 0xFFFF);
    c->r[CPU_DX] = (uint16_t)(res >> 16);
    set_flag(c, F_CF, c->r[CPU_DX] != 0);
    set_flag(c, F_OF, c->r[CPU_DX] != 0);
    alu_set_szp(c, res & 0xFFFF, 16);
}

void alu_imul8(cpu86 *c, uint8_t src) {
    int16_t res = (int16_t)((int8_t)cpu_get_r8(c, CPU_AL) * (int8_t)src);
    c->r[CPU_AX] = (uint16_t)res;
    /* CF/OF set when the result does not sign-extend from AL. */
    int over = (res > 127 || res < -128);
    set_flag(c, F_CF, over);
    set_flag(c, F_OF, over);
    alu_set_szp(c, (uint16_t)res, 16);
}

void alu_imul16(cpu86 *c, uint16_t src) {
    int32_t res = (int32_t)(int16_t)c->r[CPU_AX] * (int32_t)(int16_t)src;
    c->r[CPU_AX] = (uint16_t)(res & 0xFFFF);
    c->r[CPU_DX] = (uint16_t)((uint32_t)res >> 16);
    int over = (res > 32767 || res < -32768);
    set_flag(c, F_CF, over);
    set_flag(c, F_OF, over);
    alu_set_szp(c, (uint32_t)res & 0xFFFF, 16);
}

uint16_t alu_imul16_imm(cpu86 *c, uint16_t a, uint16_t b) {
    int32_t res = (int32_t)(int16_t)a * (int32_t)(int16_t)b;
    int over = (res > 32767 || res < -32768);
    set_flag(c, F_CF, over);
    set_flag(c, F_OF, over);
    alu_set_szp(c, (uint32_t)res & 0xFFFF, 16);
    return (uint16_t)(res & 0xFFFF);
}

bool alu_div8(cpu86 *c, uint8_t src) {
    uint16_t num = c->r[CPU_AX];
    uint16_t q;
    if (src == 0) return false;
    q = (uint16_t)(num / src);
    if (q > 0xFF) return false;
    cpu_set_r8(c, CPU_AL, (uint8_t)q);
    cpu_set_r8(c, CPU_AH, (uint8_t)(num % src));
    return true;
}

bool alu_div16(cpu86 *c, uint16_t src) {
    uint32_t num = ((uint32_t)c->r[CPU_DX] << 16) | c->r[CPU_AX];
    uint32_t q;
    if (src == 0) return false;
    q = num / src;
    if (q > 0xFFFF) return false;
    c->r[CPU_AX] = (uint16_t)q;
    c->r[CPU_DX] = (uint16_t)(num % src);
    return true;
}

bool alu_idiv8(cpu86 *c, uint8_t src) {
    int16_t num = (int16_t)c->r[CPU_AX];
    int16_t d = (int8_t)src;
    int16_t q;
    if (d == 0) return false;
    q = (int16_t)(num / d);
    if (q > 127 || q < -128) return false;
    cpu_set_r8(c, CPU_AL, (uint8_t)q);
    cpu_set_r8(c, CPU_AH, (uint8_t)(int8_t)(num % d));
    return true;
}

bool alu_idiv16(cpu86 *c, uint16_t src) {
    int32_t num = (int32_t)(((uint32_t)c->r[CPU_DX] << 16) | c->r[CPU_AX]);
    int32_t d = (int16_t)src;
    int32_t q;
    if (d == 0) return false;
    q = num / d;
    if (q > 32767 || q < -32768) return false;
    c->r[CPU_AX] = (uint16_t)q;
    c->r[CPU_DX] = (uint16_t)(int16_t)(num % d);
    return true;
}

/* ------------------------------------------------------------------ */
/* BCD adjusts                                                          */
/* ------------------------------------------------------------------ */

void alu_daa(cpu86 *c) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    uint8_t old_al = al;
    int old_cf = (c->flags & F_CF) != 0;
    int cf = 0;

    if ((al & 0x0F) > 9 || (c->flags & F_AF)) {
        al = (uint8_t)(al + 6);
        cf = old_cf || (al < old_al);
        set_flag(c, F_AF, 1);
    } else {
        set_flag(c, F_AF, 0);
    }
    if (old_al > 0x99 || old_cf) {
        al = (uint8_t)(al + 0x60);
        cf = 1;
    }
    cpu_set_r8(c, CPU_AL, al);
    set_flag(c, F_CF, cf);
    alu_set_szp(c, al, 8);
}

void alu_das(cpu86 *c) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    uint8_t old_al = al;
    int old_cf = (c->flags & F_CF) != 0;
    int cf = 0;

    if ((al & 0x0F) > 9 || (c->flags & F_AF)) {
        al = (uint8_t)(al - 6);
        cf = old_cf || (old_al < 6);
        set_flag(c, F_AF, 1);
    } else {
        set_flag(c, F_AF, 0);
    }
    if (old_al > 0x99 || old_cf) {
        al = (uint8_t)(al - 0x60);
        cf = 1;
    }
    cpu_set_r8(c, CPU_AL, al);
    set_flag(c, F_CF, cf);
    alu_set_szp(c, al, 8);
}

void alu_aaa(cpu86 *c) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    if ((al & 0x0F) > 9 || (c->flags & F_AF)) {
        cpu_set_r8(c, CPU_AL, (uint8_t)((al + 6) & 0x0F));
        cpu_set_r8(c, CPU_AH, (uint8_t)(cpu_get_r8(c, CPU_AH) + 1));
        set_flag(c, F_AF, 1);
        set_flag(c, F_CF, 1);
    } else {
        cpu_set_r8(c, CPU_AL, (uint8_t)(al & 0x0F));
        set_flag(c, F_AF, 0);
        set_flag(c, F_CF, 0);
    }
    alu_set_szp(c, cpu_get_r8(c, CPU_AL), 8);
}

void alu_aas(cpu86 *c) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    if ((al & 0x0F) > 9 || (c->flags & F_AF)) {
        cpu_set_r8(c, CPU_AL, (uint8_t)((al - 6) & 0x0F));
        cpu_set_r8(c, CPU_AH, (uint8_t)(cpu_get_r8(c, CPU_AH) - 1));
        set_flag(c, F_AF, 1);
        set_flag(c, F_CF, 1);
    } else {
        cpu_set_r8(c, CPU_AL, (uint8_t)(al & 0x0F));
        set_flag(c, F_AF, 0);
        set_flag(c, F_CF, 0);
    }
    alu_set_szp(c, cpu_get_r8(c, CPU_AL), 8);
}

void alu_aam(cpu86 *c, uint8_t base) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    cpu_set_r8(c, CPU_AH, (uint8_t)(al / base));
    cpu_set_r8(c, CPU_AL, (uint8_t)(al % base));
    alu_set_szp(c, cpu_get_r8(c, CPU_AL), 8);
}

void alu_aad(cpu86 *c, uint8_t base) {
    uint8_t al = cpu_get_r8(c, CPU_AL);
    uint8_t ah = cpu_get_r8(c, CPU_AH);
    uint8_t r = (uint8_t)(al + ah * base);
    cpu_set_r8(c, CPU_AL, r);
    cpu_set_r8(c, CPU_AH, 0);
    alu_set_szp(c, r, 8);
}
