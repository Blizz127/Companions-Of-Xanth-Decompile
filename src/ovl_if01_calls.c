void far helper_ne(void);
void far helper2(void);
void far if01_calls(int a, int b)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+8
        dec ax
        jz short $+36
        jmp short $+47
        nop
L0D:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_ne
        mov sp,bp
        mov ax,0x1
        push ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_ne
        mov sp,bp
L2C:
        mov ax,0xc
        push ax
        mov ax,0x3
        push ax
        call far ptr helper2
L39:
    }
}
