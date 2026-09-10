int g;
void far helper(int a, int b);

void far exe_52615(int far *p)
{
    int dummy;
    int far *q;

    g = 1;
    if (*p != 0) {
        q = p;
        do {
            helper(*q, -1);
            q++;
        } while (*q != 0);
    }
}
