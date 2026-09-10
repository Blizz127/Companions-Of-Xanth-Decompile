int g0;
int g1;
int arr[1];
void pascal far helper(int a);

int far exe_115107(int a)
{
    int old;

    old = g0;
    if (a >= 0 && a < g1)
        g0 = a;
    helper(arr[g0]);
    return old;
}
