void far helper_0(void);
int far ovl_241959(void)
{
    _asm {
        mov ax,0x7
        push ax
        mov ax,0x2c4
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_0
        add sp,0x6
        retf
    }
}
