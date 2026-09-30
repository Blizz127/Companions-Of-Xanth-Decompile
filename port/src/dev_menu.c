/*
 * dev_menu.c — opt-in playtest menu (shared port dev-menu spec v1).
 *
 * Everything here is host-side.  The menu reads SDL input ahead of the game,
 * draws onto the presented RGBA copy of the frame, and drives host services
 * (fast-forward pacing, screenshots, window options).  It has no access to
 * guest memory: game-state actions (warps, area finishes, cheats) are added
 * only once the safe-state predicate and each entry have been recovered from
 * the game's own code and verified by a live sweep.  Until then those pages
 * list no selectable rows and their shortcut keys report a refusal.
 *
 * Input rules (spec §3):
 *   - while open, the menu consumes keyboard, mouse buttons and pad buttons;
 *   - an "up" is consumed exactly when its "down" was consumed, so input the
 *     game already saw is never left stuck;
 *   - after closing, buttons held from the menu must be released before new
 *     gameplay input passes (neutral drain);
 *   - Back and Start are reserved from the moment either is pressed; a lone
 *     press is replayed to the game on release, a same-pad chord toggles the
 *     menu;
 *   - no auto-repeat: one row per key press or stick deflection.
 */
#include "dev_menu.h"
#include "dev_menu_font.h"
#include "dev_warp.h"
#include "port_hal.h"

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#if defined(_WIN32)
#include <direct.h>
#include <io.h>
#include <sys/stat.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
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

#if defined(__GNUC__) || defined(__clang__)
#define DM_PRINTF(f, a) __attribute__((format(printf, f, a)))
#else
#define DM_PRINTF(f, a)
#endif
#if defined(_WIN32)
#define strtok_r strtok_s
#endif

#define DM_LOG(...) do { fprintf(stderr, "[DEV_MENU] " __VA_ARGS__); fputc('\n', stderr); } while (0)

#define LAYER_W 320                 /* overlay layer, the mode-13h frame */
#define LAYER_H 200
#define DM_STICK_THRESHOLD 12000     /* PE's value on SDL's +/-32767 range */
#define DM_TOAST_FRAMES    210       /* three seconds at 70 Hz */
#define DM_MAX_ROWS        32
#define DM_MAX_PADS        16
#define DM_MAX_SCRIPT      256
#define DM_REPLAY_TAG1     0xD7      /* marks a replayed Back/Start press */
#define DM_REPLAY_TAG2     0x4D

typedef enum {
    PAGE_ROOT = 0, PAGE_WARP, PAGE_FINISH, PAGE_CHEATS, PAGE_OPTIONS, PAGE_HELP,
    PAGE_WARP_AREAS, PAGE_WARP_SPOTS, PAGE_COUNT
} dm_page;

typedef enum { ROW_INFO = 0, ROW_PAGE, ROW_ACTION } dm_row_kind;

typedef enum {
    ACT_FF_TOGGLE = 0, ACT_FF_SPEED, ACT_SCREENSHOT, ACT_FULLSCREEN, ACT_SCANLINES, ACT_HELP,
    ACT_WARP, ACT_FINISH
} dm_action;

typedef struct {
    dm_row_kind kind;
    int target;
    int param;              /* warp entry index for warp rows */
    char label[52];
} dm_row;

typedef enum { SCRIPT_INPUT = 0, SCRIPT_GAME_KEY, SCRIPT_WARP } dm_script_kind;

typedef struct {
    long long frame;
    dm_script_kind kind;
    dev_menu_input in;
    uint8_t scan, ascii;    /* SCRIPT_GAME_KEY */
    char id[32];            /* SCRIPT_WARP */
} dm_script_entry;

#ifndef XANTH_HEADLESS_STUB
typedef struct {
    bool used;
    SDL_JoystickID id;
    SDL_GameController *controller;   /* our own handle; NULL until reconciled */
    unsigned held;                    /* buttons down, from events */
    unsigned consumed;                /* downs we swallowed; their ups are ours */
    unsigned drain;                   /* held from the menu at close */
    unsigned reserved;                /* Back/Start held and not yet resolved */
    bool combo_fired;
    bool combo_touched;               /* the other combo button was pressed too */
    bool needs_neutral;               /* connected with buttons held */
    int stick_dir;
} dm_pad;
#endif

static const int s_ff_factors[4] = { 2, 4, 8, 8 };
static const char *const s_ff_names[4] = { "2x", "4x", "8x", "max" };

static struct {
    bool resolved, enabled, started;
    dev_menu_host host;

    bool open;
    dm_page page;
    dm_page help_return;
    bool help_opened_menu;
    int cursor[PAGE_COUNT];
    dm_row rows[DM_MAX_ROWS];
    int nrows;

    bool ff_on, ff_hold;
    int ff_speed;

    bool shot_pending;
    int shot_counter;

    bool cheats_used;
    time_t dev_used_since;          /* first warp this session; 0 if none */
    bool save_warned;
    int save_scan_frames;
    char warp_region[32], warp_area[48];
    int action_param;
    char toast[96];
    int toast_frames;

    dm_script_entry script[DM_MAX_SCRIPT];
    int nscript, script_next;

#ifndef XANTH_HEADLESS_STUB
    bool controllers_ready;
    bool rescan_pads;
    dm_pad pads[DM_MAX_PADS];
    bool kb_consumed[SDL_NUM_SCANCODES];
    bool kb_drain[SDL_NUM_SCANCODES];
    int kb_drain_count;
    unsigned mouse_consumed, mouse_drain;
#endif
} s_dm;

/* ------------------------------------------------------------------------
 * Opt-in resolution
 * ------------------------------------------------------------------------ */

static bool text_true(const char *v) {
    return v && (!strcmp(v, "1") || !strcmp(v, "true") || !strcmp(v, "yes") || !strcmp(v, "on"));
}

static bool text_false(const char *v) {
    return v && (!strcmp(v, "0") || !strcmp(v, "false") || !strcmp(v, "no") || !strcmp(v, "off"));
}

static bool config_dev_menu(const char *path) {
    FILE *f;
    char line[512];
    bool on = false;
    if (!path || !*path || !(f = fopen(path, "r"))) return false;
    while (fgets(line, sizeof(line), f)) {
        char *key = line, *eq, *value, *end;
        while (isspace((unsigned char)*key)) ++key;
        if (!*key || *key == '#' || *key == ';' || !(eq = strchr(key, '='))) continue;
        *eq = '\0';
        value = eq + 1;
        key[strcspn(key, " \t\r\n")] = '\0';
        value[strcspn(value, "\r\n")] = '\0';
        while (isspace((unsigned char)*value)) ++value;
        end = value + strlen(value);
        while (end > value && isspace((unsigned char)end[-1])) *--end = '\0';
        if (!strcmp(key, "dev_menu")) on = text_true(value);
    }
    fclose(f);
    return on;
}

bool dev_menu_resolve(bool cli_opt_in, const char *config_path) {
    const char *env = getenv("XANTH_DEV_MENU");
    const char *cheats = getenv("XANTH_CHEATS");
    bool requested = cli_opt_in || config_dev_menu(config_path) || text_true(env);
    if (text_false(env)) requested = false;
    s_dm.resolved = true;
    s_dm.enabled = requested && !text_false(cheats);
    if (requested && !s_dm.enabled)
        DM_LOG("hard-disabled by XANTH_CHEATS=%s", cheats);
    else if (s_dm.enabled)
        DM_LOG("enabled: F12 or Back+Start (same pad) opens the menu");
    return s_dm.enabled;
}

bool dev_menu_enabled(void) { return s_dm.enabled; }

/* ------------------------------------------------------------------------
 * Menu model
 * ------------------------------------------------------------------------ */

static void add_row(dm_row_kind kind, int target, const char *fmt, ...) DM_PRINTF(3, 4);
static int s_row_param;   /* param for the next add_row */

static void add_row(dm_row_kind kind, int target, const char *fmt, ...) {
    va_list ap;
    if (s_dm.nrows >= DM_MAX_ROWS) return;
    s_dm.rows[s_dm.nrows].kind = kind;
    s_dm.rows[s_dm.nrows].target = target;
    s_dm.rows[s_dm.nrows].param = s_row_param;
    va_start(ap, fmt);
    vsnprintf(s_dm.rows[s_dm.nrows].label, sizeof(s_dm.rows[0].label), fmt, ap);
    va_end(ap);
    s_dm.nrows++;
}

static bool scanlines_on(void) {
    return s_dm.host.scanlines_enabled && s_dm.host.scanlines_enabled();
}

static void build_rows(void) {
    s_dm.nrows = 0;
    s_row_param = 0;
    switch (s_dm.page) {
    case PAGE_ROOT:
        add_row(ROW_PAGE, PAGE_WARP, "Warp >");
        add_row(ROW_PAGE, PAGE_FINISH, "Finish Area >");
        add_row(ROW_PAGE, PAGE_CHEATS, "Cheats >");
        add_row(ROW_PAGE, PAGE_OPTIONS, "Options >");
        break;
    case PAGE_WARP: {
        int idx[DEV_WARP_MAX], n = dev_warp_regions(idx, DEV_WARP_MAX);
        if (!n) add_row(ROW_INFO, 0, "No verified checkpoints yet.");
        for (int i = 0; i < n; ++i) {
            s_row_param = idx[i];
            add_row(ROW_PAGE, PAGE_WARP_AREAS, "%s >", dev_warp_get(idx[i])->region);
        }
        break;
    }
    case PAGE_WARP_AREAS: {
        int idx[DEV_WARP_MAX], n = dev_warp_areas(s_dm.warp_region, idx, DEV_WARP_MAX);
        for (int i = 0; i < n; ++i) {
            s_row_param = idx[i];
            add_row(ROW_PAGE, PAGE_WARP_SPOTS, "%s >", dev_warp_get(idx[i])->area);
        }
        break;
    }
    case PAGE_WARP_SPOTS: {
        int idx[DEV_WARP_MAX], n = dev_warp_spots(s_dm.warp_region, s_dm.warp_area, idx, DEV_WARP_MAX);
        for (int i = 0; i < n; ++i) {
            s_row_param = idx[i];
            add_row(ROW_ACTION, ACT_WARP, "%s", dev_warp_get(idx[i])->spot);
        }
        break;
    }
    case PAGE_FINISH: {
        int room = -1, score = -1, items = -1, cur = -1, shown = 0;
        bool known = s_dm.host.read_progress && s_dm.host.read_progress(&room, &score, &items);
        if (known) cur = dev_warp_current_step(room, score, items);
        if (cur >= 0) {
            const dev_warp_entry *e = dev_warp_get(cur);
            s_row_param = cur;
            add_row(ROW_ACTION, ACT_FINISH, "Finish Current Step: %s", e->step_name);
            shown++;
            int end = dev_warp_area_end(e->region, e->area);
            if (end >= 0 && end != cur) {
                s_row_param = end;
                add_row(ROW_ACTION, ACT_FINISH, "Complete %s", e->area);
                shown++;
            }
        }
        if (!shown) {
            bool any = false;
            for (int i = 0; i < dev_warp_count(); ++i) any |= dev_warp_get(i)->step > 0;
            add_row(ROW_INFO, 0, any ? (known ? "This point is not on a verified step."
                                              : "Game progress not readable yet.")
                                     : "No verified story steps yet.");
        }
        break;
    }
    case PAGE_CHEATS:
        add_row(ROW_INFO, 0, "No verified cheats yet.");
        break;
    case PAGE_OPTIONS:
        add_row(ROW_ACTION, ACT_FF_TOGGLE, "Fast-forward: %s", s_dm.ff_on ? "ON" : "OFF");
        add_row(ROW_ACTION, ACT_FF_SPEED, "Fast-forward speed: %s", s_ff_names[s_dm.ff_speed]);
        add_row(ROW_ACTION, ACT_SCREENSHOT, "Screenshot");
        if (s_dm.host.toggle_fullscreen)
            add_row(ROW_ACTION, ACT_FULLSCREEN, "Toggle fullscreen");
        if (s_dm.host.toggle_scanlines)
            add_row(ROW_ACTION, ACT_SCANLINES, "CRT scanlines: %s", scanlines_on() ? "ON" : "OFF");
        add_row(ROW_ACTION, ACT_HELP, "Help (controls)");
        break;
    case PAGE_HELP:
        add_row(ROW_INFO, 0, "Back+Start (one pad) / F12  open, close");
        add_row(ROW_INFO, 0, "Up/Down, D-pad, stick  move");
        add_row(ROW_INFO, 0, "Enter / A  select    Esc / B  back");
        add_row(ROW_INFO, 0, "L3  fast-forward on/off");
        add_row(ROW_INFO, 0, "R3  hold to fast-forward");
        add_row(ROW_INFO, 0, "Speed and screenshots: Options page.");
        add_row(ROW_INFO, 0, "F1-F10 and Backspace stay with the game.");
        add_row(ROW_INFO, 0, "The game keeps running while the");
        add_row(ROW_INFO, 0, "menu is open.");
        break;
    default:
        break;
    }
}

static bool row_selectable(int i) {
    return i >= 0 && i < s_dm.nrows && s_dm.rows[i].kind != ROW_INFO;
}

static void fix_cursor(void) {
    int *c = &s_dm.cursor[s_dm.page];
    if (row_selectable(*c)) return;
    for (int i = 0; i < s_dm.nrows; ++i)
        if (row_selectable(i)) { *c = i; return; }
    *c = -1;
}

static void enter_page(dm_page page) {
    s_dm.page = page;
    build_rows();
    fix_cursor();
}

static void refresh_rows(void) {
    if (!s_dm.open) return;
    build_rows();
    fix_cursor();
}

static void toast(const char *fmt, ...) DM_PRINTF(1, 2);
static void toast(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(s_dm.toast, sizeof(s_dm.toast), fmt, ap);
    va_end(ap);
    s_dm.toast_frames = DM_TOAST_FRAMES;
    DM_LOG("%s", s_dm.toast);
}

static void set_drains(void);
static void update_pad_mask(void);

static void open_menu(dm_page page) {
    s_dm.open = true;
    DM_LOG("open");
    enter_page(page);
}

static void close_menu(void) {
    if (!s_dm.open) return;
    s_dm.open = false;
    s_dm.help_opened_menu = false;
    DM_LOG("close");
    set_drains();
}

static void move_cursor(int dir) {
    int *c = &s_dm.cursor[s_dm.page];
    if (*c < 0 || s_dm.nrows <= 0) return;
    for (int step = 1; step <= s_dm.nrows; ++step) {
        int i = ((*c + dir * step) % s_dm.nrows + s_dm.nrows) % s_dm.nrows;
        if (row_selectable(i)) { *c = i; return; }
    }
}

static void ensure_shot_dir(const char *dir) {
    if (!dir || !*dir) return;
#if defined(_WIN32)
    if (_mkdir(dir) != 0 && errno != EEXIST)
#else
    if (mkdir(dir, 0755) != 0 && errno != EEXIST)
#endif
        DM_LOG("cannot create screenshot directory %s: %s", dir, strerror(errno));
}

static void run_action(dm_action act) {
    switch (act) {
    case ACT_FF_TOGGLE:  dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE); break;
    case ACT_FF_SPEED:   dev_menu_input_event(DEV_MENU_IN_FF_SPEED); break;
    case ACT_SCREENSHOT: dev_menu_input_event(DEV_MENU_IN_SCREENSHOT); break;
    case ACT_FULLSCREEN:
        if (s_dm.host.toggle_fullscreen) s_dm.host.toggle_fullscreen();
        toast("Fullscreen toggled");
        break;
    case ACT_SCANLINES:
        if (s_dm.host.toggle_scanlines) s_dm.host.toggle_scanlines();
        toast("CRT scanlines %s", scanlines_on() ? "ON" : "OFF");
        break;
    case ACT_HELP:
        s_dm.help_return = s_dm.page;
        enter_page(PAGE_HELP);
        return;
    case ACT_WARP: {
        char msg[128];
        if (dev_warp_request(s_dm.action_param, msg, sizeof(msg))) close_menu();
        toast("%s", msg);
        return;
    }
    case ACT_FINISH: {
        char msg[128];
        const dev_warp_entry *e = dev_warp_get(s_dm.action_param);
        if (e && dev_warp_request(s_dm.action_param, msg, sizeof(msg))) {
            int next = dev_warp_step(e->step + 1);
            close_menu();
            DM_LOG("finish step %d (%s) via %s; next: %s", e->step, e->step_name, e->id,
                   next >= 0 ? dev_warp_get(next)->step_name : "(none recorded)");
            toast("Finishing: %s. Next: %s", e->step_name,
                  next >= 0 ? dev_warp_get(next)->step_name : "(none recorded)");
        } else {
            toast("%s", e ? msg : "Step unavailable");
        }
        return;
    }
    }
    refresh_rows();
}

static void refuse(const char *what, const char *why) {
    toast("%s: not available (%s)", what, why);
}

void dev_menu_input_event(dev_menu_input in) {
    if (!s_dm.enabled) return;
    switch (in) {
    case DEV_MENU_IN_TOGGLE:
        if (s_dm.open) close_menu();
        else open_menu(PAGE_ROOT);
        break;
    case DEV_MENU_IN_UP:
        if (s_dm.open) move_cursor(-1);
        break;
    case DEV_MENU_IN_DOWN:
        if (s_dm.open) move_cursor(1);
        break;
    case DEV_MENU_IN_CONFIRM: {
        int c;
        if (!s_dm.open) break;
        c = s_dm.cursor[s_dm.page];
        if (!row_selectable(c)) break;
        if (s_dm.rows[c].kind == ROW_PAGE) {
            const dev_warp_entry *e = dev_warp_get(s_dm.rows[c].param);
            if (s_dm.rows[c].target == PAGE_WARP_AREAS && e) {
                snprintf(s_dm.warp_region, sizeof(s_dm.warp_region), "%s", e->region);
                s_dm.cursor[PAGE_WARP_AREAS] = 0;
            } else if (s_dm.rows[c].target == PAGE_WARP_SPOTS && e) {
                snprintf(s_dm.warp_area, sizeof(s_dm.warp_area), "%s", e->area);
                s_dm.cursor[PAGE_WARP_SPOTS] = 0;
            }
            enter_page((dm_page)s_dm.rows[c].target);
        } else {
            s_dm.action_param = s_dm.rows[c].param;
            run_action((dm_action)s_dm.rows[c].target);
        }
        break;
    }
    case DEV_MENU_IN_BACK:
        if (!s_dm.open) break;
        if (s_dm.page == PAGE_HELP) {
            if (s_dm.help_opened_menu) close_menu();
            else enter_page(s_dm.help_return);
        } else if (s_dm.page == PAGE_ROOT) {
            close_menu();
        } else if (s_dm.page == PAGE_WARP_SPOTS) {
            enter_page(PAGE_WARP_AREAS);
        } else if (s_dm.page == PAGE_WARP_AREAS) {
            enter_page(PAGE_WARP);
        } else {
            enter_page(PAGE_ROOT);
        }
        break;
    case DEV_MENU_IN_HELP:
        if (!s_dm.open) {
            open_menu(PAGE_HELP);
            s_dm.help_opened_menu = true;
        } else if (s_dm.page == PAGE_HELP) {
            dev_menu_input_event(DEV_MENU_IN_BACK);
        } else {
            s_dm.help_return = s_dm.page;
            enter_page(PAGE_HELP);
        }
        break;
    case DEV_MENU_IN_GOD:
        refuse("God mode", "no verified game-state source");
        break;
    case DEV_MENU_IN_RESOURCE:
        refuse("Resource max", "no verified game-state source");
        break;
    case DEV_MENU_IN_INSTANT_WIN:
        refuse("Instant win", "no verified game-state source");
        break;
    case DEV_MENU_IN_KEY_ITEMS:
        refuse("Area key items", "no verified game-state source");
        break;
    case DEV_MENU_IN_FF_TOGGLE:
        s_dm.ff_on = !s_dm.ff_on;
        toast("Fast-forward %s (%s)", s_dm.ff_on ? "ON" : "OFF", s_ff_names[s_dm.ff_speed]);
        refresh_rows();
        break;
    case DEV_MENU_IN_FF_HOLD_ON:
        if (!s_dm.ff_hold) DM_LOG("fast-forward hold on (%s)", s_ff_names[s_dm.ff_speed]);
        s_dm.ff_hold = true;
        break;
    case DEV_MENU_IN_FF_HOLD_OFF:
        if (s_dm.ff_hold) DM_LOG("fast-forward hold off");
        s_dm.ff_hold = false;
        break;
    case DEV_MENU_IN_FF_SPEED:
        s_dm.ff_speed = (s_dm.ff_speed + 1) % 4;
        toast("Fast-forward speed %s", s_ff_names[s_dm.ff_speed]);
        refresh_rows();
        break;
    case DEV_MENU_IN_FF_SPEED_RESET:
        s_dm.ff_speed = 0;
        toast("Fast-forward speed %s", s_ff_names[s_dm.ff_speed]);
        refresh_rows();
        break;
    case DEV_MENU_IN_RECORD:
        refuse("Record video", "not in this build");
        break;
    case DEV_MENU_IN_SCREENSHOT:
        s_dm.shot_pending = true;
        break;
    case DEV_MENU_IN_QUICK_SAVE:
        refuse("Quick save", "needs the verified field-state check");
        break;
    case DEV_MENU_IN_QUICK_LOAD:
        refuse("Quick load", "needs the verified field-state check");
        break;
    default:
        break;
    }
}

/* ------------------------------------------------------------------------
 * Harness key script: XANTH_DEV_KEYS="frame:KEY,frame:KEY,..."
 * ------------------------------------------------------------------------ */

static bool script_key(const char *name, dev_menu_input *out) {
    static const struct { const char *name; dev_menu_input in; } map[] = {
        {"OPEN", DEV_MENU_IN_TOGGLE}, {"COMBO", DEV_MENU_IN_TOGGLE},
        {"UP", DEV_MENU_IN_UP}, {"DOWN", DEV_MENU_IN_DOWN},
        {"ENTER", DEV_MENU_IN_CONFIRM}, {"A", DEV_MENU_IN_CONFIRM},
        {"ESC", DEV_MENU_IN_BACK}, {"B", DEV_MENU_IN_BACK},
        {"HELP", DEV_MENU_IN_HELP}, {"GOD", DEV_MENU_IN_GOD},
        {"RESOURCE", DEV_MENU_IN_RESOURCE}, {"WIN", DEV_MENU_IN_INSTANT_WIN},
        {"KEY_ITEMS", DEV_MENU_IN_KEY_ITEMS}, {"FF", DEV_MENU_IN_FF_TOGGLE},
        {"L3", DEV_MENU_IN_FF_TOGGLE}, {"R3_DOWN", DEV_MENU_IN_FF_HOLD_ON},
        {"R3_UP", DEV_MENU_IN_FF_HOLD_OFF}, {"FF_SPEED", DEV_MENU_IN_FF_SPEED},
        {"FF_SPEED_RESET", DEV_MENU_IN_FF_SPEED_RESET}, {"RECORD", DEV_MENU_IN_RECORD},
        {"SHOT", DEV_MENU_IN_SCREENSHOT}, {"QUICK_SAVE", DEV_MENU_IN_QUICK_SAVE},
        {"QUICK_LOAD", DEV_MENU_IN_QUICK_LOAD},
    };
    for (size_t i = 0; i < sizeof(map) / sizeof(map[0]); ++i)
        if (!strcmp(name, map[i].name)) { *out = map[i].in; return true; }
    return false;
}

static void load_script(void) {
    const char *spec = getenv("XANTH_DEV_KEYS");
    char buf[4096], *tok, *save = NULL;
    s_dm.nscript = s_dm.script_next = 0;
    if (!spec || !*spec) return;
    snprintf(buf, sizeof(buf), "%s", spec);
    for (tok = strtok_r(buf, ",", &save); tok; tok = strtok_r(NULL, ",", &save)) {
        char *colon = strchr(tok, ':');
        dev_menu_input in;
        if (!colon || s_dm.nscript >= DM_MAX_SCRIPT) continue;
        *colon = '\0';
        dm_script_entry *se = &s_dm.script[s_dm.nscript];
        memset(se, 0, sizeof(*se));
        se->frame = atoll(tok);
        if (!strcmp(colon + 1, "FINISH_STEP")) {
            se->kind = SCRIPT_WARP;
            snprintf(se->id, sizeof(se->id), "%s", "@finish");
        } else if (!strncmp(colon + 1, "WARP:", 5)) {
            se->kind = SCRIPT_WARP;
            snprintf(se->id, sizeof(se->id), "%s", colon + 6);
        } else if (!strcmp(colon + 1, "GAME_SPACE")) {
            se->kind = SCRIPT_GAME_KEY; se->scan = 0x39; se->ascii = ' ';
        } else if (!strcmp(colon + 1, "GAME_ENTER")) {
            se->kind = SCRIPT_GAME_KEY; se->scan = 0x1C; se->ascii = 0x0D;
        } else if (!strcmp(colon + 1, "GAME_ESC")) {
            se->kind = SCRIPT_GAME_KEY; se->scan = 0x01; se->ascii = 0x1B;
        } else if (script_key(colon + 1, &in)) {
            se->kind = SCRIPT_INPUT;
            se->in = in;
        } else {
            DM_LOG("ignoring unknown scripted key %s", colon + 1);
            continue;
        }
        s_dm.nscript++;
    }
    DM_LOG("harness key script: %d entries", s_dm.nscript);
}

/* ------------------------------------------------------------------------
 * SDL input adapter
 * ------------------------------------------------------------------------ */

#ifndef XANTH_HEADLESS_STUB

static SDL_Texture *s_layer_tex;          /* dev_menu_render's upload target */
static SDL_Renderer *s_layer_renderer;

#define PAD_BIT(b) (1u << (unsigned)(b))
#define COMBO_BITS (PAD_BIT(SDL_CONTROLLER_BUTTON_BACK) | PAD_BIT(SDL_CONTROLLER_BUTTON_START))

static dm_pad *find_pad(SDL_JoystickID id, bool create) {
    dm_pad *free_slot = NULL;
    for (int i = 0; i < DM_MAX_PADS; ++i) {
        if (s_dm.pads[i].used && s_dm.pads[i].id == id) return &s_dm.pads[i];
        if (!s_dm.pads[i].used && !free_slot) free_slot = &s_dm.pads[i];
    }
    if (!create || !free_slot) return NULL;
    memset(free_slot, 0, sizeof(*free_slot));
    free_slot->used = true;
    free_slot->id = id;
    return free_slot;
}

/* Everything the menu swallowed and is still held must be released before
 * gameplay input passes again.  A consumed press stays marked until its
 * release, so "consumed" is exactly "held from the menu". */
static void set_drains(void) {
    for (int i = 0; i < DM_MAX_PADS; ++i) {
        dm_pad *p = &s_dm.pads[i];
        if (!p->used) continue;
        p->drain = p->consumed;
        p->stick_dir = 0;
    }
    s_dm.kb_drain_count = 0;
    for (int sc = 0; sc < SDL_NUM_SCANCODES; ++sc) {
        s_dm.kb_drain[sc] = s_dm.kb_consumed[sc];
        if (s_dm.kb_drain[sc]) s_dm.kb_drain_count++;
    }
    s_dm.mouse_drain = s_dm.mouse_consumed;
}

static void replay_button(SDL_JoystickID id, Uint8 button) {
    SDL_Event ev;
    memset(&ev, 0, sizeof(ev));
    ev.cbutton.which = id;
    ev.cbutton.button = button;
    ev.cbutton.padding1 = DM_REPLAY_TAG1;
    ev.cbutton.padding2 = DM_REPLAY_TAG2;
    ev.type = SDL_CONTROLLERBUTTONDOWN;
    ev.cbutton.state = SDL_PRESSED;
    SDL_PushEvent(&ev);
    ev.type = SDL_CONTROLLERBUTTONUP;
    ev.cbutton.state = SDL_RELEASED;
    SDL_PushEvent(&ev);
}

static bool filter_pad_button(const SDL_ControllerButtonEvent *e, bool down) {
    dm_pad *p;
    unsigned bit;
    if (e->padding1 == DM_REPLAY_TAG1 && e->padding2 == DM_REPLAY_TAG2) return false;
    if (e->button >= SDL_CONTROLLER_BUTTON_MAX) return false;
    p = find_pad(e->which, true);
    if (!p) return false;
    bit = PAD_BIT(e->button);
    if (down) p->held |= bit;
    else p->held &= ~bit;

    if (p->needs_neutral) {
        if (down) p->consumed |= bit;
        else p->consumed &= ~bit;
        if (!p->held) {
            p->needs_neutral = false;
            DM_LOG("pad %d neutral", (int)p->id);
        }
        return true;
    }
    if (!down && (p->consumed & bit)) {
        p->consumed &= ~bit;
        p->drain &= ~bit;
        if (e->button == SDL_CONTROLLER_BUTTON_RIGHTSTICK)
            dev_menu_input_event(DEV_MENU_IN_FF_HOLD_OFF);
        if (bit & COMBO_BITS) {
            bool lone = (p->reserved & bit) && !p->combo_fired && !p->combo_touched;
            p->reserved &= ~bit;
            if (lone && !s_dm.open) replay_button(e->which, e->button);
            if (!(p->held & COMBO_BITS)) p->combo_fired = p->combo_touched = false;
        }
        return true;
    }
    if (!down) return false;   /* the game saw this press, so it gets the release */

    if (bit & COMBO_BITS) {
        unsigned other = COMBO_BITS & ~bit;
        p->consumed |= bit;
        p->reserved |= bit;
        if (p->held & other) {
            p->combo_touched = true;
            if (!p->combo_fired) {
                p->combo_fired = true;
                dev_menu_input_event(DEV_MENU_IN_TOGGLE);
            }
        }
        return true;
    }
    if (p->drain && !s_dm.open) {   /* still releasing buttons held from the menu */
        p->consumed |= bit;
        return true;
    }
    if (s_dm.open) {
        p->consumed |= bit;
        switch (e->button) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP:    dev_menu_input_event(DEV_MENU_IN_UP); break;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:  dev_menu_input_event(DEV_MENU_IN_DOWN); break;
        case SDL_CONTROLLER_BUTTON_A:          dev_menu_input_event(DEV_MENU_IN_CONFIRM); break;
        case SDL_CONTROLLER_BUTTON_B:          dev_menu_input_event(DEV_MENU_IN_BACK); break;
        case SDL_CONTROLLER_BUTTON_LEFTSTICK:  dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE); break;
        case SDL_CONTROLLER_BUTTON_RIGHTSTICK: dev_menu_input_event(DEV_MENU_IN_FF_HOLD_ON); break;
        default: break;
        }
        return true;
    }
    if (e->button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
        p->consumed |= bit;
        dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE);
        return true;
    }
    if (e->button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
        p->consumed |= bit;
        dev_menu_input_event(DEV_MENU_IN_FF_HOLD_ON);
        return true;
    }
    return false;
}

static bool filter_pad_axis(const SDL_ControllerAxisEvent *e) {
    dm_pad *p = find_pad(e->which, true);
    int dir;
    if (!s_dm.open || !p) return false;
    if (p->needs_neutral) return true;
    if (e->axis == SDL_CONTROLLER_AXIS_LEFTY) {
        dir = e->value > DM_STICK_THRESHOLD ? 1 : (e->value < -DM_STICK_THRESHOLD ? -1 : 0);
        if (dir && dir != p->stick_dir)
            dev_menu_input_event(dir > 0 ? DEV_MENU_IN_DOWN : DEV_MENU_IN_UP);
        p->stick_dir = dir;
    }
    return true;
}

/* Xanth exception to the shared key map (spec section 0): retail reads the
 * function keys as game commands (F1 waits), so with the menu closed the
 * keyboard takes only a key the port never forwards to the guest.  The port's
 * BIOS translation stops at F10; F12 opens the menu.  Help, fast-forward
 * speed and screenshots live on the Options page instead of F-keys. */
#define DM_OPEN_KEY SDLK_F12

static bool host_key_input(SDL_Keycode sym, dev_menu_input *out) {
    if (sym != DM_OPEN_KEY) return false;
    *out = DEV_MENU_IN_TOGGLE;
    return true;
}

static bool filter_key(const SDL_KeyboardEvent *e, bool down) {
    SDL_Scancode sc = e->keysym.scancode;
    dev_menu_input in;
    if ((unsigned)sc >= SDL_NUM_SCANCODES) return false;
    if (!down) {
        if (!s_dm.kb_consumed[sc]) return false;
        s_dm.kb_consumed[sc] = false;
        if (s_dm.kb_drain[sc]) { s_dm.kb_drain[sc] = false; s_dm.kb_drain_count--; }
        return true;
    }
    if (e->repeat) {
        /* No auto-repeat; repeats of a key the game owns still reach it. */
        return s_dm.kb_consumed[sc] || s_dm.open;
    }
    if (host_key_input(e->keysym.sym, &in)) {
        s_dm.kb_consumed[sc] = true;
        dev_menu_input_event(in);
        return true;
    }
    if (s_dm.open) {
        s_dm.kb_consumed[sc] = true;
        switch (e->keysym.sym) {
        case SDLK_UP: case SDLK_KP_8:          dev_menu_input_event(DEV_MENU_IN_UP); break;
        case SDLK_DOWN: case SDLK_KP_2:        dev_menu_input_event(DEV_MENU_IN_DOWN); break;
        case SDLK_RETURN: case SDLK_KP_ENTER:  dev_menu_input_event(DEV_MENU_IN_CONFIRM); break;
        case SDLK_ESCAPE:                      dev_menu_input_event(DEV_MENU_IN_BACK); break;
        default: break;
        }
        return true;
    }
    if (s_dm.kb_drain_count > 0) {
        s_dm.kb_consumed[sc] = true;
        return true;
    }
    return false;
}

static bool filter_mouse_button(const SDL_MouseButtonEvent *e, bool down) {
    unsigned bit = SDL_BUTTON(e->button);
    if (!down) {
        if (!(s_dm.mouse_consumed & bit)) return false;
        s_dm.mouse_consumed &= ~bit;
        s_dm.mouse_drain &= ~bit;
        return true;
    }
    if (s_dm.open || s_dm.mouse_drain) {
        s_dm.mouse_consumed |= bit;
        return true;
    }
    return false;
}

static bool filter_event(const SDL_Event *event);

bool dev_menu_filter_event(const SDL_Event *event, void *user) {
    bool consumed;
    (void)user;
    if (!s_dm.enabled || !event) return false;
    consumed = filter_event(event);
    update_pad_mask();
    return consumed;
}

static bool filter_event(const SDL_Event *event) {
    switch (event->type) {
    case SDL_KEYDOWN:
    case SDL_KEYUP:
        return filter_key(&event->key, event->type == SDL_KEYDOWN);
    case SDL_TEXTINPUT:
    case SDL_TEXTEDITING:
    case SDL_MOUSEWHEEL:
        return s_dm.open;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        return filter_mouse_button(&event->button, event->type == SDL_MOUSEBUTTONDOWN);
    case SDL_CONTROLLERBUTTONDOWN:
    case SDL_CONTROLLERBUTTONUP:
        return filter_pad_button(&event->cbutton, event->type == SDL_CONTROLLERBUTTONDOWN);
    case SDL_CONTROLLERAXISMOTION:
        return filter_pad_axis(&event->caxis);
    case SDL_CONTROLLERDEVICEADDED:
        s_dm.rescan_pads = true;
        return false;
    case SDL_CONTROLLERDEVICEREMOVED: {
        dm_pad *p = find_pad(event->cdevice.which, false);
        if (p) {
            DM_LOG("pad %d removed", (int)p->id);
            if (p->consumed & PAD_BIT(SDL_CONTROLLER_BUTTON_RIGHTSTICK))
                dev_menu_input_event(DEV_MENU_IN_FF_HOLD_OFF);
            p->held = p->consumed = p->drain = p->reserved = 0;
            p->needs_neutral = false;
        }
        s_dm.rescan_pads = true;
        return false;
    }
    default:
        return false;
    }
}

/* Open our own handle on every controller and close handles for removed
 * ones.  Runs from the frame hook, never from inside an SDL callback.  A pad
 * that arrives with buttons held must go neutral before it can act. */
static void reconcile_pads(void) {
    if (!s_dm.controllers_ready) return;
    s_dm.rescan_pads = false;
    for (int i = 0; i < DM_MAX_PADS; ++i) {
        dm_pad *p = &s_dm.pads[i];
        if (p->used && p->controller && !SDL_GameControllerGetAttached(p->controller)) {
            SDL_GameControllerClose(p->controller);
            memset(p, 0, sizeof(*p));
        }
    }
    for (int index = 0; index < SDL_NumJoysticks(); ++index) {
        SDL_JoystickID id;
        SDL_GameController *gc;
        dm_pad *p;
        unsigned held = 0;
        if (!SDL_IsGameController(index)) continue;
        id = SDL_JoystickGetDeviceInstanceID(index);
        p = find_pad(id, false);
        if (p && p->controller) continue;
        gc = SDL_GameControllerOpen(index);
        if (!gc) continue;
        p = find_pad(id, true);
        if (!p) { SDL_GameControllerClose(gc); continue; }
        p->controller = gc;
        for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; ++b)
            if (SDL_GameControllerGetButton(gc, (SDL_GameControllerButton)b)) held |= PAD_BIT(b);
        held &= ~p->held;   /* presses we already saw as events are tracked */
        if (held) {
            p->held |= held;
            p->consumed |= held;
            p->needs_neutral = true;
        }
        DM_LOG("pad %d connected: %s%s", (int)id,
               SDL_GameControllerName(gc) ? SDL_GameControllerName(gc) : "(unnamed)",
               p->needs_neutral ? " (waiting for neutral)" : "");
    }
}

/* Keep the game's view of the pad still while the menu owns it: the whole
 * pad (analog pointer included) while open or while buttons from the menu
 * are still held, and the reserved Back/Start bits otherwise. */
static void update_pad_mask(void) {
    uint32_t mask = 0;
    static uint32_t last = 0xFFFFFFFEu;
    if (s_dm.open) {
        mask = 0xFFFFFFFFu;
    } else {
        for (int i = 0; i < DM_MAX_PADS; ++i) {
            const dm_pad *p = &s_dm.pads[i];
            if (!p->used) continue;
            if (p->drain || p->needs_neutral) mask = 0xFFFFFFFFu;
            mask |= p->reserved;
        }
    }
    if (mask != last && s_dm.host.set_pad_mask) s_dm.host.set_pad_mask(mask);
    last = mask;
}

#else  /* XANTH_HEADLESS_STUB */

static void set_drains(void) {}
static void reconcile_pads(void) {}
static void update_pad_mask(void) {}
bool dev_menu_filter_event(const SDL_Event *event, void *user) {
    (void)event; (void)user;
    return false;
}

#endif

/* ------------------------------------------------------------------------
 * Lifecycle and frame hooks
 * ------------------------------------------------------------------------ */

void dev_menu_start(const dev_menu_host *host) {
    if (!s_dm.enabled || s_dm.started) return;
    s_dm.started = true;
    if (host) s_dm.host = *host;
    {
        dev_warp_host wh;
        const char *unverified = getenv("XANTH_DEV_WARP_UNVERIFIED");
        memset(&wh, 0, sizeof(wh));
        wh.field_idle = s_dm.host.field_idle;
        wh.game_modal = s_dm.host.game_modal;
        wh.post_key = s_dm.host.post_key;
        snprintf(wh.save_dir, sizeof(wh.save_dir), "%s", s_dm.host.save_dir);
        snprintf(wh.checkpoint_dir, sizeof(wh.checkpoint_dir), "%s", s_dm.host.checkpoint_dir);
        dev_warp_load(&wh, unverified && !strcmp(unverified, "1"));
    }
    load_script();
#ifndef XANTH_HEADLESS_STUB
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0 &&
        SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0) {
        DM_LOG("controller menu input unavailable (%s); keyboard still works", SDL_GetError());
    } else {
        s_dm.controllers_ready = true;
        SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
        reconcile_pads();
    }
#endif
}

void dev_menu_shutdown(void) {
    if (!s_dm.started) return;
#ifndef XANTH_HEADLESS_STUB
    if (s_layer_tex) SDL_DestroyTexture(s_layer_tex);
    s_layer_tex = NULL;
    s_layer_renderer = NULL;
    for (int i = 0; i < DM_MAX_PADS; ++i)
        if (s_dm.pads[i].used && s_dm.pads[i].controller)
            SDL_GameControllerClose(s_dm.pads[i].controller);
    memset(s_dm.pads, 0, sizeof(s_dm.pads));
#endif
    s_dm.started = false;
}

/* Section 9: the first game save after a warp gets a warning. The save
 * format is untouched; the menu notices a save file written after the warp
 * and says so once, recording it in the side file too. */
static bool newer_save_exists(const char *dir, time_t since) {
#if defined(_WIN32)
    char pattern[600];
    struct _finddata_t fd;
    intptr_t h;
    bool found = false;
    snprintf(pattern, sizeof(pattern), "%s\\XANTH*.SAV", dir);
    if ((h = _findfirst(pattern, &fd)) == -1) return false;
    do { if (fd.time_write > since) found = true; } while (!found && _findnext(h, &fd) == 0);
    _findclose(h);
    return found;
#else
    DIR *d = opendir(dir);
    struct dirent *e;
    bool found = false;
    if (!d) return false;
    while (!found && (e = readdir(d)) != NULL) {
        char path[1100];
        struct stat st;
        if (strncasecmp(e->d_name, "XANTH", 5) != 0 || !strcasestr(e->d_name, ".SAV")) continue;
        snprintf(path, sizeof(path), "%s/%s", dir, e->d_name);
        if (stat(path, &st) == 0 && st.st_mtime > since) found = true;
    }
    closedir(d);
    return found;
#endif
}

static void check_first_save(void) {
    char path[600];
    FILE *f;
    if (!s_dm.dev_used_since || s_dm.save_warned || dev_warp_active() || !s_dm.host.save_dir[0]) return;
    if (++s_dm.save_scan_frames < 70) return;        /* about once a second */
    s_dm.save_scan_frames = 0;
    if (!newer_save_exists(s_dm.host.save_dir, s_dm.dev_used_since)) return;
    s_dm.save_warned = true;
    toast("Dev menu was used: this save may not match a normal playthrough");
    snprintf(path, sizeof(path), "%s/xanth-dev-menu.log", s_dm.host.save_dir);
    if ((f = fopen(path, "a")) != NULL) {
        fprintf(f, "%ld first save after dev-menu use\n", (long)time(NULL));
        fclose(f);
    }
}

void dev_menu_frame(long long frame) {
    if (!s_dm.enabled) return;
#ifndef XANTH_HEADLESS_STUB
    if (s_dm.rescan_pads) reconcile_pads();
#endif
    while (s_dm.script_next < s_dm.nscript && s_dm.script[s_dm.script_next].frame <= frame) {
        const dm_script_entry *se = &s_dm.script[s_dm.script_next];
        if (se->frame == frame) {
            if (se->kind == SCRIPT_INPUT) {
                dev_menu_input_event(se->in);
            } else if (se->kind == SCRIPT_GAME_KEY) {
                if (s_dm.host.post_key) s_dm.host.post_key(se->scan, se->ascii);
            } else {
                char msg[128];
                int index = dev_warp_find(se->id);
                if (!strcmp(se->id, "@finish")) {
                    int room = -1, score = -1, items = -1;
                    index = (s_dm.host.read_progress && s_dm.host.read_progress(&room, &score, &items))
                        ? dev_warp_current_step(room, score, items) : -1;
                    DM_LOG("finish step requested at room %d score %d items %d -> %s", room, score, items,
                           index >= 0 ? dev_warp_get(index)->id : "(no step)");
                }
                if (index < 0) toast("Warp refused: no checkpoint %s", se->id);
                else { dev_warp_request(index, msg, sizeof(msg)); toast("%s", msg); }
            }
        }
        s_dm.script_next++;
    }
    if (dev_warp_active()) {
        dev_warp_status ws = dev_warp_tick();
        if (ws == DEV_WARP_DONE || ws == DEV_WARP_FAILED) {
            toast("%s", dev_warp_message());
            if (ws == DEV_WARP_DONE) {
                s_dm.cheats_used = true;
                if (!s_dm.dev_used_since) s_dm.dev_used_since = time(NULL);
            }
        }
    }
    check_first_save();
    if (s_dm.toast_frames > 0 && --s_dm.toast_frames == 0) s_dm.toast[0] = '\0';
    update_pad_mask();
}

void dev_menu_after_present(void) {
    char path[700], stamp[32];
    time_t now;
    struct tm tmv;
    if (!s_dm.enabled || !s_dm.shot_pending) return;
    s_dm.shot_pending = false;
    static uint32_t shot[LAYER_W * LAYER_H];
    if (!s_dm.host.save_screenshot || !s_dm.host.copy_presented || !s_dm.host.copy_presented(shot)) {
        toast("Screenshot: no presented frame available");
        return;
    }
    dev_menu_draw(shot, LAYER_W, LAYER_H, NULL);   /* what the player sees */
    ensure_shot_dir(s_dm.host.screenshot_dir);
    now = time(NULL);
#if defined(_WIN32)
    localtime_s(&tmv, &now);
#else
    localtime_r(&now, &tmv);
#endif
    strftime(stamp, sizeof(stamp), "%Y%m%d-%H%M%S", &tmv);
    snprintf(path, sizeof(path), "%s/xanth-%s-%03d.bmp",
             s_dm.host.screenshot_dir[0] ? s_dm.host.screenshot_dir : ".", stamp,
             ++s_dm.shot_counter);
    {
        const char *name = strrchr(path, '/');
        name = name ? name + 1 : path;
        if (s_dm.host.save_screenshot(path, shot)) {
            DM_LOG("screenshot written to %s", path);
            toast("Screenshot saved: %s", name);
        } else {
            DM_LOG("screenshot failed: %s", path);
            toast("Screenshot failed: %s", name);
        }
    }
}

int dev_menu_guest_frames_per_present(void) {
    if (!s_dm.enabled || !(s_dm.ff_on || s_dm.ff_hold)) return 1;
    return s_ff_factors[s_dm.ff_speed];
}

bool dev_menu_unpaced(void) {
    return s_dm.enabled && (s_dm.ff_on || s_dm.ff_hold) && s_dm.ff_speed == 3;
}

/* ------------------------------------------------------------------------
 * Overlay drawing (RGBA8888: R<<24 | G<<16 | B<<8 | A)
 *
 * The menu is drawn into its own transparent 320x200 layer, which is then
 * composited either onto the presented RGBA copy (dev_menu_draw) or through
 * a blended texture into the renderer's viewport (dev_menu_render).
 * ------------------------------------------------------------------------ */

#define RGBA(r, g, b, a) (((uint32_t)(r) << 24) | ((uint32_t)(g) << 16) | ((uint32_t)(b) << 8) | (uint32_t)(a))
#define RGB(r, g, b) RGBA(r, g, b, 0xFF)
#define COL_SHADE   RGBA(0x08, 0x08, 0x14, 0xD0)
#define COL_TEXT    RGB(0xE8, 0xE8, 0xE8)
#define COL_DIM     RGB(0x98, 0x98, 0xA8)
#define COL_TITLE   RGB(0xFF, 0xD8, 0x60)
#define COL_SELECT  RGB(0x30, 0x58, 0xA0)
#define COL_BORDER  RGB(0x70, 0x90, 0xD0)
#define COL_ALERT   RGB(0xFF, 0x50, 0x50)

typedef struct { uint32_t *px; int w, h; } dm_canvas;

static void fill_rect(dm_canvas *c, int x, int y, int w, int h, uint32_t col);

static void shade_rect(dm_canvas *c, int x, int y, int w, int h) {
    fill_rect(c, x, y, w, h, COL_SHADE);
}

static void fill_rect(dm_canvas *c, int x, int y, int w, int h, uint32_t col) {
    for (int yy = y < 0 ? 0 : y; yy < y + h && yy < c->h; ++yy)
        for (int xx = x < 0 ? 0 : x; xx < x + w && xx < c->w; ++xx)
            c->px[yy * c->w + xx] = col;
}

static void frame_rect(dm_canvas *c, int x, int y, int w, int h, uint32_t col) {
    fill_rect(c, x, y, w, 1, col);
    fill_rect(c, x, y + h - 1, w, 1, col);
    fill_rect(c, x, y, 1, h, col);
    fill_rect(c, x + w - 1, y, 1, h, col);
}

/* Draws at most max_chars glyphs (<= 0: no limit). */
static void draw_text_n(dm_canvas *c, int x, int y, const char *s, uint32_t col, int max_chars) {
    for (int n = 0; *s && (max_chars <= 0 || n < max_chars); ++s, ++n, x += DEV_MENU_GLYPH_W) {
        unsigned ch = (unsigned char)*s;
        const uint8_t *g;
        if (ch < 32 || ch > 126) ch = '?';
        g = g_dev_menu_font[ch - 32];
        for (int row = 0; row < DEV_MENU_GLYPH_H; ++row)
            for (int col_i = 0; col_i < DEV_MENU_GLYPH_W; ++col_i)
                if (g[row] & (1u << (DEV_MENU_GLYPH_W - 1 - col_i))) {
                    int px = x + col_i, py = y + row;
                    if (px >= 0 && py >= 0 && px < c->w && py < c->h)
                        c->px[py * c->w + px] = col;
                }
    }
}

static void draw_text(dm_canvas *c, int x, int y, const char *s, uint32_t col) {
    draw_text_n(c, x, y, s, col, 0);
}

static const char *page_name(dm_page p) {
    switch (p) {
    case PAGE_WARP:    return "Warp";
    case PAGE_WARP_AREAS: return s_dm.warp_region;
    case PAGE_WARP_SPOTS: return s_dm.warp_area;
    case PAGE_FINISH:  return "Finish Area";
    case PAGE_CHEATS:  return "Cheats";
    case PAGE_OPTIONS: return "Options";
    case PAGE_HELP:    return "Help";
    default:           return "";
    }
}

static void draw_badge(dm_canvas *c, int x, int y, const char *s, uint32_t col) {
    int w = (int)strlen(s) * DEV_MENU_GLYPH_W + 4;
    shade_rect(c, x, y, w, DEV_MENU_GLYPH_H + 2);
    draw_text(c, x + 2, y + 1, s, col);
}

static uint32_t s_layer[LAYER_W * LAYER_H];

/* Renders the overlay into s_layer.  Returns false, touching nothing, when
 * no part of the menu is visible. */
static bool render_layer(void) {
    const int width = LAYER_W, height = LAYER_H;
    dm_canvas cv = { s_layer, LAYER_W, LAYER_H };
    bool ff = s_dm.ff_on || s_dm.ff_hold;
    if (!s_dm.enabled) return false;
    if (!s_dm.open && !s_dm.toast[0] && !s_dm.cheats_used && !ff) return false;
    memset(s_layer, 0, sizeof(s_layer));

    if (s_dm.cheats_used) draw_badge(&cv, width - 6 * DEV_MENU_GLYPH_W - 6, 2, "CHEATS", COL_ALERT);
    if (ff) {
        char label[16];
        snprintf(label, sizeof(label), "FF %s", s_ff_names[s_dm.ff_speed]);
        draw_badge(&cv, 2, 2, label, COL_TITLE);
    }

    if (s_dm.open) {
        const int px = 16, py = 16, pw = width - 32, ph = height - 32;
        const int line = DEV_MENU_GLYPH_H + 1, list_y = py + 20;
        const int visible = (ph - 20 - 26) / line;
        const int cols = (pw - 12) / DEV_MENU_GLYPH_W;
        int cur = s_dm.cursor[s_dm.page], first = 0;
        char title[64];

        shade_rect(&cv, px, py, pw, ph);
        frame_rect(&cv, px, py, pw, ph, COL_BORDER);
        if (s_dm.page == PAGE_ROOT) snprintf(title, sizeof(title), "DEV MENU");
        else snprintf(title, sizeof(title), "DEV MENU > %s", page_name(s_dm.page));
        draw_text(&cv, px + 6, py + 5, title, COL_TITLE);
        fill_rect(&cv, px + 4, py + 16, pw - 8, 1, COL_BORDER);

        if (cur >= visible) first = cur - visible + 1;
        for (int i = first; i < s_dm.nrows && i < first + visible; ++i) {
            int y = list_y + (i - first) * line;
            bool sel = i == cur;
            if (sel) fill_rect(&cv, px + 4, y - 1, pw - 8, line, COL_SELECT);
            draw_text(&cv, px + 8, y, sel ? ">" : " ", COL_TITLE);
            draw_text_n(&cv, px + 8 + 2 * DEV_MENU_GLYPH_W, y, s_dm.rows[i].label,
                        s_dm.rows[i].kind == ROW_INFO ? COL_DIM : COL_TEXT, cols - 2);
        }

        fill_rect(&cv, px + 4, py + ph - 26, pw - 8, 1, COL_BORDER);
        if (s_dm.toast[0]) draw_text_n(&cv, px + 6, py + ph - 24, s_dm.toast, COL_TITLE, cols);
        draw_text(&cv, px + 6, py + ph - 13, "A/Enter select  B/Esc back  F12 close", COL_DIM);
    } else if (s_dm.toast[0]) {
        int w = (int)strlen(s_dm.toast) * DEV_MENU_GLYPH_W + 8;
        if (w > width) w = width;
        shade_rect(&cv, 0, height - DEV_MENU_GLYPH_H - 4, w, DEV_MENU_GLYPH_H + 4);
        draw_text_n(&cv, 4, height - DEV_MENU_GLYPH_H - 2, s_dm.toast, COL_TITLE,
                    (width - 8) / DEV_MENU_GLYPH_W);
    }
    return true;
}

static uint8_t blend8(uint32_t src, uint32_t dst, int shift, uint32_t a) {
    uint32_t sc = (src >> shift) & 0xFF, dc = (dst >> shift) & 0xFF;
    return (uint8_t)((sc * a + dc * (255 - a) + 127) / 255);
}

void dev_menu_draw(uint32_t *rgba, int width, int height, void *user) {
    (void)user;
    if (!rgba || width != LAYER_W || height != LAYER_H || !render_layer()) return;
    for (int i = 0; i < LAYER_W * LAYER_H; ++i) {
        uint32_t src = s_layer[i], a = src & 0xFF, dst;
        if (!a) continue;
        dst = rgba[i];
        rgba[i] = a == 0xFF ? (src | 0xFFu)
                : RGB(blend8(src, dst, 24, a), blend8(src, dst, 16, a), blend8(src, dst, 8, a));
    }
}

#ifndef XANTH_HEADLESS_STUB
void dev_menu_render(SDL_Renderer *renderer, const hal_video_viewport *viewport, void *user) {
    SDL_Rect dst;
    (void)user;
    if (!renderer || !viewport || viewport->width <= 0 || !render_layer()) return;
    if (s_layer_renderer != renderer && s_layer_tex) {
        SDL_DestroyTexture(s_layer_tex);
        s_layer_tex = NULL;
    }
    if (!s_layer_tex) {
        s_layer_tex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                        SDL_TEXTUREACCESS_STREAMING, LAYER_W, LAYER_H);
        if (!s_layer_tex) return;
        SDL_SetTextureBlendMode(s_layer_tex, SDL_BLENDMODE_BLEND);
        s_layer_renderer = renderer;
    }
    SDL_UpdateTexture(s_layer_tex, NULL, s_layer, LAYER_W * (int)sizeof(uint32_t));
    dst.x = viewport->x; dst.y = viewport->y; dst.w = viewport->width; dst.h = viewport->height;
    SDL_RenderCopy(renderer, s_layer_tex, NULL, &dst);
}
#endif

/* ------------------------------------------------------------------------
 * Introspection
 * ------------------------------------------------------------------------ */

bool dev_menu_is_open(void) { return s_dm.open; }

const char *dev_menu_page_title(void) {
    return s_dm.page == PAGE_ROOT ? "DEV MENU" : page_name(s_dm.page);
}

int dev_menu_row_count(void) { return s_dm.open ? s_dm.nrows : 0; }

int dev_menu_selectable_count(void) {
    int n = 0;
    if (!s_dm.open) return 0;
    for (int i = 0; i < s_dm.nrows; ++i) n += row_selectable(i);
    return n;
}

int dev_menu_cursor(void) { return s_dm.open ? s_dm.cursor[s_dm.page] : -1; }

const char *dev_menu_row_label(int row) {
    return (s_dm.open && row >= 0 && row < s_dm.nrows) ? s_dm.rows[row].label : "";
}

const char *dev_menu_toast(void) { return s_dm.toast; }

bool dev_menu_cheats_marker(void) { return s_dm.cheats_used; }

void dev_menu_reset_for_tests(void) {
    dev_warp_reset_for_tests();
#ifndef XANTH_HEADLESS_STUB
#endif
    memset(&s_dm, 0, sizeof(s_dm));
}
