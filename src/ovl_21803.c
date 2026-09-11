void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_21803(void)
{
    _asm {
        call far ptr helper_0
        or ax,ax
        jnz short $+19
        call far ptr helper_1
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x2
L1A:
        mov ax,0x7d
        push ax
        mov ax,0x13a
        push ax
        mov ax,0x4
        push ax
        mov ax,0x33
        push ax
        call far ptr helper_3
        add sp,0x8
        retf
    }
}
