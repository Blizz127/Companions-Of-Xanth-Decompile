extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_322297(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+107
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+98
        mov ax,0x25
L1A:
        mov dx,0xf04b
        push dx
        push ax
        call far ptr helper_0
L24:
        mov sp,bp
        mov ax,0x1
        jmp short $+80
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+68
        sub al,0x7
        jz short $+16
        dec al
        jz short $+36
        sub al,0xb
        jz short $+38
        sub al,0x19
        jz short $+40
        jmp short $+50
L47:
        mov ax,0x3ad8
        push ds
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        push ax
        call far ptr helper_2
        jmp short $-56
        nop
L5F:
        mov ax,0x23
        jmp short $-72
        nop
L65:
        mov ax,0x21
        jmp short $-78
        nop
L6B:
        mov ax,0x22
        jmp short $-84
        nop
L71:
        mov ax,0x24
        jmp short $-90
        nop
L77:
        xor ax,ax
L79:
    }
}
