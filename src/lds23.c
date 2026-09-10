void far helper_lds(void);
void far lds_ax(unsigned long p, int a)
{
    _asm {
        push ds
        lds dx, dword ptr p
        mov ax, word ptr a
        call far ptr helper_lds
        pop ds
    }
}
