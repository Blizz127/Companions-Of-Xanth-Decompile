extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_310505(int a)
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
        mov ax,0x2f
L1A:
        mov dx,0xf048
        push dx
        push ax
        call far ptr helper_0
L24:
        mov sp,bp
        mov ax,0x1
        jmp short $+80
L2B:
        mov ax,mn6A06
        cmp ax,0x5b
        jz short $+64
        ja short $+68
        cmp al,0x2c
        jz short $+28
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+30
        jmp short $+52
L45:
        sub al,0x38
        jz short $+30
        sub al,0xc
        jz short $+26
        dec al
        jz short $+28
        jmp short $+38
L53:
        push word ptr mn6A04
        call far ptr helper_1
        jmp short $-56
        nop
L5F:
        mov ax,0x2b
        jmp short $-72
        nop
L65:
        mov ax,0x2c
        jmp short $-78
        nop
L6B:
        mov ax,0x2d
        jmp short $-84
        nop
L71:
        mov ax,0x2e
        jmp short $-90
        nop
L77:
        xor ax,ax
L79:
    }
}
