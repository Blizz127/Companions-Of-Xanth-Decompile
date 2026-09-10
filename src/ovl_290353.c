void far helper_0(void);
int far ovl_290353(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0E
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x87
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
        _emit 0xF7
        _emit 0xD8
        _emit 0xCB
    }
}
