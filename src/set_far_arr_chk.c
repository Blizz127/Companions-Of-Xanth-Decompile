int n;
void far *arr[1];

void far set_far_arr_chk(int i, void far *p)
{
    if (i >= 0 && i < n)
        arr[i] = p;
}
