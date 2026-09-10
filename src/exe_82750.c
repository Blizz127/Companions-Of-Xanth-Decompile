void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_82750(int a)
{
    _asm {
        _emit 0x57
        _emit 0x56
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x44
        _emit 0x42
        _emit 0xB9
        _emit 0x46
        _emit 0x42
        _emit 0x1E
        _emit 0x51
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0xB4
        _emit 0x46
        _emit 0xB9
        _emit 0x20
        _emit 0x34
        _emit 0xBA
        _emit 0xAF
        _emit 0x38
        _emit 0x8B
        _emit 0xD9
        _emit 0x1E
        _emit 0x8B
        _emit 0xF8
        _emit 0xBE
        _emit 0x54
        _emit 0x6A
        _emit 0x8E
        _emit 0xC1
        _emit 0x8E
        _emit 0xDA
        _emit 0xB9
        _emit 0x18
        _emit 0x00
        _emit 0xF3
        _emit 0xA5
        _emit 0x1F
        _emit 0x8E
        _emit 0xC3
        _emit 0x8B
        _emit 0xF0
        _emit 0xB0
        _emit 0x3F
        _emit 0x26
        _emit 0x88
        _emit 0x04
        _emit 0x26
        _emit 0xA2
        _emit 0xB5
        _emit 0x46
        _emit 0x26
        _emit 0xC6
        _emit 0x06
        _emit 0xB6
        _emit 0x46
        _emit 0x00
        _emit 0x83
        _emit 0x3E
        _emit 0x5A
        _emit 0x42
        _emit 0x00
        _emit 0x75
        _emit 0x13
        _emit 0xB8
        _emit 0xB1
        _emit 0xB8
        _emit 0xBA
        _emit 0xA7
        _emit 0x08
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xA3
        _emit 0x5A
        _emit 0x42
        _emit 0x5E
        _emit 0x5F
    }
}
