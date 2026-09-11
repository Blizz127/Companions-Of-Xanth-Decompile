void far helper1(void);
void far helper2(void);
int far exe_57124(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x19
        jz short $+11
        sub ax,0x1f
        jz short $+14
        xor ax,ax
        jmp short $+15
L11:
        call far ptr helper1
        jmp short $+8
        nop
L19:
        call far ptr helper2
L1E:
    }
}
