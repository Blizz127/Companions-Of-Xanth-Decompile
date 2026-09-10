unsigned g;
unsigned far helper1(void);
void far helper2(int a, int b);

void far if13_div(int a, int b)
{
    switch (b) {
    default:
        break;
    case 3:
        g = helper1() % 3u;
    case 1:
        helper2(3, 0x0C);
        break;
    }
}
