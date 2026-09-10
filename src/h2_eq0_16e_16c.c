#pragma optimize("g", on)
#pragma optimize("s", off)

int far helper(int a, int b);

int far h2_eq0_16e_16c(void)
{
    return helper(366, 364) == 0;
}
