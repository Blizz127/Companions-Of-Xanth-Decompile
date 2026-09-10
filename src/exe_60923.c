void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_60923(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        call far ptr helper_0
        call far ptr helper_1
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0xB9
        _emit 0x99
        _emit 0x21
        _emit 0x51
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xB8
        _emit 0xC7
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x3F
        _emit 0x01
        _emit 0x50
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7C
        _emit 0x14
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_6
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        call far ptr helper_7
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x7C
        _emit 0x0B
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_8
    }
}
