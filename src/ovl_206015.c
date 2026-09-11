extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_206015(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x1f
L2B:
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+81
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+64
        ja short $+68
        cmp al,0x2c
        jz short $+28
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+24
        jmp short $+52
L57:
        sub al,0x38
        jz short $+24
        sub al,0x6
        jz short $+26
        sub al,0x6
        jz short $+28
        jmp short $+38
L65:
        mov ax,0x1a
        jmp short $-61
        nop
L6B:
        mov ax,0x19
        jmp short $-67
        nop
L71:
        mov ax,0x1b
        jmp short $-73
        nop
L77:
        mov ax,0x1e
        jmp short $-79
        nop
L7D:
        mov ax,0x1c
        jmp short $-85
        nop
L83:
        mov ax,0x1d
        jmp short $-91
        nop
L89:
        xor ax,ax
L8B:
    }
}
