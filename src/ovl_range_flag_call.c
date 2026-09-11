extern char __near mb02F9;
char g;
void far helper_ne(void);
void far range_flag_call(int a, int b)
{
    _asm {
        mov ax,[bp+0x8]
        dec ax
        dec ax
        jz short $+14
        dec ax
        jl short $+33
        jo short $+31
        dec ax
        dec ax
        jng short $+13
        jmp short $+25
        nop
L13:
        mov byte ptr mb02F9,0x1
        jmp short $+17
        nop
L1B:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_ne
L29:
    }
}
