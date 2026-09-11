extern char __near mb0310;
extern char __near mb0311;
void far helper_0(void);
int far ovl_169937(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+21
        cmp byte ptr mb0310,0x0
        jz short $+14
        cmp byte ptr mb0311,0x0
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L22:
        xor ax,ax
L24:
        retf
    }
}
