int a[4];
int b[4];
int c[4];

void far set_triple_idx(int x, int y, int z, int i)
{
    if (i < 4) {
        a[i] = z;
        b[i] = x;
        c[i] = y;
    }
}
