void far helper(void);
void far helper_mkfp(void);
int far if15_298999(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+37
        mov ax,0x24
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jz short $+22
        mov ax,0x16
        mov dx,0xf046
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L29:
        mov ax,0x18a
L2C:
    }
}
