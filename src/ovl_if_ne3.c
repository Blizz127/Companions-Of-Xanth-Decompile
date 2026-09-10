int g;
void far helper_ne(int a, int b, int c);

void far if_ne3(int a, int b)
{
    switch (b) {
    case 3:
        break;
    default:
        helper_ne(a, b, 0);
        g++;
        if (g == 3)
            helper_ne(a, 3, 1);
        break;
    }
}
