/*
 * guest_state.h — read-only observation of the retail game's own state.
 *
 * Host features (the dev menu, controller helpers) must act only when the
 * game itself is idle in the field. The retail main loop (image 08A7:0000)
 * polls get_event (exe 39607) from one call site; every modal state (title,
 * dialogs, message boxes, timed waits, turns) polls from a different site or
 * not at all. See docs/GUEST_UI_SEMANTICS.md section 6.
 *
 * The observer installs two observe-only CPU hooks: get_event's entry, which
 * records the caller and arguments and invalidates idle, and the main loop's
 * return site, which marks the field idle only when the main loop's own call
 * returned an idle event. Both let the instruction run normally: no guest
 * byte, register or cycle count changes.
 */
#ifndef GUEST_STATE_H
#define GUEST_STATE_H

#include <stdbool.h>
#include <stdint.h>

#include "vm.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Retail addresses (load-image offsets; see docs/GUEST_UI_SEMANTICS.md). */
#define GUEST_GET_EVENT_IMAGE      39607u   /* exe_39607: get_event(mask, &event) */
#define GUEST_MAIN_POLL_RETURN     35856u   /* 08A7:01A0, the main loop's return site */
#define GUEST_DS_EVENT_RECORD      0x69E2u  /* the main loop's event record {type,x,y,code} */
#define GUEST_DS_EVENT_READ        0x0072u  /* synthetic event ring read index */
#define GUEST_DS_EVENT_WRITE       0x0074u  /* synthetic event ring write index */
#define GUEST_DS_PLAYBACK          0x07E4u  /* 1 while recorded input plays back */
#define GUEST_DS_VIEW_SWITCH       0x0058u  /* set during a view-mode switch */
#define GUEST_DS_MAP_VIEW          0x0056u  /* 1 in the map view */

typedef enum {
    GUEST_IDLE_UNKNOWN = 0,   /* no poll observed yet */
    GUEST_IDLE_FIELD,         /* main loop got an idle event; empty queue, no guard */
    GUEST_IDLE_MAP,           /* as FIELD, but in the map view */
    GUEST_BUSY_EVENT,         /* main loop is fetching or acting on an event */
    GUEST_BUSY_QUEUE,         /* main loop with synthetic events pending */
    GUEST_BUSY_GUARD,         /* main loop during playback or a view switch */
    GUEST_BUSY_MODAL          /* last poll came from another site */
} guest_idle_state;

/* Install the observer. Fails (and installs nothing) if the observer was
 * already installed, or another hook already owns either address. */
bool guest_state_install(const vm *m);
void guest_state_uninstall(void);
bool guest_state_installed(void);

/* Classify the game's current input state from its own variables. */
guest_idle_state guest_state_classify(void);
bool guest_state_field_idle(void);          /* classify() == GUEST_IDLE_FIELD */
const char *guest_state_name(guest_idle_state s);

/* Diagnostics: the last get_event caller as a load-image offset (0 when it
 * lies outside the EXE image, e.g. in an overlay), its runtime CS:IP, the
 * DGROUP segment seen at that poll, and the number of polls so far. */
uint32_t guest_state_last_caller_image(void);
uint32_t guest_state_last_caller_csip(void);
uint16_t guest_state_dgroup(void);
uint64_t guest_state_poll_count(void);
uint16_t guest_state_last_event_type(void);  /* type the main loop last received */

#ifdef __cplusplus
}
#endif

#endif /* GUEST_STATE_H */
