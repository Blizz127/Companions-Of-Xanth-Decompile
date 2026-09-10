void far helper_ne(int a, int b, int c);

void far dec2_range(int a, int b)
{
    switch (b) {
    default:
        break;
    case 2:
    case 3:
        helper_ne(a, b, 0);
        break;
    }
}
