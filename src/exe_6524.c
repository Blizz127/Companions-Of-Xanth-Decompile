void far helper0(void);
void far helper6(void);
unsigned long far exe_6524(int a, int b, int c, int d, int e)
{
    _asm {
        sub sp,0x8
        call far ptr helper0
        mov [bp-0x2],dx
        or dx,ax
        jnz short $+8
        xor ax,ax
        cwd
        jmp short $+27
        nop
L15:
        push word ptr [bp-0x2]
        push ax
        push word ptr [bp+0xe]
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper6
L2D:
    }
}
