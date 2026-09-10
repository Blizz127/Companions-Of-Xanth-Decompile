void far helper_0(void);
int far exe_96922(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xC4
        _emit 0x5E
        _emit 0x06
        _emit 0x26
        _emit 0xFF
        _emit 0x77
        _emit 0x02
        _emit 0x26
        _emit 0xFF
        _emit 0x37
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x89
        _emit 0x46
        _emit 0xFC
        _emit 0x89
        _emit 0x56
        _emit 0xFE
        _emit 0x0B
        _emit 0xD0
        _emit 0x74
        _emit 0x14
        _emit 0xC4
        _emit 0x5E
        _emit 0xFC
        _emit 0x26
        _emit 0xF6
        _emit 0x47
        _emit 0x0A
        _emit 0x80
        _emit 0x74
        _emit 0x0A
        _emit 0x26
        _emit 0x8B
        _emit 0x47
        _emit 0x06
        _emit 0x26
        _emit 0x8B
        _emit 0x57
        _emit 0x08
        _emit 0xEB
        _emit 0x03
        _emit 0x33
        _emit 0xC0
        _emit 0x99
    }
}
