extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_277606(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+125
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+116
        mov ax,0x6
L1A:
        mov dx,0xf03d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+98
        nop
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+80
        ja short $+84
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+64
        sub al,0x19
        jnz short $+72
L43:
        push word ptr mn6A04
        mov ax,0x26
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        cmp word ptr mn6A06,0x2c
        jnz short $+8
        mov ax,0x3670
        jmp short $+6
        nop
L61:
        mov ax,0x3675
L64:
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x4
        jmp short $-97
L7D:
        mov ax,0x3
        jmp short $-102
        nop
L83:
        mov ax,0x5
        jmp short $-108
        nop
L89:
        xor ax,ax
L8B:
    }
}
