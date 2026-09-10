#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a, int b);

int far h2_eq0_bf_e(void)
{
    return helper(191, 14) == 0;
}
