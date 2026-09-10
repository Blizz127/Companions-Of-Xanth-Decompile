void far helper_0(void);
void far helper_1(void);
int far ovl_246496(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x29
        _emit 0x01
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x1A
        _emit 0xB8
        _emit 0x28
        _emit 0x01
        _emit 0x50
        _emit 0xB8
        _emit 0x38
        _emit 0x01
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x06
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
