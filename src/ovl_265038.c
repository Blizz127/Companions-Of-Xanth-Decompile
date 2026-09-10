void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_265038(void)
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
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0x1D
        _emit 0x00
        _emit 0xB8
        _emit 0x19
        _emit 0x0E
        _emit 0x50
        _emit 0xB8
        _emit 0x5F
        _emit 0x03
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_3
        _emit 0x83
        _emit 0x3E
        _emit 0xA8
        _emit 0x02
        _emit 0x16
        _emit 0x75
        _emit 0x11
        _emit 0xC6
        _emit 0x06
        _emit 0x83
        _emit 0x07
        _emit 0x01
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0xEB
        _emit 0x0A
        _emit 0x90
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
