void far swap_far_ints(int far *p, int far *q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
}
