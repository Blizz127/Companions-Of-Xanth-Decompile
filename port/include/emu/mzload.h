/*
 * mzload.h — DOS MZ executable loader.
 *
 * Mirrors tools/identify.py::identify_mz and tools/mz.py::parse_relocs so the
 * two can be differentially tested against each other. The retail XANTH.EXE
 * is a plain MZ: all 5,304 relocations fall inside the 191,656-byte load
 * image, so a textbook loader is sufficient. The 43,193 bytes appended after
 * the MZ image are the RTLink/Plus runtime, which the game reads itself via
 * ordinary file I/O — the loader must NOT try to interpret them.
 */
#ifndef EMU_MZLOAD_H
#define EMU_MZLOAD_H

#include "port_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    /* Straight from the header. */
    uint16_t cblp, cp, crlc, cparhdr, minalloc, maxalloc;
    uint16_t ss, sp, csum, ip, cs, lfarlc, ovno;

    /* Derived. */
    uint32_t header_bytes;   /* cparhdr * 16 */
    uint32_t image_size;     /* bytes of load image, excluding the header */
    uint32_t file_size;
    uint32_t tail_size;      /* bytes past the declared image (RTLink data) */
    uint32_t reloc_offset;
} mz_header_t;

typedef struct {
    mz_header_t hdr;
    uint16_t    load_seg;    /* where the image was placed */
    uint16_t    psp_seg;     /* load_seg - 0x10 */
    uint16_t    entry_cs, entry_ip;
    uint16_t    entry_ss, entry_sp;
    uint32_t    relocs_applied;
} mz_image_t;

/* Parse only — does not touch guest memory. Returns false on a bad header. */
bool mz_parse_header(const uint8_t *data, size_t len, mz_header_t *out);

/*
 * Load `path` into g_dos_mem at `load_seg` and apply relocations.
 * `psp_seg` is where the PSP will live (load_seg is normally psp_seg + 0x10).
 * On failure returns false and fills `err`.
 */
bool mz_load_file(const char *path, uint16_t load_seg, mz_image_t *out,
                  char *err, size_t errlen);

#ifdef __cplusplus
}
#endif

#endif /* EMU_MZLOAD_H */
