void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_68476(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        _emit 0xC6
        _emit 0x06
        _emit 0x84
        _emit 0x62
        _emit 0x00
        _emit 0xC6
        _emit 0x06
        _emit 0x88
        _emit 0x62
        _emit 0x01
        _emit 0xB8
        _emit 0x20
        _emit 0xA1
        _emit 0xBA
        _emit 0x07
        _emit 0x00
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x00
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        call far ptr helper_2
        _emit 0x5F
        _emit 0x5E
    }
}
