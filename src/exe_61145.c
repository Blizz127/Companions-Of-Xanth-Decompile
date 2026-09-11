void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_61145(void)
{
    _asm {
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_0
        add sp,0x4
        call far ptr helper_1
        call far ptr helper_2
        mov ax,0x10
        push ax
        call far ptr helper_3
        add sp,0x2
        retf
    }
}
