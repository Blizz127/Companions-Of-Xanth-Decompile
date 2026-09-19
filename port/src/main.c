#include "port_engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

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

#if defined(_MSC_VER) || defined(__MINGW32__)
  #include <intrin.h>
  #define CPU_PAUSE() _mm_pause()
#elif defined(__x86_64__) || defined(__i386__)
  #define CPU_PAUSE() __builtin_ia32_pause()
#else
  #define CPU_PAUSE() ((void)0)
#endif

static char g_dump_frames_dir[512] = {0};

static void print_usage(const char *prog_name) {
    printf("Companions of Xanth (1993) - Native Cross-Platform Port\n");
    printf("Usage: %s [options]\n\n", prog_name);
    printf("Options:\n");
    printf("  --headless          Run in headless mode (no window or real audio)\n");
    printf("  --frames <N>        Execute exactly N frame ticks and exit cleanly\n");
    printf("  --nocycle           Disable VGA DAC dynamic palette cycling\n");
    printf("  --xmouse            Enable alternative INT 33h mouse driver handling\n");
    printf("  --data <path>       Specify path to game data assets (default: original)\n");
    printf("  --test-boot         Run boot validation suite and assert non-black frame ratio\n");
    printf("  -h, --help          Display this help message and exit\n");
}

static int parse_cli_args(int argc, char **argv, EngineConfig *cfg) {
    cfg->headless = false;
    cfg->max_frames = 0;
    cfg->has_max_frames = false;
    cfg->palette_cycling_enabled = true;
    cfg->use_xmouse = false;
    cfg->test_boot = false;
    cfg->target_fps = 70.0;
    snprintf(cfg->data_path, sizeof(cfg->data_path), "original");
    cfg->save_path[0] = '\0';

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--headless") == 0) {
            cfg->headless = true;
        } else if (strcmp(argv[i], "--nocycle") == 0) {
            cfg->palette_cycling_enabled = false;
        } else if (strcmp(argv[i], "--xmouse") == 0) {
            cfg->use_xmouse = true;
        } else if (strcmp(argv[i], "--test-boot") == 0) {
            cfg->test_boot = true;
        } else if (strcmp(argv[i], "--frames") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[ERROR] Missing argument for --frames\n");
                return -1;
            }
            char *endptr = NULL;
            long val = strtol(argv[++i], &endptr, 10);
            if (*endptr != '\0') {
                fprintf(stderr, "[ERROR] Invalid non-integer argument for --frames: %s\n", argv[i]);
                return -2;
            }
            if (val < 0) {
                fprintf(stderr, "[ERROR] Negative frame count rejected: %ld\n", val);
                return -3;
            }
            cfg->max_frames = (uint64_t)val;
            cfg->has_max_frames = true;
        } else if (strcmp(argv[i], "--data") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[ERROR] Missing argument for --data\n");
                return -4;
            }
            snprintf(cfg->data_path, sizeof(cfg->data_path), "%s", argv[++i]);
        } else if (strcmp(argv[i], "--saves") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[ERROR] Missing argument for --saves\n");
                return -5;
            }
            snprintf(cfg->save_path, sizeof(cfg->save_path), "%s", argv[++i]);
        } else if (strcmp(argv[i], "--dump-frames") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "[ERROR] Missing argument for --dump-frames\n");
                return -6;
            }
            snprintf(g_dump_frames_dir, sizeof(g_dump_frames_dir), "%s", argv[++i]);
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_usage(argv[0]);
            exit(0);
        } else {
            fprintf(stderr, "[WARN] Unknown command-line argument: %s\n", argv[i]);
        }
    }
    return 0;
}

void engine_run_tick_loop(EngineContext *ctx) {
#ifndef XANTH_HEADLESS_STUB
    uint64_t perf_freq = SDL_GetPerformanceFrequency();
    if (perf_freq == 0) perf_freq = 1000000;
#else
    uint64_t perf_freq = 1000000;
#endif

    double target_fps = ctx->config.target_fps > 0 ? ctx->config.target_fps : 70.0;
    uint64_t frame_period_ticks = (uint64_t)((double)perf_freq / target_fps);

#ifndef XANTH_HEADLESS_STUB
    uint64_t next_frame_tick = SDL_GetPerformanceCounter();
#else
    uint64_t next_frame_tick = 0;
#endif

    ctx->running = true;

    /* If --frames 0 was specified, terminate immediately without ticking */
    if (ctx->config.has_max_frames && ctx->config.max_frames == 0) {
        ctx->running = false;
        return;
    }

    while (ctx->running) {
        if (ctx->config.has_max_frames && ctx->frame_count >= ctx->config.max_frames) {
            ctx->running = false;
            break;
        }

        /* 1. Poll Input Events */
        int mouse_x = 0, mouse_y = 0, mouse_btn = 0, key_code = 0;
        hal_input_poll(&mouse_x, &mouse_y, &mouse_btn, &key_code);
        if (key_code == 27) { /* Escape key triggers exit */
            ctx->running = false;
            break;
        }

        /* Forward inputs to interactive engine handler */
        engine_handle_input(ctx, mouse_x, mouse_y, mouse_btn, key_code);

        /* 2. Update Engine State Machine & Boot Phase */
        engine_update_phase(ctx);

        /* 3. Audio Sequencing & Streaming Tick */
        hal_audio_tick();

        /* 4. VGA Palette Cycling (Dynamic Water / Magic registers 240..255) */
        if (ctx->config.palette_cycling_enabled) {
            hal_video_cycle_palette(240, 16);
        }

        /* 5. Render Scene & Flip Framebuffer */
        hal_video_flip();

        /* Optional diagnostic frame dumping */
        if (g_dump_frames_dir[0]) {
            if (ctx->frame_count == 50 || ctx->frame_count == 150 ||
                ctx->frame_count == 250 || ctx->frame_count == 350 ||
                ctx->frame_count == 450 || ctx->frame_count == 500) {
                char bmp_path[512];
                snprintf(bmp_path, sizeof(bmp_path), "%s/frame_%04" PRIu64 ".bmp",
                         g_dump_frames_dir, ctx->frame_count);
                hal_video_save_bmp(bmp_path);
            }
        }

        /* 6. Advance Frame Counter */
        ctx->frame_count++;

        /* Check termination frame count */
        if (ctx->config.has_max_frames && ctx->frame_count >= ctx->config.max_frames) {
            ctx->running = false;
            break;
        }

        /* 7. Monotonic Timing & CPU Yielding (Keeps CPU usage < 1%) */
#ifndef XANTH_HEADLESS_STUB
        next_frame_tick += frame_period_ticks;
        uint64_t now = SDL_GetPerformanceCounter();

        if (now < next_frame_tick) {
            uint64_t remaining_ticks = next_frame_tick - now;
            double remaining_ms = (double)remaining_ticks * 1000.0 / (double)perf_freq;
            if (ctx->config.headless) {
                while (SDL_GetPerformanceCounter() < next_frame_tick) {
                    SDL_Delay(1);
                }
            } else {
                if (remaining_ms > 2.0) {
                    SDL_Delay((Uint32)(remaining_ms - 1.0));
                }
                while (SDL_GetPerformanceCounter() < next_frame_tick) {
                    CPU_PAUSE();
                }
            }
        } else {
            next_frame_tick = now;
        }
#endif
    }
}

int main(int argc, char **argv) {
    EngineConfig cfg;
    int parse_res = parse_cli_args(argc, argv, &cfg);
    if (parse_res != 0) {
        return 1;
    }

    /* Configure environment for headless mode */
    if (cfg.headless) {
#if defined(_WIN32) || defined(_MSC_VER)
        _putenv("SDL_VIDEODRIVER=dummy");
        _putenv("SDL_AUDIODRIVER=dummy");
#else
        setenv("SDL_VIDEODRIVER", "dummy", 1);
        setenv("SDL_AUDIODRIVER", "dummy", 1);
#endif
    }

    if (engine_init(&g_engine_ctx, &cfg) != 0) {
        fprintf(stderr, "[FATAL] engine_init failed\n");
        return 1;
    }

    /* Run main engine tick loop */
    engine_run_tick_loop(&g_engine_ctx);

    /* Verify smoke test assertions */
    if (cfg.test_boot) {
        double pixel_ratio = engine_verify_framebuffer(g_engine_ctx.screen_buffer);
        printf("[SMOKE] Frame %" PRIu64 " reached, non-black pixel ratio = %.1f%%\n",
               g_engine_ctx.frame_count, pixel_ratio * 100.0);

        if (g_engine_ctx.frame_count >= 50) {
            if (pixel_ratio <= 0.20) {
                fprintf(stderr, "[FAIL] Non-black pixel ratio %.1f%% <= 20%%\n", pixel_ratio * 100.0);
                engine_shutdown(&g_engine_ctx);
                return 2;
            }
        }

        printf("[SMOKE] BOOT_SUCCESS: Frame %" PRIu64 " reached, non-black pixel ratio = %.1f%%, clean shutdown.\n",
               g_engine_ctx.frame_count, pixel_ratio * 100.0);
    }

    engine_shutdown(&g_engine_ctx);
    return 0;
}
