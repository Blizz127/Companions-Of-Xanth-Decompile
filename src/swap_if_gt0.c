int g;

int far swap_if_gt0(int a)
{
    int old;

    old = g;
    if (a > 0)
        g = a;
    return old;
}
