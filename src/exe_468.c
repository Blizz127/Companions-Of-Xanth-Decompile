void far helper_0(void);
int far exe_468(void)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        call far ptr helper_0
        _emit 0x1E
        _emit 0xB4
        _emit 0x25
        _emit 0xB0
        _emit 0x08
        _emit 0x2E
        _emit 0xC5
        _emit 0x16
        _emit 0x0C
        _emit 0x00
        _emit 0xCD
        _emit 0x21
        _emit 0x1F
        _emit 0xCB
    }
}
