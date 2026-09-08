void far helper_int_zero(int a, int b);

void far call_int_zero(int a)
{
    helper_int_zero(a, 0);
}
