/*
 * mzload.c — DOS MZ executable loader.
 *
 * Kept deliberately close to the Python reference in tools/, because
 * tests/test_mzload.py diffs the two and any drift is a bug in one of them.
 */
#include "mzload.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool mz_parse_header(const uint8_t *data, size_t len, mz_header_t *out) {
    if (!data || len < 0x1C) return false;
    if (!((data[0] == 'M' && data[1] == 'Z') ||
          (data[0] == 'Z' && data[1] == 'M'))) {
        return false;
    }

    out->cblp     = read_le16(data + 0x02);
    out->cp       = read_le16(data + 0x04);
    out->crlc     = read_le16(data + 0x06);
    out->cparhdr  = read_le16(data + 0x08);
    out->minalloc = read_le16(data + 0x0A);
    out->maxalloc = read_le16(data + 0x0C);
    out->ss       = read_le16(data + 0x0E);
    out->sp       = read_le16(data + 0x10);
    out->csum     = read_le16(data + 0x12);
    out->ip       = read_le16(data + 0x14);
    out->cs       = read_le16(data + 0x16);
    out->lfarlc   = read_le16(data + 0x18);
    out->ovno     = read_le16(data + 0x1A);

    if (out->cp == 0) return false;

    out->header_bytes = (uint32_t)out->cparhdr * 16u;
    /* Same expression the Python reference uses: a zero cblp means the last
     * page is full. */
    out->image_size = ((uint32_t)out->cp - 1u) * 512u
                    + (out->cblp ? out->cblp : 512u);
    if (out->image_size < out->header_bytes) return false;
    out->image_size -= out->header_bytes;

    out->file_size    = (uint32_t)len;
    out->reloc_offset = out->lfarlc;
    out->tail_size    = (len > out->header_bytes + out->image_size)
                      ? (uint32_t)len - (out->header_bytes + out->image_size)
                      : 0u;
    return true;
}

bool mz_load_file(const char *path, uint16_t load_seg, mz_image_t *out,
                  char *err, size_t errlen) {
    FILE *f = NULL;
    uint8_t *buf = NULL;
    long fsize;
    size_t got;
    mz_header_t h;
    uint32_t base;

#define FAIL(...)                                      \
    do {                                               \
        if (err) snprintf(err, errlen, __VA_ARGS__);   \
        if (buf) free(buf);                            \
        if (f) fclose(f);                              \
        return false;                                  \
    } while (0)

    memset(out, 0, sizeof(*out));

    f = fopen(path, "rb");
    if (!f) FAIL("cannot open '%s'", path);
    if (fseek(f, 0, SEEK_END) != 0) FAIL("seek failed on '%s'", path);
    fsize = ftell(f);
    if (fsize <= 0) FAIL("'%s' is empty", path);
    rewind(f);

    buf = (uint8_t *)malloc((size_t)fsize);
    if (!buf) FAIL("out of memory reading '%s'", path);
    got = fread(buf, 1, (size_t)fsize, f);
    if (got != (size_t)fsize) FAIL("short read on '%s'", path);
    fclose(f);
    f = NULL;

    if (!mz_parse_header(buf, (size_t)fsize, &h)) FAIL("'%s' is not an MZ image", path);

    if (h.header_bytes + h.image_size > (uint32_t)fsize) {
        FAIL("declared image (%u + %u) exceeds file size %ld",
             h.header_bytes, h.image_size, fsize);
    }

    base = (uint32_t)load_seg * 16u;
    if (base + h.image_size > DOS_MEM_SIZE) {
        FAIL("image does not fit at segment %04X (%u bytes)", load_seg, h.image_size);
    }

    memcpy(g_dos_mem + base, buf + h.header_bytes, h.image_size);

    /* Apply relocations: add the load segment to each pointed-at word. */
    for (uint16_t i = 0; i < h.crlc; i++) {
        uint32_t rec = h.reloc_offset + (uint32_t)i * 4u;
        uint16_t r_off, r_seg;
        uint32_t target;

        if (rec + 4u > (uint32_t)fsize) FAIL("relocation table runs past EOF");
        r_off = read_le16(buf + rec);
        r_seg = read_le16(buf + rec + 2);

        target = ((uint32_t)r_seg * 16u + r_off);
        if (target + 2u > h.image_size) {
            FAIL("relocation %u targets %05X, outside the %u-byte image",
                 i, target, h.image_size);
        }
        {
            uint32_t at = base + target;
            uint16_t v  = (uint16_t)(read_le16(g_dos_mem + at) + load_seg);
            write_le16(g_dos_mem + at, v);
        }
        out->relocs_applied++;
    }

    free(buf);

    out->hdr      = h;
    out->load_seg = load_seg;
    out->psp_seg  = (uint16_t)(load_seg - 0x10);
    out->entry_cs = (uint16_t)(h.cs + load_seg);
    out->entry_ip = h.ip;
    out->entry_ss = (uint16_t)(h.ss + load_seg);
    out->entry_sp = h.sp;
    return true;
#undef FAIL
}
