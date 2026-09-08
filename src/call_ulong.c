void far helper_ulong(unsigned long a);

void far call_ulong(unsigned a)
{
    helper_ulong(a);
}
