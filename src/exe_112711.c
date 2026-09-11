/*
 * exe-code:0x1B847, 84 bytes.
 *
 * Walk the records of the far table selected by the global index and, for
 * every record whose word at +10 equals the argument, set bit 7 of its
 * second byte.
 *
 * The declarations are forced by the code. All three globals are __near so
 * the base folds into the displacement. The local `p` is declared *first*:
 * CL does not reference the slot (the pointer stays in es:di) but it still
 * lays out `i` at bp-6 and `off` at bp-8, and declaring p after them puts i
 * at bp-2 and the whole unit two bytes off from retail.
 */
extern unsigned __near g_idx;
extern int __near g_cnt[];
extern char far * __near g_tbl[];

void far exe_112711(int v)
{
    char far *p;
    int i, off;

    i = 0;
    if (g_cnt[g_idx] > 0) {
        off = 0;
        do {
            p = g_tbl[g_idx] + off;
            if (*(int *)(p + 10) == v)
                p[1] |= 0x80;
            off += 20;
            i++;
        } while (g_cnt[g_idx] > i);
    }
}
