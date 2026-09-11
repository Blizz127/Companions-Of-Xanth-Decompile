void far helper_0(void);
int far ovl_241917(void)
{
    _asm {
        mov ax,0xc
        push ax
        mov ax,0x194
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_0
        add sp,0x6
        retf
    }
}
