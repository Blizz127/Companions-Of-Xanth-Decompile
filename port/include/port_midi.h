#ifndef PORT_MIDI_H
#define PORT_MIDI_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MIDI_MAX_TRACKS 32
#define MIDI_OPL_VOICES 9

typedef struct {
    const uint8_t *data;
    uint32_t length;
    uint32_t pos;
    uint32_t current_tick;
    uint32_t next_event_tick;
    uint8_t running_status;
    bool active;
} MidiTrackState;

typedef struct {
    uint8_t note;
    uint8_t channel;
    uint8_t velocity;
    bool active;
    uint32_t start_time;
} MidiVoice;

typedef struct {
    uint8_t *mus_data;
    size_t mus_size;
    int track_count;
    uint32_t track_offsets[128];
    uint32_t track_sizes[128];

    /* Currently playing MIDI */
    bool playing;
    bool loop;
    uint16_t format;
    uint16_t num_tracks;
    uint16_t division;          /* Ticks per quarter note */
    uint32_t tempo_us_per_beat; /* Microseconds per beat, default 500000 = 120 BPM */
    uint64_t current_tick;
    double sample_accumulator;

    MidiTrackState tracks[MIDI_MAX_TRACKS];
    MidiVoice voices[MIDI_OPL_VOICES];
    uint8_t channel_volume[16];
    uint8_t channel_program[16];
} MidiPlayer;

extern MidiPlayer g_midi_player;

/**
 * Initializes the MIDI subsystem and loads a .MUS archive.
 * Returns 0 on success, negative error code on failure.
 */
int midi_init(const char *mus_path);

/**
 * Shuts down the MIDI player and frees allocated buffers.
 */
void midi_shutdown(void);

/**
 * Starts playback of a specific track within the loaded .MUS file.
 */
int midi_play(int track_index, bool loop);

/**
 * Stops playback and sends Key-Off to all active OPL voices.
 */
void midi_stop(void);

/**
 * Ticks the MIDI sequencer forward by the specified number of audio frames.
 * Automatically dispatches Note-On, Note-Off, and Controller events to the OPL3 synth.
 */
void midi_tick(uint32_t frames, uint32_t sample_rate);

#ifdef __cplusplus
}
#endif

#endif /* PORT_MIDI_H */
