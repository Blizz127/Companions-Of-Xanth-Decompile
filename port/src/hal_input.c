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

void hal_input_init(void) {
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
}

void hal_input_shutdown(void) {
    /* Clean up input resources */
}

/* -------------------------------------------------------------------------
 * INT 33h Mouse Implementation
 * ------------------------------------------------------------------------- */
void hal_mouse_reset(int *status, int *num_buttons) {
    g_mouse.virt_x = 320;
    g_mouse.virt_y = 100;
    g_mouse.screen_x = 160;
    g_mouse.screen_y = 100;
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
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            last_key = 27; /* Escape */
            break;

        case SDL_KEYDOWN: {
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

        case SDL_MOUSEMOTION: {
            int vp_x = 0, vp_y = 0, vp_w = 0, vp_h = 0;
            hal_video_get_viewport(&vp_x, &vp_y, &vp_w, &vp_h);

            if (vp_w > 0 && vp_h > 0) {
                int vx = event.motion.x - vp_x;
                int vy = event.motion.y - vp_y;
                if (vx < 0) vx = 0;
                if (vy < 0) vy = 0;
                if (vx >= vp_w) vx = vp_w - 1;
                if (vy >= vp_h) vy = vp_h - 1;

                int sx = (vx * HAL_VIDEO_WIDTH) / vp_w;
                int sy = (vy * HAL_VIDEO_HEIGHT) / vp_h;
                if (sx < 0) sx = 0;
                if (sx >= HAL_VIDEO_WIDTH) sx = HAL_VIDEO_WIDTH - 1;
                if (sy < 0) sy = 0;
                if (sy >= HAL_VIDEO_HEIGHT) sy = HAL_VIDEO_HEIGHT - 1;

                g_mouse.screen_x = sx;
                g_mouse.screen_y = sy;
                g_mouse.virt_x = sx * 2;
                g_mouse.virt_y = sy;
            }
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            bool down = (event.type == SDL_MOUSEBUTTONDOWN);
            uint8_t btn_mask = 0;
            if (event.button.button == SDL_BUTTON_LEFT) btn_mask = HAL_MOUSE_BTN_LEFT;
            else if (event.button.button == SDL_BUTTON_RIGHT) btn_mask = HAL_MOUSE_BTN_RIGHT;
            else if (event.button.button == SDL_BUTTON_MIDDLE) btn_mask = HAL_MOUSE_BTN_MIDDLE;

            if (down) g_mouse.buttons |= btn_mask;
            else g_mouse.buttons &= ~btn_mask;
            break;
        }
        }
    }
#endif

    if (mouse_x) *mouse_x = g_mouse.screen_x;
    if (mouse_y) *mouse_y = g_mouse.screen_y;
    if (mouse_buttons) *mouse_buttons = g_mouse.buttons;
    if (key_code) *key_code = last_key;
}
