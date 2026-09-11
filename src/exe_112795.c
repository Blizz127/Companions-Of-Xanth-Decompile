/*
 * exe-code:0x1B89B, 58 bytes.
 *
 * Set bit 7 of the second byte of record `i` in a table reached through a
 * far pointer selected by a global index, but only while the record index is
 * still inside the count for that table.
 *
 * Every declaration here is forced by the code. All three globals are __near
 * so the accesses stay DS-relative with the array base folded into the
 * displacement. `p` must be a named local: CL then allocates the four bytes
 * (sub sp,4) even though it keeps the pointer in cx:dx, and folding the
 * record offset into the pointer (`p = t + i * 20`) is what makes CL add it
 * with `add cx,ax` instead of carrying it separately in si.
 */
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112795(int i)
{
    char far *p;

    if (g_cnt[g_idx] <= i)
        return;
    p = g_tbl[g_idx] + i * 20;
    p[1] |= 0x80;
}
