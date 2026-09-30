#ifndef XANTH_CONTROLLER_GUEST_ACTIONS_H
#define XANTH_CONTROLLER_GUEST_ACTIONS_H
#include "controller_guest_ui.h"

typedef enum {
    CONTROLLER_GUEST_ACTION_SNAP = 1,
    CONTROLLER_GUEST_ACTION_PREVIOUS_VERB,
    CONTROLLER_GUEST_ACTION_NEXT_VERB
} controller_guest_action;
typedef struct {
    int16_t x, y;
    uint16_t group, index, verb_id; /* verb_id is zero for object snap. */
} controller_guest_action_target;
/* Caller MUST have guest_state_field_idle(), mouse buttons zero, no pending
 * button edge, normal key, or pointer activity. Borrow paused live memory and
 * verified DGROUP. Resolver never posts events, writes memory, or caches state.
 * Map mode declines. HIT supplies a pointer target; NONE supplies no action.
 * On NONE/INVALID the output is untouched. */
controller_guest_ui_status controller_guest_action_resolve(
    const controller_guest_ui_view *view, controller_guest_action action,
    controller_guest_action_target *target);
#endif
