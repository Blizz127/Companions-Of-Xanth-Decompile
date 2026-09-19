#ifndef PORT_RGN_H
#define PORT_RGN_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RGN_MAX_POINTS 128
#define RGN_MAX_REGIONS 64
#define RGN_MAX_ROOMS 256

typedef struct {
    int16_t x;
    int16_t y;
} RgnPoint;

typedef struct {
    uint16_t obj_id;
    uint16_t num_pts;
    RgnPoint pts[RGN_MAX_POINTS];
    int16_t min_x;
    int16_t min_y;
    int16_t max_x;
    int16_t max_y;
} RgnRegion;

typedef struct {
    uint16_t room_id;
    uint16_t room_index;
    uint16_t region_count;
    RgnRegion regions[RGN_MAX_REGIONS];
} RgnRoom;

typedef struct {
    int room_count;
    RgnRoom rooms[RGN_MAX_ROOMS];
    uint8_t *raw_data;
    size_t file_size;
} RgnContainer;

/**
 * Loads and parses a retail .RGN polygon region file.
 * Returns NULL on failure.
 */
RgnContainer *rgn_load(const char *path);

/**
 * Frees resources allocated for an RgnContainer.
 */
void rgn_free(RgnContainer *rgn);

/**
 * Retrieves a room's region list by its room index (matching .PIC entry index).
 * Returns NULL if room_index is not defined in the container.
 */
const RgnRoom *rgn_get_room(const RgnContainer *rgn, int room_index);

/**
 * Tests whether point (x, y) in room coordinates (0..264, 0..122) falls within
 * the given region. Supports both AABB bounding boxes (num_pts == 2) and
 * arbitrary convex/concave polygons (num_pts > 2) using ray-casting.
 */
bool rgn_point_in_region(const RgnRegion *region, int x, int y);

/**
 * Finds the object ID under point (x, y) in the specified room.
 * Evaluates regions in reverse definition order so that foreground/specific
 * item regions take precedence over broad surface backdrops.
 * Returns -1 if no region covers (x, y).
 */
int rgn_find_object_at(const RgnRoom *room, int x, int y);

#ifdef __cplusplus
}
#endif

#endif /* PORT_RGN_H */
