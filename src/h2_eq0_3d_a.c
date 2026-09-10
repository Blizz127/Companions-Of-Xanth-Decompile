#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a, int b);

int far h2_eq0_3d_a(void)
{
    return helper(61, 10) == 0;
}
