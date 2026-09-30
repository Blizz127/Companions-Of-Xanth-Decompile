/* Synthetic-guest regression for the interrupt flag around emulated BIOS
 * and DOS services; no retail assets.
 *
 * The PC BIOS keyboard status call (INT 16h AH=01h/11h) executes STI and
 * returns with RET 2, so its caller comes back with interrupts enabled
 * whatever IF it called with. Services that return through IRET restore the
 * caller's own flags. These cases pin the rule down:
 *   (a) a masked caller polling INT 16h status gets IF back and sees ticks;
 *   (b) masked guest code that makes no service call stays masked;
 *   (c) the one-instruction shadows after MOV SS and STI still hold;
 *   (d) IRET-returning services (INT 21h, blocking INT 16h AH=00h) return
 *       with the caller's IF still clear and their results intact.
 */
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "line %d: %s\n", __LINE__, #c); failed = 1; } } while (0)

/* Data words at the end of each program, written by the ISR. */
#define D_COUNT 0x80
#define D_RETIP 0x82
#define D_RETCS 0x84
#define D_RETFL 0x86

/* ISR at 0x40: record the interrupted IP/CS/FLAGS, count, EOI, IRET. */
static const unsigned char isr[] = {
    0x55,                   /* push bp            */
    0x89, 0xE5,             /* mov bp,sp          */
    0x50,                   /* push ax            */
    0x8B, 0x46, 0x02,       /* mov ax,[bp+2]      */
    0x2E, 0xA3, D_RETIP, 0, /* mov cs:[RETIP],ax  */
    0x8B, 0x46, 0x04,       /* mov ax,[bp+4]      */
    0x2E, 0xA3, D_RETCS, 0, /* mov cs:[RETCS],ax  */
    0x8B, 0x46, 0x06,       /* mov ax,[bp+6]      */
    0x2E, 0xA3, D_RETFL, 0, /* mov cs:[RETFL],ax  */
    0x2E, 0xFF, 0x06, D_COUNT, 0, /* inc word cs:[COUNT] */
    0xB0, 0x20,             /* mov al,20h         */
    0xE6, 0x20,             /* out 20h,al         */
    0x58,                   /* pop ax             */
    0x5D,                   /* pop bp             */
    0xCF,                   /* iret               */
};

/* Common prologue at 0: DS=CS, INT 08h -> CS:0040 via DOS AH=25h. */
static const unsigned char prologue[] = {
    0x0E, 0x1F,             /* push cs; pop ds    */
    0xBA, 0x40, 0x00,       /* mov dx,0040h       */
    0xB8, 0x08, 0x25,       /* mov ax,2508h       */
    0xCD, 0x21,             /* int 21h            */
};
#define BODY 0x0A

static int failed;
static char g_dir[64];

static unsigned rd(unsigned seg, unsigned off) {
    unsigned a = seg * 16u + off;
    return g_dos_mem[a] | (g_dos_mem[a + 1] << 8);
}

static void put16(unsigned char *p, unsigned v) { p[0] = (unsigned char)v; p[1] = (unsigned char)(v >> 8); }

/* Build a one-segment MZ program (prologue, body at BODY, ISR at 0x40) and
 * start a VM on it. */
static vm *start(const unsigned char *body, size_t n) {
    char path[512], err[512];
    unsigned char exe[512] = {0}, *code = exe + 32;
    vm_config cfg;
    vm *v = calloc(1, sizeof(*v));
    if (!v || n > 0x40 - BODY) return NULL;
    put16(exe, 0x5a4d); put16(exe + 2, 512); put16(exe + 4, 1); put16(exe + 8, 2);
    put16(exe + 10, 0x100); put16(exe + 12, 0xffff); put16(exe + 16, 0xff0); put16(exe + 24, 0x1c);
    memcpy(code, prologue, sizeof(prologue));
    memcpy(code + BODY, body, n);
    memcpy(code + 0x40, isr, sizeof(isr));
    snprintf(path, sizeof(path), "%s/IRQ.EXE", g_dir);
    FILE *f = fopen(path, "wb");
    if (!f) return NULL;
    fwrite(exe, 1, sizeof(exe), f);
    fclose(f);
    memset(&cfg, 0, sizeof(cfg));
    snprintf(cfg.exe_path, sizeof(cfg.exe_path), "%s", path);
    snprintf(cfg.data_dir, sizeof(cfg.data_dir), "%s", g_dir);
    snprintf(cfg.save_dir, sizeof(cfg.save_dir), "%s", g_dir);
    if (!vm_init(v, &cfg, err, sizeof(err))) { fprintf(stderr, "%s\n", err); free(v); return NULL; }
    return v;
}

static void stop(vm *v) {
    char path[512];
    vm_shutdown(v);
    free(v);
    snprintf(path, sizeof(path), "%s/IRQ.EXE", g_dir); unlink(path);
    snprintf(path, sizeof(path), "%s/LEGEND.INI", g_dir); unlink(path);
}

/* Single-step until CS:IP matches. */
static int step_to(vm *v, unsigned cs, unsigned ip, int limit) {
    for (int i = 0; i < limit; i++) {
        if (v->cpu.s[CPU_CS] == cs && v->cpu.ip == ip) return 1;
        if (!vm_run(v, 1)) return 0;
    }
    return v->cpu.s[CPU_CS] == cs && v->cpu.ip == ip;
}

static void test_masked_caller_progresses(void) {
    /* cli; mov ah,01h; int 16h; (status call returns IF=1) L: jmp L */
    static const unsigned char body[] = { 0xFA, 0xB4, 0x01, 0xCD, 0x16, 0xEB, 0xFE };
    vm *v = start(body, sizeof(body));
    CHECK(v);
    if (!v) return;
    unsigned cs = v->img.load_seg;
    CHECK(step_to(v, cs, BODY + 0x03, 100));          /* at int 16h, IF clear */
    CHECK(!(v->cpu.flags & 0x0200));
    CHECK(step_to(v, cs, BODY + 0x05, 50));           /* back from the BIOS */
    CHECK(v->cpu.flags & 0x0200);                     /* RET 2: interrupts enabled */
    CHECK(v->cpu.flags & 0x0040);                     /* ZF: no key waiting */
    vm_run(v, 2000000);
    CHECK(rd(cs, D_COUNT) > 0);                       /* ticks reach the guest ISR */
    CHECK(!v->cpu.fault);
    printf("(a) masked INT 16h status poller: IF restored, %u ticks serviced\n", rd(cs, D_COUNT));
    stop(v);
}

static void test_masked_loop_stays_masked(void) {
    /* cli; L: inc ax; jmp L */
    static const unsigned char body[] = { 0xFA, 0x40, 0xEB, 0xFD };
    vm *v = start(body, sizeof(body));
    CHECK(v);
    if (!v) return;
    vm_run(v, 2000000);
    CHECK(rd(v->img.load_seg, D_COUNT) == 0);
    CHECK(v->tick_pending);                           /* held, not dropped */
    CHECK(!(v->cpu.flags & 0x0200));
    printf("(b) masked busy loop: %u ticks serviced, tick pending=%d\n",
           rd(v->img.load_seg, D_COUNT), v->tick_pending);
    stop(v);
}

static void test_shadows_hold(void) {
    /* body @0A: cli(+0); sti(+1); nop(+2); mov ax,ss(+3); mov ss,ax(+5);
     *           mov sp,0FF0h(+7); nop(+A); nop(+B); cli(+C); jmp $(+D) */
    static const unsigned char body[] = {
        0xFA, 0xFB, 0x90, 0x8C, 0xD0, 0x8E, 0xD0, 0xBC, 0xF0, 0x0F, 0x90, 0x90, 0xFA, 0xEB, 0xFE };
    vm *v = start(body, sizeof(body));
    CHECK(v);
    if (!v) return;
    unsigned cs = v->img.load_seg;

    /* STI shadow: a tick pending while IF is clear is not taken at STI, nor
     * before the instruction after STI has run: it lands at +3. */
    CHECK(step_to(v, cs, BODY + 0x01, 100));
    CHECK(!(v->cpu.flags & 0x0200));
    v->tick_pending = true;
    vm_run(v, 1);                                     /* sti */
    CHECK(rd(cs, D_COUNT) == 0 && v->cpu.s[CPU_CS] == cs && v->cpu.ip == BODY + 0x02);
    vm_run(v, 1);                                     /* nop, in the shadow */
    CHECK(rd(cs, D_COUNT) == 0 && v->cpu.s[CPU_CS] == cs && v->cpu.ip == BODY + 0x03);
    CHECK(step_to(v, cs, BODY + 0x05, 200));          /* IRQ, then mov ax,ss */
    CHECK(rd(cs, D_COUNT) == 1 && rd(cs, D_RETIP) == BODY + 0x03);

    /* MOV SS shadow: a tick that becomes pending as MOV SS completes waits
     * until MOV SP has run too. */
    vm_run(v, 1);                                     /* mov ss,ax */
    CHECK(v->cpu.s[CPU_CS] == cs && v->cpu.ip == BODY + 0x07);
    v->tick_pending = true;
    vm_run(v, 1);                                     /* mov sp, in the shadow */
    CHECK(rd(cs, D_COUNT) == 1 && v->cpu.s[CPU_CS] == cs && v->cpu.ip == BODY + 0x0A);
    CHECK(step_to(v, cs, BODY + 0x0B, 200));          /* IRQ, then nop */
    CHECK(rd(cs, D_COUNT) == 2 && rd(cs, D_RETIP) == BODY + 0x0A);
    printf("(c) STI and MOV SS shadows: ticks taken at %04X and %04X\n",
           BODY + 0x03, BODY + 0x0A);
    stop(v);
}

static void test_iret_services_keep_caller_flags(void) {
    /* cli; mov ah,3Eh; mov bx,0FFFFh; int 21h (close bad handle: CF=1);
     * mov ah,00h; int 16h (blocking read, key queued); jmp $ */
    static const unsigned char body[] = {
        0xFA, 0xB4, 0x3E, 0xBB, 0xFF, 0xFF, 0xCD, 0x21,
        0xB4, 0x00, 0xCD, 0x16, 0xEB, 0xFE };
    vm *v = start(body, sizeof(body));
    CHECK(v);
    if (!v) return;
    unsigned cs = v->img.load_seg, sp_before;
    CHECK(step_to(v, cs, BODY + 0x06, 100));          /* at int 21h */
    sp_before = v->cpu.r[CPU_SP];
    CHECK(step_to(v, cs, BODY + 0x08, 50));
    CHECK(!(v->cpu.flags & 0x0200));                  /* caller's IF: still clear */
    CHECK(v->cpu.flags & 0x0001);                     /* the service's CF */
    CHECK(v->cpu.r[CPU_AX] == 6);                     /* invalid handle */
    CHECK(v->cpu.r[CPU_SP] == sp_before);
    vm_post_key(v, 0x39, 0x20);                       /* Space */
    CHECK(step_to(v, cs, BODY + 0x0C, 50));
    CHECK(!(v->cpu.flags & 0x0200));                  /* AH=00h returns via IRET */
    CHECK(v->cpu.r[CPU_AX] == 0x3920);
    CHECK(rd(cs, D_COUNT) == 0);
    printf("(d) INT 21h and INT 16h AH=00h: IF=0 kept, CF=1 AX=6, key %04X\n", 0x3920);
    stop(v);
}

int main(void) {
    snprintf(g_dir, sizeof(g_dir), "/tmp/xanth-irq-XXXXXX");
    if (!mkdtemp(g_dir)) return 2;
    test_masked_caller_progresses();
    test_masked_loop_stays_masked();
    test_shadows_hold();
    test_iret_services_keep_caller_flags();
    rmdir(g_dir);
    printf("VM interrupt flag %s\n", failed ? "FAIL" : "PASS");
    return failed;
}
