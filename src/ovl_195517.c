#pragma optimize("g", on)
#pragma optimize("s", off)

int g;
void far helper(int a);

int far ovl_195517(void)
{
    g = 0x11;
    helper(0x5A);
    return 1;
}
