void far helper_0(void);
void far helper_1(void);
int far exe_50301(int a)
{
    _asm {
        cmp word ptr [bp+0xa],0x0
        jl short $+17
        push word ptr [bp+0x6]
        call far ptr helper_0
        mov sp,bp
        cmp ax,[bp+0xa]
        jnz short $+22
L15:
        push word ptr [bp+0x6]
        call far ptr helper_1
        mov sp,bp
        cmp ax,[bp+0x8]
        jnz short $+7
        mov ax,0x1
        jmp short $+4
L29:
        xor ax,ax
L2B:
    }
}
