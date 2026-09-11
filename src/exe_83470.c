void far helper2(void);
void far helper1(void);
void far exe_83470(int a, int b)
{
    _asm {
        sub sp,0x6
        cmp word ptr [bp+0x6],0x5
        jnz short $+8
        mov ax,0x80
        jmp short $+5
        nop
L0F:
        xor ax,ax
L11:
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper2
        add sp,0x4
        push dx
        push ax
        call far ptr helper1
    }
}
