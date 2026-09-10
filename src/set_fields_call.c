void far helper_fields(int far *p);

void far set_fields_call(int far *p, int a, int b)
{
    p[1] = a;
    p[2] = b;
    helper_fields(p);
}
