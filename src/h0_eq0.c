#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a);

int far h0_eq0(void)
{
    return helper(0) == 0;
}
