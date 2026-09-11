/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x20feb, 27 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xE8, 0x1A, 0xD2, 0xEA, 0x03, 0x08, 0xCB, 0x30, 0x0A, 0x00, 0xE8, 0x10,
    0xD2, 0xEA, 0x65, 0x08, 0xCB, 0x30, 0x0A, 0x00, 0xE8, 0x06, 0xD2, 0xEA,
    0x9F, 0x07, 0xCB,
};
