/*
 * cpu86_alu.h — flag-producing arithmetic for the 8086 core.
 *
 * WHY EAGER FLAGS
 *
 * Lazy flags (store operands + operation, materialise on demand) are the
 * standard x86-interpreter optimisation and the wrong choice for this port:
 *
 *  - The workload does not need it. The game targeted a 386/25-486; we need
 *    roughly 4M instructions/sec and an eager C interpreter sustains 50-150M
 *    on modern hardware. There is over an order of magnitude of headroom, so
 *    the optimisation buys nothing observable.
 *  - Lazy flags are the richest bug source in hand-written x86 cores, and
 *    their failures present as "the game hangs 40 minutes in" rather than as
 *    a failing test.
 *  - The retail code uses pushf/popf (nine complete functions), lahf/sahf,
 *    and the BCD adjusts. Every one of those forces materialisation anyway,
 *    and each is a place a lazy scheme gets AF or PF subtly wrong.
 *  - Debuggability: the tracer can print a true FLAGS word at every
 *    instruction for free, so traced and untraced runs cannot diverge.
 *
 * UNDEFINED FLAGS ARE PINNED, NOT LEFT TO CHANCE. Where the manual says
 * "undefined" we implement documented 8086 behaviour and note it at the call
 * site. The one that genuinely bites is shift/rotate by CL == 0, which must
 * leave ALL flags unchanged.
 */
#ifndef EMU_CPU86_ALU_H
#define EMU_CPU86_ALU_H

#include "cpu86.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ALU operation selectors; values match the 8086 reg-field encoding for the
 * 0x00-0x3F group and the 0x80-0x83 group, so they decode directly. */
enum { ALU_ADD = 0, ALU_OR, ALU_ADC, ALU_SBB, ALU_AND, ALU_SUB, ALU_XOR, ALU_CMP };

/* Shift/rotate selectors, matching the 0xD0-0xD3 reg field. */
enum { SH_ROL = 0, SH_ROR, SH_RCL, SH_RCR, SH_SHL, SH_SHR, SH_SAL6, SH_SAR };

extern const uint8_t cpu_parity_table[256];

/* Set SF/ZF/PF from a result of width `w` (8 or 16). */
void alu_set_szp(cpu86 *c, uint32_t r, int w);

/* Core ALU. Returns the result; CMP returns the difference but the caller
 * must discard it. Width `w` is 8 or 16. */
uint16_t alu_op(cpu86 *c, int op, uint16_t a, uint16_t b, int w);

/* INC/DEC preserve CF, which is why they are not ALU_ADD/ALU_SUB. */
uint16_t alu_inc(cpu86 *c, uint16_t a, int w);
uint16_t alu_dec(cpu86 *c, uint16_t a, int w);

/* Shifts and rotates. A count of 0 leaves every flag untouched. */
uint16_t alu_shift(cpu86 *c, int op, uint16_t v, uint8_t count, int w);

/* Multiply / divide. The divide helpers return false on a divide error, in
 * which case the caller must raise INT 0 without having modified state. */
void alu_mul8(cpu86 *c, uint8_t src);
void alu_mul16(cpu86 *c, uint16_t src);
void alu_imul8(cpu86 *c, uint8_t src);
void alu_imul16(cpu86 *c, uint16_t src);
bool alu_div8(cpu86 *c, uint8_t src);
bool alu_div16(cpu86 *c, uint16_t src);
bool alu_idiv8(cpu86 *c, uint8_t src);
bool alu_idiv16(cpu86 *c, uint16_t src);

/* 80186 three-operand IMUL: returns the truncated 16-bit product and sets
 * CF/OF when the full result does not fit. */
uint16_t alu_imul16_imm(cpu86 *c, uint16_t a, uint16_t b);

/* BCD adjusts. */
void alu_daa(cpu86 *c);
void alu_das(cpu86 *c);
void alu_aaa(cpu86 *c);
void alu_aas(cpu86 *c);
void alu_aam(cpu86 *c, uint8_t base);   /* caller raises INT 0 if base == 0 */
void alu_aad(cpu86 *c, uint8_t base);

#ifdef __cplusplus
}
#endif

#endif /* EMU_CPU86_ALU_H */
