void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_188208(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x88
        _emit 0x13
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0xAC
        _emit 0x09
        _emit 0x50
        _emit 0xB8
        _emit 0x49
        _emit 0x01
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x80
        _emit 0x3E
        _emit 0x2F
        _emit 0x03
        _emit 0x00
        _emit 0x74
        _emit 0x12
        _emit 0xC7
        _emit 0x06
        _emit 0xA8
        _emit 0x02
        _emit 0x0B
        _emit 0x00
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xA2
        _emit 0x2E
        _emit 0x03
        _emit 0xCB
    }
}
