#include "port_story.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

StoryTextDatabase g_story_text_db = {0};

static uint16_t read_u16(const uint8_t *p) {
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}

int story_text_load(const char *path) {
    story_text_free();

    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "[STORY] Cannot open %s\n", path);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz < 20) {
        fprintf(stderr, "[STORY] File too small: %ld bytes\n", sz);
        fclose(f);
        return -2;
    }

    uint8_t *data = (uint8_t *)malloc((size_t)sz);
    if (!data) {
        fclose(f);
        return -3;
    }

    if (fread(data, 1, (size_t)sz, f) != (size_t)sz) {
        fclose(f);
        free(data);
        return -4;
    }
    fclose(f);

    size_t pos = 0;
    uint16_t segment_count = read_u16(data + pos);
    pos += 2;

    if (segment_count > STORY_MAX_SEGMENTS) {
        fprintf(stderr, "[STORY] Too many segments: %u (max %d)\n", segment_count, STORY_MAX_SEGMENTS);
        free(data);
        return -5;
    }
    g_story_text_db.segment_count = segment_count;

    typedef struct {
        uint16_t string_count;
        uint16_t stream_size;
        uint16_t flags;
    } SegmentHeader;

    SegmentHeader headers[STORY_MAX_SEGMENTS];
    for (int s = 0; s < segment_count; s++) {
        headers[s].string_count = read_u16(data + pos);
        headers[s].stream_size = read_u16(data + pos + 2);
        headers[s].flags = read_u16(data + pos + 4);
        pos += 6;
        g_story_text_db.string_counts[s] = headers[s].string_count;
    }

    /* Read string size tables */
    uint16_t *size_tables[STORY_MAX_SEGMENTS];
    for (int s = 0; s < segment_count; s++) {
        int cnt = headers[s].string_count;
        size_tables[s] = (uint16_t *)malloc(cnt * sizeof(uint16_t));
        if (!size_tables[s]) {
            free(data);
            return -6;
        }
        for (int i = 0; i < cnt; i++) {
            size_tables[s][i] = read_u16(data + pos);
            pos += 2;
        }
    }

    /* Huffman tree */
    uint16_t huff_size = read_u16(data + pos);
    pos += 2;
    uint16_t *huff_table = (uint16_t *)malloc(huff_size * sizeof(uint16_t));
    if (!huff_table) {
        free(data);
        return -7;
    }
    for (int i = 0; i < huff_size; i++) {
        huff_table[i] = read_u16(data + pos);
        pos += 2;
    }

    /* Shorthand offsets */
    uint16_t sh_offsets_cnt = read_u16(data + pos);
    pos += 2;
    uint16_t *sh_offsets = (uint16_t *)malloc(sh_offsets_cnt * sizeof(uint16_t));
    if (!sh_offsets) {
        free(huff_table);
        free(data);
        return -8;
    }
    for (int i = 0; i < sh_offsets_cnt; i++) {
        sh_offsets[i] = read_u16(data + pos);
        pos += 2;
    }

    /* Shorthand data */
    uint16_t sh_size = read_u16(data + pos);
    pos += 2;
    const uint8_t *shorthands = data + pos;
    pos += sh_size;

    /* Decompress all strings */
    char buffer[16384];
    int total_decompressed = 0;

    for (int s = 0; s < segment_count; s++) {
        int cnt = headers[s].string_count;
        g_story_text_db.strings[s] = (char **)calloc(cnt, sizeof(char *));
        if (!g_story_text_db.strings[s]) continue;

        for (int i = 0; i < cnt; i++) {
            uint16_t comp_len = size_tables[s][i];
            const uint8_t *raw_stream = data + pos;
            pos += comp_len;

            uint16_t uncomp_len = 0;
            uint8_t bitcounter = 0;
            uint8_t buf_byte = 0;
            uint16_t stream_idx = 0;
            uint16_t remaining = comp_len;

            while (remaining > 0) {
                uint16_t treecode = huff_size - 2;
                bool hit_end = false;
                while (true) {
                    if (remaining == 0 && bitcounter == 0) {
                        hit_end = true;
                        break;
                    }
                    if (bitcounter == 0) {
                        buf_byte = raw_stream[stream_idx++];
                        remaining--;
                        bitcounter = 8;
                    }
                    uint16_t idx = (buf_byte & 1) | treecode;
                    treecode = huff_table[idx];
                    buf_byte >>= 1;
                    bitcounter--;
                    if ((treecode & 0x8000) != 0) {
                        break;
                    }
                }
                if (hit_end) break;
                treecode = treecode ^ 0xFFFF;
                if (treecode >= 0x80) {
                    uint16_t sh_idx = treecode - 0x80;
                    if (sh_idx < sh_offsets_cnt) {
                        uint16_t off = sh_offsets[sh_idx];
                        while (off < sh_size && shorthands[off] != 0 && (size_t)(uncomp_len + 1) < sizeof(buffer)) {
                            buffer[uncomp_len++] = (char)shorthands[off++];
                        }
                    }
                } else {
                    if ((size_t)(uncomp_len + 1) < sizeof(buffer)) {
                        buffer[uncomp_len++] = (char)treecode;
                    }
                }
            }
            buffer[uncomp_len] = '\0';

            /* Strip trailing CR/LF/0x0B controls */
            while (uncomp_len > 0 && (buffer[uncomp_len - 1] == '\r' ||
                                      buffer[uncomp_len - 1] == '\n' ||
                                      buffer[uncomp_len - 1] == 0x0B)) {
                buffer[--uncomp_len] = '\0';
            }

            g_story_text_db.strings[s][i] = strdup(buffer);
            total_decompressed++;
        }
        free(size_tables[s]);
    }

    free(huff_table);
    free(sh_offsets);
    free(data);

    g_story_text_db.total_strings = total_decompressed;
    g_story_text_db.loaded = true;

    printf("[STORY] Successfully loaded and decompressed %d strings across %d segments from %s\n",
           total_decompressed, segment_count, path);
    return 0;
}

const char *story_text_get(int segment, int string_idx) {
    if (!g_story_text_db.loaded || segment < 0 || segment >= g_story_text_db.segment_count) {
        return "";
    }
    if (string_idx < 0 || string_idx >= g_story_text_db.string_counts[segment]) {
        return "";
    }
    const char *str = g_story_text_db.strings[segment][string_idx];
    return str ? str : "";
}

void story_text_free(void) {
    if (!g_story_text_db.loaded) return;
    for (int s = 0; s < g_story_text_db.segment_count; s++) {
        if (g_story_text_db.strings[s]) {
            for (int i = 0; i < g_story_text_db.string_counts[s]; i++) {
                if (g_story_text_db.strings[s][i]) {
                    free(g_story_text_db.strings[s][i]);
                }
            }
            free(g_story_text_db.strings[s]);
            g_story_text_db.strings[s] = NULL;
        }
        g_story_text_db.string_counts[s] = 0;
    }
    g_story_text_db.segment_count = 0;
    g_story_text_db.total_strings = 0;
    g_story_text_db.loaded = false;
}
