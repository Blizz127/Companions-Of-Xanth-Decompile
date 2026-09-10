void far helper2(int a, int b);

void far range35(int a, int b)
{
    switch (b) {
    default:
        break;
    case 3:
    case 4:
    case 5:
        helper2(3, 0x0F);
        break;
    }
}
