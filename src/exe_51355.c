void far helper_0(void);
void far helper_1(void);
int near exe_51355(void)
{
    _asm {
        call far ptr helper_0
        _emit 0xA1
        _emit 0x66
        _emit 0x02
        _emit 0xA3
        _emit 0x58
        _emit 0x02
        _emit 0xC6
        _emit 0x06
        _emit 0xEB
        _emit 0x00
        _emit 0x00
        _emit 0xB8
        _emit 0x03
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xA1
        _emit 0x0A
        _emit 0x6A
        _emit 0xA3
        _emit 0x04
        _emit 0x6A
        _emit 0xA1
        _emit 0x08
        _emit 0x6A
        _emit 0xA3
        _emit 0x02
        _emit 0x6A
        _emit 0xA1
        _emit 0xFA
        _emit 0x69
        _emit 0xA3
        _emit 0x06
        _emit 0x6A
        _emit 0x3D
        _emit 0x51
        _emit 0x00
        _emit 0x75
        _emit 0x0C
        _emit 0xA0
        _emit 0x04
        _emit 0x6A
        _emit 0xA2
        _emit 0x5C
        _emit 0x6E
        _emit 0xC7
        _emit 0x06
        _emit 0x04
        _emit 0x6A
        _emit 0x00
        _emit 0x00
        _emit 0x83
        _emit 0x3E
        _emit 0x04
        _emit 0x6A
        _emit 0x00
        _emit 0x74
        _emit 0x1C
        _emit 0x8E
        _emit 0x06
        _emit 0x30
        _emit 0x5A
        _emit 0x8B
        _emit 0x1E
        _emit 0x04
        _emit 0x6A
        _emit 0x8B
        _emit 0xC3
    }
}
