/*
 * dev_warp.c — dev-menu warps through the game's own Restore dialog.
 * See dev_warp.h. Everything the game sees is keystrokes a player could
 * type; the only host-side change is a save file placed in (and afterwards
 * removed from) the save directory, like swapping a memory card.
 */
#include "dev_warp.h"
#include "asset_check.h"
#include <ctype.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(_WIN32)
#define strtok_r strtok_s
#endif

#define DW_LOG(...) do { fprintf(stderr, "[DEV_MENU] " __VA_ARGS__); fputc('\n', stderr); } while (0)

/* Frame budgets at 70 Hz. */
#define DW_IDLE_TIMEOUT     700    /* field-idle must come within 10 s */
#define DW_DIALOG_TIMEOUT   350    /* the Restore dialog must open within 5 s */
#define DW_DIALOG_SETTLE     10
#define DW_KEY_GAP            3
#define DW_RESTORE_TIMEOUT 2100    /* the restore must finish within 30 s */

typedef enum {
    W_IDLE = 0, W_WAIT_IDLE, W_WAIT_DIALOG, W_SETTLE, W_TYPE, W_WAIT_DONE
} dw_state;

static struct {
    dev_warp_host host;
    dev_warp_entry entries[DEV_WARP_MAX];
    int count;

    dw_state state;
    int target;
    int frames, deadline;
    int typed;
    bool left_idle;
    bool used;
    char slot_path[600];
    char message[160];
} s_dw;

/* ------------------------------------------------------------------------ */

static void copy_field(char *dst, size_t size, const char *src) {
    snprintf(dst, size, "%s", src ? src : "");
}

static bool file_exists(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) return false;
    fclose(f);
    return true;
}

int dev_warp_load(const dev_warp_host *host, bool include_unverified) {
    char path[600], line[512];
    FILE *f;
    s_dw.count = 0;
    if (host) s_dw.host = *host;
    snprintf(path, sizeof(path), "%s/checkpoints.txt", s_dw.host.checkpoint_dir);
    if (!s_dw.host.checkpoint_dir[0] || !(f = fopen(path, "r"))) return 0;
    while (fgets(line, sizeof(line), f) && s_dw.count < DEV_WARP_MAX) {
        char *field[12] = {0}, *save = NULL, *tok;
        int n = 0;
        char save_path[600];
        line[strcspn(line, "\r\n")] = '\0';
        if (!line[0] || line[0] == '#') continue;
        for (tok = strtok_r(line, "\t", &save); tok && n < 12; tok = strtok_r(NULL, "\t", &save))
            field[n++] = tok;
        if (n < 7 || strlen(field[6]) != 64) continue;
        bool digest_valid = true;
        for (int j = 0; j < 64; ++j) digest_valid &= isxdigit((unsigned char)field[6][j]) != 0;
        if (!digest_valid) continue;
        dev_warp_entry *e = &s_dw.entries[s_dw.count];
        copy_field(e->id, sizeof(e->id), field[0]);
        copy_field(e->label, sizeof(e->label), field[1]);
        copy_field(e->region, sizeof(e->region), field[2]);
        copy_field(e->area, sizeof(e->area), field[3]);
        copy_field(e->spot, sizeof(e->spot), field[4]);
        e->verified = field[5][0] == '1';
        copy_field(e->sha256, sizeof(e->sha256), field[6]);
        for (int j = 0; j < 64; ++j) e->sha256[j] = (char)tolower((unsigned char)e->sha256[j]);
        e->room = n > 7 ? atoi(field[7]) : -1;
        e->score = n > 8 ? atoi(field[8]) : -1;
        e->step = n > 9 ? atoi(field[9]) : 0;
        copy_field(e->step_name, sizeof(e->step_name), n > 10 ? field[10] : "");
        e->items = n > 11 ? atoi(field[11]) : -1;
        snprintf(save_path, sizeof(save_path), "%s/%s.SAV", s_dw.host.checkpoint_dir, e->id);
        char actual[65];
        if ((!e->verified && !include_unverified) ||
            !xanth_sha256_file(save_path, actual) || strcmp(actual, e->sha256)) continue;
        s_dw.count++;
    }
    fclose(f);
    DW_LOG("warp checkpoints: %d offered from %s", s_dw.count, path);
    return s_dw.count;
}

int dev_warp_count(void) { return s_dw.count; }

const dev_warp_entry *dev_warp_get(int index) {
    return (index >= 0 && index < s_dw.count) ? &s_dw.entries[index] : NULL;
}

int dev_warp_find(const char *id) {
    for (int i = 0; i < s_dw.count; ++i)
        if (!strcmp(s_dw.entries[i].id, id)) return i;
    return -1;
}

int dev_warp_regions(int *out, int max) {
    int n = 0;
    for (int i = 0; i < s_dw.count && n < max; ++i) {
        bool seen = false;
        for (int j = 0; j < n; ++j) seen |= !strcmp(s_dw.entries[out[j]].region, s_dw.entries[i].region);
        if (!seen) out[n++] = i;
    }
    return n;
}

int dev_warp_areas(const char *region, int *out, int max) {
    int n = 0;
    for (int i = 0; i < s_dw.count && n < max; ++i) {
        bool seen = false;
        if (strcmp(s_dw.entries[i].region, region)) continue;
        for (int j = 0; j < n; ++j) seen |= !strcmp(s_dw.entries[out[j]].area, s_dw.entries[i].area);
        if (!seen) out[n++] = i;
    }
    return n;
}

int dev_warp_spots(const char *region, const char *area, int *out, int max) {
    int n = 0;
    for (int i = 0; i < s_dw.count && n < max; ++i)
        if (!strcmp(s_dw.entries[i].region, region) && !strcmp(s_dw.entries[i].area, area))
            out[n++] = i;
    return n;
}

int dev_warp_step(int order) {
    for (int i = 0; i < s_dw.count; ++i)
        if (s_dw.entries[i].step == order) return i;
    return -1;
}

/* The fingerprint at a step's start: the previous step's end, or a fresh
 * game (score 0, room and items unknown). */
static bool start_of(int order, int *room, int *score, int *items) {
    int prev = dev_warp_step(order - 1);
    if (order == 1) { *room = -1; *score = 0; *items = -1; return true; }
    if (prev < 0) return false;
    *room = s_dw.entries[prev].room;
    *score = s_dw.entries[prev].score;
    *items = s_dw.entries[prev].items;
    return *score >= 0;
}

static bool same_point(int r1, int s1, int i1, int r2, int s2, int i2) {
    return s1 == s2 && (r1 < 0 || r2 < 0 || r1 == r2) && (i1 < 0 || i2 < 0 || i1 == i2);
}

int dev_warp_current_step(int room, int score, int items) {
    for (int order = 1; order < 1000; ++order) {
        int end = dev_warp_step(order), sr, ss, si;
        const dev_warp_entry *e;
        if (end < 0) {
            if (dev_warp_step(order + 1) < 0) break;
            continue;
        }
        e = &s_dw.entries[end];
        if (!start_of(order, &sr, &ss, &si) || e->score < 0) continue;
        /* A step whose end looks exactly like its start cannot be told apart
         * once done: never offered. */
        if (same_point(sr, ss, si, e->room, e->score, e->items)) continue;
        if (e->score > ss) {
            if (score > ss && score < e->score) return end;
            /* At exactly the start score only the recorded start point counts,
             * so a finished step that scored nothing is not mistaken for it. */
            if (score == ss && same_point(sr, ss, si, room, score, items)) return end;
        } else if (same_point(sr, ss, si, room, score, items)) {
            return end;                 /* scores nothing: its exact start only */
        }
    }
    return -1;
}

int dev_warp_area_end(const char *region, const char *area) {
    int best = -1;
    for (int i = 0; i < s_dw.count; ++i) {
        const dev_warp_entry *e = &s_dw.entries[i];
        if (e->step > 0 && !strcmp(e->region, region) && !strcmp(e->area, area) &&
            (best < 0 || e->step > s_dw.entries[best].step))
            best = i;
    }
    return best;
}

/* ------------------------------------------------------------------------ */

static bool copy_file(const char *src, const char *dst) {
    char buf[4096];
    size_t n;
    bool ok = true;
    FILE *in = fopen(src, "rb"), *out;
    if (!in) return false;
    out = fopen(dst, "wbx"); /* Never overwrite an existing player save. */
    if (!out) { fclose(in); return false; }
    while ((n = fread(buf, 1, sizeof(buf), in)) > 0)
        if (fwrite(buf, 1, n, out) != n) { ok = false; break; }
    if (ferror(in)) ok = false;
    fclose(in);
    if (fclose(out) != 0) ok = false;
    if (!ok) remove(dst);
    return ok;
}

/* The lowest free slot, as the game's own Save would use; the Restore
 * dialog does not list high slot numbers. The file is removed again once
 * the restore has finished. */
static bool free_slot(char *out, size_t size) {
    for (int n = 0; n <= 99; ++n) {
        snprintf(out, size, "%s/XANTH%03d.SAV", s_dw.host.save_dir, n);
        if (!file_exists(out)) return true;
    }
    return false;
}

static void side_marker(const dev_warp_entry *e) {
    char path[600];
    FILE *f;
    time_t now = time(NULL);
    snprintf(path, sizeof(path), "%s/xanth-dev-menu.log", s_dw.host.save_dir);
    if (!(f = fopen(path, "a"))) return;
    fprintf(f, "%ld warp %s (%s / %s / %s): saves made after this may not match a normal playthrough\n",
            (long)now, e->id, e->region, e->area, e->spot);
    fclose(f);
}

static void finish(dev_warp_status status, const char *fmt, const char *arg) {
    snprintf(s_dw.message, sizeof(s_dw.message), fmt, arg);
    DW_LOG("%s", s_dw.message);
    if (s_dw.slot_path[0]) {
        remove(s_dw.slot_path);
        s_dw.slot_path[0] = '\0';
    }
    s_dw.state = W_IDLE;
    (void)status;
}

bool dev_warp_request(int index, char *msg, size_t msg_size) {
    char src[600];
    const dev_warp_entry *e = dev_warp_get(index);
    if (s_dw.state != W_IDLE) { snprintf(msg, msg_size, "Warp already in progress"); return false; }
    if (!e || !s_dw.host.field_idle || !s_dw.host.game_modal || !s_dw.host.post_key) {
        snprintf(msg, msg_size, "Warp unavailable");
        return false;
    }
    snprintf(src, sizeof(src), "%s/%s.SAV", s_dw.host.checkpoint_dir, e->id);
    char actual[65];
    if (!xanth_sha256_file(src, actual) || strcmp(actual, e->sha256)) {
        snprintf(msg, msg_size, "Warp refused: checkpoint changed since verification");
        return false;
    }
    if (!free_slot(s_dw.slot_path, sizeof(s_dw.slot_path)) || !copy_file(src, s_dw.slot_path)) {
        s_dw.slot_path[0] = '\0';
        snprintf(msg, msg_size, "Warp refused: cannot place the checkpoint save");
        DW_LOG("%s (%s)", msg, strerror(errno));
        return false;
    }
    if (!xanth_sha256_file(s_dw.slot_path, actual) || strcmp(actual, e->sha256)) {
        remove(s_dw.slot_path);
        s_dw.slot_path[0] = 0;
        snprintf(msg, msg_size, "Warp refused: checkpoint copy changed");
        return false;
    }
    s_dw.target = index;
    s_dw.state = W_WAIT_IDLE;
    s_dw.frames = 0;
    s_dw.deadline = DW_IDLE_TIMEOUT;
    s_dw.typed = 0;
    s_dw.left_idle = false;
    snprintf(msg, msg_size, "Warp to %s requested", e->spot);
    snprintf(s_dw.message, sizeof(s_dw.message), "%s", msg);
    DW_LOG("warp requested: %s -> %s (%s)", e->id, e->spot, s_dw.slot_path);
    return true;
}

/* Scan codes for the characters a label may use. */
static uint8_t scan_of(char ch) {
    static const char letters[] = "qwertyuiopasdfghjklzxcvbnm";
    static const uint8_t letter_scan[] = {
        0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
        0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
        0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32 };
    const char *p;
    if (ch == ' ') return 0x39;
    if (ch >= '1' && ch <= '9') return (uint8_t)(0x02 + (ch - '1'));
    if (ch == '0') return 0x0B;
    if ((p = strchr(letters, ch)) != NULL) return letter_scan[p - letters];
    return 0;
}

dev_warp_status dev_warp_tick(void) {
    const dev_warp_entry *e = dev_warp_get(s_dw.target);
    bool idle;
    if (s_dw.state == W_IDLE) return DEV_WARP_IDLE;
    if (!e) { finish(DEV_WARP_FAILED, "Warp failed: %s", "checkpoint vanished"); return DEV_WARP_FAILED; }
    idle = s_dw.host.field_idle();
    s_dw.frames++;

    switch (s_dw.state) {
    case W_WAIT_IDLE:
        if (idle) {
            s_dw.host.post_key(0x13, 'r');               /* R: Restore Game */
            s_dw.state = W_WAIT_DIALOG;
            s_dw.frames = 0;
            s_dw.deadline = DW_DIALOG_TIMEOUT;
        } else if (s_dw.frames > s_dw.deadline) {
            finish(DEV_WARP_FAILED, "Warp refused: %s", "the game is not idle in the field");
            return DEV_WARP_FAILED;
        }
        break;
    case W_WAIT_DIALOG:
        /* Type nothing until the dialog itself owns input: in the field the
         * same letters are verbs. */
        if (s_dw.host.game_modal()) {
            s_dw.state = W_SETTLE;
            s_dw.frames = 0;
        } else if (s_dw.frames > s_dw.deadline) {
            finish(DEV_WARP_FAILED, "Warp failed: %s", "the Restore dialog did not open");
            return DEV_WARP_FAILED;
        }
        break;
    case W_SETTLE:
        if (!s_dw.host.game_modal()) {
            finish(DEV_WARP_FAILED, "Warp failed: %s", "the Restore dialog closed early");
            return DEV_WARP_FAILED;
        }
        if (s_dw.frames >= DW_DIALOG_SETTLE) {
            s_dw.state = W_TYPE;
            s_dw.frames = 0;
        }
        break;
    case W_TYPE:
        if (!s_dw.host.game_modal()) {
            finish(DEV_WARP_FAILED, "Warp failed: %s", "the Restore dialog closed early");
            return DEV_WARP_FAILED;
        }
        if (s_dw.frames % DW_KEY_GAP) break;
        if (e->label[s_dw.typed]) {
            char ch = e->label[s_dw.typed++];
            s_dw.host.post_key(scan_of(ch), (uint8_t)ch);
        } else {
            s_dw.host.post_key(0x1C, 0x0D);              /* Enter: restore */
            s_dw.state = W_WAIT_DONE;
            s_dw.frames = 0;
            s_dw.deadline = DW_RESTORE_TIMEOUT;
        }
        break;
    case W_WAIT_DONE:
        if (idle && s_dw.frames > DW_DIALOG_SETTLE) {
            s_dw.used = true;
            side_marker(e);
            finish(DEV_WARP_DONE, "Warped to %s", e->spot);
            return DEV_WARP_DONE;
        }
        if (s_dw.frames > s_dw.deadline) {
            finish(DEV_WARP_FAILED, "Warp failed: %s", "the restore did not finish");
            return DEV_WARP_FAILED;
        }
        break;
    default:
        break;
    }
    return DEV_WARP_RUNNING;
}

bool dev_warp_active(void) { return s_dw.state != W_IDLE; }
const char *dev_warp_message(void) { return s_dw.message; }
bool dev_warp_used(void) { return s_dw.used; }

void dev_warp_shutdown(void) {
    if (s_dw.slot_path[0]) remove(s_dw.slot_path);
    s_dw.slot_path[0] = 0;
    s_dw.state = W_IDLE;
}

void dev_warp_reset_for_tests(void) {
    if (s_dw.slot_path[0]) remove(s_dw.slot_path);
    memset(&s_dw, 0, sizeof(s_dw));
}
