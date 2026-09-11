extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_270416(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+109
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+100
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x6
L2B:
        mov dx,0xf03a
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+65
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+48
        ja short $+52
        cmp al,0x2c
        jz short $+24
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xb
        jz short $+20
        jmp short $+36
L57:
        sub al,0x38
        jz short $+20
        sub al,0xc
        jz short $+16
        jmp short $+26
L61:
        mov ax,0x4
        jmp short $-57
        nop
L67:
        mov ax,0x2
        jmp short $-63
        nop
L6D:
        mov ax,0x3
        jmp short $-69
        nop
L73:
        mov ax,0x5
        jmp short $-75
        nop
L79:
        xor ax,ax
L7B:
    }
}
