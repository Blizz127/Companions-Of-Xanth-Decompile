void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_34489(void)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB9
        _emit 0x01
        _emit 0x00
        _emit 0x51
        _emit 0xBA
        _emit 0x91
        _emit 0x00
        _emit 0x52
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB9
        _emit 0x01
        _emit 0x00
        _emit 0x51
        _emit 0xB9
        _emit 0x92
        _emit 0x00
        _emit 0x51
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB9
        _emit 0x03
        _emit 0x00
        _emit 0x51
        _emit 0xB9
        _emit 0x26
        _emit 0x80
        _emit 0x51
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x04
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x26
        _emit 0x80
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x25
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x19
        _emit 0x00
        _emit 0xBA
        _emit 0x35
        _emit 0xF0
        _emit 0xCB
    }
}
