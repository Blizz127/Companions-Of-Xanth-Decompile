void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_51709(int a)
{
    _asm {
        les bx, [bp+0x6]
        mov ax,es:[bx+0xa]
        or ax,es:[bx+0x8]
        jz short $+15
        push word ptr es:[bx]
        call dword ptr es:[bx+0x8]
        mov sp,bp
        or ax,ax
        jz short $+105
L1A:
        les bx, [bp+0x6]
        cmp word ptr es:[bx],0x0
        jz short $+40
        cmp word ptr es:[bx+0x2],0x0
        jnz short $+33
        mov ax,es:[bx+0xa]
        or ax,es:[bx+0x8]
        jnz short $+23
        cmp word ptr es:[bx+0x6],0x0
        jnz short $+16
        push word ptr es:[bx]
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+58
L49:
        les bx, [bp+0x6]
        cmp word ptr es:[bx+0x2],0x0
        jz short $+20
        push word ptr es:[bx+0x2]
        push word ptr es:[bx]
        call far ptr helper_1
        mov sp,bp
        or ax,ax
        jz short $+30
L65:
        les bx, [bp+0x6]
        cmp word ptr es:[bx+0x6],0x0
        jz short $+26
        push word ptr es:[bx+0x6]
        push word ptr es:[bx]
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jnz short $+8
L81:
        xor ax,ax
        jmp short $+7
        nop
        nop
L87:
        mov ax,0x1
L8A:
    }
}
