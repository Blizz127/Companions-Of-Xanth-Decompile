/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0xd8f, 20 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x80, 0x3E, 0xF4, 0x41, 0x01, 0x75, 0x0C, 0x06, 0x57, 0x56, 0x55, 0xFF,
    0x16, 0xFC, 0x41, 0x5D, 0x5E, 0x5F, 0x07, 0xCB,
};
