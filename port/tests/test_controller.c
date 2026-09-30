/* Asset-free regression of controller hotplug and shared pointer buttons. */
#include "port_hal.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(c) do { if (!(c)) { fprintf(stderr, "line %d: %s\n", __LINE__, #c); exit(1); } } while (0)
/* Input-only fixture: no window required for controller/button tests. */
void hal_video_get_viewport(int *x, int *y, int *w, int *h) {
    *x = *y = 0; *w = 320; *h = 200;
}
bool hal_video_map_mouse(int x, int y, int *sx, int *sy) { *sx=x; *sy=y; return true; }
bool hal_video_map_touch(float x, float y, int *sx, int *sy) {
    *sx = (int)(x * 320); *sy = (int)(y * 200); return true;
}
void hal_video_mouse_window_event(uint32_t id, bool inside) { (void)id; (void)inside; }
static int buttons(void) {
    int b; hal_input_poll(NULL, NULL, &b, NULL); return b;
}
static void pad(SDL_JoystickID id, Uint8 button, int down) {
    SDL_Event e = {0}; e.type = down ? SDL_CONTROLLERBUTTONDOWN : SDL_CONTROLLERBUTTONUP;
    e.cbutton.which = id; e.cbutton.button = button;
    CHECK(SDL_PushEvent(&e) == 1);
}
static void mouse(int down) {
    SDL_Event e = {0}; e.type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
    e.button.button = SDL_BUTTON_LEFT; CHECK(SDL_PushEvent(&e) == 1);
}
static void mouse_at(int down, Uint8 button, int x, int y) {
    SDL_Event e = {0}; e.type = down ? SDL_MOUSEBUTTONDOWN : SDL_MOUSEBUTTONUP;
    e.button.button = button; e.button.x = x; e.button.y = y;
    CHECK(SDL_PushEvent(&e) == 1);
}
static void pointer(int x, int y, int buttons) {
    hal_pointer_event e;
    CHECK(hal_input_take_pointer_event(&e));
    CHECK(e.x == x && e.y == y && e.buttons == buttons);
}
static bool consume_input(const SDL_Event *e, void *user) {
    unsigned *counts = user;
    if (e->type == SDL_KEYDOWN) { ++counts[0]; return true; }
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN ||
        e->type == SDL_MOUSEBUTTONUP) { ++counts[1]; return true; }
    return false;
}
static void finger(Uint32 type, SDL_FingerID id, float x, float y) {
    SDL_Event e = {0}; e.type = type; e.tfinger.fingerId = id;
    e.tfinger.touchId = 1; e.tfinger.x = x; e.tfinger.y = y;
    CHECK(SDL_PushEvent(&e) == 1);
}
static void test_pointer_events_and_filter(void) {
    hal_pointer_event e;
    CHECK(!hal_input_take_pointer_event(&e)); /* Ordered delivery is opt-in. */
    hal_input_enable_pointer_events(true);
    CHECK(!hal_input_take_pointer_event(NULL)); /* Does not discard snapshot. */
    pointer(160, 100, 0); /* Consumer explicitly discards the initial snapshot. */
    CHECK(!hal_input_take_pointer_event(&e));
    mouse_at(1, SDL_BUTTON_LEFT, 20, 30);
    mouse_at(0, SDL_BUTTON_LEFT, 25, 35);
    CHECK(buttons() == 0); /* A same-poll complete click must survive. */
    pointer(20, 30, HAL_MOUSE_BTN_LEFT);
    pointer(25, 35, 0);
    CHECK(!hal_input_take_pointer_event(&e));
    mouse_at(1, SDL_BUTTON_RIGHT, 40, 45);
    mouse_at(0, SDL_BUTTON_RIGHT, 40, 45); buttons();
    pointer(40, 45, HAL_MOUSE_BTN_RIGHT); pointer(40, 45, 0);
    mouse_at(1, SDL_BUTTON_MIDDLE, 40, 45);
    mouse_at(0, SDL_BUTTON_MIDDLE, 40, 45); buttons();
    pointer(40, 45, HAL_MOUSE_BTN_MIDDLE); pointer(40, 45, 0);
    CHECK(!hal_input_take_pointer_event(&e));

    unsigned consumed[] = {0, 0};
    hal_input_set_event_filter(consume_input, consumed);
    SDL_Event event = {0}; event.type = SDL_KEYDOWN; event.key.keysym.sym = SDLK_z;
    CHECK(SDL_PushEvent(&event) == 1);
    event.type = SDL_MOUSEMOTION; event.motion.x = 90; event.motion.y = 95;
    CHECK(SDL_PushEvent(&event) == 1);
    mouse_at(1, SDL_BUTTON_LEFT, 90, 95); mouse_at(0, SDL_BUTTON_LEFT, 90, 95);
    int x, y, b, key;
    hal_input_poll(&x, &y, &b, &key);
    CHECK(consumed[0] == 1 && consumed[1] == 3);
    CHECK(x == 40 && y == 45 && b == 0 && key == 0);
    CHECK(!hal_keyboard_peek(NULL)); CHECK(!hal_input_take_pointer_event(&e));
    hal_input_set_event_filter(NULL, NULL);
    event = (SDL_Event){0}; event.type = SDL_KEYDOWN; event.key.keysym.sym = SDLK_z;
    CHECK(SDL_PushEvent(&event) == 1); buttons();
    CHECK(hal_keyboard_read() == 0x2c7a); /* Ordinary input resumes afterward. */

    finger(SDL_FINGERDOWN, 7, 0.25f, 0.5f);
    finger(SDL_FINGERUP, 7, 0.25f, 0.5f);
    /* SDL often follows a touch with synthesized mouse events; do not double click. */
    event = (SDL_Event){0}; event.type = SDL_MOUSEBUTTONDOWN;
    event.button.which = SDL_TOUCH_MOUSEID; event.button.button = SDL_BUTTON_LEFT;
    event.button.x = 1; event.button.y = 2; CHECK(SDL_PushEvent(&event) == 1);
    event.type = SDL_MOUSEBUTTONUP; CHECK(SDL_PushEvent(&event) == 1);
    CHECK(buttons() == 0);
    pointer(80, 100, HAL_MOUSE_BTN_LEFT); pointer(80, 100, 0);
    CHECK(!hal_input_take_pointer_event(&e));
    finger(SDL_FINGERDOWN, 7, 0.25f, 0.5f);
    finger(SDL_FINGERDOWN, 8, 0.75f, 0.25f);
    finger(SDL_FINGERMOTION, 8, 0.5f, 0.25f);
    finger(SDL_FINGERUP, 8, 0.5f, 0.25f);
    CHECK(buttons() == HAL_MOUSE_BTN_LEFT); /* Only the first finger owns click. */
    pointer(80, 100, HAL_MOUSE_BTN_LEFT);
    CHECK(!hal_input_take_pointer_event(&e));
    finger(SDL_FINGERUP, 7, 0.25f, 0.5f); CHECK(buttons() == 0);
    pointer(80, 100, 0); CHECK(!hal_input_take_pointer_event(&e));
    hal_input_enable_pointer_events(false);
    mouse_at(1, SDL_BUTTON_LEFT, 80, 100); mouse_at(0, SDL_BUTTON_LEFT, 80, 100);
    CHECK(buttons() == 0); CHECK(!hal_input_take_pointer_event(&e));
}
#if SDL_VERSION_ATLEAST(2, 24, 0)
static int attach_pad(const char *name, Uint16 vendor, Uint16 product) {
    SDL_VirtualJoystickDesc desc = {0};
    desc.version = SDL_VIRTUAL_JOYSTICK_DESC_VERSION;
    desc.type = SDL_JOYSTICK_TYPE_GAMECONTROLLER;
    desc.naxes = SDL_CONTROLLER_AXIS_MAX;
    desc.nbuttons = SDL_CONTROLLER_BUTTON_MAX;
    desc.button_mask = (1u << SDL_CONTROLLER_BUTTON_MAX) - 1;
    desc.axis_mask = (1u << SDL_CONTROLLER_AXIS_MAX) - 1;
    desc.vendor_id = vendor; desc.product_id = product; desc.name = name;
    int index = SDL_JoystickAttachVirtualEx(&desc); CHECK(index >= 0); return index;
}
static void test_steam_pads(void) {
    CHECK(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) == 0);
    hal_input_init(); hal_input_enable_gamepad(true);
    int steam_index = attach_pad("Steam Virtual Gamepad", 0x28de, 0x11ff);
    int physical_index = attach_pad("Legion virtual test fixture", 0x17ef, 0x6182);
    SDL_Joystick *steam = SDL_JoystickOpen(steam_index), *physical = SDL_JoystickOpen(physical_index);
    CHECK(steam && physical); CHECK(buttons() == 0);
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    CHECK(buttons() == HAL_MOUSE_BTN_LEFT); /* Silent Steam pad never captures input. */
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_A, 0) == 0);
    CHECK(buttons() == 0);
    CHECK(SDL_JoystickSetVirtualButton(steam, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    CHECK(buttons() == HAL_MOUSE_BTN_LEFT); /* Virtual is allowed when producing alone. */
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_X, 1) == 0);
    CHECK(buttons() == HAL_MOUSE_BTN_RIGHT); /* Physical input immediately takes precedence. */
    CHECK(SDL_JoystickSetVirtualButton(steam, SDL_CONTROLLER_BUTTON_A, 0) == 0); buttons();
    CHECK(SDL_JoystickSetVirtualButton(steam, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    CHECK(buttons() == HAL_MOUSE_BTN_RIGHT); /* Producing physical pad retains precedence. */
    CHECK(SDL_JoystickSetVirtualButton(steam, SDL_CONTROLLER_BUTTON_A, 0) == 0); buttons();
    CHECK(SDL_JoystickDetachVirtual(physical_index) == 0); CHECK(buttons() == 0);
    SDL_JoystickClose(physical);
    physical_index = attach_pad("Legion reconnected held test", 0x17ef, 0x6182);
    physical = SDL_JoystickOpen(physical_index); CHECK(physical);
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    CHECK(buttons() == 0); /* Reconnected while held: must reach neutral first. */
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_A, 0) == 0); CHECK(buttons() == 0);
    CHECK(SDL_JoystickSetVirtualButton(physical, SDL_CONTROLLER_BUTTON_A, 1) == 0);
    CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    CHECK(SDL_JoystickDetachVirtual(physical_index) == 0); CHECK(buttons() == 0); SDL_JoystickClose(physical);
    CHECK(SDL_JoystickDetachVirtual(steam_index) == 0); CHECK(buttons() == 0); SDL_JoystickClose(steam);
    SDL_Event key = {0}; key.type = SDL_KEYDOWN; key.key.keysym.sym = SDLK_z;
    CHECK(SDL_PushEvent(&key) == 1); buttons(); CHECK(hal_keyboard_read() == 0x2c7a);
    hal_input_shutdown(); SDL_Quit();
}
#endif

int main(void) {
    SDL_setenv("SDL_GAMECONTROLLER_IGNORE_DEVICES", "0x28de/0x1205,0x28de/0x1206,0x17ef/0x6182,0x17ef/0xabcd,0x28de/0x12ef,0x28de/0x12f0,0x28de/0x12f8,0x28de/0x12ff,0x28de/0x1300,0xbeef/0x1234", 1);
    SDL_setenv("SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT", "0x28de/0x1205,0x17ef/0x6182,0x28de/0x12f0,0x28de/0x12ff", 1);
    SDL_setenv("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD", "1", 1);
    CHECK(SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "0"));
    hal_input_prepare_gamepad(false);
    CHECK(strstr(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES"), "0x17ef/0x6182") != NULL);
    CHECK(!strcmp(SDL_GetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS), "0"));
    hal_input_prepare_gamepad(true);
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES"), "0x28de/0x12ef,0x28de/0x1300,0xbeef/0x1234"));
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"), ""));
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD"), "1"));
    CHECK(!strcmp(SDL_GetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS), "1"));
    CHECK(SDL_WasInit(0) == 0); /* Hint preparation does not initialize SDL. */
    CHECK(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) == 0);
    hal_input_init();
    test_pointer_events_and_filter();
    hal_input_init();
    SDL_Event key = {0}; key.type = SDL_KEYDOWN; key.key.keysym.sym = SDLK_F9;
    CHECK(SDL_PushEvent(&key) == 1); buttons();
    CHECK(hal_keyboard_read() == 0x4300); /* Default still reaches the guest. */
    hal_input_enable_hotkeys(true); key.key.keysym.sym = SDLK_F10; key.key.repeat = 1;
    CHECK(SDL_PushEvent(&key) == 1); buttons();
    CHECK(hal_input_take_hotkey() == 0); CHECK(!hal_keyboard_peek(NULL));
    hal_input_enable_gamepad(true); /* Before attachment: exercise hotplug. */
    int index = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_GAMECONTROLLER, 6, 21, 0);
    CHECK(index >= 0);
    SDL_Joystick *stick = SDL_JoystickOpen(index); CHECK(stick != NULL);
    SDL_JoystickID id = SDL_JoystickInstanceID(stick);
    CHECK(buttons() == 0);
    hal_input_enable_pointer_events(true);
    pointer(160, 100, 0);
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); pad(id, SDL_CONTROLLER_BUTTON_A, 0);
    CHECK(buttons() == 0);
    pointer(160, 100, HAL_MOUSE_BTN_LEFT); pointer(160, 100, 0);
    hal_pointer_event ordered;
    CHECK(!hal_input_take_pointer_event(&ordered));
    hal_input_enable_pointer_events(false);
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    pad(id, SDL_CONTROLLER_BUTTON_A, 0); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(0); CHECK(buttons() == 0);
    pad(id + 999, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == 0);
    /* Helpers are opt-in, ordered, and never synthesize guest clicks. */
    pad(id, SDL_CONTROLLER_BUTTON_Y, 1); pad(id, SDL_CONTROLLER_BUTTON_Y, 0);
    CHECK(buttons() == 0);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_NONE);
    hal_input_enable_guest_ui_actions(true);
    pad(id, SDL_CONTROLLER_BUTTON_Y, 1); pad(id, SDL_CONTROLLER_BUTTON_Y, 1);
    pad(id, SDL_CONTROLLER_BUTTON_Y, 0);
    pad(id, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, 1); pad(id, SDL_CONTROLLER_BUTTON_LEFTSHOULDER, 0);
    pad(id, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, 1); pad(id, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, 0);
    CHECK(buttons() == 0);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_SNAP);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_PREVIOUS_VERB);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_NEXT_VERB);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_NONE);
    hal_input_set_pad_button_mask(1u << SDL_CONTROLLER_BUTTON_Y);
    pad(id, SDL_CONTROLLER_BUTTON_Y, 1); pad(id, SDL_CONTROLLER_BUTTON_Y, 0); buttons();
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_NONE);
    hal_input_set_pad_button_mask(0);
    pad(id, SDL_CONTROLLER_BUTTON_Y, 1); pad(id, SDL_CONTROLLER_BUTTON_Y, 0); buttons();
    hal_input_enable_gamepad(false);
    CHECK(hal_input_take_controller_action() == HAL_CONTROLLER_NONE);
    hal_input_enable_gamepad(true);
    hal_input_enable_guest_ui_actions(false);
    hal_input_set_pad_button_mask(1u << SDL_CONTROLLER_BUTTON_X);
    pad(id, SDL_CONTROLLER_BUTTON_X, 1); CHECK(buttons() == 0);
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    pad(id, SDL_CONTROLLER_BUTTON_A, 0); CHECK(buttons() == 0);
    pad(id, SDL_CONTROLLER_BUTTON_X, 0); CHECK(buttons() == 0);
    hal_input_set_pad_button_mask(0);
    pad(id, SDL_CONTROLLER_BUTTON_X, 1); CHECK(buttons() == HAL_MOUSE_BTN_RIGHT);
    hal_input_enable_gamepad(false); CHECK(buttons() == 0);
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == 0);
    hal_input_enable_gamepad(true);
    pad(id, SDL_CONTROLLER_BUTTON_DPAD_UP, 1); buttons();
    CHECK(hal_keyboard_read() == 0x4800);
    pad(id, SDL_CONTROLLER_BUTTON_START, 1); buttons();
    CHECK(hal_keyboard_read() == 0x1c0d);
    hal_mouse_set_h_range(100, 200); hal_mouse_set_v_range(50, 60);
    hal_mouse_set_position(200, 60);
    CHECK(SDL_JoystickSetVirtualAxis(stick, SDL_CONTROLLER_AXIS_LEFTX, 32767) == 0);
    CHECK(SDL_JoystickSetVirtualAxis(stick, SDL_CONTROLLER_AXIS_LEFTY, 32767) == 0);
    buttons();
    int x, y; hal_mouse_get_state(&x, &y, NULL); CHECK(x == 200 && y == 60);
    hal_mouse_set_h_range(0, 639); hal_mouse_set_v_range(0, 199);
    hal_mouse_set_position(320, 100);
    hal_input_set_pad_button_mask(UINT32_MAX);
    SDL_Delay(20); buttons();
    hal_mouse_get_state(&x, &y, NULL); CHECK(x == 320 && y == 100);
    hal_input_set_pad_button_mask(0);
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(1); buttons();
    CHECK(SDL_JoystickDetachVirtual(index) == 0); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(0); CHECK(buttons() == 0);
    SDL_JoystickClose(stick);
    index = SDL_JoystickAttachVirtual(SDL_JOYSTICK_TYPE_GAMECONTROLLER, 6, 21, 0);
    CHECK(index >= 0); stick = SDL_JoystickOpen(index); CHECK(stick != NULL);
    id = SDL_JoystickInstanceID(stick); buttons();
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    hal_input_enable_gamepad(false); CHECK(buttons() == 0);
    hal_input_shutdown(); SDL_JoystickClose(stick);
    CHECK(SDL_JoystickDetachVirtual(index) == 0); SDL_Quit();
#if SDL_VERSION_ATLEAST(2, 24, 0)
    test_steam_pads();
#endif
    puts("Controller hotplug, isolation, mappings, ranges and button ownership passed");
    return 0;
}
