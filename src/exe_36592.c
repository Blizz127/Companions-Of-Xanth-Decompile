void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_36592(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x8D
        _emit 0x46
        _emit 0xFC
        _emit 0x16
        _emit 0x50
        _emit 0x8D
        _emit 0x46
        _emit 0xFE
        _emit 0x16
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x28
        call far ptr helper_1
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xFE
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x14
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x18
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x0C
        call far ptr helper_3
    }
}
