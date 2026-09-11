void far helper_0(void);
int far ovl_30022(int a)
{
    _asm {
        mov ax,[bp+0x8]
        dec ax
        jz short $+13
        dec ax
        dec ax
        jz short $+39
        dec ax
        dec ax
        jz short $+43
        jmp short $+125
        nop
L11:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        xor ax,ax
        push ax
        mov ax,0x1
        push ax
        mov ax,0x8009
        push ax
        jmp short $+90
        nop
L2F:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        jmp short $+78
L37:
        xor ax,ax
        push ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x2
        push cx
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov cx,0x3
        push cx
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x4
        push ax
L83:
        push word ptr [bp+0x6]
L86:
        call far ptr helper_0
L8B:
    }
}
