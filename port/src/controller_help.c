#include "controller_help.h"

/* Small, independently authored host font. Five columns, seven rows, uppercase
 * only: no retail .FNT files or guest text renderer are used by this overlay. */
static const uint8_t letters[26][7] = {
    {14,17,17,31,17,17,17}, /* A */
    {30,17,17,30,17,17,30}, /* B */
    {14,17,16,16,16,17,14}, /* C */
    {30,17,17,17,17,17,30}, /* D */
    {31,16,16,30,16,16,31}, /* E */
    {31,16,16,30,16,16,16}, /* F */
    {14,17,16,23,17,17,15}, /* G */
    {17,17,17,31,17,17,17}, /* H */
    {14,4,4,4,4,4,14},      /* I */
    {7,2,2,2,18,18,12},    /* J */
    {17,18,20,24,20,18,17}, /* K */
    {16,16,16,16,16,16,31}, /* L */
    {17,27,21,21,17,17,17}, /* M */
    {17,25,21,19,17,17,17}, /* N */
    {14,17,17,17,17,17,14}, /* O */
    {30,17,17,30,16,16,16}, /* P */
    {14,17,17,17,21,18,13}, /* Q */
    {30,17,17,30,20,18,17}, /* R */
    {15,16,16,14,1,1,30},   /* S */
    {31,4,4,4,4,4,4},      /* T */
    {17,17,17,17,17,17,14}, /* U */
    {17,17,17,17,17,10,4}, /* V */
    {17,17,17,21,21,21,10}, /* W */
    {17,17,10,4,10,17,17}, /* X */
    {17,17,10,4,4,4,4},    /* Y */
    {31,1,2,4,8,16,31},    /* Z */
};

static void rectangle(uint32_t *pixels, int x, int y, int w, int h,
                      uint32_t color) {
    for (int yy = y; yy < y + h && yy < CONTROLLER_HELP_HEIGHT; ++yy) {
        if (yy < 0) continue;
        for (int xx = x; xx < x + w && xx < CONTROLLER_HELP_WIDTH; ++xx) {
            if (xx >= 0) pixels[yy * CONTROLLER_HELP_WIDTH + xx] = color;
        }
    }
}

static void text(uint32_t *pixels, int x, int y, int scale,
                 const char *value, uint32_t color) {
    for (; *value; ++value, x += 6 * scale) {
        for (int row = 0; row < 7; ++row) {
            uint8_t bits = 0;
            if (*value >= 'A' && *value <= 'Z') bits = letters[*value - 'A'][row];
            else if (*value == '/' && row > 0 && row < 6) bits = 1u << (row - 1);
            for (int col = 0; col < 5; ++col) {
                if (bits & (1u << (4 - col)))
                    rectangle(pixels, x + col * scale, y + row * scale,
                              scale, scale, color);
            }
        }
    }
}

static void instruction(uint32_t *pixels, int y, const char *button,
                        const char *action) {
    text(pixels, 12, y, 1, button, 0x83D7FFFFu);
    text(pixels, 98, y, 1, action, 0xF2F5F8FFu);
}

bool controller_help_render(uint32_t *pixels, size_t pixel_count,
                            bool can_verb_cycle, bool can_snap) {
    if (!pixels || pixel_count < CONTROLLER_HELP_PIXELS) return false;
    rectangle(pixels, 0, 0, CONTROLLER_HELP_WIDTH, CONTROLLER_HELP_HEIGHT,
              0x14202CF8u);
    rectangle(pixels, 0, 0, CONTROLLER_HELP_WIDTH, 2, 0x83D7FFFFu);
    rectangle(pixels, 0, CONTROLLER_HELP_HEIGHT - 2, CONTROLLER_HELP_WIDTH, 2,
              0x83D7FFFFu);
    rectangle(pixels, 0, 0, 2, CONTROLLER_HELP_HEIGHT, 0x83D7FFFFu);
    rectangle(pixels, CONTROLLER_HELP_WIDTH - 2, 0, 2, CONTROLLER_HELP_HEIGHT,
              0x83D7FFFFu);
    text(pixels, 12, 12, 2, "CONTROLLER HELP", 0xF2F5F8FFu);
    text(pixels, 12, 34, 1, "POINTER AND GAME CONTROLS", 0xADC1D3FFu);
    rectangle(pixels, 12, 48, CONTROLLER_HELP_WIDTH - 24, 1, 0x52738AFFu);
    instruction(pixels, 58, "LEFT STICK", "MOVE POINTER");
    instruction(pixels, 73, "A", "LEFT CLICK");
    instruction(pixels, 88, "X", "RIGHT CLICK");
    if (can_verb_cycle)
        instruction(pixels, 103, "LB / RB", "PREVIOUS / NEXT VERB");
    if (can_snap) instruction(pixels, 118, "Y", "SNAP TO HIGHLIGHT");
    instruction(pixels, 133, "START", "ENTER");
    instruction(pixels, 153, "BACK", "CLOSE HELP");
    return true;
}
