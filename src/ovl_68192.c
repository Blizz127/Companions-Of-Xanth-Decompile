extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_68192(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+95
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+55
        ja short $+85
        sub al,0x13
        jz short $+10
        sub al,0x19
        jz short $+6
        sub al,0xe
        jnz short $+73
L1E:
        mov ax,0x11
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        mov cx,0x3
        push cx
        mov cx,0x80b1
        push cx
        call far ptr helper_1
L3E:
        mov sp,bp
        mov ax,0x1
        jmp short $+36
L45:
        push word ptr mn6A04
        mov ax,0x12
        push ax
        call far ptr helper_2
        mov sp,bp
        push dx
        push ax
        mov ax,0x12
        mov dx,0xf015
        push dx
        push ax
        call far ptr helper_0
        jmp short $-37
L65:
        xor ax,ax
L67:
    }
}
