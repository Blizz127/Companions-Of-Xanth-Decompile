int g;
int far helper1(void);
int far helper2(void);

int far exe_90642(void)
{
    int c;

    if (helper1()) {
        c = helper2();
        if (c != 0x20 && c != 0x0D)
            g = c;
    } else
        c = 0;
    return c;
}
