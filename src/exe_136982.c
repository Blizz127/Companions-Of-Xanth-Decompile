/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x21716, 26 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x50, 0x41, 0x54, 0x48, 0x00, 0x8B, 0x46, 0x10, 0x0E, 0xE8, 0x65, 0x00,
    0x72, 0xF1, 0x83, 0xFB, 0xFF, 0x75, 0x03, 0xF9, 0xEB, 0xE9, 0x8B, 0xF2,
    0x8B, 0xCB,
};
