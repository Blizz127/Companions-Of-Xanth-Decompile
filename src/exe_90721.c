#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a);

int far exe_90721(void)
{
    return helper(2) & 3;
}
