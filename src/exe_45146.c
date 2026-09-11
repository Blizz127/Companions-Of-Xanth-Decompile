void far helper(void);
int far exe_45146(int a, int b)
{
    _asm {
        sub sp,0x6
        lea ax,[bp-0x2]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper
        add sp,0x8
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        or dx,ax
        jz short $+19
        les bx,word ptr [bp-0x6]
        mov cl,[bp-0x2]
        mov al,es:[bx]
        shr al,cl
        and ax,0x1
        jmp short $+5
        nop
L31:
        xor ax,ax
L33:
    }
}
