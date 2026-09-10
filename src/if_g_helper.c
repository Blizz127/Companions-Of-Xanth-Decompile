unsigned char g;
void far helper(void);

void far if_g_helper(void)
{
    if (g)
        helper();
}
