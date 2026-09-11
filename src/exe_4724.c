/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x1274, 20 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x80, 0x3E, 0xF4, 0x41, 0x01, 0x75, 0x0C, 0x8B, 0x16, 0x1F, 0x42, 0x80,
    0xC2, 0x0C, 0xB0, 0xD4, 0xE9, 0x83, 0xFC, 0xC3,
};
