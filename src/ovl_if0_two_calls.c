char g;
void far helper3(int a, int b, int c);
void far helper_ne(int a, int b, int c);

void far if0_two_calls(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
        g = 1;
        helper3(0x93, 1, 0);
        helper_ne(a, 1, 0);
        break;
    }
}
