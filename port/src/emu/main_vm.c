/*
 * main_vm.c — the native port's entry point.
 *
 * Runs the real retail XANTH.EXE under the 16-bit VM, presenting through the
 * SDL HAL. Recovered units with verified native adapters are dispatched at
 * their retail addresses; all other game instructions remain guest code.
 * This file wires input, timing and presentation to the guest machine.
 *
 * The Mode 13h framebuffer is already aliased to g_dos_mem + 0xA0000, so the
 * guest's VGA writes need no copying; only the DAC palette has to be pushed
 * across each frame.
 */
#include "vm.h"
#include "native_stage2.h"
#include "port_hal.h"
#include "asset_check.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#if !defined(_WIN32) && !defined(__APPLE__)
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

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

static void report_startup_error(const char *message, bool headless) {
    fprintf(stderr, "[FATAL] %s\n", message);
#ifndef XANTH_HEADLESS_STUB
    if (!headless &&
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
                                 "Companions of Xanth could not start",
                                 message, NULL) == 0)
        return;
#else
    (void)headless;
#endif
    fprintf(stderr, "[FATAL] Could not display a graphical error dialog.\n");
}

/* A first-run chooser is deliberately delegated to the desktop environment's
 * installed file chooser.  This adds no bundled UI toolkit or library and
 * does not run for a valid data path or in headless mode. */
#if !defined(_WIN32) && !defined(__APPLE__)
static bool run_directory_picker(const char *tool, const char *start,
                                 char *out, size_t out_size) {
    int fds[2];
    pid_t child;
    size_t used = 0;
    int status = 0;
    char initial[1024];
    if (pipe(fds) != 0) return false;
    child = fork();
    if (child < 0) { close(fds[0]); close(fds[1]); return false; }
    if (child == 0) {
        close(fds[0]);
        if (dup2(fds[1], STDOUT_FILENO) < 0) _exit(126);
        close(fds[1]);
        if (!strcmp(tool, "kdialog"))
            execlp(tool, tool, "--getexistingdirectory", start,
                   "Choose your Companions of Xanth game-data folder", (char *)NULL);
        else {
            snprintf(initial, sizeof(initial), "%s/", start);
            execlp(tool, tool, "--file-selection", "--directory",
                   "--filename", initial, "--title",
                   "Choose your Companions of Xanth game-data folder", (char *)NULL);
        }
        _exit(127);
    }
    close(fds[1]);
    while (used + 1 < out_size) {
        ssize_t n = read(fds[0], out + used, out_size - used - 1);
        if (n <= 0) break;
        used += (size_t)n;
    }
    close(fds[0]);
    out[used] = '\0';
    while (used && (out[used-1] == '\n' || out[used-1] == '\r'))
        out[--used] = '\0';
    pid_t waited;
    do { waited = waitpid(child, &status, 0); } while (waited < 0 && errno == EINTR);
    if (waited < 0) return false;
    return WIFEXITED(status) && WEXITSTATUS(status) == 0 && used > 0;
}

static bool program_in_path(const char *name) {
    const char *path = getenv("PATH");
    const char *at = path;
    if (!path || !*path) return false;
    while (*at) {
        const char *end = strchr(at, ':');
        size_t n = end ? (size_t)(end - at) : strlen(at);
        char candidate[1024];
        int written = snprintf(candidate, sizeof(candidate), "%.*s/%s",
                               (int)(n > 900 ? 900 : n), at, name);
        if (written > 0 && (size_t)written < sizeof(candidate) &&
            access(candidate, X_OK) == 0) return true;
        if (!end) break;
        at = end + 1;
    }
    return false;
}

static bool pick_data_directory(const char *start, char *out, size_t out_size) {
    if (program_in_path("kdialog"))
        return run_directory_picker("kdialog", start, out, out_size);
    if (program_in_path("zenity"))
        return run_directory_picker("zenity", start, out, out_size);
    return false;
}

static void data_directory_state_path(char *out, size_t out_size) {
    const char *base = getenv("XDG_CONFIG_HOME");
    const char *home = getenv("HOME");
    char dir[768];
    if (!base || !*base) {
        char parent[768];
        if (!home || !*home) { out[0] = '\0'; return; }
        snprintf(parent, sizeof(parent), "%.700s/.config", home);
        if (mkdir(parent, 0700) != 0 && access(parent, F_OK) != 0) {
            out[0] = '\0'; return;
        }
        snprintf(dir, sizeof(dir), "%.740s/companions-of-xanth", parent);
    } else {
        if (mkdir(base, 0700) != 0 && access(base, F_OK) != 0) {
            out[0] = '\0'; return;
        }
        snprintf(dir, sizeof(dir), "%.680s/companions-of-xanth", base);
    }
    if (mkdir(dir, 0700) != 0 && access(dir, F_OK) != 0) { out[0] = '\0'; return; }
    snprintf(out, out_size, "%s/data-directory.txt", dir);
}

static void load_remembered_data_directory(char *out, size_t out_size) {
    char path[1024], line[1024];
    FILE *f;
    data_directory_state_path(path, sizeof(path));
    if (!path[0] || !(f = fopen(path, "r"))) return;
    if (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] && out_size) {
            snprintf(out, out_size, "%.*s", (int)(out_size - 1), line);
        }
    }
    fclose(f);
}

static bool remember_data_directory(const char *directory) {
    char path[1024];
    FILE *f;
    data_directory_state_path(path, sizeof(path));
    if (!path[0] || !(f = fopen(path, "w"))) return false;
    fprintf(f, "%s\n", directory);
    return fclose(f) == 0;
}
#endif

static void make_friendly_asset_error(const char *detail, char *out,
                                      size_t out_size) {
    if (strstr(detail, "SHA-256 mismatch")) {
        snprintf(out, out_size,
                 "These files do not match the supported XANBUD game release. "
                 "They may be from another version or an incomplete install. "
                 "Choose the folder containing XANTH.EXE and the 90 runtime "
                 "files, all directly inside it.");
    } else if (strstr(detail, "missing or unreadable")) {
        snprintf(out, out_size,
                 "The game-data folder is missing required files. Choose the "
                 "folder containing XANTH.EXE and the 90 runtime files, all "
                 "directly inside it.");
    } else {
        snprintf(out, out_size, "%s", detail);
    }
}

/*
 * Guest time per host frame.
 *
 * The virtual clock runs at cycles_per_second and the PIT ticks at 18.2 Hz
 * off it, so pacing one frame's worth of cycles per host frame is what makes
 * the game run at the speed it was written for. Tying it to instructions
 * executed instead would make the game's speed depend on how fast the host
 * interpreter happens to be.
 */
#define TARGET_FPS 70.0

static void print_usage(const char *prog) {
    printf("Companions of Xanth (1993) — native port\n");
    printf("Usage: %s [options]\n\n", prog);
    printf("  --data <dir>     Directory holding the retail game files\n");
    printf("  --saves <dir>    Directory for saves and generated config\n");
    printf("  --mods <dir>     Opt in to SHA-256-keyed asset replacements\n");
    printf("  --replacement-fonts  Also allow hash-keyed .FNT replacements from --mods\n");
    printf("  --replacement-graphics  Allow hash-keyed .PIC/.RGN replacements from --mods\n");
    printf("  --config <file>  Load optional Xanth port settings\n");
    printf("  --exe <file>     Path to XANTH.EXE (default: <data>/XANTH.EXE)\n");
    printf("  --scale <n>      Window scale factor (default 3)\n");
    printf("  --fit            Fit a 4:3 viewport to fullscreen desktop\n");
    printf("  --pixel-perfect  Use square pixels with integer scaling (16:10 image)\n");
    printf("  --crt            Enable optional scanline overlay\n");
    printf("  --linear         Enable optional linear texture filtering\n");
    printf("  --enhanced-graphics Enable linear filtering and CRT scanlines\n");
    printf("  --handheld       Open at 1280x800 for Deck/Legion Go displays\n");
    printf("  --controller     Enable SDL gamepad input (automatic by default)\n");
    printf("  --no-controller  Disable automatic controller input\n");
    printf("  --hotkeys        Enable F11 fullscreen and F10 scanline hotkeys\n");
    printf("  --volume-<name> <0..128>  Set master/music/sfx/voice channel volume\n");
    printf("  --soundfont <sf2>  Opt in to FluidSynth General MIDI using your soundfont\n");
    printf("  --fullscreen     Start fullscreen\n");
    printf("  --headless       No window or audio device\n");
    printf("  --frames <n>     Run n frames then exit\n");
    printf("  --shot <file>    Write a BMP of the final frame\n");
    printf("  --audio-dump <wav> Capture final mixed SDL output (optional)\n");
    printf("  --cpu-speed <n>  Virtual CPU cycles per second (default 4000000)\n");
    printf("  --trace-dos      Log DOS calls\n");
    printf("  --permissive     Warn instead of aborting on unimplemented services\n");
    printf("  -h, --help       This message\n");
}

static uint8_t parse_volume(const char *text) {
    long value = strtol(text,NULL,10);
    if (value < 0) value=0;
    if (value > 128) value=128;
    return (uint8_t)value;
}

static bool config_bool(const char *value) {
    return !strcmp(value,"1") || !strcmp(value,"true") || !strcmp(value,"yes") || !strcmp(value,"on");
}

static bool load_port_config(const char *path, int *scale, bool *fullscreen,
                             bool *headless, bool *pixel_perfect, bool *crt,
                             bool *linear, bool *handheld, bool *gamepad,
                             bool *hotkeys,
                             bool *enhanced_graphics,
                             bool *replacement_fonts,
                             bool *replacement_graphics,
                             uint8_t *master, uint8_t *music, uint8_t *sfx,
                             uint8_t *voice, char *mods, size_t mods_size,
                             char *soundfont, size_t soundfont_size) {
    FILE *f=fopen(path,"r");
    char line[512];
    if (!f) return false;
    while (fgets(line,sizeof(line),f)) {
        char *key=line, *eq, *value;
        while (isspace((unsigned char)*key)) ++key;
        if (!*key || *key=='#' || *key==';') continue;
        eq=strchr(key,'=');
        if (!eq) continue;
        *eq='\0'; value=eq+1;
        key[strcspn(key," \t\r\n")]='\0';
        value[strcspn(value,"\r\n")]='\0';
        while (isspace((unsigned char)*value)) ++value;
        char *end=value+strlen(value);
        while (end>value && isspace((unsigned char)end[-1])) *--end='\0';
        if (!strcmp(key,"scale")) *scale=atoi(value);
        else if (!strcmp(key,"fullscreen")) *fullscreen=config_bool(value);
        else if (!strcmp(key,"headless")) *headless=config_bool(value);
        else if (!strcmp(key,"pixel_perfect")) *pixel_perfect=config_bool(value);
        else if (!strcmp(key,"crt")) *crt=config_bool(value);
        else if (!strcmp(key,"linear_filter")) *linear=config_bool(value);
        else if (!strcmp(key,"handheld_1280x800")) *handheld=config_bool(value);
        else if (!strcmp(key,"controller")) *gamepad=config_bool(value);
        else if (!strcmp(key,"hotkeys")) *hotkeys=config_bool(value);
        else if (!strcmp(key,"enhanced_graphics")) *enhanced_graphics=config_bool(value);
        else if (!strcmp(key,"replacement_fonts")) *replacement_fonts=config_bool(value);
        else if (!strcmp(key,"replacement_graphics")) *replacement_graphics=config_bool(value);
        else if (!strcmp(key,"volume_master")) *master=parse_volume(value);
        else if (!strcmp(key,"volume_music")) *music=parse_volume(value);
        else if (!strcmp(key,"volume_sfx")) *sfx=parse_volume(value);
        else if (!strcmp(key,"volume_voice")) *voice=parse_volume(value);
        else if (!strcmp(key,"mods") && mods_size) snprintf(mods,mods_size,"%s",value);
        else if (!strcmp(key,"soundfont") && soundfont_size) snprintf(soundfont,soundfont_size,"%s",value);
    }
    fclose(f);
    return true;
}

int main(int argc, char **argv) {
    vm_config cfg;
    vm machine;
    char err[512] = {0};
    char shot_path[512] = {0};
    char audio_dump_path[512] = {0};
    int scale = 3;
    bool fullscreen = false, headless = false;
    bool pixel_perfect = false, crt = false, linear = false, handheld = false;
    bool gamepad = true, hotkeys = false;
    bool enhanced_graphics = false;
    bool replacement_fonts = false;
    bool replacement_graphics = false;
    char config_path[512] = "";
    char soundfont_path[512] = "";
    long long max_frames = 0;
    unsigned long cpu_speed = 4000000ul;
    uint8_t volume_master = 128, volume_music = 100, volume_sfx = 110, volume_voice = 120;
    bool have_exe = false;

    memset(&cfg, 0, sizeof(cfg));
    snprintf(cfg.data_dir, sizeof(cfg.data_dir), "game_cd/XANTH");
#if !defined(_WIN32) && !defined(__APPLE__)
    {
        const char *home = getenv("HOME");
        if (home && *home)
            snprintf(cfg.data_dir, sizeof(cfg.data_dir),
                     "%.470s/Games/companions-of-xanth/data", home);
        load_remembered_data_directory(cfg.data_dir, sizeof(cfg.data_dir));
    }
#endif
    snprintf(cfg.save_dir, sizeof(cfg.save_dir), "build/saves");

    for (int i=1;i<argc;++i)
        if (!strcmp(argv[i],"--config") && i+1<argc)
            snprintf(config_path,sizeof(config_path),"%s",argv[i+1]);
    if (config_path[0] &&
        !load_port_config(config_path,&scale,&fullscreen,&headless,&pixel_perfect,
                         &crt,&linear,&handheld,&gamepad,&hotkeys,
                         &enhanced_graphics,&replacement_fonts,
                         &replacement_graphics,
                         &volume_master,
                         &volume_music,&volume_sfx,&volume_voice,cfg.mods_dir,
                         sizeof(cfg.mods_dir),soundfont_path,sizeof(soundfont_path))) {
        fprintf(stderr,"[FATAL] cannot read config file: %s\n",config_path);
        return 2;
    }
    if (enhanced_graphics) {
        crt = true;
        linear = true;
    }

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--data") && i + 1 < argc)
            snprintf(cfg.data_dir, sizeof(cfg.data_dir), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--saves") && i + 1 < argc)
            snprintf(cfg.save_dir, sizeof(cfg.save_dir), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--mods") && i + 1 < argc)
            snprintf(cfg.mods_dir, sizeof(cfg.mods_dir), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--replacement-fonts")) replacement_fonts = true;
        else if (!strcmp(argv[i], "--replacement-graphics")) replacement_graphics = true;
        else if (!strcmp(argv[i], "--soundfont") && i+1<argc)
            snprintf(soundfont_path,sizeof(soundfont_path),"%s",argv[++i]);
        else if (!strcmp(argv[i],"--config") && i+1<argc) ++i;
        else if (!strcmp(argv[i], "--exe") && i + 1 < argc) {
            snprintf(cfg.exe_path, sizeof(cfg.exe_path), "%s", argv[++i]);
            have_exe = true;
        }
        else if (!strcmp(argv[i], "--scale") && i + 1 < argc) scale = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--fit")) fullscreen = true;
        else if (!strcmp(argv[i], "--pixel-perfect")) pixel_perfect = true;
        else if (!strcmp(argv[i], "--crt")) crt = true;
        else if (!strcmp(argv[i], "--linear")) linear = true;
        else if (!strcmp(argv[i], "--enhanced-graphics")) crt = linear = true;
        else if (!strcmp(argv[i], "--handheld")) handheld = true;
        else if (!strcmp(argv[i], "--controller")) gamepad = true;
        else if (!strcmp(argv[i], "--no-controller")) gamepad = false;
        else if (!strcmp(argv[i], "--hotkeys")) hotkeys = true;
        else if (!strcmp(argv[i], "--volume-master") && i + 1 < argc) volume_master = parse_volume(argv[++i]);
        else if (!strcmp(argv[i], "--volume-music") && i + 1 < argc) volume_music = parse_volume(argv[++i]);
        else if (!strcmp(argv[i], "--volume-sfx") && i + 1 < argc) volume_sfx = parse_volume(argv[++i]);
        else if (!strcmp(argv[i], "--volume-voice") && i + 1 < argc) volume_voice = parse_volume(argv[++i]);
        else if (!strcmp(argv[i], "--fullscreen")) fullscreen = true;
        else if (!strcmp(argv[i], "--headless")) headless = true;
        else if (!strcmp(argv[i], "--frames") && i + 1 < argc)
            max_frames = atoll(argv[++i]);
        else if (!strcmp(argv[i], "--shot") && i + 1 < argc)
            snprintf(shot_path, sizeof(shot_path), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--audio-dump") && i + 1 < argc)
            snprintf(audio_dump_path, sizeof(audio_dump_path), "%s", argv[++i]);
        else if (!strcmp(argv[i], "--cpu-speed") && i + 1 < argc)
            cpu_speed = strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--trace-dos")) cfg.trace_dos = true;
        else if (!strcmp(argv[i], "--permissive")) cfg.permissive = true;
        else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            print_usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "[ERROR] unknown argument: %s\n", argv[i]);
            return 2;
        }
    }

    hal_input_prepare_gamepad(gamepad);

    if (!have_exe) {
        int n = snprintf(cfg.exe_path, sizeof(cfg.exe_path),
                         "%.480s/XANTH.EXE", cfg.data_dir);
        if (n < 0 || (size_t)n >= sizeof(cfg.exe_path)) {
            fprintf(stderr, "[FATAL] data directory path is too long\n");
            return 2;
        }
    }

    {
        char asset_error[1024];
        bool selected_new_directory = false;
        if (!xanth_check_assets(cfg.exe_path,cfg.data_dir,asset_error,sizeof(asset_error))) {
#if !defined(_WIN32) && !defined(__APPLE__)
            if (!headless) {
                char chosen[512];
                const char *home = getenv("HOME");
                char start[512];
                if (home && *home)
                    snprintf(start, sizeof(start),
                             "%.455s/Games/companions-of-xanth/data", home);
                else
                    snprintf(start, sizeof(start), "%s", cfg.data_dir);
                if (pick_data_directory(start, chosen, sizeof(chosen))) {
                    snprintf(cfg.data_dir, sizeof(cfg.data_dir), "%s", chosen);
                    if (!have_exe) {
                        int n = snprintf(cfg.exe_path, sizeof(cfg.exe_path),
                                         "%.480s/XANTH.EXE", cfg.data_dir);
                        if (n < 0 || (size_t)n >= sizeof(cfg.exe_path)) {
                            snprintf(asset_error, sizeof(asset_error),
                                     "The selected game-data folder path is too long.");
                            report_startup_error(asset_error, headless);
                            return 2;
                        }
                    }
                    selected_new_directory = true;
                    if (!xanth_check_assets(cfg.exe_path, cfg.data_dir,
                                            asset_error, sizeof(asset_error))) {
                        char friendly[1024];
                        make_friendly_asset_error(asset_error, friendly, sizeof(friendly));
                        report_startup_error(friendly, headless);
                        return 2;
                    }
                } else {
                    char friendly[1024];
                    make_friendly_asset_error(asset_error, friendly, sizeof(friendly));
                    char message[1400];
                    snprintf(message, sizeof(message),
                             "%s\n\nIf the folder chooser is unavailable, install "
                             "kdialog or zenity, or start with --data <folder>.",
                             friendly);
                    report_startup_error(message, headless);
                    return 2;
                }
            } else {
                char friendly[1024];
                make_friendly_asset_error(asset_error, friendly, sizeof(friendly));
                char message[1400];
                snprintf(message, sizeof(message),
                         "%s\nSupply the folder with --data <directory> or "
                         "XANTH_DATA. No game files are included.", friendly);
                report_startup_error(message, headless);
                return 2;
            }
#else
            char friendly[1024];
            make_friendly_asset_error(asset_error, friendly, sizeof(friendly));
            report_startup_error(friendly, headless);
            return 2;
#endif
        }
#if !defined(_WIN32) && !defined(__APPLE__)
        if (selected_new_directory && !remember_data_directory(cfg.data_dir))
            fprintf(stderr,
                    "[WARN] game folder works for this session, but could not "
                    "be remembered; pass it with --data next time.\n");
#else
        (void)selected_new_directory;
#endif
    }

    if (headless) {
#if defined(_WIN32) || defined(_MSC_VER)
        _putenv("SDL_VIDEODRIVER=dummy");
        _putenv("SDL_AUDIODRIVER=dummy");
#else
        setenv("SDL_VIDEODRIVER", "dummy", 1);
        setenv("SDL_AUDIODRIVER", "dummy", 1);
#endif
    }

    /* Video first: it owns the SDL window that the framebuffer is presented
     * through, and vm_init zeroes g_dos_mem, so ordering matters. */
    if (!hal_video_init(scale, fullscreen, headless, false)) {
        fprintf(stderr, "[FATAL] could not initialise video\n");
        return 1;
    }
    if (pixel_perfect) hal_video_set_present_mode(HAL_VIDEO_PRESENT_PIXEL_INTEGER);
    if (crt || linear) hal_video_set_filter(crt,linear);
    if (handheld) hal_video_set_window_size(1280,800);
    hal_input_init();
    hal_input_enable_gamepad(gamepad);
    hal_input_enable_pointer_events(true);
    hal_input_enable_hotkeys(hotkeys);
    if (!hal_audio_init())
        fprintf(stderr, "[WARN] audio unavailable; continuing silently\n");
    hal_audio_set_volume(volume_master,volume_music,volume_sfx,volume_voice);
    if (audio_dump_path[0] && !hal_audio_capture_wav_start(audio_dump_path)) {
        fprintf(stderr, "[FATAL] cannot capture audio to %s (SDL output unavailable)\n",
                audio_dump_path);
        hal_audio_shutdown();
        hal_input_shutdown();
        hal_video_shutdown();
        return 2;
    }
    if (soundfont_path[0] && !hal_audio_enable_fluidsynth(soundfont_path)) {
        fprintf(stderr,"[FATAL] could not enable FluidSynth with the requested soundfont\n");
        hal_audio_shutdown();
        hal_input_shutdown();
        hal_video_shutdown();
        return 2;
    }
    vm_audio_opl_write = hal_audio_write_opl;
    vm_audio_dma_write = hal_audio_dma_submit_block;
    vm_audio_mpu_read_data = hal_audio_mpu_read_data;
    vm_audio_mpu_read_status = hal_audio_mpu_read_status;
    vm_audio_mpu_write_data = hal_audio_mpu_write_data;
    vm_audio_mpu_write_cmd = hal_audio_mpu_write_cmd;
    cfg.use_general_midi = soundfont_path[0] != '\0';
    cfg.replacement_fonts = replacement_fonts;
    cfg.replacement_graphics = replacement_graphics;

    if (!vm_init(&machine, &cfg, err, sizeof(err))) {
        fprintf(stderr, "[FATAL] %s\n", err);
        hal_video_shutdown();
        return 1;
    }
    if (!xanth_native_stage2_install(&machine)) {
        fprintf(stderr, "[FATAL] could not install verified Stage-2 native units\n");
        vm_shutdown(&machine);
        hal_audio_shutdown();
        hal_input_shutdown();
        hal_video_shutdown();
        return 1;
    }
    machine.cycles_per_second = cpu_speed;
    machine.pit_period_cycles = cpu_speed * 10 / 182;
    machine.next_tick_cycles  = machine.cpu.cycles + machine.pit_period_cycles;

    {
        const uint64_t cycles_per_frame =
            (uint64_t)(machine.cycles_per_second / TARGET_FPS);
        long long frame = 0;
        bool running = true;
        int last_mx = -1, last_my = -1, last_btn = 0;
        hal_pointer_event pending_pointer;
        bool have_pending_pointer = false, pointer_edge_waiting = false;
        uint64_t pointer_poll_sequence = machine.mouse_poll_sequence;

#ifndef XANTH_HEADLESS_STUB
        uint64_t perf_freq = SDL_GetPerformanceFrequency();
        uint64_t next_frame;
        if (perf_freq == 0) perf_freq = 1000000;
        next_frame = SDL_GetPerformanceCounter();
#endif

        while (running) {
            int mx = 0, my = 0, btn = 0, key = 0;
            uint16_t k;
            uint64_t target;

            if (max_frames && frame >= max_frames) break;

            /* ---- input ---- */
            hal_input_poll(&mx, &my, &btn, &key);
            switch (hal_input_take_hotkey()) {
            case 1: hal_video_toggle_fullscreen(); break;
            case 2: hal_video_toggle_crt(); break;
            case 3: hal_video_toggle_controller_help(); break;
            default: break;
            }
            if (key == 27) { running = false; break; }   /* Escape quits */

            /* Keep a quick press until the retail INT33 poll observes it.
             * Callback delivery alone cannot satisfy a game polling BX. */
            for (;;) {
                if (!have_pending_pointer)
                    have_pending_pointer = hal_input_take_pointer_event(&pending_pointer);
                if (!have_pending_pointer) break;
                hal_pointer_event pointer = pending_pointer;
                int changed = pointer.buttons ^ last_btn;
                if (pointer_edge_waiting && machine.mouse_poll_sequence == pointer_poll_sequence)
                    break;
                pointer_edge_waiting = false;
                have_pending_pointer = false;
                if (pointer.x != last_mx || pointer.y != last_my) {
                    vm_post_mouse_move(&machine, pointer.x, pointer.y);
                    last_mx = pointer.x; last_my = pointer.y;
                }
                for (int b = 0; b < 3; ++b)
                    if (changed & (1 << b))
                        vm_post_mouse_button(&machine, b, (pointer.buttons & (1 << b)) != 0);
                last_btn = pointer.buttons;
                if (changed) {
                    pointer_poll_sequence = machine.mouse_poll_sequence;
                    pointer_edge_waiting = true;
                    break;
                }
            }

            while (hal_keyboard_peek(&k)) {
                k = hal_keyboard_read();
                vm_post_key(&machine, (uint8_t)(k >> 8), (uint8_t)(k & 0xFF));
            }

            /* ---- run one frame of guest time ---- */
            target = machine.cpu.cycles + cycles_per_frame;
            while (machine.cpu.cycles < target) {
                /* The budget is in instructions; the coarse cost model charges
                 * four cycles each, and a blocked read jumps to the next tick,
                 * so this converges quickly whether the guest is busy or idle. */
                if (!vm_run(&machine, (target - machine.cpu.cycles) / 4 + 1)) {
                    running = false;
                    break;
                }
                if (machine.waiting_for_input) break;
            }

            /* ---- present ---- */
            hal_audio_tick();
            hal_video_set_palette(machine.dac, 0, 256);
            hal_video_flip();
            frame++;

#ifndef XANTH_HEADLESS_STUB
            next_frame += (uint64_t)(perf_freq / TARGET_FPS);
            {
                uint64_t now = SDL_GetPerformanceCounter();
                if (now < next_frame) {
                    double ms = (double)(next_frame - now) * 1000.0 / (double)perf_freq;
                    if (ms > 1.0) SDL_Delay((Uint32)(ms - 0.5));
                } else {
                    next_frame = now;   /* fell behind: do not accumulate debt */
                }
            }
#endif
        }
    }

    if (shot_path[0]) {
        if (vm_save_bmp(&machine, shot_path))
            fprintf(stderr, "wrote %s\n", shot_path);
    }

    fprintf(stderr, "[native] set_int_and_zero hits: %llu\n",
            (unsigned long long)xanth_native_set_int_and_zero_hits());
    fprintf(stderr, "[native] set_far_ptr hits: %llu\n",
            (unsigned long long)xanth_native_set_far_ptr_hits());
    fprintf(stderr, "[native] exe_94712 hits: %llu\n",
            (unsigned long long)xanth_native_exe_94712_hits());
    fprintf(stderr, "[native] if0_helper_inc fast-return hits: %llu\n",
            (unsigned long long)xanth_native_if0_helper_inc_hits());
    fprintf(stderr, "[native] exe_14360 hits: %llu\n",
            (unsigned long long)xanth_native_exe_14360_hits());
    fprintf(stderr, "[native] set_far_arr hits: %llu\n",
            (unsigned long long)xanth_native_set_far_arr_hits());
    fprintf(stderr, "[native] get_far_idx hits: %llu\n",
            (unsigned long long)xanth_native_get_far_idx_hits());
    fprintf(stderr, "[native] exe_37625 hits: %llu\n",
            (unsigned long long)xanth_native_exe_37625_hits());
    fprintf(stderr, "[native] exe_99679 hits: %llu\n",
            (unsigned long long)xanth_native_exe_99679_hits());
    fprintf(stderr, "[native] exe_86810 hits: %llu\n",
            (unsigned long long)xanth_native_exe_86810_hits());
    fprintf(stderr, "[native] exe_84866 hits: %llu\n",
            (unsigned long long)xanth_native_exe_84866_hits());
    fprintf(stderr, "[native] set_int_pair A hits: %llu\n",
            (unsigned long long)xanth_native_set_int_pair_a_hits());
    fprintf(stderr, "[native] set_int_pair B hits: %llu\n",
            (unsigned long long)xanth_native_set_int_pair_b_hits());
    fprintf(stderr, "[native] set_int A hits: %llu\n",
            (unsigned long long)xanth_native_set_int_a_hits());
    fprintf(stderr, "[native] set_int B hits: %llu\n",
            (unsigned long long)xanth_native_set_int_b_hits());
    fprintf(stderr, "[native] clear_byte hits: %llu\n",
            (unsigned long long)xanth_native_clear_byte_hits());
    fprintf(stderr, "[native] swap_int hits: %llu\n",
            (unsigned long long)xanth_native_swap_int_hits());
    fprintf(stderr, "[native] exe_115346 hits: %llu\n",
            (unsigned long long)xanth_native_exe_115346_hits());
    fprintf(stderr, "[native] arr_set_one hits: %llu\n",
            (unsigned long long)xanth_native_arr_set_one_hits());
    fprintf(stderr, "[native] exe_114942 hits: %llu\n",
            (unsigned long long)xanth_native_exe_114942_hits());
    fprintf(stderr, "[native] exe_114942 negative hits: %llu\n",
            (unsigned long long)xanth_native_exe_114942_negative_hits());
    fprintf(stderr, "[native] store_two_globals hits: %llu\n",
            (unsigned long long)xanth_native_store_two_globals_hits());
    fprintf(stderr, "[native] set_int_if_ge0 hits: %llu\n",
            (unsigned long long)xanth_native_set_int_if_ge0_hits());
    fprintf(stderr, "[native] iabs hits: %llu\n",
            (unsigned long long)xanth_native_iabs_hits());
    fprintf(stderr, "[native] set_far_arr_chk hits: %llu\n",
            (unsigned long long)xanth_native_set_far_arr_chk_hits());
    fprintf(stderr, "[native] set_byte_one hits: %llu\n",
            (unsigned long long)xanth_native_set_byte_one_hits());
    fprintf(stderr, "[native] exe_136552 hits: %llu\n",
            (unsigned long long)xanth_native_exe_136552_hits());
    fprintf(stderr, "[native] exe_52710 hits: %llu\n",
            (unsigned long long)xanth_native_exe_52710_hits());
    fprintf(stderr, "[native] exe_112795 hits: %llu\n",
            (unsigned long long)xanth_native_exe_112795_hits());
    fprintf(stderr, "[native] exe_52674 hits: %llu\n",
            (unsigned long long)xanth_native_exe_52674_hits());
    fprintf(stderr, "[native] exe_112711 hits: %llu\n",
            (unsigned long long)xanth_native_exe_112711_hits());
    fprintf(stderr, "[native] exe_34775 hits: %llu\n",
            (unsigned long long)xanth_native_exe_34775_hits());
    fprintf(stderr, "[native] add_mod hits: %llu\n",
            (unsigned long long)xanth_native_add_mod_hits());
    fprintf(stderr, "[native] set_fields hits: %llu\n",
            (unsigned long long)xanth_native_set_fields_hits());
    fprintf(stderr, "[native] exe_112853 hits: %llu\n",
            (unsigned long long)xanth_native_exe_112853_hits());
    fprintf(stderr, "[native] exe_100016 fast-return hits: %llu\n",
            (unsigned long long)xanth_native_exe_100016_fast_hits());
    fprintf(stderr, "[native] exe_103774 negative hits: %llu\n",
            (unsigned long long)xanth_native_exe_103774_negative_hits());
    fprintf(stderr, "[native] exe_100203 prefix hits: %llu\n",
            (unsigned long long)xanth_native_exe_100203_prefix_hits());
    fprintf(stderr, "[native] exe_103744 hits: %llu\n",
            (unsigned long long)xanth_native_exe_103744_hits());
    vm_report(&machine, stderr);
    vm_shutdown(&machine);
    hal_audio_shutdown();
    hal_input_shutdown();
    hal_video_shutdown();
    return (machine.cpu.fault && machine.cpu.fault != CPU_FAULT_EXITED) ? 3 : 0;
}
