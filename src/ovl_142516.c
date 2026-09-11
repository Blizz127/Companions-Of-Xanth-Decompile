extern int __near mn2992;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_142516(void)
{
    _asm {
        mov ax,0xa7
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2994
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        inc word ptr mn2992
        mov ax,mn2992
        dec ax
        jz short $+11
        dec ax
        jz short $+30
        dec ax
        jz short $+49
        jmp short $+82
        nop
L32:
        mov ax,0x126
        push ax
        mov ax,0xa7
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x52
        jmp short $+47
        nop
L48:
        mov ax,0x127
        push ax
        mov ax,0xa7
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x53
        jmp short $+25
        nop
L5E:
        xor ax,ax
        push ax
        mov ax,0x9d
        push ax
        mov ax,0xa7
        push ax
        call far ptr helper_3
        add sp,0x6
        mov ax,0x54
L74:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L81:
        cmp word ptr mn2992,0x3
        jnl short $+20
        mov ax,0x1
        push ax
        mov ax,0xe
        push ax
        call far ptr helper_4
        add sp,0x4
        jmp short $+8
L9A:
        mov word ptr mn2992,0x0
LA0:
        mov ax,0x1
        retf
    }
}
