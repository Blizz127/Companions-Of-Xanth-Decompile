extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_95312(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+113
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+93
        ja short $+11
        sub ax,0x12
        jz short $+24
        jmp short $+96
        nop
        nop
L1B:
        sub ax,0x2c
        jz short $+83
        sub ax,0xa
        jc short $+84
        sub ax,0x1
        jna short $+73
        jmp short $+77
        nop
L2D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jnz short $+25
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x7
        jmp short $+6
        nop
L57:
        mov ax,0x8
L5A:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L6B:
        mov ax,0x5
        jmp short $-20
        nop
L71:
        mov ax,0x6
        jmp short $-26
        nop
L77:
        xor ax,ax
L79:
    }
}
