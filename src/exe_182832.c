/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x2ca30, 17 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xC4, 0x00, 0x61, 0x00, 0xC8, 0x00, 0x01, 0x01, 0xC9, 0x00, 0x03, 0x01,
    0xCA, 0x00, 0x04, 0x01, 0xCB,
};
