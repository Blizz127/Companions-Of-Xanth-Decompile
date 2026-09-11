extern char __near mb0359;
void far helper_0(void);
int far exe_61391(void)
{
    _asm {
        cmp byte ptr mb0359,0x0
        jz short $+47
        mov ax,0x16d
        push ax
        mov ax,0x157
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+27
        mov ax,0x16c
        push ax
        mov ax,0x16e
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L34:
        xor ax,ax
L36:
        retf
    }
}
