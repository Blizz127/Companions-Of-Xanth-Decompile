void far helper_ne(int a, int b, int c);
void far helper2(int a, int b);

void far if_nz_else(int a, int b)
{
    switch (b) {
    default:
        helper_ne(a, b, 0);
        break;
    case 0:
        helper2(0x192, 0x0A);
        break;
    }
}
