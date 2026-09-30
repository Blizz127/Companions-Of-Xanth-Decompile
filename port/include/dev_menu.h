/*
 * dev_menu.h — opt-in playtest menu (shared port dev-menu spec v1).
 *
 * The menu is host-only: it draws on the presented RGBA copy of the frame,
 * never on guest VRAM, and in this milestone it holds no pointer to guest
 * memory at all.  Warp, Finish Area and Cheats list only entries verified
 * against the game's own state; until those land they show no selectable rows.
 *
 * Off by default.  Enabled by --dev-menu, XANTH_DEV_MENU=1 or dev_menu=1 in
 * the port config; XANTH_CHEATS=0 hard-disables it so nothing is subscribed.
 */
#ifndef DEV_MENU_H
#define DEV_MENU_H

#include <stdbool.h>
#include <stdint.h>

#include "port_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Abstract menu inputs.  SDL events and the harness key script both map here.
 * The key names follow the shared spec; for Xanth only DEV_MENU_IN_TOGGLE
 * has a keyboard shortcut (F12), because retail uses F1-F10 itself. */
typedef enum {
    DEV_MENU_IN_TOGGLE = 0,      /* F12, Back+Start on one pad */
    DEV_MENU_IN_UP,
    DEV_MENU_IN_DOWN,
    DEV_MENU_IN_CONFIRM,         /* Enter, A */
    DEV_MENU_IN_BACK,            /* Escape, B */
    DEV_MENU_IN_HELP,            /* spec F1 */
    DEV_MENU_IN_GOD,             /* spec F2 */
    DEV_MENU_IN_RESOURCE,        /* spec F3 */
    DEV_MENU_IN_INSTANT_WIN,     /* spec F4 */
    DEV_MENU_IN_KEY_ITEMS,       /* spec F5 */
    DEV_MENU_IN_FF_TOGGLE,       /* L3 (spec F6) */
    DEV_MENU_IN_FF_HOLD_ON,      /* R3 down */
    DEV_MENU_IN_FF_HOLD_OFF,     /* R3 up */
    DEV_MENU_IN_FF_SPEED,        /* spec F7 */
    DEV_MENU_IN_FF_SPEED_RESET,  /* spec Shift+F7 */
    DEV_MENU_IN_RECORD,          /* spec F9 */
    DEV_MENU_IN_SCREENSHOT,      /* spec F10 */
    DEV_MENU_IN_QUICK_SAVE,      /* spec F11 */
    DEV_MENU_IN_QUICK_LOAD,      /* spec F12 */
    DEV_MENU_IN_COUNT
} dev_menu_input;

/* Host services the Options page drives.  Any member may be NULL. */
typedef struct {
    void (*toggle_fullscreen)(void);
    void (*toggle_scanlines)(void);
    bool (*scanlines_enabled)(void);
    /* Screenshots: the presented 320x200 RGBA frame, which the menu
     * composites its overlay onto before writing it. */
    bool (*copy_presented)(uint32_t *rgba);
    bool (*save_screenshot)(const char *path, const uint32_t *rgba);
    /* hal_input_set_pad_button_mask: SDL button bits kept from the game. */
    void (*set_pad_mask)(uint32_t mask);
    char screenshot_dir[512];
    /* Warps (dev_warp.h): the game's own idle signal, the keyboard path a
     * player uses, and where saves and user-local checkpoints live. */
    bool (*field_idle)(void);
    bool (*game_modal)(void);
    /* The game's own progress: current room (DS:0256), score (DS:0264) and
     * inventory count (DS:69FC), read only; false if not yet known. */
    bool (*read_progress)(int *room, int *score, int *items);
    void (*post_key)(uint8_t scan, uint8_t ascii);
    char save_dir[512];
    char checkpoint_dir[512];
} dev_menu_host;

/* Resolve whether the menu is on.  It is on by default; in order of
 * precedence, XANTH_CHEATS=0 hard-disables it, XANTH_DEV_MENU=0/1 overrides,
 * then the CLI (cli < 0: no flag, 0: --no-dev-menu, > 0: --dev-menu), then
 * the dev_menu key of the port config file (may be NULL or empty).  Call
 * once, before SDL is initialised.  Returns true when the menu is enabled. */
bool dev_menu_resolve(int cli, const char *config_path);
bool dev_menu_enabled(void);

/* Start the menu (controllers, harness script).  No-op when the menu is not
 * enabled.  The caller registers dev_menu_filter_event with
 * hal_input_set_event_filter and dev_menu_render with hal_video_set_overlay. */
void dev_menu_start(const dev_menu_host *host);
void dev_menu_shutdown(void);

/* Per-presented-frame hooks. */
void dev_menu_frame(long long frame);
void dev_menu_after_present(void);

/* Fast-forward: guest frames to run per presented frame (1 when off), and
 * whether frame pacing is skipped entirely (the "max" speed). */
int  dev_menu_guest_frames_per_present(void);
bool dev_menu_unpaced(void);

/* Overlay hooks.  dev_menu_draw composites onto the presented 320x200
 * RGBA8888 copy (R<<24|G<<16|B<<8|A); dev_menu_render draws the same layer
 * into the renderer's viewport before present.  Both leave everything
 * untouched when nothing is visible. */
void dev_menu_draw(uint32_t *rgba, int width, int height, void *user);
void dev_menu_render(SDL_Renderer *renderer, const hal_video_viewport *viewport, void *user);

/* SDL input filter for hal_input_set_event_filter.  Returns true when the
 * menu consumes the event. */
bool dev_menu_filter_event(const SDL_Event *event, void *user);

/* Direct input, shared by the SDL adapter and the harness key script. */
void dev_menu_input_event(dev_menu_input in);

/* Introspection for tests and the overlay. */
bool dev_menu_is_open(void);
const char *dev_menu_page_title(void);
int  dev_menu_row_count(void);
int  dev_menu_selectable_count(void);
int  dev_menu_cursor(void);
const char *dev_menu_row_label(int row);
const char *dev_menu_toast(void);
bool dev_menu_cheats_marker(void);

/* Test-only: forget all state, as if the process had just started. */
void dev_menu_reset_for_tests(void);

#ifdef __cplusplus
}
#endif

#endif /* DEV_MENU_H */
