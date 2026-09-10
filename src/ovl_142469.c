void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_142469(void)
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
        _emit 0x00
        _emit 0x06
        _emit 0x50
        _emit 0xB8
        _emit 0x29
        _emit 0x03
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xA2
        _emit 0x13
        _emit 0x03
        _emit 0xCB
    }
}
