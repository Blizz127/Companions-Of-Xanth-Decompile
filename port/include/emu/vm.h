/*
 * vm.h — the machine: CPU plus DOS/BIOS services, memory layout and tracing.
 */
#ifndef EMU_VM_H
#define EMU_VM_H

#include "cpu86.h"
#include "dos_mcb.h"
#include "mzload.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ------------------------------------------------------------------ */
/* Guest memory map                                                    */
/* ------------------------------------------------------------------ */
#define VM_SEG_IVT        0x0000
#define VM_SEG_BDA        0x0040
#define VM_SEG_DOSDATA    0x0050
#define VM_SEG_ARENA      0x0080  /* first MCB */
#define VM_SEG_ARENA_END  0xA000  /* top of conventional memory (VGA below) */

/*
 * Host-service trampoline page. Each slot is 16 bytes: HLT followed by IRET
 * (or RETF). Interrupt vectors point here, so the guest's own AH=35h/25h
 * get/set-vector calls and its handler chaining all work unmodified — which
 * matters because the game replaces INT 08h and chains to the old handler.
 */
#define VM_SEG_TRAMP      0xF100
#define VM_TRAMP_SLOTS    256

/* One extra slot past the 256 interrupt slots, used as the return address for
 * an INT 33h event callback. See the mouse-callback comment in vm.c. */
#define VM_TRAMP_MOUSE_RET 0x1000

#define VM_MAX_FILES      40
#define VM_KEY_QUEUE      32

typedef struct {
    bool  used;
    FILE *fp;
    char  host_path[512];
    bool  is_device;      /* stdin/stdout/stderr/CON */
    int   device_id;
} vm_file;

typedef struct {
    char     exe_path[512];
    char     data_dir[512];
    char     save_dir[512];
    char     mods_dir[512]; /* empty unless hash-keyed replacements are opted in */
    bool     use_general_midi; /* opt-in MPU-401 path for the configured soundfont */
    bool     trace_int;
    bool     trace_dos;
    bool     trace_cpu;
    bool     permissive;    /* unimplemented services warn instead of trapping */
    /* Diagnostic: make DOS console reads return "no character" instead of
     * blocking. Not correct DOS behaviour -- it exists because it proved the
     * game has a mouse-polling loop behind its blocking read. See the
     * mouse-input note in docs/PORT.md. */
    bool     nonblocking_conin;
    uint64_t max_instructions;
} vm_config;

typedef struct vm {
    cpu86      cpu;
    vm_config  cfg;
    mcb_arena  arena;
    mz_image_t img;

    uint16_t   psp_seg;
    uint16_t   env_seg;
    uint16_t   dta_seg, dta_off;

    vm_file    files[VM_MAX_FILES];

    bool       exited;
    int        exit_code;
    uint64_t   insn_count;

    /* Timing. Virtual cycles are the authority; the host clock never
     * influences guest state, which is what keeps replay deterministic. */
    uint64_t   cycles_per_second;
    uint64_t   pit_period_cycles;
    uint64_t   next_tick_cycles;
    uint64_t   timer_ticks;
    bool       tick_pending;

    /* VGA DAC. Captured from ports 3C8/3C9 so a framebuffer dump has real
     * colours; the HAL takes this over at M5. */
    uint8_t    dac[256 * 3];
    uint8_t    dac_index;
    uint8_t    dac_component;
    uint32_t   dac_writes;

    /* 8253 PIT channel 0.
     *
     * Not optional: the game's audio setup programs the divisor, then latches
     * and reads the counter twice to CALIBRATE ITS TIMING. A port that returns
     * a constant makes the measured delta zero and the calibration loop spins
     * forever. */
    struct {
        uint16_t divisor;      /* 0 means 65536 */
        uint8_t  access;       /* 1 = lo only, 2 = hi only, 3 = lo then hi */
        uint8_t  write_hi;     /* next data write is the high byte */
        uint8_t  read_hi;      /* next data read is the high byte */
        uint16_t latch;
        bool     latched;
        uint8_t  mode;
    } pit0;

    /* Intel 8237 DMA Controller (Channels 0..3) */
    struct {
        uint16_t base_addr[4];
        uint16_t cur_addr[4];
        uint16_t base_count[4];
        uint16_t cur_count[4];
        uint8_t  page[4];
        uint8_t  mode[4];
        uint8_t  mask;          /* bit N = channel N masked */
        uint8_t  flip_flop;     /* 0 = low byte next, 1 = high byte next */
    } dma;

    /* 8259 PIC Ports 0x20/0x21 */
    struct {
        uint8_t imr;            /* Interrupt Mask Register (port 0x21) */
        uint8_t irr;            /* Interrupt Request Register */
        uint8_t isr;            /* In-Service Register */
        uint8_t last_cmd;       /* Last command (port 0x20, e.g. 0x20 EOI) */
    } pic;

    /* Sound Blaster DSP at base 0x220.
     *
     * Detection is a handshake: write 1 then 0 to the reset port, poll the
     * read-buffer-status port for bit 7, and expect 0xAA from the read-data
     * port. A card that never answers is reported absent and the game runs
     * without digitized sound. */
    struct {
        uint16_t base;
        uint8_t  out_queue[16];
        int      out_head, out_tail;
        uint8_t  last_cmd;
        int      cmd_args_needed;
        uint8_t  cmd_args[4];
        int      cmd_args_got;
        uint8_t  reset_state;
        bool     speaker_on;
        uint16_t time_constant;
        uint32_t sample_rate;
        uint8_t  irq;
        bool     irq_pending;
        bool     dma_active;
        bool     auto_init;
        uint32_t block_size;
        uint32_t dma_base_phys;
        uint64_t dma_end_cycles;
        uint64_t dma_transferred_bytes;
        uint32_t accesses;
    } sb;

    /* AdLib / OPL. The index/data pair is latched here and forwarded to the
     * audio HAL; the timer status is modelled locally because that is what
     * the card-detection handshake actually reads. */
    uint16_t   opl_index;
    uint8_t    opl_status;
    uint8_t    opl_timer_ctl;
    uint32_t   opl_writes;
    uint32_t   speaker_writes;   /* port 0x61 — RealSound gates the speaker here */
    uint8_t    speaker_port;     /* latched port 0x61 */
    uint16_t   rs_batch_n;
    uint8_t    rs_batch[256];
    uint64_t   rs_pwm_writes;    /* port 0x42 writes while the speaker is on */
    uint64_t   rs_samples;       /* PCM samples pushed into the mixer */

    uint8_t    stub_key;   /* what a blocking console read returns for now */

    /* ---- Input -------------------------------------------------------
     * One queue feeds INT 16h, DOS console input and the BIOS keyboard
     * buffer; one state block feeds INT 33h. Events are posted by the host
     * (SDL front end, or a replay script) so that guest-visible input is
     * fully reproducible. */
    struct { uint8_t scan, ascii; } keyq[VM_KEY_QUEUE];
    int        keyq_head, keyq_tail;
    uint8_t    pending_ext;   /* second byte of an extended-key DOS read */
    bool       svc_flags_slot_valid;
    uint16_t   svc_saved_flags;

    int        mouse_x, mouse_y;          /* logical 320x200 space */
    int        mouse_buttons;             /* bit 0 left, 1 right, 2 middle */
    bool       mouse_visible;
    int        mouse_min_x, mouse_max_x;
    int        mouse_min_y, mouse_max_y;
    int        press_count[3],  press_x[3],  press_y[3];
    int        release_count[3], release_x[3], release_y[3];
    int        mickey_dx, mickey_dy;

    /* Idle detection: a guest spinning on "is there input yet?" should not
     * burn the whole slice. Counted per service and reset when input lands. */
    uint32_t   idle_polls;

    /* INT 33h event handler. The game installs one (AX=0014h) and relies on
     * the driver calling it; it does not poll for movement. */
    uint16_t   m33_handler_seg, m33_handler_off;
    uint16_t   m33_mask;
    uint16_t   m33_pending;        /* condition bits waiting to be delivered */
    bool       m33_in_callback;
    uint32_t   m33_calls;
    struct {                        /* guest state saved across the callback */
        uint16_t r[8], s[4], ip, flags;
    } m33_saved;
    uint64_t   waits;      /* times a blocking service had to wait for input */
    bool       waiting_for_input;  /* set on block, cleared when input lands */

    /* ---- Overlay provenance -----------------------------------------
     * RTLink pages sections of XANTH.OVL into a fixed region, so the SAME
     * segment:offset holds different code at different times. Without a
     * record of what was loaded where, an address cannot be mapped back to a
     * source unit -- which breaks both debugging and Stage 2's dispatch.
     *
     * Every read on the OVL handle is recorded here: which payload offset
     * landed on which paragraph, and when. */
#define VM_OVL_PARAS   0x10000       /* one entry per paragraph of the 1 MB */
#define VM_OVL_LOADS   512
    int        ovl_handle;           /* DOS handle of XANTH.OVL, -1 if closed */
    int32_t   *ovl_provenance;       /* payload offset resident per paragraph */
    struct {
        uint32_t file_off, length;
        uint16_t seg, off;
        uint64_t at_insn;
    } ovl_loads[VM_OVL_LOADS];
    int        ovl_load_count;
    uint16_t   ovl_base_seg;         /* lowest destination segment observed */

    /* Distinct files the guest opened, for the report. Low volume and high
     * diagnostic value: it shows at a glance whether RTLink paged its
     * overlays and whether the game's own asset loaders ran. */
#define VM_MAX_OPENED 64
    char       opened[VM_MAX_OPENED][16];
    int        opened_count;

    /* Find-first/find-next state. Snapshotted and sorted at 4Eh so the
     * results cannot depend on host readdir order. */
    struct {
        char   dir[512];
        char **names;
        int    count;
        int    index;
    } find;

    /* Execution profile: a sampled histogram of where the guest spends its
     * time, bucketed by paragraph. Turns "it is stuck somewhere" into an
     * address, and later hands Stage 2 a measured list of hot functions
     * rather than a guessed one. */
    uint32_t  *prof;              /* 64K buckets, one per paragraph of the 1 MB */
    uint64_t   prof_samples;

    /* Diagnostics: what did the guest actually ask for? Dumped on exit so
     * the DOS kernel's scope is driven by measurement, not guesswork. */
    uint32_t   int_counts[256];
    uint32_t   dos_counts[256];   /* indexed by AH */
    bool       dos_unimpl[256];
    uint16_t   last_unimpl_int;
    uint16_t   last_unimpl_ah;
} vm;

bool vm_init(vm *v, const vm_config *cfg, char *err, size_t errlen);
void vm_shutdown(vm *v);

/* Run until the instruction budget is met, or the guest exits or faults.
 * Returns false once the machine has stopped for good. */
bool vm_run(vm *v, uint64_t max_insns);

void vm_report(const vm *v, FILE *out);
bool vm_save_bmp(const vm *v, const char *path);

/* Overlay provenance: which XANTH.OVL payload offset is resident at an
 * address right now, or -1. This is what makes an overlay address mappable
 * back to a source unit, and it is the same mechanism Stage 2 needs for
 * dispatch. */
void    vm_note_overlay_load(vm *v, uint32_t file_off, uint32_t len,
                             uint16_t seg, uint16_t off);
int32_t vm_overlay_payload_at(const vm *v, uint16_t seg, uint16_t off);

/* Checkpoint hash over framebuffer + palette. Hashes, never pixels. */
uint64_t vm_frame_hash(const vm *v);

/* ---- Host input injection ----------------------------------------
 * The only way guest-visible input enters the machine. Keeping it to these
 * three calls is what makes deterministic replay possible later. */
void vm_post_key(vm *v, uint8_t scancode, uint8_t ascii);
void vm_post_mouse_move(vm *v, int x, int y);
void vm_post_mouse_button(vm *v, int button, bool pressed);

/* Audio sink, injected by the front end so the core stays SDL-free. */
extern void (*vm_audio_opl_write)(uint16_t reg, uint8_t val);
extern void (*vm_audio_dma_write)(const uint8_t *samples, uint32_t count, uint32_t sample_rate);
extern uint8_t (*vm_audio_mpu_read_data)(void);
extern uint8_t (*vm_audio_mpu_read_status)(void);
extern void (*vm_audio_mpu_write_data)(uint8_t data);
extern void (*vm_audio_mpu_write_cmd)(uint8_t cmd);

/* Guest clock, derived from the virtual timer (never the host clock). */
void vm_clock_time(const vm *v, int *hh, int *mm, int *ss, int *cs);
void vm_clock_date(const vm *v, int *year, int *month, int *day, int *dow);

/* Exposed for testing: DOS 8.3 wildcard semantics (not glob). */
bool dos_match_83(const char *pattern, const char *filename);
void vm_dump_state(const vm *v, FILE *out);

#ifdef __cplusplus
}
#endif

#endif /* EMU_VM_H */
