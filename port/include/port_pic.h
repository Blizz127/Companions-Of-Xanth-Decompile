#ifndef PORT_PIC_H
#define PORT_PIC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int id;
    uint32_t offset;
    uint16_t flags;
    uint16_t width;
    uint16_t height;
    int16_t x;
    int16_t y;
    bool has_coords;
    bool has_palette;
    uint8_t palette[256 * 3]; /* 8-bit RGB components */
    uint8_t *pixels;          /* width * height 8bpp indexed pixels */
    size_t pixel_count;
} PicEntry;

typedef struct {
    int count;
    PicEntry *entries;
    uint8_t *file_data;
    size_t file_size;
} PicContainer;

/**
 * Open a .PIC container file and parse all entry headers.
 * Does not decompress pixel payloads until requested.
 */
PicContainer *pic_open(const char *file_path);

/**
 * Decompress pixel data for a specific entry in the container.
 * Returns 0 on success, negative error code on failure.
 */
int pic_decompress_entry(PicContainer *pc, int entry_idx);

/**
 * Decompress all entries in the container.
 */
int pic_decompress_all(PicContainer *pc);

/**
 * Apply the 256-color palette from a PicEntry to the HAL video DAC.
 */
void pic_apply_palette(const PicEntry *entry);

/**
 * Blit a PicEntry onto a target 8bpp buffer (e.g. VGA backbuffer).
 * Handles coordinate clipping and optional transparent color key.
 */
void pic_blit(const PicEntry *entry,
              uint8_t *dest, int dest_w, int dest_h,
              int dest_x, int dest_y,
              bool use_transparency, uint8_t trans_color);

/**
 * Release all memory associated with a PicContainer.
 */
void pic_close(PicContainer *pc);

#ifdef __cplusplus
}
#endif

#endif /* PORT_PIC_H */
