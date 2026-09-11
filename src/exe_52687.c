/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0xcdcf, 23 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x8E, 0x06, 0x32, 0x5A, 0x8B, 0x1E, 0x02, 0x01, 0x03, 0xDB, 0x26, 0xC7,
    0x87, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x8C, 0xC2, 0xCB,
};
