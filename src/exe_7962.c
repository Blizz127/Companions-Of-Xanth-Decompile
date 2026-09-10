void far helper_0(void);
int near exe_7962(int a)
{
    _asm {
        _emit 0x56
        _emit 0x8B
        _emit 0x76
        _emit 0x04
        _emit 0x8A
        _emit 0x44
        _emit 0x0A
        _emit 0xA8
        _emit 0x83
        _emit 0x74
        _emit 0x26
        _emit 0xA8
        _emit 0x08
        _emit 0x74
        _emit 0x22
        _emit 0xFF
        _emit 0x74
        _emit 0x08
        _emit 0xFF
        _emit 0x74
        _emit 0x06
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x80
        _emit 0x64
        _emit 0x0A
        _emit 0xF7
        _emit 0x33
        _emit 0xC0
        _emit 0x89
        _emit 0x44
        _emit 0x06
        _emit 0x89
        _emit 0x44
        _emit 0x08
        _emit 0x89
        _emit 0x04
        _emit 0x89
        _emit 0x44
        _emit 0x02
        _emit 0x89
        _emit 0x44
        _emit 0x04
        _emit 0x5E
    }
}
