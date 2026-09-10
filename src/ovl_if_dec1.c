void far helper_ne(int a, int b, int c);

void far call_if_dec(int a, int b)
{
    switch (b) {
    case 1:
        break;
    default:
        helper_ne(a, b, 0);
        break;
    }
}
