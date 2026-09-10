void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_20559(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        call far ptr helper_0
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x18
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0xFF
        _emit 0xFF
        _emit 0xB8
        _emit 0x91
        _emit 0x01
        _emit 0xB9
        _emit 0x81
        _emit 0x31
        _emit 0x51
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x0F
        _emit 0x90
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        call far ptr helper_4
        call far ptr helper_5
        _emit 0x8B
        _emit 0x46
        _emit 0xFE
    }
}
