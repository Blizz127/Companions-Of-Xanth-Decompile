void far helper_0(void);
void far helper_1(void);
int far ovl_159472(void)
{
    _asm {
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x93
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x1C
        _emit 0x80
        _emit 0x3E
        _emit 0x38
        _emit 0x03
        _emit 0x00
        _emit 0x75
        _emit 0x15
        _emit 0xC6
        _emit 0x06
        _emit 0x38
        _emit 0x03
        _emit 0x01
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xCB
    }
}
