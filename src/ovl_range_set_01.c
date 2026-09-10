char g;

void far range_set_01(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
    case 1:
        g = 1;
        break;
    }
}
