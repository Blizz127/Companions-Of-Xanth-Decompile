extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_305552(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jz short $+5
        jmp L9D
L0B:
        mov ax,mn6A06
        cmp ax,0x45
        jnz short $+5
        jmp L97
L16:
        jna short $+5
        jmp L9D
L1B:
        sub al,0x13
        jz short $+12
        sub al,0x19
        jz short $+96
        sub al,0x18
        jz short $+108
        jmp short $+118
L29:
        mov ax,0x3
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        push ax
        mov cx,0xf
        push cx
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1b58
        push ax
        call far ptr helper_2
        mov sp,bp
        mov ax,0x4
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_3
        mov sp,bp
        xor ax,ax
        push ax
        push ax
        mov ax,0x1a9
        push ax
        call far ptr helper_4
        mov sp,bp
        mov ax,0x1ae
        push ax
        call far ptr helper_5
L7A:
        mov sp,bp
        mov ax,0x1
        jmp short $+32
L81:
        mov ax,0x6
L84:
        mov dx,0xf02f
        push dx
        push ax
        call far ptr helper_0
        jmp short $-20
        nop
L91:
        mov ax,0x5
        jmp short $-16
        nop
L97:
        mov ax,0x7
        jmp short $-22
        nop
L9D:
        xor ax,ax
L9F:
    }
}
