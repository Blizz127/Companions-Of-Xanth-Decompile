void pascal far helper_int(int a);

void far call_int(int a)
{
    helper_int(a);
}
