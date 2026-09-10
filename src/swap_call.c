void pascal far helper_swap_call(int a);

int g;

int far swap_call(int a)
{
    int old;

    old = g;
    g = a;
    helper_swap_call(a);
    return old;
}
