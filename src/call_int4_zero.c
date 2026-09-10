void far helper_int4_zero(int a, int b, int c, int d, int e);

void far call_int4_zero(int a, int b, int c, int d)
{
    helper_int4_zero(a, b, c, d, 0);
}
