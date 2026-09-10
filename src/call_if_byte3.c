void far helper_star3(int a, int b);

struct S {
    unsigned char k;
    char pad[15];
    int a;
    int b;
};

void far call_if_byte3(struct S far *p)
{
    if (p->k == 3)
        helper_star3(p->a, p->b);
}
