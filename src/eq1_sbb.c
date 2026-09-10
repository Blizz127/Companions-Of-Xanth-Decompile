#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a);

int far eq1_sbb(int a)
{
    return helper(a) == 0;
}
