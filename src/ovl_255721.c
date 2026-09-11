extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_255721(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+51
        jmp short $+117
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+108
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x5
L2B:
        mov dx,0xf042
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+73
        nop
L3D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+56
        ja short $+60
        cmp al,0x2e
        jz short $+22
        ja short $+12
        sub al,0xf
        jz short $+16
        sub al,0x4
        jz short $+18
        jmp short $+44
L57:
        sub al,0x38
        jz short $+6
        sub al,0xc
        jnz short $+36
L5F:
        mov ax,0x4
        jmp short $-55
        nop
L65:
        mov ax,0x15
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2
        jmp short $-78
L7B:
        mov ax,0x3
        jmp short $-83
        nop
L81:
        xor ax,ax
L83:
    }
}
