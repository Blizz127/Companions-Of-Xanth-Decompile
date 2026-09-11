void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_91308(void)
{
    _asm {
        call far ptr helper_0
        mov ax,0x72
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_3
        mov ax,0x1
        retf
    }
}
