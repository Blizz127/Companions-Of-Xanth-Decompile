/*
 * asset_oracle.c — reference decoders for the retail data files.
 *
 * These are NOT the game. They were extracted from the retired hand-written
 * engine (see port/legacy/) and kept for one purpose: to diff against what
 * the real game's own loaders produce while it runs under the VM. Turning
 * "the screen looks wrong" into "byte 4,183 of entry 12 differs" is worth far
 * more than deleting them, so they stay until the interpreted equivalents are
 * validated against them.
 *
 * Nothing here may be used to render or drive gameplay. See CONSTRAINTS.md.
 */
#include "port_assets.h"
#include "port_font.h"
#include "port_pic.h"
#include "port_rgn.h"
#include "port_midi.h"
#include "port_story.h"
#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Global Managers and Tables */
OverlayManager g_overlay_mgr = {0};
ObjectTable g_object_table = {0};
StoryDatabase g_story_db = {0};

/* The retired renderer's PIC/RGN containers are not part of the oracle
 * surface and have been dropped; see port/legacy/README.md. */
/* -------------------------------------------------------------------------
 * Overlay Consolidation Implementation (original/XANTH.OVL)
 * ------------------------------------------------------------------------- */
int overlay_init(const char *ovl_path) {
    memset(&g_overlay_mgr, 0, sizeof(OverlayManager));

    FILE *f = fopen(ovl_path, "rb");
    if (!f) {
        fprintf(stderr, "[ENGINE] Cannot open overlay file: %s\n", ovl_path);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz != OVL_FILE_SIZE) {
        fprintf(stderr, "[ENGINE] XANTH.OVL size mismatch: expected %d, got %ld\n",
                OVL_FILE_SIZE, sz);
        fclose(f);
        return -2;
    }
    g_overlay_mgr.file_size = (size_t)sz;

    /* Read 62 directory entries */
    size_t read_entries = fread(g_overlay_mgr.dir_entries, sizeof(OvlDirEntry), OVL_SECTION_COUNT, f);
    if (read_entries != OVL_SECTION_COUNT) {
        fprintf(stderr, "[ENGINE] Failed to read 62 overlay directory entries\n");
        fclose(f);
        return -3;
    }

    /* Allocate and read 325,595 bytes payload starting at offset 496 */
    fseek(f, OVL_PAYLOAD_OFFSET, SEEK_SET);
    g_overlay_mgr.payload_buffer = (uint8_t *)malloc(OVL_PAYLOAD_SIZE);
    if (!g_overlay_mgr.payload_buffer) {
        fclose(f);
        return -6;
    }

    size_t read_payload = fread(g_overlay_mgr.payload_buffer, 1, OVL_PAYLOAD_SIZE, f);
    fclose(f);

    if (read_payload != OVL_PAYLOAD_SIZE) {
        free(g_overlay_mgr.payload_buffer);
        g_overlay_mgr.payload_buffer = NULL;
        return -7;
    }
    g_overlay_mgr.payload_size = read_payload;

    /* Build section index table */
    uint32_t cur_offset = 0;
    for (int i = 0; i < OVL_SECTION_COUNT; i++) {
        g_overlay_mgr.sections[i].section_id = (uint16_t)i;
        g_overlay_mgr.sections[i].size = g_overlay_mgr.dir_entries[i].size;
        g_overlay_mgr.sections[i].segment = g_overlay_mgr.dir_entries[i].segment;
        g_overlay_mgr.sections[i].payload_offset = cur_offset;
        g_overlay_mgr.sections[i].file_offset = OVL_PAYLOAD_OFFSET + cur_offset;
        g_overlay_mgr.sections[i].data = g_overlay_mgr.payload_buffer + cur_offset;
        cur_offset += g_overlay_mgr.dir_entries[i].size;
    }

    g_overlay_mgr.loaded = true;
    printf("[ENGINE] Loaded XANTH.OVL: 62 overlay sections consolidated into %zu bytes flat RAM\n",
           g_overlay_mgr.payload_size);
    return 0;
}

void overlay_shutdown(void) {
    if (g_overlay_mgr.payload_buffer) {
        free(g_overlay_mgr.payload_buffer);
        g_overlay_mgr.payload_buffer = NULL;
    }
    g_overlay_mgr.loaded = false;
}

const uint8_t *overlay_get_payload(void) {
    return g_overlay_mgr.payload_buffer;
}

const OverlaySection *overlay_get_section(int section_id) {
    if (section_id < 0 || section_id >= OVL_SECTION_COUNT) return NULL;
    return &g_overlay_mgr.sections[section_id];
}

const uint8_t *overlay_resolve_address(uint32_t payload_offset) {
    if (!g_overlay_mgr.loaded || payload_offset >= g_overlay_mgr.payload_size) return NULL;
    return g_overlay_mgr.payload_buffer + payload_offset;
}

/* -------------------------------------------------------------------------
 * OBJECT.DAT Relational String Table Loader
 * ------------------------------------------------------------------------- */
int object_table_load(const char *path) {
    memset(&g_object_table, 0, sizeof(ObjectTable));

    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "[ENGINE] Cannot open OBJECT.DAT at %s\n", path);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz < 2 || sz != 4838) {
        fclose(f);
        return -2;
    }
    g_object_table.file_size = (size_t)sz;

    uint16_t table_len = 0;
    if (fread(&table_len, 2, 1, f) != 1) {
        fclose(f);
        return -3;
    }
    g_object_table.table_len = table_len;

    g_object_table.raw_buffer = (char *)malloc(table_len + 1);
    if (!g_object_table.raw_buffer) {
        fclose(f);
        return -5;
    }

    if (fread(g_object_table.raw_buffer, 1, table_len, f) != table_len) {
        free(g_object_table.raw_buffer);
        g_object_table.raw_buffer = NULL;
        fclose(f);
        return -6;
    }
    g_object_table.raw_buffer[table_len] = '\0';
    fclose(f);

    /* Parse null-terminated strings */
    int count = 0;
    char *ptr = g_object_table.raw_buffer;
    char *end = g_object_table.raw_buffer + table_len;

    while (ptr < end && count < MAX_OBJECT_STRINGS) {
        if (*ptr == '\0') {
            ptr++;
            continue;
        }
        g_object_table.strings[count++] = ptr;
        ptr += strlen(ptr) + 1;
    }
    g_object_table.string_count = count;

    printf("[ENGINE] Loaded OBJECT.DAT: %d object strings parsed\n", count);
    return 0;
}

void object_table_shutdown(void) {
    if (g_object_table.raw_buffer) {
        free(g_object_table.raw_buffer);
        g_object_table.raw_buffer = NULL;
    }
    g_object_table.string_count = 0;
}

const char *object_table_get(int index) {
    if (index < 0 || index >= g_object_table.string_count) return NULL;
    return g_object_table.strings[index];
}

int object_table_find(const char *name) {
    if (!name) return -1;
    for (int i = 0; i < g_object_table.string_count; i++) {
        if (strcmp(g_object_table.strings[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

/* -------------------------------------------------------------------------
 * XANTHSTR.DAT Story String Database Loader (Compatibility)
 * ------------------------------------------------------------------------- */
int story_db_load(const char *path) {
    memset(&g_story_db, 0, sizeof(StoryDatabase));

    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "[ENGINE] Cannot open XANTHSTR.DAT at %s\n", path);
        return -1;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz != 210146) {
        fclose(f);
        return -2;
    }
    g_story_db.file_size = (size_t)sz;

    g_story_db.raw_buffer = (uint8_t *)malloc(sz);
    if (!g_story_db.raw_buffer) {
        fclose(f);
        return -3;
    }

    if (fread(g_story_db.raw_buffer, 1, sz, f) != (size_t)sz) {
        free(g_story_db.raw_buffer);
        g_story_db.raw_buffer = NULL;
        fclose(f);
        return -4;
    }
    fclose(f);

    uint16_t count = *(const uint16_t *)g_story_db.raw_buffer;
    if (count != XANTHSTR_RECORD_COUNT) {
        free(g_story_db.raw_buffer);
        g_story_db.raw_buffer = NULL;
        return -5;
    }
    g_story_db.entry_count = count;

    for (int i = 0; i < XANTHSTR_RECORD_COUNT; i++) {
        const uint8_t *ent_ptr = g_story_db.raw_buffer + 2 + i * 6;
        uint16_t length = *(const uint16_t *)(ent_ptr);
        uint32_t offset = *(const uint32_t *)(ent_ptr + 2);

        g_story_db.records[i].length = length;
        g_story_db.records[i].offset = offset;
        g_story_db.records[i].data = g_story_db.raw_buffer + offset;
    }

    /* Also load into fully decompressed story text database */
    story_text_load(path);

    printf("[ENGINE] Loaded XANTHSTR.DAT (%d story database records, %d decompressed strings)\n",
           count, g_story_text_db.total_strings);
    return 0;
}

void story_db_shutdown(void) {
    if (g_story_db.raw_buffer) {
        free(g_story_db.raw_buffer);
        g_story_db.raw_buffer = NULL;
    }
    g_story_db.entry_count = 0;
    story_text_free();
}

const uint8_t *story_db_get_record(int index, uint16_t *out_len) {
    if (index < 0 || index >= g_story_db.entry_count) return NULL;
    if (out_len) *out_len = g_story_db.records[index].length;
    return g_story_db.records[index].data;
}
