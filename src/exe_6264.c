extern void __near nc0006(void);

int far exe_6264(void)
{
    _asm {
        xor ah,ah
        call nc0006
        retf
    }
}
