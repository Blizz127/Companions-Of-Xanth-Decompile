void far helper_0(void);
int far exe_82721(void)
{
    _asm {
        _emit 0x80
        _emit 0x3E
        _emit 0x46
        _emit 0x42
        _emit 0x00
        _emit 0x74
        _emit 0x13
        _emit 0xB8
        _emit 0x46
        _emit 0x42
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
