int g;

void pascal far helper_p(int a, int b, int c, int d);

void pascal far pascal_star(int a, int b, int far *p)
{
    helper_p(*p, a, b, g);
}
