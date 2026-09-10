void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_3744(void)
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
        call far ptr helper_1
        _emit 0xB8
        _emit 0x2A
        _emit 0x63
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_3
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB9
        _emit 0x7F
        _emit 0x00
        _emit 0x51
        _emit 0x38
        _emit 0x06
        _emit 0x6E
        _emit 0x03
        _emit 0x1B
        _emit 0xC9
        _emit 0x81
        _emit 0xE1
        _emit 0x08
        _emit 0xFE
        _emit 0x81
        _emit 0xC1
        _emit 0x02
        _emit 0x03
        _emit 0x51
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        call far ptr helper_5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x2B
        _emit 0xC0
        _emit 0xA3
        _emit 0x88
        _emit 0x5D
        _emit 0xA3
        _emit 0x86
        _emit 0x5D
        _emit 0xC7
        _emit 0x06
        _emit 0x8A
        _emit 0x5D
        _emit 0xA0
        _emit 0x00
        _emit 0xCB
    }
}
