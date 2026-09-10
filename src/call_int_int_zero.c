void far helper_int_int_zero(int a, int b, int c);

void far call_int_int_zero(int a, int b)
{
    helper_int_int_zero(a, b, 0);
}
