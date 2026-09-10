void far helper_lds(void);
void far lds_call(unsigned long p)
{
    _asm {
        push ds
        lds dx, dword ptr p
        call far ptr helper_lds
        pop ds
    }
}
