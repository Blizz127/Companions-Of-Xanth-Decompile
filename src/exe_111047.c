void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_111047(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x8D
        _emit 0x46
        _emit 0xFA
        _emit 0x16
        _emit 0x50
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
        _emit 0x10
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB9
        _emit 0x06
        _emit 0x00
        _emit 0x51
        _emit 0x8B
        _emit 0x4E
        _emit 0x08
        _emit 0x03
        _emit 0x0E
        _emit 0x08
        _emit 0x68
        _emit 0x49
        _emit 0x51
        _emit 0x8B
        _emit 0x4E
        _emit 0x06
        _emit 0x03
        _emit 0x0E
        _emit 0x06
        _emit 0x68
        _emit 0x49
        _emit 0x51
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0x8B
        _emit 0x4E
        _emit 0xFE
        _emit 0x89
        _emit 0x0E
        _emit 0x0A
        _emit 0x68
        _emit 0x51
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0E
        _emit 0xA3
        _emit 0x0C
        _emit 0x68
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0xBA
        _emit 0x4F
        _emit 0x1E
        _emit 0x50
        call far ptr helper_2
        _emit 0xC7
        _emit 0x06
        _emit 0x0E
        _emit 0x68
        _emit 0x00
        _emit 0x00
    }
}
