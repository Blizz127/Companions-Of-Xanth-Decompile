#ifndef PORT_ENGINE_H
#define PORT_ENGINE_H

#include "port_types.h"
#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Engine Lifecycle State Machine Phases
 * ------------------------------------------------------------------------- */
typedef enum {
    PHASE_INIT               = 0,
    PHASE_ASSETS_MOUNTED     = 1,
    PHASE_VIDEO_INIT         = 2,
    PHASE_LOGO_SPLASH        = 3,
    PHASE_TITLE_SCREEN       = 4,
    PHASE_CUTSCENE_DEMONS    = 5,
    PHASE_CUTSCENE_XANTH     = 6,
    PHASE_INTRO_PLAYING      = 7,
    PHASE_GAMEPLAY_ROOM      = 8,
    PHASE_SHUTDOWN           = 9
} EnginePhase;

/* -------------------------------------------------------------------------
 * Overlay Consolidation Structures (original/XANTH.OVL)
 * ------------------------------------------------------------------------- */
#define OVL_SECTION_COUNT      62
#define OVL_PAYLOAD_OFFSET     496
#define OVL_PAYLOAD_SIZE       325595
#define OVL_FILE_SIZE          326091
#define OVL_TARGET_SEGMENT     0x30CB

typedef struct {
    uint16_t size;    /* Section size in bytes */
    uint16_t segment; /* Target segment in real mode: 0x30CB */
} OvlDirEntry;

typedef struct {
    uint16_t section_id;
    uint16_t size;
    uint16_t segment;
    uint32_t file_offset;
    uint32_t payload_offset;
    const uint8_t *data;
} OverlaySection;

typedef struct {
    bool loaded;
    size_t file_size;
    size_t payload_size;
    OvlDirEntry dir_entries[OVL_SECTION_COUNT];
    OverlaySection sections[OVL_SECTION_COUNT];
    uint8_t *payload_buffer;
} OverlayManager;

extern OverlayManager g_overlay_mgr;

int overlay_init(const char *ovl_path);
void overlay_shutdown(void);
const uint8_t *overlay_get_payload(void);
const OverlaySection *overlay_get_section(int section_id);
const uint8_t *overlay_resolve_address(uint32_t payload_offset);

/* -------------------------------------------------------------------------
 * Core Relational Databases (OBJECT.DAT, XANTHSTR.DAT)
 * ------------------------------------------------------------------------- */
#define MAX_OBJECT_STRINGS 1024

typedef struct {
    uint16_t table_len;
    size_t file_size;
    char *raw_buffer;
    int string_count;
    const char *strings[MAX_OBJECT_STRINGS];
} ObjectTable;

extern ObjectTable g_object_table;

int object_table_load(const char *path);
void object_table_shutdown(void);
const char *object_table_get(int index);
int object_table_find(const char *name);

#define XANTHSTR_RECORD_COUNT 80

typedef struct {
    uint16_t length;
    uint32_t offset;
    const uint8_t *data;
} StoryRecord;

typedef struct {
    uint16_t entry_count;
    size_t file_size;
    uint8_t *raw_buffer;
    StoryRecord records[XANTHSTR_RECORD_COUNT];
} StoryDatabase;

extern StoryDatabase g_story_db;

int story_db_load(const char *path);
void story_db_shutdown(void);
const uint8_t *story_db_get_record(int index, uint16_t *out_len);

/* -------------------------------------------------------------------------
 * Engine Context & Configuration
 * ------------------------------------------------------------------------- */
typedef struct {
    bool headless;
    uint64_t max_frames;
    bool has_max_frames;
    bool palette_cycling_enabled;
    bool use_xmouse;
    bool test_boot;
    double target_fps;
    char data_path[512];
    char save_path[512];
} EngineConfig;

typedef struct {
    EngineConfig config;
    EnginePhase phase;
    bool running;
    uint64_t frame_count;
    uint8_t *screen_buffer;
    uint8_t *back_buffer;

    /* Interactive UI and Story state */
    int mouse_x;
    int mouse_y;
    int mouse_btn;
    int active_verb;
    int score;
    char cmd_buffer[128];
    int cmd_len;
    char story_lines[64][64];
    int story_line_count;
    int current_room; /* 0: Bedroom, 1: Foyer, 2: Kitchen */
    bool foyer_light_on;
    bool fridge_open;
    bool phone_answered;
    bool package_received;
    bool package_picked_up;
    bool front_door_open;
    bool envelope_opened;
    bool letter_read;
    bool monitor_on;
    int monitor_anim_frame;
    bool sandwich_taken;
    bool disk_in_drive;
    char hovered_object[64];
} EngineContext;

extern EngineContext g_engine_ctx;

int engine_init(EngineContext *ctx, const EngineConfig *cfg);
void engine_shutdown(EngineContext *ctx);
void engine_update_phase(EngineContext *ctx);
void engine_handle_input(EngineContext *ctx, int mouse_x, int mouse_y, int mouse_btn, int key_code);
void engine_run_tick_loop(EngineContext *ctx);
double engine_verify_framebuffer(const uint8_t *screen_buffer);

#ifdef __cplusplus
}
#endif

#endif /* PORT_ENGINE_H */
