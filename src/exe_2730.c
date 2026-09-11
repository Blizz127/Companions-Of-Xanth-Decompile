/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0xaaa, 23 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x52, 0x09, 0x72, 0xEA, 0xB8, 0x20, 0xB0, 0xE8, 0x79, 0x01, 0xB8, 0x00,
    0xA0, 0xE8, 0x73, 0x01, 0xC6, 0x06, 0xF4, 0x41, 0x00, 0xF8, 0xC3,
};
