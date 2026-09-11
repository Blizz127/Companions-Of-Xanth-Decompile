extern char __near mb4E9E;

int far exe_98653(int a)
{
    _asm {
        cmp word ptr [bp+0x6],0x0
        jz short $+9
        and byte ptr mb4E9E,0xfd
        jmp short $+7
L0D:
        or byte ptr mb4E9E,0x2
L12:
    }
}
