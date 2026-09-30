/* Asset-free regression of the opt-in dev menu: opt-in resolution, the
 * all-off identity, navigation, input capture and neutral drain, the same-pad
 * combo, fast-forward, refusals, the harness key script and virtual pads. */
#include "dev_menu.h"
#include "dev_warp.h"
#include <unistd.h>
#include "port_hal.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "line %d: %s\n", __LINE__, #c); exit(1); } } while (0)

/* Input-only fixture: no window required. */
void hal_video_get_viewport(int *x, int *y, int *w, int *h) {
    *x = *y = 0; *w = 320; *h = 200;
}
bool hal_video_map_mouse(int x, int y, int *sx, int *sy) { *sx = x; *sy = y; return true; }
bool hal_video_map_touch(float x, float y, int *sx, int *sy) {
    *sx = (int)(x * 320); *sy = (int)(y * 200); return true;
}
void hal_video_mouse_window_event(uint32_t id, bool inside) { (void)id; (void)inside; }

static int g_fullscreen_calls, g_scanline_calls, g_shot_calls;
static bool g_scanlines;
static char g_shot_path[700];
static uint32_t g_pad_mask, g_shot_pixel;
static void stub_fullscreen(void) { g_fullscreen_calls++; }
static void stub_scanlines(void) { g_scanline_calls++; g_scanlines = !g_scanlines; }
static bool stub_scanlines_on(void) { return g_scanlines; }
static bool stub_copy(uint32_t *rgba) {
    for (int i = 0; i < 320 * 200; ++i) rgba[i] = 0x285078FFu;
    return true;
}
static bool stub_shot(const char *path, const uint32_t *rgba) {
    g_shot_calls++; snprintf(g_shot_path, sizeof(g_shot_path), "%s", path);
    g_shot_pixel = rgba[100 * 320 + 200];
    return true;
}
static void stub_mask(uint32_t mask) { g_pad_mask = mask; }

static void begin(bool opt_in) {
    dev_menu_host host;
    memset(&host, 0, sizeof(host));
    host.toggle_fullscreen = stub_fullscreen;
    host.toggle_scanlines = stub_scanlines;
    host.scanlines_enabled = stub_scanlines_on;
    host.copy_presented = stub_copy;
    host.save_screenshot = stub_shot;
    host.set_pad_mask = stub_mask;
    snprintf(host.screenshot_dir, sizeof(host.screenshot_dir), "%s", "test-shots");
    dev_menu_reset_for_tests();
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
    hal_input_init();
    dev_menu_resolve(opt_in, NULL);
    dev_menu_start(&host);
    hal_input_set_event_filter(dev_menu_filter_event, NULL);
    g_pad_mask = 0;
    g_fullscreen_calls = g_scanline_calls = g_shot_calls = 0;
    g_scanlines = false;
}

/* Event builders.  filt() calls the menu filter directly; push() goes through
 * SDL and hal_input_poll(), which is what the game actually receives. */
static SDL_Event key_ev(SDL_Keycode sym, SDL_Scancode sc, bool down, bool repeat, Uint16 mod) {
    SDL_Event e; memset(&e, 0, sizeof(e));
    e.type = down ? SDL_KEYDOWN : SDL_KEYUP;
    e.key.keysym.sym = sym; e.key.keysym.scancode = sc; e.key.keysym.mod = mod;
    e.key.repeat = repeat; e.key.state = down ? SDL_PRESSED : SDL_RELEASED;
    return e;
}
static SDL_Event btn_ev(SDL_JoystickID id, Uint8 button, bool down) {
    SDL_Event e; memset(&e, 0, sizeof(e));
    e.type = down ? SDL_CONTROLLERBUTTONDOWN : SDL_CONTROLLERBUTTONUP;
    e.cbutton.which = id; e.cbutton.button = button;
    e.cbutton.state = down ? SDL_PRESSED : SDL_RELEASED;
    return e;
}
static SDL_Event axis_ev(SDL_JoystickID id, Uint8 axis, Sint16 value) {
    SDL_Event e; memset(&e, 0, sizeof(e));
    e.type = SDL_CONTROLLERAXISMOTION;
    e.caxis.which = id; e.caxis.axis = axis; e.caxis.value = value;
    return e;
}
static SDL_Event mouse_ev(Uint8 button, bool down) {
    SDL_Event e; memset(&e, 0, sizeof(e));
    e.type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
    e.button.button = button; e.button.state = down ? SDL_PRESSED : SDL_RELEASED;
    return e;
}
static bool filt(SDL_Event e) { return dev_menu_filter_event(&e, NULL); }
static bool key(SDL_Keycode sym, SDL_Scancode sc, bool down) {
    return filt(key_ev(sym, sc, down, false, 0));
}
static bool tap(SDL_Keycode sym, SDL_Scancode sc) {
    bool a = key(sym, sc, true), b = key(sym, sc, false);
    return a && b;
}
#define OPEN()  tap(SDLK_F12, SDL_SCANCODE_F12)
#define DOWN()  tap(SDLK_DOWN, SDL_SCANCODE_DOWN)
#define UP()    tap(SDLK_UP, SDL_SCANCODE_UP)
#define ENTER() tap(SDLK_RETURN, SDL_SCANCODE_RETURN)
#define ESC()   tap(SDLK_ESCAPE, SDL_SCANCODE_ESCAPE)
static bool pad_tap(SDL_JoystickID id, Uint8 b) {
    bool x = filt(btn_ev(id, b, true)), y = filt(btn_ev(id, b, false));
    return x && y;
}

static int push_and_poll(SDL_Event e, int *key_code) {
    int buttons = 0;
    CHECK(SDL_PushEvent(&e) >= 0);                         /* 0: the menu filtered it */
    hal_input_poll(NULL, NULL, &buttons, key_code);
    return buttons;
}
static int fifo_count(void) {
    int n = 0;
    while (hal_keyboard_peek(NULL)) { hal_keyboard_read(); n++; }
    return n;
}
static int queued_replays(void) {
    SDL_Event ev[16];
    int n = SDL_PeepEvents(ev, 16, SDL_PEEKEVENT, SDL_CONTROLLERBUTTONDOWN, SDL_CONTROLLERBUTTONUP);
    return n < 0 ? 0 : n;
}

static void test_resolution(void) {
    SDL_setenv("XANTH_DEV_MENU", "", 1); SDL_setenv("XANTH_CHEATS", "", 1);
    dev_menu_reset_for_tests();
    CHECK(!dev_menu_resolve(false, NULL));                 /* off by default */
    CHECK(dev_menu_resolve(true, NULL));                   /* --dev-menu */
    SDL_setenv("XANTH_DEV_MENU", "1", 1);
    CHECK(dev_menu_resolve(false, NULL));
    SDL_setenv("XANTH_CHEATS", "0", 1);
    CHECK(!dev_menu_resolve(false, NULL));                 /* hard disable wins */
    CHECK(!dev_menu_resolve(true, NULL));
    SDL_setenv("XANTH_CHEATS", "", 1);
    SDL_setenv("XANTH_DEV_MENU", "0", 1);
    CHECK(!dev_menu_resolve(true, NULL));                  /* explicit env off */
    SDL_setenv("XANTH_DEV_MENU", "", 1);
    {
        FILE *f = fopen("dev_menu_test.cfg", "w");
        CHECK(f); fputs("# port config\nscale = 3\n dev_menu = true \n", f); fclose(f);
        CHECK(dev_menu_resolve(false, "dev_menu_test.cfg"));
        f = fopen("dev_menu_test.cfg", "w");
        CHECK(f); fputs("dev_menu=0\n", f); fclose(f);
        CHECK(!dev_menu_resolve(false, "dev_menu_test.cfg"));
        remove("dev_menu_test.cfg");
    }
    CHECK(!dev_menu_resolve(false, "no-such-file.cfg"));
}

static void test_disabled_is_inert(void) {
    uint32_t px[320 * 200], ref[320 * 200];
    int key_code = 0;
    for (int i = 0; i < 320 * 200; ++i) px[i] = ref[i] = 0x10203000u + (uint32_t)i;
    begin(false);
    CHECK(!dev_menu_enabled());
    push_and_poll(key_ev(SDLK_F8, SDL_SCANCODE_F8, true, false, 0), &key_code);
    CHECK(!dev_menu_is_open());
    CHECK(hal_keyboard_read() == 0x4200);                  /* retail F8 reaches the game */
    dev_menu_frame(1);
    dev_menu_draw(px, 320, 200, NULL);
    CHECK(!memcmp(px, ref, sizeof(px)));
    CHECK(dev_menu_guest_frames_per_present() == 1 && !dev_menu_unpaced());
    dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE);
    CHECK(dev_menu_guest_frames_per_present() == 1);

    /* Requested but hard-disabled: identical to off. */
    SDL_setenv("XANTH_CHEATS", "0", 1);
    begin(true);
    SDL_setenv("XANTH_CHEATS", "", 1);
    CHECK(!dev_menu_enabled());
    push_and_poll(key_ev(SDLK_F8, SDL_SCANCODE_F8, true, false, 0), &key_code);
    CHECK(!dev_menu_is_open() && hal_keyboard_read() == 0x4200);
}

static void test_all_off_identity(void) {
    uint32_t px[320 * 200], ref[320 * 200];
    int key_code = 0;
    for (int i = 0; i < 320 * 200; ++i) px[i] = ref[i] = 0xA0B0C0FFu ^ (uint32_t)(i * 2654435761u);
    begin(true);
    CHECK(dev_menu_enabled() && !dev_menu_is_open());
    for (long long f = 0; f < 5; ++f) dev_menu_frame(f);
    dev_menu_draw(px, 320, 200, NULL);
    CHECK(!memcmp(px, ref, sizeof(px)));                   /* nothing visible: untouched */
    CHECK(dev_menu_guest_frames_per_present() == 1 && !dev_menu_unpaced());
    CHECK(!dev_menu_cheats_marker());
    /* Ordinary game input still passes with the menu closed. */
    push_and_poll(key_ev(SDLK_z, SDL_SCANCODE_Z, true, false, 0), &key_code);
    CHECK(hal_keyboard_read() == 0x2c7a);
    CHECK(push_and_poll(mouse_ev(SDL_BUTTON_LEFT, true), NULL) & HAL_MOUSE_BTN_LEFT);
    CHECK(!(push_and_poll(mouse_ev(SDL_BUTTON_LEFT, false), NULL) & HAL_MOUSE_BTN_LEFT));
    push_and_poll(key_ev(SDLK_ESCAPE, SDL_SCANCODE_ESCAPE, true, false, 0), &key_code);
    CHECK(key_code == 27);                                 /* Escape still quits when closed */
    fifo_count();

    /* Retail F-keys (F1 waits) always reach the game; F12 never did. */
    for (int k = 0; k < 10; ++k) {
        static const SDL_Keycode syms[10] = { SDLK_F1, SDLK_F2, SDLK_F3, SDLK_F4, SDLK_F5,
                                              SDLK_F6, SDLK_F7, SDLK_F8, SDLK_F9, SDLK_F10 };
        push_and_poll(key_ev(syms[k], (SDL_Scancode)(SDL_SCANCODE_F1 + k), true, false, 0), &key_code);
        push_and_poll(key_ev(syms[k], (SDL_Scancode)(SDL_SCANCODE_F1 + k), false, false, 0), &key_code);
        CHECK(hal_keyboard_read() == (uint16_t)((0x3B + k) << 8));
        CHECK(!dev_menu_is_open() && dev_menu_guest_frames_per_present() == 1);
    }
    CHECK(fifo_count() == 0);

    /* Opening draws; closing restores the untouched presentation. */
    push_and_poll(key_ev(SDLK_F12, SDL_SCANCODE_F12, true, false, 0), &key_code);
    CHECK(dev_menu_is_open() && fifo_count() == 0);
    dev_menu_draw(px, 320, 200, NULL);
    CHECK(memcmp(px, ref, sizeof(px)) != 0);
    memcpy(px, ref, sizeof(px));
    push_and_poll(key_ev(SDLK_z, SDL_SCANCODE_Z, true, false, 0), &key_code);
    CHECK(fifo_count() == 0);                              /* typing is captured while open */
    CHECK(!(push_and_poll(mouse_ev(SDL_BUTTON_LEFT, true), NULL) & HAL_MOUSE_BTN_LEFT));
    push_and_poll(key_ev(SDLK_ESCAPE, SDL_SCANCODE_ESCAPE, true, false, 0), &key_code);
    CHECK(key_code != 27 && !dev_menu_is_open());          /* Esc at root closes, never quits */
}

static void test_navigation(void) {
    begin(true);
    CHECK(OPEN() && dev_menu_is_open());
    CHECK(!strcmp(dev_menu_page_title(), "DEV MENU"));
    CHECK(dev_menu_row_count() == 4 && dev_menu_selectable_count() == 4);
    CHECK(!strcmp(dev_menu_row_label(0), "Warp >"));
    CHECK(!strcmp(dev_menu_row_label(1), "Finish Area >"));
    CHECK(!strcmp(dev_menu_row_label(2), "Cheats >"));
    CHECK(!strcmp(dev_menu_row_label(3), "Options >"));
    CHECK(dev_menu_cursor() == 0);
    DOWN(); DOWN(); DOWN();
    CHECK(dev_menu_cursor() == 3);
    DOWN(); CHECK(dev_menu_cursor() == 0);                 /* wraps */
    UP(); CHECK(dev_menu_cursor() == 3);
    CHECK(filt(key_ev(SDLK_UP, SDL_SCANCODE_UP, true, true, 0)));   /* auto-repeat ignored */
    CHECK(dev_menu_cursor() == 3);
    key(SDLK_UP, SDL_SCANCODE_UP, false);
    ENTER();
    CHECK(!strcmp(dev_menu_page_title(), "Options"));
    CHECK(!strcmp(dev_menu_row_label(0), "Fast-forward: OFF"));
    ESC();
    CHECK(!strcmp(dev_menu_page_title(), "DEV MENU") && dev_menu_cursor() == 3);
    UP(); UP(); UP();
    ENTER();                                               /* Warp: an empty group */
    CHECK(!strcmp(dev_menu_page_title(), "Warp"));
    CHECK(dev_menu_selectable_count() == 0 && dev_menu_cursor() == -1);
    DOWN(); ENTER();
    CHECK(!strcmp(dev_menu_page_title(), "Warp"));
    ESC(); ESC();
    CHECK(!dev_menu_is_open());

    /* Help is an Options row and returns to Options. */
    OPEN(); UP(); ENTER();
    CHECK(!strcmp(dev_menu_page_title(), "Options"));
    UP();
    CHECK(!strcmp(dev_menu_row_label(dev_menu_cursor()), "Help (controls)"));
    ENTER();
    CHECK(!strcmp(dev_menu_page_title(), "Help") && dev_menu_selectable_count() == 0);
    ESC();
    CHECK(!strcmp(dev_menu_page_title(), "Options"));
    ESC(); ESC();
    CHECK(!dev_menu_is_open());
    /* The harness HELP input still opens help directly from closed. */
    dev_menu_input_event(DEV_MENU_IN_HELP);
    CHECK(dev_menu_is_open() && !strcmp(dev_menu_page_title(), "Help"));
    ESC();
    CHECK(!dev_menu_is_open());
}

static void test_keyboard_capture_and_drain(void) {
    begin(true);
    /* A key the game saw before opening keeps its release. */
    CHECK(!key(SDLK_a, SDL_SCANCODE_A, true));
    OPEN();
    CHECK(!key(SDLK_a, SDL_SCANCODE_A, false));
    /* Repeats of a game-owned key while open are swallowed (no input leaks). */
    CHECK(filt(key_ev(SDLK_b, SDL_SCANCODE_B, true, true, 0)));
    /* Close with Escape held: gameplay keys wait until it is released. */
    CHECK(key(SDLK_ESCAPE, SDL_SCANCODE_ESCAPE, true));
    CHECK(!dev_menu_is_open());
    CHECK(key(SDLK_z, SDL_SCANCODE_Z, true));              /* drained */
    CHECK(key(SDLK_ESCAPE, SDL_SCANCODE_ESCAPE, false));
    CHECK(key(SDLK_z, SDL_SCANCODE_Z, false));             /* its down was ours */
    CHECK(!key(SDLK_z, SDL_SCANCODE_Z, true));             /* neutral: back to the game */
    CHECK(!key(SDLK_z, SDL_SCANCODE_Z, false));
}

static void test_mouse_capture_and_drain(void) {
    begin(true);
    CHECK(!filt(mouse_ev(SDL_BUTTON_LEFT, true)));         /* game owns this click */
    OPEN();
    CHECK(!filt(mouse_ev(SDL_BUTTON_LEFT, false)));        /* so it gets the release */
    CHECK(filt(mouse_ev(SDL_BUTTON_RIGHT, true)));         /* captured while open */
    OPEN();
    CHECK(!dev_menu_is_open());
    CHECK(filt(mouse_ev(SDL_BUTTON_LEFT, true)));          /* right still held: drain */
    CHECK(filt(mouse_ev(SDL_BUTTON_RIGHT, false)));
    CHECK(filt(mouse_ev(SDL_BUTTON_LEFT, false)));
    CHECK(!filt(mouse_ev(SDL_BUTTON_LEFT, true)));
    CHECK(!filt(mouse_ev(SDL_BUTTON_LEFT, false)));
}

static void test_same_pad_combo(void) {
    begin(true);
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, true)));
    CHECK(!dev_menu_is_open());
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, true)));
    CHECK(dev_menu_is_open());
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, false)));
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, false)));
    CHECK(queued_replays() == 0);                          /* a chord never reaches the game */
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, true)));
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, true)));
    CHECK(!dev_menu_is_open());                            /* either order closes */
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, false));
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, false));
    CHECK(queued_replays() == 0);

    /* Buttons on two pads never combine; each lone press is replayed. */
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, true)));
    CHECK(filt(btn_ev(8, SDL_CONTROLLER_BUTTON_START, true)));
    CHECK(!dev_menu_is_open());
    CHECK(filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, false)));
    CHECK(filt(btn_ev(8, SDL_CONTROLLER_BUTTON_START, false)));
    CHECK(queued_replays() == 4);
    {
        SDL_Event ev;
        int passed = 0;
        while (SDL_PollEvent(&ev)) passed += !dev_menu_filter_event(&ev, NULL);
        CHECK(passed == 4);                                /* replays pass the filter */
    }
    CHECK(pad_tap(9, SDL_CONTROLLER_BUTTON_START));        /* lone Start: game gets a tap */
    CHECK(queued_replays() == 2);
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);

    /* The game's view of the pad: reserved Back/Start while armed, the whole
     * pad (analog pointer too) while open or draining, nothing otherwise. */
    CHECK(g_pad_mask == 0);
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, true));
    CHECK(g_pad_mask == (1u << SDL_CONTROLLER_BUTTON_BACK));
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, true));
    CHECK(dev_menu_is_open() && g_pad_mask == 0xFFFFFFFFu);
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_START, false));
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_BACK, false));
    CHECK(g_pad_mask == 0xFFFFFFFFu);
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_A, true));        /* held into the close */
    OPEN();
    CHECK(!dev_menu_is_open() && g_pad_mask == 0xFFFFFFFFu);
    filt(btn_ev(7, SDL_CONTROLLER_BUTTON_A, false));
    CHECK(g_pad_mask == 0);
}

static void test_pad_navigation_and_drain(void) {
    begin(true);
    filt(btn_ev(3, SDL_CONTROLLER_BUTTON_BACK, true));
    filt(btn_ev(3, SDL_CONTROLLER_BUTTON_START, true));
    filt(btn_ev(3, SDL_CONTROLLER_BUTTON_START, false));
    filt(btn_ev(3, SDL_CONTROLLER_BUTTON_BACK, false));
    CHECK(dev_menu_is_open());
    CHECK(pad_tap(3, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && dev_menu_cursor() == 1);
    CHECK(pad_tap(3, SDL_CONTROLLER_BUTTON_DPAD_UP) && dev_menu_cursor() == 0);
    CHECK(filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 20000)) && dev_menu_cursor() == 1);
    CHECK(filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 32000)) && dev_menu_cursor() == 1);
    CHECK(filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 0)));
    CHECK(filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 20000)) && dev_menu_cursor() == 2);
    CHECK(filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, -20000)) && dev_menu_cursor() == 1);
    filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 0));
    CHECK(pad_tap(3, SDL_CONTROLLER_BUTTON_A));
    CHECK(!strcmp(dev_menu_page_title(), "Finish Area"));
    CHECK(pad_tap(3, SDL_CONTROLLER_BUTTON_B));
    CHECK(!strcmp(dev_menu_page_title(), "DEV MENU"));
    /* Hold X, close from the keyboard: the pad drains before play resumes. */
    CHECK(filt(btn_ev(3, SDL_CONTROLLER_BUTTON_X, true)));
    OPEN();
    CHECK(!dev_menu_is_open());
    CHECK(!filt(axis_ev(3, SDL_CONTROLLER_AXIS_LEFTY, 20000)));  /* closed: stick is the game's */
    CHECK(filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, true)));
    CHECK(filt(btn_ev(3, SDL_CONTROLLER_BUTTON_X, false)));
    CHECK(filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, false)));
    CHECK(!filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, true)));
    CHECK(!filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, false)));
    /* The game's own held button keeps its release across an open/close. */
    CHECK(!filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, true)));
    OPEN();
    CHECK(!filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, false)));
    OPEN();
    /* Removal clears state. */
    {
        SDL_Event rm; memset(&rm, 0, sizeof(rm));
        filt(btn_ev(3, SDL_CONTROLLER_BUTTON_Y, true));
        rm.type = SDL_CONTROLLERDEVICEREMOVED; rm.cdevice.which = 3;
        CHECK(!filt(rm));
        CHECK(!filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, true)));
        filt(btn_ev(3, SDL_CONTROLLER_BUTTON_A, false));
    }
}

static void test_fast_forward(void) {
    begin(true);
    CHECK(!tap(SDLK_F6, SDL_SCANCODE_F6));                 /* retail key: not ours */
    CHECK(!tap(SDLK_F7, SDL_SCANCODE_F7));
    CHECK(dev_menu_guest_frames_per_present() == 1);
    dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE);
    CHECK(dev_menu_guest_frames_per_present() == 2 && !dev_menu_unpaced());
    dev_menu_input_event(DEV_MENU_IN_FF_SPEED); CHECK(dev_menu_guest_frames_per_present() == 4);
    dev_menu_input_event(DEV_MENU_IN_FF_SPEED); CHECK(dev_menu_guest_frames_per_present() == 8);
    dev_menu_input_event(DEV_MENU_IN_FF_SPEED); CHECK(dev_menu_unpaced());
    dev_menu_input_event(DEV_MENU_IN_FF_SPEED_RESET);
    CHECK(dev_menu_guest_frames_per_present() == 2 && !dev_menu_unpaced());
    dev_menu_input_event(DEV_MENU_IN_FF_TOGGLE);
    CHECK(dev_menu_guest_frames_per_present() == 1);
    CHECK(filt(btn_ev(4, SDL_CONTROLLER_BUTTON_RIGHTSTICK, true)));
    CHECK(dev_menu_guest_frames_per_present() == 2);
    CHECK(filt(btn_ev(4, SDL_CONTROLLER_BUTTON_RIGHTSTICK, false)));
    CHECK(dev_menu_guest_frames_per_present() == 1);
    CHECK(pad_tap(4, SDL_CONTROLLER_BUTTON_LEFTSTICK));
    CHECK(dev_menu_guest_frames_per_present() == 2);
    CHECK(pad_tap(4, SDL_CONTROLLER_BUTTON_LEFTSTICK));
    CHECK(dev_menu_guest_frames_per_present() == 1);
    /* Removing a pad mid-hold releases the hold. */
    CHECK(filt(btn_ev(4, SDL_CONTROLLER_BUTTON_RIGHTSTICK, true)));
    {
        SDL_Event rm; memset(&rm, 0, sizeof(rm));
        rm.type = SDL_CONTROLLERDEVICEREMOVED; rm.cdevice.which = 4;
        filt(rm);
    }
    CHECK(dev_menu_guest_frames_per_present() == 1);
    /* Options rows drive the same state. */
    OPEN(); UP(); ENTER();
    DOWN(); ENTER();
    CHECK(!strcmp(dev_menu_row_label(1), "Fast-forward speed: 4x"));
    UP(); ENTER();
    CHECK(!strcmp(dev_menu_row_label(0), "Fast-forward: ON"));
    CHECK(dev_menu_guest_frames_per_present() == 4);
    CHECK(!dev_menu_cheats_marker());                      /* fast-forward is not a cheat */
}

static void test_refusals_and_options(void) {
    begin(true);
    dev_menu_input_event(DEV_MENU_IN_QUICK_SAVE);
    CHECK(strstr(dev_menu_toast(), "Quick save: not available"));
    dev_menu_input_event(DEV_MENU_IN_QUICK_LOAD);
    CHECK(strstr(dev_menu_toast(), "Quick load"));
    dev_menu_input_event(DEV_MENU_IN_GOD);
    CHECK(strstr(dev_menu_toast(), "God mode"));
    dev_menu_input_event(DEV_MENU_IN_RECORD);
    CHECK(strstr(dev_menu_toast(), "Record video"));
    CHECK(!tap(SDLK_F11, SDL_SCANCODE_F11));               /* unbound: passes through */
    CHECK(!dev_menu_cheats_marker() && g_shot_calls == 0);
    for (int i = 0; i < 400; ++i) dev_menu_frame(i);
    CHECK(dev_menu_toast()[0] == '\0');                    /* toasts expire */

    CHECK(!tap(SDLK_F10, SDL_SCANCODE_F10));               /* retail key: not ours */
    dev_menu_input_event(DEV_MENU_IN_SCREENSHOT);
    CHECK(g_shot_calls == 0);                              /* taken after the present */
    dev_menu_after_present();
    CHECK(g_shot_calls == 1 && !strncmp(g_shot_path, "test-shots/xanth-", 17));
    CHECK(g_shot_pixel == 0x285078FFu);                    /* closed: the plain frame */
    CHECK(strstr(dev_menu_toast(), "Screenshot saved"));
    dev_menu_after_present();
    CHECK(g_shot_calls == 1);
    OPEN();
    dev_menu_input_event(DEV_MENU_IN_SCREENSHOT);
    dev_menu_after_present();
    CHECK(g_shot_calls == 2 && g_shot_pixel != 0x285078FFu);  /* open: menu composited */
    OPEN();
    remove("test-shots");

    OPEN(); UP(); ENTER();
    CHECK(!strcmp(dev_menu_page_title(), "Options"));
    DOWN(); DOWN(); DOWN();
    CHECK(!strcmp(dev_menu_row_label(dev_menu_cursor()), "Toggle fullscreen"));
    ENTER(); CHECK(g_fullscreen_calls == 1);
    DOWN();
    CHECK(!strcmp(dev_menu_row_label(dev_menu_cursor()), "CRT scanlines: OFF"));
    ENTER();
    CHECK(g_scanline_calls == 1);
    CHECK(!strcmp(dev_menu_row_label(dev_menu_cursor()), "CRT scanlines: ON"));
    UP(); UP(); UP(); UP();
    ENTER();
    CHECK(!strcmp(dev_menu_row_label(0), "Fast-forward: ON"));
    CHECK(dev_menu_guest_frames_per_present() == 2);
}

static void test_key_script(void) {
    SDL_setenv("XANTH_DEV_KEYS", "5:OPEN,6:DOWN,7:BOGUS,9:ENTER,12:ESC,12:ESC,20:COMBO", 1);
    begin(true);
    SDL_setenv("XANTH_DEV_KEYS", "", 1);
    for (long long f = 0; f < 5; ++f) dev_menu_frame(f);
    CHECK(!dev_menu_is_open());
    dev_menu_frame(5); CHECK(dev_menu_is_open());
    dev_menu_frame(6); CHECK(dev_menu_cursor() == 1);
    dev_menu_frame(9); CHECK(!strcmp(dev_menu_page_title(), "Finish Area"));
    dev_menu_frame(12); CHECK(!dev_menu_is_open());        /* two ESCs on one frame */
    dev_menu_frame(25); CHECK(!dev_menu_is_open());        /* skipped frames never fire late */
}

static void test_renderer_overlay(void) {
    static uint32_t shown[320 * 200], soft[320 * 200];
    const uint32_t bg = 0x285078FFu;                       /* RGBA8888 40,80,120 */
    hal_video_viewport vp = { 0, 0, 320, 200 };
    SDL_Window *win;
    SDL_Renderer *r;
    int worst = 0;
    CHECK(SDL_InitSubSystem(SDL_INIT_VIDEO) == 0);
    win = SDL_CreateWindow("dev menu test", 0, 0, 320, 200, SDL_WINDOW_HIDDEN);
    CHECK(win);
    r = SDL_CreateRenderer(win, -1, SDL_RENDERER_SOFTWARE);
    CHECK(r);
    begin(true);
    SDL_SetRenderDrawColor(r, 40, 80, 120, 255);
    SDL_RenderClear(r);
    dev_menu_render(r, &vp, NULL);                         /* closed: draws nothing */
    CHECK(SDL_RenderReadPixels(r, NULL, SDL_PIXELFORMAT_RGBA8888, shown, 320 * 4) == 0);
    for (int i = 0; i < 320 * 200; ++i) CHECK(shown[i] == bg);

    OPEN();
    SDL_RenderClear(r);
    dev_menu_render(r, &vp, NULL);
    CHECK(SDL_RenderReadPixels(r, NULL, SDL_PIXELFORMAT_RGBA8888, shown, 320 * 4) == 0);
    for (int i = 0; i < 320 * 200; ++i) soft[i] = bg;
    dev_menu_draw(soft, 320, 200, NULL);
    CHECK(shown[100 * 320 + 200] != bg);                   /* inside the shaded panel */
    for (int i = 0; i < 320 * 200; ++i)
        for (int sh = 8; sh <= 24; sh += 8) {
            int d = (int)((shown[i] >> sh) & 0xFF) - (int)((soft[i] >> sh) & 0xFF);
            if (d < 0) d = -d;
            if (d > worst) worst = d;
        }
    CHECK(worst <= 2);                                     /* same image, blend rounding only */
    OPEN();
    dev_menu_shutdown();                                   /* releases the layer texture */
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow(win);
}

#if SDL_VERSION_ATLEAST(2, 24, 0)
static void pump(long long *frame) {
    hal_input_poll(NULL, NULL, NULL, NULL);
    dev_menu_frame((*frame)++);
    hal_input_poll(NULL, NULL, NULL, NULL);
}

static void test_virtual_pad_hotplug(void) {
    SDL_VirtualJoystickDesc desc;
    SDL_Joystick *js;
    long long frame = 0;
    int index;
    begin(true);
    memset(&desc, 0, sizeof(desc));
    desc.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
    desc.type = SDL_JOYSTICK_TYPE_GAMECONTROLLER;
    desc.naxes = SDL_CONTROLLER_AXIS_MAX;
    desc.nbuttons = SDL_CONTROLLER_BUTTON_MAX;
    desc.button_mask = (1u << SDL_CONTROLLER_BUTTON_MAX) - 1;
    desc.axis_mask = (1u << SDL_CONTROLLER_AXIS_MAX) - 1;
    desc.vendor_id = 0x17ef; desc.product_id = 0x6182;
    desc.name = "Dev menu held-at-connect fixture";
    index = SDL_JoystickAttachVirtualEx(&desc);
    CHECK(index >= 0);
    js = SDL_JoystickOpen(index);
    CHECK(js);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    SDL_JoystickUpdate();
    pump(&frame); pump(&frame);                            /* ADDED -> our handle opens */

    OPEN();
    CHECK(dev_menu_is_open() && dev_menu_cursor() == 0);
    /* Connected with A held: the pad cannot operate the menu until neutral. */
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_DPAD_DOWN, 1) == 0);
    pump(&frame);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_DPAD_DOWN, 0) == 0);
    pump(&frame);
    CHECK(dev_menu_cursor() == 0);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_A, 0) == 0);
    pump(&frame);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_DPAD_DOWN, 1) == 0);
    pump(&frame);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_DPAD_DOWN, 0) == 0);
    pump(&frame);
    CHECK(dev_menu_cursor() == 1);                         /* neutral: now it navigates */

    /* Same-pad combo through the real SDL path. */
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_BACK, 1) == 0);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_START, 1) == 0);
    pump(&frame);
    CHECK(!dev_menu_is_open());
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_BACK, 0) == 0);
    CHECK(SDL_JoystickSetVirtualButton(js, SDL_CONTROLLER_BUTTON_START, 0) == 0);
    pump(&frame);

    /* Removal, then the keyboard still drives the menu. */
    CHECK(SDL_JoystickDetachVirtual(index) == 0);
    SDL_JoystickClose(js);
    pump(&frame); pump(&frame);
    OPEN(); DOWN();
    CHECK(dev_menu_is_open() && dev_menu_cursor() == 2);
    OPEN();
    CHECK(!dev_menu_is_open());
}
#endif


static bool review_idle, review_modal;
static bool review_field(void) { return review_idle; }
static bool review_dialog(void) { return review_modal; }
static void review_key(uint8_t scan, uint8_t ascii) { (void)scan; (void)ascii; }
static SDL_Event touch_ev(Uint32 type, SDL_FingerID finger) {
    SDL_Event e; memset(&e, 0, sizeof(e)); e.type = type;
    e.tfinger.touchId = 1; e.tfinger.fingerId = finger; return e;
}
static void test_touch_capture(void) {
    begin(true);
    CHECK(!filt(touch_ev(SDL_FINGERDOWN, 1)));
    OPEN();
    CHECK(!filt(touch_ev(SDL_FINGERUP, 1))); /* game-owned release */
    CHECK(filt(touch_ev(SDL_FINGERDOWN, 2)));
    CHECK(filt(touch_ev(SDL_FINGERMOTION, 2)));
    ESC();
    CHECK(filt(touch_ev(SDL_FINGERUP, 2))); /* menu-owned release after closing */
    CHECK(!filt(touch_ev(SDL_FINGERDOWN, 3)));
    CHECK(!filt(touch_ev(SDL_FINGERUP, 3)));
}
static void test_restore_capture_and_same_second_save(void) {
    char ck[] = "/tmp/xanth-menu-ck-XXXXXX", sv[] = "/tmp/xanth-menu-sv-XXXXXX";
    char path[256], msg[160]; FILE *f;
    CHECK(mkdtemp(ck) && mkdtemp(sv));
    snprintf(path, sizeof(path), "%s/home.SAV", ck); f = fopen(path, "w"); CHECK(f); fputs("h", f); fclose(f);
    snprintf(path, sizeof(path), "%s/checkpoints.txt", ck); f = fopen(path, "w"); CHECK(f);
    fputs("home\thome\tMundania\tHouse\tBedroom\t1\t"
          "aaa9402664f1a41f40ebbc52c9993eb66aeb366602958fdfaa283b71e64db123\n", f); fclose(f);
    begin(true); dev_menu_shutdown();
    dev_menu_host host = {0}; host.field_idle = review_field; host.game_modal = review_dialog;
    host.post_key = review_key; host.set_pad_mask = stub_mask;
    snprintf(host.checkpoint_dir, sizeof(host.checkpoint_dir), "%s", ck);
    snprintf(host.save_dir, sizeof(host.save_dir), "%s", sv);
    dev_menu_start(&host); review_idle = true; review_modal = false;
    CHECK(dev_warp_request(0, msg, sizeof(msg)));
    CHECK(key(SDLK_w, SDL_SCANCODE_W, true));
    CHECK(filt(mouse_ev(SDL_BUTTON_LEFT, true)));
    CHECK(filt(btn_ev(123, SDL_CONTROLLER_BUTTON_A, true)));
    CHECK(filt(touch_ev(SDL_FINGERDOWN, 4)));
    SDL_Event motion = {0}; motion.type = SDL_MOUSEMOTION; CHECK(filt(motion));
    dev_menu_frame(0); CHECK(g_pad_mask == 0xFFFFFFFFu);
    review_idle = false; review_modal = true;
    for (int i = 1; i <= 40; ++i) dev_menu_frame(i);
    review_idle = true; review_modal = false;
    for (int i = 41; i <= 70; ++i) dev_menu_frame(i);
    CHECK(!dev_warp_active() && dev_warp_used());
    CHECK(key(SDLK_w, SDL_SCANCODE_W, false));
    CHECK(filt(mouse_ev(SDL_BUTTON_LEFT, false)));
    CHECK(filt(btn_ev(123, SDL_CONTROLLER_BUTTON_A, false)));
    CHECK(filt(touch_ev(SDL_FINGERUP, 4)));
    snprintf(path, sizeof(path), "%s/XANTH000.SAV", sv); CHECK(access(path, F_OK) != 0);
    f = fopen(path, "w"); CHECK(f); fputs("new player save", f); fclose(f);
    for (int i = 71; i <= 150; ++i) dev_menu_frame(i);
    CHECK(strstr(dev_menu_toast(), "this save may not match"));
    dev_menu_shutdown();
    remove(path); snprintf(path, sizeof(path), "%s/xanth-dev-menu.log", sv); remove(path);
    snprintf(path, sizeof(path), "%s/home.SAV", ck); remove(path);
    snprintf(path, sizeof(path), "%s/checkpoints.txt", ck); remove(path);
    rmdir(ck); rmdir(sv);
}

int main(void) {
    SDL_setenv("SDL_VIDEODRIVER", "dummy", 1);
    SDL_setenv("XANTH_DEV_KEYS", "", 1);
    CHECK(SDL_Init(SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) == 0);
    test_resolution();
    test_disabled_is_inert();
    test_all_off_identity();
    test_navigation();
    test_keyboard_capture_and_drain();
    test_mouse_capture_and_drain();
    test_touch_capture();
    test_restore_capture_and_same_second_save();
    test_same_pad_combo();
    test_pad_navigation_and_drain();
    test_fast_forward();
    test_refusals_and_options();
    test_key_script();
    test_renderer_overlay();
#if SDL_VERSION_ATLEAST(2, 24, 0)
    test_virtual_pad_hotplug();
#endif
    dev_menu_shutdown();
    dev_menu_reset_for_tests();
    SDL_Quit();
    puts("dev menu tests passed");
    return 0;
}
