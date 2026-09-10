void far helper_0(void);
int far exe_714(int a)
{
    _asm {
        _emit 0x57
        _emit 0x56
        _emit 0x8A
        _emit 0x66
        _emit 0x06
        call far ptr helper_0
        _emit 0x5E
        _emit 0x5F
    }
}
