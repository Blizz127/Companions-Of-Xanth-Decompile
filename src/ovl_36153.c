void far helper_0(void);
int far ovl_36153(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+16
        sub ax,0x3
        jz short $+11
        dec ax
        jz short $+16
        dec ax
        jz short $+39
        dec ax
        jnz short $+68
L15:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        jmp short $+52
L1D:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x5
        jmp short $+26
        nop
L37:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        xor ax,ax
        push ax
        mov ax,0x4
L4E:
        push ax
L4F:
        push word ptr [bp+0x6]
        call far ptr helper_0
L57:
    }
}
