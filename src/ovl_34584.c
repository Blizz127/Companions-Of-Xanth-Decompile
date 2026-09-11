extern int __near mn6A10;
void far helper_0(void);
void far helper_1(void);
int far ovl_34584(void)
{
    _asm {
        mov ax,0x1
        push ax
        mov ax,0x99
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_0
        add sp,0x6
        or ax,ax
        jz short $+52
        mov ax,0x1
        push ax
        mov ax,0x73
        push ax
        mov ax,0x8a
        push ax
        call far ptr helper_0
        add sp,0x6
        or ax,ax
        jz short $+28
        xor ax,ax
        push ax
        mov ax,0xa
        push ax
        call far ptr helper_1
        add sp,0x4
        mov word ptr mn6A10,0x4be
        mov ax,0x1a
        jmp short $+35
L4A:
        mov ax,0x1
        push ax
        mov ax,0x99
        push ax
        mov ax,0x73
        push ax
        call far ptr helper_0
        add sp,0x6
        or ax,ax
        jz short $+14
        mov word ptr mn6A10,0x4bf
        mov ax,0x1b
L6B:
        mov dx,0xf035
L6E:
        retf
    }
}
