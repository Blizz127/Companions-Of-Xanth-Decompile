#include "port_midi.h"
#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

MidiPlayer g_midi_player = {0};

/* Precomputed OPL (block, f_num) table for MIDI notes 0..127 */
static uint8_t s_note_block[128];
static uint16_t s_note_fnum[128];
static bool s_tables_initialized = false;

static void init_freq_tables(void) {
    if (s_tables_initialized) return;

    for (int n = 0; n < 128; n++) {
        double freq = 440.0 * pow(2.0, (double)(n - 69) / 12.0);
        uint8_t best_block = 7;
        uint16_t best_fnum = 1023;

        for (int b = 0; b < 8; b++) {
            double fnum = (freq * (double)(1 << (20 - b))) / 49716.0;
            if (fnum <= 1023.0) {
                best_block = (uint8_t)b;
                best_fnum = (uint16_t)(fnum + 0.5);
                break;
            }
        }
        s_note_block[n] = best_block;
        s_note_fnum[n] = best_fnum;
    }
    s_tables_initialized = true;
}

static inline uint16_t read_be16(const uint8_t *p) {
    return (uint16_t)((p[0] << 8) | p[1]);
}

static inline uint32_t read_be32(const uint8_t *p) {
    return (uint32_t)((p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]);
}

static inline uint32_t read_varlen(const uint8_t *data, uint32_t *pos, uint32_t len) {
    uint32_t val = 0;
    while (*pos < len) {
        uint8_t b = data[(*pos)++];
        val = (val << 7) | (b & 0x7F);
        if (!(b & 0x80)) break;
    }
    return val;
}

int midi_init(const char *mus_path) {
    init_freq_tables();
    midi_shutdown();

    if (!mus_path) return -1;

    FILE *f = fopen(mus_path, "rb");
    if (!f) {
        fprintf(stderr, "[MIDI] Cannot open .MUS file: %s\n", mus_path);
        return -2;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz < 16) {
        fclose(f);
        return -3;
    }

    uint8_t *data = (uint8_t *)malloc((size_t)sz);
    if (!data) {
        fclose(f);
        return -4;
    }

    if (fread(data, 1, (size_t)sz, f) != (size_t)sz) {
        free(data);
        fclose(f);
        return -5;
    }
    fclose(f);

    g_midi_player.mus_data = data;
    g_midi_player.mus_size = (size_t)sz;

    /* Parse .MUS index table */
    uint32_t table_len = read_le32(data);
    int num_entries = (int)(table_len / 12);
    if (num_entries > 128) num_entries = 128;

    int valid_tracks = 0;
    for (int i = 0; i < num_entries; i++) {
        uint32_t off = read_le32(data + i * 12);
        if (off < (uint32_t)sz - 14 && memcmp(data + off, "MThd", 4) == 0) {
            uint32_t next_off = (i + 1 < num_entries) ? read_le32(data + (i + 1) * 12) : (uint32_t)sz;
            if (next_off > (uint32_t)sz || next_off <= off) {
                next_off = (uint32_t)sz;
            }
            g_midi_player.track_offsets[valid_tracks] = off;
            g_midi_player.track_sizes[valid_tracks] = next_off - off;
            valid_tracks++;
        }
    }

    g_midi_player.track_count = valid_tracks;
    for (int c = 0; c < 16; c++) {
        g_midi_player.channel_volume[c] = 100;
        g_midi_player.channel_program[c] = 0;
    }

    printf("[MIDI] Loaded %s: %d standard MIDI tracks detected\n", mus_path, valid_tracks);
    return 0;
}

void midi_shutdown(void) {
    midi_stop();
    if (g_midi_player.mus_data) {
        free(g_midi_player.mus_data);
        g_midi_player.mus_data = NULL;
    }
    memset(&g_midi_player, 0, sizeof(MidiPlayer));
}

void midi_stop(void) {
    g_midi_player.playing = false;

    /* Key off all active OPL channels */
    for (int v = 0; v < MIDI_OPL_VOICES; v++) {
        if (g_midi_player.voices[v].active) {
            uint8_t block = s_note_block[g_midi_player.voices[v].note];
            uint16_t fnum = s_note_fnum[g_midi_player.voices[v].note];
            hal_audio_write_opl((uint16_t)(0xB0 + v), (uint8_t)(((block & 0x07) << 2) | ((fnum >> 8) & 0x03)));
            g_midi_player.voices[v].active = false;
        }
    }
}

static void note_on(uint8_t ch, uint8_t note, uint8_t vel) {
    if (note > 127) return;
    if (vel == 0) {
        /* Note On with 0 velocity is Note Off */
        for (int v = 0; v < MIDI_OPL_VOICES; v++) {
            if (g_midi_player.voices[v].active &&
                g_midi_player.voices[v].channel == ch &&
                g_midi_player.voices[v].note == note) {
                uint8_t block = s_note_block[note];
                uint16_t fnum = s_note_fnum[note];
                hal_audio_write_opl((uint16_t)(0xB0 + v), (uint8_t)(((block & 0x07) << 2) | ((fnum >> 8) & 0x03)));
                g_midi_player.voices[v].active = false;
                break;
            }
        }
        return;
    }

    /* Find available voice or steal oldest */
    int voice_idx = -1;
    for (int v = 0; v < MIDI_OPL_VOICES; v++) {
        if (!g_midi_player.voices[v].active) {
            voice_idx = v;
            break;
        }
    }
    if (voice_idx < 0) {
        uint32_t oldest_time = 0xFFFFFFFF;
        for (int v = 0; v < MIDI_OPL_VOICES; v++) {
            if (g_midi_player.voices[v].start_time < oldest_time) {
                oldest_time = g_midi_player.voices[v].start_time;
                voice_idx = v;
            }
        }
    }
    if (voice_idx < 0) voice_idx = 0;

    MidiVoice *mv = &g_midi_player.voices[voice_idx];
    mv->active = true;
    mv->channel = ch;
    mv->note = note;
    mv->velocity = vel;
    mv->start_time = (uint32_t)g_midi_player.current_tick;

    uint8_t block = s_note_block[note];
    uint16_t fnum = s_note_fnum[note];

    /* Volume calculation combining channel volume & note velocity */
    uint32_t vol = (uint32_t)vel * (uint32_t)g_midi_player.channel_volume[ch & 0x0F] / 127;
    uint8_t tl = (vol > 63) ? 0 : (uint8_t)(63 - vol);

    /* OPL Attenuation (TL register 0x40 + voice) */
    hal_audio_write_opl((uint16_t)(0x40 + (voice_idx % 9)), tl);

    /* Frequency low byte */
    hal_audio_write_opl((uint16_t)(0xA0 + voice_idx), (uint8_t)(fnum & 0xFF));

    /* Frequency high, octave block, and Key-On flag (0x20) */
    uint8_t b0_val = (uint8_t)(0x20 | ((block & 0x07) << 2) | ((fnum >> 8) & 0x03));
    hal_audio_write_opl((uint16_t)(0xB0 + voice_idx), b0_val);
}

static void note_off(uint8_t ch, uint8_t note) {
    if (note > 127) return;
    for (int v = 0; v < MIDI_OPL_VOICES; v++) {
        if (g_midi_player.voices[v].active &&
            g_midi_player.voices[v].channel == ch &&
            g_midi_player.voices[v].note == note) {
            uint8_t block = s_note_block[note];
            uint16_t fnum = s_note_fnum[note];
            hal_audio_write_opl((uint16_t)(0xB0 + v), (uint8_t)(((block & 0x07) << 2) | ((fnum >> 8) & 0x03)));
            g_midi_player.voices[v].active = false;
            break;
        }
    }
}

int midi_play(int track_index, bool loop) {
    if (track_index < 0 || track_index >= g_midi_player.track_count) {
        return -1;
    }

    midi_stop();

    uint32_t off = g_midi_player.track_offsets[track_index];
    uint32_t sz = g_midi_player.track_sizes[track_index];
    const uint8_t *data = g_midi_player.mus_data + off;

    if (sz < 14 || memcmp(data, "MThd", 4) != 0) {
        return -2;
    }

    g_midi_player.format = read_be16(data + 8);
    g_midi_player.num_tracks = read_be16(data + 10);
    g_midi_player.division = read_be16(data + 12);
    if (g_midi_player.division == 0) g_midi_player.division = 120;
    if (g_midi_player.num_tracks > MIDI_MAX_TRACKS) {
        g_midi_player.num_tracks = MIDI_MAX_TRACKS;
    }

    g_midi_player.tempo_us_per_beat = 500000; /* 120 BPM default */
    g_midi_player.current_tick = 0;
    g_midi_player.sample_accumulator = 0.0;
    g_midi_player.loop = loop;

    /* Parse each MTrk chunk */
    uint32_t cur = 14;
    for (int t = 0; t < g_midi_player.num_tracks; t++) {
        MidiTrackState *trk = &g_midi_player.tracks[t];
        memset(trk, 0, sizeof(MidiTrackState));

        if (cur + 8 > sz || memcmp(data + cur, "MTrk", 4) != 0) {
            break;
        }
        uint32_t trk_len = read_be32(data + cur + 4);
        cur += 8;

        if (cur + trk_len > sz) trk_len = sz - cur;

        trk->data = data + cur;
        trk->length = trk_len;
        trk->pos = 0;
        trk->active = true;

        /* Read first delta-time */
        uint32_t delta = read_varlen(trk->data, &trk->pos, trk->length);
        trk->next_event_tick = delta;

        cur += trk_len;
    }

    g_midi_player.playing = true;
    printf("[MIDI] Playing Track %d: Format %d, %d tracks, Division %d (Loop: %s)\n",
           track_index, g_midi_player.format, g_midi_player.num_tracks,
           g_midi_player.division, loop ? "YES" : "NO");
    return 0;
}

static void advance_track_event(MidiTrackState *trk) {
    if (!trk->active || trk->pos >= trk->length) {
        trk->active = false;
        return;
    }

    uint8_t status = trk->data[trk->pos];
    if (status >= 0x80) {
        trk->pos++;
        trk->running_status = status;
    } else {
        status = trk->running_status;
    }

    uint8_t ev_type = status & 0xF0;
    uint8_t ch = status & 0x0F;

    if (ev_type == 0x90) { /* Note On */
        if (trk->pos + 2 <= trk->length) {
            uint8_t note = trk->data[trk->pos++];
            uint8_t vel = trk->data[trk->pos++];
            note_on(ch, note, vel);
        }
    } else if (ev_type == 0x80) { /* Note Off */
        if (trk->pos + 2 <= trk->length) {
            uint8_t note = trk->data[trk->pos++];
            trk->pos++; /* skip release velocity */
            note_off(ch, note);
        }
    } else if (ev_type == 0xB0) { /* Control Change */
        if (trk->pos + 2 <= trk->length) {
            uint8_t ctrl = trk->data[trk->pos++];
            uint8_t val = trk->data[trk->pos++];
            if (ctrl == 7) { /* Channel Volume */
                g_midi_player.channel_volume[ch] = val;
            }
        }
    } else if (ev_type == 0xC0) { /* Program Change */
        if (trk->pos + 1 <= trk->length) {
            g_midi_player.channel_program[ch] = trk->data[trk->pos++];
        }
    } else if (ev_type == 0xD0 || ev_type == 0xA0 || ev_type == 0xE0) {
        /* Other channel events */
        int skip = (ev_type == 0xD0) ? 1 : 2;
        trk->pos += (uint32_t)skip;
    } else if (status == 0xFF) { /* Meta Event */
        if (trk->pos < trk->length) {
            uint8_t meta_type = trk->data[trk->pos++];
            uint32_t meta_len = read_varlen(trk->data, &trk->pos, trk->length);

            if (meta_type == 0x51 && meta_len == 3 && trk->pos + 3 <= trk->length) {
                /* Set Tempo (microseconds per quarter note) */
                uint32_t us = (uint32_t)((trk->data[trk->pos] << 16) |
                                        (trk->data[trk->pos + 1] << 8) |
                                         trk->data[trk->pos + 2]);
                if (us > 0) g_midi_player.tempo_us_per_beat = us;
            } else if (meta_type == 0x2F) {
                /* End of Track */
                trk->active = false;
                return;
            }
            trk->pos += meta_len;
        }
    } else if (status == 0xF0 || status == 0xF7) { /* SysEx */
        uint32_t sysex_len = read_varlen(trk->data, &trk->pos, trk->length);
        trk->pos += sysex_len;
    }

    /* Read next delta-time */
    if (trk->pos < trk->length) {
        uint32_t delta = read_varlen(trk->data, &trk->pos, trk->length);
        trk->next_event_tick += delta;
    } else {
        trk->active = false;
    }
}

void midi_tick(uint32_t frames, uint32_t sample_rate) {
    if (!g_midi_player.playing || sample_rate == 0) return;

    /* Calculate elapsed ticks for this frame chunk */
    double seconds = (double)frames / (double)sample_rate;
    double us = seconds * 1000000.0;
    double ticks = (us / (double)g_midi_player.tempo_us_per_beat) * (double)g_midi_player.division;

    g_midi_player.sample_accumulator += ticks;
    uint32_t advance_ticks = (uint32_t)g_midi_player.sample_accumulator;
    if (advance_ticks == 0) return;

    g_midi_player.sample_accumulator -= (double)advance_ticks;

    for (uint32_t step = 0; step < advance_ticks; step++) {
        g_midi_player.current_tick++;

        bool any_active = false;
        for (int t = 0; t < g_midi_player.num_tracks; t++) {
            MidiTrackState *trk = &g_midi_player.tracks[t];
            while (trk->active && trk->next_event_tick <= g_midi_player.current_tick) {
                advance_track_event(trk);
            }
            if (trk->active) any_active = true;
        }

        if (!any_active) {
            if (g_midi_player.loop) {
                /* Restart tracks */
                g_midi_player.current_tick = 0;
                for (int t = 0; t < g_midi_player.num_tracks; t++) {
                    MidiTrackState *trk = &g_midi_player.tracks[t];
                    trk->pos = 0;
                    trk->active = true;
                    trk->running_status = 0;
                    uint32_t delta = read_varlen(trk->data, &trk->pos, trk->length);
                    trk->next_event_tick = delta;
                }
            } else {
                midi_stop();
                break;
            }
        }
    }
}
