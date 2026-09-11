/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x20cdf, 7 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xE8, 0x26, 0xD5, 0xEA, 0x16, 0x00, 0xCB,
};
