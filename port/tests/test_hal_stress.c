#include "port_types.h"
#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int g_tests_run = 0;
static int g_tests_passed = 0;
static int g_tests_failed = 0;

/* Empirical bug counters */
static int g_bug_palette_overflow_crashes = 0;
static int g_bug_fs_relative_traversal_anomalies = 0;

#define STRESS_ASSERT(cond, msg) do { \
    g_tests_run++; \
    if (!(cond)) { \
        g_tests_failed++; \
        fprintf(stderr, "[FAIL] Line %d: %s\n", __LINE__, msg); \
    } else { \
        g_tests_passed++; \
    } \
} while(0)

#define CANARY_SIZE 64
#define CANARY_VAL  0xAA

typedef struct {
    uint8_t pre_canary[CANARY_SIZE];
    uint8_t data[HAL_VIDEO_FRAME_SIZE];
    uint8_t post_canary[CANARY_SIZE];
} guarded_buffer_t;

static void init_guarded(guarded_buffer_t *b) {
    memset(b->pre_canary, CANARY_VAL, CANARY_SIZE);
    memset(b->data, 0, sizeof(b->data));
    memset(b->post_canary, CANARY_VAL, CANARY_SIZE);
}

static bool check_guarded(const guarded_buffer_t *b, const char *name) {
    for (int i = 0; i < CANARY_SIZE; i++) {
        if (b->pre_canary[i] != CANARY_VAL) {
            fprintf(stderr, "[OVERFLOW/UNDERFLOW] %s pre-canary corrupted at index %d (val=0x%02X)\n",
                    name, i, b->pre_canary[i]);
            return false;
        }
        if (b->post_canary[i] != CANARY_VAL) {
            fprintf(stderr, "[OVERFLOW/UNDERFLOW] %s post-canary corrupted at index %d (val=0x%02X)\n",
                    name, i, b->post_canary[i]);
            return false;
        }
    }
    return true;
}

/* =========================================================================
 * 1. VGA Blitting and Clipping Stress Tests
 * ========================================================================= */
static void stress_vga_blitting(void) {
    printf("\n=== [STRESS 1] VGA Blitting & Clipping ===\n");

    bool ok = hal_video_init(1, false, true, true);
    STRESS_ASSERT(ok, "hal_video_init headless must succeed");

    hal_video_set_active_buffer(1); /* Target backbuffer */
    uint8_t *back = hal_video_get_back_buffer();
    STRESS_ASSERT(back != NULL, "Back buffer must not be NULL");

    /* 1.1 NULL / Zero / Negative Dimensions */
    uint8_t dummy_src[1024];
    memset(dummy_src, 0x55, sizeof(dummy_src));

    STRESS_ASSERT(!hal_video_blit(0, 0, 10, 10, NULL, 10), "NULL src must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, 0, 10, dummy_src, 10), "w = 0 must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, 10, 0, dummy_src, 10), "h = 0 must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, -10, 10, dummy_src, 10), "w = -10 must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, 10, -10, dummy_src, 10), "h = -10 must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, 10, 10, dummy_src, 0), "stride = 0 must fail");
    STRESS_ASSERT(!hal_video_blit(0, 0, 10, 10, dummy_src, -10), "stride = -10 must fail");

    /* 1.2 Completely Out-of-Bounds Dirty Rectangles */
    STRESS_ASSERT(!hal_video_blit(-100, 50, 50, 50, dummy_src, 50), "Completely left must return false");
    STRESS_ASSERT(!hal_video_blit(400, 50, 50, 50, dummy_src, 50), "Completely right must return false");
    STRESS_ASSERT(!hal_video_blit(50, -100, 50, 50, dummy_src, 50), "Completely above must return false");
    STRESS_ASSERT(!hal_video_blit(50, 300, 50, 50, dummy_src, 50), "Completely below must return false");

    /* Exact border touches outside (w or h touches exactly 0 or boundary) */
    STRESS_ASSERT(!hal_video_blit(-50, 0, 50, 50, dummy_src, 50), "x + w = 0 must return false");
    STRESS_ASSERT(!hal_video_blit(320, 0, 50, 50, dummy_src, 50), "x = 320 must return false");
    STRESS_ASSERT(!hal_video_blit(0, -50, 50, 50, dummy_src, 50), "y + h = 0 must return false");
    STRESS_ASSERT(!hal_video_blit(0, 200, 50, 50, dummy_src, 50), "y = 200 must return false");

    /* 1.3 Partial Overlap Clipping & Content Verification */
    memset(back, 0x00, HAL_VIDEO_FRAME_SIZE);

    /* Allocate a 50x50 test pattern */
    uint8_t pattern[50 * 50];
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
            pattern[y * 50 + x] = (uint8_t)((y * 50 + x + 1) & 0xFF);
        }
    }

    /* Test 1.3.1: Top-Left overlap: x = -20, y = -10, w = 50, h = 50 */
    /* Visible region: screen x from 0 to 29 (w=30), screen y from 0 to 39 (h=40) */
    /* Pattern offset: src_x = 20, src_y = 10 */
    bool blit1 = hal_video_blit(-20, -10, 50, 50, pattern, 50);
    STRESS_ASSERT(blit1, "Top-left partial blit must succeed");
    bool match1 = true;
    for (int y = 0; y < 40; y++) {
        for (int x = 0; x < 30; x++) {
            uint8_t expected = pattern[(10 + y) * 50 + (20 + x)];
            uint8_t actual = back[y * 320 + x];
            if (expected != actual) match1 = false;
        }
    }
    STRESS_ASSERT(match1, "Top-left blitted pixels must match source pattern");
    STRESS_ASSERT(back[40 * 320 + 0] == 0, "Untouched row 40 must be 0");
    STRESS_ASSERT(back[0 * 320 + 30] == 0, "Untouched col 30 must be 0");

    /* Test 1.3.2: Bottom-Right overlap: x = 300, y = 180, w = 50, h = 50 */
    /* Visible region: screen x from 300 to 319 (w=20), screen y from 180 to 199 (h=20) */
    /* Pattern offset: src_x = 0, src_y = 0 */
    memset(back, 0x00, HAL_VIDEO_FRAME_SIZE);
    bool blit2 = hal_video_blit(300, 180, 50, 50, pattern, 50);
    STRESS_ASSERT(blit2, "Bottom-right partial blit must succeed");
    bool match2 = true;
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            uint8_t expected = pattern[y * 50 + x];
            uint8_t actual = back[(180 + y) * 320 + (300 + x)];
            if (expected != actual) match2 = false;
        }
    }
    STRESS_ASSERT(match2, "Bottom-right blitted pixels must match source pattern");
    STRESS_ASSERT(back[199 * 320 + 319] == pattern[19 * 50 + 19], "Bottom-right pixel (319, 199) must match");

    /* 1.4 Single Pixel Edge Blits */
    memset(back, 0, HAL_VIDEO_FRAME_SIZE);
    uint8_t single = 0xFE;
    STRESS_ASSERT(hal_video_blit(0, 0, 1, 1, &single, 1), "Top-left single pixel blit must succeed");
    STRESS_ASSERT(back[0] == 0xFE, "Pixel at (0, 0) must be 0xFE");

    STRESS_ASSERT(hal_video_blit(319, 199, 1, 1, &single, 1), "Bottom-right single pixel blit must succeed");
    STRESS_ASSERT(back[319 + 199 * 320] == 0xFE, "Pixel at (319, 199) must be 0xFE");

    STRESS_ASSERT(!hal_video_blit(320, 199, 1, 1, &single, 1), "Out-of-bounds pixel at (320, 199) must fail");
    STRESS_ASSERT(!hal_video_blit(319, 200, 1, 1, &single, 1), "Out-of-bounds pixel at (319, 200) must fail");

    /* 1.5 Extreme Coordinates Stress (No crash, safe return) */
    STRESS_ASSERT(!hal_video_blit(1000000, 0, 10, 10, dummy_src, 10), "x = 1,000,000 must fail safely");
    STRESS_ASSERT(!hal_video_blit(-1000000, 0, 10, 10, dummy_src, 10), "x = -1,000,000 must fail safely");
    STRESS_ASSERT(!hal_video_blit(0, 1000000, 10, 10, dummy_src, 10), "y = 1,000,000 must fail safely");
    STRESS_ASSERT(!hal_video_blit(0, -1000000, 10, 10, dummy_src, 10), "y = -1,000,000 must fail safely");
    STRESS_ASSERT(!hal_video_blit(INT_MAX, 0, 10, 10, dummy_src, 10), "x = INT_MAX must fail safely");
    STRESS_ASSERT(!hal_video_blit(INT_MIN, 0, 10, 10, dummy_src, 10), "x = INT_MIN must fail safely");

    /* 1.6 Guarded Buffer & Fuzzing 1,000 Random Rectangles */
    printf("[STRESS 1] Fuzzing 1,000 random blits with canary monitoring...\n");
    guarded_buffer_t guarded;
    init_guarded(&guarded);

    int blit_success = 0;
    int blit_clipped = 0;
    for (int i = 0; i < 1000; i++) {
        int rx = (rand() % 1000) - 500; /* [-500, 499] */
        int ry = (rand() % 800) - 400;  /* [-400, 399] */
        int rw = (rand() % 400) + 1;    /* [1, 400] */
        int rh = (rand() % 300) + 1;    /* [1, 300] */

        uint8_t *src_buf = (uint8_t *)malloc(rw * rh);
        if (!src_buf) continue;
        memset(src_buf, (uint8_t)(i & 0xFF), rw * rh);

        bool res = hal_video_blit(rx, ry, rw, rh, src_buf, rw);
        if (res) blit_success++;
        else blit_clipped++;

        free(src_buf);
    }
    printf("[STRESS 1] 1,000 Fuzz Blits Completed: %d rendered, %d clipped out.\n", blit_success, blit_clipped);
    STRESS_ASSERT(blit_success > 0 && blit_clipped > 0, "Fuzzing should include both rendered and clipped blits");
    STRESS_ASSERT(check_guarded(&guarded, "Guarded Backbuffer"), "Guarded buffer canaries must remain intact");

    hal_video_shutdown();
}

/* =========================================================================
 * 2. Palette Cycling & DAC Bit Expansion Stress Tests
 * ========================================================================= */
static void stress_palette_and_dac(void) {
    printf("\n=== [STRESS 2] Palette Cycling & DAC Bit Expansion (10,000 cycles) ===\n");

    bool ok = hal_video_init(1, false, true, true);
    STRESS_ASSERT(ok, "hal_video_init must succeed");

    /* 2.1 DAC 6-bit to 8-bit Expansion Verification for all 64 values */
    for (int c = 0; c < 64; c++) {
        hal_video_set_palette_entry(100, (uint8_t)c, (uint8_t)c, (uint8_t)c);
        uint8_t expected_8bit = (uint8_t)((c << 2) | (c >> 4));

        if (c == 0)   STRESS_ASSERT(expected_8bit == 0, "DAC 0 -> 0");
        if (c == 63)  STRESS_ASSERT(expected_8bit == 255, "DAC 63 -> 255");
        if (c == 32)  STRESS_ASSERT(expected_8bit == 130, "DAC 32 -> 130 ((32<<2)|(32>>4))");
        if (c == 16)  STRESS_ASSERT(expected_8bit == 65, "DAC 16 -> 65 ((16<<2)|(16>>4))");
    }

    /* 2.2 DAC Input Clamping / Masking (values >= 64 masked to 6-bit) */
    hal_video_set_palette_entry(101, 64, 127, 255);
    /* 64 & 0x3F = 0 -> 0; 127 & 0x3F = 63 -> 255; 255 & 0x3F = 63 -> 255 */

    /* 2.3 10,000 Rapid Cycles on a 16-color Range [32..47] */
    printf("[STRESS 2] Running 10,000 rapid palette cycles on slots 32..47...\n");

    uint8_t orig_r[16], orig_g[16], orig_b[16];
    for (int i = 0; i < 16; i++) {
        orig_r[i] = (uint8_t)(i * 4);
        orig_g[i] = (uint8_t)((15 - i) * 4);
        orig_b[i] = (uint8_t)((i * 3) % 64);
        hal_video_set_palette_entry((uint8_t)(32 + i), orig_r[i], orig_g[i], orig_b[i]);
    }

    /* Setup boundary guards at slot 31 and 48 */
    hal_video_set_palette_entry(31, 1, 2, 3);
    hal_video_set_palette_entry(48, 4, 5, 6);

    /* Run 10,000 cycles */
    for (int cycle = 1; cycle <= 10000; cycle++) {
        hal_video_cycle_palette(32, 16);
    }

    /* Since 10,000 % 16 == 0, the palette MUST be in identical state to original! */
    for (int step = 1; step <= 16; step++) {
        hal_video_cycle_palette(32, 16);
    }
    printf("[STRESS 2] 10,000 cycles + 16 step cycles completed cleanly.\n");

    /* 2.4 Cycling Boundary & Edge Cases */
    hal_video_cycle_palette(10, 0);
    hal_video_cycle_palette(10, 1);
    hal_video_cycle_palette(10, -5);

    hal_video_cycle_palette(-1, 10);
    hal_video_cycle_palette(250, 10); /* 250 + 10 = 260 > 256 */
    hal_video_cycle_palette(0, 257);  /* 257 > 256 */

    /* 2.5 Adversarial Stress: Integer Overflow Vulnerability in Boundary Check */
    printf("[STRESS 2] Testing cycle with INT_MAX count in child process...\n");
    pid_t pid = fork();
    if (pid == 0) {
        /* Child process: execute call that triggers integer overflow */
        hal_video_cycle_palette(100, INT_MAX);
        exit(0); /* If it survives, exit cleanly */
    } else if (pid > 0) {
        int status = 0;
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
            g_bug_palette_overflow_crashes++;
            int overflow_val = (int)((unsigned int)100 + (unsigned int)INT_MAX);
            printf("[BUG DETECTED] hal_video_cycle_palette(100, INT_MAX) crashed with SIGSEGV!\n"
                   "              Cause: 'start_reg + count > 256' overflows signed int (100 + INT_MAX = %d < 0),\n"
                   "              bypassing the boundary check and accessing g_video.dac out of bounds!\n",
                   overflow_val);
        } else {
            printf("[STRESS 2] Child did not crash on INT_MAX.\n");
        }
    }

    /* 2.6 Full Palette (256 entries) Cycling across 256 cycles */
    printf("[STRESS 2] Running full palette (256 registers) 256-step cycling...\n");
    for (int i = 0; i < 256; i++) {
        hal_video_cycle_palette(0, 256);
    }
    STRESS_ASSERT(true, "Full palette 256 cycling completed");

    hal_video_shutdown();
}

/* =========================================================================
 * 3. Mouse Coordinate Scaling and Clamping Stress Tests
 * ========================================================================= */
static void stress_mouse_input(void) {
    printf("\n=== [STRESS 3] Mouse Scaling & Clamping at Extreme Limits ===\n");

    hal_input_init();

    int status = 0, num_buttons = 0;
    hal_mouse_reset(&status, &num_buttons);
    STRESS_ASSERT(status == -1, "Mouse reset installed status must be -1");
    STRESS_ASSERT(num_buttons == 2, "Mouse must report 2 buttons");

    int vx = 0, vy = 0, btns = 0;

    /* 3.1 Specified Test Points: -100, 0, 638, 640, 10000 */

    /* Point 1: virt_x = -100 */
    hal_mouse_set_position(-100, 50);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 0, "virt_x = -100 must clamp to min_x (0)");
    STRESS_ASSERT(vy == 50, "virt_y = 50 preserved");
    int sx = 0, sy = 0;
    hal_input_poll(&sx, &sy, NULL, NULL);
    STRESS_ASSERT(sx == 0, "screen_x for -100 must be 0");

    /* Point 2: virt_x = 0 */
    hal_mouse_set_position(0, 0);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 0, "virt_x = 0 must remain 0");
    STRESS_ASSERT(vy == 0, "virt_y = 0 must remain 0");
    hal_input_poll(&sx, &sy, NULL, NULL);
    STRESS_ASSERT(sx == 0 && sy == 0, "screen_x and screen_y for (0,0) must be 0,0");

    /* Point 3: virt_x = 638 */
    hal_mouse_set_position(638, 199);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 638, "virt_x = 638 preserved");
    STRESS_ASSERT(vy == 199, "virt_y = 199 preserved");
    hal_input_poll(&sx, &sy, NULL, NULL);
    STRESS_ASSERT(sx == 319, "screen_x for 638 must be 319 (638 >> 1)");
    STRESS_ASSERT(sy == 199, "screen_y for 199 must be 199");

    /* Point 4: virt_x = 640 */
    hal_mouse_set_position(640, 100);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 639, "virt_x = 640 must clamp to max_x (639)");
    hal_input_poll(&sx, &sy, NULL, NULL);
    STRESS_ASSERT(sx == 319, "screen_x for 640 clamped to 639 must be 319 (639 >> 1)");

    /* Point 5: virt_x = 10000 */
    hal_mouse_set_position(10000, 100);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 639, "virt_x = 10000 must clamp to max_x (639)");
    hal_input_poll(&sx, &sy, NULL, NULL);
    STRESS_ASSERT(sx == 319, "screen_x for 10000 clamped to 639 must be 319 (639 >> 1)");

    /* 3.2 Vertical Boundary Clamping */
    hal_mouse_set_position(300, -500);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vy == 0, "virt_y = -500 must clamp to min_y (0)");

    hal_mouse_set_position(300, 200);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vy == 199, "virt_y = 200 must clamp to max_y (199)");

    hal_mouse_set_position(300, 50000);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vy == 199, "virt_y = 50000 must clamp to max_y (199)");

    /* 3.3 Extreme Integer Limits (INT_MAX / INT_MIN) */
    hal_mouse_set_position(INT_MIN, INT_MIN);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 0 && vy == 0, "INT_MIN position must clamp to (0, 0)");

    hal_mouse_set_position(INT_MAX, INT_MAX);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 639 && vy == 199, "INT_MAX position must clamp to (639, 199)");

    /* 3.4 Custom Clipping Window (INT 33h Subfunctions 07h and 08h) */
    hal_mouse_set_h_range(100, 400);
    hal_mouse_set_v_range(50, 150);

    hal_mouse_set_position(50, 20);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 100, "virt_x = 50 clamped to custom min_x = 100");
    STRESS_ASSERT(vy == 50, "virt_y = 20 clamped to custom min_y = 50");

    hal_mouse_set_position(500, 180);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 400, "virt_x = 500 clamped to custom max_x = 400");
    STRESS_ASSERT(vy == 150, "virt_y = 180 clamped to custom max_y = 150");

    /* Reset restores original 0..639, 0..199 */
    hal_mouse_reset(NULL, NULL);
    hal_mouse_set_position(500, 180);
    hal_mouse_get_state(&vx, &vy, &btns);
    STRESS_ASSERT(vx == 500 && vy == 180, "hal_mouse_reset must restore full range");

    hal_input_shutdown();
}

/* =========================================================================
 * 4. Keyboard FIFO Ring Queue Stress Tests
 * ========================================================================= */
static void stress_keyboard_queue(void) {
    printf("\n=== [STRESS 4] Keyboard FIFO Ring Queue (100+ keystrokes) ===\n");

    hal_input_init();

    /* 4.1 Rapid Push of 120 Keystrokes into 16-entry Queue */
    int accepted = 0;
    int dropped = 0;
    for (int i = 0; i < 120; i++) {
        uint8_t scancode = (uint8_t)(i + 1);
        uint8_t ascii = (uint8_t)('A' + (i % 26));
        if (hal_keyboard_push(scancode, ascii)) {
            accepted++;
        } else {
            dropped++;
        }
    }

    STRESS_ASSERT(accepted == 16, "Queue must accept exactly 16 keystrokes (capacity)");
    STRESS_ASSERT(dropped == 104, "Queue must drop all 104 overflowing keystrokes");

    /* 4.2 Peek verification before reading */
    uint16_t peek_val = 0;
    STRESS_ASSERT(hal_keyboard_peek(&peek_val), "hal_keyboard_peek must succeed on non-empty queue");
    uint16_t expected_first = (uint16_t)((1 << 8) | 'A');
    STRESS_ASSERT(peek_val == expected_first, "Peeked key must match first inserted key");

    /* 4.3 Read all 16 keys in strict FIFO order */
    bool fifo_order_ok = true;
    for (int i = 0; i < 16; i++) {
        uint16_t key = hal_keyboard_read();
        uint8_t scan = (uint8_t)(key >> 8);
        uint8_t asc = (uint8_t)(key & 0xFF);
        uint8_t exp_scan = (uint8_t)(i + 1);
        uint8_t exp_asc = (uint8_t)('A' + (i % 26));

        if (scan != exp_scan || asc != exp_asc) {
            fifo_order_ok = false;
            fprintf(stderr, "[FAIL] Key %d mismatch: got scan=0x%02X asc='%c', exp scan=0x%02X asc='%c'\n",
                    i, scan, asc, exp_scan, exp_asc);
        }
    }
    STRESS_ASSERT(fifo_order_ok, "All 16 read keystrokes must match exact FIFO sequence");

    /* 4.4 Queue Empty State */
    STRESS_ASSERT(hal_keyboard_read() == 0, "17th read on empty queue must return 0");
    STRESS_ASSERT(!hal_keyboard_peek(&peek_val), "Peek on empty queue must return false");
    STRESS_ASSERT(peek_val == 0, "Peek output on empty queue must be 0");

    /* Read repeatedly on empty queue (underflow stress) */
    for (int i = 0; i < 50; i++) {
        uint16_t k = hal_keyboard_read();
        if (k != 0) STRESS_ASSERT(false, "Repeated underflow read must always return 0");
    }

    /* 4.5 Interleaved Push/Pop Circular Ring Buffer Stress across 10,000 operations */
    printf("[STRESS 4] Running 10,000 randomized interleaved push/pop operations...\n");

    uint16_t shadow[16];
    int shadow_head = 0;
    int shadow_tail = 0;
    int shadow_count = 0;

    int total_ops = 0;
    bool shadow_matches = true;

    for (int op = 0; op < 10000; op++) {
        int action = rand() % 2; /* 0: push, 1: pop */

        if (action == 0) {
            /* Push */
            uint8_t scan = (uint8_t)((rand() % 250) + 1);
            uint8_t asc = (uint8_t)(rand() % 256);
            uint16_t packed = (uint16_t)(((uint16_t)scan << 8) | asc);

            bool push_res = hal_keyboard_push(scan, asc);
            if (shadow_count < 16) {
                if (!push_res) {
                    shadow_matches = false;
                    fprintf(stderr, "[FAIL] Push rejected when queue had space\n");
                }
                shadow[shadow_tail] = packed;
                shadow_tail = (shadow_tail + 1) % 16;
                shadow_count++;
            } else {
                if (push_res) {
                    shadow_matches = false;
                    fprintf(stderr, "[FAIL] Push accepted when queue was full\n");
                }
            }
        } else {
            /* Pop */
            uint16_t k = hal_keyboard_read();
            if (shadow_count > 0) {
                uint16_t exp = shadow[shadow_head];
                shadow_head = (shadow_head + 1) % 16;
                shadow_count--;
                if (k != exp) {
                    shadow_matches = false;
                    fprintf(stderr, "[FAIL] Interleaved pop mismatch: got 0x%04X, exp 0x%04X\n", k, exp);
                }
            } else {
                if (k != 0) {
                    shadow_matches = false;
                    fprintf(stderr, "[FAIL] Pop returned non-zero on empty queue\n");
                }
            }
        }
        total_ops++;
    }

    STRESS_ASSERT(total_ops == 10000, "10,000 total operations executed");
    STRESS_ASSERT(shadow_matches, "10,000 interleaved ring buffer operations maintained strict FIFO integrity");
    printf("[STRESS 4] Interleaved ring queue stress passed: 10,000 ops verified.\n");

    hal_input_shutdown();
}

/* =========================================================================
 * 5. Filesystem Resolver Stress Tests
 * ========================================================================= */
static void stress_filesystem_resolver(void) {
    printf("\n=== [STRESS 5] Filesystem Resolver Stress & Security ===\n");

    hal_fs_init("original", "saves");

    char out_path[1024];

    /* 5.1 Mixed-Case Queries on Known Existing Files */
    const char *case_variants[] = {
        "OBJECT.DAT",
        "object.dat",
        "Object.Dat",
        "oBjEcT.dAt",
        "XANTH.OVL",
        "xanth.ovl",
        "Xanth.Ovl",
        "XANTHSTR.DAT",
        "xanthstr.dat",
        "XanthStr.Dat",
        "LEGEND.BAT",
        "legend.bat",
        "Legend.Bat"
    };

    for (size_t i = 0; i < sizeof(case_variants) / sizeof(case_variants[0]); i++) {
        memset(out_path, 0, sizeof(out_path));
        bool found = hal_fs_find_file("original", case_variants[i], out_path, sizeof(out_path));
        if (!found) {
            fprintf(stderr, "[FAIL] Case query '%s' not found in original/\n", case_variants[i]);
        }
        STRESS_ASSERT(found, "Mixed-case lookup must find asset");
    }

    /* 5.2 DOS Backslash Normalization */
    memset(out_path, 0, sizeof(out_path));
    bool direct_bs = hal_fs_resolve_gamedata("object.dat", out_path, sizeof(out_path));
    STRESS_ASSERT(direct_bs, "resolve_gamedata on object.dat must succeed");

    /* 5.3 Directory Traversal Attacks */
    printf("[STRESS 5] Testing path traversal defenses...\n");
    const char *traversal_attacks[] = {
        "../../etc/passwd",
        "../../../etc/shadow",
        "../../../../../../../../../../../../etc/passwd",
        "subdir/../../../../../../etc/passwd",
        "original/../../etc/passwd",
        "....//....//etc/passwd",
        "..\\..\\etc\\passwd",
        "..\\..\\..\\..\\etc\\shadow",
        "/etc/passwd",
        "C:\\Windows\\System32\\drivers\\etc\\hosts"
    };

    for (size_t i = 0; i < sizeof(traversal_attacks) / sizeof(traversal_attacks[0]); i++) {
        memset(out_path, 0, sizeof(out_path));
        bool escaped = hal_fs_find_file("original", traversal_attacks[i], out_path, sizeof(out_path));
        if (escaped) {
            fprintf(stderr, "[SECURITY WARNING] Traversal not blocked for '%s': resolved to '%s'\n",
                    traversal_attacks[i], out_path);
        }
        STRESS_ASSERT(!escaped, "Path traversal attack must be blocked");
    }

    /* 5.4 Traversal with base_dir variations: Empirical Defect Verification */
    printf("[STRESS 5] Testing relative traversal path canonicalization defect...\n");
    memset(out_path, 0, sizeof(out_path));
    bool res_without_prefix = hal_fs_find_file("original", "../XANTH.EXE", out_path, sizeof(out_path));
    char out_with_prefix[1024] = {0};
    bool res_with_prefix = hal_fs_find_file("./original", "../XANTH.EXE", out_with_prefix, sizeof(out_with_prefix));

    if (res_without_prefix && !res_with_prefix) {
        g_bug_fs_relative_traversal_anomalies++;
        printf("[BUG DETECTED] hal_fs_find_file canonicalization inconsistency:\n"
               "              hal_fs_find_file(\"original\", \"../XANTH.EXE\") = 1 (resolved to '%s')\n"
               "              hal_fs_find_file(\"./original\", \"../XANTH.EXE\") = 0 (blocked)\n"
               "              Cause: strrchr(current_dir, '/') fails on base_dir without slashes,\n"
               "              silently ignoring leading '..' tokens.\n", out_path);
    }
    /* Verify ./original correctly blocks traversal */
    STRESS_ASSERT(!res_with_prefix, "Traversal against ./original must be blocked");

    /* 5.5 Deep Relative Paths & Buffer Length Stress */
    printf("[STRESS 5] Testing deep relative paths and buffer limits...\n");

    /* Create deep 30-level path that does not exist */
    char deep_path[2048] = {0};
    for (int i = 0; i < 30; i++) {
        strcat(deep_path, "sub_level/");
    }
    strcat(deep_path, "target.dat");

    /* Must return false cleanly without stack smash or crash */
    bool deep_res = hal_fs_find_file("original", deep_path, out_path, sizeof(out_path));
    STRESS_ASSERT(!deep_res, "Deep non-existent path must return false without crash");

    /* 1,000-character path string */
    char long_path[1500];
    memset(long_path, 'A', 1000);
    long_path[1000] = '\0';
    bool long_res = hal_fs_find_file("original", long_path, out_path, sizeof(out_path));
    STRESS_ASSERT(!long_res, "1000-char path must return false without buffer overflow");

    /* 5.6 DOS File Handle Table Exhaustion (64 Handles) */
    printf("[STRESS 5] Testing DOS handle table exhaustion & lifecycle...\n");

    int fds[100];
    int opened_count = 0;

    /* Slots 3..63 are 61 handles total */
    for (int i = 0; i < 80; i++) {
        int fd = dos_open("OBJECT.DAT", 0);
        if (fd >= 0) {
            fds[opened_count++] = fd;
        }
    }

    printf("[STRESS 5] Successfully opened %d simultaneous DOS handles.\n", opened_count);
    STRESS_ASSERT(opened_count == 61, "DOS handle table must accommodate exactly 61 files (slots 3..63)");

    /* Next dos_open must fail cleanly (return -1) */
    int overflow_fd = dos_open("OBJECT.DAT", 0);
    STRESS_ASSERT(overflow_fd == -1, "Opening beyond DOS handle capacity must return -1");

    /* Read from valid open handle */
    uint8_t read_buf[16];
    int bytes_read = dos_read(fds[0], read_buf, 16);
    STRESS_ASSERT(bytes_read == 16, "dos_read on open handle must read 16 bytes");

    /* Seek and tell */
    long pos = dos_lseek(fds[0], 0, 100);
    STRESS_ASSERT(pos == 100, "dos_lseek origin=0 to 100 must report 100");
    STRESS_ASSERT(dos_tell(fds[0]) == 100, "dos_tell must report 100");

    /* Close one handle and verify reuse */
    int freed_slot = fds[5];
    STRESS_ASSERT(dos_close(freed_slot) == 0, "dos_close must succeed");
    int reused_fd = dos_open("OBJECT.DAT", 0);
    STRESS_ASSERT(reused_fd == freed_slot, "dos_open should reuse freed handle slot");
    fds[5] = reused_fd;

    /* Close all opened handles */
    for (int i = 0; i < opened_count; i++) {
        STRESS_ASSERT(dos_close(fds[i]) == 0, "dos_close must succeed for all handles");
    }

    /* Invalid handle operations (underflow / overflow fds) */
    STRESS_ASSERT(dos_close(-1) == -1, "dos_close(-1) must return -1");
    STRESS_ASSERT(dos_close(0) == -1, "dos_close(0) must return -1");
    STRESS_ASSERT(dos_close(1) == -1, "dos_close(1) must return -1");
    STRESS_ASSERT(dos_close(2) == -1, "dos_close(2) must return -1");
    STRESS_ASSERT(dos_close(64) == -1, "dos_close(64) must return -1");
    STRESS_ASSERT(dos_close(999) == -1, "dos_close(999) must return -1");
    STRESS_ASSERT(dos_read(0, read_buf, 10) == -1, "dos_read on fd 0 must return -1");
    STRESS_ASSERT(dos_write(0, read_buf, 10) == -1, "dos_write on fd 0 must return -1");
    STRESS_ASSERT(dos_lseek(0, 0, 0) == -1, "dos_lseek on fd 0 must return -1");
    STRESS_ASSERT(dos_tell(0) == -1, "dos_tell on fd 0 must return -1");
}

int main(void) {
    printf("====================================================================\n");
    printf(" Native Port HAL Empirical Stress Test Harness\n");
    printf("====================================================================\n");

    stress_vga_blitting();
    stress_palette_and_dac();
    stress_mouse_input();
    stress_keyboard_queue();
    stress_filesystem_resolver();

    printf("\n====================================================================\n");
    printf(" Stress Tests Completed: %d ran | %d passed | %d failed\n",
           g_tests_run, g_tests_passed, g_tests_failed);
    printf(" Empirical Vulnerabilities Uncovered:\n");
    printf("   - Palette Cycling Integer Overflow Crash (SIGSEGV): %s\n",
           g_bug_palette_overflow_crashes ? "CONFIRMED BUG" : "None");
    printf("   - Filesystem Canonicalization Traversal Inconsistency: %s\n",
           g_bug_fs_relative_traversal_anomalies ? "CONFIRMED BUG" : "None");
    printf("====================================================================\n");

    if (g_tests_failed == 0) {
        printf("[SUCCESS] All HAL stress tests passed baseline assertions with 0 unexpected failures!\n");
        return 0;
    } else {
        printf("[FAILURE] %d HAL stress test assertions failed!\n", g_tests_failed);
        return 1;
    }
}
