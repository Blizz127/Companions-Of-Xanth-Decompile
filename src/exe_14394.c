char tbl[1];

int far exe_14394(int a)
{
    if (tbl[a] & 2)
        return a - 0x20;
    else
        return a;
}
