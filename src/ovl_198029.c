extern char __near mb0329;
void far helper_0(void);
int far ovl_198029(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x10
        jnz short $+47
        cmp byte ptr mb0329,0x0
        jnz short $+32
        mov ax,0xa
        push ax
        mov ax,0x103
        push ax
        call far ptr helper_0
        mov sp,bp
        or ax,ax
        jz short $+7
        mov ax,0x311a
        jmp short $+11
L25:
        mov ax,0x3123
        jmp short $+6
        nop
L2B:
        mov ax,0x3130
L2E:
        mov dx,ds
        jmp short $+6
        nop
L33:
        xor ax,ax
        cwd
L36:
    }
}
