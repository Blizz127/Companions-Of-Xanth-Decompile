#include "port_engine.h"
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
EngineContext g_engine_ctx = {0};

/* Loaded Game Asset Containers */
static PicContainer *g_pic_ui     = NULL; /* XANTH_00.PIC */
static PicContainer *g_pic_legend = NULL; /* XANTH_98.PIC */
static PicContainer *g_pic_title  = NULL; /* XANTH_99.PIC */
static PicContainer *g_pic_demons = NULL; /* XANTH_94.PIC */
static PicContainer *g_pic_xanth  = NULL; /* XANTH_91.PIC */
static PicContainer *g_pic_room02 = NULL; /* XANTH_02.PIC */
static RgnContainer *g_rgn_room02 = NULL; /* XANTH_02.RGN */

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

static void story_add_single_line(EngineContext *ctx, const char *line) {
    if (!line || !*line) return;
    if (ctx->story_line_count >= 64) {
        for (int i = 0; i < 63; i++) {
            memcpy(ctx->story_lines[i], ctx->story_lines[i + 1], sizeof(ctx->story_lines[0]));
        }
        ctx->story_line_count = 63;
    }
    snprintf(ctx->story_lines[ctx->story_line_count++], sizeof(ctx->story_lines[0]), "%s", line);
}

static void story_add_line(EngineContext *ctx, const char *text) {
    if (!text || !*text) return;

    const char *p = text;
    while (*p) {
        while (*p == ' ') p++;
        if (!*p) break;

        int max_len = 36;
        int len = 0;
        int last_space = -1;
        while (p[len] && len < max_len && p[len] != '\n') {
            if (p[len] == ' ') last_space = len;
            len++;
        }

        int take = len;
        if (p[len] != '\0' && p[len] != '\n' && last_space > 0) {
            take = last_space;
        }

        char tmp[64];
        if (take >= (int)sizeof(tmp) - 1) take = (int)sizeof(tmp) - 1;
        memcpy(tmp, p, take);
        tmp[take] = '\0';

        story_add_single_line(ctx, tmp);

        p += take;
        if (*p == ' ' || *p == '\n') p++;
    }
}

/* -------------------------------------------------------------------------
 * Engine Lifecycle Initialization
 * ------------------------------------------------------------------------- */
int engine_init(EngineContext *ctx, const EngineConfig *cfg) {
    memset(ctx, 0, sizeof(*ctx));
    ctx->config = *cfg;
    ctx->phase = PHASE_INIT;
    ctx->running = true;
    ctx->frame_count = 0;
    ctx->active_verb = 1; /* Default to LOOK */
    ctx->score = 0;
    ctx->cmd_len = 0;
    ctx->cmd_buffer[0] = '\0';

    hal_fs_init(cfg->data_path, cfg->save_path);

    /* Initialize Video HAL */
    if (!hal_video_init(2, false, cfg->headless, cfg->palette_cycling_enabled)) {
        fprintf(stderr, "[ENGINE] hal_video_init failed\n");
        return -1;
    }

    ctx->screen_buffer = hal_video_get_screen_buffer();
    ctx->back_buffer = hal_video_get_back_buffer();

    /* Initialize Audio HAL */
    hal_audio_init();

    /* Initialize Input HAL */
    hal_input_init();

    return 0;
}

void engine_shutdown(EngineContext *ctx) {
    ctx->running = false;
    ctx->phase = PHASE_SHUTDOWN;

    if (g_pic_legend) { pic_close(g_pic_legend); g_pic_legend = NULL; }
    if (g_pic_title)  { pic_close(g_pic_title);  g_pic_title = NULL; }
    if (g_pic_demons) { pic_close(g_pic_demons); g_pic_demons = NULL; }
    if (g_pic_xanth)  { pic_close(g_pic_xanth);  g_pic_xanth = NULL; }
    if (g_pic_room02) { pic_close(g_pic_room02); g_pic_room02 = NULL; }
    if (g_pic_ui)     { pic_close(g_pic_ui);     g_pic_ui = NULL; }
    if (g_rgn_room02) { rgn_free(g_rgn_room02);   g_rgn_room02 = NULL; }

    midi_shutdown();
    hal_audio_shutdown();
    hal_video_shutdown();
    hal_input_shutdown();

    overlay_shutdown();
    object_table_shutdown();
    story_db_shutdown();
}

/* -------------------------------------------------------------------------
 * Authentic Scene Rendering Subroutines
 * ------------------------------------------------------------------------- */

/* Phase 3: Authentic 3D LEGEND Entertainment Logo Splash */
static void render_logo_splash(EngineContext *ctx) {
    uint8_t *buf = ctx->back_buffer;
    memset(buf, 0, HAL_VIDEO_FRAME_SIZE);

    if (g_pic_legend && g_pic_legend->count > 58) {
        pic_decompress_entry(g_pic_legend, 0);  /* Palette */
        pic_decompress_entry(g_pic_legend, 58); /* 3D LEGEND logo sprite (188x199) */

        pic_apply_palette(&g_pic_legend->entries[0]);
        const PicEntry *logo = &g_pic_legend->entries[58];

        int lx = (SCREEN_W - logo->width) / 2;
        int ly = (SCREEN_H - logo->height) / 2;
        pic_blit(logo, buf, SCREEN_W, SCREEN_H, lx, ly, true, 0);
    }

    /* Subtitle header & footer */
    font_draw_text_centered_shadow(buf, 172, "ENTERTAINMENT COMPANY", 14, 0);
    font_draw_text_centered_shadow(buf, 184, "presents", 11, 0);

    hal_video_set_active_buffer(1);
    hal_video_flip();
}

/* Phase 4: Authentic COMPANIONS OF XANTH Title Screen */
static void render_title_screen(EngineContext *ctx) {
    uint8_t *buf = ctx->back_buffer;
    /* Deep midnight blue backdrop */
    memset(buf, 0, HAL_VIDEO_FRAME_SIZE);

    if (g_pic_title && g_pic_title->count > 42) {
        pic_decompress_entry(g_pic_title, 42); /* Palette */
        pic_decompress_entry(g_pic_title, 30); /* Golden logo banner (316x90) */

        pic_apply_palette(&g_pic_title->entries[42]);
        const PicEntry *logo = &g_pic_title->entries[30];

        int lx = (SCREEN_W - logo->width) / 2;
        int ly = 12;
        pic_blit(logo, buf, SCREEN_W, SCREEN_H, lx, ly, true, 0);
    }

    /* Author & Credits */
    font_draw_text_centered_shadow(buf, 110, "A Graphic Adventure Game", 14, 0);
    font_draw_text_centered_shadow(buf, 124, "Based on the Xanth Novels by", 7, 0);
    font_draw_text_centered_shadow(buf, 136, "PIERS ANTHONY", 15, 0);

    /* Prompt Box */
    font_draw_box(buf, 24, 154, 272, 20, 14, 1);
    font_draw_text_centered_shadow(buf, 160, "[ Press SPACE or Click to Start ]", 15, 0);

    /* Status Bar */
    font_draw_box(buf, 0, 186, 320, 14, 8, 0);
    font_draw_text(buf, 8, 189, "F1: Help | ESC: Quit | Saves: 0-9", 11);
    font_draw_text(buf, 220, 189, "VGA 320x200", 14);

    hal_video_set_active_buffer(1);
    hal_video_flip();
}

/* Phase 5: Cutscene 1 - The Bet of Demon Earth and Demon Xanth */
static void render_cutscene_demons(EngineContext *ctx) {
    uint8_t *buf = ctx->back_buffer;

    if (g_pic_demons && g_pic_demons->count > 0) {
        pic_decompress_entry(g_pic_demons, 0); /* Full 320x200 cutscene */
        pic_apply_palette(&g_pic_demons->entries[0]);
        pic_blit(&g_pic_demons->entries[0], buf, SCREEN_W, SCREEN_H, 0, 0, false, 0);
    } else {
        memset(buf, 0, HAL_VIDEO_FRAME_SIZE);
    }

    /* Narrative Dialogue Box at bottom */
    font_draw_box(buf, 6, 138, 308, 48, 14, 0);
    font_draw_text_centered_shadow(buf, 142, "Demon Earth & Demon Xanth bet...", 14, 0);
    font_draw_text_centered_shadow(buf, 153, "\"Two Mundanes will compete!\"", 15, 0);
    font_draw_text_centered_shadow(buf, 164, "\"If your Mundane wins, I yield.\"", 11, 0);
    font_draw_text_centered_shadow(buf, 175, "[ Click or Space to Continue ]", 10, 0);

    hal_video_set_active_buffer(1);
    hal_video_flip();
}

/* Phase 6: Cutscene 2 - Dug Barlum Enters the Realm of Xanth */
static void render_cutscene_xanth(EngineContext *ctx) {
    uint8_t *buf = ctx->back_buffer;

    if (g_pic_xanth && g_pic_xanth->count > 0) {
        pic_decompress_entry(g_pic_xanth, 0); /* Full 320x200 cutscene */
        pic_apply_palette(&g_pic_xanth->entries[0]);
        pic_blit(&g_pic_xanth->entries[0], buf, SCREEN_W, SCREEN_H, 0, 0, false, 0);
    } else {
        memset(buf, 0, HAL_VIDEO_FRAME_SIZE);
    }

    /* Narrative Dialogue Box */
    font_draw_box(buf, 6, 138, 308, 48, 14, 0);
    font_draw_text_centered_shadow(buf, 142, "Dug Barlum enters magical Xanth!", 14, 0);
    font_draw_text_centered_shadow(buf, 153, "\"Where magic is real and puns rule!\"", 15, 0);
    font_draw_text_centered_shadow(buf, 164, "Choose your companion wisely!", 11, 0);
    font_draw_text_centered_shadow(buf, 175, "[ Click or Space to Begin Quest ]", 10, 0);

    hal_video_set_active_buffer(1);
    hal_video_flip();
}

/* Phase 8: Authentic Classic Legend 3-Panel Interactive Room View */
static void render_gameplay_room(EngineContext *ctx) {
    uint8_t *buf = ctx->back_buffer;
    memset(buf, 0, HAL_VIDEO_FRAME_SIZE);

    /* 0. Detect Hovered Interactive Hotspot from .RGN polygon regions */
    int rx = ctx->mouse_x - 8;
    int ry = ctx->mouse_y - 6;
    ctx->hovered_object[0] = '\0';
    if (rx >= 0 && rx < 264 && ry >= 0 && ry < 122 && g_rgn_room02) {
        int rgn_slot = (ctx->current_room == 0) ? 0 : ((ctx->current_room == 1) ? 41 : 68);
        const RgnRoom *rr = rgn_get_room(g_rgn_room02, rgn_slot);
        if (rr) {
            int oid = rgn_find_object_at(rr, rx, ry);
            if (oid >= 0) {
                const char *oname = object_table_get(oid);
                if (oname) {
                    strncpy(ctx->hovered_object, oname, sizeof(ctx->hovered_object) - 1);
                }
            }
        }
    }

    /* 1. Viewport Graphic (x=8, y=6, w=264, h=122): Authentic Room Scene & Overlays */
    int room_entry_idx = 0;
    if (ctx->current_room == 1) room_entry_idx = ctx->foyer_light_on ? 42 : 41; /* Foyer */
    else if (ctx->current_room == 2) room_entry_idx = 68; /* Kitchen */

    if (g_pic_room02 && g_pic_room02->count > room_entry_idx) {
        pic_decompress_entry(g_pic_room02, room_entry_idx);
        pic_apply_palette(&g_pic_room02->entries[room_entry_idx]);
        pic_blit(&g_pic_room02->entries[room_entry_idx], buf, SCREEN_W, SCREEN_H, 8, 6, false, 0);

        /* Room 0 (Bedroom Desk): Authentic sprite overlays */
        if (ctx->current_room == 0) {
            /* Unopened envelope on desk at (202, 82) */
            if (!ctx->envelope_opened && g_pic_room02->count > 3) {
                pic_decompress_entry(g_pic_room02, 3);
                pic_blit(&g_pic_room02->entries[3], buf, SCREEN_W, SCREEN_H, 8 + 202, 6 + 82, true, 0);
            }
            /* Yellow Post-It note at (201, 61) */
            if (g_pic_room02->count > 6) {
                pic_decompress_entry(g_pic_room02, 6);
                pic_blit(&g_pic_room02->entries[6], buf, SCREEN_W, SCREEN_H, 8 + 201, 6 + 61, true, 0);
            }
            /* Computer monitor screen if on */
            if (ctx->monitor_on) {
                int frame = 20 + ((int)(ctx->frame_count / 8) % 13);
                if (g_pic_room02->count > frame) {
                    pic_decompress_entry(g_pic_room02, frame);
                    pic_blit(&g_pic_room02->entries[frame], buf, SCREEN_W, SCREEN_H, 8 + 145, 6 + 13, true, 0);
                }
            }
        }
        /* Room 1 (Foyer): Authentic sprite overlays */
        else if (ctx->current_room == 1) {
            /* Open front door at (192, 2) */
            if (ctx->front_door_open && g_pic_room02->count > 65) {
                pic_decompress_entry(g_pic_room02, 65);
                pic_blit(&g_pic_room02->entries[65], buf, SCREEN_W, SCREEN_H, 8 + 192, 6 + 2, true, 0);
            }
            /* Delivered package on floor at (216, 94) */
            if (ctx->package_received && !ctx->package_picked_up && g_pic_room02->count > 44) {
                pic_decompress_entry(g_pic_room02, 44);
                pic_blit(&g_pic_room02->entries[44], buf, SCREEN_W, SCREEN_H, 8 + 216, 6 + 94, true, 0);
            }
        }
        /* Room 2 (Kitchen): Authentic sprite overlays */
        else if (ctx->current_room == 2) {
            /* Open refrigerator at (107, 37) */
            if (ctx->fridge_open && g_pic_room02->count > 69) {
                pic_decompress_entry(g_pic_room02, 69);
                pic_blit(&g_pic_room02->entries[69], buf, SCREEN_W, SCREEN_H, 8 + 107, 6 + 37, true, 0);
                /* Food / sandwich inside fridge at (142, 81) */
                if (!ctx->sandwich_taken && g_pic_room02->count > 70) {
                    pic_decompress_entry(g_pic_room02, 70);
                    pic_blit(&g_pic_room02->entries[70], buf, SCREEN_W, SCREEN_H, 8 + 142, 6 + 81, true, 0);
                }
            }
        }
    }

    /* Ornamental frame border around graphic viewport */
    font_draw_rect(buf, 7, 5, 266, 1, 14);
    font_draw_rect(buf, 7, 128, 266, 1, 14);
    font_draw_rect(buf, 7, 5, 1, 124, 14);
    font_draw_rect(buf, 272, 5, 1, 124, 14);

    /* 2. Compass & Navigation Pane (x=276, y=5, w=38, h=124) */
    font_draw_box(buf, 276, 5, 38, 124, 14, 1);
    if (g_pic_ui && g_pic_ui->count > 0) {
        pic_decompress_entry(g_pic_ui, 0); /* 42x39 compass rose */
        pic_blit(&g_pic_ui->entries[0], buf, SCREEN_W, SCREEN_H, 274, 16, true, 0);
    } else {
        font_draw_text(buf, 283, 8, "DIR", 14);
    }

    /* Dynamic directions based on room */
    bool can_nw = (ctx->current_room == 0);
    bool can_w  = (ctx->current_room == 1);
    bool can_e  = (ctx->current_room == 2);
    bool can_se = (ctx->current_room == 1);

    font_draw_text(buf, 281, 60, can_nw ? "NW " : (can_se ? "SE " : (can_w ? " W " : (can_e ? " E " : "   "))), 14);
    font_draw_text(buf, 281, 76, "UP ", 8);
    font_draw_text(buf, 281, 90, "DOWN", 8);
    font_draw_text(buf, 281, 108, "MAP", 14);

    /* 3. Action Verb Buttons (x=8, y=131, w=306, h=15) */
    static const char *verbs[] = { "LOOK", "TAKE", "TALK", "CAST", "INV", "EXAM", "USE" };
    int vx = 8;
    for (int i = 0; i < 7; i++) {
        int vw = (i == 5) ? 44 : 38;
        bool is_active = (ctx->active_verb == (i + 1));
        font_draw_box(buf, vx, 131, vw, 13, is_active ? 14 : 7, is_active ? 1 : 0);
        font_draw_text(buf, vx + 4, 134, verbs[i], is_active ? 15 : 11);
        vx += vw + 4;
    }

    /* 4. Story & Narration Log Pane (x=8, y=146, w=306, h=42) */
    font_draw_box(buf, 8, 146, 306, 42, 8, 0);

    int start_line = (ctx->story_line_count > 3) ? (ctx->story_line_count - 3) : 0;
    int sy = 149;
    for (int i = 0; i < 3 && (start_line + i) < ctx->story_line_count; i++) {
        font_draw_text(buf, 12, sy, ctx->story_lines[start_line + i], 15);
        sy += 9;
    }

    /* Command prompt line with blinking cursor */
    char prompt_str[140];
    bool cursor_on = ((ctx->frame_count / 15) % 2) == 0;
    snprintf(prompt_str, sizeof(prompt_str), "> %s%s", ctx->cmd_buffer, cursor_on ? "_" : " ");
    font_draw_text(buf, 12, 176, prompt_str, 14);

    /* 5. Footer Status Bar (x=0, y=189, w=320, h=11) */
    font_draw_box(buf, 0, 189, 320, 11, 14, 1);
    static const char *room_titles[] = { "Computer Desk", "Front Hall", "Kitchen" };
    const char *rtitle = (ctx->current_room >= 0 && ctx->current_room <= 2) ? room_titles[ctx->current_room] : "Mundania";
    char status_str[128];
    if (ctx->hovered_object[0] != '\0') {
        snprintf(status_str, sizeof(status_str), "POINTING AT: %s | SCORE: %d | %s",
                 ctx->hovered_object, ctx->score, rtitle);
    } else {
        snprintf(status_str, sizeof(status_str), "SCORE: %d | ROOM: %s | ESC: Exit", ctx->score, rtitle);
    }
    font_draw_text(buf, 8, 191, status_str, 15);

    hal_video_set_active_buffer(1);
    hal_video_flip();
}

/* -------------------------------------------------------------------------
 * Engine Phase Transitions
 * ------------------------------------------------------------------------- */
void engine_update_phase(EngineContext *ctx) {
    if (ctx->frame_count < 5) {
        ctx->phase = PHASE_INIT;
    } else if (ctx->frame_count < 15) {
        if (ctx->phase < PHASE_ASSETS_MOUNTED) {
            ctx->phase = PHASE_ASSETS_MOUNTED;

            char ovl_path[512] = {0};
            char obj_path[512] = {0};
            char str_path[512] = {0};
            char pic_path[512] = {0};
            char rgn_path[512] = {0};

            if (hal_fs_resolve_gamedata("XANTH.OVL", ovl_path, sizeof(ovl_path))) {
                overlay_init(ovl_path);
            }
            if (hal_fs_resolve_gamedata("OBJECT.DAT", obj_path, sizeof(obj_path))) {
                object_table_load(obj_path);
            }
            if (hal_fs_resolve_gamedata("XANTHSTR.DAT", str_path, sizeof(str_path))) {
                story_db_load(str_path);
            }

            /* Open authentic PIC asset containers */
            if (hal_fs_resolve_gamedata("XANTH_00.PIC", pic_path, sizeof(pic_path))) {
                g_pic_ui = pic_open(pic_path);
            }
            if (hal_fs_resolve_gamedata("XANTH_98.PIC", pic_path, sizeof(pic_path))) {
                g_pic_legend = pic_open(pic_path);
            }
            if (hal_fs_resolve_gamedata("XANTH_99.PIC", pic_path, sizeof(pic_path))) {
                g_pic_title = pic_open(pic_path);
            }
            if (hal_fs_resolve_gamedata("XANTH_94.PIC", pic_path, sizeof(pic_path))) {
                g_pic_demons = pic_open(pic_path);
            }
            if (hal_fs_resolve_gamedata("XANTH_91.PIC", pic_path, sizeof(pic_path))) {
                g_pic_xanth = pic_open(pic_path);
            }
            if (hal_fs_resolve_gamedata("XANTH_02.PIC", pic_path, sizeof(pic_path))) {
                g_pic_room02 = pic_open(pic_path);
            }

            /* Open authentic .RGN hotspot region container */
            if (hal_fs_resolve_gamedata("XANTH_02.RGN", rgn_path, sizeof(rgn_path))) {
                g_rgn_room02 = rgn_load(rgn_path);
            }

            /* Initialize default adventure story narration lines from Mundania Bedroom */
            story_add_line(ctx, "You're sitting at a desk in your bedroom.");
            story_add_line(ctx, "On the desk is a computer, an unopened envelope, and a pencil holder.");
            story_add_line(ctx, "You can see a bad storm brewing through your bedroom window.");
        }
    } else if (ctx->frame_count < 25) {
        if (ctx->phase < PHASE_VIDEO_INIT) {
            ctx->phase = PHASE_VIDEO_INIT;
        }
    } else if (ctx->frame_count < 100) {
        if (ctx->phase < PHASE_LOGO_SPLASH) {
            ctx->phase = PHASE_LOGO_SPLASH;
            printf("[ENGINE] Displaying authentic LEGEND Entertainment logo splash\n");
            render_logo_splash(ctx);

            /* Play opening fanfare on OPL3 FM synth */
            hal_audio_write_opl(0xA0, 0x6B);
            hal_audio_write_opl(0xB0, 0x31);
        }
    } else if (ctx->frame_count < 220) {
        if (ctx->phase < PHASE_TITLE_SCREEN) {
            ctx->phase = PHASE_TITLE_SCREEN;
            printf("[ENGINE] Displaying authentic COMPANIONS OF XANTH title screen\n");
            render_title_screen(ctx);

            /* Start authentic title soundtrack on OPL3 via .MUS MIDI stream */
            char mus_path[512] = {0};
            if (hal_fs_resolve_gamedata("XANTH_01.MUS", mus_path, sizeof(mus_path))) {
                midi_init(mus_path);
                midi_play(0, true);
            }
        }
    } else if (ctx->frame_count < 320) {
        if (ctx->phase < PHASE_CUTSCENE_DEMONS) {
            ctx->phase = PHASE_CUTSCENE_DEMONS;
            printf("[ENGINE] Playing authentic Cutscene 1: The Bet of the Demons\n");
            render_cutscene_demons(ctx);
        }
    } else if (ctx->frame_count < 420) {
        if (ctx->phase < PHASE_CUTSCENE_XANTH) {
            ctx->phase = PHASE_CUTSCENE_XANTH;
            printf("[ENGINE] Playing authentic Cutscene 2: Dug Enters Xanth\n");
            render_cutscene_xanth(ctx);
        }
    } else {
        if (ctx->phase < PHASE_GAMEPLAY_ROOM) {
            ctx->phase = PHASE_GAMEPLAY_ROOM;
            printf("[ENGINE] Entering authentic 3-panel gameplay view: Room 2 Computer Desk\n");
            render_gameplay_room(ctx);

            /* Start authentic Mundania room soundtrack on OPL3 via .MUS MIDI stream */
            char mus_path[512] = {0};
            if (hal_fs_resolve_gamedata("XANTH_02.MUS", mus_path, sizeof(mus_path))) {
                midi_init(mus_path);
                midi_play(0, true);
            }
        }
    }

    /* Redraw current phase if active */
    if (ctx->phase == PHASE_GAMEPLAY_ROOM) {
        render_gameplay_room(ctx);
    } else if (ctx->phase == PHASE_TITLE_SCREEN) {
        render_title_screen(ctx);
    } else if (ctx->phase == PHASE_LOGO_SPLASH) {
        render_logo_splash(ctx);
    } else if (ctx->phase == PHASE_CUTSCENE_DEMONS) {
        render_cutscene_demons(ctx);
    } else if (ctx->phase == PHASE_CUTSCENE_XANTH) {
        render_cutscene_xanth(ctx);
    }
}

/* -------------------------------------------------------------------------
 * Interactive Input Event Handling
 * ------------------------------------------------------------------------- */
static void execute_command(EngineContext *ctx, const char *cmd) {
    if (!cmd || !*cmd) return;

    char lower[128];
    int len = 0;
    while (cmd[len] && len < 127) {
        lower[len] = (char)tolower((unsigned char)cmd[len]);
        len++;
    }
    lower[len] = '\0';

    char echo_msg[132];
    snprintf(echo_msg, sizeof(echo_msg), "> %s", cmd);
    story_add_line(ctx, echo_msg);

    /* Universal Navigation Commands */
    if (strcmp(lower, "nw") == 0 || strstr(lower, "northwest") || strstr(lower, "go hall") || strstr(lower, "go foyer")) {
        if (ctx->current_room == 0) {
            ctx->current_room = 1;
            story_add_line(ctx, "You step northwest into the front hall.");
            story_add_line(ctx, "A potted fern, Beethoven portrait, and front door stand before you.");
            return;
        } else {
            story_add_line(ctx, "You can't go northwest from here.");
            return;
        }
    } else if (strcmp(lower, "se") == 0 || strstr(lower, "southeast") || strstr(lower, "go bedroom") || strstr(lower, "go desk")) {
        if (ctx->current_room == 1) {
            ctx->current_room = 0;
            story_add_line(ctx, "You return southeast to your bedroom computer desk.");
            return;
        } else {
            story_add_line(ctx, "You can't go southeast from here.");
            return;
        }
    } else if (strcmp(lower, "w") == 0 || strstr(lower, "west") || strstr(lower, "go kitchen")) {
        if (ctx->current_room == 1) {
            ctx->current_room = 2;
            story_add_line(ctx, "You walk west into the kitchen.");
            story_add_line(ctx, "A yellow refrigerator hums beside the sink. The telephone hangs on the wall.");
            return;
        } else {
            story_add_line(ctx, "You can't go west from here.");
            return;
        }
    } else if (strcmp(lower, "e") == 0 || strstr(lower, "east")) {
        if (ctx->current_room == 2) {
            ctx->current_room = 1;
            story_add_line(ctx, "You step back east into the front hall.");
            return;
        } else {
            story_add_line(ctx, "You can't go east from here.");
            return;
        }
    }

    /* Room 0: Bedroom / Computer Desk */
    if (ctx->current_room == 0) {
        if (strcmp(lower, "look") == 0 || strcmp(lower, "l") == 0 || strstr(lower, "look desk")) {
            story_add_line(ctx, "You're sitting at a desk in your bedroom. On the desk is your personal computer,");
            story_add_line(ctx, "an unopened envelope, and a pencil holder. You can see a bad storm brewing outside.");
        } else if (strstr(lower, "envelope") || strstr(lower, "mail")) {
            hal_audio_play_sound_file("MAIL.RS");
            ctx->envelope_opened = true;
            story_add_line(ctx, "You carefully open the envelope and a letter and a bracelet fall into your hands.");
            ctx->score += 5;
        } else if (strstr(lower, "letter") || strstr(lower, "read letter") || strstr(lower, "pia")) {
            ctx->letter_read = true;
            story_add_line(ctx, "\"Dear Dug, It's over... I'm giving you back the bracelet you gave me. - Pia\"");
        } else if (strstr(lower, "bracelet")) {
            story_add_line(ctx, "The cheap silver bracelet is engraved: \"I <3 P\". It fit Pia's wrist perfectly.");
        } else if (strstr(lower, "post-it") || strstr(lower, "note") || strstr(lower, "numbers")) {
            hal_audio_play_sound_file("WRITE.RS");
            story_add_line(ctx, "Scribbled on the yellow Post-It note:");
            story_add_line(ctx, "Ed 383-5283  |  Pia 385-8377  |  Weather 936-8267");
            ctx->score += 5;
        } else if (strstr(lower, "window") || strstr(lower, "rain") || strstr(lower, "storm")) {
            hal_audio_play_sound_file("THUNDER.RS");
            story_add_line(ctx, "You watch the raging storm through the window and lightning strikes the yard!");
        } else if (strstr(lower, "pencils") || strstr(lower, "holder") || strstr(lower, "jar")) {
            story_add_line(ctx, "It's a pencil holder with a bunch of pens and pencils in it. Jammed tightly.");
        } else if (strstr(lower, "bookshelf") || strstr(lower, "books")) {
            story_add_line(ctx, "Your bookshelf contains motorcycle magazines and classics of fantasy literature.");
        } else if (strstr(lower, "computer") || strstr(lower, "monitor") || strstr(lower, "screen")) {
            hal_audio_play_sound_file("PCON.RS");
            ctx->monitor_on = true;
            story_add_line(ctx, "On the screen, Grundy Golem dances excitedly: \"Choose your Companion!\"");
            ctx->score += 5;
        } else if (strstr(lower, "talk")) {
            story_add_line(ctx, "Talking to furniture is an advanced sign of Progressive Game Players' Syndrome.");
        } else if (strstr(lower, "inv") || strstr(lower, "inventory") || strcmp(lower, "i") == 0) {
            story_add_line(ctx, "You have: envelope from Pia, cheap silver bracelet, and yellow Post-It note.");
        } else if (strstr(lower, "cast") || strstr(lower, "magic") || strstr(lower, "xanth")) {
            hal_audio_play_sound_file("LAUGH.RS");
            story_add_line(ctx, "Demon Earth and Demon Xanth chuckle in the cosmos... Magic awakens!");
            ctx->score += 10;
        } else if (strstr(lower, "help") || strcmp(lower, "?") == 0) {
            story_add_line(ctx, "Try: LOOK, EXAMINE ENVELOPE, READ NOTE, WINDOW, NW (go to hall), INV, or click.");
        } else {
            story_add_line(ctx, "You consider doing that, but the mysterious computer screen draws your gaze.");
        }
    }
    /* Room 1: Front Hall / Foyer */
    else if (ctx->current_room == 1) {
        if (strcmp(lower, "look") == 0 || strcmp(lower, "l") == 0 || strstr(lower, "look hall") || strstr(lower, "look foyer")) {
            story_add_line(ctx, "You stand in the front hall. There is a potted fern, a Beethoven portrait, and front door.");
        } else if (strstr(lower, "switch") || strstr(lower, "light")) {
            ctx->foyer_light_on = !ctx->foyer_light_on;
            story_add_line(ctx, ctx->foyer_light_on ? "Click. The foyer lights turn on brightly." : "Click. The foyer lights turn off.");
        } else if (strstr(lower, "door") || strstr(lower, "doorbell") || strstr(lower, "open door")) {
            hal_audio_play_sound_file("DOORBELL.RS");
            ctx->front_door_open = true;
            ctx->package_received = true;
            ctx->score += 10;
            story_add_line(ctx, "Ding-dong! The delivery person hands you a package from Xanth!");
            story_add_line(ctx, "Inside is the Companions of Xanth game box, floppy disk, and 3D glasses!");
        } else if (strstr(lower, "package") || strstr(lower, "box") || strstr(lower, "disk")) {
            ctx->package_picked_up = true;
            story_add_line(ctx, "You pick up the Companions of Xanth game package from the floor.");
        } else if (strstr(lower, "painting") || strstr(lower, "portrait") || strstr(lower, "beethoven")) {
            story_add_line(ctx, "A framed portrait of Ludwig van Beethoven scowls down at you in artistic genius.");
        } else if (strstr(lower, "plant") || strstr(lower, "fern") || strstr(lower, "flower") || strstr(lower, "table")) {
            story_add_line(ctx, "A leafy green fern and a vase of orange tulips sit atop the mahogany table.");
        } else if (strstr(lower, "mat")) {
            story_add_line(ctx, "A durable blue welcome mat rests neatly in front of the entry door.");
        } else if (strstr(lower, "inv") || strstr(lower, "inventory") || strcmp(lower, "i") == 0) {
            if (ctx->package_received) {
                story_add_line(ctx, "You have: game box, 3.5\" floppy disk, 3D glasses, letter from Pia, silver bracelet.");
            } else {
                story_add_line(ctx, "You have: letter from Pia, cheap silver bracelet, and yellow Post-It note.");
            }
        } else if (strstr(lower, "help") || strcmp(lower, "?") == 0) {
            story_add_line(ctx, "Try: OPEN DOOR, FLIP SWITCH, LOOK BEETHOVEN, W (to kitchen), SE (to bedroom).");
        } else {
            story_add_line(ctx, "Nothing unusual happens.");
        }
    }
    /* Room 2: Kitchen */
    else if (ctx->current_room == 2) {
        if (strcmp(lower, "look") == 0 || strcmp(lower, "l") == 0 || strstr(lower, "look kitchen")) {
            story_add_line(ctx, "You are in the kitchen. A yellow refrigerator hums beside the sink. A phone hangs on the wall.");
        } else if (strstr(lower, "fridge") || strstr(lower, "refrigerator") || strstr(lower, "icebox") || strstr(lower, "open")) {
            hal_audio_play_sound_file("FRIDGE.RS");
            ctx->fridge_open = !ctx->fridge_open;
            story_add_line(ctx, ctx->fridge_open ? "You open the refrigerator. Inside you see spicy mustard, a sandwich, and cold soda." : "You shut the refrigerator door.");
        } else if (strstr(lower, "mustard") || strstr(lower, "sandwich")) {
            ctx->sandwich_taken = true;
            story_add_line(ctx, "You grab the spicy mustard and sandwich. Sustenance for an adventurer!");
            ctx->score += 5;
        } else if (strstr(lower, "phone") || strstr(lower, "telephone") || strstr(lower, "call") || strstr(lower, "ed")) {
            hal_audio_play_sound_file("PHONE.RS");
            ctx->phone_answered = true;
            ctx->score += 5;
            story_add_line(ctx, "Edsel says: \"Hey Dug! Got the new Xanth game yet? Call me when you do!\"");
        } else if (strstr(lower, "sink") || strstr(lower, "dishes")) {
            story_add_line(ctx, "The kitchen sink is spotless. All dishes are clean and neatly stacked.");
        } else if (strstr(lower, "inv") || strstr(lower, "inventory") || strcmp(lower, "i") == 0) {
            story_add_line(ctx, "You have: letter from Pia, cheap silver bracelet, and Post-It note.");
        } else if (strstr(lower, "help") || strcmp(lower, "?") == 0) {
            story_add_line(ctx, "Try: OPEN FRIDGE, ANSWER PHONE, TAKE SANDWICH, E (to foyer).");
        } else {
            story_add_line(ctx, "You can't do that here.");
        }
    }
}

void engine_handle_input(EngineContext *ctx, int mouse_x, int mouse_y, int mouse_btn, int key_code) {
    ctx->mouse_x = mouse_x;
    ctx->mouse_y = mouse_y;
    ctx->mouse_btn = mouse_btn;

    /* Click or Space/Enter to advance through cutscenes and splashes */
    if (key_code == ' ' || key_code == 13 || mouse_btn != 0) {
        if (ctx->phase == PHASE_LOGO_SPLASH) {
            ctx->phase = PHASE_TITLE_SCREEN;
            ctx->frame_count = 101;
            return;
        } else if (ctx->phase == PHASE_TITLE_SCREEN) {
            ctx->phase = PHASE_CUTSCENE_DEMONS;
            ctx->frame_count = 221;
            return;
        } else if (ctx->phase == PHASE_CUTSCENE_DEMONS) {
            ctx->phase = PHASE_CUTSCENE_XANTH;
            ctx->frame_count = 321;
            return;
        } else if (ctx->phase == PHASE_CUTSCENE_XANTH) {
            ctx->phase = PHASE_GAMEPLAY_ROOM;
            ctx->frame_count = 421;
            return;
        }
    }

    /* Gameplay Phase Interactive Input */
    if (ctx->phase == PHASE_GAMEPLAY_ROOM) {
        /* Mouse Clicks */
        if (mouse_btn & 1) {
            /* 1. Click in Viewport (x=8..272, y=6..128) */
            if (mouse_x >= 8 && mouse_x <= 272 && mouse_y >= 6 && mouse_y <= 128) {
                if (ctx->hovered_object[0] != '\0') {
                    static const char *verb_cmds[] = { "look", "take", "talk", "cast", "inventory", "examine", "use" };
                    const char *verb = "look";
                    if (ctx->active_verb >= 1 && ctx->active_verb <= 7) {
                        verb = verb_cmds[ctx->active_verb - 1];
                    }
                    char action[128];
                    snprintf(action, sizeof(action), "%s %s", verb, ctx->hovered_object);
                    execute_command(ctx, action);
                } else {
                    /* Edge navigation fallback */
                    if (ctx->current_room == 0 && mouse_x < 30) execute_command(ctx, "nw");
                    else if (ctx->current_room == 1 && mouse_x < 40) execute_command(ctx, "west");
                    else if (ctx->current_room == 1 && mouse_y >= 110) execute_command(ctx, "se");
                    else if (ctx->current_room == 2 && mouse_x >= 240) execute_command(ctx, "east");
                    else execute_command(ctx, "look");
                }
            }
            /* 2. Click in Verb Bar (y=131..144) */
            else if (mouse_y >= 131 && mouse_y <= 144) {
                static const char *verbs[] = { "look", "take", "talk", "cast", "inv", "examine", "use" };
                int vx = 8;
                for (int i = 0; i < 7; i++) {
                    int vw = (i == 5) ? 54 : 38;
                    if (mouse_x >= vx && mouse_x <= vx + vw) {
                        ctx->active_verb = i + 1;
                        if (i == 0) execute_command(ctx, "look");
                        else if (i == 4) execute_command(ctx, "inventory");
                        else {
                            snprintf(ctx->cmd_buffer, sizeof(ctx->cmd_buffer), "%s ", verbs[i]);
                            ctx->cmd_len = (int)strlen(ctx->cmd_buffer);
                        }
                        break;
                    }
                    vx += vw + 4;
                }
            }
            /* 3. Click in Compass (x=276..314, y=5..128) */
            else if (mouse_x >= 276 && mouse_x <= 314 && mouse_y >= 5 && mouse_y <= 128) {
                if (mouse_y >= 20 && mouse_y <= 36) {
                    if (ctx->current_room == 0) execute_command(ctx, "nw");
                } else if (mouse_y >= 37 && mouse_y <= 52) {
                    if (ctx->current_room == 1) execute_command(ctx, "west");
                    else if (ctx->current_room == 2) execute_command(ctx, "east");
                } else if (mouse_y >= 53 && mouse_y <= 68) {
                    if (ctx->current_room == 1) execute_command(ctx, "se");
                }
            }
        }

        /* Keyboard Input */
        if (key_code > 0) {
            if (key_code == 13) { /* Enter */
                if (ctx->cmd_len > 0) {
                    execute_command(ctx, ctx->cmd_buffer);
                    ctx->cmd_buffer[0] = '\0';
                    ctx->cmd_len = 0;
                }
            } else if (key_code == 8 || key_code == 127) { /* Backspace */
                if (ctx->cmd_len > 0) {
                    ctx->cmd_buffer[--ctx->cmd_len] = '\0';
                }
            } else if (key_code >= 32 && key_code <= 126) { /* Printable char */
                if (ctx->cmd_len + 1 < (int)sizeof(ctx->cmd_buffer) - 1) {
                    ctx->cmd_buffer[ctx->cmd_len++] = (char)key_code;
                    ctx->cmd_buffer[ctx->cmd_len] = '\0';
                }
            }
        }
    }
}

/* -------------------------------------------------------------------------
 * Framebuffer Verification
 * ------------------------------------------------------------------------- */
double engine_verify_framebuffer(const uint8_t *screen_buffer) {
    if (!screen_buffer) return 0.0;

    size_t non_black = 0;
    for (size_t i = 0; i < HAL_VIDEO_FRAME_SIZE; i++) {
        if (screen_buffer[i] != 0) {
            non_black++;
        }
    }
    return (double)non_black / (double)HAL_VIDEO_FRAME_SIZE;
}
