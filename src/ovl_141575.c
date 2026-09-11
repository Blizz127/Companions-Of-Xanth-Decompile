extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_141575(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+103
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+89
        ja short $+93
        cmp al,0x13
        jz short $+77
        ja short $+13
        sub al,0x8
        jz short $+21
        sub al,0x7
L1E:
        jz short $+37
        jmp short $+77
        nop
L23:
        sub al,0x2c
        jz short $+10
        sub al,0xc
        jz short $+26
        sub al,0xc
        jmp short $-15
L2F:
        mov ax,0x3c
L32:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+46
L43:
        mov ax,0x1
        push ax
        mov ax,0xa7
        push ax
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x3e
        jmp short $-39
L5B:
        mov ax,0x3f
        jmp short $-44
        nop
L61:
        mov ax,0x3b
        jmp short $-50
        nop
L67:
        mov ax,0x3d
        jmp short $-56
        nop
L6D:
        xor ax,ax
L6F:
    }
}
