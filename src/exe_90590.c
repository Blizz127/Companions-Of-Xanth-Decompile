int far helper(void);

int far exe_90590(void)
{
    int c;

    c = helper();
    if (c >= 0x61 && c <= 0x7A)
        *(int *)&c = c - 0x20;
    return c;
}
