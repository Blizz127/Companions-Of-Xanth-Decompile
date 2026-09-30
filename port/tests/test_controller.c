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
    SDL_setenv("SDL_GAMECONTROLLER_IGNORE_DEVICES", "0x28de/0x1205,0x28de/0x1206,0x17ef/0x6182,0x17ef/0xabcd,0xbeef/0x1234", 1);
    SDL_setenv("SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT", "0x28de/0x1205,0x17ef/0x6182", 1);
    SDL_setenv("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD", "1", 1);
    hal_input_prepare_gamepad(false);
    CHECK(strstr(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES"), "0x17ef/0x6182") != NULL);
    hal_input_prepare_gamepad(true);
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES"), "0xbeef/0x1234"));
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT"), ""));
    CHECK(!strcmp(SDL_getenv("SDL_GAMECONTROLLER_ALLOW_STEAM_VIRTUAL_GAMEPAD"), "1"));
    CHECK(SDL_WasInit(0) == 0); /* Hint preparation does not initialize SDL. */
    CHECK(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) == 0);
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
    pad(id, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(1); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    pad(id, SDL_CONTROLLER_BUTTON_A, 0); CHECK(buttons() == HAL_MOUSE_BTN_LEFT);
    mouse(0); CHECK(buttons() == 0);
    pad(id + 999, SDL_CONTROLLER_BUTTON_A, 1); CHECK(buttons() == 0);
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
