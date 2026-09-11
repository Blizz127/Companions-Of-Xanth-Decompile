extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_150994(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L93
L0B:
        mov ax,mn6A06
        cmp ax,0x49
        jz short $+106
        ja short $+128
        cmp al,0x2c
        jz short $+28
        ja short $+12
        sub al,0x8
        jz short $+22
        sub al,0xb
        jz short $+56
        jmp short $+112
L25:
        sub al,0x2e
        jz short $+56
        sub al,0x16
        jz short $+52
        dec al
        jz short $+70
        jmp short $+98
L33:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0xf
L47:
        mov dx,0xf019
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+63
        nop
L59:
        mov ax,0xe
        jmp short $-21
        nop
L5F:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x12
        jmp short $-44
L75:
        mov ax,0x10
        jmp short $-49
        nop
L7B:
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x11
        jmp short $-73
        nop
L93:
        xor ax,ax
L95:
    }
}
