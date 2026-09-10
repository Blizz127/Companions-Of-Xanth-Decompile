void far helper_ne(int a, int b, int c);

void far call_if_eq1(int a, int b)
{
    switch (b) {
    default:
        break;
    case 1:
        helper_ne(a, b, 0);
        break;
    }
}
