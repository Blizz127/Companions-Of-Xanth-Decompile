/*
 * exe-code:0x1855F, 48 bytes.
 *
 * A flag test against an 8-bit counter index. If the low bit of `g` matches
 * the argument, bump the byte table at index `g`; otherwise, while `g` stays
 * below 0xF, advance `g` and set that entry to 1.
 *
 * Two details are forced by the code and are why this is spelled this way:
 * `g` is read as a byte (`mov al,[g]`) yet updated as a word
 * (`inc word [g]`), so the low bit is taken through a cast rather than by
 * declaring `g` a char; and the table access is `[bx+4F2Ah]`, a near access
 * with the base folded in, so `t` must be declared near — as a far array CL
 * emits `mov es,[g]` plus `es:[bx]` and the unit grows by ten bytes.
 */
extern unsigned g;
extern char __near t[];

void far exe_99679(int a)
{
    if (a == ((char)g & 1))
        t[g]++;
    else if (g < 0xF) {
        g++;
        t[g] = 1;
    }
}
