extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_250689(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+39
        jmp short $+93
        nop
L0F:
        mov ax,mn6A06
        dec ax
        dec ax
        jz short $+7
        sub ax,0x36
        jnz short $+80
L1B:
        mov ax,0x128
        push ax
        push word ptr mn6A04
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+61
        nop
L31:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+44
        ja short $+48
        sub al,0x13
        jz short $+12
        sub al,0x25
        jz short $+28
        sub al,0xc
        jz short $+24
        jmp short $+34
L49:
        mov ax,0x3f
L4C:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L5D:
        mov ax,0x40
        jmp short $-20
        nop
L63:
        mov ax,0x41
        jmp short $-26
        nop
L69:
        xor ax,ax
L6B:
    }
}
