#ifndef XANTH_CONTROLLER_GUEST_UI_H
#define XANTH_CONTROLLER_GUEST_UI_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Borrowed, paused VM memory. Calls read live tables; never retain pointers or
 * records across VM execution, and never substitute boundary CPU DS for DGROUP. */
typedef struct {
    const uint8_t *memory;
    size_t memory_size;
    uint16_t dgroup_segment; /* Verified by guest_state_dgroup(); zero declines. */
} controller_guest_ui_view;
typedef struct {
    uint16_t group, index, object_id;
    int16_t type, x0, y0, x1, y1;
    uint8_t flags;
} controller_guest_ui_region;
typedef enum {
    CONTROLLER_GUEST_UI_INVALID = -1,
    CONTROLLER_GUEST_UI_NONE = 0,
    CONTROLLER_GUEST_UI_HIT = 1
} controller_guest_ui_status;
/* Conservative safety ceilings; unsupported layouts decline rather than wrap
 * pointers, allocate without bounds, or approximate the guest's hit test. */
#define CONTROLLER_GUEST_UI_MAX_GROUPS 8
#define CONTROLLER_GUEST_UI_MAX_RECORDS 256
#define CONTROLLER_GUEST_UI_MAX_VERTICES 256

controller_guest_ui_status controller_guest_ui_hit(const controller_guest_ui_view *view,
    int16_t x, int16_t y, controller_guest_ui_region *hit);
/* Return the enabled type 3/5/6/7/8 records in table order. The returned records
 * are descriptive only: snap re-reads them, and resolves overlap through hit. */
controller_guest_ui_status controller_guest_ui_candidates(const controller_guest_ui_view *view,
    controller_guest_ui_region *regions, size_t capacity, size_t *count);
/* Find the nearest on-screen pixel that the exact last-wins hit test maps to
 * this current group/index. Fully obscured or off-screen records return NONE.
 * Caller re-queries on each action; there is no across-frame cache. */
controller_guest_ui_status controller_guest_ui_snap(const controller_guest_ui_view *view,
    uint16_t group, uint16_t index, int16_t from_x, int16_t from_y,
    int16_t *snap_x, int16_t *snap_y);
typedef struct {
    uint16_t group, index, row, verb_id;
    int16_t x, y, row_top;
} controller_guest_ui_verb_row;
/* Read current standard/context lists and font row height. Return only nonzero
 * verbs with a visible point whose exact hit resolves to the same type-8 record.
 * count is the required capacity; consume at most capacity entries. No guest
 * writes: malformed or unterminated lists decline, including the standard
 * getter's not-yet-installed terminator. */
controller_guest_ui_status controller_guest_ui_verb_rows(const controller_guest_ui_view *view,
    controller_guest_ui_verb_row *rows, size_t capacity, size_t *count);
#endif
