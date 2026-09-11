extern char __near mb029A;
char g;
void far helper_ne(void);
void far if_eq1_flag(int a, int b)
{
    _asm {
        mov ax,[bp+0x8]
        dec ax
        jz short $+7
        dec ax
        jz short $+12
        jmp short $+24
L0B:
        mov byte ptr mb029A,0x1
        jmp short $+17
        nop
L13:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_ne
L21:
    }
}
