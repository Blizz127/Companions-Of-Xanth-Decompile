void far helper_ne(int a, int b, int c);

void far range02(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
    case 1:
    case 2:
        helper_ne(a, b, 0);
        break;
    }
}
