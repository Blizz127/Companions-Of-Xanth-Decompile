void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_127422(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x5a03
        push ax
        mov ax,0x127
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        retf
    }
}
