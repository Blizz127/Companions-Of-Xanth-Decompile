extern char __near mb0357;
void far helper_0(void);
int far ovl_266408(void)
{
    _asm {
        mov ax,0xa
        push ax
        mov ax,0x155
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+14
        cmp byte ptr mb0357,0x0
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L20:
        xor ax,ax
L22:
        retf
    }
}
