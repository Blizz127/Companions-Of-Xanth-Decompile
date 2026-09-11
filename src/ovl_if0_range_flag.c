extern char __near mb030D;
char g;
void far helper_ne(void);
void far if0_range_flag(int a, int b)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+13
        dec ax
        jz short $+29
        dec ax
        jl short $+31
        jo short $+29
        dec ax
        jg short $+26
L12:
        xor ax,ax
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_ne
        mov sp,bp
        jmp short $+8
        nop
L25:
        mov byte ptr mb030D,0x1
L2A:
    }
}
