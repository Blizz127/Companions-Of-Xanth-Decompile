void pascal far helper0(int a);

int g;

int far swap_if_ne(int a)
{
    int old;

    old = g;
    if (a >= 0 && a != old) {
        helper0(0);
        g = a;
    }
    return old;
}
