void far helper_ne(void);

int g;

int far swap_if_ne_call(int a)
{
    int old;

    old = g;
    if (old != a)
        helper_ne();
    g = a;
    return old;
}
