extern int __near mn02BC;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_187333(void)
{
    _asm {
        inc word ptr mn02BC
        mov ax,mn02BC
        dec ax
        jz short $+10
        dec ax
        jz short $+43
        dec ax
        jz short $+58
        jmp short $+102
L12:
        mov ax,0xee
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x14
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_1
        add sp,0x8
        jmp short $+66
L36:
        mov ax,0x15
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+48
L48:
        mov ax,0x16
        mov dx,0xf01f
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1388
        push ax
        call far ptr helper_2
        add sp,0x2
        mov word ptr mn02A8,0x17
        mov ax,0x5a
        push ax
        call far ptr helper_3
        add sp,0x2
L76:
        cmp word ptr mn02BC,0x3
        jnl short $+18
        mov ax,0x2
        push ax
        mov ax,0x19
        push ax
        call far ptr helper_4
        add sp,0x4
L8D:
        mov ax,0x1
        retf
    }
}
