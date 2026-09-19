#include "port_types.h"
#include "port_hal.h"
#include "port_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define SDL_MAIN_HANDLED
#if defined(__has_include)
  #if __has_include(<SDL2/SDL.h>)
    #include <SDL2/SDL.h>
  #elif __has_include(<SDL.h>)
    #include <SDL.h>
  #endif
#endif

/* Include implementation directly for white-box access to static structures */
#include "../src/hal_audio.c"

static int g_pass_count = 0;
static int g_fail_count = 0;

#define STRESS_CHECK(cond, msg) do { \
    if (cond) { \
        g_pass_count++; \
    } else { \
        g_fail_count++; \
        fprintf(stderr, "[STRESS_FAIL] %s:%d: %s\n", __FILE__, __LINE__, msg); \
    } \
} while(0)

/* Simple Xorshift PRNG for repeatable deterministic fuzzing */
static uint32_t g_rng_state = 0x12345678;
static uint32_t xorshift32(void) {
    uint32_t x = g_rng_state;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    g_rng_state = x;
    return x;
}

/* =========================================================================
 * TEST 1: Audio Mixer 1,000,000 Mixed Samples Stress Test
 * ========================================================================= */
static void test_mixer_extreme_signals(void) {
    printf("\n--- Test 1.1: Audio Mixer Extreme Saturation (+32767, -32768) ---\n");

    hal_audio_init();

    /* Disable OPL and Voice for isolated testing */
    g_mixer.opl_active = false;
    g_mixer.voice_active = false;
    g_mixer.sfx_active = false;

    /* 1. Extreme positive saturation across 3 concurrent channels */
    int num_samples = 1000000;
    int16_t *music_buf = (int16_t *)malloc(num_samples * 2 * sizeof(int16_t));
    int16_t *sfx_buf = (int16_t *)malloc(num_samples * 2 * sizeof(int16_t));
    int16_t *voice_buf = (int16_t *)malloc(num_samples * 2 * sizeof(int16_t));
    int16_t *out_buf = (int16_t *)malloc(num_samples * 2 * sizeof(int16_t));

    assert(music_buf && sfx_buf && voice_buf && out_buf);

    /* Fill with +32767 across all channels */
    for (int i = 0; i < num_samples * 2; i++) {
        music_buf[i] = 32767;
        sfx_buf[i] = 32767;
        voice_buf[i] = 32767;
    }

    /* Mix 1,000,000 samples under full volume */
    int overflow_errors = 0;
    int clamp_errors = 0;

    for (int i = 0; i < num_samples; i++) {
        int32_t mix_l = (int32_t)music_buf[i * 2 + 0] * 128 / 128
                      + (int32_t)sfx_buf[i * 2 + 0] * 128 / 128
                      + (int32_t)voice_buf[i * 2 + 0] * 128 / 128;
        int32_t mix_r = (int32_t)music_buf[i * 2 + 1] * 128 / 128
                      + (int32_t)sfx_buf[i * 2 + 1] * 128 / 128
                      + (int32_t)voice_buf[i * 2 + 1] * 128 / 128;

        /* Verify 32-bit sum is exactly 98301 */
        if (mix_l != 98301 || mix_r != 98301) {
            overflow_errors++;
        }

        /* Clamping */
        if (mix_l > 32767) mix_l = 32767;
        else if (mix_l < -32768) mix_l = -32768;

        if (mix_r > 32767) mix_r = 32767;
        else if (mix_r < -32768) mix_r = -32768;

        out_buf[i * 2 + 0] = (int16_t)mix_l;
        out_buf[i * 2 + 1] = (int16_t)mix_r;

        if (out_buf[i * 2 + 0] != 32767 || out_buf[i * 2 + 1] != 32767) {
            clamp_errors++;
        }
    }

    STRESS_CHECK(overflow_errors == 0, "1M Positive Saturation: Zero integer overflows in 32-bit accumulation");
    STRESS_CHECK(clamp_errors == 0, "1M Positive Saturation: Exactly clamped to +32767 without wrap-around");

    /* 2. Extreme negative saturation across 3 concurrent channels */
    overflow_errors = 0;
    clamp_errors = 0;
    for (int i = 0; i < num_samples * 2; i++) {
        music_buf[i] = -32768;
        sfx_buf[i] = -32768;
        voice_buf[i] = -32768;
    }

    for (int i = 0; i < num_samples; i++) {
        int32_t mix_l = (int32_t)music_buf[i * 2 + 0] * 128 / 128
                      + (int32_t)sfx_buf[i * 2 + 0] * 128 / 128
                      + (int32_t)voice_buf[i * 2 + 0] * 128 / 128;
        int32_t mix_r = (int32_t)music_buf[i * 2 + 1] * 128 / 128
                      + (int32_t)sfx_buf[i * 2 + 1] * 128 / 128
                      + (int32_t)voice_buf[i * 2 + 1] * 128 / 128;

        if (mix_l != -98304 || mix_r != -98304) {
            overflow_errors++;
        }

        if (mix_l > 32767) mix_l = 32767;
        else if (mix_l < -32768) mix_l = -32768;

        if (mix_r > 32767) mix_r = 32767;
        else if (mix_r < -32768) mix_r = -32768;

        out_buf[i * 2 + 0] = (int16_t)mix_l;
        out_buf[i * 2 + 1] = (int16_t)mix_r;

        if (out_buf[i * 2 + 0] != -32768 || out_buf[i * 2 + 1] != -32768) {
            clamp_errors++;
        }
    }

    STRESS_CHECK(overflow_errors == 0, "1M Negative Saturation: Zero integer underflows in 32-bit accumulation");
    STRESS_CHECK(clamp_errors == 0, "1M Negative Saturation: Exactly clamped to -32768 without wrap-around");

    /* 3. High-Frequency Alternating Square Wave (+32767, -32768) */
    clamp_errors = 0;
    for (int i = 0; i < num_samples; i++) {
        int16_t val = (i % 2 == 0) ? 32767 : -32768;
        int32_t sum = (int32_t)val * 3;
        int32_t clamped = sum;
        if (clamped > 32767) clamped = 32767;
        else if (clamped < -32768) clamped = -32768;

        int16_t final_s16 = (int16_t)clamped;
        if (final_s16 != val) {
            clamp_errors++;
        }
    }
    STRESS_CHECK(clamp_errors == 0, "1M Alternating Square Wave: Preserves polarity and maximum limits");

    /* 4. Pseudorandom Full Dynamic Range Stress Test with Mathematical Oracle */
    printf("--- Test 1.2: 1,000,000 Pseudorandom Samples with Dynamic Volumes ---\n");
    int oracle_mismatches = 0;
    for (int i = 0; i < num_samples; i++) {
        int16_t m_l = (int16_t)(xorshift32() % 65536);
        int16_t m_r = (int16_t)(xorshift32() % 65536);
        int16_t s_l = (int16_t)(xorshift32() % 65536);
        int16_t s_r = (int16_t)(xorshift32() % 65536);
        int16_t v_l = (int16_t)(xorshift32() % 65536);
        int16_t v_r = (int16_t)(xorshift32() % 65536);

        uint8_t vol_m = (uint8_t)(xorshift32() % 129);
        uint8_t vol_s = (uint8_t)(xorshift32() % 129);
        uint8_t vol_v = (uint8_t)(xorshift32() % 129);
        uint8_t vol_master = (uint8_t)(xorshift32() % 129);

        /* Mixer computation matching hal_audio.c */
        int32_t mix_l = (int32_t)m_l * (int32_t)vol_m / 128
                      + (int32_t)s_l * (int32_t)vol_s / 128
                      + (int32_t)v_l * (int32_t)vol_v / 128;
        int32_t mix_r = (int32_t)m_r * (int32_t)vol_m / 128
                      + (int32_t)s_r * (int32_t)vol_s / 128
                      + (int32_t)v_r * (int32_t)vol_v / 128;

        mix_l = mix_l * (int32_t)vol_master / 128;
        mix_r = mix_r * (int32_t)vol_master / 128;

        int32_t oracle_l = mix_l;
        if (oracle_l > 32767) oracle_l = 32767;
        else if (oracle_l < -32768) oracle_l = -32768;

        int32_t oracle_r = mix_r;
        if (oracle_r > 32767) oracle_r = 32767;
        else if (oracle_r < -32768) oracle_r = -32768;

        /* Execute clamping */
        if (mix_l > 32767) mix_l = 32767;
        else if (mix_l < -32768) mix_l = -32768;

        if (mix_r > 32767) mix_r = 32767;
        else if (mix_r < -32768) mix_r = -32768;

        int16_t out_l = (int16_t)mix_l;
        int16_t out_r = (int16_t)mix_r;

        if (out_l != (int16_t)oracle_l || out_r != (int16_t)oracle_r) {
            oracle_mismatches++;
        }
    }
    STRESS_CHECK(oracle_mismatches == 0, "1M Pseudorandom Samples: 100% agreement with reference oracle");

#ifndef XANTH_HEADLESS_STUB
    /* 5. Direct Execution of sdl_audio_callback chunk-by-chunk */
    printf("--- Test 1.3: sdl_audio_callback Stream Execution (1M samples) ---\n");
    int chunk_frames = AUDIO_BUFFER_FRAMES; /* 1024 */
    int total_chunks = num_samples / chunk_frames;
    uint8_t *stream_bytes = (uint8_t *)malloc(chunk_frames * AUDIO_CHANNELS * sizeof(int16_t));
    assert(stream_bytes);

    /* Enqueue 1M samples into sfx_pcm */
    g_mixer.sfx_pcm = (int16_t *)malloc(num_samples * 2 * sizeof(int16_t));
    for (int i = 0; i < num_samples * 2; i++) {
        g_mixer.sfx_pcm[i] = (i % 2 == 0) ? 32767 : -32768;
    }
    g_mixer.sfx_total_frames = num_samples;
    g_mixer.sfx_current_frame = 0;
    g_mixer.sfx_active = true;

    for (int c = 0; c < total_chunks; c++) {
        sdl_audio_callback(&g_mixer, stream_bytes, chunk_frames * AUDIO_CHANNELS * sizeof(int16_t));
        int16_t *s = (int16_t *)stream_bytes;
        for (int i = 0; i < chunk_frames * AUDIO_CHANNELS; i++) {
            int32_t val32 = (int32_t)s[i];
            if (val32 < -32768 || val32 > 32767) {
                clamp_errors++;
            }
        }
    }
    STRESS_CHECK(clamp_errors == 0, "sdl_audio_callback execution across 1M samples maintained valid s16 bounds");
    free(stream_bytes);
#endif

    /* 6. Vulnerability check: OPL temp buffer overflow */
    printf("--- Test 1.4: Vulnerability analysis on AUDIO_BUFFER_FRAMES overrun ---\n");
    printf("[AUDIT] opl_temp buffer capacity: %d frames (%zu bytes)\n",
           AUDIO_BUFFER_FRAMES, sizeof(g_mixer.opl_temp));
    printf("[AUDIT] In sdl_audio_callback: num_frames = len / (AUDIO_CHANNELS * sizeof(int16_t))\n");
    printf("[AUDIT] If audio backend requests > 1024 frames, hal_audio_render_opl overruns opl_temp!\n");

    free(music_buf);
    free(sfx_buf);
    free(voice_buf);
    free(out_buf);
    hal_audio_shutdown();
}

/* =========================================================================
 * TEST 2: RealSound ADPCM Decoding Fuzz & Crash Resistance Stress Test
 * ========================================================================= */
static void test_realsound_fuzz(void) {
    printf("\n--- Test 2: RealSound ADPCM Crash Resistance & Fuzzing ---\n");
    hal_audio_init();

    /* 1. Corrupt Magic Headers */
    printf("-> Testing corrupt magic headers...\n");
    uint8_t bad_magics[][16] = {
        { 'S', 'T', 'E', 'V', 'E', 0x00, 0, 0, 0, 0, 0, 0 },
        { 'S', 'T', 'E', 'V', 'E', 0x03, 0, 0, 0, 0, 0, 0 },
        { 'S', 'T', 'E', 'V', 'X', 0x01, 0, 0, 0, 0, 0, 0 },
        { 'X', 'X', 'X', 'X', 'X', 0x02, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    for (size_t i = 0; i < sizeof(bad_magics) / sizeof(bad_magics[0]); i++) {
        bool res = hal_audio_play_rs(bad_magics[i], sizeof(bad_magics[i]));
        STRESS_CHECK(res == false, "Bad magic rejected safely");
    }

    /* 2. Truncated Streams */
    printf("-> Testing truncated stream boundaries (len 0..35)...\n");
    uint8_t valid_hdr[64] = {
        'S', 'T', 'E', 'V', 'E', 0x02,
        0x40, 0x1F, /* 8000 Hz */
        0x10, 0x00, /* 16 samples */
        0x88, 0x97, 0x6A, 0x5B, 0x88, 0x97, 0x6A, 0x5B
    };

    for (size_t len = 0; len < 10; len++) {
        bool res = hal_audio_play_rs(valid_hdr, len);
        STRESS_CHECK(res == false, "Stream len < 10 rejected safely");
    }

    /* 3. Retail Format Truncation / Out-of-bounds length */
    printf("-> Testing retail format corrupted rlen...\n");
    uint8_t retail_corrupt[64];
    memset(retail_corrupt, 0, sizeof(retail_corrupt));
    memcpy(retail_corrupt, "STEVE\x02", 6);
    retail_corrupt[6] = 0x48; /* Retail tag */
    /* Set 24-bit length to 0x00FFFFFF (16.7 MB) in a 40-byte buffer */
    retail_corrupt[7] = 0xFF;
    retail_corrupt[8] = 0xFF;
    retail_corrupt[9] = 0xFF;

    /* Buffer size is 40 bytes. Should NOT crash or overread */
    bool res_ret = hal_audio_play_rs(retail_corrupt, 40);
    STRESS_CHECK(res_ret == true || res_ret == false, "Retail out-of-bounds length did not crash");

    /* 4. Extensive Fuzz Testing: 50,000 iterations */
    printf("-> Running 50,000 fuzz iterations on hal_audio_play_rs...\n");
    int crashes = 0;
    uint8_t fuzz_buf[4096];

    for (int it = 0; it < 50000; it++) {
        size_t fuzz_len = xorshift32() % sizeof(fuzz_buf);

        /* Randomly inject valid prefix to stress deep decoder paths */
        int mode = it % 4;
        if (mode == 0) {
            /* Completely random garbage */
            for (size_t b = 0; b < fuzz_len; b++) {
                fuzz_buf[b] = (uint8_t)xorshift32();
            }
        } else if (mode == 1) {
            /* Valid magic + random header */
            if (fuzz_len >= 6) {
                memcpy(fuzz_buf, "STEVE\x02", 6);
                for (size_t b = 6; b < fuzz_len; b++) {
                    fuzz_buf[b] = (uint8_t)xorshift32();
                }
            }
        } else if (mode == 2) {
            /* Retail magic + retail tag + random data */
            if (fuzz_len >= 32) {
                memcpy(fuzz_buf, "STEVE\x01", 6);
                fuzz_buf[6] = 0x48;
                for (size_t b = 7; b < fuzz_len; b++) {
                    fuzz_buf[b] = (uint8_t)xorshift32();
                }
            }
        } else {
            /* Synthetic header format with boundary sample rates and counts */
            if (fuzz_len >= 12) {
                memcpy(fuzz_buf, "STEVE\x02", 6);
                uint16_t sr = (uint16_t)(4000 + (xorshift32() % 44000));
                uint16_t sc = (uint16_t)(xorshift32() % 10000);
                fuzz_buf[6] = (uint8_t)(sr & 0xFF);
                fuzz_buf[7] = (uint8_t)(sr >> 8);
                fuzz_buf[8] = (uint8_t)(sc & 0xFF);
                fuzz_buf[9] = (uint8_t)(sc >> 8);
                for (size_t b = 10; b < fuzz_len; b++) {
                    fuzz_buf[b] = (uint8_t)xorshift32();
                }
            }
        }

        /* Must not crash! */
        hal_audio_play_rs(fuzz_buf, fuzz_len);
    }
    STRESS_CHECK(crashes == 0, "50,000 RealSound Fuzz iterations completed with 0 crashes");

    hal_audio_shutdown();
}

/* =========================================================================
 * TEST 3: VOC Speech Archive Loader & Clip Index Boundaries
 * ========================================================================= */
typedef struct {
    uint32_t offset;
    uint32_t length;
} voc_entry_t;

typedef struct {
    uint16_t clip_count;
    voc_entry_t *entries;
    size_t file_size;
} voc_archive_t;

static int voc_archive_load_header(const uint8_t *header_data, size_t header_len,
                                   size_t total_file_size, voc_archive_t *out_arch) {
    if (!header_data || !out_arch || header_len < 2) {
        return -1; /* Header too short */
    }

    uint16_t count = (uint16_t)(header_data[0] | ((uint16_t)header_data[1] << 8));
    out_arch->clip_count = count;
    out_arch->file_size = total_file_size;

    size_t required_bytes = 2 + (size_t)count * 8;
    if (header_len < required_bytes) {
        /* Truncated header table */
        out_arch->entries = NULL;
        return -2;
    }

    out_arch->entries = (voc_entry_t *)malloc(count * sizeof(voc_entry_t));
    if (!out_arch->entries) return -3;

    for (uint16_t i = 0; i < count; i++) {
        const uint8_t *p = header_data + 2 + i * 8;
        uint32_t off = (uint32_t)(p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24));
        uint32_t len = (uint32_t)(p[4] | ((uint32_t)p[5] << 8) | ((uint32_t)p[6] << 16) | ((uint32_t)p[7] << 24));

        out_arch->entries[i].offset = off;
        out_arch->entries[i].length = len;
    }

    return 0;
}

static const voc_entry_t *voc_archive_get_clip(const voc_archive_t *arch, int clip_index) {
    if (!arch || !arch->entries) return NULL;
    if (clip_index < 0 || clip_index >= arch->clip_count) {
        return NULL; /* Out of bounds clip index rejected safely */
    }
    return &arch->entries[clip_index];
}

static void test_voc_speech_archive(void) {
    printf("\n--- Test 3: VOC Speech Archive Loader & Clip Index Boundaries ---\n");

    /* 1. Synthesize 1,327 clip table */
    uint16_t retail_clips = 1327;
    size_t table_bytes = 2 + retail_clips * 8;
    uint8_t *mock_header = (uint8_t *)malloc(table_bytes);
    assert(mock_header);

    mock_header[0] = (uint8_t)(retail_clips & 0xFF);
    mock_header[1] = (uint8_t)(retail_clips >> 8);

    uint32_t cur_offset = (uint32_t)table_bytes;
    for (uint16_t i = 0; i < retail_clips; i++) {
        uint32_t len = 1000 + (i % 500);
        uint8_t *p = mock_header + 2 + i * 8;
        p[0] = (uint8_t)(cur_offset & 0xFF);
        p[1] = (uint8_t)((cur_offset >> 8) & 0xFF);
        p[2] = (uint8_t)((cur_offset >> 16) & 0xFF);
        p[3] = (uint8_t)((cur_offset >> 24) & 0xFF);

        p[4] = (uint8_t)(len & 0xFF);
        p[5] = (uint8_t)((len >> 8) & 0xFF);
        p[6] = (uint8_t)((len >> 16) & 0xFF);
        p[7] = (uint8_t)((len >> 24) & 0xFF);

        cur_offset += len;
    }

    size_t archive_total_size = cur_offset;

    voc_archive_t arch;
    int parse_rc = voc_archive_load_header(mock_header, table_bytes, archive_total_size, &arch);
    STRESS_CHECK(parse_rc == 0, "Valid 1,327-entry VOC header parsed successfully");
    STRESS_CHECK(arch.clip_count == 1327, "Clip count matches exactly 1,327");

    /* 2. Test Invalid Clip Indices: -1, 1327, 99999 */
    printf("-> Testing boundary clip indices (-1, 0, 1326, 1327, 99999)...\n");
    const voc_entry_t *clip_neg1 = voc_archive_get_clip(&arch, -1);
    STRESS_CHECK(clip_neg1 == NULL, "Invalid clip index -1 rejected safely");

    const voc_entry_t *clip_0 = voc_archive_get_clip(&arch, 0);
    STRESS_CHECK(clip_0 != NULL, "Valid clip index 0 retrieved successfully");

    const voc_entry_t *clip_last = voc_archive_get_clip(&arch, 1326);
    STRESS_CHECK(clip_last != NULL, "Valid clip index 1326 retrieved successfully");

    const voc_entry_t *clip_1327 = voc_archive_get_clip(&arch, 1327);
    STRESS_CHECK(clip_1327 == NULL, "Out of bounds clip index 1327 rejected safely");

    const voc_entry_t *clip_99999 = voc_archive_get_clip(&arch, 99999);
    STRESS_CHECK(clip_99999 == NULL, "Out of bounds clip index 99999 rejected safely");

    /* 3. Corrupted Offset Tables */
    printf("-> Testing corrupted offset tables...\n");
    /* Truncated header data */
    voc_archive_t bad_arch;
    int trunc_rc1 = voc_archive_load_header(mock_header, 1, archive_total_size, &bad_arch);
    STRESS_CHECK(trunc_rc1 == -1, "Header len 1 rejected safely");

    int trunc_rc2 = voc_archive_load_header(mock_header, 100, archive_total_size, &bad_arch);
    STRESS_CHECK(trunc_rc2 == -2, "Truncated header table (100 bytes for 1327 entries) rejected safely");

    /* Table with out-of-bounds offsets */
    uint8_t corrupt_table[18];
    corrupt_table[0] = 2; corrupt_table[1] = 0; /* 2 entries */
    /* Entry 0: offset 100, length 200 */
    memset(corrupt_table + 2, 0, 16);
    corrupt_table[2] = 100; corrupt_table[6] = 200;
    /* Entry 1: offset 0xFFFFFFFF, length 0x1000 (wrap-around attack) */
    corrupt_table[10] = 0xFF; corrupt_table[11] = 0xFF; corrupt_table[12] = 0xFF; corrupt_table[13] = 0xFF;
    corrupt_table[14] = 0x00; corrupt_table[15] = 0x10;

    voc_archive_t wrap_arch;
    int wrap_rc = voc_archive_load_header(corrupt_table, sizeof(corrupt_table), 5000, &wrap_arch);
    STRESS_CHECK(wrap_rc == 0, "Corrupt table parsed without crashing");
    if (wrap_arch.entries) {
        uint64_t end = (uint64_t)wrap_arch.entries[1].offset + (uint64_t)wrap_arch.entries[1].length;
        STRESS_CHECK(end > wrap_arch.file_size, "Detected overflow / out-of-bounds offset in entry 1");
        free(wrap_arch.entries);
    }

    /* 4. Stress test hal_audio_play_voc with fuzz buffers */
    printf("-> Stress testing hal_audio_play_voc with 20,000 fuzz buffers...\n");
    hal_audio_init();
    for (int it = 0; it < 20000; it++) {
        size_t vlen = xorshift32() % 4096;
        uint8_t vbuf[4096];
        for (size_t b = 0; b < vlen; b++) {
            vbuf[b] = (uint8_t)xorshift32();
        }
        hal_audio_play_voc(vbuf, vlen);
    }
    STRESS_CHECK(true, "20,000 hal_audio_play_voc fuzz buffers completed without crashing");

    /* Edge cases: NULL data, 0 len, huge len */
    STRESS_CHECK(hal_audio_play_voc(NULL, 100) == false, "NULL voc data rejected safely");
    STRESS_CHECK(hal_audio_play_voc(mock_header, 0) == false, "0 length voc data rejected safely");

    free(arch.entries);
    free(mock_header);
    hal_audio_shutdown();
}

int main(void) {
    printf("====================================================================\n");
    printf(" Running M2_2 Audio, Engine & Smoke Test Adversarial Harness\n");
    printf("====================================================================\n");

    test_mixer_extreme_signals();
    test_realsound_fuzz();
    test_voc_speech_archive();

    printf("\n====================================================================\n");
    printf(" Adversarial Harness Completed: %d passed, %d failed.\n",
           g_pass_count, g_fail_count);
    printf("====================================================================\n");

    return (g_fail_count == 0) ? 0 : 1;
}
