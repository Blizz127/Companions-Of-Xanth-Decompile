char g;
void far helper_ne(int a, int b, int c);

void far set_then_range(int a, int b)
{
    g = 1;
    switch (b) {
    default:
        break;
    case 0:
    case 1:
        helper_ne(a, b, 0);
        break;
    }
}
