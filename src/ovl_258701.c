void far helper_0(void);
void far helper_1(void);
int far ovl_258701(void)
{
    _asm {
        mov ax,0xe
        push ax
        mov ax,0x144
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+108
        mov ax,0x145
        push ax
        mov ax,0x149
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+82
        mov ax,0x145
        push ax
        mov ax,0x14a
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+62
        mov ax,0x145
        push ax
        mov ax,0x14b
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+42
        mov ax,0x145
        push ax
        mov ax,0x14c
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jnz short $+22
        mov ax,0x145
        push ax
        mov ax,0x14d
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
L78:
        mov ax,0x1
        jmp short $+5
        nop
L7E:
        xor ax,ax
L80:
        retf
    }
}
