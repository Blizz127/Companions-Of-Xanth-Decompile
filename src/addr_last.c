void far helper_addr(int a, int b, int c, int d, int far *e);

void far addr_last(int a, int b, int c, int d, int e)
{
    int dummy[3];

    helper_addr(a, b, c, d, &e);
}
