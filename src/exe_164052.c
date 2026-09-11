/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x280d4, 9 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x80, 0x01, 0x98, 0x01, 0x00, 0x00, 0x73, 0x01, 0xCB,
};
