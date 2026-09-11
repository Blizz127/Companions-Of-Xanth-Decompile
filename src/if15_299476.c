void far helper(void);
void far helper_mkfp(void);
int far if15_299476(int a)
{
    _asm {
        mov ax,0xa
        push ax
        mov ax,0x195
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+28
        cmp word ptr [bp+0x6],0xf
        jnz short $+17
        mov ax,0x20
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
L28:
        mov ax,0x19a
        jmp short $+15
L2D:
        cmp word ptr [bp+0x6],0xf
        jz short $+6
        xor ax,ax
        jmp short $+5
L37:
        mov ax,0xffff
L3A:
    }
}
