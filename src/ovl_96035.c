extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_96035(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+97
        mov ax,mn6A06
        cmp ax,0x2c
        jz short $+83
        ja short $+87
        sub al,0x12
        jz short $+9
        dec al
        jz short $+67
        jmp short $+77
        nop
L1D:
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
L47:
        mov ax,0x8
L4A:
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L5B:
        mov ax,0x12
        jmp short $-20
        nop
L61:
        mov ax,0x13
        jmp short $-26
        nop
L67:
        xor ax,ax
L69:
    }
}
