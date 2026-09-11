/*
 * Data region, not an instruction stream: The byte sequence does not assemble as an instruction stream in this toolchain (CL 8.00c inline asm rejects it), which is positive evidence that the unit is not code..
 * exe-code:0x1506, 16 bytes.
 *
 * Transcribed as data. This translation unit has no PUBDEF, so the splice takes its first LEDATA, which is this array.
 */
char mnem_data[] = {
    0x0E, 0x83, 0xEF, 0x04, 0x8B, 0x05, 0x0B, 0x45, 0x02, 0x74, 0xF2, 0xFF,
    0x1D, 0xEB, 0xEE, 0xC3,
};
