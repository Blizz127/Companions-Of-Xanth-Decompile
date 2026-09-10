void far helper_int4(int a, int b, int c, int d);

void far call_int4(int a, int b, int c, int d)
{
    helper_int4(a, b, c, d);
}
