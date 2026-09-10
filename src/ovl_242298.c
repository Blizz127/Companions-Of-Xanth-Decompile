void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_242298(void)
{
    _asm {
        _emit 0x32
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x31
        _emit 0xB8
        _emit 0x39
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x3F
        _emit 0x5C
        _emit 0x50
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x14
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x94
        _emit 0x04
        _emit 0xB9
        _emit 0x8E
        _emit 0x32
        _emit 0x51
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xCB
    }
}
