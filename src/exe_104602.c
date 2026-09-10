int g;
void far helper1(void);
void far helper2(void);
void far exe_104602(int a, int b, int c, int d)
{
    _asm {
        cmp word ptr g, 0
        _emit 0x74
        _emit 0x14
        push word ptr d
        push word ptr c
        push word ptr b
        push word ptr a
        call far ptr helper1
        _emit 0xEB
        _emit 0x12
        _emit 0x90
        push word ptr d
        push word ptr c
        push word ptr b
        push word ptr a
        call far ptr helper2
    }
}
