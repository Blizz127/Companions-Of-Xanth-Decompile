int g;

int far swap_int(int a)
{
    int old;

    old = g;
    g = a;
    return old;
}
