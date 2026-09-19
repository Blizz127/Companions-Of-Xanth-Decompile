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
void hal_video_shutdown(void);
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
uint64_t hal_video_get_frame_count(void);
bool hal_video_save_bmp(const char *path);

/* -------------------------------------------------------------------------
 * Audio Subsystem API (OPL3, Sound Blaster, VOC, RealSound, SDL2 Mixer)
 * ------------------------------------------------------------------------- */
bool hal_audio_init(void);
void hal_audio_shutdown(void);
void hal_audio_write_opl(uint16_t reg, uint8_t val);
uint8_t hal_audio_read_opl_status(void);
void hal_audio_render_opl(int16_t *stereo_out, uint32_t num_frames);
bool hal_audio_play_rs(const uint8_t *data, size_t len);
bool hal_audio_play_voc(const uint8_t *data, size_t len);
bool hal_audio_play_sound_file(const char *filename);
void hal_audio_set_volume(uint8_t master, uint8_t music, uint8_t sfx, uint8_t voice);
void hal_audio_tick(void);

/* Sound Blaster DSP emulation */
void hal_audio_dsp_reset(void);
void hal_audio_dsp_write(uint16_t port, uint8_t val);
uint8_t hal_audio_dsp_read(uint16_t port);

/* Roland MT-32 MPU-401 UART emulation */
uint8_t hal_audio_mpu_read_status(void);
void hal_audio_mpu_write_cmd(uint8_t cmd);
void hal_audio_mpu_write_data(uint8_t data);

/* -------------------------------------------------------------------------
 * Input Subsystem API (INT 33h Mouse & INT 16h Keyboard)
 * ------------------------------------------------------------------------- */
#define HAL_MOUSE_BTN_LEFT    0x01
#define HAL_MOUSE_BTN_RIGHT   0x02
#define HAL_MOUSE_BTN_MIDDLE  0x04

void hal_input_init(void);
void hal_input_shutdown(void);
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
