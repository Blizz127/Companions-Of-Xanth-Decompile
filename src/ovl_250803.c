extern int __near mn6A06;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
int far ovl_250803(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+35
        jmp short $+113
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+104
        mov ax,0x126
        push ax
        push word ptr mn6A04
L1F:
        push word ptr mn6A06
        call far ptr helper_0
        mov sp,bp
        jmp short $+85
        nop
L2D:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+68
        ja short $+72
        cmp al,0x38
        jz short $+56
        ja short $+12
        sub al,0x12
        jz short $+18
        dec al
        jz short $+24
        jmp short $+56
L47:
        sub al,0x42
        jz short $+8
        sub al,0x2
        jz short $+36
        jmp short $+46
L51:
        xor ax,ax
        push ax
        mov ax,0x126
        push ax
        jmp short $-57
        nop
L5B:
        mov ax,0x42
L5E:
        mov dx,0xf026
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
        jmp short $+17
        nop
L71:
        mov ax,0x43
        jmp short $-22
        nop
L77:
        mov ax,0x44
        jmp short $-28
        nop
L7D:
        xor ax,ax
L7F:
    }
}
