void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_26714(void)
{
    _asm {
        call far ptr helper_0
        mov ax,0x17
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x17
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x94
        push ax
        mov ax,0x13a
        push ax
        mov ax,0x81
        push ax
        mov ax,0x33
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0xa
        xor ax,ax
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x17
        push ax
        call far ptr helper_2
        add sp,0x2
        call far ptr helper_4
        retf
    }
}
