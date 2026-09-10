void far helper_ne(int a, int b, int c);

void far range01(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
    case 1:
        helper_ne(a, b, 0);
        break;
    }
}
