void far helper_0(void);
int far ovl_38491(int a)
{
    _asm {
        mov ax,[bp+0x8]
        dec ax
        jz short $+11
        dec ax
        jz short $+34
        dec ax
        jz short $+59
        jmp short $+71
        nop
L0F:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        push ax
        mov cx,0x2
        push cx
        jmp short $+8
L29:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
L2F:
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        mov ax,0x3
        push ax
        jmp short $+9
        nop
L45:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
L4B:
        push word ptr [bp+0x6]
        call far ptr helper_0
L53:
    }
}
