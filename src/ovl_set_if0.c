char g;

void far set_if0(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
        g = 1;
        break;
    }
}
