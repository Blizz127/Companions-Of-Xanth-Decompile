char far * far helper(int a, int b, int far *bit);

#pragma optimize("g", on)
#pragma optimize("s", off)
void far exe_45256(int a, int b)
{
    int bit;
    char far *p;

    p = helper(a, b, &bit);
    if (p != 0)
        *p &= (char)~(1 << bit);
}
