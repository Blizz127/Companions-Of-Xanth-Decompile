int g;

void far helper_byte_addr(int x, unsigned char far *p);

void far call_byte_addr(unsigned a)
{
    *((unsigned char *)&a + 1) = 0;
    helper_byte_addr(g, (unsigned char far *)&a);
}
