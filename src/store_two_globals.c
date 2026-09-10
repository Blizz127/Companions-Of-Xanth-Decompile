int g0;
int g1;

void far store_two_globals(int far *p, int far *q)
{
    *p = g0;
    *q = g1;
}
