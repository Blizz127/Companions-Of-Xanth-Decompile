void far helper_int_ten(int a, int b);

void far call_int_ten(int a)
{
    helper_int_ten(a, 10);
}
