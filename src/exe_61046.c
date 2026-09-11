void far helper_0(void);
void far helper_1(void);
int far exe_61046(void)
{
    _asm {
        xor ax,ax
        push ax
        push ax
        mov ax,0x0
        mov cx,0x2252
        push cx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x2
        retf
    }
}
