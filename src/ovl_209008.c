void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_209008(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x83
        _emit 0x7E
        _emit 0x0E
        _emit 0x00
        _emit 0x74
        _emit 0x26
        _emit 0xFF
        _emit 0x36
        _emit 0xFE
        _emit 0x31
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xEB
        _emit 0x55
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x3B
        _emit 0x46
        _emit 0x0C
        _emit 0x7F
        _emit 0x4A
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0x3B
        _emit 0x46
        _emit 0x0A
        _emit 0x7F
        _emit 0x34
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        call far ptr helper_2
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0xFA
        _emit 0x3D
        _emit 0x11
        _emit 0x00
        _emit 0x7D
        _emit 0x05
        _emit 0xC7
        _emit 0x46
        _emit 0xFA
        _emit 0x11
        _emit 0x00
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xFF
        _emit 0x76
        _emit 0xFA
        call far ptr helper_3
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xFF
        _emit 0x46
        _emit 0xFE
        _emit 0x39
        _emit 0x46
        _emit 0xFE
        _emit 0x7E
        _emit 0xCC
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0xFF
        _emit 0x46
        _emit 0xFC
        _emit 0x39
        _emit 0x46
        _emit 0xFC
        _emit 0x7E
        _emit 0xB6
    }
}
