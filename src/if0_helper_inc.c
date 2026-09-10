int g;
void far helper(void);

void far if0_helper_inc(void)
{
    if (g == 0) {
        helper();
        g++;
    }
}
