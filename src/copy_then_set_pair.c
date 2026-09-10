int g0;
int g1;
int prev0;
int prev1;

void far copy_then_set_pair(int a, int b)
{
    prev0 = g0;
    prev1 = g1;
    g0 = a;
    g1 = b;
}
