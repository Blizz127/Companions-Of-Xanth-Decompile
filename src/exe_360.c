void far helper_0(void);
int far exe_360(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x9C
        _emit 0xFA
        _emit 0x2E
        _emit 0xA3
        _emit 0x08
        _emit 0x00
        _emit 0x3D
        _emit 0x01
        _emit 0x00
        _emit 0x2E
        _emit 0xC7
        _emit 0x06
        _emit 0x06
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0x2E
        _emit 0x83
        _emit 0x16
        _emit 0x06
        _emit 0x00
        _emit 0x00
        call far ptr helper_0
        _emit 0x9D
    }
}
