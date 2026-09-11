void far helper_0(void);
void far helper_1(void);
int far ovl_9594(int a)
{
    _asm {
        sub sp,0x8
        mov word ptr [bp-0x2],0x0
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov [bp-0x4],ax
        or ax,ax
        jz short $+55
        mov ax,[bp+0x6]
        mov cx,ax
        add ax,ax
        add ax,cx
        add ax,ax
        add ax,0x66
        mov cx,0x23a1
        mov [bp-0x8],ax
        mov [bp-0x6],cx
L34:
        les bx, [bp-0x8]
        cmp byte ptr es:[bx],0x1
        jz short $+5
        inc word ptr [bp-0x2]
L40:
        push word ptr [bp-0x4]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x4],ax
        or ax,ax
        jnz short $-28
L52:
        mov ax,[bp-0x2]
    }
}
