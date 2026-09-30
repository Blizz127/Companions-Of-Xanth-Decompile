#include "controller_guest_actions.h"
#include <limits.h>
#define MAX_ROWS 256u
static bool read_word(const controller_guest_ui_view *v, uint16_t offset, uint16_t *out) {
    if (!v || !v->memory || !v->dgroup_segment) return false;
    size_t p = ((size_t)v->dgroup_segment << 4) + offset;
    if (offset > 0xfffeu || p > 0xffffeu || p > v->memory_size ||
        v->memory_size - p < 2) return false;
    *out = (uint16_t)(v->memory[p] | ((uint16_t)v->memory[p + 1] << 8));
    return true;
}
controller_guest_ui_status controller_guest_action_resolve(
        const controller_guest_ui_view *v, controller_guest_action action,
        controller_guest_action_target *out) {
    uint16_t x, y, mode;
    if (!out || (action != CONTROLLER_GUEST_ACTION_SNAP &&
        action != CONTROLLER_GUEST_ACTION_PREVIOUS_VERB &&
        action != CONTROLLER_GUEST_ACTION_NEXT_VERB) ||
        !read_word(v, 0x69e4, &x) || !read_word(v, 0x69e6, &y) ||
        !read_word(v, 0x0056, &mode)) return CONTROLLER_GUEST_UI_INVALID;
    if (x > 319 || y > 199) return CONTROLLER_GUEST_UI_INVALID;
    if (mode) return CONTROLLER_GUEST_UI_NONE;
    controller_guest_ui_region hit = {0};
    controller_guest_ui_status status = controller_guest_ui_hit(v, (int16_t)x, (int16_t)y, &hit);
    if (status == CONTROLLER_GUEST_UI_INVALID) return status;
    if (action == CONTROLLER_GUEST_ACTION_SNAP) {
        uint16_t hover;
        if (!read_word(v, 0x0062, &hover)) return CONTROLLER_GUEST_UI_INVALID;
        if (status != CONTROLLER_GUEST_UI_HIT || (hit.type != 3 && hit.type != 7) ||
            !hit.object_id || hover != hit.object_id) return CONTROLLER_GUEST_UI_NONE;
        int cx = ((int)hit.x0 + hit.x1) / 2, cy = ((int)hit.y0 + hit.y1) / 2;
        int16_t sx, sy;
        status = controller_guest_ui_snap(v, hit.group, hit.index, (int16_t)cx, (int16_t)cy, &sx, &sy);
        if (status != CONTROLLER_GUEST_UI_HIT) return status;
        controller_guest_ui_region checked;
        status = controller_guest_ui_hit(v, sx, sy, &checked);
        if (status != CONTROLLER_GUEST_UI_HIT) return status;
        if (checked.group != hit.group || checked.index != hit.index ||
            checked.object_id != hover || (checked.flags & 0x80u)) return CONTROLLER_GUEST_UI_NONE;
        *out = (controller_guest_action_target){sx, sy, hit.group, hit.index, 0};
        return CONTROLLER_GUEST_UI_HIT;
    }
    controller_guest_ui_verb_row rows[MAX_ROWS]; size_t count = 0;
    status = controller_guest_ui_verb_rows(v, rows, MAX_ROWS, &count);
    if (status != CONTROLLER_GUEST_UI_HIT) return status;
    if (count > MAX_ROWS) return CONTROLLER_GUEST_UI_INVALID;
    uint16_t height;
    if (!read_word(v, 0x5c32, &height) || !height || height > 200)
        return CONTROLLER_GUEST_UI_INVALID;
    size_t current = count;
    if (hit.type == 8) {
        for (size_t i = 0; i < count; i++) {
            if (rows[i].group == hit.group && rows[i].index == hit.index &&
                (int)y >= rows[i].row_top && (int)y < (int)rows[i].row_top + height) {
                current = i; break;
            }
        }
    }
    size_t next;
    if (current == count) next = action == CONTROLLER_GUEST_ACTION_NEXT_VERB ? 0 : count - 1;
    else if (action == CONTROLLER_GUEST_ACTION_NEXT_VERB) next = (current + 1) % count;
    else next = (current + count - 1) % count;
    *out = (controller_guest_action_target){rows[next].x, rows[next].y,
        rows[next].group, rows[next].index, rows[next].verb_id};
    return CONTROLLER_GUEST_UI_HIT;
}
