extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_255859(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+115
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+106
        mov ax,0xb
L1A:
        mov dx,0xf042
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+88
        nop
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+70
        ja short $+74
        cmp al,0x2c
        jz short $+52
        ja short $+12
        sub al,0xf
        jz short $+18
        sub al,0x4
        jz short $+36
        jmp short $+58
L47:
        sub al,0x2e
        jz short $+42
        sub al,0x16
        jz short $+38
        jmp short $+48
L51:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0xa
        jmp short $-75
L67:
        mov ax,0x6
        jmp short $-80
        nop
L6D:
        mov ax,0x7
        jmp short $-86
        nop
L73:
        mov ax,0x9
        jmp short $-92
        nop
L79:
        mov ax,0x8
        jmp short $-98
        nop
L7F:
        xor ax,ax
L81:
    }
}
