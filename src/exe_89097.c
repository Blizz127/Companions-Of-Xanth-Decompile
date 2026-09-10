void far helper_0(void);
void far helper_1(void);
int far exe_89097(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0x57
        _emit 0x56
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x4A
        _emit 0x43
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0x83
        _emit 0x46
        _emit 0xFC
        _emit 0x18
        _emit 0xC7
        _emit 0x07
        _emit 0xFF
        _emit 0xFF
        _emit 0x81
        _emit 0x7E
        _emit 0xFC
        call far ptr helper_0
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        _emit 0xB8
        _emit 0x36
        _emit 0x43
        _emit 0x1E
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xB8
        _emit 0xAF
        _emit 0x38
        _emit 0x1E
        _emit 0xBF
        _emit 0x4A
        _emit 0x6D
        _emit 0xBE
        _emit 0x84
        _emit 0x6A
        _emit 0x1E
        _emit 0x07
        _emit 0x8E
        _emit 0xD8
        _emit 0xB9
        _emit 0x48
        _emit 0x00
        _emit 0xF3
        _emit 0xA5
        _emit 0x1F
        _emit 0x5E
        _emit 0x5F
    }
}
