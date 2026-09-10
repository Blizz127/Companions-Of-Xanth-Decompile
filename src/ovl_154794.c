int g;
char obj_a;
char obj_b;

char far * far ovl_154794(int a)
{
    switch (a) {
    default:
        return 0;
    case 16:
        switch (g) {
        case 0x107:
        case 0x10C:
            return &obj_a;
        default:
            return &obj_b;
        }
    }
}
