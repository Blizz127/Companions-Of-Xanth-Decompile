extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_289071(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xbb8
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x17
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x37ec
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x1770
        push ax
        call far ptr helper_1
        add sp,0x2
        mov word ptr mn02A8,0x1b
        mov ax,0x5a
        push ax
        call far ptr helper_4
        add sp,0x2
        mov ax,0x1
        retf
    }
}
