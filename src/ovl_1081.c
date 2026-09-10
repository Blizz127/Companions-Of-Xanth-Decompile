void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_1081(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x2D
        _emit 0x40
        _emit 0x01
        _emit 0xF7
        _emit 0xD8
        _emit 0x99
        _emit 0x2B
        _emit 0xC2
        _emit 0xD1
        _emit 0xF8
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        call far ptr helper_2
    }
}
