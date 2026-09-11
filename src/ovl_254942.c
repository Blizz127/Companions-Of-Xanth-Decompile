extern int __near mn6A06;
extern int __near mn6A02;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_254942(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+69
        jmp short $+113
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+104
        push word ptr mn6A02
        mov ax,0x23
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x25
L3D:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+51
        nop
L4F:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+34
        ja short $+38
        sub al,0x13
        jz short $+16
        sub al,0x25
        jz short $+18
        sub al,0x2
        jz short $+8
        sub al,0xa
        jz short $+10
        jmp short $+20
L6B:
        mov ax,0x22
        jmp short $-49
        nop
L71:
        mov ax,0x23
        jmp short $-55
        nop
L77:
        mov ax,0x24
        jmp short $-61
        nop
L7D:
        xor ax,ax
L7F:
    }
}
