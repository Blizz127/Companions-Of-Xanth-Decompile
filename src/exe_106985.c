void far helper_0(void);
int far exe_106985(void)
{
    _asm {
        _emit 0x57
        _emit 0x83
        _emit 0x3E
        _emit 0x68
        _emit 0x4F
        _emit 0x00
        _emit 0x74
        _emit 0x08
        call far ptr helper_0
        _emit 0xEB
        _emit 0x0D
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0xB9
        _emit 0x0A
        _emit 0x00
        _emit 0xBF
        _emit 0x8A
        _emit 0x67
        _emit 0x1E
        _emit 0x07
        _emit 0xF3
        _emit 0xAB
        _emit 0x5F
        _emit 0xCB
    }
}
