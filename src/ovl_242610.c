void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_242610(void)
{
    _asm {
        _emit 0xB8
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x00
        _emit 0x5F
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_2
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x38
        _emit 0xB8
        _emit 0x08
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xA4
        _emit 0x06
        _emit 0xB9
        _emit 0x8E
        _emit 0x32
        _emit 0x51
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x20
        _emit 0xB8
        _emit 0x34
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x02
        _emit 0x5F
        _emit 0x50
        _emit 0xB8
        _emit 0x01
        _emit 0x5F
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0xD0
        _emit 0x07
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xCB
    }
}
