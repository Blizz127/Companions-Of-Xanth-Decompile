void far helper_ne(int a, int b, int c);

void far dec2_range_b(int a, int b)
{
    switch (b) {
    default:
        break;
    case 2:
    case 3:
    case 4:
        helper_ne(a, b, 0);
        break;
    }
}
