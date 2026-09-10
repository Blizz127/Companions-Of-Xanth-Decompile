int far * far helper(int a);

#pragma optimize("s", off)
#pragma optimize("g", on)
void far zero_until(int a)
{
    int far *p;

    p = helper(a);
    if (*p != 0) {
        do {
            *p = 0;
            p++;
        } while (*p != 0);
    }
}
