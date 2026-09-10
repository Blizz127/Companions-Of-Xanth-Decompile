void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_121724(void)
{
    _asm {
        _emit 0x83
        _emit 0x3E
        _emit 0xE2
        _emit 0x51
        _emit 0x00
        _emit 0x74
        _emit 0x7D
        _emit 0xFF
        _emit 0x0E
        _emit 0xE2
        _emit 0x51
        call far ptr helper_0
        _emit 0x8B
        _emit 0x1E
        _emit 0xE2
        _emit 0x51
        _emit 0x03
        _emit 0xDB
        _emit 0xFF
        _emit 0xB7
        _emit 0x80
        _emit 0x69
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0xF7
        _emit 0x2E
        _emit 0xE2
        _emit 0x51
        _emit 0x05
        _emit 0x82
        _emit 0x69
        _emit 0x1E
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0xF7
        _emit 0x2E
        _emit 0xE2
        _emit 0x51
        _emit 0x05
        _emit 0x82
        _emit 0x69
        _emit 0x1E
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_5
        _emit 0xB8
        _emit 0x41
        _emit 0x52
        _emit 0x1E
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0xE0
        _emit 0x51
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x83
        _emit 0x3E
        _emit 0xE2
        _emit 0x51
        _emit 0x00
        _emit 0x75
        _emit 0x0C
        _emit 0xFF
        _emit 0x36
        _emit 0xE4
        _emit 0x51
        call far ptr helper_7
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_8
        _emit 0xCB
    }
}
