void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_66521(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        call far ptr helper_0
        call far ptr helper_1
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
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
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_7
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x5F
        _emit 0x5E
    }
}
