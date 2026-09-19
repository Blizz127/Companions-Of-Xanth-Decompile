#include "port_rgn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline uint16_t read_u16(const uint8_t *p) {
    return (uint16_t)(p[0] | (p[1] << 8));
}

static inline int16_t read_s16(const uint8_t *p) {
    return (int16_t)(p[0] | (p[1] << 8));
}

RgnContainer *rgn_load(const char *path) {
    if (!path) return NULL;

    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "[RGN] Cannot open region file: %s\n", path);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);

    if (sz < 6) {
        fprintf(stderr, "[RGN] File too small: %s (%ld bytes)\n", path, sz);
        fclose(f);
        return NULL;
    }

    uint8_t *data = (uint8_t *)malloc((size_t)sz);
    if (!data) {
        fclose(f);
        return NULL;
    }

    if (fread(data, 1, (size_t)sz, f) != (size_t)sz) {
        free(data);
        fclose(f);
        return NULL;
    }
    fclose(f);

    RgnContainer *rgn = (RgnContainer *)calloc(1, sizeof(RgnContainer));
    if (!rgn) {
        free(data);
        return NULL;
    }
    rgn->raw_data = data;
    rgn->file_size = (size_t)sz;

    uint16_t header_size = read_u16(data);
    int num_slots = header_size / 6;

    for (int slot = 0; slot < num_slots && slot < RGN_MAX_ROOMS; slot++) {
        size_t dir_off = (size_t)slot * 6;
        if (dir_off + 6 > (size_t)sz) break;

        uint16_t offset = read_u16(data + dir_off);
        uint16_t room_id = read_u16(data + dir_off + 2);
        uint16_t region_count = read_u16(data + dir_off + 4);

        if (offset >= header_size && offset < (uint16_t)sz && region_count > 0) {
            RgnRoom *room = &rgn->rooms[rgn->room_count++];
            room->room_index = (uint16_t)slot;
            room->room_id = room_id;
            room->region_count = (region_count > RGN_MAX_REGIONS) ? RGN_MAX_REGIONS : region_count;

            size_t pos = offset;
            for (uint16_t reg_idx = 0; reg_idx < room->region_count; reg_idx++) {
                if (pos + 4 > (size_t)sz) break;

                RgnRegion *reg = &room->regions[reg_idx];
                reg->obj_id = read_u16(data + pos);
                uint16_t npts = read_u16(data + pos + 2);
                pos += 4;

                reg->num_pts = (npts > RGN_MAX_POINTS) ? RGN_MAX_POINTS : npts;

                int16_t min_x = 32767, min_y = 32767;
                int16_t max_x = -32768, max_y = -32768;

                for (uint16_t p = 0; p < reg->num_pts; p++) {
                    if (pos + 4 > (size_t)sz) break;
                    int16_t px = read_s16(data + pos);
                    int16_t py = read_s16(data + pos + 2);
                    pos += 4;

                    reg->pts[p].x = px;
                    reg->pts[p].y = py;

                    if (px < min_x) min_x = px;
                    if (px > max_x) max_x = px;
                    if (py < min_y) min_y = py;
                    if (py > max_y) max_y = py;
                }

                /* For skipped points beyond RGN_MAX_POINTS */
                if (npts > RGN_MAX_POINTS) {
                    pos += (size_t)(npts - RGN_MAX_POINTS) * 4;
                }

                reg->min_x = min_x;
                reg->min_y = min_y;
                reg->max_x = max_x;
                reg->max_y = max_y;
            }
        }
    }

    printf("[RGN] Loaded %s: %d active rooms with hotspot regions\n", path, rgn->room_count);
    return rgn;
}

void rgn_free(RgnContainer *rgn) {
    if (!rgn) return;
    if (rgn->raw_data) {
        free(rgn->raw_data);
    }
    free(rgn);
}

const RgnRoom *rgn_get_room(const RgnContainer *rgn, int room_index) {
    if (!rgn) return NULL;
    for (int i = 0; i < rgn->room_count; i++) {
        if (rgn->rooms[i].room_index == (uint16_t)room_index) {
            return &rgn->rooms[i];
        }
    }
    return NULL;
}

bool rgn_point_in_region(const RgnRegion *region, int x, int y) {
    if (!region || region->num_pts == 0) return false;

    /* Quick bounding box rejection */
    if (x < region->min_x || x > region->max_x || y < region->min_y || y > region->max_y) {
        return false;
    }

    /* Bounding box definition (2 points: top-left, bottom-right) */
    if (region->num_pts == 2) {
        return true;
    }

    /* Polygon ray-casting algorithm (Jordan curve theorem) */
    bool inside = false;
    int n = (int)region->num_pts;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        int16_t xi = region->pts[i].x;
        int16_t yi = region->pts[i].y;
        int16_t xj = region->pts[j].x;
        int16_t yj = region->pts[j].y;

        if (((yi > y) != (yj > y)) &&
            ((int32_t)x < (int32_t)(xj - xi) * (int32_t)(y - yi) / (yj - yi) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}

int rgn_find_object_at(const RgnRoom *room, int x, int y) {
    if (!room || room->region_count == 0) return -1;

    /* Scan backwards: later regions override earlier base surface regions */
    for (int i = (int)room->region_count - 1; i >= 0; i--) {
        if (rgn_point_in_region(&room->regions[i], x, y)) {
            return (int)room->regions[i].obj_id;
        }
    }
    return -1;
}
