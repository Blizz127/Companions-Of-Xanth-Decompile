void far helper_ne(int a, int b, int c);

#pragma optimize("g", on)
void far if_1246(int a, int b)
{
    switch (b) {
    default:
        break;
    case 1:
    case 4:
    case 6:
        helper_ne(a, b, 0);
        break;
    case 2:
        helper_ne(a, b, 0);
        helper_ne(a, 3, 1);
        break;
    }
}
