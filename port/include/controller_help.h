#ifndef CONTROLLER_HELP_H
#define CONTROLLER_HELP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define CONTROLLER_HELP_WIDTH 320
#define CONTROLLER_HELP_HEIGHT 176
#define CONTROLLER_HELP_PIXELS (CONTROLLER_HELP_WIDTH * CONTROLLER_HELP_HEIGHT)

/* Render into a separate host-owned panel, never a guest framebuffer.
 * Pixels use packed 0xRRGGBBAA (SDL_PIXELFORMAT_RGBA8888). The caller controls
 * visibility and composites this panel after the guest presentation pass.
 * Verb shortcuts and Y are shown only when their source-backed guest controls
 * are available. Both capability flags should default to false.
 * Returns false without writing for null or undersized destination buffers. */
bool controller_help_render(uint32_t *pixels, size_t pixel_count,
                            bool can_verb_cycle, bool can_snap);

#endif
