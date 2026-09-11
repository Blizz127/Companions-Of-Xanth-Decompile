void far cli_flag(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jnz L0A
        cli
        jmp short L0B
        nop
L0A:
        sti
L0B:
    }
}
