void far helper_0(void);
int far exe_61366(void)
{
    _asm {
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x65
        _emit 0x01
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x3D
        _emit 0x01
        _emit 0x00
        _emit 0x1B
        _emit 0xC0
        _emit 0x05
        _emit 0x15
        _emit 0x5A
        _emit 0xCB
    }
}
