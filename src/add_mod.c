unsigned g0;
unsigned g1;

void far add_mod(unsigned a)
{
    g0 += a;
    g1 += g0 / 0x5A0;
    g0 %= 0x5A0;
}
