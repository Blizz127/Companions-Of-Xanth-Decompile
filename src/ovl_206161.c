extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_206161(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+107
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+98
        mov ax,0x11f
        push ax
        push word ptr mn6A04
L1F:
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+79
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x2c
        jz short $+36
        ja short $+14
        sub ax,0x8
        jz short $+29
        sub ax,0xb
        jz short $+34
        jmp short $+54
L43:
        sub ax,0x38
        jz short $+17
        sub ax,0x6
        jz short $+12
        sub ax,0x6
        jc short $+39
        sub ax,0x1
        ja short $+34
L57:
        push word ptr mn6A02
        mov ax,0x11f
        push ax
        jmp short $-64
L61:
        mov ax,0x20
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        jmp short $+5
        nop
L77:
        xor ax,ax
L79:
    }
}
