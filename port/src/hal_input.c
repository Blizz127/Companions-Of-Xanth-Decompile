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

/* -------------------------------------------------------------------------
 * INT 33h Mouse State
 * ------------------------------------------------------------------------- */
typedef struct {
    int virt_x;     /* 0..639 (virtual X) */
    int virt_y;     /* 0..199 (virtual Y) */
    int screen_x;   /* 0..319 (logical screen X) */
    int screen_y;   /* 0..199 (logical screen Y) */
    int buttons;    /* bit 0: left (0x01), bit 1: right (0x02), bit 2: middle (0x04) */
    bool visible;
    int min_x, max_x;
    int min_y, max_y;
} mouse_state_t;

static mouse_state_t g_mouse;
static int g_mouse_buttons, g_gamepad_buttons, g_touch_buttons;
/* Keep complete presses even when SDL delivers DOWN and UP in one poll. */
#define POINTER_QUEUE_CAPACITY 1024
static hal_pointer_event g_pointer_queue[POINTER_QUEUE_CAPACITY];
static bool g_pointer_motion[POINTER_QUEUE_CAPACITY];
static unsigned g_pointer_head, g_pointer_count;
static bool g_pointer_events;
static hal_pointer_event g_pointer_last;
void hal_input_enable_pointer_events(bool enabled) {
    g_pointer_events = enabled;
    g_pointer_head = g_pointer_count = 0;
    g_pointer_last = (hal_pointer_event){g_mouse.screen_x,g_mouse.screen_y,g_mouse.buttons};
    if (enabled) { g_pointer_queue[0] = g_pointer_last; g_pointer_motion[0] = false; g_pointer_count = 1; }
}
bool hal_input_take_pointer_event(hal_pointer_event *event) {
    if (!event || !g_pointer_count) return false;
    *event = g_pointer_queue[g_pointer_head];
    g_pointer_head = (g_pointer_head + 1) % POINTER_QUEUE_CAPACITY;
    --g_pointer_count;
    return true;
}
static void record_pointer(void) {
    g_mouse.buttons = g_mouse_buttons | g_gamepad_buttons | g_touch_buttons;
    hal_pointer_event now = {g_mouse.screen_x,g_mouse.screen_y,g_mouse.buttons};
    if (!g_pointer_events || (now.x == g_pointer_last.x && now.y == g_pointer_last.y &&
                              now.buttons == g_pointer_last.buttons)) return;
    bool motion = now.buttons == g_pointer_last.buttons;
    unsigned tail = (g_pointer_head + g_pointer_count - 1) % POINTER_QUEUE_CAPACITY;
    if (motion && g_pointer_count && g_pointer_motion[tail]) {
        g_pointer_queue[tail] = now;
        g_pointer_last = now;
    } else if (g_pointer_count < POINTER_QUEUE_CAPACITY) {
        tail = (g_pointer_head + g_pointer_count++) % POINTER_QUEUE_CAPACITY;
        g_pointer_queue[tail] = now;
        g_pointer_motion[tail] = motion;
        g_pointer_last = now;
    }
}


/* -------------------------------------------------------------------------
 * INT 16h BIOS Keyboard FIFO Ring Buffer
 * ------------------------------------------------------------------------- */
#define KEYBOARD_QUEUE_CAPACITY 16

typedef struct {
    uint8_t scancode;
    uint8_t ascii;
} key_entry_t;

typedef struct {
    key_entry_t entries[KEYBOARD_QUEUE_CAPACITY];
    int head;
    int tail;
    int count;
    uint8_t shift_flags;
} keyboard_state_t;

static keyboard_state_t g_keyboard;
static bool (*g_event_filter)(const SDL_Event *, void *);
static void *g_event_filter_user;
static uint32_t g_pad_button_mask;
void hal_input_set_event_filter(bool (*fn)(const SDL_Event *, void *), void *user) {
    g_event_filter = fn; g_event_filter_user = user;
}
void hal_input_set_pad_button_mask(uint32_t mask) { g_pad_button_mask = mask; }
static bool g_gamepad_enabled;
static bool g_hotkeys_enabled;
static int g_pending_hotkey;
#ifndef XANTH_HEADLESS_STUB
#define MAX_GAMEPADS 16
typedef struct {
    SDL_GameController *controller;
    SDL_JoystickID id;
    unsigned buttons;
    bool ready, steam_virtual;
} gamepad_slot;
static gamepad_slot g_pads[MAX_GAMEPADS];
static int g_active_pad = -1;
static SDL_FingerID g_touch_finger;
static SDL_TouchID g_touch_device;
static bool g_touch_active;
static Uint32 g_pad_ticks;
static int g_pad_fraction_x, g_pad_fraction_y;
static int axis_step(int value, int maximum_speed, Uint32 elapsed, int *fraction) {
    int magnitude = abs(value) - 12000;
    if (magnitude <= 0) { *fraction = 0; return 0; }
    int velocity = (int)((int64_t)magnitude * magnitude * maximum_speed / (20768LL * 20768LL));
    if (value < 0) velocity = -velocity;
    *fraction += velocity * (int)elapsed;
    int step = *fraction / 1000;
    *fraction -= step * 1000;
    return step;
}

static void close_gamepads(void) {
    for (int i = 0; i < MAX_GAMEPADS; ++i) {
        if (g_pads[i].controller) SDL_GameControllerClose(g_pads[i].controller);
        memset(&g_pads[i], 0, sizeof(g_pads[i]));
    }
    g_active_pad = -1;
}

static int find_gamepad(SDL_JoystickID id) {
    for (int i = 0; i < MAX_GAMEPADS; ++i)
        if (g_pads[i].controller && g_pads[i].id == id) return i;
    return -1;
}

static bool gamepad_has_input(const gamepad_slot *pad) {
    if (pad->buttons) return true;
    for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; ++b)
        if (SDL_GameControllerGetButton(pad->controller, (SDL_GameControllerButton)b)) return true;
    return abs(SDL_GameControllerGetAxis(pad->controller, SDL_CONTROLLER_AXIS_LEFTX)) > 12000 ||
           abs(SDL_GameControllerGetAxis(pad->controller, SDL_CONTROLLER_AXIS_LEFTY)) > 12000;
}

static void reconcile_gamepads(void) {
    for (int i = 0; i < MAX_GAMEPADS; ++i) {
        gamepad_slot *pad = &g_pads[i];
        if (!pad->controller) continue;
        if (!SDL_GameControllerGetAttached(pad->controller)) {
            SDL_GameControllerClose(pad->controller);
            memset(pad, 0, sizeof(*pad));
            if (g_active_pad == i) g_active_pad = -1;
        } else if (!pad->ready && !gamepad_has_input(pad)) pad->ready = true;
    }
    for (int j = 0; j < SDL_NumJoysticks(); ++j) {
        if (!SDL_IsGameController(j) || find_gamepad(SDL_JoystickGetDeviceInstanceID(j)) >= 0) continue;
        int i;
        for (i = 0; i < MAX_GAMEPADS && g_pads[i].controller; ++i) {}
        if (i == MAX_GAMEPADS) break;
        SDL_GameController *controller = SDL_GameControllerOpen(j);
        if (!controller) continue;
        gamepad_slot *pad = &g_pads[i];
        pad->controller = controller;
        pad->id = SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(controller));
        const char *name = SDL_GameControllerName(controller);
#if SDL_VERSION_ATLEAST(2, 0, 6)
        pad->steam_virtual = SDL_GameControllerGetVendor(controller) == 0x28de &&
                            SDL_GameControllerGetProduct(controller) == 0x11ff;
#endif
        if (name && strstr(name, "Steam Virtual")) pad->steam_virtual = true;
        pad->ready = !gamepad_has_input(pad);
    }
}

static bool select_gamepad(int index) {
    gamepad_slot *pad = &g_pads[index];
    if (!pad->ready) return false;
    if (pad->steam_virtual) {
        for (int i = 0; i < MAX_GAMEPADS; ++i)
            if (i != index && g_pads[i].controller && g_pads[i].ready &&
                !g_pads[i].steam_virtual && gamepad_has_input(&g_pads[i])) return false;
    }
    if (g_active_pad != index) {
        g_active_pad = index;
        unsigned vendor = 0, product = 0;
#if SDL_VERSION_ATLEAST(2, 0, 6)
        vendor = SDL_GameControllerGetVendor(pad->controller);
        product = SDL_GameControllerGetProduct(pad->controller);
#endif
        fprintf(stderr, "[DEV_MENU] pad: %s vid:pid=%04x:%04x instance=%d reason=%s\n",
                SDL_GameControllerName(pad->controller), vendor, product, (int)pad->id,
                pad->steam_virtual ? "virtual-only" : "physical-active");
    }
    return true;
}
#endif

void hal_input_init(void) {
    g_mouse_buttons = g_gamepad_buttons = 0;
    g_event_filter = NULL; g_event_filter_user = NULL; g_pad_button_mask = 0;
    memset(&g_mouse, 0, sizeof(g_mouse));
    g_mouse.virt_x = 320;
    g_mouse.virt_y = 100;
    g_mouse.screen_x = 160;
    g_mouse.screen_y = 100;
    g_mouse.min_x = 0;
    g_mouse.max_x = 639;
    g_mouse.min_y = 0;
    g_mouse.max_y = 199;
    g_mouse.visible = true;

    memset(&g_keyboard, 0, sizeof(g_keyboard));
    g_gamepad_enabled = false;
    g_touch_buttons = 0;
#ifndef XANTH_HEADLESS_STUB
    g_touch_active = false;
    g_pad_ticks = SDL_GetTicks(); g_pad_fraction_x = g_pad_fraction_y = 0;
#endif
    hal_input_enable_pointer_events(false);
    g_hotkeys_enabled = false;
    g_pending_hotkey = 0;
#ifndef XANTH_HEADLESS_STUB
    close_gamepads();
#endif
}

void hal_input_enable_hotkeys(bool enabled) {
    g_hotkeys_enabled = enabled;
}

int hal_input_take_hotkey(void) {
    int hotkey = g_pending_hotkey;
    g_pending_hotkey = 0;
    return hotkey;
}

void hal_input_prepare_gamepad(bool enabled) {
#ifndef XANTH_HEADLESS_STUB
    if (!enabled) return;
    SDL_setenv("SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS", "1", 1);
    SDL_SetHintWithPriority(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1", SDL_HINT_OVERRIDE);
    const char *keys[] = {"SDL_GAMECONTROLLER_IGNORE_DEVICES", "SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"};
    for (unsigned i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i) {
        const char *value = SDL_getenv(keys[i]);
        if (!value || !*value) continue;
        char *before = SDL_strdup(value), *copy = SDL_strdup(value);
        char *after = SDL_calloc(strlen(value) + 1, 1);
        if (!before || !copy || !after) { SDL_free(before); SDL_free(copy); SDL_free(after); continue; }
        char *cursor = copy;
        while (cursor && *cursor) {
            char *entry = cursor, *comma = strchr(cursor, ',');
            if (comma) { *comma = 0; cursor = comma + 1; } else cursor = NULL;
            unsigned vid = 0, pid = 0;
            bool handheld = sscanf(entry, " %x/%x", &vid, &pid) == 2 &&
                (vid == 0x17ef || (vid == 0x28de && (pid == 0x1205 || pid == 0x1206 || (pid >= 0x12f0 && pid <= 0x12ff))));
            if (!handheld) { if (*after) strcat(after, ","); strcat(after, entry); }
        }
        if (strcmp(before, after)) {
            SDL_setenv(keys[i], after, 1);
            fprintf(stderr, "[DEV_MENU] %s: %s -> %s\n", keys[i], before, after);
        }
        SDL_free(before); SDL_free(copy); SDL_free(after);
    }
#else
    (void)enabled;
#endif
}

void hal_input_enable_gamepad(bool enabled) {
    g_gamepad_enabled = enabled;
#ifndef XANTH_HEADLESS_STUB
    if (!enabled) {
        close_gamepads();
        g_gamepad_buttons = 0;
        g_mouse.buttons = g_mouse_buttons;
        return;
    }
    hal_input_prepare_gamepad(true);
    if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0 && SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0) {
        fprintf(stderr, "[DEV_MENU] controller unavailable: %s\n", SDL_GetError());
        return;
    }
    reconcile_gamepads();
#else
    (void)enabled;
#endif
}

void hal_input_shutdown(void) {
    /* Release controller-owned clicks while preserving a held physical mouse. */
    g_gamepad_enabled = false;
    g_gamepad_buttons = 0;
    g_mouse.buttons = g_mouse_buttons;
#ifndef XANTH_HEADLESS_STUB
    close_gamepads();
#endif
}

/* -------------------------------------------------------------------------
 * INT 33h Mouse Implementation
 * ------------------------------------------------------------------------- */
void hal_mouse_reset(int *status, int *num_buttons) {
    g_mouse.virt_x = 320;
    g_mouse.virt_y = 100;
    g_mouse.screen_x = 160;
    g_mouse.screen_y = 100;
    g_mouse_buttons = g_gamepad_buttons = 0;
    g_mouse.buttons = 0;
    g_mouse.visible = false;
    g_mouse.min_x = 0;
    g_mouse.max_x = 639;
    g_mouse.min_y = 0;
    g_mouse.max_y = 199;

    if (status) *status = -1; /* -1 (0xFFFF) = mouse driver installed */
    if (num_buttons) *num_buttons = 2; /* 2 buttons */
}

void hal_mouse_show(void) {
    g_mouse.visible = true;
}

void hal_mouse_hide(void) {
    g_mouse.visible = false;
}

void hal_mouse_get_state(int *virt_x, int *virt_y, int *buttons) {
    if (virt_x) *virt_x = g_mouse.virt_x;
    if (virt_y) *virt_y = g_mouse.virt_y;
    if (buttons) *buttons = g_mouse.buttons;
}

void hal_mouse_set_position(int virt_x, int virt_y) {
    if (virt_x < g_mouse.min_x) virt_x = g_mouse.min_x;
    if (virt_x > g_mouse.max_x) virt_x = g_mouse.max_x;
    if (virt_y < g_mouse.min_y) virt_y = g_mouse.min_y;
    if (virt_y > g_mouse.max_y) virt_y = g_mouse.max_y;

    g_mouse.virt_x = virt_x;
    g_mouse.virt_y = virt_y;
    g_mouse.screen_x = virt_x >> 1;
    g_mouse.screen_y = virt_y;
}

void hal_mouse_set_h_range(int min_x, int max_x) {
    g_mouse.min_x = min_x;
    g_mouse.max_x = max_x;
}

void hal_mouse_set_v_range(int min_y, int max_y) {
    g_mouse.min_y = min_y;
    g_mouse.max_y = max_y;
}

/* -------------------------------------------------------------------------
 * INT 16h Keyboard Implementation
 * ------------------------------------------------------------------------- */
bool hal_keyboard_push(uint8_t scancode, uint8_t ascii) {
    if (g_keyboard.count >= KEYBOARD_QUEUE_CAPACITY) {
        return false; /* Buffer full: drop key */
    }

    g_keyboard.entries[g_keyboard.tail].scancode = scancode;
    g_keyboard.entries[g_keyboard.tail].ascii = ascii;
    g_keyboard.tail = (g_keyboard.tail + 1) % KEYBOARD_QUEUE_CAPACITY;
    g_keyboard.count++;
    return true;
}

uint16_t hal_keyboard_read(void) {
    if (g_keyboard.count == 0) {
        return 0;
    }

    key_entry_t entry = g_keyboard.entries[g_keyboard.head];
    g_keyboard.head = (g_keyboard.head + 1) % KEYBOARD_QUEUE_CAPACITY;
    g_keyboard.count--;

    /* Pack (scancode << 8) | ascii */
    return (uint16_t)(((uint16_t)entry.scancode << 8) | (uint16_t)entry.ascii);
}

bool hal_keyboard_peek(uint16_t *out_key) {
    if (g_keyboard.count == 0) {
        if (out_key) *out_key = 0;
        return false;
    }

    key_entry_t entry = g_keyboard.entries[g_keyboard.head];
    if (out_key) {
        *out_key = (uint16_t)(((uint16_t)entry.scancode << 8) | (uint16_t)entry.ascii);
    }
    return true;
}

uint8_t hal_keyboard_get_shift_flags(void) {
    return g_keyboard.shift_flags;
}

/* -------------------------------------------------------------------------
 * Scancode Translation Helper
 * ------------------------------------------------------------------------- */
#ifndef XANTH_HEADLESS_STUB
static void translate_sdl_key(const SDL_KeyboardEvent *key, uint8_t *out_scan, uint8_t *out_ascii) {
    uint8_t scan = 0;
    uint8_t ascii = 0;

    switch (key->keysym.sym) {
    case SDLK_ESCAPE:    scan = 0x01; ascii = 0x1B; break;
    case SDLK_1:         scan = 0x02; ascii = '1'; break;
    case SDLK_2:         scan = 0x03; ascii = '2'; break;
    case SDLK_3:         scan = 0x04; ascii = '3'; break;
    case SDLK_4:         scan = 0x05; ascii = '4'; break;
    case SDLK_5:         scan = 0x06; ascii = '5'; break;
    case SDLK_6:         scan = 0x07; ascii = '6'; break;
    case SDLK_7:         scan = 0x08; ascii = '7'; break;
    case SDLK_8:         scan = 0x09; ascii = '8'; break;
    case SDLK_9:         scan = 0x0A; ascii = '9'; break;
    case SDLK_0:         scan = 0x0B; ascii = '0'; break;
    case SDLK_MINUS:     scan = 0x0C; ascii = '-'; break;
    case SDLK_EQUALS:    scan = 0x0D; ascii = '='; break;
    case SDLK_BACKSPACE: scan = 0x0E; ascii = 0x08; break;
    case SDLK_TAB:       scan = 0x0F; ascii = 0x09; break;
    case SDLK_q:         scan = 0x10; ascii = 'q'; break;
    case SDLK_w:         scan = 0x11; ascii = 'w'; break;
    case SDLK_e:         scan = 0x12; ascii = 'e'; break;
    case SDLK_r:         scan = 0x13; ascii = 'r'; break;
    case SDLK_t:         scan = 0x14; ascii = 't'; break;
    case SDLK_y:         scan = 0x15; ascii = 'y'; break;
    case SDLK_u:         scan = 0x16; ascii = 'u'; break;
    case SDLK_i:         scan = 0x17; ascii = 'i'; break;
    case SDLK_o:         scan = 0x18; ascii = 'o'; break;
    case SDLK_p:         scan = 0x19; ascii = 'p'; break;
    case SDLK_RETURN:    scan = 0x1C; ascii = 0x0D; break;
    case SDLK_LCTRL:     scan = 0x1D; ascii = 0x00; break;
    case SDLK_a:         scan = 0x1E; ascii = 'a'; break;
    case SDLK_s:         scan = 0x1F; ascii = 's'; break;
    case SDLK_d:         scan = 0x20; ascii = 'd'; break;
    case SDLK_f:         scan = 0x21; ascii = 'f'; break;
    case SDLK_g:         scan = 0x22; ascii = 'g'; break;
    case SDLK_h:         scan = 0x23; ascii = 'h'; break;
    case SDLK_j:         scan = 0x24; ascii = 'j'; break;
    case SDLK_k:         scan = 0x25; ascii = 'k'; break;
    case SDLK_l:         scan = 0x26; ascii = 'l'; break;
    case SDLK_LSHIFT:    scan = 0x2A; ascii = 0x00; break;
    case SDLK_z:         scan = 0x2C; ascii = 'z'; break;
    case SDLK_x:         scan = 0x2D; ascii = 'x'; break;
    case SDLK_c:         scan = 0x2E; ascii = 'c'; break;
    case SDLK_v:         scan = 0x2F; ascii = 'v'; break;
    case SDLK_b:         scan = 0x30; ascii = 'b'; break;
    case SDLK_n:         scan = 0x31; ascii = 'n'; break;
    case SDLK_m:         scan = 0x32; ascii = 'm'; break;
    case SDLK_RSHIFT:    scan = 0x36; ascii = 0x00; break;
    case SDLK_LALT:      scan = 0x38; ascii = 0x00; break;
    case SDLK_SPACE:     scan = 0x39; ascii = ' '; break;
    case SDLK_CAPSLOCK:  scan = 0x3A; ascii = 0x00; break;
    case SDLK_F1:        scan = 0x3B; ascii = 0x00; break;
    case SDLK_F2:        scan = 0x3C; ascii = 0x00; break;
    case SDLK_F3:        scan = 0x3D; ascii = 0x00; break;
    case SDLK_F4:        scan = 0x3E; ascii = 0x00; break;
    case SDLK_F5:        scan = 0x3F; ascii = 0x00; break;
    case SDLK_F6:        scan = 0x40; ascii = 0x00; break;
    case SDLK_F7:        scan = 0x41; ascii = 0x00; break;
    case SDLK_F8:        scan = 0x42; ascii = 0x00; break;
    case SDLK_F9:        scan = 0x43; ascii = 0x00; break;
    case SDLK_F10:       scan = 0x44; ascii = 0x00; break;
    case SDLK_UP:        scan = 0x48; ascii = 0x00; break;
    case SDLK_LEFT:      scan = 0x4B; ascii = 0x00; break;
    case SDLK_RIGHT:     scan = 0x4D; ascii = 0x00; break;
    case SDLK_DOWN:      scan = 0x50; ascii = 0x00; break;
    default:
        if (key->keysym.sym >= 32 && key->keysym.sym < 127) {
            ascii = (uint8_t)key->keysym.sym;
            scan = 0x39; /* Generic */
        }
        break;
    }

    /* Shift modification */
    if (key->keysym.mod & KMOD_SHIFT) {
        if (ascii >= 'a' && ascii <= 'z') {
            ascii = (uint8_t)(ascii - 'a' + 'A');
        }
    }

    *out_scan = scan;
    *out_ascii = ascii;
}
#endif

/* -------------------------------------------------------------------------
 * Event Polling Loop
 * ------------------------------------------------------------------------- */
void hal_input_poll(int *mouse_x, int *mouse_y, int *mouse_buttons, int *key_code) {
    int last_key = 0;

#ifndef XANTH_HEADLESS_STUB
    SDL_Event event;
    while ((!g_pointer_events || g_pointer_count < POINTER_QUEUE_CAPACITY - 2) && SDL_PollEvent(&event)) {
        if (g_event_filter && g_event_filter(&event, g_event_filter_user)) continue;
        switch (event.type) {
        case SDL_QUIT:
            last_key = 27; /* Escape */
            break;

        case SDL_KEYDOWN: {
            if (g_hotkeys_enabled && (event.key.keysym.sym == SDLK_F11 ||
                                      event.key.keysym.sym == SDLK_F10)) {
                if (event.key.repeat == 0)
                    g_pending_hotkey = event.key.keysym.sym == SDLK_F11 ? 1 : 2;
                break; /* Host shortcuts, including repeats, stay out of BIOS FIFO. */
            }
            uint8_t scan = 0, ascii = 0;
            translate_sdl_key(&event.key, &scan, &ascii);
            if (scan != 0 || ascii != 0) {
                hal_keyboard_push(scan, ascii);
                last_key = ascii ? ascii : scan;
            }
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                last_key = 27;
            }

            /* Shift flags update */
            SDL_Keymod mod = SDL_GetModState();
            g_keyboard.shift_flags = 0;
            if (mod & KMOD_RSHIFT) g_keyboard.shift_flags |= 0x01;
            if (mod & KMOD_LSHIFT) g_keyboard.shift_flags |= 0x02;
            if (mod & KMOD_CTRL)   g_keyboard.shift_flags |= 0x04;
            if (mod & KMOD_ALT)    g_keyboard.shift_flags |= 0x08;
            if (mod & KMOD_CAPS)   g_keyboard.shift_flags |= 0x40;
            break;
        }

        case SDL_CONTROLLERDEVICEADDED:
        case SDL_CONTROLLERDEVICEREMOVED:
            if (g_gamepad_enabled) reconcile_gamepads();
            break;
        case SDL_CONTROLLERAXISMOTION: {
            int index = find_gamepad(event.caxis.which);
            if (g_gamepad_enabled && index >= 0 &&
                (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX || event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) &&
                abs(event.caxis.value) > 12000) (void)select_gamepad(index);
            break;
        }

        case SDL_CONTROLLERBUTTONDOWN:
        case SDL_CONTROLLERBUTTONUP: {
            int index = find_gamepad(event.cbutton.which);
            if (!g_gamepad_enabled || index < 0 || event.cbutton.button >= SDL_CONTROLLER_BUTTON_MAX) break;
            bool down = event.type == SDL_CONTROLLERBUTTONDOWN;
            if (down) g_pads[index].buttons |= 1u << event.cbutton.button;
            else g_pads[index].buttons &= ~(1u << event.cbutton.button);
            if (down) (void)select_gamepad(index);
            if (!g_pads[index].ready || index != g_active_pad ||
                (g_pad_button_mask & (1u << event.cbutton.button))) break;
            unsigned held = g_pads[index].buttons & ~g_pad_button_mask;
            g_gamepad_buttons = ((held & (1u << SDL_CONTROLLER_BUTTON_A)) ? HAL_MOUSE_BTN_LEFT : 0) |
                                ((held & (1u << SDL_CONTROLLER_BUTTON_X)) ? HAL_MOUSE_BTN_RIGHT : 0);
            switch (event.cbutton.button) {
            case SDL_CONTROLLER_BUTTON_A:
                if (down) g_gamepad_buttons |= HAL_MOUSE_BTN_LEFT;
                else g_gamepad_buttons &= ~HAL_MOUSE_BTN_LEFT;
                break;
            case SDL_CONTROLLER_BUTTON_X:
                if (down) g_gamepad_buttons |= HAL_MOUSE_BTN_RIGHT;
                else g_gamepad_buttons &= ~HAL_MOUSE_BTN_RIGHT;
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
                if (down) (void)hal_keyboard_push(0x48,0);
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                if (down) (void)hal_keyboard_push(0x50,0);
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                if (down) (void)hal_keyboard_push(0x4B,0);
                break;
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                if (down) (void)hal_keyboard_push(0x4D,0);
                break;
            case SDL_CONTROLLER_BUTTON_BACK:
                if (down) g_pending_hotkey = 3;
                break;
            case SDL_CONTROLLER_BUTTON_START:
                if (down) (void)hal_keyboard_push(0x1C,0x0D);
                break;
            default: break;
            }
            break;
        }

        case SDL_WINDOWEVENT:
            if (event.window.event == SDL_WINDOWEVENT_ENTER)
                hal_video_mouse_window_event(event.window.windowID, true);
            else if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED &&
                     SDL_GetMouseFocus() == SDL_GetWindowFromID(event.window.windowID))
                hal_video_mouse_window_event(event.window.windowID, true);
            else if (event.window.event == SDL_WINDOWEVENT_LEAVE || event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                hal_video_mouse_window_event(event.window.windowID, false);
                if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                    g_mouse_buttons = g_touch_buttons = 0;
                    g_touch_active = false;
                }
            }
            break;
        case SDL_FINGERDOWN:
        case SDL_FINGERMOTION:
        case SDL_FINGERUP: {
            if (event.type == SDL_FINGERDOWN && !g_touch_active) {
                g_touch_active = true; g_touch_finger = event.tfinger.fingerId;
                g_touch_device = event.tfinger.touchId;
            }
            if (!g_touch_active || g_touch_finger != event.tfinger.fingerId ||
                g_touch_device != event.tfinger.touchId) break;
            int sx, sy;
            if (hal_video_map_touch(event.tfinger.x, event.tfinger.y, &sx, &sy))
                hal_mouse_set_position(sx * 2, sy);
            g_touch_buttons = event.type == SDL_FINGERUP ? 0 : HAL_MOUSE_BTN_LEFT;
            if (event.type == SDL_FINGERUP) g_touch_active = false;
            break;
        }
        case SDL_MOUSEMOTION: {
            if (event.motion.which == SDL_TOUCH_MOUSEID) break;
            g_pad_fraction_x = g_pad_fraction_y = 0;
            int sx, sy;
            if (hal_video_map_mouse(event.motion.x, event.motion.y, &sx, &sy))
                hal_mouse_set_position(sx * 2, sy);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            if (event.button.which == SDL_TOUCH_MOUSEID) break;
            bool down = (event.type == SDL_MOUSEBUTTONDOWN);
            int sx, sy;
            if (hal_video_map_mouse(event.button.x, event.button.y, &sx, &sy))
                hal_mouse_set_position(sx * 2, sy);
            uint8_t btn_mask = 0;
            if (event.button.button == SDL_BUTTON_LEFT) btn_mask = HAL_MOUSE_BTN_LEFT;
            else if (event.button.button == SDL_BUTTON_RIGHT) btn_mask = HAL_MOUSE_BTN_RIGHT;
            else if (event.button.button == SDL_BUTTON_MIDDLE) btn_mask = HAL_MOUSE_BTN_MIDDLE;

            if (down) g_mouse_buttons |= btn_mask;
            else g_mouse_buttons &= ~btn_mask;
            break;
        }
        }
        record_pointer();
    }
    Uint32 now = SDL_GetTicks();
    Uint32 elapsed = now - g_pad_ticks;
    g_pad_ticks = now;
    if (elapsed > 50) elapsed = 50;
    if (g_gamepad_enabled) reconcile_gamepads();
    g_gamepad_buttons = 0;
    if (g_active_pad >= 0 && g_pads[g_active_pad].controller && g_pad_button_mask != UINT32_MAX) {
        gamepad_slot *pad = &g_pads[g_active_pad];
        if ((pad->buttons & ~g_pad_button_mask) & (1u << SDL_CONTROLLER_BUTTON_A)) g_gamepad_buttons |= HAL_MOUSE_BTN_LEFT;
        if ((pad->buttons & ~g_pad_button_mask) & (1u << SDL_CONTROLLER_BUTTON_X)) g_gamepad_buttons |= HAL_MOUSE_BTN_RIGHT;
        int dx=SDL_GameControllerGetAxis(pad->controller,SDL_CONTROLLER_AXIS_LEFTX);
        int dy=SDL_GameControllerGetAxis(pad->controller,SDL_CONTROLLER_AXIS_LEFTY);
        int step_x = axis_step(dx, 300, elapsed, &g_pad_fraction_x);
        int step_y = axis_step(dy, 240, elapsed, &g_pad_fraction_y);
        if (step_x || step_y) {
            int nx=g_mouse.screen_x+step_x, ny=g_mouse.screen_y+step_y;
            if (nx<0) nx=0;
            if (nx>=HAL_VIDEO_WIDTH) nx=HAL_VIDEO_WIDTH-1;
            if (ny<0) ny=0;
            if (ny>=HAL_VIDEO_HEIGHT) ny=HAL_VIDEO_HEIGHT-1;
            hal_mouse_set_position(nx*2, ny);
        }
    }
#endif

    record_pointer();
    if (mouse_x) *mouse_x = g_mouse.screen_x;
    if (mouse_y) *mouse_y = g_mouse.screen_y;
    if (mouse_buttons) *mouse_buttons = g_mouse.buttons;
    if (key_code) *key_code = last_key;
}
