extern char __near mb0314;
void far helper_0(void);
int far ovl_138001(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jnz short $+15
        cmp byte ptr mb0314,0x0
        jz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L1C:
        xor ax,ax
L1E:
        retf
    }
}
