/*
 * tool_vmboot.c — boot the retail image under the VM and drive it with a
 * scripted input trace.
 *
 * This is the Stage 1 driver, and the script format is deliberately the seed
 * of the `.xit` replay format the walkthrough regression suite will use:
 * text, diffable, and indexed by instruction count rather than wall time so
 * that a run is reproducible.
 *
 *   # comment
 *   1000000   move 162 113
 *   1000100   click left
 *   2000000   key 13
 *   3000000   shot build/frames/title.bmp
 *
 * Unimplemented host services are fatal by default, so a run either completes
 * or tells you exactly what to write next.
 */
#include "vm.h"
#include "native_stage2.h"
#include "port_hal.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 4096

/*
 * Trace format: an ORDERED list of steps, not timestamped events.
 *
 * Timestamps were the obvious first design and the wrong one: any change to
 * interpreter speed shifts every instruction count, and delivering input
 * early (when the guest actually blocks) then reorders the script against
 * its own screenshots. Ordered steps with an explicit `waitinput` are both
 * robust and readable.
 *
 *   waitinput        run until the guest blocks asking for input
 *   run N            run exactly N instructions (stops early if blocked)
 *   key K            queue ASCII code K
 *   move X Y         move the mouse, in 320x200 coordinates
 *   click left       press, hold across several polls, release
 *   shot PATH        dump the framebuffer now
 *   checkpoint NAME  print a hash of framebuffer + palette
 *   include FILE     splice in another trace, resolved next to this one
 */
typedef enum { ST_WAITINPUT, ST_RUN, ST_KEY, ST_MOVE, ST_CLICK, ST_SHOT,
               ST_HASH, ST_DUMP, ST_DOWN, ST_UP } step_kind;

typedef struct {
    step_kind kind;
    long long a, b;
    char      text[256];
} script_step;

static script_step g_steps[MAX_EVENTS];
static int         g_step_count;

/* How long a scripted click holds the button down and stays released, in
 * scheduler slices. See the comment in ST_CLICK for why it must be non-zero
 * and why it no longer needs to be large. */
#define CLICK_HOLD_SLICES 6

static int button_id(const char *s) {
    if (!strcmp(s, "right"))  return 1;
    if (!strcmp(s, "middle")) return 2;
    return 0;
}

/*
 * Resolve `name` relative to the directory of `base`, so an `include` in a
 * trace names its sibling rather than something relative to the cwd.
 */
static void sibling_path(const char *base, const char *name,
                         char *out, size_t out_sz) {
    const char *slash = strrchr(base, '/');
    if (name[0] == '/' || !slash) {
        snprintf(out, out_sz, "%s", name);
    } else {
        int dir_len = (int)(slash - base);
        snprintf(out, out_sz, "%.*s/%s", dir_len, base, name);
    }
}

static bool load_script_depth(const char *path, int depth);

static bool load_script(const char *path) { return load_script_depth(path, 0); }

/*
 * Walkthrough segments are cumulative -- segment 4 replays 1, 2 and 3 before
 * reaching its own material. `include` lets each segment name its predecessor
 * instead of holding a copy of it, so a coordinate fixed in segment 1 is fixed
 * everywhere rather than in four files that can silently drift apart.
 */
#define MAX_INCLUDE_DEPTH 32

static bool load_script_depth(const char *path, int depth) {
    FILE *f;
    char line[512];

    if (depth > MAX_INCLUDE_DEPTH) {
        fprintf(stderr, "script include nested deeper than %d: '%s' -- "
                        "is there an include cycle?\n", MAX_INCLUDE_DEPTH, path);
        return false;
    }
    f = fopen(path, "r");
    if (!f) { fprintf(stderr, "cannot open script '%s'\n", path); return false; }

    while (fgets(line, sizeof(line), f)) {
        char verb[32] = {0}, a1[256] = {0}, a2[64] = {0};
        char *p = line;
        script_step *st;

        while (*p && isspace((unsigned char)*p)) p++;
        if (*p == '#' || *p == '\0' || *p == '\n') continue;
        if (sscanf(p, "%31s %255s %63s", verb, a1, a2) < 1) continue;

        if (!strcmp(verb, "include")) {
            char inc[512];
            sibling_path(path, a1, inc, sizeof(inc));
            if (!load_script_depth(inc, depth + 1)) { fclose(f); return false; }
            continue;
        }
        if (g_step_count >= MAX_EVENTS) break;

        st = &g_steps[g_step_count];
        memset(st, 0, sizeof(*st));

        if (!strcmp(verb, "waitinput")) {
            st->kind = ST_WAITINPUT;
            /* Bounded low: with the DOS status-flag fix the game no longer
             * parks in a blocking read, so a large bound would just burn the
             * whole budget. `run N` is the primary pacing verb now. */
            st->a = a1[0] ? atoll(a1) : 60;
        } else if (!strcmp(verb, "run")) {
            st->kind = ST_RUN; st->a = atoll(a1);
        } else if (!strcmp(verb, "key")) {
            st->kind = ST_KEY; st->a = atoll(a1); st->b = a2[0] ? atoll(a2) : 0;
        } else if (!strcmp(verb, "move")) {
            st->kind = ST_MOVE; st->a = atoll(a1); st->b = atoll(a2);
        } else if (!strcmp(verb, "click")) {
            st->kind = ST_CLICK; st->a = button_id(a1);
        } else if (!strcmp(verb, "down")) {
            st->kind = ST_DOWN; st->a = button_id(a1);
        } else if (!strcmp(verb, "up")) {
            st->kind = ST_UP; st->a = button_id(a1);
        } else if (!strcmp(verb, "dump")) {
            /* dump SEG:OFF LEN -- hex around a guest address */
            unsigned sg = 0, of = 0;
            st->kind = ST_DUMP;
            if (sscanf(a1, "%x:%x", &sg, &of) == 2) { st->a = sg; st->b = of; }
            snprintf(st->text, sizeof(st->text), "%s", a2[0] ? a2 : "64");
        } else if (!strcmp(verb, "checkpoint")) {
            st->kind = ST_HASH; snprintf(st->text, sizeof(st->text), "%s", a1);
        } else if (!strcmp(verb, "shot")) {
            st->kind = ST_SHOT; snprintf(st->text, sizeof(st->text), "%s", a1);
        } else {
            fprintf(stderr, "unknown script verb '%s'\n", verb);
            continue;
        }
        g_step_count++;
    }
    fclose(f);
    return true;
}

/*
 * Run `slices` scheduler slices.
 *
 * A slice ends either when it has executed SLICE_INSNS instructions or when
 * the guest blocks for input -- and a block advances the virtual clock by one
 * timer tick. So a slice is roughly "one tick of game time OR a chunk of
 * compute", and counting slices is a stable way to say "let the fade finish"
 * without hard-coding instruction counts that shift whenever the interpreter
 * changes.
 */
#define SLICE_INSNS 2000000ULL

/* Optional progress watch: report whenever the amount of drawn screen changes
 * materially. Far more useful than guessing when to take a screenshot. */
static bool     g_watch;
static uint32_t g_watch_last = 0xFFFFFFFFu;
static int      g_watch_lit  = -1;

static uint32_t framebuffer_nonblack(void) {
    uint32_t n = 0;
    for (uint32_t i = 0; i < 64000; i++) if (g_dos_mem[0xA0000u + i]) n++;
    return n;
}

static void watch_tick(vm *m) {
    hal_audio_tick();
    uint32_t n;
    if (!g_watch) return;
    n = framebuffer_nonblack();
    {
        int lit = 0;
        for (int i = 0; i < 256; i++)
            if (m->dac[i*3] || m->dac[i*3+1] || m->dac[i*3+2]) lit++;
        if (g_watch_lit < 0 || abs(lit - g_watch_lit) > 24) {
            g_watch_lit = lit;
            g_watch_last = 0xFFFFFFFFu;   /* force a report below */
        }
    }
    if (g_watch_last == 0xFFFFFFFFu ||
        (n > g_watch_last ? n - g_watch_last : g_watch_last - n) > 1500) {
        {
            int lit = 0;
            for (int i = 0; i < 256; i++)
                if (m->dac[i*3] || m->dac[i*3+1] || m->dac[i*3+2]) lit++;
            fprintf(stderr,
                "[watch] %10llu insns  %5u/64000 drawn (%.1f%%)  "
                "palette: %d/256 lit, %u writes\n",
                (unsigned long long)m->insn_count, n, 100.0 * n / 64000.0,
                lit, m->dac_writes);
        }
        g_watch_last = n;
    }
}

static bool run_slices(vm *m, long long slices) {
    for (long long i = 0; i < slices; i++) {
        if (!vm_run(m, SLICE_INSNS)) return false;
        watch_tick(m);
    }
    return true;
}

/* Run until the guest blocks for input, bounded by `slices`. */
static bool run_until_waiting(vm *m, long long slices) {
    for (long long i = 0; i < slices; i++) {
        if (!vm_run(m, SLICE_INSNS)) return false;
        watch_tick(m);
        if (m->waiting_for_input) return true;
    }
    return true;
}

static bool run_script(vm *m, uint64_t overall_budget) {
    bool alive = true;

    for (int i = 0; i < g_step_count && alive; i++) {
        script_step *st = &g_steps[i];
        if (m->insn_count >= overall_budget) {
            fprintf(stderr, "[script] instruction budget exhausted at step %d\n", i);
            break;
        }

        switch (st->kind) {
        case ST_WAITINPUT:
            alive = run_until_waiting(m, st->a ? st->a : 2000);
            fprintf(stderr, "[script] waitinput -> %s at %llu insns\n",
                    m->waiting_for_input ? "blocked" : "timed out",
                    (unsigned long long)m->insn_count);
            break;

        case ST_RUN:
            alive = run_slices(m, st->a);
            fprintf(stderr, "[script] run %lld slices -> %llu insns\n",
                    st->a, (unsigned long long)m->insn_count);
            break;

        case ST_KEY:
            vm_post_key(m, (uint8_t)st->b, (uint8_t)st->a);
            fprintf(stderr, "[script] key %lld\n", st->a);
            break;

        case ST_MOVE:
            vm_post_mouse_move(m, (int)st->a, (int)st->b);
            fprintf(stderr, "[script] move %lld,%lld\n", st->a, st->b);
            break;

        case ST_CLICK: {
            /*
             * Press, hold, release.
             *
             * The hold matters: code that reads button STATE via INT 33h
             * AX=0003 rather than edge counts cannot see an instantaneous
             * click. It does not need to be long, though -- the game polls
             * the mouse on every pass of its input loop, millions of times a
             * run, so a few slices spans thousands of polls.
             *
             * An earlier version also jiggled the cursor, on the theory that
             * the game only learned button state from movement callbacks.
             * That was a workaround for the DOS status-flag bug, not a real
             * requirement, and it tripled the cost of every click.
             */
            vm_post_mouse_button(m, (int)st->a, true);
            fprintf(stderr, "[script] press %lld at %d,%d\n",
                    st->a, m->mouse_x, m->mouse_y);
            alive = run_slices(m, CLICK_HOLD_SLICES);
            vm_post_mouse_button(m, (int)st->a, false);
            if (alive) alive = run_slices(m, CLICK_HOLD_SLICES);
            fprintf(stderr, "[script] release %lld at %llu insns\n",
                    st->a, (unsigned long long)m->insn_count);
            break;
        }

        case ST_DOWN:
            vm_post_mouse_button(m, (int)st->a, true);
            fprintf(stderr, "[script] button %lld down at %d,%d\n",
                    st->a, m->mouse_x, m->mouse_y);
            break;

        case ST_UP:
            vm_post_mouse_button(m, (int)st->a, false);
            fprintf(stderr, "[script] button %lld up\n", st->a);
            break;

        case ST_DUMP: {
            /* Emit a raw binary alongside the hex so it can be fed straight
             * to ndisasm; reading 8086 by eye is how subtle mistakes happen. */
            int len = atoi(st->text);
            char path[320];
            FILE *bin;
            uint16_t seg = st->a ? (uint16_t)st->a : m->cpu.s[CPU_DS];
            snprintf(path, sizeof(path), "build/frames/dump_%04X_%04llX.bin",
                     seg, st->b);
            bin = fopen(path, "wb");
            fprintf(stderr, "[script] dump %04X:%04llX (ds=%04X cs=%04X, %d bytes) -> %s\n",
                    seg, st->b, m->cpu.s[CPU_DS], m->cpu.s[CPU_CS], len, path);
            for (int off = 0; off < len; off++) {
                uint8_t byte = seg_r8(seg, (uint16_t)(st->b + off));
                if (bin) fputc(byte, bin);
            }
            if (bin) fclose(bin);
            break;
        }

        case ST_HASH:
            fprintf(stderr, "[script] hash %s = %016llx\n",
                    st->text, (unsigned long long)vm_frame_hash(m));
            break;

        case ST_SHOT:
            if (vm_save_bmp(m, st->text))
                fprintf(stderr, "[script] shot %s at %llu insns\n",
                        st->text, (unsigned long long)m->insn_count);
            else
                fprintf(stderr, "[script] COULD NOT WRITE %s\n", st->text);
            break;
        }
    }
    return alive;
}

/*
 * --hook-at: install a Stage-2 style hook at a guest address and log the
 * registers each time it is reached.
 *
 * This is the same cpu86_hook_install() mechanism that Stage 2 will use to
 * divert execution into statically recompiled C, exercised here as a
 * debugger breakpoint. Running it against real code now is how we find out
 * the mechanism works before anything depends on it.
 */
typedef struct {
    unsigned long exe_offset;
    uint32_t hits;
} hook_probe;

static hook_probe g_hook_probes[256];
static size_t g_hook_probe_count;

static hook_result_t log_hook(cpu86 *c, void *user) {
    hook_probe *probe = (hook_probe *)user;
    if (probe->hits == 0) {
        fprintf(stderr,
            "[hook] exe-code %lu @%04X:%04X  called from %04X:%04X  "
            "AX=%04X DX=%04X DS=%04X  "
            "args=%04X %04X %04X\n",
            probe->exe_offset, c->s[CPU_CS], c->ip,
            seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 2)),
            seg_r16(c->s[CPU_SS], c->r[CPU_SP]),
            c->r[CPU_AX], c->r[CPU_DX], c->s[CPU_DS],
            seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 4)),
            seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 6)),
            seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 8)));
    }
    probe->hits++;
    return HOOK_CONTINUE;   /* observe only; let the guest code run */
}

int main(int argc, char **argv) {
    vm_config cfg;
    vm machine;
    char err[512] = {0};
    uint64_t insns = 20000000ULL;
    char bmp_path[512] = {0};
    char script_path[512] = {0};
    bool vm_only = false;

    memset(&cfg, 0, sizeof(cfg));
    snprintf(cfg.exe_path, sizeof(cfg.exe_path), "original/XANTH.EXE");
    snprintf(cfg.data_dir, sizeof(cfg.data_dir), "game_cd/XANTH");
    snprintf(cfg.save_dir, sizeof(cfg.save_dir), "build/saves");

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--exe") && i + 1 < argc)
            snprintf(cfg.exe_path, sizeof(cfg.exe_path), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--data") && i + 1 < argc)
            snprintf(cfg.data_dir, sizeof(cfg.data_dir), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--saves") && i + 1 < argc)
            snprintf(cfg.save_dir, sizeof(cfg.save_dir), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--insns") && i + 1 < argc)
            insns = strtoull(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--script") && i + 1 < argc)
            snprintf(script_path, sizeof(script_path), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--trace-int"))  cfg.trace_int = true;
        else if (!strcmp(argv[i], "--trace-dos"))  cfg.trace_dos = true;
        else if (!strcmp(argv[i], "--trace-cpu"))  cfg.trace_cpu = true;
        else if (!strcmp(argv[i], "--permissive")) cfg.permissive = true;
        else if (!strcmp(argv[i], "--vm-only")) vm_only = true;
        else if (!strcmp(argv[i], "--watch")) g_watch = true;
        else if (!strcmp(argv[i], "--nonblocking-conin")) cfg.nonblocking_conin = true;
        else if (!strcmp(argv[i], "--hook-at") && i + 1 < argc) {
            if (g_hook_probe_count == sizeof(g_hook_probes) / sizeof(g_hook_probes[0])) {
                fprintf(stderr, "too many --hook-at probes (max %zu)\n",
                        sizeof(g_hook_probes) / sizeof(g_hook_probes[0]));
                return 2;
            }
            g_hook_probes[g_hook_probe_count++].exe_offset = strtoul(argv[++i], NULL, 0);
        }
        else if (!strcmp(argv[i], "--bmp") && i + 1 < argc)
            snprintf(bmp_path, sizeof(bmp_path), "%s", argv[++i]);
        else { fprintf(stderr, "unknown argument: %s\n", argv[i]); return 2; }
    }

    cfg.max_instructions = insns;

    if (script_path[0] && !load_script(script_path)) return 2;

    hal_audio_init();
    vm_audio_opl_write = hal_audio_write_opl;
    vm_audio_dma_write = hal_audio_dma_submit_block;

    if (!vm_init(&machine, &cfg, err, sizeof(err))) {
        fprintf(stderr, "[vm] init failed: %s\n", err);
        hal_audio_shutdown();
        return 1;
    }

    if (!vm_only && !xanth_native_stage2_install(&machine)) {
        fprintf(stderr, "[vm] could not install verified Stage-2 native units\n");
        vm_shutdown(&machine);
        hal_audio_shutdown();
        return 1;
    }

    for (size_t p = 0; p < g_hook_probe_count; p++) {
        /* exe-code offsets are relative to the load segment. */
        uint32_t lin = (uint32_t)machine.img.load_seg * 16u + g_hook_probes[p].exe_offset;
        uint16_t sg = (uint16_t)(lin >> 4), of = (uint16_t)(lin & 0xF);
        if (cpu86_hook_install(sg, of, log_hook, &g_hook_probes[p]))
            fprintf(stderr, "[hook] watching exe-code %lu -> %04X:%04X\n",
                    g_hook_probes[p].exe_offset, sg, of);
        else {
            fprintf(stderr, "[hook] could not install exe-code %lu\n",
                    g_hook_probes[p].exe_offset);
            vm_shutdown(&machine);
            hal_audio_shutdown();
            return 1;
        }
    }

    if (g_step_count)
        run_script(&machine, insns);
    else
        vm_run(&machine, insns);

    for (size_t p = 0; p < g_hook_probe_count; p++)
        fprintf(stderr, "[hook] exe-code %lu hits: %u\n",
                g_hook_probes[p].exe_offset, g_hook_probes[p].hits);
    if (!vm_only)
        fprintf(stderr, "[native] set_int_and_zero hits: %llu\n",
                (unsigned long long)xanth_native_set_int_and_zero_hits());
    if (!vm_only)
        fprintf(stderr, "[native] set_far_ptr hits: %llu\n",
                (unsigned long long)xanth_native_set_far_ptr_hits());
    if (!vm_only)
        fprintf(stderr, "[native] exe_94712 hits: %llu\n",
                (unsigned long long)xanth_native_exe_94712_hits());
    if (!vm_only)
        fprintf(stderr, "[native] if0_helper_inc fast-return hits: %llu\n",
                (unsigned long long)xanth_native_if0_helper_inc_hits());
    if (!vm_only)
        fprintf(stderr, "[native] exe_14360 hits: %llu\n",
                (unsigned long long)xanth_native_exe_14360_hits());
    if (!vm_only)
        fprintf(stderr, "[native] set_far_arr hits: %llu\n",
                (unsigned long long)xanth_native_set_far_arr_hits());
    if (!vm_only)
        fprintf(stderr, "[native] get_far_idx hits: %llu\n",
                (unsigned long long)xanth_native_get_far_idx_hits());
    if (!vm_only)
        fprintf(stderr, "[native] exe_37625 hits: %llu\n",
                (unsigned long long)xanth_native_exe_37625_hits());
    if (!vm_only)
        fprintf(stderr, "[native] exe_99679 hits: %llu\n",
                (unsigned long long)xanth_native_exe_99679_hits());

    vm_report(&machine, stderr);

    if (bmp_path[0]) {
        if (vm_save_bmp(&machine, bmp_path))
            fprintf(stderr, "wrote %s\n", bmp_path);
        else
            fprintf(stderr, "could not write %s\n", bmp_path);
    }

    if (machine.cpu.fault && machine.cpu.fault != CPU_FAULT_EXITED) {
        fprintf(stderr, "\nSTOPPED: %s\n", cpu86_fault_name(machine.cpu.fault));
        vm_dump_state(&machine, stderr);
        vm_shutdown(&machine);
        hal_audio_shutdown();
        return 3;
    }

    vm_shutdown(&machine);
    hal_audio_shutdown();
    return 0;
}
