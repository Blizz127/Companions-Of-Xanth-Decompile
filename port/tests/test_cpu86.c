/*
 * test_cpu86.c — conformance suite for the 8086/80186 core.
 *
 * Links WITHOUT SDL by design, so it runs in asset-free CI.
 *
 * The emphasis is deliberately on the cases that produce bugs with DISTANT
 * symptoms — undefined-flag behaviour, shift-by-zero, AF, the 8086 segment
 * and offset wraparound rules, REP semantics, and the interrupt-inhibit rule
 * after a segment load. A core that gets ADD right and these wrong will run
 * for forty minutes and then hang somewhere unrelated.
 */
#include "cpu86_alu.h"
#include "vm.h"
#include <stdio.h>
#include <string.h>

static int g_checks, g_fails;

#define CHECK(cond, fmt, ...)                                                  \
    do {                                                                       \
        g_checks++;                                                            \
        if (!(cond)) {                                                         \
            g_fails++;                                                         \
            printf("  FAIL %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
        }                                                                      \
    } while (0)

#define CHECK_EQ(actual, expect, what)                                         \
    do {                                                                       \
        unsigned long _a = (unsigned long)(actual);                            \
        unsigned long _e = (unsigned long)(expect);                            \
        g_checks++;                                                            \
        if (_a != _e) {                                                        \
            g_fails++;                                                         \
            printf("  FAIL %s:%d: %s = 0x%lX, expected 0x%lX\n",               \
                   __FILE__, __LINE__, (what), _a, _e);                        \
        }                                                                      \
    } while (0)

/* ------------------------------------------------------------------ */
/* Harness: assemble a byte sequence at 0x1000:0000 and run it.        */
/* ------------------------------------------------------------------ */
#define CODE_SEG 0x1000
#define STACK_SEG 0x2000
#define DATA_SEG 0x3000

static cpu86 C;

static void load(const uint8_t *code, size_t n) {
    memset(g_dos_mem, 0, DOS_MEM_SIZE);
    /* Pad the code segment with HLT so that a test which runs "plenty of"
     * instructions stops at the end of its program instead of wandering into
     * zero bytes (which decode as `add [bx+si],al` and quietly clobber the
     * flags the test is about to assert on). */
    memset(g_dos_mem + CODE_SEG * 16, 0xF4, 256);
    cpu86_reset(&C);
    C.s[CPU_CS] = CODE_SEG;
    C.s[CPU_DS] = DATA_SEG;
    C.s[CPU_ES] = DATA_SEG;
    C.s[CPU_SS] = STACK_SEG;
    C.r[CPU_SP] = 0xFFF0;
    C.ip = 0;
    memcpy(g_dos_mem + CODE_SEG * 16, code, n);
}

static void run_n(int insns) {
    for (int i = 0; i < insns && !C.fault && !C.halted; i++) cpu86_step(&C);
}

#define LOAD_RUN(arr, n) do { load((arr), sizeof(arr)); run_n(n); } while (0)

static int flag(uint16_t f) { return (C.flags & f) != 0; }

/* ------------------------------------------------------------------ */
static void test_alu_flags(void) {
    printf("alu flags\n");

    /* ADD 0x7FFF + 1 -> signed overflow, no carry. */
    {
        uint8_t code[] = { 0xB8,0xFF,0x7F, 0x83,0xC0,0x01 };  /* mov ax,7FFF; add ax,1 */
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x8000, "ax");
        CHECK(flag(F_OF), "OF must be set on 7FFF+1");
        CHECK(!flag(F_CF), "CF must be clear on 7FFF+1");
        CHECK(flag(F_SF), "SF must be set");
        CHECK(!flag(F_ZF), "ZF must be clear");
        CHECK(flag(F_AF), "AF must be set (0xF + 1 carries out of bit 3)");
    }

    /* ADD 0xFFFF + 1 -> carry, no signed overflow, zero result. */
    {
        uint8_t code[] = { 0xB8,0xFF,0xFF, 0x83,0xC0,0x01 };
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x0000, "ax");
        CHECK(flag(F_CF), "CF must be set on FFFF+1");
        CHECK(!flag(F_OF), "OF must be clear on FFFF+1");
        CHECK(flag(F_ZF), "ZF must be set");
    }

    /* SUB 0x8000 - 1 -> signed overflow. */
    {
        uint8_t code[] = { 0xB8,0x00,0x80, 0x83,0xE8,0x01 };
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x7FFF, "ax");
        CHECK(flag(F_OF), "OF must be set on 8000-1");
        CHECK(!flag(F_CF), "CF must be clear on 8000-1");
    }

    /* Logic ops clear CF and OF. */
    {
        uint8_t code[] = { 0xF9, 0xB8,0xFF,0xFF, 0x25,0x0F,0x00 }; /* stc; mov ax,FFFF; and ax,0F */
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 0x000F, "ax");
        CHECK(!flag(F_CF), "AND must clear CF even if STC set it");
        CHECK(!flag(F_OF), "AND must clear OF");
        CHECK(flag(F_PF), "PF set: 0x0F has four one-bits");
    }

    /* INC must PRESERVE CF — this is the whole reason it is not ADD 1. */
    {
        uint8_t code[] = { 0xF9, 0xB8,0x05,0x00, 0x40 };  /* stc; mov ax,5; inc ax */
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 6, "ax");
        CHECK(flag(F_CF), "INC must preserve CF");
    }

    /* Parity is computed from the LOW BYTE only, even for 16-bit results. */
    {
        uint8_t code[] = { 0xB8,0xFF,0x01, 0x05,0x00,0x01 }; /* mov ax,1FF; add ax,100 */
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x02FF, "ax");
        CHECK(flag(F_PF), "PF from low byte 0xFF (eight one-bits, even)");
    }
}

/* ------------------------------------------------------------------ */
static void test_shifts(void) {
    printf("shifts and rotates\n");

    /* THE important one: a shift by CL == 0 must leave every flag alone. */
    {
        uint8_t code[] = {
            0xF9,                    /* stc                      */
            0xB8,0x34,0x12,          /* mov ax,1234h             */
            0xB1,0x00,               /* mov cl,0                 */
            0xD3,0xE0                /* shl ax,cl                */
        };
        LOAD_RUN(code, 4);
        CHECK_EQ(C.r[CPU_AX], 0x1234, "ax unchanged");
        CHECK(flag(F_CF), "shift by CL=0 must leave CF untouched");
    }

    /* SHL sets CF from the last bit shifted out. */
    {
        uint8_t code[] = { 0xB8,0x00,0x80, 0xD1,0xE0 };  /* mov ax,8000; shl ax,1 */
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x0000, "ax");
        CHECK(flag(F_CF), "CF from bit shifted out");
        CHECK(flag(F_ZF), "ZF set");
    }

    /* SAR sign-extends. */
    {
        uint8_t code[] = { 0xB8,0x00,0x80, 0xC1,0xF8,0x04 }; /* mov ax,8000; sar ax,4 */
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0xF800, "sar must sign-extend");
        CHECK(!flag(F_OF), "SAR clears OF");
    }

    /* SHR is a logical shift. */
    {
        uint8_t code[] = { 0xB8,0x00,0x80, 0xC1,0xE8,0x04 };
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0x0800, "shr must zero-fill");
    }

    /* RCL rotates through carry: 9 bits for a byte. */
    {
        uint8_t code[] = { 0xF9, 0xB0,0x00, 0xD0,0xD0 };  /* stc; mov al,0; rcl al,1 */
        LOAD_RUN(code, 3);
        CHECK_EQ(cpu_get_r8(&C, CPU_AL), 0x01, "carry rotated into bit 0");
        CHECK(!flag(F_CF), "CF now holds the old bit 7 (0)");
    }
}

/* ------------------------------------------------------------------ */
static void test_muldiv(void) {
    printf("multiply and divide\n");

    { /* MUL 16: CF/OF reflect a non-zero high half. */
        uint8_t code[] = { 0xB8,0x00,0x10, 0xBB,0x00,0x10, 0xF7,0xE3 };
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 0x0000, "low");
        CHECK_EQ(C.r[CPU_DX], 0x0100, "high");
        CHECK(flag(F_CF) && flag(F_OF), "CF/OF set when DX != 0");
    }

    { /* IMUL 8 negative. */
        uint8_t code[] = { 0xB0,0xFF, 0xB3,0x02, 0xF6,0xEB }; /* al=-1; bl=2; imul bl */
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 0xFFFE, "-1 * 2 == -2");
        CHECK(!flag(F_CF), "result fits in a byte, so CF clear");
    }

    { /* DIV by zero must raise INT 0 rather than trapping the host. */
        uint8_t code[] = { 0xB8,0x10,0x00, 0xB3,0x00, 0xF6,0xF3 };
        /* Point the INT 0 vector at a recognisable address. */
        load(code, sizeof(code));
        seg_w16(0, 0, 0xBEEF);
        seg_w16(0, 2, 0xC0DE);
        run_n(3);
        CHECK_EQ(C.s[CPU_CS], 0xC0DE, "divide error vectored via the IVT");
        CHECK_EQ(C.ip, 0xBEEF, "divide error entry offset");
        CHECK(!C.fault, "a divide error is an interrupt, not a host fault");
    }

    { /* Quotient overflow is also a divide error. */
        uint8_t code[] = { 0xB8,0x00,0xFF, 0xB3,0x01, 0xF6,0xF3 }; /* ax=FF00 / 1 > 0xFF */
        load(code, sizeof(code));
        seg_w16(0, 0, 0x1234); seg_w16(0, 2, 0x5678);
        run_n(3);
        CHECK_EQ(C.s[CPU_CS], 0x5678, "quotient overflow vectors too");
    }
}

/* ------------------------------------------------------------------ */
static void test_memory_wrap(void) {
    printf("memory and segment wrap\n");

    /* A word read at offset 0xFFFF wraps to offset 0 of the SAME segment. */
    {
        uint8_t code[] = { 0xA1,0xFF,0xFF };   /* mov ax,[FFFF] */
        load(code, sizeof(code));
        seg_w8(DATA_SEG, 0xFFFF, 0xAA);
        seg_w8(DATA_SEG, 0x0000, 0xBB);
        run_n(1);
        CHECK_EQ(C.r[CPU_AX], 0xBBAA, "word at FFFF wraps within the segment");
    }

    /* Linear addressing wraps at 1 MB. */
    {
        CHECK_EQ(cpu_lin(0xFFFF, 0x0010), 0x00000, "FFFF:0010 wraps to 0");
        CHECK_EQ(cpu_lin(0xF000, 0xFFFF), 0xFFFFF, "top of memory");
    }

    /* Segment override is honoured, and the BP default is SS. */
    {
        uint8_t code[] = { 0xBD,0x10,0x00, 0x8B,0x46,0x00 };  /* mov bp,10; mov ax,[bp] */
        load(code, sizeof(code));
        seg_w16(STACK_SEG, 0x10, 0x1111);
        seg_w16(DATA_SEG,  0x10, 0x2222);
        run_n(2);
        CHECK_EQ(C.r[CPU_AX], 0x1111, "[bp] defaults to SS, not DS");
    }
    {
        uint8_t code[] = { 0xBD,0x10,0x00, 0x3E,0x8B,0x46,0x00 }; /* ds: mov ax,[bp] */
        load(code, sizeof(code));
        seg_w16(STACK_SEG, 0x10, 0x1111);
        seg_w16(DATA_SEG,  0x10, 0x2222);
        run_n(2);
        CHECK_EQ(C.r[CPU_AX], 0x2222, "DS override beats the SS default");
    }

    /* LEA computes an address and must not touch memory or apply a segment. */
    {
        uint8_t code[] = { 0xBB,0x10,0x00, 0xBE,0x05,0x00, 0x8D,0x00 }; /* lea ax,[bx+si] */
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 0x15, "lea computes bx+si");
    }
}

/* ------------------------------------------------------------------ */
static void test_string_ops(void) {
    printf("string operations\n");

    /* REP MOVSW forward. */
    {
        uint8_t code[] = { 0xFC, 0xF3,0xA5 };  /* cld; rep movsw */
        load(code, sizeof(code));
        C.r[CPU_CX] = 4;
        C.r[CPU_SI] = 0x100;
        C.r[CPU_DI] = 0x200;
        for (int i = 0; i < 4; i++) seg_w16(DATA_SEG, (uint16_t)(0x100 + i * 2), (uint16_t)(0xA000 + i));
        run_n(64);
        for (int i = 0; i < 4; i++)
            CHECK_EQ(seg_r16(DATA_SEG, (uint16_t)(0x200 + i * 2)), 0xA000 + i, "copied word");
        CHECK_EQ(C.r[CPU_CX], 0, "CX exhausted");
        CHECK_EQ(C.r[CPU_SI], 0x108, "SI advanced by 8");
        CHECK_EQ(C.r[CPU_DI], 0x208, "DI advanced by 8");
    }

    /* DF=1 walks backwards. */
    {
        uint8_t code[] = { 0xFD, 0xF3,0xA4 };  /* std; rep movsb */
        load(code, sizeof(code));
        C.r[CPU_CX] = 3;
        C.r[CPU_SI] = 0x102;
        C.r[CPU_DI] = 0x202;
        seg_w8(DATA_SEG, 0x100, 1); seg_w8(DATA_SEG, 0x101, 2); seg_w8(DATA_SEG, 0x102, 3);
        run_n(64);
        CHECK_EQ(seg_r8(DATA_SEG, 0x200), 1, "backward copy byte 0");
        CHECK_EQ(seg_r8(DATA_SEG, 0x202), 3, "backward copy byte 2");
    }

    /* REP with CX == 0 must do nothing at all. */
    {
        uint8_t code[] = { 0xFC, 0xF3,0xAA };  /* cld; rep stosb */
        load(code, sizeof(code));
        C.r[CPU_CX] = 0;
        C.r[CPU_DI] = 0x300;
        cpu_set_r8(&C, CPU_AL, 0x5A);
        run_n(8);
        CHECK_EQ(seg_r8(DATA_SEG, 0x300), 0x00, "rep with CX=0 writes nothing");
        CHECK_EQ(C.r[CPU_DI], 0x300, "and does not advance DI");
    }

    /* REPNE SCASB stops on a match and leaves CX/DI just past it. */
    {
        uint8_t code[] = { 0xFC, 0xF2,0xAE };  /* cld; repne scasb */
        load(code, sizeof(code));
        C.r[CPU_CX] = 8;
        C.r[CPU_DI] = 0x400;
        cpu_set_r8(&C, CPU_AL, 0x42);
        seg_w8(DATA_SEG, 0x402, 0x42);
        run_n(64);
        CHECK_EQ(C.r[CPU_DI], 0x403, "DI one past the match");
        CHECK_EQ(C.r[CPU_CX], 5, "CX decremented three times");
        CHECK(flag(F_ZF), "ZF set because the scan matched");
    }

    /* STOS writes through ES and ignores a segment override on the
     * destination — a classic place to get the segment wrong. */
    {
        uint8_t code[] = { 0xFC, 0xAA };
        load(code, sizeof(code));
        C.s[CPU_ES] = 0x4000;
        C.r[CPU_DI] = 0x10;
        cpu_set_r8(&C, CPU_AL, 0x77);
        run_n(2);
        CHECK_EQ(seg_r8(0x4000, 0x10), 0x77, "STOS targets ES");
    }
}

/* ------------------------------------------------------------------ */
static void test_control_flow(void) {
    printf("control flow\n");

    /* Far call then far return restores CS:IP and the stack. */
    {
        uint8_t code[] = { 0x9A, 0x00,0x00, 0x00,0x20 };  /* call far 2000:0000 */
        load(code, sizeof(code));
        g_dos_mem[0x20000] = 0xCB;                        /* retf */
        {
            uint16_t sp0 = C.r[CPU_SP];
            run_n(1);
            CHECK_EQ(C.s[CPU_CS], 0x2000, "far call loaded CS");
            CHECK_EQ(C.ip, 0x0000, "far call loaded IP");
            CHECK_EQ(C.r[CPU_SP], sp0 - 4, "far call pushed CS and IP");
            run_n(1);
            CHECK_EQ(C.s[CPU_CS], CODE_SEG, "retf restored CS");
            CHECK_EQ(C.ip, 5, "retf restored IP past the call");
            CHECK_EQ(C.r[CPU_SP], sp0, "retf restored SP");
        }
    }

    /* RETF n also pops arguments — the pascal convention this game uses. */
    {
        uint8_t code[] = { 0x9A, 0x00,0x00, 0x00,0x20 };
        load(code, sizeof(code));
        g_dos_mem[0x20000] = 0xCA;                        /* retf 8 */
        g_dos_mem[0x20001] = 0x08;
        g_dos_mem[0x20002] = 0x00;
        {
            uint16_t sp0 = C.r[CPU_SP];
            run_n(2);
            CHECK_EQ(C.r[CPU_SP], sp0 + 8, "retf 8 popped eight argument bytes");
        }
    }

    /* Conditional jumps: JZ taken, JNZ not. */
    {
        uint8_t code[] = { 0x31,0xC0, 0x74,0x02, 0xB0,0xFF, 0xB4,0x11 };
        /* xor ax,ax; jz +2; mov al,FF; mov ah,11 */
        LOAD_RUN(code, 3);
        CHECK_EQ(cpu_get_r8(&C, CPU_AH), 0x11, "JZ skipped the mov al,FF");
        CHECK_EQ(cpu_get_r8(&C, CPU_AL), 0x00, "al untouched");
    }

    /* LOOP decrements CX and branches while non-zero. */
    {
        uint8_t code[] = { 0xB9,0x03,0x00, 0x40, 0xE2,0xFD }; /* mov cx,3; inc ax; loop -3 */
        LOAD_RUN(code, 32);
        CHECK_EQ(C.r[CPU_AX], 3, "loop body ran three times");
        CHECK_EQ(C.r[CPU_CX], 0, "CX exhausted");
    }

    /* INT pushes flags/CS/IP, clears IF and TF, and vectors via the IVT. */
    {
        uint8_t code[] = { 0xFB, 0xCD,0x21 };   /* sti; int 21h */
        load(code, sizeof(code));
        seg_w16(0, 0x21 * 4, 0x1234);
        seg_w16(0, 0x21 * 4 + 2, 0x5678);
        run_n(2);
        CHECK_EQ(C.s[CPU_CS], 0x5678, "INT loaded CS from the IVT");
        CHECK_EQ(C.ip, 0x1234, "INT loaded IP from the IVT");
        CHECK(!flag(F_IF), "INT cleared IF");
        CHECK_EQ(seg_r16(STACK_SEG, C.r[CPU_SP]), 3, "return IP pushed");
        CHECK_EQ(seg_r16(STACK_SEG, (uint16_t)(C.r[CPU_SP] + 2)), CODE_SEG, "return CS pushed");
        CHECK(seg_r16(STACK_SEG, (uint16_t)(C.r[CPU_SP] + 4)) & F_IF,
              "the pushed FLAGS still has IF set");
    }

    /* IRET restores all three. */
    {
        uint8_t code[] = { 0xCF };
        load(code, sizeof(code));
        cpu86_push16(&C, F_IF | F_ALWAYS_SET);
        cpu86_push16(&C, 0x1111);
        cpu86_push16(&C, 0x2222);
        run_n(1);
        CHECK_EQ(C.ip, 0x2222, "iret restored IP");
        CHECK_EQ(C.s[CPU_CS], 0x1111, "iret restored CS");
        CHECK(flag(F_IF), "iret restored IF");
    }
}

/* ------------------------------------------------------------------ */
static void test_segment_load_inhibit(void) {
    printf("segment-load interrupt inhibit\n");
    /*
     * A real 8086 does not accept an interrupt on the boundary after loading
     * a segment register, which is what makes `mov ss,ax; mov sp,bx` atomic.
     * The retail C runtime depends on this; losing it corrupts the stack in
     * a way that surfaces far from the cause.
     */
    {
        uint8_t code[] = { 0x8E,0xD0 };   /* mov ss,ax */
        LOAD_RUN(code, 1);
        CHECK(C.inhibit_irq, "MOV Sreg must inhibit the next interrupt");
    }
    {
        uint8_t code[] = { 0x1F };        /* pop ds */
        LOAD_RUN(code, 1);
        CHECK(C.inhibit_irq, "POP Sreg must inhibit the next interrupt");
    }
    {
        uint8_t code[] = { 0x90 };        /* nop */
        LOAD_RUN(code, 1);
        CHECK(!C.inhibit_irq, "an ordinary instruction must not inhibit");
    }
}

/* ------------------------------------------------------------------ */
static void test_bcd_and_misc(void) {
    printf("BCD and miscellaneous\n");

    { /* DAA after adding two BCD values. */
        uint8_t code[] = { 0xB0,0x19, 0x04,0x28, 0x27 };  /* mov al,19h; add al,28h; daa */
        LOAD_RUN(code, 3);
        CHECK_EQ(cpu_get_r8(&C, CPU_AL), 0x47, "19 + 28 == 47 in BCD");
    }

    { /* AAA. */
        uint8_t code[] = { 0xB8,0x0F,0x00, 0x37 };   /* mov ax,000F; aaa */
        LOAD_RUN(code, 2);
        CHECK_EQ(cpu_get_r8(&C, CPU_AL), 0x05, "aaa adjusts AL");
        CHECK_EQ(cpu_get_r8(&C, CPU_AH), 0x01, "aaa carries into AH");
        CHECK(flag(F_CF) && flag(F_AF), "aaa sets CF and AF");
    }

    { /* XLAT. */
        uint8_t code[] = { 0xD7 };
        load(code, sizeof(code));
        C.r[CPU_BX] = 0x100;
        cpu_set_r8(&C, CPU_AL, 3);
        seg_w8(DATA_SEG, 0x103, 0x9C);
        run_n(1);
        CHECK_EQ(cpu_get_r8(&C, CPU_AL), 0x9C, "xlat indexes DS:[BX+AL]");
    }

    { /* PUSHF/POPF round-trip, with the always-set bits normalised. */
        uint8_t code[] = { 0xF9, 0x9C, 0xF8, 0x9D };  /* stc; pushf; clc; popf */
        LOAD_RUN(code, 4);
        CHECK(flag(F_CF), "popf restored CF");
    }

    { /* LAHF / SAHF. */
        uint8_t code[] = { 0xF9, 0x9F };   /* stc; lahf */
        LOAD_RUN(code, 2);
        CHECK(cpu_get_r8(&C, CPU_AH) & F_CF, "lahf captured CF");
    }

    { /* CBW sign-extends. */
        uint8_t code[] = { 0xB0,0x80, 0x98 };
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 0xFF80, "cbw sign-extends 0x80");
    }

    { /* CWD sign-extends into DX. */
        uint8_t code[] = { 0xB8,0x00,0x80, 0x99 };
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_DX], 0xFFFF, "cwd sign-extends");
    }

    { /* XCHG. */
        uint8_t code[] = { 0xB8,0x11,0x11, 0xBB,0x22,0x22, 0x93 };
        LOAD_RUN(code, 3);
        CHECK_EQ(C.r[CPU_AX], 0x2222, "xchg swapped ax");
        CHECK_EQ(C.r[CPU_BX], 0x1111, "xchg swapped bx");
    }
}

/* ------------------------------------------------------------------ */
static void test_186_ops(void) {
    printf("80186 additions\n");

    { /* PUSHA / POPA round-trip. */
        uint8_t code[] = { 0x60, 0x61 };
        load(code, sizeof(code));
        C.r[CPU_AX] = 0x1111; C.r[CPU_CX] = 0x2222;
        C.r[CPU_DX] = 0x3333; C.r[CPU_BX] = 0x4444;
        C.r[CPU_BP] = 0x5555; C.r[CPU_SI] = 0x6666; C.r[CPU_DI] = 0x7777;
        {
            uint16_t sp0 = C.r[CPU_SP];
            run_n(2);
            CHECK_EQ(C.r[CPU_AX], 0x1111, "popa restored ax");
            CHECK_EQ(C.r[CPU_DI], 0x7777, "popa restored di");
            CHECK_EQ(C.r[CPU_SP], sp0, "pusha/popa are stack-neutral");
        }
    }

    { /* PUSH imm8 sign-extends. */
        uint8_t code[] = { 0x6A,0xFF };
        LOAD_RUN(code, 1);
        CHECK_EQ(seg_r16(STACK_SEG, C.r[CPU_SP]), 0xFFFF, "push imm8 sign-extends");
    }

    { /* IMUL r16, rm16, imm8. */
        uint8_t code[] = { 0xBB,0x03,0x00, 0x6B,0xC3,0x05 };  /* mov bx,3; imul ax,bx,5 */
        LOAD_RUN(code, 2);
        CHECK_EQ(C.r[CPU_AX], 15, "3 * 5");
        CHECK(!flag(F_OF), "no overflow");
    }

    { /* ENTER / LEAVE. */
        uint8_t code[] = { 0xC8,0x04,0x00,0x00, 0xC9 };  /* enter 4,0; leave */
        load(code, sizeof(code));
        C.r[CPU_BP] = 0xAAAA;
        {
            uint16_t sp0 = C.r[CPU_SP];
            run_n(1);
            CHECK_EQ(C.r[CPU_SP], sp0 - 2 - 4, "enter pushed bp and allocated 4");
            run_n(1);
            CHECK_EQ(C.r[CPU_SP], sp0, "leave unwound the frame");
            CHECK_EQ(C.r[CPU_BP], 0xAAAA, "leave restored bp");
        }
    }
}

/* ------------------------------------------------------------------ */
static void test_self_modifying_stack_code(void) {
    printf("code execution from the stack segment\n");
    /*
     * The retail C runtime's int86 helper (src/exe_19820.asm) writes
     * `CD <n>; CB` into a STACK buffer and far-calls it. Instruction fetch
     * must therefore work from SS at a runtime-computed address. If this
     * test fails, every library call that issues a dynamic interrupt breaks.
     */
    uint8_t code[] = { 0x9A, 0x00,0x03, 0x00,0x20 };   /* call far 2000:0300 */
    load(code, sizeof(code));

    /* Build `int 21h; retf` at 2000:0300 at "runtime". */
    seg_w8(0x2000, 0x300, 0xCD);
    seg_w8(0x2000, 0x301, 0x21);
    seg_w8(0x2000, 0x302, 0xCB);

    seg_w16(0, 0x21 * 4, 0x4444);
    seg_w16(0, 0x21 * 4 + 2, 0x8888);

    run_n(2);
    CHECK_EQ(C.s[CPU_CS], 0x8888, "generated INT executed from a data page");
    CHECK_EQ(C.ip, 0x4444, "and vectored correctly");
}

/* ------------------------------------------------------------------ */
static void test_bad_opcode_is_loud(void) {
    printf("unimplemented opcodes fault loudly\n");
    /*
     * Anything 286+ must fault rather than silently doing nothing. Silent
     * no-ops are how an emulator runs for an hour and then misbehaves with
     * no clue where it went wrong.
     */
    uint8_t code[] = { 0x0F, 0x00 };
    LOAD_RUN(code, 1);
    CHECK_EQ(C.fault, CPU_FAULT_BAD_OPCODE, "0F escape must fault");
    CHECK_EQ(C.ip, 0, "IP must stay at the offending instruction");
}

/* ------------------------------------------------------------------ */
static hook_result_t test_hook(cpu86 *c, void *user) {
    *(int *)user += 1;
    c->r[CPU_AX] = 0xF00D;
    return HOOK_DID_RETF;
}

static void test_hooks(void) {
    printf("Stage-2 hook mechanism\n");
    /* A hook standing in for a natively recompiled function. */
    int called = 0;
    uint8_t code[] = { 0x9A, 0x00,0x00, 0x00,0x20 };   /* call far 2000:0000 */
    load(code, sizeof(code));
    cpu86_hook_clear_all();
    CHECK(cpu86_hook_install(0x2000, 0x0000, test_hook, &called), "hook installed");
    {
        uint16_t sp0 = C.r[CPU_SP];
        run_n(2);
        CHECK_EQ(called, 1, "hook fired exactly once");
        CHECK_EQ(C.r[CPU_AX], 0xF00D, "hook wrote its result");
        CHECK_EQ(C.s[CPU_CS], CODE_SEG, "HOOK_DID_RETF performed the far return");
        CHECK_EQ(C.ip, 5, "returned past the call");
        CHECK_EQ(C.r[CPU_SP], sp0, "stack balanced");
    }
    cpu86_hook_clear_all();
}

/* ------------------------------------------------------------------ */
static void test_dos_wildcards(void) {
    printf("DOS 8.3 wildcard matching\n");
    /*
     * DOS semantics, NOT glob. The game globs "%s\\%s*.SAV" for save slots,
     * so getting this wrong either hides saves or lists the whole directory.
     */
    CHECK(dos_match_83("*.SAV", "XANTH01.SAV"), "*.SAV matches a save");
    CHECK(dos_match_83("*.SAV", "xanth01.sav"), "matching is case-insensitive");
    CHECK(!dos_match_83("*.SAV", "XANTH01.DAT"), "extension must match");
    CHECK(dos_match_83("*.*", "ANYTHING.TXT"), "*.* matches everything");
    CHECK(dos_match_83("XANTH???.SAV", "XANTH012.SAV"), "? matches one char");
    CHECK(dos_match_83("XANTH???.SAV", "XANTH01.SAV"),
          "? also matches the end of a short field");
    CHECK(!dos_match_83("XANTH.SAV", "XANTH01.SAV"), "literal name must match");
    CHECK(dos_match_83("XANTH01.*", "XANTH01.SAV"), "* in the extension field");
    /* The classic trap: in DOS, '*' consumes the rest of its FIELD only,
     * so "*.SAV" must not match a file whose extension differs. */
    CHECK(!dos_match_83("*.SAV", "XANTH01.SAVE"), "extension field is 3 chars");
}

/* ------------------------------------------------------------------ */
int main(void) {
    printf("=== cpu86 conformance ===\n");
    test_alu_flags();
    test_shifts();
    test_muldiv();
    test_memory_wrap();
    test_string_ops();
    test_control_flow();
    test_segment_load_inhibit();
    test_bcd_and_misc();
    test_186_ops();
    test_self_modifying_stack_code();
    test_bad_opcode_is_loud();
    test_hooks();
    test_dos_wildcards();

    printf("\n%d checks, %d failures\n", g_checks, g_fails);
    return g_fails ? 1 : 0;
}
