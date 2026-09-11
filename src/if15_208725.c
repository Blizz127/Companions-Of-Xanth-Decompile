void far helper3(void);
void far helper(void);
void far helper_mkfp(void);
int far if15_208725(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+63
        xor ax,ax
        push ax
        mov cx,0x11
        push cx
        mov cx,0x127
        push cx
        call far ptr helper3
        mov sp,bp
        or ax,ax
        jz short $+41
        mov ax,0x1
        push ax
        mov ax,0x124
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jnz short $+22
        mov ax,0x5a
        mov dx,0xf025
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L43:
        mov ax,0x10c
L46:
    }
}
