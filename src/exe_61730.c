int g;
void far *p;
void far helper_0(void far *q);
void far helper_1(int a);
void far helper_2(int a);

#pragma optimize("g", on)
#pragma optimize("s", off)
void far exe_61730(int a)
{
    int t;

    t = g;
    helper_0(p);
    g = 0;
    helper_1(1);
    if (t == 1)
        helper_2(4);
}
