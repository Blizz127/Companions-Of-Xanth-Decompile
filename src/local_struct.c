struct S {
    int a;
    int pad[2];
    int b;
};

void far helper_s(struct S far *p);

void far local_struct(int a, int b)
{
    struct S s;

    s.a = a;
    s.b = b;
    helper_s(&s);
}
