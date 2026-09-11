void far helper_0(void);
int far ovl_34085(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+20
        sub ax,0x1b
        jz short $+45
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        jmp L9B
        nop
L19:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        mov ax,0x6
        push ax
        mov ax,0x80ee
        jmp short $+101
L37:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        xor cx,cx
        push cx
        mov dx,0x806b
        push dx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        xor cx,cx
        push cx
        mov dx,0x806c
        push dx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        push ax
        mov cx,0x806c
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        xor cx,cx
        push cx
        mov cx,0x806d
        push cx
        call far ptr helper_0
        add sp,0x6
        mov ax,0x1
        push ax
        push ax
        mov ax,0x806d
L9A:
        push ax
L9B:
        call far ptr helper_0
    }
}
