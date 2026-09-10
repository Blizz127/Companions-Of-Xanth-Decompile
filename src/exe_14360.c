char tbl[1];

int far exe_14360(int a)
{
    if (tbl[a] & 1)
        return a + 0x20;
    else
        return a;
}
