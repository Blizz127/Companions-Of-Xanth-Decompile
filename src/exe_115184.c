int g;
int arr[1];
void far helper(void);

int far exe_115184(void)
{
    int old;

    old = arr[g];
    if (old) {
        helper();
        arr[g] = 0;
    }
    return old;
}
