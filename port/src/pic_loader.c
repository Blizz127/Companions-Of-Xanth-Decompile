#include "port_pic.h"
#include "port_hal.h"
#include "blast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const uint8_t *in_ptr;
    unsigned in_left;
    uint8_t *out_ptr;
    unsigned out_left;
    unsigned total_out;
} BlastContext;

static unsigned blast_feed_in(void *how, unsigned char **buf) {
    BlastContext *ctx = (BlastContext *)how;
    if (ctx->in_left == 0) return 0;
    *buf = (unsigned char *)ctx->in_ptr;
    unsigned len = ctx->in_left;
    ctx->in_ptr += len;
    ctx->in_left = 0;
    return len;
}

static int blast_sink_out(void *how, unsigned char *buf, unsigned len) {
    BlastContext *ctx = (BlastContext *)how;
    if (len > ctx->out_left) {
        return 1; /* Buffer overflow */
    }
    memcpy(ctx->out_ptr, buf, len);
    ctx->out_ptr += len;
    ctx->out_left -= len;
    ctx->total_out += len;
    return 0;
}

static uint16_t read_u16(const uint8_t *p) {
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}

static int16_t read_s16(const uint8_t *p) {
    return (int16_t)((uint16_t)p[0] | ((uint16_t)p[1] << 8));
}

static uint32_t read_u32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

PicContainer *pic_open(const char *file_path) {
    if (!file_path) return NULL;

    FILE *f = fopen(file_path, "rb");
    if (!f) {
        fprintf(stderr, "[PIC] Cannot open file: %s\n", file_path);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz < 12) {
        fprintf(stderr, "[PIC] File too small: %s (%ld bytes)\n", file_path, sz);
        fclose(f);
        return NULL;
    }

    uint8_t *data = (uint8_t *)malloc((size_t)sz);
    if (!data) {
        fclose(f);
        return NULL;
    }

    if (fread(data, 1, (size_t)sz, f) != (size_t)sz) {
        fclose(f);
        free(data);
        return NULL;
    }
    fclose(f);

    /* Parse entry index table */
    size_t pos = 0;
    uint32_t offset = read_u32(data + pos);
    pos += 4;

    /* Temporary dynamic array for entries */
    int capacity = 64;
    int count = 0;
    PicEntry *entries = (PicEntry *)malloc(capacity * sizeof(PicEntry));
    if (!entries) {
        free(data);
        return NULL;
    }

    while (offset != 0 && pos + 8 <= (size_t)sz) {
        if (count >= capacity) {
            capacity *= 2;
            PicEntry *new_entries = (PicEntry *)realloc(entries, capacity * sizeof(PicEntry));
            if (!new_entries) {
                free(entries);
                free(data);
                return NULL;
            }
            entries = new_entries;
        }

        PicEntry *e = &entries[count];
        memset(e, 0, sizeof(PicEntry));
        e->id = count;
        e->offset = offset;
        e->flags = read_u16(data + pos);
        e->width = read_u16(data + pos + 2);
        e->height = read_u16(data + pos + 4);
        /* 2 bytes padding at pos + 6 */
        pos += 8;

        e->has_coords = (e->flags & 1) != 0;
        e->has_palette = (e->flags & (1 << 12)) != 0;
        e->pixel_count = (size_t)e->width * (size_t)e->height;

        count++;

        if (pos + 4 <= (size_t)sz) {
            offset = read_u32(data + pos);
            pos += 4;
        } else {
            break;
        }
    }

    PicContainer *pc = (PicContainer *)malloc(sizeof(PicContainer));
    if (!pc) {
        free(entries);
        free(data);
        return NULL;
    }

    pc->count = count;
    pc->entries = entries;
    pc->file_data = data;
    pc->file_size = (size_t)sz;

    return pc;
}

int pic_decompress_entry(PicContainer *pc, int entry_idx) {
    if (!pc || entry_idx < 0 || entry_idx >= pc->count) {
        return -1;
    }

    PicEntry *e = &pc->entries[entry_idx];
    if (e->pixels) {
        return 0; /* Already decompressed */
    }

    size_t start = e->offset;
    size_t end = (entry_idx + 1 < pc->count) ? pc->entries[entry_idx + 1].offset : pc->file_size;
    if (start >= pc->file_size || end > pc->file_size || start >= end) {
        fprintf(stderr, "[PIC] Invalid offset range for entry %d: [%zu, %zu]\n", entry_idx, start, end);
        return -2;
    }

    const uint8_t *chunk = pc->file_data + start;
    size_t cur = 0;

    if (e->has_coords) {
        if (cur + 4 > (end - start)) return -3;
        e->x = read_s16(chunk + cur);
        e->y = read_s16(chunk + cur + 2);
        cur += 4;
    }

    if (e->has_palette) {
        if (cur + 768 > (end - start)) return -4;
        const uint8_t *raw_pal = chunk + cur;
        for (int i = 0; i < 256 * 3; i++) {
            uint8_t val = raw_pal[i];
            /* Convert 6-bit VGA DAC (0..63) to 8-bit RGB (0..255) */
            e->palette[i] = (uint8_t)((val << 2) | (val >> 4));
        }
        cur += 768;
    }

    size_t comp_size = (end - start) - cur;
    if (comp_size == 0 || e->pixel_count == 0) {
        return 0;
    }

    e->pixels = (uint8_t *)malloc(e->pixel_count);
    if (!e->pixels) {
        return -5;
    }

    BlastContext ctx;
    ctx.in_ptr = chunk + cur;
    ctx.in_left = (unsigned)comp_size;
    ctx.out_ptr = e->pixels;
    ctx.out_left = (unsigned)e->pixel_count;
    ctx.total_out = 0;

    int res = blast(blast_feed_in, &ctx, blast_sink_out, &ctx, NULL, NULL);
    if (res != 0) {
        fprintf(stderr, "[PIC] blast decompression failed on entry %d: error %d\n", entry_idx, res);
        free(e->pixels);
        e->pixels = NULL;
        return -6;
    }

    if (ctx.total_out != e->pixel_count) {
        fprintf(stderr, "[PIC] Size mismatch on entry %d: decompressed %u, expected %zu\n",
                entry_idx, ctx.total_out, e->pixel_count);
    }

    return 0;
}

int pic_decompress_all(PicContainer *pc) {
    if (!pc) return -1;
    int success = 0;
    for (int i = 0; i < pc->count; i++) {
        if (pic_decompress_entry(pc, i) == 0) {
            success++;
        }
    }
    return success;
}

void pic_apply_palette(const PicEntry *entry) {
    if (!entry || !entry->has_palette) return;
    for (int i = 0; i < 256; i++) {
        /* Convert 8-bit back to 6-bit scale for hal_video_set_palette_entry */
        uint8_t r = entry->palette[i * 3 + 0] >> 2;
        uint8_t g = entry->palette[i * 3 + 1] >> 2;
        uint8_t b = entry->palette[i * 3 + 2] >> 2;
        hal_video_set_palette_entry((uint8_t)i, r, g, b);
    }
}

void pic_blit(const PicEntry *entry,
              uint8_t *dest, int dest_w, int dest_h,
              int dest_x, int dest_y,
              bool use_transparency, uint8_t trans_color) {
    if (!entry || !entry->pixels || !dest) return;

    int src_w = entry->width;
    int src_h = entry->height;

    for (int sy = 0; sy < src_h; sy++) {
        int dy = dest_y + sy;
        if (dy < 0 || dy >= dest_h) continue;

        for (int sx = 0; sx < src_w; sx++) {
            int dx = dest_x + sx;
            if (dx < 0 || dx >= dest_w) continue;

            uint8_t col = entry->pixels[sy * src_w + sx];
            if (use_transparency && col == trans_color) {
                continue;
            }
            dest[dy * dest_w + dx] = col;
        }
    }
}

void pic_close(PicContainer *pc) {
    if (!pc) return;
    if (pc->entries) {
        for (int i = 0; i < pc->count; i++) {
            if (pc->entries[i].pixels) {
                free(pc->entries[i].pixels);
            }
        }
        free(pc->entries);
    }
    if (pc->file_data) {
        free(pc->file_data);
    }
    free(pc);
}
