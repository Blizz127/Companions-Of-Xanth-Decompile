#include "controller_help.h"
#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SDL_MAIN_HANDLED
#ifndef XANTH_HEADLESS_STUB
  #if defined(__has_include)
    #if __has_include(<SDL2/SDL.h>)
      #include <SDL2/SDL.h>
    #elif __has_include(<SDL.h>)
      #include <SDL.h>
    #else
      #define XANTH_HEADLESS_STUB 1
    #endif
  #else
    #include <SDL.h>
  #endif
#endif

/* g_dos_mem now lives in src/dos_mem.c so the emulation core can link
 * without SDL. The Mode 13h framebuffer is still aliased to it at +0xA0000
 * in hal_video_init(), which is why guest VGA writes need no translation. */

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} vga_dac_t;

typedef struct {
    uint8_t *screen_buffer;  /* Points to g_dos_mem + 0xA0000 */
    uint8_t *back_buffer;    /* Dynamically allocated 64,000 bytes */
    int active_target;       /* 0: screen, 1: back */

    vga_dac_t dac[HAL_VIDEO_PALETTE_NUM];
    uint32_t rgba[HAL_VIDEO_PALETTE_NUM]; /* RGBA8888 lookup */
    bool cycling_enabled;

#ifndef XANTH_HEADLESS_STUB
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
#else
    void *window;
    void *renderer;
    void *texture;
#endif

    uint32_t *rgba_surface;  /* 320x200 32-bit RGBA surface (256,000 bytes) */

    int window_width;
    int window_height;
    int viewport_x;
    int viewport_y;
    int viewport_w;
    int viewport_h;

    bool headless;
    bool fullscreen;
    hal_video_present_mode present_mode;
    bool crt_scanlines;
    bool linear_filter;
    int saved_host_cursor;
    bool host_cursor_hidden;
    uint64_t frame_count;
} hal_video_ctx_t;

static hal_video_ctx_t g_video;

hal_video_viewport hal_video_compute_viewport(int win_w, int win_h,
                                               hal_video_present_mode mode) {
    hal_video_viewport viewport = {0, 0, 0, 0};
    if (win_w <= 0 || win_h <= 0) return viewport;

    if (mode == HAL_VIDEO_PRESENT_PIXEL_INTEGER) {
        int factor_w = win_w / HAL_VIDEO_WIDTH;
        int factor_h = win_h / HAL_VIDEO_HEIGHT;
        int factor = factor_w < factor_h ? factor_w : factor_h;
        if (factor < 1) factor = 1;
        viewport.width = HAL_VIDEO_WIDTH * factor;
        viewport.height = HAL_VIDEO_HEIGHT * factor;
    } else {
        if ((int64_t)win_w * 3 > (int64_t)win_h * 4) {
            viewport.height = win_h;
            viewport.width = (int)(((int64_t)win_h * 4) / 3);
        } else {
            viewport.width = win_w;
            viewport.height = (int)(((int64_t)win_w * 3) / 4);
        }
    }
    viewport.x = (win_w - viewport.width) / 2;
    viewport.y = (win_h - viewport.height) / 2;
    return viewport;
}

/* Input must use the same geometry even before the first presented frame,
 * after a mode/size change, and when presentation is disabled headlessly. */
static void update_viewport(void) {
    int width = g_video.window_width, height = g_video.window_height;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.renderer && !g_video.headless)
        SDL_GetRendererOutputSize(g_video.renderer, &width, &height);
#endif
    hal_video_viewport viewport = hal_video_compute_viewport(
        width, height, g_video.present_mode);
    g_video.viewport_x = viewport.x;
    g_video.viewport_y = viewport.y;
    g_video.viewport_w = viewport.width;
    g_video.viewport_h = viewport.height;
}

bool hal_video_map_window_point(int window_w, int window_h, int output_w, int output_h,
    hal_video_present_mode mode, int window_x, int window_y, int *screen_x, int *screen_y) {
    if (window_w <= 0 || window_h <= 0 || output_w <= 0 || output_h <= 0)
        return false;
    hal_video_viewport viewport = hal_video_compute_viewport(output_w, output_h, mode);
    if (viewport.width <= 0 || viewport.height <= 0) return false;
    int64_t x = (int64_t)window_x * output_w / window_w - viewport.x;
    int64_t y = (int64_t)window_y * output_h / window_h - viewport.y;
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= viewport.width) x = viewport.width - 1;
    if (y >= viewport.height) y = viewport.height - 1;
    if (screen_x) *screen_x = (int)(x * HAL_VIDEO_WIDTH / viewport.width);
    if (screen_y) *screen_y = (int)(y * HAL_VIDEO_HEIGHT / viewport.height);
    return true;
}

bool hal_video_map_mouse(int window_x, int window_y, int *screen_x, int *screen_y) {
    int window_w = g_video.window_width, window_h = g_video.window_height;
    int output_w = window_w, output_h = window_h;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.window && !g_video.headless)
        SDL_GetWindowSize(g_video.window, &window_w, &window_h);
    if (g_video.renderer && !g_video.headless)
        SDL_GetRendererOutputSize(g_video.renderer, &output_w, &output_h);
#endif
    return hal_video_map_window_point(window_w, window_h, output_w, output_h,
        g_video.present_mode, window_x, window_y, screen_x, screen_y);
}

bool hal_video_map_touch(float x, float y, int *screen_x, int *screen_y) {
    int w = g_video.window_width, h = g_video.window_height;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.window && !g_video.headless) SDL_GetWindowSize(g_video.window, &w, &h);
#endif
    if (!(x >= 0 && x <= 1 && y >= 0 && y <= 1)) return false;
    return hal_video_map_mouse((int)(x * w), (int)(y * h), screen_x, screen_y);
}

void hal_video_mouse_window_event(uint32_t window_id, bool inside) {
#ifndef XANTH_HEADLESS_STUB
    if (!g_video.window || g_video.headless || window_id != SDL_GetWindowID(g_video.window))
        return;
    if (inside && !g_video.host_cursor_hidden) {
        g_video.saved_host_cursor = SDL_ShowCursor(SDL_QUERY);
        SDL_ShowCursor(SDL_DISABLE);
        g_video.host_cursor_hidden = true;
    } else if (!inside && g_video.host_cursor_hidden) {
        SDL_ShowCursor(g_video.saved_host_cursor);
        g_video.host_cursor_hidden = false;
    }
#else
    (void)window_id;
    (void)inside;
#endif
}

bool hal_video_init(int scale, bool fullscreen, bool headless, bool enable_cycling) {
    memset(&g_video, 0, sizeof(g_video));
    if (scale > INT_MAX / HAL_VIDEO_WIDTH) {
        fprintf(stderr, "[HAL_VIDEO] Window scale is too large\n");
        return false;
    }

    g_video.screen_buffer = g_dos_mem + 0xA0000;
    g_video.back_buffer = (uint8_t *)calloc(1, HAL_VIDEO_FRAME_SIZE);
    if (!g_video.back_buffer) {
        fprintf(stderr, "[HAL_VIDEO] Failed to allocate backbuffer\n");
        return false;
    }

    g_video.rgba_surface = (uint32_t *)calloc(HAL_VIDEO_FRAME_SIZE, sizeof(uint32_t));
    if (!g_video.rgba_surface) {
        fprintf(stderr, "[HAL_VIDEO] Failed to allocate RGBA surface\n");
        free(g_video.back_buffer);
        g_video.back_buffer = NULL;
        return false;
    }

    g_video.active_target = 0; /* Default: screen buffer */
    g_video.cycling_enabled = enable_cycling;
    g_video.headless = headless;
    g_video.fullscreen = fullscreen;
    g_video.present_mode = HAL_VIDEO_PRESENT_ASPECT_4_3;
    g_video.crt_scanlines = false;
    g_video.linear_filter = false;
    g_video.frame_count = 0;

    /* Initialize default VGA 16-color palette for UI/text elements, grayscale for rest */
    static const uint8_t s_default_vga16[16][3] = {
        { 0,  0,  0}, /* 0: Black */
        { 0,  0, 42}, /* 1: Blue */
        { 0, 42,  0}, /* 2: Green */
        { 0, 42, 42}, /* 3: Cyan */
        {42,  0,  0}, /* 4: Red */
        {42,  0, 42}, /* 5: Magenta */
        {42, 21,  0}, /* 6: Brown */
        {42, 42, 42}, /* 7: Light Gray */
        {21, 21, 21}, /* 8: Dark Gray */
        {21, 21, 63}, /* 9: Bright Blue */
        {21, 63, 21}, /* 10: Bright Green */
        {21, 63, 63}, /* 11: Bright Cyan */
        {63, 21, 21}, /* 12: Bright Red */
        {63, 21, 63}, /* 13: Bright Magenta */
        {63, 63, 21}, /* 14: Yellow */
        {63, 63, 63}, /* 15: Bright White */
    };
    for (int i = 0; i < 16; i++) {
        hal_video_set_palette_entry((uint8_t)i, s_default_vga16[i][0], s_default_vga16[i][1], s_default_vga16[i][2]);
    }
    for (int i = 16; i < HAL_VIDEO_PALETTE_NUM; i++) {
        hal_video_set_palette_entry((uint8_t)i, (uint8_t)(i % 64), (uint8_t)(i % 64), (uint8_t)(i % 64));
    }

    if (scale < 1) scale = 2;
    g_video.window_width = HAL_VIDEO_WIDTH * scale;
    g_video.window_height = HAL_VIDEO_HEIGHT * scale;

#ifndef XANTH_HEADLESS_STUB
    /* Let the first click activate and reach the game in the same event. */
#ifdef SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH
    SDL_SetHint(SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH, "1");
#endif
    if (headless) {
        /* Headless mode: configure SDL dummy video driver if not already set */
        setenv("SDL_VIDEODRIVER", "dummy", 0);
    }

    if (SDL_WasInit(SDL_INIT_VIDEO) == 0) {
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
            fprintf(stderr, "[HAL_VIDEO] SDL_InitSubSystem(VIDEO) failed: %s\n", SDL_GetError());
            /* In headless mode, we can still function with memory-only rendering */
            if (!headless) {
                return false;
            }
        }
    }

    Uint32 win_flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) win_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    if (headless) win_flags |= SDL_WINDOW_HIDDEN;
    else win_flags |= SDL_WINDOW_SHOWN;

    g_video.window = SDL_CreateWindow(
        "Companions of Xanth",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        g_video.window_width, g_video.window_height,
        win_flags
    );

    if (g_video.window) {
        Uint32 renderer_flags = SDL_RENDERER_ACCELERATED;
        if (!headless) renderer_flags |= SDL_RENDERER_PRESENTVSYNC;
        else renderer_flags = SDL_RENDERER_SOFTWARE;

        g_video.renderer = SDL_CreateRenderer(g_video.window, -1, renderer_flags);
        if (!g_video.renderer) {
            g_video.renderer = SDL_CreateRenderer(g_video.window, -1, 0);
        }

        if (g_video.renderer) {
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
            g_video.texture = SDL_CreateTexture(
                g_video.renderer,
                SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_STREAMING,
                HAL_VIDEO_WIDTH, HAL_VIDEO_HEIGHT
            );
            if (g_video.texture) {
                SDL_SetTextureBlendMode(g_video.texture, SDL_BLENDMODE_NONE);
            }
        }
    }
#endif

    update_viewport();
#ifndef XANTH_HEADLESS_STUB
    if (g_video.window && SDL_GetMouseFocus() == g_video.window)
        hal_video_mouse_window_event(SDL_GetWindowID(g_video.window), true);
#endif

    return true;
}

void hal_video_set_present_mode(hal_video_present_mode mode) {
    g_video.present_mode = mode;
    update_viewport();
}

void hal_video_set_filter(bool crt_scanlines, bool linear_filter) {
    g_video.crt_scanlines = crt_scanlines;
    g_video.linear_filter = linear_filter;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.texture) {
#if SDL_VERSION_ATLEAST(2, 0, 12)
        SDL_SetTextureScaleMode(g_video.texture,
            linear_filter ? SDL_ScaleModeLinear : SDL_ScaleModeNearest);
#else
        /* Older SDL reads this hint only when creating a texture. Setting
         * it on the existing texture leaves filtering unchanged. */
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, linear_filter ? "linear" : "nearest");
        SDL_Texture *replacement = SDL_CreateTexture(g_video.renderer,
            SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING,
            HAL_VIDEO_WIDTH, HAL_VIDEO_HEIGHT);
        if (replacement) {
            SDL_SetTextureBlendMode(replacement, SDL_BLENDMODE_NONE);
            SDL_DestroyTexture(g_video.texture);
            g_video.texture = replacement;
        } else {
            fprintf(stderr, "[HAL_VIDEO] Failed to change texture filtering: %s\n",
                    SDL_GetError());
        }
#endif
    }
#endif
}

void hal_video_set_window_size(int width, int height) {
    if (width <= 0 || height <= 0) return;
    g_video.window_width = width;
    g_video.window_height = height;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.window) SDL_SetWindowSize(g_video.window,width,height);
#endif
    update_viewport();
}

void hal_video_toggle_fullscreen(void) {
    g_video.fullscreen = !g_video.fullscreen;
#ifndef XANTH_HEADLESS_STUB
    if (g_video.window && !g_video.headless)
        (void)SDL_SetWindowFullscreen(g_video.window,
            g_video.fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
#endif
}

void hal_video_toggle_crt(void) {
    g_video.crt_scanlines = !g_video.crt_scanlines;
}

static void (*g_overlay)(SDL_Renderer *, const hal_video_viewport *, void *);
static void *g_overlay_user;
void hal_video_set_overlay(void (*fn)(SDL_Renderer *, const hal_video_viewport *, void *), void *user) {
    g_overlay = fn; g_overlay_user = user;
}
static bool g_controller_help;
static bool g_help_can_verb_cycle, g_help_can_snap;
#ifndef XANTH_HEADLESS_STUB
static SDL_Texture *g_help_texture;
#endif
void hal_video_toggle_controller_help(void) { g_controller_help = !g_controller_help; }
void hal_video_set_controller_capabilities(bool can_verb_cycle, bool can_snap) {
    if (can_verb_cycle == g_help_can_verb_cycle && can_snap == g_help_can_snap) return;
    g_help_can_verb_cycle = can_verb_cycle; g_help_can_snap = can_snap;
#ifndef XANTH_HEADLESS_STUB
    if (g_help_texture) { SDL_DestroyTexture(g_help_texture); g_help_texture = NULL; }
#endif
}
void hal_video_shutdown(void) {
#ifndef XANTH_HEADLESS_STUB
    if (g_video.host_cursor_hidden) {
        SDL_ShowCursor(g_video.saved_host_cursor);
        g_video.host_cursor_hidden = false;
    }
    if (g_help_texture) { SDL_DestroyTexture(g_help_texture); g_help_texture = NULL; }
    if (g_video.texture) {
        SDL_DestroyTexture(g_video.texture);
        g_video.texture = NULL;
    }
    if (g_video.renderer) {
        SDL_DestroyRenderer(g_video.renderer);
        g_video.renderer = NULL;
    }
    if (g_video.window) {
        SDL_DestroyWindow(g_video.window);
        g_video.window = NULL;
    }
#endif
    if (g_video.back_buffer) {
        free(g_video.back_buffer);
        g_video.back_buffer = NULL;
    }
    if (g_video.rgba_surface) {
        free(g_video.rgba_surface);
        g_video.rgba_surface = NULL;
    }
}

void hal_video_set_active_buffer(int target) {
    g_video.active_target = (target != 0) ? 1 : 0;
}

uint8_t *hal_video_get_screen_buffer(void) {
    return g_video.screen_buffer;
}

uint8_t *hal_video_get_back_buffer(void) {
    return g_video.back_buffer;
}

uint8_t *hal_video_get_active_buffer(void) {
    return (g_video.active_target == 1) ? g_video.back_buffer : g_video.screen_buffer;
}

void hal_video_set_palette_entry(uint8_t index, uint8_t r6, uint8_t g6, uint8_t b6) {
    r6 &= 0x3F;
    g6 &= 0x3F;
    b6 &= 0x3F;

    g_video.dac[index].r = r6;
    g_video.dac[index].g = g6;
    g_video.dac[index].b = b6;

    /* Bit replication formula: (c << 2) | (c >> 4) */
    uint8_t r8 = (uint8_t)((r6 << 2) | (r6 >> 4));
    uint8_t g8 = (uint8_t)((g6 << 2) | (g6 >> 4));
    uint8_t b8 = (uint8_t)((b6 << 2) | (b6 >> 4));

    /* RGBA8888 packed format: (R << 24) | (G << 16) | (B << 8) | A */
    g_video.rgba[index] = ((uint32_t)r8 << 24) | ((uint32_t)g8 << 16) | ((uint32_t)b8 << 8) | 0xFF;
}

void hal_video_set_palette(const uint8_t *rgb_triplets, int start, int count) {
    if (!rgb_triplets || start < 0 || count <= 0) return;
    for (int i = 0; i < count; i++) {
        int idx = start + i;
        if (idx >= HAL_VIDEO_PALETTE_NUM) break;
        hal_video_set_palette_entry(
            (uint8_t)idx,
            rgb_triplets[i * 3 + 0],
            rgb_triplets[i * 3 + 1],
            rgb_triplets[i * 3 + 2]
        );
    }
}

void hal_video_cycle_palette(int start_reg, int count) {
    if (!g_video.cycling_enabled || count <= 1 || start_reg < 0 || start_reg >= HAL_VIDEO_PALETTE_NUM || count > HAL_VIDEO_PALETTE_NUM - start_reg) {
        return;
    }

    /* Rotate palette entries: right shift circularly by 1 */
    vga_dac_t last = g_video.dac[start_reg + count - 1];
    for (int i = count - 1; i > 0; i--) {
        g_video.dac[start_reg + i] = g_video.dac[start_reg + i - 1];
        hal_video_set_palette_entry(
            (uint8_t)(start_reg + i),
            g_video.dac[start_reg + i].r,
            g_video.dac[start_reg + i].g,
            g_video.dac[start_reg + i].b
        );
    }
    g_video.dac[start_reg] = last;
    hal_video_set_palette_entry((uint8_t)start_reg, last.r, last.g, last.b);
}

bool hal_video_blit(int x, int y, int w, int h, const uint8_t *src, int stride) {
    if (!src || w <= 0 || h <= 0 || stride <= 0) return false;

    int x0 = (x < 0) ? 0 : ((x > HAL_VIDEO_WIDTH) ? HAL_VIDEO_WIDTH : x);
    int y0 = (y < 0) ? 0 : ((y > HAL_VIDEO_HEIGHT) ? HAL_VIDEO_HEIGHT : y);
    int x1 = (x + w < 0) ? 0 : ((x + w > HAL_VIDEO_WIDTH) ? HAL_VIDEO_WIDTH : x + w);
    int y1 = (y + h < 0) ? 0 : ((y + h > HAL_VIDEO_HEIGHT) ? HAL_VIDEO_HEIGHT : y + h);

    int clip_w = x1 - x0;
    int clip_h = y1 - y0;
    if (clip_w <= 0 || clip_h <= 0) return false;

    int src_off_x = x0 - x;
    int src_off_y = y0 - y;

    uint8_t *dst = hal_video_get_active_buffer();
    for (int row = 0; row < clip_h; row++) {
        const uint8_t *src_row = src + (src_off_y + row) * stride + src_off_x;
        uint8_t *dst_row = dst + (y0 + row) * HAL_VIDEO_WIDTH + x0;
        memcpy(dst_row, src_row, (size_t)clip_w);
    }
    return true;
}

void hal_video_flip(void) {
    /* If active target was backbuffer, copy backbuffer to screen buffer */
    if (g_video.active_target == 1) {
        memcpy(g_video.screen_buffer, g_video.back_buffer, HAL_VIDEO_FRAME_SIZE);
    }

    /* Expand 8-bit paletted screen buffer to 32-bit RGBA surface */
    if (g_video.rgba_surface) {
        for (int i = 0; i < HAL_VIDEO_FRAME_SIZE; i++) {
            uint8_t idx = g_video.screen_buffer[i];
            g_video.rgba_surface[i] = g_video.rgba[idx];
        }
    }

    g_video.frame_count++;

#ifndef XANTH_HEADLESS_STUB
    if (g_video.renderer && g_video.texture && !g_video.headless) {
        SDL_UpdateTexture(g_video.texture, NULL, g_video.rgba_surface, HAL_VIDEO_WIDTH * sizeof(uint32_t));

        int win_w = 0, win_h = 0;
        SDL_GetRendererOutputSize(g_video.renderer, &win_w, &win_h);
        if (win_w > 0 && win_h > 0) {
            /* 4:3 pixel-aspect correction, or square-pixel integer scaling. */
            hal_video_viewport viewport = hal_video_compute_viewport(
                win_w, win_h, g_video.present_mode);
            int target_w = viewport.width, target_h = viewport.height;
            int off_x = viewport.x, off_y = viewport.y;

            g_video.viewport_x = off_x;
            g_video.viewport_y = off_y;
            g_video.viewport_w = target_w;
            g_video.viewport_h = target_h;

            SDL_Rect dst_rect = { off_x, off_y, target_w, target_h };
            SDL_SetRenderDrawColor(g_video.renderer, 0, 0, 0, 255);
            SDL_RenderClear(g_video.renderer);
            SDL_RenderCopy(g_video.renderer, g_video.texture, NULL, &dst_rect);
            if (g_video.crt_scanlines) {
                SDL_SetRenderDrawBlendMode(g_video.renderer, SDL_BLENDMODE_BLEND);
                SDL_SetRenderDrawColor(g_video.renderer, 0, 0, 0, 48);
                for (int y = off_y + 1; y < off_y + target_h; y += 2)
                    SDL_RenderDrawLine(g_video.renderer, off_x, y, off_x + target_w - 1, y);
                SDL_SetRenderDrawBlendMode(g_video.renderer, SDL_BLENDMODE_NONE);
            }
            if (g_controller_help) {
                if (!g_help_texture) {
                    uint32_t *panel = malloc(CONTROLLER_HELP_PIXELS * sizeof(*panel));
                    if (panel && controller_help_render(panel, CONTROLLER_HELP_PIXELS, g_help_can_verb_cycle, g_help_can_snap)) {
                        g_help_texture = SDL_CreateTexture(g_video.renderer, SDL_PIXELFORMAT_RGBA8888,
                            SDL_TEXTUREACCESS_STATIC, CONTROLLER_HELP_WIDTH, CONTROLLER_HELP_HEIGHT);
                        if (g_help_texture) {
                            SDL_UpdateTexture(g_help_texture, NULL, panel, CONTROLLER_HELP_WIDTH * sizeof(*panel));
                            SDL_SetTextureBlendMode(g_help_texture, SDL_BLENDMODE_BLEND);
                        }
                    }
                    free(panel);
                }
                if (g_help_texture) {
                    SDL_Rect help_rect = {off_x, off_y + target_h * 12 / 200,
                                          target_w, target_h * CONTROLLER_HELP_HEIGHT / 200};
                    SDL_RenderCopy(g_video.renderer, g_help_texture, NULL, &help_rect);
                }
            }
            if (g_overlay) g_overlay(g_video.renderer, &viewport, g_overlay_user);
            SDL_RenderPresent(g_video.renderer);
        }
    }
#endif
}

void hal_video_wait_vsync(void) {
    /* Handled by SDL_RENDERER_PRESENTVSYNC or main frame pacer */
}

void hal_video_get_viewport(int *x, int *y, int *w, int *h) {
    update_viewport();
    if (x) *x = g_video.viewport_x;
    if (y) *y = g_video.viewport_y;
    if (w) *w = g_video.viewport_w;
    if (h) *h = g_video.viewport_h;
}

uint64_t hal_video_get_frame_count(void) {
    return g_video.frame_count;
}

/* Writes a 24-bit BMP; pixel(x, y) returns RGBA8888 for the source image. */
static bool write_bmp(const char *path, uint32_t (*pixel)(int x, int y)) {
    FILE *f = fopen(path, "wb");
    if (!f) return false;

    int w = HAL_VIDEO_WIDTH;
    int h = HAL_VIDEO_HEIGHT;
    int row_bytes = (w * 3 + 3) & ~3;
    uint32_t img_size = (uint32_t)(row_bytes * h);
    uint32_t file_size = 54 + img_size;

    uint8_t header[54] = {
        'B', 'M',
        (uint8_t)(file_size & 0xFF), (uint8_t)((file_size >> 8) & 0xFF),
        (uint8_t)((file_size >> 16) & 0xFF), (uint8_t)((file_size >> 24) & 0xFF),
        0, 0, 0, 0,
        54, 0, 0, 0,
        40, 0, 0, 0,
        (uint8_t)(w & 0xFF), (uint8_t)((w >> 8) & 0xFF), 0, 0,
        (uint8_t)(h & 0xFF), (uint8_t)((h >> 8) & 0xFF), 0, 0,
        1, 0, 24, 0,
        0, 0, 0, 0,
        (uint8_t)(img_size & 0xFF), (uint8_t)((img_size >> 8) & 0xFF),
        (uint8_t)((img_size >> 16) & 0xFF), (uint8_t)((img_size >> 24) & 0xFF),
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    };
    fwrite(header, 1, 54, f);

    uint8_t *row = (uint8_t *)calloc(1, row_bytes);
    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            uint32_t p = pixel(x, y);
            row[x * 3 + 0] = (uint8_t)(p >> 8);
            row[x * 3 + 1] = (uint8_t)(p >> 16);
            row[x * 3 + 2] = (uint8_t)(p >> 24);
        }
        fwrite(row, 1, row_bytes, f);
    }
    free(row);
    fclose(f);
    return true;
}

static uint32_t guest_pixel(int x, int y) {
    uint8_t idx = g_video.screen_buffer[y * HAL_VIDEO_WIDTH + x];
    vga_dac_t d = g_video.dac[idx];
    /* 6-bit DAC to 8-bit RGB */
    uint8_t r = (uint8_t)((d.r << 2) | (d.r >> 4));
    uint8_t g = (uint8_t)((d.g << 2) | (d.g >> 4));
    uint8_t b = (uint8_t)((d.b << 2) | (d.b >> 4));
    return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | 0xFF;
}

static const uint32_t *g_bmp_rgba;

static uint32_t rgba_pixel(int x, int y) {
    return g_bmp_rgba[y * HAL_VIDEO_WIDTH + x];
}

bool hal_video_save_bmp(const char *path) {
    if (!path || !g_video.screen_buffer) return false;
    return write_bmp(path, guest_pixel);
}

bool hal_video_copy_presented(uint32_t *dst) {
    if (!dst || !g_video.rgba_surface) return false;
    memcpy(dst, g_video.rgba_surface, HAL_VIDEO_FRAME_SIZE * sizeof(uint32_t));
    return true;
}

bool hal_video_save_rgba_bmp(const char *path, const uint32_t *rgba) {
    if (!path || !rgba) return false;
    g_bmp_rgba = rgba;
    return write_bmp(path, rgba_pixel);
}

bool hal_video_crt_enabled(void) {
    return g_video.crt_scanlines;
}
