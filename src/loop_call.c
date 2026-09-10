int far helper_loop(int n, char far *p);

void far loop_call(void)
{
    char buf[8];

    while (!helper_loop(8, buf))
        ;
}
