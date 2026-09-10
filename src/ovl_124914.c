void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_124914(void)
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
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0x81
        _emit 0x3E
        _emit 0x56
        _emit 0x02
        _emit 0x8C
        _emit 0x00
        _emit 0x75
        _emit 0x06
        _emit 0xB8
        _emit 0x92
        _emit 0x01
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0x96
        _emit 0x01
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
