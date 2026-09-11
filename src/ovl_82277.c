extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_82277(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+113
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+104
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x28
L2B:
        mov dx,0xf004
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+69
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+36
        ja short $+56
        sub al,0x13
        jz short $+12
        sub al,0x16
        jz short $+14
        dec al
        jz short $+16
        jmp short $+42
L55:
        mov ax,0x24
        jmp short $-45
        nop
L5B:
        mov ax,0x25
        jmp short $-51
        nop
L61:
        mov ax,0x27
        jmp short $-57
        nop
L67:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x26
        jmp short $-80
L7D:
        xor ax,ax
L7F:
    }
}
