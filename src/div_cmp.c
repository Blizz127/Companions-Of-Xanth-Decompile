int far helper_div(void);

int far div_cmp(int a)
{
    return helper_div() % 100 < a;
}
