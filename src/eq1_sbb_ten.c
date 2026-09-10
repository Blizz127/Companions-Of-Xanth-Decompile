#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a, int b);

int far eq1_sbb_ten(int a)
{
    return helper(a, 10) == 0;
}
