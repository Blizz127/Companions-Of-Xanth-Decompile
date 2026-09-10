int g;
int arr[1];
int far helper(int a);
void far helper2(int a);

#pragma optimize("g", on)
#pragma optimize("s", off)
void far exe_92430(int a)
{
    int i;

    i = helper(g);
    if (i >= 0) {
        arr[i] = a;
        helper2(0);
    }
}
