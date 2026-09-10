int g;
void far helper2(int a);
void far helper_ne(int a);

#pragma optimize("s", off)
void far range01_then(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
    case 1:
        helper2(4);
        g = 0x1A;
        helper_ne(0x5A);
        break;
    }
}
