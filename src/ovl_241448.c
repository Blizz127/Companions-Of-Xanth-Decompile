extern int __near mn3380;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_241448(void)
{
    _asm {
        mov ax,0x60
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x60
        mov cx,0x328e
        push cx
        push ax
        call far ptr helper_1
        add sp,0x4
        push word ptr mn3380
        call far ptr helper_2
        add sp,0x2
        mov ax,0xffff
        push ax
        call far ptr helper_3
        add sp,0x2
        retf
    }
}
