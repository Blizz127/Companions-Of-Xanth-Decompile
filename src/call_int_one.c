void far helper_int_one(int a, int b);

void far call_int_one(int a)
{
    helper_int_one(a, 1);
}
