void far helper_ne(int a, int b, int c);

void far call_if_zero(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
        helper_ne(a, 0, 0);
        break;
    }
}
