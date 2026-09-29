/*
 * port_assets.h — reference decoders for the retail data files.
 *
 * These are ORACLES, not the game. They were extracted from the retired
 * hand-written engine (see port/legacy/README.md) and kept for one purpose:
 * diffing against what the real game's own loaders produce while it runs
 * under the VM. That turns "the screen looks wrong" into "byte 4,183 of
 * entry 12 differs", which is worth far more than deleting them.
 *
 * Nothing here may be used to render or drive gameplay. See CONSTRAINTS.md.
 *
 * Caveat on the overlay declarations: the 62-entry directory model below is
 * the one the retired engine used, and it is WRONG -- the size fields sum to
 * 43,284 against a 325,595-byte payload, so they do not partition it. The
 * structures are retained only to keep the existing file-shape tests
 * compiling. Do not build anything new on them; see docs/PORT.md.
 */
#ifndef PORT_ASSETS_H
#define PORT_ASSETS_H

#include "port_types.h"
#include "port_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

#endif /* PORT_ASSETS_H */
