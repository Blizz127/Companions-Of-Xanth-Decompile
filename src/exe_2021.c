
int far exe_2021(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x5E
        _emit 0x06
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xFA
        _emit 0x89
        _emit 0x87
        _emit 0x7D
        _emit 0x40
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x09
        _emit 0xC4
        _emit 0x9F
        _emit 0x7F
        _emit 0x40
        _emit 0x26
        _emit 0xC7
        _emit 0x07
        _emit 0xFF
        _emit 0x00
        _emit 0xFB
    }
}
