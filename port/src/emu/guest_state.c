/*
 * guest_state.c — read-only observation of the retail game's own state.
 *
 * Two observe-only hooks:
 *   - get_event's entry (exe 39607) records who asked, with the arguments
 *     from the stack (mask, event record), and invalidates idle: whatever
 *     the game was doing, it is asking for input again.
 *   - the main loop's return site (08A7:01A0, image 35856) reads the event
 *     the call just filled in. Only when that call was the main loop's own
 *     (mask 0x3FF, record at DGROUP:69E2) and the event is type 8 ("idle,
 *     no buttons") is the field marked idle. Any other event -- a key, a
 *     click, a queued command -- leaves it invalid, because the game is
 *     about to act on it.
 * Classification then adds the game's own queue indices and guard flags.
 * Nothing here writes guest memory, registers or cycle counts.
 */
#include "guest_state.h"

#include "cpu86.h"

#define GUEST_EVENT_MASK_ALL  0x03FFu
#define GUEST_EVENT_IDLE      0x0008u

static struct {
    bool installed;
    uint16_t load_seg;
    uint16_t entry_seg, entry_off;     /* get_event entry */
    uint16_t ret_seg, ret_off;         /* main loop return site */
    uint16_t dgroup;
    uint16_t caller_cs, caller_ip;
    uint16_t mask, event_off, event_seg;
    bool main_call;                    /* last entry was the main loop's verified call */
    bool idle;                         /* last return delivered an idle event */
    uint16_t last_event;
    uint64_t polls;
} s_gs;

static uint32_t image_of(uint16_t cs, uint16_t ip) {
    uint32_t lin = ((uint32_t)cs << 4) + ip;
    uint32_t base = (uint32_t)s_gs.load_seg << 4;
    return lin < base ? 0 : lin - base;
}

static hook_result_t on_get_event(cpu86 *c, void *user) {
    uint16_t ss = c->s[CPU_SS], sp = c->r[CPU_SP];
    (void)user;
    /* Far call: [SP] = return IP, [SP+2] = return CS, then the arguments
     * get_event(mask, far *event): [SP+4] mask, [SP+6] offset, [SP+8] seg. */
    s_gs.caller_ip = seg_r16(ss, sp);
    s_gs.caller_cs = seg_r16(ss, (uint16_t)(sp + 2));
    s_gs.mask      = seg_r16(ss, (uint16_t)(sp + 4));
    s_gs.event_off = seg_r16(ss, (uint16_t)(sp + 6));
    s_gs.event_seg = seg_r16(ss, (uint16_t)(sp + 8));
    s_gs.dgroup = c->s[CPU_DS];
    s_gs.polls++;
    s_gs.idle = false;
    s_gs.main_call = image_of(s_gs.caller_cs, s_gs.caller_ip) == GUEST_MAIN_POLL_RETURN &&
                     s_gs.mask == GUEST_EVENT_MASK_ALL &&
                     s_gs.event_off == GUEST_DS_EVENT_RECORD &&
                     s_gs.event_seg == s_gs.dgroup;
    return HOOK_CONTINUE;
}

static hook_result_t on_main_return(cpu86 *c, void *user) {
    (void)c; (void)user;
    if (s_gs.main_call) {
        s_gs.last_event = seg_r16(s_gs.event_seg, s_gs.event_off);
        s_gs.idle = s_gs.last_event == GUEST_EVENT_IDLE;
    } else {
        s_gs.idle = false;
    }
    s_gs.main_call = false;
    return HOOK_CONTINUE;
}

static void split(uint32_t image, uint16_t *seg, uint16_t *off) {
    uint32_t lin = ((uint32_t)s_gs.load_seg << 4) + image;
    *seg = (uint16_t)(lin >> 4);
    *off = (uint16_t)(lin & 0xF);
}

bool guest_state_install(const vm *m) {
    if (s_gs.installed || !m) return false;
    s_gs.load_seg = m->img.load_seg;
    split(GUEST_GET_EVENT_IMAGE, &s_gs.entry_seg, &s_gs.entry_off);
    split(GUEST_MAIN_POLL_RETURN, &s_gs.ret_seg, &s_gs.ret_off);
    if (cpu86_hook_present(s_gs.entry_seg, s_gs.entry_off) ||
        cpu86_hook_present(s_gs.ret_seg, s_gs.ret_off))
        return false;
    if (!cpu86_hook_install(s_gs.entry_seg, s_gs.entry_off, on_get_event, NULL))
        return false;
    if (!cpu86_hook_install(s_gs.ret_seg, s_gs.ret_off, on_main_return, NULL)) {
        cpu86_hook_remove(s_gs.entry_seg, s_gs.entry_off);
        return false;
    }
    s_gs.installed = true;
    s_gs.polls = 0;
    s_gs.caller_cs = s_gs.caller_ip = 0;
    s_gs.dgroup = 0;
    s_gs.main_call = s_gs.idle = false;
    s_gs.last_event = 0;
    return true;
}

void guest_state_uninstall(void) {
    if (s_gs.installed) {
        cpu86_hook_remove(s_gs.entry_seg, s_gs.entry_off);
        cpu86_hook_remove(s_gs.ret_seg, s_gs.ret_off);
    }
    s_gs.installed = false;
}

bool guest_state_installed(void) { return s_gs.installed; }

uint32_t guest_state_last_caller_image(void) {
    return s_gs.polls ? image_of(s_gs.caller_cs, s_gs.caller_ip) : 0;
}

uint32_t guest_state_last_caller_csip(void) {
    return ((uint32_t)s_gs.caller_cs << 16) | s_gs.caller_ip;
}

uint16_t guest_state_dgroup(void) { return s_gs.dgroup; }

uint64_t guest_state_poll_count(void) { return s_gs.polls; }

uint16_t guest_state_last_event_type(void) { return s_gs.last_event; }

guest_idle_state guest_state_classify(void) {
    uint16_t ds = s_gs.dgroup;
    if (!s_gs.installed || !s_gs.polls) return GUEST_IDLE_UNKNOWN;
    if (guest_state_last_caller_image() != GUEST_MAIN_POLL_RETURN) return GUEST_BUSY_MODAL;
    if (!s_gs.idle) return GUEST_BUSY_EVENT;
    if (seg_r16(ds, GUEST_DS_EVENT_READ) != seg_r16(ds, GUEST_DS_EVENT_WRITE))
        return GUEST_BUSY_QUEUE;
    if (seg_r16(ds, GUEST_DS_PLAYBACK) == 1 || seg_r16(ds, GUEST_DS_VIEW_SWITCH) != 0)
        return GUEST_BUSY_GUARD;
    if (seg_r16(ds, GUEST_DS_MAP_VIEW) == 1) return GUEST_IDLE_MAP;
    return GUEST_IDLE_FIELD;
}

bool guest_state_field_idle(void) {
    return guest_state_classify() == GUEST_IDLE_FIELD;
}

const char *guest_state_name(guest_idle_state s) {
    switch (s) {
    case GUEST_IDLE_FIELD: return "field-idle";
    case GUEST_IDLE_MAP:   return "map-idle";
    case GUEST_BUSY_EVENT: return "busy-event";
    case GUEST_BUSY_QUEUE: return "busy-queue";
    case GUEST_BUSY_GUARD: return "busy-guard";
    case GUEST_BUSY_MODAL: return "busy-modal";
    default:               return "unknown";
    }
}
