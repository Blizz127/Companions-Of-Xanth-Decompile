
int near exe_158144(void)
{
    _asm {
        xor al,[bx]
        add [bx+si],al
        add byte ptr [bx+di],0xc3
    }
}
