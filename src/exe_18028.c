
int far exe_18028(int a)
{
    _asm {
        _emit 0x8A
        _emit 0x66
        _emit 0x06
        _emit 0x8A
        _emit 0xD4
        _emit 0x80
        _emit 0xE2
        _emit 0x0F
        _emit 0xCD
        _emit 0x16
        _emit 0x75
        _emit 0x09
        _emit 0x80
        _emit 0xFA
        _emit 0x01
        _emit 0x75
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xEB
        _emit 0x0A
        _emit 0x80
        _emit 0xFA
        _emit 0x02
        _emit 0x74
        _emit 0x05
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x01
        _emit 0x48
    }
}
