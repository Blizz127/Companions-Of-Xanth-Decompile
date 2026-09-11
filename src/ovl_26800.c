void far helper_0(void);
int far ovl_26800(int a)
{
    _asm {
        sub sp,0x6
        mov byte ptr [bp-0x6],0x0
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        mov es,dx
        mov bx,ax
        mov [bp-0x4],ax
        mov word ptr [bp-0x2],es
        cmp word ptr es:[bx],0x0
        jz short $+80
L22:
        cmp byte ptr [bp-0x6],0x1
        jnz short $+31
        mov bx,[bp-0x4]
        mov ax,es:[bx+0x2]
        mov es:[bx],ax
        cmp word ptr es:[bx+0x4],0x0
        jnz short $+36
        les bx, [bp-0x4]
        mov word ptr es:[bx+0x2],0x0
        jmp short $+46
        nop
L45:
        mov ax,[bp+0x8]
        mov bx,[bp-0x4]
        cmp es:[bx],ax
        jnz short $+13
        mov byte ptr [bp-0x6],0x1
        cmp word ptr es:[bx+0x2],0x0
        jz short $+18
L5B:
        add word ptr [bp-0x4],0x2
        les bx, [bp-0x4]
        cmp word ptr es:[bx],0x0
        jnz short $-68
        jmp short $+8
        nop
L6B:
        mov word ptr es:[bx],0x0
L70:
    }
}
