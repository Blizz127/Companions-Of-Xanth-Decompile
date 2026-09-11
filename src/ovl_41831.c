/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * ovl-payload:0xa367, 9 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x30, 0x35, 0x09, 0xCB, 0x30, 0xF0, 0x00, 0xCB, 0x30,
};
