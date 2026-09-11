void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_204313(void)
{
    _asm {
        mov ax,0x1
        push ax
        mov ax,0x124
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+35
        push ax
        mov ax,0x1
        push ax
        mov ax,0x124
        push ax
        call far ptr helper_1
        add sp,0x6
        mov ax,0xa
        push ax
        mov ax,0x124
        push ax
        call far ptr helper_2
        add sp,0x4
L35:
        retf
    }
}
