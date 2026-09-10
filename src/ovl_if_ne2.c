int g;
void far helper_ne(int a, int b, int c);

void far if_ne2(int a, int b)
{
    switch (b) {
    case 2:
        break;
    default:
        helper_ne(a, b, 0);
        g++;
        if (g == 2)
            helper_ne(a, 2, 1);
        break;
    }
}
