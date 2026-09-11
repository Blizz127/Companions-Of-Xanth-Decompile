/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x2170b, 11 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0xB8, 0x00, 0x30, 0xCD, 0x21, 0x3C, 0x03, 0x73, 0x07, 0xF9, 0xC3,
};
