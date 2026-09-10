char g;
int c0;
int c1;
void far helper1(int a);
void far helper2(int a, int b);
void far helper_ne(int a, int b, int c);

#pragma optimize("s", off)
void far if2_three(int a, int b)
{
    c0++;
    switch (b) {
    default:
        break;
    case 2:
        g = 1;
        c1++;
        if (c1 > 4) {
            helper1(0x27);
            helper2(0x28, 0);
            helper_ne(0x8104, 0, 0);
        }
        break;
    }
}
