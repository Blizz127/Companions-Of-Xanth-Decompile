extern char __near mb0310;
void far helper_0(void);
int far ovl_169906(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+15
        cmp byte ptr mb0310,0x0
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L1C:
        xor ax,ax
L1E:
        retf
    }
}
