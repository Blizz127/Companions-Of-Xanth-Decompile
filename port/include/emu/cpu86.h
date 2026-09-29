/*
 * cpu86.h — 8086/80186 real-mode interpreter for the Companions of Xanth port.
 *
 * Design notes that callers depend on:
 *
 *  - The core is ARCHITECTURAL, not behavioural. `INT n` is implemented purely
 *    as "push FLAGS, clear IF/TF, push CS:IP, load the vector from the IVT".
 *    Nothing special-cases a particular interrupt number. Host services are
 *    reached because the VM installs handlers in the IVT at boot. This is
 *    required: the retail game hooks INT 08h via DOS AH=35h/25h and chains to
 *    the previous handler, which only works if vectors are real.
 *
 *  - Memory is the shared 1 MB `g_dos_mem` array from port_types.h. The Mode
 *    13h framebuffer already lives at +0xA0000, so guest VGA writes need no
 *    translation. All accesses mask to 20 bits to reproduce 8086 wraparound.
 *
 *  - Flags are EAGER and stored in the real 8086 bit layout, so pushf/popf/
 *    lahf/sahf are trivial. See cpu86_alu.c for the rationale.
 *
 *  - Instruction fetch may occur from ANY segment, including SS. The retail
 *    C runtime's int86 helper builds `CD <n>; CB` in a stack buffer and calls
 *    it. Do not add an assumption that code lives in CS.
 */
#ifndef EMU_CPU86_H
#define EMU_CPU86_H

#include "port_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ */
/* Register indices. Values match the 8086 instruction encodings, so   */
/* they can be used directly as decoded from a ModRM byte.             */
/* ------------------------------------------------------------------ */
enum { CPU_AX = 0, CPU_CX, CPU_DX, CPU_BX, CPU_SP, CPU_BP, CPU_SI, CPU_DI };
enum { CPU_ES = 0, CPU_CS, CPU_SS, CPU_DS };

/* Byte register encodings: AL CL DL BL AH CH DH BH */
enum { CPU_AL = 0, CPU_CL, CPU_DL, CPU_BL, CPU_AH, CPU_CH, CPU_DH, CPU_BH };

/* ------------------------------------------------------------------ */
/* FLAGS                                                               */
/* ------------------------------------------------------------------ */
#define F_CF 0x0001u
#define F_PF 0x0004u
#define F_AF 0x0010u
#define F_ZF 0x0040u
#define F_SF 0x0080u
#define F_TF 0x0100u
#define F_IF 0x0200u
#define F_DF 0x0400u
#define F_OF 0x0800u

/*
 * On a real 8086 bit 1 reads as 1 and bits 12..15 read as 1. We pin the 8086
 * pattern deliberately (the 286+ clears 12..15 in real mode). If anything
 * ever turns out to care, this is the single place to flip it.
 */
#define F_ALWAYS_SET 0xF002u
#define F_MODIFIABLE (F_CF|F_PF|F_AF|F_ZF|F_SF|F_TF|F_IF|F_DF|F_OF)

/* ------------------------------------------------------------------ */
/* Faults                                                              */
/* ------------------------------------------------------------------ */
typedef enum {
    CPU_OK = 0,
    CPU_FAULT_BAD_OPCODE,    /* opcode not implemented (e.g. any 0F escape) */
    CPU_FAULT_UNIMPL_INT,    /* host service refused the call */
    CPU_FAULT_HOST_ABORT,    /* a host callback asked to stop */
    CPU_FAULT_BREAKPOINT,    /* debugger breakpoint hit */
    CPU_FAULT_EXITED         /* guest terminated (DOS AH=4Ch) */
} cpu_fault_t;

/* ------------------------------------------------------------------ */
/* Stage-2 hook mechanism.                                             */
/*                                                                     */
/* Designed in now, used later: it lets execution at a given CS:IP be  */
/* diverted to a native C function. Three consumers share one bitmap — */
/* statically recompiled replacements, debugger breakpoints, and       */
/* per-site profiling counters.                                        */
/* ------------------------------------------------------------------ */
typedef enum {
    HOOK_CONTINUE = 0,  /* interpret the instruction normally */
    HOOK_DID_RETN,      /* native fn ran and performed a near return */
    HOOK_DID_RETF,      /* ... a far return */
    HOOK_DID_SETIP      /* ... and set CS:IP itself */
} hook_result_t;

struct cpu86;
typedef hook_result_t (*cpu_hook_fn)(struct cpu86 *c, void *user);

typedef struct cpu86 {
    uint16_t r[8];      /* GPRs, indexed by the enum above */
    uint16_t s[4];      /* segment registers */
    uint16_t ip;
    uint16_t flags;

    uint64_t cycles;    /* virtual cycle counter; the authority for timing */
    uint64_t budget;    /* cpu86_run stops once cycles >= budget */
    uint64_t step_budget_remaining; /* vm_run budget available at this boundary */
    uint8_t  step_guest_insns;      /* instruction-equivalents consumed by this step */

    /* Per-instruction decode state, reset at the top of each step. */
    uint16_t insn_ip;      /* IP at the first prefix byte (REP rewinds here) */
    int      seg_override; /* CPU_ES/CS/SS/DS, or -1 for "use the default" */
    uint8_t  rep;          /* 0, 0xF2 (REPNE) or 0xF3 (REP/REPE) */

    /*
     * Set by MOV Sreg,* / POP Sreg / segment-override prefixes. A real 8086
     * does not take an interrupt on the boundary after loading a segment
     * register, so that `mov ss,ax; mov sp,bx` is atomic. The retail C
     * runtime depends on this.
     */
    uint8_t  inhibit_irq;

    uint8_t  halted;        /* HLT executed outside the trampoline page */
    uint8_t  yield_request; /* a service detected an idle spin; end the slice */
    uint8_t  fault;         /* cpu_fault_t */
    uint32_t fault_addr;    /* linear address the fault occurred at */

    /* Where the most recent `INT n` was issued from. Cheap to maintain and
     * the only reliable way to attribute a host service back to guest code:
     * by the time a trampoline handler runs, CS:IP is the trampoline's. */
    uint16_t last_int_cs, last_int_ip;

    void    *vm;            /* owning vm, passed back to host callbacks */
} cpu86;

/* ------------------------------------------------------------------ */
/* Memory access. All guest memory goes through these four functions.  */
/*                                                                     */
/* Word accesses are deliberately TWO byte accesses so that a read at  */
/* offset 0xFFFF wraps within the segment exactly as an 8086 does, and */
/* so the port stays alignment- and endian-clean on every host.        */
/* ------------------------------------------------------------------ */
static inline uint32_t cpu_lin(uint16_t seg, uint16_t off) {
    return (((uint32_t)seg << 4) + off) & 0xFFFFFu;
}

static inline uint8_t mem_r8(uint32_t lin) {
    return g_dos_mem[lin & 0xFFFFFu];
}

static inline void mem_w8(uint32_t lin, uint8_t v) {
    g_dos_mem[lin & 0xFFFFFu] = v;
}

static inline uint16_t seg_r8(uint16_t seg, uint16_t off) {
    return g_dos_mem[cpu_lin(seg, off)];
}

static inline void seg_w8(uint16_t seg, uint16_t off, uint8_t v) {
    g_dos_mem[cpu_lin(seg, off)] = v;
}

static inline uint16_t seg_r16(uint16_t seg, uint16_t off) {
    uint8_t lo = g_dos_mem[cpu_lin(seg, off)];
    uint8_t hi = g_dos_mem[cpu_lin(seg, (uint16_t)(off + 1))];
    return (uint16_t)(lo | ((uint16_t)hi << 8));
}

static inline void seg_w16(uint16_t seg, uint16_t off, uint16_t v) {
    g_dos_mem[cpu_lin(seg, off)]                  = (uint8_t)(v & 0xFF);
    g_dos_mem[cpu_lin(seg, (uint16_t)(off + 1))]  = (uint8_t)(v >> 8);
}

/* ------------------------------------------------------------------ */
/* Byte-register access, host-endian independent.                      */
/* ------------------------------------------------------------------ */
static inline uint8_t cpu_get_r8(const cpu86 *c, int i) {
    uint16_t w = c->r[i & 3];
    return (uint8_t)((i & 4) ? (w >> 8) : (w & 0xFF));
}

static inline void cpu_set_r8(cpu86 *c, int i, uint8_t v) {
    uint16_t *w = &c->r[i & 3];
    if (i & 4) *w = (uint16_t)((*w & 0x00FF) | ((uint16_t)v << 8));
    else       *w = (uint16_t)((*w & 0xFF00) | v);
}

/* ------------------------------------------------------------------ */
/* Core API                                                            */
/* ------------------------------------------------------------------ */
void     cpu86_reset(cpu86 *c);

/* Execute until the cycle budget is met, or a fault / yield / halt.
 * Returns the number of virtual cycles actually consumed. */
uint64_t cpu86_run(cpu86 *c, uint64_t cycles);

/* Execute exactly one instruction (including one REP iteration). */
void     cpu86_step(cpu86 *c);

void     cpu86_push16(cpu86 *c, uint16_t v);
uint16_t cpu86_pop16(cpu86 *c);

/* Architectural interrupt: push FLAGS/CS/IP, clear IF+TF, vector via IVT. */
void     cpu86_interrupt(cpu86 *c, uint8_t vec);

/* Drive an entry point as if by `call far` (used to bootstrap the image). */
void     cpu86_far_call(cpu86 *c, uint16_t seg, uint16_t off);

const char *cpu86_fault_name(int fault);

/* ------------------------------------------------------------------ */
/* Hook registry                                                       */
/* ------------------------------------------------------------------ */
bool cpu86_hook_install(uint16_t seg, uint16_t off, cpu_hook_fn fn, void *user);
void cpu86_hook_remove(uint16_t seg, uint16_t off);
void cpu86_hook_clear_all(void);

/* ------------------------------------------------------------------ */
/* Port I/O and HLT dispatch are supplied by the VM layer. The CPU core */
/* deliberately does not know what a device is; this keeps it linkable  */
/* into the SDL-free conformance test binary.                           */
/* ------------------------------------------------------------------ */
extern uint8_t  (*cpu86_port_in8)(cpu86 *c, uint16_t port);
extern uint16_t (*cpu86_port_in16)(cpu86 *c, uint16_t port);
extern void     (*cpu86_port_out8)(cpu86 *c, uint16_t port, uint8_t v);
extern void     (*cpu86_port_out16)(cpu86 *c, uint16_t port, uint16_t v);

/* Called when HLT executes. Returning true means "handled, keep going"
 * (the trampoline-page host-service case); false means a real halt. */
extern bool     (*cpu86_on_hlt)(cpu86 *c, uint32_t lin);

#ifdef __cplusplus
}
#endif

#endif /* EMU_CPU86_H */
