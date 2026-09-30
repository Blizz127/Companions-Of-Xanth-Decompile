#include "controller_help.h"
#include "port_types.h"
#include <stdio.h>
#include <string.h>

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "controller help check failed at line %d: %s\n", \
                __LINE__, #condition); \
        return 1; \
    } \
} while (0)

static uint8_t guest_snapshot[DOS_MEM_SIZE];
static uint32_t baseline[CONTROLLER_HELP_PIXELS];
static struct {
    uint32_t before;
    uint32_t pixels[CONTROLLER_HELP_PIXELS];
    uint32_t after;
} panel;

int main(int argc, char **argv) {
    for (size_t i = 0; i < DOS_MEM_SIZE; ++i)
        g_dos_mem[i] = (uint8_t)(i * 17u + i / 127u);
    memcpy(guest_snapshot, g_dos_mem, sizeof(guest_snapshot));
    panel.before = 0x12345678u;
    panel.after = 0x87654321u;
    memset(panel.pixels, 0xA5, sizeof(panel.pixels));
    memcpy(baseline, panel.pixels, sizeof(baseline));
    CHECK(!controller_help_render(NULL, CONTROLLER_HELP_PIXELS, false, false));
    CHECK(!controller_help_render(panel.pixels, CONTROLLER_HELP_PIXELS - 1,
                                  false, false));
    CHECK(memcmp(baseline, panel.pixels, sizeof(baseline)) == 0);
    CHECK(controller_help_render(panel.pixels, CONTROLLER_HELP_PIXELS, false, false));
    CHECK(memcmp(baseline, panel.pixels, sizeof(baseline)) != 0);
    memcpy(baseline, panel.pixels, sizeof(baseline));
    for (int verbs = 0; verbs <= 1; ++verbs) {
        for (int snap = 0; snap <= 1; ++snap) {
            CHECK(controller_help_render(panel.pixels, CONTROLLER_HELP_PIXELS,
                                         verbs != 0, snap != 0));
            size_t verb_changes = 0, snap_changes = 0;
            for (int y = 0; y < CONTROLLER_HELP_HEIGHT; ++y) {
                for (int x = 0; x < CONTROLLER_HELP_WIDTH; ++x) {
                    size_t index = (size_t)y * CONTROLLER_HELP_WIDTH + x;
                    if (panel.pixels[index] == baseline[index]) continue;
                    if (y >= 103 && y < 110) ++verb_changes;
                    else if (y >= 118 && y < 125) ++snap_changes;
                    else CHECK(false);
                }
            }
            CHECK((verb_changes > 0) == (verbs != 0));
            CHECK((snap_changes > 0) == (snap != 0));
            CHECK(panel.before == 0x12345678u && panel.after == 0x87654321u);
            /* Includes all 64 KB of VGA memory and the rest of guest RAM. */
            CHECK(memcmp(guest_snapshot, g_dos_mem, sizeof(guest_snapshot)) == 0);
        }
    }
    if (argc > 1) {
        /* Preview the current supported state: no speculative verb/Y actions. */
        CHECK(controller_help_render(panel.pixels, CONTROLLER_HELP_PIXELS, false, false));
        FILE *output = fopen(argv[1], "wb");
        CHECK(output != NULL);
        fprintf(output, "P6\n%d %d\n255\n", CONTROLLER_HELP_WIDTH, CONTROLLER_HELP_HEIGHT);
        for (size_t i = 0; i < CONTROLLER_HELP_PIXELS; ++i) {
            uint32_t pixel = panel.pixels[i];
            uint8_t rgb[] = {(uint8_t)(pixel >> 24), (uint8_t)(pixel >> 16),
                             (uint8_t)(pixel >> 8)};
            CHECK(fwrite(rgb, 1, sizeof(rgb), output) == sizeof(rgb));
        }
        CHECK(fclose(output) == 0);
    }
    puts("Controller help: capability gates, buffer bounds, and guest RAM identity passed.");
    return 0;
}
