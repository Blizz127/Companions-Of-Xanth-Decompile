extern char __near mb0359;
char g;
void far helper_mkfp(void);
int far if15_281527(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0xf
        jz short $+7
        mov ax,0x170
        jmp short $+38
L0B:
        cmp byte ptr mb0359,0x0
        jnz short $+11
        mov ax,0x47
        mov dx,0xf03e
        jmp short $+6
        nop
L1B:
        xor ax,ax
        cwd
L1E:
        push dx
        push ax
        mov ax,0x46
        mov dx,0xf03e
        push dx
        push ax
        call far ptr helper_mkfp
        xor ax,ax
L2F:
    }
}
