void far helper_eq2(int a, int b);

void far if_eq2_call(int unused, int b)
{
    if (b == 2)
        helper_eq2(3, 12);
}
