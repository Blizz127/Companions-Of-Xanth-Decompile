void far helper_0(void);
int far exe_89640(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xB8
        _emit 0x36
        _emit 0x43
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x4A
        _emit 0x43
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0xC7
        _emit 0x07
        _emit 0xFF
        _emit 0xFF
        _emit 0x8B
        _emit 0x46
        _emit 0xFC
        _emit 0x05
        _emit 0x02
        _emit 0x00
        _emit 0x1E
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0x5E
        _emit 0xFC
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xC7
        _emit 0x47
        _emit 0x16
        _emit 0x00
        _emit 0x00
        _emit 0x83
        _emit 0x46
        _emit 0xFC
        _emit 0x18
        _emit 0x81
        _emit 0x7E
        _emit 0xFC
        _emit 0x9A
        _emit 0x44
        _emit 0x72
        _emit 0xD6
    }
}
