/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0xaafb, 20 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x57, 0x33, 0xC0, 0x8E, 0x06, 0x22, 0x5A, 0xB9, 0x20, 0x00, 0xBF, 0x32,
    0x00, 0xF3, 0xAB, 0xA3, 0xEC, 0x00, 0x5F, 0xCB,
};
