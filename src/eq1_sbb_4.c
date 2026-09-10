#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a, int b, int c);

int far eq1_sbb_4(int a, int b)
{
    return helper(a, b, 4) == 0;
}
