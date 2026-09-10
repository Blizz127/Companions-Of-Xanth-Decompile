void far helper_0(void);
int far ovl_191472(void)
{
    _asm {
        _emit 0xB8
        _emit 0xD9
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x3D
        _emit 0x54
        _emit 0x01
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
