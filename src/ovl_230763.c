/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * ovl-payload:0x3856b, 10 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x32, 0xCC, 0x0F, 0x1E, 0x32, 0x85, 0x12, 0x1E, 0x32, 0xCB,
};
