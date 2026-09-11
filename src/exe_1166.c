extern char __near mb401A;

int far exe_1166(void)
{
    _asm {
        sub ah,ah
        mov mb401A,al
    }
}
