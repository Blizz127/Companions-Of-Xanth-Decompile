/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x22561, 13 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xFF, 0x1F, 0xFE, 0x3F, 0xFC, 0x7F, 0x98, 0xFF, 0x00, 0xFF, 0x81, 0xFF,
    0xC3,
};
