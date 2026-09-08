void far helper_int_int(int a, int b);

void far call_int_int(int a, int b)
{
    helper_int_int(a, b);
}
