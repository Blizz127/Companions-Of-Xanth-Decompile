void far helper(void);
void far helper_mkfp(void);
int far if15_292486(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jnz short $+41
        mov ax,0xe
        push ax
        mov ax,0x187
        push ax
        call far ptr helper
        mov sp,bp
        or ax,ax
        jnz short $+22
        mov ax,0x25
        mov dx,0xf045
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp,bp
        xor ax,ax
        jmp short $+6
        nop
L2D:
        mov ax,0x18a
L30:
    }
}
