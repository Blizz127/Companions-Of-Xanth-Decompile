void far helper_0(void);
int far exe_113768(int a)
{
    _asm {
        les bx, [bp+0xa]
        cmp byte ptr es:[bx],0x0
        jz short $+54
lbl0A:
        mov al,es:[bx]
        cbw
        push ax
        call far ptr helper_0
        add sp,0x2
        les bx, [bp+0x6]
        mov cx,ax
        mov al,es:[bx]
        cbw
        push ax
        mov si,cx
        call far ptr helper_0
        add sp,0x2
        cmp si,ax
        jnz short $+17
        inc word ptr [bp+0x6]
        inc word ptr [bp+0xa]
        les bx, [bp+0xa]
        cmp byte ptr es:[bx],0x0
        jnz short $-50
lbl3E:
        les bx, [bp+0xa]
        cmp byte ptr es:[bx],0x1
        sbb ax,ax
        neg ax
    }
}
