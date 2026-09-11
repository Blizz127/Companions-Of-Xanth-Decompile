void far helper4(void);
int far eq1_noparam(void)
{
    _asm {
        sub ax,ax
        push ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper4
        mov sp,bp
        dec ax
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L19:
        xor ax,ax
L1B:
    }
}
