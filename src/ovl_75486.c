void far helper_0(void);
void far helper_1(void);
int far ovl_75486(void)
{
    _asm {
        _emit 0xC6
        _emit 0x06
        _emit 0x25
        _emit 0x03
        _emit 0x01
        call far ptr helper_0
        _emit 0xB9
        _emit 0x0C
        _emit 0x00
        _emit 0x99
        _emit 0xF7
        _emit 0xF9
        _emit 0x42
        _emit 0x52
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
