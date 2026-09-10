char g0;
char g1;
void far helper_ne(int a, int b, int c);

void far range04_then(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        helper_ne(a, b, 0);
        if (g0 && g1)
            helper_ne(a, 5, 1);
        break;
    }
}
