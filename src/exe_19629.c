/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x4cad, 17 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x80, 0xE1, 0xFE, 0x53, 0xFC, 0x8B, 0x77, 0x08, 0x8B, 0x5F, 0x0A, 0x33,
    0xFF, 0xEB, 0x23, 0x8B, 0xC3,
};
