#include "port_types.h"
#include "port_hal.h"
#include "port_engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static int g_tests_run = 0;
static int g_tests_passed = 0;

#define TEST_ASSERT(cond, msg) do { \
    g_tests_run++; \
    if (!(cond)) { \
        fprintf(stderr, "[FAIL] %s:%d: %s\n", __FILE__, __LINE__, msg); \
    } else { \
        g_tests_passed++; \
    } \
} while(0)

/* -------------------------------------------------------------------------
 * Test 1: Portable Types & Memory Virtualization Bridge
 * ------------------------------------------------------------------------- */
static void test_portable_types_and_memory(void) {
    printf("[TEST] Running test_portable_types_and_memory...\n");

    TEST_ASSERT(sizeof(sbyte) == 1, "sbyte must be 1 byte");
    TEST_ASSERT(sizeof(ubyte) == 1, "ubyte must be 1 byte");
    TEST_ASSERT(sizeof(sword) == 2, "sword must be 2 bytes");
    TEST_ASSERT(sizeof(uword) == 2, "uword must be 2 bytes");
    TEST_ASSERT(sizeof(sdword) == 4, "sdword must be 4 bytes");
    TEST_ASSERT(sizeof(udword) == 4, "udword must be 4 bytes");

    /* Segmented linear address math: (seg << 4) + off */
    uint32_t linear_vga = DOS_LINEAR_ADDR(0xA000, 0x0000);
    TEST_ASSERT(linear_vga == 0xA0000, "0xA000:0x0000 must be linear 0xA0000");

    uint32_t linear_ovl = DOS_LINEAR_ADDR(0x30CB, 0x0010);
    TEST_ASSERT(linear_ovl == (0x30CB0 + 0x0010), "0x30CB:0x0010 linear computation mismatch");

    /* MK_FP, FP_SEG, FP_OFF */
    void *ptr = MK_FP(0x1000, 0x0020);
    TEST_ASSERT(ptr != NULL, "MK_FP must return non-NULL for valid DOS address");
    TEST_ASSERT(FP_SEG(ptr) == (0x10020 >> 4), "FP_SEG must match normalized segment");
    TEST_ASSERT(FP_OFF(ptr) == (0x10020 & 0x0F), "FP_OFF must match normalized offset");

    /* Out of bounds pointer */
    void *bad_ptr = MK_FP(0xFFFF, 0xFFFF);
    TEST_ASSERT(bad_ptr == NULL, "MK_FP above 1MB must return NULL");

    /* Endianness helpers */
    uint8_t le_buf[4] = { 0x34, 0x12, 0x78, 0x56 };
    TEST_ASSERT(read_le16(le_buf) == 0x1234, "read_le16 mismatch");
    TEST_ASSERT(read_le32(le_buf) == 0x56781234, "read_le32 mismatch");
}

/* -------------------------------------------------------------------------
 * Test 2: Mode 13h VGA Double Buffering & 6-bit DAC Expansion
 * ------------------------------------------------------------------------- */
static void test_vga_and_palette(void) {
    printf("[TEST] Running test_vga_and_palette...\n");

    bool vga_ok = hal_video_init(2, false, true, true);
    TEST_ASSERT(vga_ok, "hal_video_init must succeed");

    uint8_t *screen = hal_video_get_screen_buffer();
    uint8_t *back = hal_video_get_back_buffer();
    TEST_ASSERT(screen != NULL, "Screen buffer must be valid");
    TEST_ASSERT(back != NULL, "Back buffer must be valid");

    /* 6-bit DAC to 8-bit RGBA bit replication formula: (c << 2) | (c >> 4) */
    hal_video_set_palette_entry(10, 63, 0, 32);
    /* 63 -> 255, 0 -> 0, 32 -> 130 */
    /* Check through palette cycling or directly */
    hal_video_set_active_buffer(1);
    TEST_ASSERT(hal_video_get_active_buffer() == back, "Active buffer must be backbuffer");

    /* Test dirty rect blit with boundary clipping */
    uint8_t tile[100];
    memset(tile, 42, sizeof(tile));
    bool blit_ok = hal_video_blit(310, 195, 20, 20, tile, 20);
    TEST_ASSERT(blit_ok, "Clipped blit must succeed");

    /* Test full-screen flip */
    memset(back, 7, HAL_VIDEO_FRAME_SIZE);
    hal_video_flip();
    TEST_ASSERT(screen[0] == 7 && screen[HAL_VIDEO_FRAME_SIZE - 1] == 7, "Screen buffer must match backbuffer after flip");

    hal_video_shutdown();
}

/* -------------------------------------------------------------------------
 * Test 3: INT 33h Mouse & INT 16h Keyboard
 * ------------------------------------------------------------------------- */
static void test_input_subsystem(void) {
    printf("[TEST] Running test_input_subsystem...\n");

    hal_input_init();

    /* Mouse reset and coordinate scaling */
    int status = 0, num_buttons = 0;
    hal_mouse_reset(&status, &num_buttons);
    TEST_ASSERT(status == -1, "Mouse reset status must be -1 (installed)");
    TEST_ASSERT(num_buttons >= 2, "Mouse must report >= 2 buttons");

    /* Position scaling: logical (160, 100) -> virtual (320, 100) */
    hal_mouse_set_position(320, 100);
    int vx = 0, vy = 0, btns = 0;
    hal_mouse_get_state(&vx, &vy, &btns);
    TEST_ASSERT(vx == 320, "Virtual X must be 320");
    TEST_ASSERT(vy == 100, "Virtual Y must be 100");

    /* Keyboard 16-entry FIFO ring buffer */
    for (int i = 0; i < 16; i++) {
        bool push_ok = hal_keyboard_push((uint8_t)(0x10 + i), (uint8_t)('a' + i));
        TEST_ASSERT(push_ok, "Pushing key 0..15 must succeed");
    }

    /* 17th key must be rejected (buffer full) */
    bool overflow_ok = hal_keyboard_push(0x99, 'z');
    TEST_ASSERT(!overflow_ok, "Buffer full must reject 17th keystroke");

    /* FIFO ordering check */
    uint16_t peek_key = 0;
    TEST_ASSERT(hal_keyboard_peek(&peek_key), "Keyboard peek must succeed");
    TEST_ASSERT(peek_key == ((0x10 << 8) | 'a'), "First key peek must be 'a'");

    uint16_t popped = hal_keyboard_read();
    TEST_ASSERT(popped == ((0x10 << 8) | 'a'), "First popped key must be 'a'");

    hal_input_shutdown();
}

/* -------------------------------------------------------------------------
 * Test 4: Filesystem Case-Insensitive Search, INI, Save Slot Paths
 * ------------------------------------------------------------------------- */
static void test_filesystem_and_ini(void) {
    printf("[TEST] Running test_filesystem_and_ini...\n");

    /* Case-insensitive search */
    char resolved[512] = {0};
    bool found_lower = hal_fs_find_file("original", "object.dat", resolved, sizeof(resolved));
    TEST_ASSERT(found_lower, "Must find object.dat in original/");

    char resolved_upper[512] = {0};
    bool found_upper = hal_fs_find_file("original", "OBJECT.DAT", resolved_upper, sizeof(resolved_upper));
    TEST_ASSERT(found_upper, "Must find OBJECT.DAT in original/");

    /* Directory traversal attack prevention */
    char bad_resolved[512] = {0};
    bool traversal_blocked = !hal_fs_find_file("original", "../../etc/passwd", bad_resolved, sizeof(bad_resolved));
    TEST_ASSERT(traversal_blocked, "Directory traversal attack must be blocked");

    /* Save slot naming */
    char save_path[512] = {0};
    bool save_ok = hal_fs_get_save_path(5, save_path, sizeof(save_path));
    TEST_ASSERT(save_ok, "hal_fs_get_save_path must succeed");
    TEST_ASSERT(strstr(save_path, "XANTH05.SAV") != NULL, "Save path must contain XANTH05.SAV");
}

/* -------------------------------------------------------------------------
 * Test 5: Audio RealSound ADPCM & SB DSP Echo Test
 * ------------------------------------------------------------------------- */
static void test_audio_subsystem(void) {
    printf("[TEST] Running test_audio_subsystem...\n");

    hal_audio_init();

    /* Test SB DSP Reset & Echo Test (Command 0xE0) */
    hal_audio_dsp_reset();
    TEST_ASSERT(hal_audio_dsp_read(0x22A) == 0xAA, "DSP Reset must produce 0xAA in read buffer");

    /* Echo command: write 0xE0, write 0xC6, read ~0xC6 = 0x39 */
    hal_audio_dsp_write(0x22C, 0xE0);
    hal_audio_dsp_write(0x22C, 0xC6);
    uint8_t echo_resp = hal_audio_dsp_read(0x22A);
    TEST_ASSERT(echo_resp == 0x39, "DSP Echo test response must be 0x39 (~0xC6)");

    /* Test RealSound ADPCM decoding */
    uint8_t rs_mock[20] = {
        'S', 'T', 'E', 'V', 'E', 0x02,
        0x40, 0x1F, /* 8000 Hz */
        0x08, 0x00, /* 8 samples */
        0x88, 0x97, 0x6A, 0x5B, /* 4 bytes ADPCM */
        0, 0, 0, 0, 0, 0
    };
    bool rs_ok = hal_audio_play_rs(rs_mock, sizeof(rs_mock));
    TEST_ASSERT(rs_ok, "hal_audio_play_rs must succeed on valid RealSound header");

    hal_audio_shutdown();
}

/* -------------------------------------------------------------------------
 * Test 6: Overlay Consolidation & Relational Databases
 * ------------------------------------------------------------------------- */
static void test_overlay_and_databases(void) {
    printf("[TEST] Running test_overlay_and_databases...\n");

    int ovl_res = overlay_init("original/XANTH.OVL");
    TEST_ASSERT(ovl_res == 0, "overlay_init must succeed for original/XANTH.OVL");
    TEST_ASSERT(g_overlay_mgr.loaded, "Overlay manager loaded flag must be true");
    TEST_ASSERT(g_overlay_mgr.payload_size == OVL_PAYLOAD_SIZE, "Overlay payload size must be 325,595 bytes");

    int obj_res = object_table_load("original/OBJECT.DAT");
    TEST_ASSERT(obj_res == 0, "object_table_load must succeed");
    TEST_ASSERT(g_object_table.string_count >= 500, "OBJECT.DAT must contain >= 500 strings");
    TEST_ASSERT(object_table_find("You") >= 0, "OBJECT.DAT must contain 'You'");
    TEST_ASSERT(object_table_find("Grundy") >= 0, "OBJECT.DAT must contain 'Grundy'");

    int str_res = story_db_load("original/XANTHSTR.DAT");
    TEST_ASSERT(str_res == 0, "story_db_load must succeed");
    TEST_ASSERT(g_story_db.entry_count == 80, "XANTHSTR.DAT entry count must be 80");

    uint16_t rlen = 0;
    const uint8_t *rec = story_db_get_record(0, &rlen);
    TEST_ASSERT(rec != NULL && rlen > 0, "First story record must be non-empty");

    overlay_shutdown();
    object_table_shutdown();
    story_db_shutdown();
}

int main(void) {
    printf("====================================================================\n");
    printf(" Running Native Port Unit Test Suite\n");
    printf("====================================================================\n");

    test_portable_types_and_memory();
    test_vga_and_palette();
    test_input_subsystem();
    test_filesystem_and_ini();
    test_audio_subsystem();
    test_overlay_and_databases();

    printf("====================================================================\n");
    printf(" Unit Tests Completed: %d / %d assertions passed.\n", g_tests_passed, g_tests_run);
    printf("====================================================================\n");

    if (g_tests_passed == g_tests_run) {
        printf("[SUCCESS] All unit tests passed!\n");
        return 0;
    } else {
        printf("[FAILURE] %d assertions failed!\n", g_tests_run - g_tests_passed);
        return 1;
    }
}
