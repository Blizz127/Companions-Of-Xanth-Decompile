int far helper_local_int(int a, int far *p, int n);

int far call_local_int(int a)
{
    int v;

    helper_local_int(a, &v, 2);
    return v;
}
