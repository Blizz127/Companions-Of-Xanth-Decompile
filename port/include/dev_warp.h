/*
 * dev_warp.h — dev-menu warps through the game's own Restore dialog.
 *
 * A checkpoint is a save the game's own Save dialog wrote at a recorded
 * route point, kept in a user-local directory (never in the repository).
 * A warp copies it into a free save slot, waits until the game is idle in
 * the field, then types what a player would: R to open "Restore Game", the
 * checkpoint's label to select it, Enter to restore. No guest memory is
 * written. Only checkpoints a live sweep has verified are offered.
 *
 * The list lives in <checkpoint dir>/checkpoints.txt, one tab-separated
 * line per checkpoint:
 *     id  label  region  area  spot  verified(0/1)  sha256-of-save
 *     [room  score  step  step-name  items]
 * and each save is <checkpoint dir>/<id>.SAV. room and score are the game's
 * own progress variables (DS:0256, DS:0264) recorded when the save was made;
 * step > 0 marks the state at the end of that step of the published route.
 */
#ifndef DEV_WARP_H
#define DEV_WARP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DEV_WARP_MAX 64

typedef struct {
    char id[32];
    char label[32];
    char region[32];
    char area[48];
    char spot[48];
    bool verified;
    int room, score, items;   /* -1 when not recorded */
    int step;                 /* 0: plain warp spot */
    char step_name[48];
} dev_warp_entry;

typedef struct {
    bool (*field_idle)(void);                    /* guest_state_field_idle */
    bool (*game_modal)(void);                    /* a modal dialog owns input */
    void (*post_key)(uint8_t scan, uint8_t ascii);
    char save_dir[512];                          /* the game's save directory */
    char checkpoint_dir[512];
} dev_warp_host;

typedef enum {
    DEV_WARP_IDLE = 0,
    DEV_WARP_RUNNING,
    DEV_WARP_DONE,
    DEV_WARP_FAILED
} dev_warp_status;

/* Load the checkpoint list; include_unverified is for sweeps only. Returns
 * the number of entries offered. */
int  dev_warp_load(const dev_warp_host *host, bool include_unverified);
int  dev_warp_count(void);
const dev_warp_entry *dev_warp_get(int index);
int  dev_warp_find(const char *id);

/* Distinct regions, areas within a region, spots within an area, in list
 * order. Each returns the count and fills out[] with entry indices of the
 * first entry of each region/area, or every spot. */
int  dev_warp_regions(int *out, int max);
int  dev_warp_areas(const char *region, int *out, int max);
int  dev_warp_spots(const char *region, const char *area, int *out, int max);

/* Start a warp; false (with a message) if one is running or the entry is
 * unusable. dev_warp_tick advances it once per presented frame. */
bool dev_warp_request(int index, char *msg, size_t msg_size);
dev_warp_status dev_warp_tick(void);
bool dev_warp_active(void);
const char *dev_warp_message(void);   /* last result, for the toast and log */
bool dev_warp_used(void);             /* any warp completed this session */

/* Story steps (Finish Area). Given the live room, score and inventory count
 * (DS:69FC), the entry that
 * completes the step the player is on, or -1 if the progress is not on the
 * recorded route. The step's start is the previous step's end (or a fresh
 * game with score 0); the player is on it while start <= score < end, or at
 * its exact start when the step scores nothing. */
int  dev_warp_current_step(int room, int score, int items);
/* The last step entry of the given area, or -1. */
int  dev_warp_area_end(const char *region, const char *area);
/* The step entry with the given order, or -1. */
int  dev_warp_step(int order);

void dev_warp_reset_for_tests(void);

#ifdef __cplusplus
}
#endif

#endif /* DEV_WARP_H */
