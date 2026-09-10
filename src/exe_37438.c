void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_37438(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xA3
        _emit 0x50
        _emit 0x00
        _emit 0xA3
        _emit 0x52
        _emit 0x00
        _emit 0xA3
        _emit 0x54
        _emit 0x00
        _emit 0xBB
        _emit 0x34
        _emit 0x00
        _emit 0x8E
        _emit 0x06
        _emit 0x1E
        _emit 0x5A
        _emit 0x89
        _emit 0x5E
        _emit 0xFC
        _emit 0x8C
        _emit 0x46
        _emit 0xFE
        _emit 0x26
        _emit 0x38
        _emit 0x07
        _emit 0x74
        _emit 0x26
        _emit 0x50
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_4
        call far ptr helper_5
    }
}
