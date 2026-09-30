#ifndef PORT_HAL_H
#define PORT_HAL_H

#include "port_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Video Subsystem API (Mode 13h 320x200 8bpp)
 * ------------------------------------------------------------------------- */
#define HAL_VIDEO_WIDTH       320
#define HAL_VIDEO_HEIGHT      200
#define HAL_VIDEO_FRAME_SIZE  (HAL_VIDEO_WIDTH * HAL_VIDEO_HEIGHT) /* 64,000 bytes */
#define HAL_VIDEO_PALETTE_NUM 256

bool hal_video_init(int scale, bool fullscreen, bool headless, bool enable_cycling);
typedef enum {
    HAL_VIDEO_PRESENT_ASPECT_4_3 = 0, /* DOS pixel aspect correction */
    HAL_VIDEO_PRESENT_PIXEL_INTEGER = 1 /* square pixels, integer scale */
} hal_video_present_mode;
typedef struct {
    int x, y, width, height;
} hal_video_viewport;
/* Pure geometry shared by the renderer and asset-free HAL checks. */
hal_video_viewport hal_video_compute_viewport(int window_width, int window_height,
                                               hal_video_present_mode mode);
void hal_video_set_present_mode(hal_video_present_mode mode);
void hal_video_set_filter(bool crt_scanlines, bool linear_filter);
void hal_video_set_window_size(int width, int height);
void hal_video_toggle_fullscreen(void);
void hal_video_toggle_crt(void);
void hal_video_shutdown(void);
void hal_video_toggle_controller_help(void);
void hal_video_set_active_buffer(int target); /* 0: screen 0xA000, 1: backbuffer */
uint8_t *hal_video_get_screen_buffer(void);
uint8_t *hal_video_get_back_buffer(void);
uint8_t *hal_video_get_active_buffer(void);
void hal_video_flip(void);
bool hal_video_blit(int x, int y, int w, int h, const uint8_t *src, int stride);
void hal_video_set_palette_entry(uint8_t index, uint8_t r6, uint8_t g6, uint8_t b6);
void hal_video_set_palette(const uint8_t *rgb_triplets, int start, int count);
void hal_video_cycle_palette(int start_reg, int count);
void hal_video_wait_vsync(void);
void hal_video_get_viewport(int *x, int *y, int *w, int *h);
/* SDL mouse points are window coordinates; presentation uses drawable pixels. */
bool hal_video_map_window_point(int window_w, int window_h, int output_w, int output_h,
    hal_video_present_mode mode, int window_x, int window_y, int *screen_x, int *screen_y);
bool hal_video_map_touch(float x, float y, int *screen_x, int *screen_y);
bool hal_video_map_mouse(int window_x, int window_y, int *screen_x, int *screen_y);
void hal_video_mouse_window_event(uint32_t window_id, bool inside);
uint64_t hal_video_get_frame_count(void);
bool hal_video_save_bmp(const char *path);

/* -------------------------------------------------------------------------
 * Audio Subsystem API (OPL3, Sound Blaster, VOC, RealSound, SDL2 Mixer)
 * ------------------------------------------------------------------------- */
bool hal_audio_init(void);
void hal_audio_shutdown(void);
/* Optional diagnostic capture of the final mixed SDL output; off by default. */
bool hal_audio_capture_wav_start(const char *path);
void hal_audio_write_opl(uint16_t reg, uint8_t val);
uint8_t hal_audio_read_opl_status(void);
void hal_audio_render_opl(int16_t *stereo_out, uint32_t num_frames);
bool hal_audio_play_rs(const uint8_t *data, size_t len);
bool hal_audio_play_voc(const uint8_t *data, size_t len);
bool hal_audio_play_sound_file(const char *filename);
void hal_audio_set_volume(uint8_t master, uint8_t music, uint8_t sfx, uint8_t voice);
bool hal_audio_enable_fluidsynth(const char *soundfont_path);
void hal_audio_tick(void);
void hal_audio_dma_submit_block(const uint8_t *pcm_mono_8bit, uint32_t count, uint32_t sample_rate);

/* Sound Blaster DSP emulation */
void hal_audio_dsp_reset(void);
void hal_audio_dsp_write(uint16_t port, uint8_t val);
uint8_t hal_audio_dsp_read(uint16_t port);

/* Roland MT-32 MPU-401 UART emulation */
uint8_t hal_audio_mpu_read_status(void);
uint8_t hal_audio_mpu_read_data(void);
void hal_audio_mpu_write_cmd(uint8_t cmd);
void hal_audio_mpu_write_data(uint8_t data);

/* -------------------------------------------------------------------------
 * Input Subsystem API (INT 33h Mouse & INT 16h Keyboard)
 * ------------------------------------------------------------------------- */
#define HAL_MOUSE_BTN_LEFT    0x01
#define HAL_MOUSE_BTN_RIGHT   0x02
#define HAL_MOUSE_BTN_MIDDLE  0x04

/* SDL types are opaque here, so stub clients need no SDL dependency. */
typedef union SDL_Event SDL_Event;
typedef struct SDL_Renderer SDL_Renderer;
void hal_input_set_event_filter(bool (*fn)(const SDL_Event *, void *), void *user);
/* Mask uses SDL_CONTROLLER_BUTTON_* bit indices, not DOS mouse bits.
 * UINT32_MAX captures the entire pad, including analog pointer movement. */
void hal_input_set_pad_button_mask(uint32_t mask);
void hal_video_set_overlay(void (*fn)(SDL_Renderer *, const hal_video_viewport *, void *), void *user);
void hal_input_init(void);
/* Call before SDL initialization when controller input is requested. */
void hal_input_prepare_gamepad(bool enabled);
void hal_input_enable_gamepad(bool enabled);
void hal_input_enable_hotkeys(bool enabled);
int hal_input_take_hotkey(void);
/* Optional host gestures. Consumers validate live guest state before acting. */
typedef enum {
    HAL_CONTROLLER_NONE = 0, HAL_CONTROLLER_SNAP,
    HAL_CONTROLLER_PREVIOUS_VERB, HAL_CONTROLLER_NEXT_VERB
} hal_controller_action;
void hal_input_enable_guest_ui_actions(bool enabled);
hal_controller_action hal_input_take_controller_action(void);
void hal_input_shutdown(void);
typedef struct { int x, y, buttons; } hal_pointer_event;
void hal_input_enable_pointer_events(bool enabled);
bool hal_input_take_pointer_event(hal_pointer_event *event);
void hal_input_poll(int *mouse_x, int *mouse_y, int *mouse_buttons, int *key_code);

/* Mouse API (INT 33h) */
void hal_mouse_reset(int *status, int *num_buttons);
void hal_mouse_show(void);
void hal_mouse_hide(void);
void hal_mouse_get_state(int *virt_x, int *virt_y, int *buttons);
void hal_mouse_set_position(int virt_x, int virt_y);
void hal_mouse_set_h_range(int min_x, int max_x);
void hal_mouse_set_v_range(int min_y, int max_y);

/* Keyboard API (INT 16h) */
bool     hal_keyboard_push(uint8_t scancode, uint8_t ascii);
uint16_t hal_keyboard_read(void);              /* AH=00h: Pop key (blocking) */
bool     hal_keyboard_peek(uint16_t *out_key); /* AH=01h: Check key (non-blocking) */
uint8_t  hal_keyboard_get_shift_flags(void);   /* AH=02h: Read shift status */

/* -------------------------------------------------------------------------
 * Filesystem & Configuration API
 * ------------------------------------------------------------------------- */
typedef struct {
    char mouse[64];
    char gamedata[260];
    char savedata[260];
    char music[64];
    char sound[64];
} legend_ini_t;

void hal_fs_init(const char *cli_data_path, const char *cli_save_path);
bool hal_fs_parse_ini(const char *ini_path, legend_ini_t *config);
bool hal_fs_find_file(const char *base_dir, const char *rel_path, char *out_path, size_t max_len);
bool hal_fs_resolve_gamedata(const char *filename, char *out_path, size_t max_len);
bool hal_fs_resolve_savedata(const char *filename, char *out_path, size_t max_len);
bool hal_fs_get_save_path(int slot, char *out_path, size_t max_len);

/* DOS File I/O Compatibility Layer (INT 21h emulation) */
int  dos_open(const char *path, int mode);
int  dos_create(const char *path);
int  dos_read(int fd, void far *buffer, unsigned int bytes);
int  dos_write(int fd, const void far *buffer, unsigned int bytes);
long dos_lseek(int fd, unsigned int origin, unsigned long offset);
int  dos_close(int fd);
long dos_tell(int fd);

#ifdef __cplusplus
}
#endif

#endif /* PORT_HAL_H */
