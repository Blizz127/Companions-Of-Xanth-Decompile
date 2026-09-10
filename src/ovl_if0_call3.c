void far helper3(int a, int b, int c);

void far if0_call3(int a, int b)
{
    switch (b) {
    default:
        break;
    case 0:
        helper3(0x127, 0x11, 0);
        break;
    }
}
