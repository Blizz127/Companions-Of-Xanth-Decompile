#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* 1 MB Virtual DOS conventional memory buffer */
uint8_t g_dos_mem[DOS_MEM_SIZE] = {0};

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
    uint64_t frame_count;
} hal_video_ctx_t;

static hal_video_ctx_t g_video;

bool hal_video_init(int scale, bool fullscreen, bool headless, bool enable_cycling) {
    memset(&g_video, 0, sizeof(g_video));

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

    /* Initial 4:3 viewport */
    g_video.viewport_x = 0;
    g_video.viewport_y = 0;
    g_video.viewport_w = g_video.window_width;
    g_video.viewport_h = g_video.window_height;

    return true;
}

void hal_video_shutdown(void) {
#ifndef XANTH_HEADLESS_STUB
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
            /* 4:3 aspect ratio letterboxing / pillarboxing */
            int target_w, target_h;
            if (win_w * 3 > win_h * 4) {
                target_h = win_h;
                target_w = (win_h * 4) / 3;
            } else {
                target_w = win_w;
                target_h = (win_w * 3) / 4;
            }
            int off_x = (win_w - target_w) / 2;
            int off_y = (win_h - target_h) / 2;

            g_video.viewport_x = off_x;
            g_video.viewport_y = off_y;
            g_video.viewport_w = target_w;
            g_video.viewport_h = target_h;

            SDL_Rect dst_rect = { off_x, off_y, target_w, target_h };
            SDL_SetRenderDrawColor(g_video.renderer, 0, 0, 0, 255);
            SDL_RenderClear(g_video.renderer);
            SDL_RenderCopy(g_video.renderer, g_video.texture, NULL, &dst_rect);
            SDL_RenderPresent(g_video.renderer);
        }
    }
#endif
}

void hal_video_wait_vsync(void) {
    /* Handled by SDL_RENDERER_PRESENTVSYNC or main frame pacer */
}

void hal_video_get_viewport(int *x, int *y, int *w, int *h) {
    if (x) *x = g_video.viewport_x;
    if (y) *y = g_video.viewport_y;
    if (w) *w = g_video.viewport_w;
    if (h) *h = g_video.viewport_h;
}

uint64_t hal_video_get_frame_count(void) {
    return g_video.frame_count;
}

bool hal_video_save_bmp(const char *path) {
    if (!path || !g_video.screen_buffer) return false;

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
            uint8_t idx = g_video.screen_buffer[y * w + x];
            vga_dac_t d = g_video.dac[idx];
            /* 6-bit DAC to 8-bit RGB */
            uint8_t r = (uint8_t)((d.r << 2) | (d.r >> 4));
            uint8_t g = (uint8_t)((d.g << 2) | (d.g >> 4));
            uint8_t b = (uint8_t)((d.b << 2) | (d.b >> 4));
            row[x * 3 + 0] = b;
            row[x * 3 + 1] = g;
            row[x * 3 + 2] = r;
        }
        fwrite(row, 1, row_bytes, f);
    }
    free(row);
    fclose(f);
    return true;
}
