extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
int far ovl_101244(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+99
        jmp LC5
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jz short $+5
        jmp LC5
L1A:
        cmp word ptr mn6A04,0x78
        jnz short $+5
        jmp LC5
L24:
        push word ptr mn6A04
        mov ax,0x6
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        push word ptr mn6A02
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2d
L5C:
        mov dx,0xf009
        push dx
        push ax
        call far ptr helper_1
        mov sp,bp
        mov ax,0x1
        jmp short $+92
L6D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+58
        ja short $+80
        sub al,0x13
        jz short $+8
        sub al,0x31
        jz short $+26
        jmp short $+70
L81:
        mov ax,0x6e
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2a
        jmp short $-57
L97:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x2b
        jmp short $-79
LAD:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x2c
        jmp short $-102
        nop
LC5:
        xor ax,ax
LC7:
    }
}
