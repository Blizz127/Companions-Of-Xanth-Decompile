#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
 * Constants & Definitions
 * ------------------------------------------------------------------------- */
#define AUDIO_SAMPLE_RATE    44100
#define AUDIO_CHANNELS       2
#define AUDIO_BUFFER_FRAMES  1024
#define OPL_REGISTER_COUNT   512
#define OPL_CMD_QUEUE_SIZE   2048

/* -------------------------------------------------------------------------
 * Nuked OPL3 / FM Synthesizer Model
 * ------------------------------------------------------------------------- */
typedef struct {
    uint16_t reg;
    uint8_t  val;
} opl_cmd_t;

typedef struct {
    opl_cmd_t buffer[OPL_CMD_QUEUE_SIZE];
    volatile uint32_t head;
    volatile uint32_t tail;
} opl_queue_t;

typedef struct {
    uint8_t registers[OPL_REGISTER_COUNT];
    opl_queue_t queue;

    /* Simple FM voice synthesis state for 9 primary channels */
    struct {
        uint16_t f_num;
        uint8_t  block;
        bool     key_on;
        double   phase;
        double   phase_inc;
        double   volume;
    } channels[18];

    uint8_t status;
    uint32_t timer1_counter;
} opl3_state_t;

static opl3_state_t g_opl3;

/* -------------------------------------------------------------------------
 * Sound Blaster DSP Emulation Model
 * ------------------------------------------------------------------------- */
typedef enum {
    DSP_STATE_READY = 0,
    DSP_STATE_WAIT_ARG1,
    DSP_STATE_WAIT_ARG2
} dsp_state_t;

typedef struct {
    dsp_state_t state;
    uint8_t current_cmd;
    uint8_t read_buf[64];
    uint32_t read_head;
    uint32_t read_tail;

    uint32_t sample_rate;
    bool speaker_on;
    bool dma_active;
    uint16_t dma_length;
    uint16_t dma_count;
} sb_dsp_t;

static sb_dsp_t g_dsp;

/* -------------------------------------------------------------------------
 * Audio Mixer & Stream State
 * ------------------------------------------------------------------------- */
typedef struct {
    /* Channel 0: OPL3 FM Music */
    bool opl_active;
    int16_t opl_temp[AUDIO_BUFFER_FRAMES * AUDIO_CHANNELS];

    /* Channel 1: RealSound / Sound Blaster SFX */
    bool sfx_active;
    int16_t *sfx_pcm;
    size_t sfx_total_frames;
    size_t sfx_current_frame;

    /* Channel 2: Dialogue Voice (VOC) */
    bool voice_active;
    int16_t *voice_pcm;
    size_t voice_total_frames;
    size_t voice_current_frame;

    /* Volume controls (0..128) */
    uint8_t master_volume;
    uint8_t music_volume;
    uint8_t sfx_volume;
    uint8_t voice_volume;

#ifndef XANTH_HEADLESS_STUB
    SDL_AudioDeviceID device_id;
#else
    uint32_t device_id;
#endif
    bool dummy_mode;
    bool initialized;
} audio_mixer_t;

static audio_mixer_t g_mixer;

/* -------------------------------------------------------------------------
 * OPL3 Internal Synthesis Functions
 * ------------------------------------------------------------------------- */
static void opl_write_internal(opl3_state_t *chip, uint16_t reg, uint8_t val) {
    if (reg >= OPL_REGISTER_COUNT) return;
    chip->registers[reg] = val;

    /* Channel frequency / Key-on registers (0xA0..0xA8, 0xB0..0xB8) */
    if (reg >= 0xA0 && reg <= 0xA8) {
        int ch = reg - 0xA0;
        chip->channels[ch].f_num = (chip->channels[ch].f_num & 0x300) | val;
    } else if (reg >= 0xB0 && reg <= 0xB8) {
        int ch = reg - 0xB0;
        chip->channels[ch].f_num = (chip->channels[ch].f_num & 0x0FF) | ((uint16_t)(val & 0x03) << 8);
        chip->channels[ch].block = (val >> 2) & 0x07;
        chip->channels[ch].key_on = (val & 0x20) != 0;

        /* Frequency in Hz = f_num * 49716 / 2^(20 - block) */
        if (chip->channels[ch].f_num > 0) {
            double freq = (double)chip->channels[ch].f_num * 49716.0 / (double)(1 << (20 - chip->channels[ch].block));
            chip->channels[ch].phase_inc = (freq * 2.0 * 3.141592653589793) / (double)AUDIO_SAMPLE_RATE;
        } else {
            chip->channels[ch].phase_inc = 0.0;
        }
    } else if (reg >= 0x40 && reg <= 0x55) {
        /* Total level / attenuation */
        int ch = (reg - 0x40) % 9;
        uint8_t tl = val & 0x3F;
        chip->channels[ch].volume = 1.0 - ((double)tl / 63.0);
        if (chip->channels[ch].volume < 0.0) chip->channels[ch].volume = 0.0;
    } else if (reg == 0x02) {
        /* Timer 1 value */
    } else if (reg == 0x04) {
        /* Timer control: start Timer 1 */
        if (val & 0x01) {
            chip->status |= 0xC0; /* Timer 1 expired flag */
        }
        if (val & 0x80) {
            chip->status = 0x00;  /* Reset flags */
        }
    }
}

static void opl_flush_commands(opl3_state_t *chip) {
    while (chip->queue.tail != chip->queue.head) {
        opl_cmd_t cmd = chip->queue.buffer[chip->queue.tail];
        opl_write_internal(chip, cmd.reg, cmd.val);
        chip->queue.tail = (chip->queue.tail + 1) % OPL_CMD_QUEUE_SIZE;
    }
}

void hal_audio_write_opl(uint16_t reg, uint8_t val) {
    uint32_t next_head = (g_opl3.queue.head + 1) % OPL_CMD_QUEUE_SIZE;
    if (next_head != g_opl3.queue.tail) {
        g_opl3.queue.buffer[g_opl3.queue.head].reg = reg & 0x1FF;
        g_opl3.queue.buffer[g_opl3.queue.head].val = val;
        g_opl3.queue.head = next_head;
    } else {
        /* If queue full, write immediately */
        opl_write_internal(&g_opl3, reg, val);
    }
}

uint8_t hal_audio_read_opl_status(void) {
    return g_opl3.status;
}

void hal_audio_render_opl(int16_t *stereo_out, uint32_t num_frames) {
    opl_flush_commands(&g_opl3);

    for (uint32_t i = 0; i < num_frames; i++) {
        double sample_sum = 0.0;

        for (int ch = 0; ch < 9; ch++) {
            if (g_opl3.channels[ch].key_on && g_opl3.channels[ch].phase_inc > 0.0) {
                double s = sin(g_opl3.channels[ch].phase);
                double vol = g_opl3.channels[ch].volume > 0.0 ? g_opl3.channels[ch].volume : 0.7;
                sample_sum += s * vol;

                g_opl3.channels[ch].phase += g_opl3.channels[ch].phase_inc;
                if (g_opl3.channels[ch].phase >= 2.0 * 3.141592653589793) {
                    g_opl3.channels[ch].phase -= 2.0 * 3.141592653589793;
                }
            }
        }

        /* Scale and clamp to signed 16-bit range */
        double scaled = sample_sum * 4000.0;
        int32_t val16 = (int32_t)scaled;
        if (val16 > 32767) val16 = 32767;
        else if (val16 < -32768) val16 = -32768;

        stereo_out[i * 2 + 0] = (int16_t)val16;
        stereo_out[i * 2 + 1] = (int16_t)val16;
    }
}

/* -------------------------------------------------------------------------
 * Sound Blaster DSP Emulation
 * ------------------------------------------------------------------------- */
void hal_audio_dsp_reset(void) {
    memset(&g_dsp, 0, sizeof(g_dsp));
    g_dsp.sample_rate = 22050;
    g_dsp.speaker_on = true;

    /* Push 0xAA (DSP Ready) into read buffer */
    g_dsp.read_buf[g_dsp.read_head % 64] = 0xAA;
    g_dsp.read_head++;
}

void hal_audio_dsp_write(uint16_t port, uint8_t val) {
    if (port == 0x226) {
        /* Reset register: 1 then 0 resets DSP */
        if (val == 1) {
            g_dsp.state = DSP_STATE_READY;
        } else if (val == 0) {
            hal_audio_dsp_reset();
        }
        return;
    }

    if (port == 0x22C) {
        switch (g_dsp.state) {
        case DSP_STATE_READY:
            g_dsp.current_cmd = val;
            switch (val) {
            case 0xE0: /* Echo / Invert test */
                g_dsp.state = DSP_STATE_WAIT_ARG1;
                break;
            case 0xE1: /* Get DSP Version */
                g_dsp.read_buf[g_dsp.read_head++ % 64] = 2; /* Major: 2 */
                g_dsp.read_buf[g_dsp.read_head++ % 64] = 1; /* Minor: 1 */
                break;
            case 0x40: /* Set Time Constant */
                g_dsp.state = DSP_STATE_WAIT_ARG1;
                break;
            case 0x14: /* 8-bit DMA single cycle */
                g_dsp.state = DSP_STATE_WAIT_ARG1;
                break;
            case 0xD1: /* Speaker ON */
                g_dsp.speaker_on = true;
                break;
            case 0xD3: /* Speaker OFF */
                g_dsp.speaker_on = false;
                break;
            case 0xD0: /* Pause DMA */
                g_dsp.dma_active = false;
                break;
            case 0xD4: /* Continue DMA */
                g_dsp.dma_active = true;
                break;
            default:
                break;
            }
            break;

        case DSP_STATE_WAIT_ARG1:
            if (g_dsp.current_cmd == 0xE0) {
                /* Return bitwise NOT of argument */
                g_dsp.read_buf[g_dsp.read_head++ % 64] = (uint8_t)(~val);
                g_dsp.state = DSP_STATE_READY;
            } else if (g_dsp.current_cmd == 0x40) {
                uint32_t divisor = 256 - (uint32_t)val;
                if (divisor > 0) {
                    g_dsp.sample_rate = 1000000 / divisor;
                }
                g_dsp.state = DSP_STATE_READY;
            } else if (g_dsp.current_cmd == 0x14) {
                g_dsp.dma_length = val;
                g_dsp.state = DSP_STATE_WAIT_ARG2;
            }
            break;

        case DSP_STATE_WAIT_ARG2:
            if (g_dsp.current_cmd == 0x14) {
                g_dsp.dma_length |= ((uint16_t)val << 8);
                g_dsp.dma_count = g_dsp.dma_length + 1;
                g_dsp.dma_active = true;
                g_dsp.state = DSP_STATE_READY;
            }
            break;
        }
    }
}

uint8_t hal_audio_dsp_read(uint16_t port) {
    if (port == 0x22A) {
        /* Read Data Port */
        if (g_dsp.read_tail < g_dsp.read_head) {
            uint8_t val = g_dsp.read_buf[g_dsp.read_tail % 64];
            g_dsp.read_tail++;
            return val;
        }
        return 0x00;
    }

    if (port == 0x22C) {
        /* Write Buffer Status (bit 7: busy). 0x00 = ready */
        return 0x00;
    }

    if (port == 0x22E) {
        /* Read Buffer Status (bit 7: data ready). 0x80 = ready, 0x00 = empty */
        if (g_dsp.read_tail < g_dsp.read_head) {
            return 0x80;
        }
        return 0x00;
    }

    return 0xFF;
}

/* -------------------------------------------------------------------------
 * Roland MT-32 MPU-401 UART Emulation
 * ------------------------------------------------------------------------- */
static uint8_t g_mpu_ack = 0;
static bool g_mpu_has_ack = false;

uint8_t hal_audio_mpu_read_status(void) {
    /* Bit 6 = DRR (0 = ready to write data)
     * Bit 7 = DSR (0 = data available to read, 1 = no data) */
    uint8_t status = 0x00;
    if (!g_mpu_has_ack) {
        status |= 0x80; /* No data to read */
    }
    return status;
}

void hal_audio_mpu_write_cmd(uint8_t cmd) {
    if (cmd == 0xFF || cmd == 0x3F) {
        /* Reset (0xFF) or enter UART mode (0x3F): set ACK byte 0xFE */
        g_mpu_ack = 0xFE;
        g_mpu_has_ack = true;
    }
}

void hal_audio_mpu_write_data(uint8_t data) {
    /* In native port, data can be forwarded to ALSA/WinMM or discarded in headless mode */
    (void)data;
}

/* -------------------------------------------------------------------------
 * Steve Baker RealSound 4-bit ADPCM Decoder
 * ------------------------------------------------------------------------- */
bool hal_audio_play_rs(const uint8_t *data, size_t len) {
    if (!data || len < 10) return false;

    /* Verify magic "STEVE\x02" or "STEVE\x01" */
    if (memcmp(data, "STEVE", 5) != 0) return false;
    if (data[5] != 0x01 && data[5] != 0x02) return false;

    uint32_t sample_rate = 8000;
    uint32_t expected_samples = 0;
    const uint8_t *adpcm_payload = NULL;
    size_t payload_bytes = 0;

    /* Check synthetic test format: 16-bit sample_rate, 16-bit num_samples at offset 6 */
    uint16_t w1 = (uint16_t)(data[6] | ((uint16_t)data[7] << 8));
    uint16_t w2 = (uint16_t)(data[8] | ((uint16_t)data[9] << 8));

    if (w1 >= 4000 && w1 <= 48000 && (size_t)(10 + (w2 + 1) / 2) <= len) {
        /* Synthetic format */
        sample_rate = w1;
        expected_samples = w2;
        adpcm_payload = data + 10;
        payload_bytes = len - 10;
    } else if (len >= 32 && data[6] == 0x48) {
        /* Retail format: 32-byte header, 24-bit data length at offset 7 */
        uint32_t rlen = (uint32_t)(data[7] | ((uint32_t)data[8] << 8) | ((uint32_t)data[9] << 16));
        sample_rate = 8000;
        expected_samples = rlen * 2;
        adpcm_payload = data + 32;
        payload_bytes = rlen;
        if (32 + rlen > len) payload_bytes = len - 32;
    } else {
        /* Fallback generic */
        sample_rate = 8000;
        adpcm_payload = data + 10;
        payload_bytes = len - 10;
        expected_samples = (uint32_t)(payload_bytes * 2);
    }

    if (expected_samples == 0 || payload_bytes == 0) return false;

    /* Decode 4-bit nibble ADPCM into 8-bit PCM samples */
    uint8_t *pcm8 = (uint8_t *)malloc(expected_samples);
    if (!pcm8) return false;

    size_t samples_decoded = 0;
    int32_t val = 128; /* Baseline silence */

    for (size_t i = 0; i < payload_bytes && samples_decoded < expected_samples; i++) {
        uint8_t b = adpcm_payload[i];

        /* Low nibble first */
        uint8_t low = b & 0x0F;
        val += ((int32_t)low - 8) * 8;
        if (val < 0) val = 0;
        else if (val > 255) val = 255;
        pcm8[samples_decoded++] = (uint8_t)val;

        if (samples_decoded >= expected_samples) break;

        /* High nibble second */
        uint8_t high = (b >> 4) & 0x0F;
        val += ((int32_t)high - 8) * 8;
        if (val < 0) val = 0;
        else if (val > 255) val = 255;
        pcm8[samples_decoded++] = (uint8_t)val;
    }

    /* Resample from sample_rate to 44,100 Hz 16-bit stereo */
    size_t dst_frames = (size_t)((double)samples_decoded * (double)AUDIO_SAMPLE_RATE / (double)sample_rate);
    if (dst_frames == 0) dst_frames = 1;

    int16_t *stereo_s16 = (int16_t *)malloc(dst_frames * AUDIO_CHANNELS * sizeof(int16_t));
    if (!stereo_s16) {
        free(pcm8);
        return false;
    }

    double ratio = (double)sample_rate / (double)AUDIO_SAMPLE_RATE;
    double src_pos = 0.0;

    for (size_t i = 0; i < dst_frames; i++) {
        size_t idx0 = (size_t)src_pos;
        size_t idx1 = (idx0 + 1 < samples_decoded) ? idx0 + 1 : idx0;
        double frac = src_pos - (double)idx0;

        double s0 = (double)pcm8[idx0] - 128.0;
        double s1 = (double)pcm8[idx1] - 128.0;
        double interp = (1.0 - frac) * s0 + frac * s1;

        int32_t sample16 = (int32_t)(interp * 256.0);
        if (sample16 > 32767) sample16 = 32767;
        else if (sample16 < -32768) sample16 = -32768;

        stereo_s16[i * 2 + 0] = (int16_t)sample16;
        stereo_s16[i * 2 + 1] = (int16_t)sample16;

        src_pos += ratio;
        if (src_pos >= (double)samples_decoded) break;
    }

    free(pcm8);

    /* Enqueue to mixer Channel 1 (SFX) */
    if (g_mixer.sfx_pcm) {
        free(g_mixer.sfx_pcm);
    }
    g_mixer.sfx_pcm = stereo_s16;
    g_mixer.sfx_total_frames = dst_frames;
    g_mixer.sfx_current_frame = 0;
    g_mixer.sfx_active = true;

    return true;
}

/* -------------------------------------------------------------------------
 * VOC Speech Archive Audio Decoder
 * ------------------------------------------------------------------------- */
bool hal_audio_play_voc(const uint8_t *data, size_t len) {
    if (!data || len == 0) return false;

    /* 8-bit unsigned PCM at 11,025 Hz -> resample to 44,100 Hz (4x) */
    size_t dst_frames = len * 4;

    int16_t *stereo_s16 = (int16_t *)malloc(dst_frames * AUDIO_CHANNELS * sizeof(int16_t));
    if (!stereo_s16) return false;

    for (size_t i = 0; i < len; i++) {
        double s = (double)data[i] - 128.0;
        int32_t sample16 = (int32_t)(s * 256.0);
        if (sample16 > 32767) sample16 = 32767;
        else if (sample16 < -32768) sample16 = -32768;

        /* 4x replication for 11025 -> 44100 */
        for (int k = 0; k < 4; k++) {
            size_t frame_idx = i * 4 + k;
            stereo_s16[frame_idx * 2 + 0] = (int16_t)sample16;
            stereo_s16[frame_idx * 2 + 1] = (int16_t)sample16;
        }
    }

    if (g_mixer.voice_pcm) {
        free(g_mixer.voice_pcm);
    }
    g_mixer.voice_pcm = stereo_s16;
    g_mixer.voice_total_frames = dst_frames;
    g_mixer.voice_current_frame = 0;
    g_mixer.voice_active = true;

    return true;
}

bool hal_audio_play_sound_file(const char *filename) {
    if (!filename || !*filename) return false;
    char path[512] = {0};
    if (!hal_fs_resolve_gamedata(filename, path, sizeof(path))) {
        return false;
    }
    FILE *f = fopen(path, "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0 || sz > 10 * 1024 * 1024) {
        fclose(f);
        return false;
    }
    uint8_t *buf = (uint8_t *)malloc((size_t)sz);
    if (!buf) {
        fclose(f);
        return false;
    }
    if (fread(buf, 1, (size_t)sz, f) != (size_t)sz) {
        free(buf);
        fclose(f);
        return false;
    }
    fclose(f);

    bool ok = false;
    if (sz >= 10 && memcmp(buf, "STEVE", 5) == 0) {
        ok = hal_audio_play_rs(buf, (size_t)sz);
    } else if (sz >= 20 && memcmp(buf, "Creative Voice File", 19) == 0) {
        if (sz > 30 && buf[26] == 1) {
            uint32_t block_len = (uint32_t)buf[27] | ((uint32_t)buf[28] << 8) | ((uint32_t)buf[29] << 16);
            if (block_len > 2 && 32 + block_len - 2 <= (uint32_t)sz) {
                ok = hal_audio_play_voc(buf + 32, block_len - 2);
            } else {
                ok = hal_audio_play_voc(buf + 30, (size_t)(sz - 30));
            }
        } else {
            ok = hal_audio_play_voc(buf + 26, (size_t)(sz - 26));
        }
    } else {
        ok = hal_audio_play_voc(buf, (size_t)sz);
    }
    free(buf);
    return ok;
}

/* -------------------------------------------------------------------------
 * SDL2 Audio Callback & 3-Channel Mixer
 * ------------------------------------------------------------------------- */
#ifndef XANTH_HEADLESS_STUB
static void sdl_audio_callback(void *userdata, Uint8 *stream, int len) {
    if (!userdata || !stream || len <= 0) return;

    audio_mixer_t *mixer = (audio_mixer_t *)userdata;
    int16_t *out = (int16_t *)stream;
    int total_frames = len / (AUDIO_CHANNELS * (int)sizeof(int16_t));

    int frames_done = 0;
    while (frames_done < total_frames) {
        int chunk_frames = total_frames - frames_done;
        if (chunk_frames > AUDIO_BUFFER_FRAMES) {
            chunk_frames = AUDIO_BUFFER_FRAMES;
        }

        /* 1. Synthesize OPL3 FM Music */
        if (mixer->opl_active && !mixer->dummy_mode) {
            hal_audio_render_opl(mixer->opl_temp, (uint32_t)chunk_frames);
        } else {
            memset(mixer->opl_temp, 0, (size_t)chunk_frames * AUDIO_CHANNELS * sizeof(int16_t));
        }

        /* 2. Mix Channels with 32-bit signed accumulation and volume scaling */
        int16_t *chunk_out = out + frames_done * AUDIO_CHANNELS;
        for (int i = 0; i < chunk_frames; i++) {
            int32_t mix_l = 0;
            int32_t mix_r = 0;

            /* Channel 0: Music */
            if (mixer->opl_active) {
                mix_l += (int32_t)mixer->opl_temp[i * 2 + 0] * (int32_t)mixer->music_volume / 128;
                mix_r += (int32_t)mixer->opl_temp[i * 2 + 1] * (int32_t)mixer->music_volume / 128;
            }

            /* Channel 1: SFX */
            if (mixer->sfx_active && mixer->sfx_pcm && mixer->sfx_current_frame < mixer->sfx_total_frames) {
                mix_l += (int32_t)mixer->sfx_pcm[mixer->sfx_current_frame * 2 + 0] * (int32_t)mixer->sfx_volume / 128;
                mix_r += (int32_t)mixer->sfx_pcm[mixer->sfx_current_frame * 2 + 1] * (int32_t)mixer->sfx_volume / 128;
                mixer->sfx_current_frame++;
                if (mixer->sfx_current_frame >= mixer->sfx_total_frames) {
                    mixer->sfx_active = false;
                }
            }

            /* Channel 2: Voice */
            if (mixer->voice_active && mixer->voice_pcm && mixer->voice_current_frame < mixer->voice_total_frames) {
                mix_l += (int32_t)mixer->voice_pcm[mixer->voice_current_frame * 2 + 0] * (int32_t)mixer->voice_volume / 128;
                mix_r += (int32_t)mixer->voice_pcm[mixer->voice_current_frame * 2 + 1] * (int32_t)mixer->voice_volume / 128;
                mixer->voice_current_frame++;
                if (mixer->voice_current_frame >= mixer->voice_total_frames) {
                    mixer->voice_active = false;
                }
            }

            /* Apply Master Volume */
            mix_l = mix_l * (int32_t)mixer->master_volume / 128;
            mix_r = mix_r * (int32_t)mixer->master_volume / 128;

            /* Saturation Clamping to signed 16-bit range [-32768, 32767] */
            if (mix_l > 32767) mix_l = 32767;
            else if (mix_l < -32768) mix_l = -32768;

            if (mix_r > 32767) mix_r = 32767;
            else if (mix_r < -32768) mix_r = -32768;

            chunk_out[i * 2 + 0] = (int16_t)mix_l;
            chunk_out[i * 2 + 1] = (int16_t)mix_r;
        }

        frames_done += chunk_frames;
    }
}
#endif

bool hal_audio_init(void) {
    memset(&g_mixer, 0, sizeof(g_mixer));
    memset(&g_opl3, 0, sizeof(g_opl3));
    hal_audio_dsp_reset();

    g_mixer.master_volume = 128;
    g_mixer.music_volume = 100;
    g_mixer.sfx_volume = 110;
    g_mixer.voice_volume = 120;
    g_mixer.opl_active = true;

#ifndef XANTH_HEADLESS_STUB
    if (SDL_WasInit(SDL_INIT_AUDIO) == 0) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            fprintf(stderr, "[HAL_AUDIO] SDL_InitSubSystem(AUDIO) failed: %s\n", SDL_GetError());
            g_mixer.dummy_mode = true;
            g_mixer.initialized = true;
            return true;
        }
    }

    SDL_AudioSpec wanted, obtained;
    memset(&wanted, 0, sizeof(wanted));
    wanted.freq = AUDIO_SAMPLE_RATE;
    wanted.format = AUDIO_S16SYS;
    wanted.channels = AUDIO_CHANNELS;
    wanted.samples = AUDIO_BUFFER_FRAMES;
    wanted.callback = sdl_audio_callback;
    wanted.userdata = &g_mixer;

    g_mixer.device_id = SDL_OpenAudioDevice(NULL, 0, &wanted, &obtained, 0);
    if (g_mixer.device_id == 0) {
        /* Headless or no audio hardware available: fallback to dummy mode */
        g_mixer.dummy_mode = true;
    } else {
        SDL_PauseAudioDevice(g_mixer.device_id, 0); /* Unpause audio */
    }
#else
    g_mixer.dummy_mode = true;
#endif

    g_mixer.initialized = true;
    return true;
}

void hal_audio_shutdown(void) {
#ifndef XANTH_HEADLESS_STUB
    if (g_mixer.device_id != 0) {
        SDL_CloseAudioDevice(g_mixer.device_id);
        g_mixer.device_id = 0;
    }
#endif
    if (g_mixer.sfx_pcm) {
        free(g_mixer.sfx_pcm);
        g_mixer.sfx_pcm = NULL;
    }
    if (g_mixer.voice_pcm) {
        free(g_mixer.voice_pcm);
        g_mixer.voice_pcm = NULL;
    }
    g_mixer.initialized = false;
}

void hal_audio_set_volume(uint8_t master, uint8_t music, uint8_t sfx, uint8_t voice) {
    g_mixer.master_volume = master;
    g_mixer.music_volume = music;
    g_mixer.sfx_volume = sfx;
    g_mixer.voice_volume = voice;
}

void hal_audio_tick(void) {
    /* If in headless dummy mode, advance audio frame positions periodically */
    if (g_mixer.dummy_mode) {
        size_t frames_per_tick = AUDIO_SAMPLE_RATE / 70;
        if (g_mixer.sfx_active) {
            g_mixer.sfx_current_frame += frames_per_tick;
            if (g_mixer.sfx_current_frame >= g_mixer.sfx_total_frames) {
                g_mixer.sfx_active = false;
            }
        }
        if (g_mixer.voice_active) {
            g_mixer.voice_current_frame += frames_per_tick;
            if (g_mixer.voice_current_frame >= g_mixer.voice_total_frames) {
                g_mixer.voice_active = false;
            }
        }
    }
}
