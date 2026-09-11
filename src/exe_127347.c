/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x1f173, 17 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xE8, 0x92, 0xF0, 0xEA, 0x00, 0x00, 0x1E, 0x32, 0x32, 0x00, 0xE8, 0x88,
    0xF0, 0xEA, 0x00, 0x00, 0xCB,
};
