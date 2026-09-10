void far helper_0(void);
int far exe_103886(int a)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x10
        _emit 0xA0
        _emit 0x09
        _emit 0x6E
        _emit 0x24
        _emit 0x40
        _emit 0x3C
        _emit 0x01
        _emit 0xF5
        _emit 0x1B
        _emit 0xC0
        _emit 0x25
        _emit 0x03
        _emit 0x00
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
