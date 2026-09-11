void far helper(void);
int far exe_50273(int a, int b)
{
    _asm {
        push word ptr [bp+0x6]
        call far ptr helper
        mov sp,bp
        cmp ax,[bp+0x8]
        jnz short $+8
        mov ax,0x1
        jmp short $+5
        nop
L15:
        xor ax,ax
L17:
    }
}
