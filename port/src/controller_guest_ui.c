#include "controller_guest_ui.h"
#include <limits.h>
#include <string.h>

/* Source evidence: exe_109530 and exe_112178, GUEST_UI_SEMANTICS.md.
 * The polygon routine uses signed word differences and integer intersections,
 * including its horizontal-edge/vertex rules and BOTH ray parities. */
#define GROUP_COUNT 0x51deu
#define GROUP_POINTERS 0x67c2u
#define GROUP_COUNTS 0x67e2u
#define RECORD_BYTES 20u
#define MAX_TOTAL_VERTICES 4096u

typedef struct {
    controller_guest_ui_region region;
    uint16_t vertices;
    size_t polygon;
} record;
typedef struct {
    const controller_guest_ui_view *view;
    record records[CONTROLLER_GUEST_UI_MAX_RECORDS];
    size_t count;
} table;

static bool span(const controller_guest_ui_view *v, uint16_t segment, uint16_t offset,
                 size_t length, size_t *address) {
    size_t base = ((size_t)segment << 4) + offset;
    if (!v || !v->memory || (size_t)offset + length > 0x10000u ||
        base > 0x100000u || length > 0x100000u - base ||
        base > v->memory_size || length > v->memory_size - base) return false;
    *address = base;
    return true;
}
static uint16_t word(const controller_guest_ui_view *v, size_t p) {
    return (uint16_t)(v->memory[p] | ((uint16_t)v->memory[p + 1] << 8));
}
static int16_t signed_word(uint16_t value) {
    return value <= INT16_MAX ? (int16_t)value : (int16_t)((int32_t)value - 65536);
}
static int16_t sub_word(int16_t a, int16_t b) {
    return signed_word((uint16_t)((uint16_t)a - (uint16_t)b));
}
static bool load(const controller_guest_ui_view *v, table *t) {
    size_t count_address, pointer_address, counts_address;
    if (!v || !v->dgroup_segment) return false;
    uint16_t ds = v->dgroup_segment;
    if (!span(v, ds, GROUP_COUNT, 2, &count_address)) return false;
    uint16_t groups = word(v, count_address);
    if (groups > CONTROLLER_GUEST_UI_MAX_GROUPS ||
        !span(v, ds, GROUP_POINTERS, groups * 4u, &pointer_address) ||
        !span(v, ds, GROUP_COUNTS, groups * 2u, &counts_address)) return false;
    t->view = v;
    t->count = 0;
    size_t total_vertices = 0;
    for (uint16_t g = 0; g < groups; g++) {
        uint16_t count = word(v, counts_address + g * 2u);
        uint16_t offset = word(v, pointer_address + g * 4u);
        uint16_t segment = word(v, pointer_address + g * 4u + 2u);
        size_t base;
        if (count > CONTROLLER_GUEST_UI_MAX_RECORDS - t->count) return false;
        if (!count) continue;
        if ((!offset && !segment) || !span(v, segment, offset, count * RECORD_BYTES, &base)) return false;
        for (uint16_t i = 0; i < count; i++) {
            size_t p = base + i * RECORD_BYTES;
            record *r = &t->records[t->count++];
            r->region = (controller_guest_ui_region){g, i, word(v, p + 10),
                (int16_t)(v->memory[p] < 128 ? v->memory[p] : (int)v->memory[p] - 256),
                signed_word(word(v, p + 2)), signed_word(word(v, p + 4)),
                signed_word(word(v, p + 6)), signed_word(word(v, p + 8)), v->memory[p + 1]};
            r->vertices = 0;
            r->polygon = 0;
            if (r->region.type == 3 && !(r->region.flags & 0x80u)) {
                r->vertices = word(v, p + 14);
                if (r->vertices > CONTROLLER_GUEST_UI_MAX_VERTICES ||
                    r->vertices > MAX_TOTAL_VERTICES - total_vertices) return false;
                total_vertices += r->vertices;
                if (r->vertices) {
                    uint16_t po = word(v, p + 16), ps = word(v, p + 18);
                    if ((!po && !ps) || !span(v, ps, po, r->vertices * 4u, &r->polygon)) return false;
                }
            }
        }
    }
    return true;
}
static int16_t vx(const table *t, const record *r, unsigned i) {
    return signed_word(word(t->view, r->polygon + i * 4u));
}
static int16_t vy(const table *t, const record *r, unsigned i) {
    return signed_word(word(t->view, r->polygon + i * 4u + 2u));
}
static bool contains(const table *t, const record *r, int16_t x, int16_t y) {
    const controller_guest_ui_region *b = &r->region;
    if (x < b->x0 || x > b->x1 || y < b->y0 || y > b->y1) return false;
    if (!r->vertices) return true;
    unsigned left = 0, right = 0, n = r->vertices;
    for (unsigned i = 0, previous = n - 1; i < n; previous = i++) {
        int16_t ax = vx(t, r, previous), ay = vy(t, r, previous);
        int16_t bx = vx(t, r, i), by = vy(t, r, i), distance;
        if (ay == y && by == ay) {
            if ((ax <= x && bx >= x) || (bx <= x && ax >= x)) return true;
            continue;
        }
        if (by == y) {
            int16_t next_y = vy(t, r, (i + 1) % n);
            if (next_y == by) {
                int16_t after_y = vy(t, r, (i + 2) % n);
                if (by < ay && after_y > by) continue;
                if (by > ay && after_y < by) continue;
            } else {
                if (by < ay && next_y > by) continue;
                if (by > ay && next_y < by) continue;
            }
            distance = sub_word(bx, x);
        } else {
            if (!((ay < y && by > y) || (by < y && ay > y))) continue;
            int16_t dx = sub_word(bx, ax), dy = sub_word(y, ay);
            int16_t denominator = sub_word(by, ay);
            /* The guest's signed long helper returns quotient low word in AX. */
            int32_t quotient = (int32_t)dx * dy / denominator;
            distance = signed_word((uint16_t)((uint16_t)quotient - (uint16_t)x + (uint16_t)ax));
        }
        if (!distance) return true;
        if (distance < 0) left++; else right++;
    }
    return (left & 1u) && (right & 1u);
}
static const record *hit_record(const table *t, int16_t x, int16_t y) {
    const record *hit = NULL;
    for (size_t i = 0; i < t->count; i++) {
        const record *r = &t->records[i];
        if (!(r->region.flags & 0x80u) && contains(t, r, x, y)) hit = r;
    }
    return hit;
}
static bool candidate(const record *r) {
    int type = r->region.type;
    return !(r->region.flags & 0x80u) && (type == 3 || type == 5 || type == 6 || type == 7 || type == 8);
}
controller_guest_ui_status controller_guest_ui_hit(const controller_guest_ui_view *v,
        int16_t x, int16_t y, controller_guest_ui_region *hit) {
    table t;
    if (!load(v, &t)) return CONTROLLER_GUEST_UI_INVALID;
    const record *r = hit_record(&t, x, y);
    if (!r) return CONTROLLER_GUEST_UI_NONE;
    if (hit) *hit = r->region;
    return CONTROLLER_GUEST_UI_HIT;
}
controller_guest_ui_status controller_guest_ui_candidates(const controller_guest_ui_view *v,
        controller_guest_ui_region *regions, size_t capacity, size_t *count) {
    table t;
    if (count) *count = 0;
    if (!load(v, &t)) return CONTROLLER_GUEST_UI_INVALID;
    size_t n = 0;
    for (size_t i = 0; i < t.count; i++) if (candidate(&t.records[i])) {
        if (regions && n < capacity) regions[n] = t.records[i].region;
        n++;
    }
    if (count) *count = n;
    return n ? CONTROLLER_GUEST_UI_HIT : CONTROLLER_GUEST_UI_NONE;
}
controller_guest_ui_status controller_guest_ui_snap(const controller_guest_ui_view *v,
        uint16_t group, uint16_t index, int16_t from_x, int16_t from_y,
        int16_t *snap_x, int16_t *snap_y) {
    table t;
    if (!load(v, &t)) return CONTROLLER_GUEST_UI_INVALID;
    const record *target = NULL;
    for (size_t i = 0; i < t.count; i++)
        if (t.records[i].region.group == group && t.records[i].region.index == index)
            target = &t.records[i];
    if (!target || !candidate(target)) return CONTROLLER_GUEST_UI_NONE;
    int x0 = target->region.x0 < 0 ? 0 : target->region.x0;
    int y0 = target->region.y0 < 0 ? 0 : target->region.y0;
    int x1 = target->region.x1 > 319 ? 319 : target->region.x1;
    int y1 = target->region.y1 > 199 ? 199 : target->region.y1;
    int64_t best = INT64_MAX;
    int16_t best_x = 0, best_y = 0;
    for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
        int64_t dx = x - from_x, dy = y - from_y;
        int64_t distance = dx * dx + dy * dy;
        if (distance >= best) continue;
        if (hit_record(&t, (int16_t)x, (int16_t)y) != target) continue;
        best = distance; best_x = (int16_t)x; best_y = (int16_t)y;
    }
    if (best == INT64_MAX) return CONTROLLER_GUEST_UI_NONE;
    if (snap_x) *snap_x = best_x;
    if (snap_y) *snap_y = best_y;
    return CONTROLLER_GUEST_UI_HIT;
}

/* exe_36771 selects the standard list for index 6, regardless of group.
 * exe_52687 returns DS:5A32:0000 after writing its terminator at DS:0102.
 * We require that terminator already exists; host inspection never writes it. */
#define MAX_VERBS 64u
static bool verb_list(const table *t, bool standard, uint16_t verbs[MAX_VERBS], size_t *count) {
    const controller_guest_ui_view *v = t->view;
    size_t p, base;
    uint16_t segment, offset, limit = MAX_VERBS;
    if (standard) {
        if (!span(v, v->dgroup_segment, 0x5a32, 2, &p)) return false;
        segment = word(v, p); offset = 0;
        if (!span(v, v->dgroup_segment, 0x0102, 2, &p)) return false;
        limit = word(v, p);
        if (limit > MAX_VERBS) return false;
    } else {
        if (!span(v, v->dgroup_segment, 0x5c34, 4, &p)) return false;
        offset = word(v, p); segment = word(v, p + 2);
    }
    if ((!segment && !offset)) return false;
    *count = 0;
    for (size_t i = 0; i <= limit; i++) {
        if ((size_t)offset + i * 2u > UINT16_MAX ||
            !span(v, segment, (uint16_t)(offset + i * 2u), 2, &base)) return false;
        uint16_t verb = word(v, base);
        if (!verb) return true;
        if (i == limit) return false;
        verbs[(*count)++] = verb;
    }
    return false;
}
controller_guest_ui_status controller_guest_ui_verb_rows(const controller_guest_ui_view *v,
        controller_guest_ui_verb_row *rows, size_t capacity, size_t *count) {
    table t; size_t p, n = 0;
    if (count) *count = 0;
    if (!load(v, &t) || !span(v, v->dgroup_segment, 0x5c32, 2, &p))
        return CONTROLLER_GUEST_UI_INVALID;
    int height = signed_word(word(v, p));
    if (height <= 0 || height > 200) return CONTROLLER_GUEST_UI_INVALID;
    for (size_t i = 0; i < t.count; i++) {
        const record *r = &t.records[i];
        if (r->region.type != 8 || (r->region.flags & 0x80u)) continue;
        /* exe_36771 obtains row origin from group 0 even when handed an index.
         * Other groups are unsupported layouts, not interchangeable panels. */
        if (r->region.group != 0) return CONTROLLER_GUEST_UI_INVALID;
        uint16_t verbs[MAX_VERBS]; size_t verb_count;
        if (!verb_list(&t, r->region.index == 6, verbs, &verb_count)) return CONTROLLER_GUEST_UI_INVALID;
        for (size_t row = 0; row < verb_count; row++) {
            int top = r->region.y0 + (int)row * height;
            int y0 = top < 0 ? 0 : top;
            int y1 = top + height - 1;
            if (y1 > r->region.y1) y1 = r->region.y1;
            if (y1 > 199) y1 = 199;
            int x0 = r->region.x0 < 0 ? 0 : r->region.x0;
            int x1 = r->region.x1 > 319 ? 319 : r->region.x1;
            int center_x = ((int)r->region.x0 + r->region.x1) / 2;
            int center_y = top + height / 2;
            int64_t best = INT64_MAX; int16_t bx = 0, by = 0;
            for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
                int64_t dx = x - center_x, dy = y - center_y;
                int64_t distance = dx * dx + dy * dy;
                if (distance >= best || hit_record(&t, (int16_t)x, (int16_t)y) != r) continue;
                best = distance; bx = (int16_t)x; by = (int16_t)y;
            }
            if (best == INT64_MAX) continue;
            if (rows && n < capacity) rows[n] = (controller_guest_ui_verb_row){
                r->region.group, r->region.index, (uint16_t)row, verbs[row], bx, by, (int16_t)top};
            n++;
        }
    }
    if (count) *count = n;
    return n ? CONTROLLER_GUEST_UI_HIT : CONTROLLER_GUEST_UI_NONE;
}
