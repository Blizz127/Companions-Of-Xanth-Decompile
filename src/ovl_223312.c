void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_223312(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x10
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0x8D
        _emit 0x46
        _emit 0xF0
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x0C
        _emit 0x5E
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x09
        _emit 0x00
        _emit 0x2B
        _emit 0x06
        _emit 0x48
        _emit 0x6D
        _emit 0x50
        _emit 0x8D
        _emit 0x46
        _emit 0xF0
        _emit 0x16
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x99
        _emit 0x2B
        _emit 0xC2
        _emit 0xD1
        _emit 0xF8
        _emit 0x2B
        _emit 0x06
        _emit 0xDA
        _emit 0x6D
        _emit 0xF7
        _emit 0xD8
        _emit 0x05
        _emit 0x16
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0x8D
        _emit 0x46
        _emit 0xF0
        _emit 0x16
        _emit 0x50
        call far ptr helper_6
    }
}
