void far helper_a0bc(int a, int b, int c, int d);

void far call_int_zero_int_int(int a, int b, int c)
{
    helper_a0bc(a, 0, b, c);
}
