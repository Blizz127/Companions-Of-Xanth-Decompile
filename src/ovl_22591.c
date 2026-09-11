
int far ovl_22591(int a)
{
    _asm {
        sub sp,0x6
        mov ax,0xc0
        mov cx,0x2263
        mov [bp-0x6],ax
        mov dl,0x1
        mov [bp-0x1],dl
        mov [bp-0x2],dl
        mov es,cx
        mov bx,ax
        cmp word ptr es:[bx],0x0
        jz short $+65
L1E:
        mov ax,[bp+0x6]
        cmp es:[bx],ax
        jnz short $+11
        mov ax,[bp+0x8]
        cmp es:[bx+0x2],ax
        jz short $+34
L2F:
        mov ax,[bp+0x6]
        cmp es:[bx+0x2],ax
        jnz short $+10
        mov ax,[bp+0x8]
        cmp es:[bx],ax
        jz short $+17
L40:
        add word ptr [bp-0x6],0x6
        mov bx,[bp-0x6]
        cmp word ptr es:[bx],0x0
        jnz short $-45
        jmp short $+16
L4F:
        mov al,es:[bx+0x4]
        mov [bp-0x2],al
        mov al,es:[bx+0x5]
        mov [bp-0x1],al
L5D:
        mov ax,[bp-0x2]
    }
}
