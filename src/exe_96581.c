void far helper_0(void);
void far helper_1(void);
int far exe_96581(void)
{
    _asm {
        _emit 0xFF
        _emit 0x36
        _emit 0xA8
        _emit 0x4D
        _emit 0xFF
        _emit 0x36
        _emit 0xA6
        _emit 0x4D
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0xAC
        _emit 0x4D
        _emit 0xFF
        _emit 0x36
        _emit 0xAA
        _emit 0x4D
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xA1
        _emit 0xAC
        _emit 0x4D
        _emit 0x0B
        _emit 0x06
        _emit 0xAA
        _emit 0x4D
        _emit 0x74
        _emit 0x10
        _emit 0xFF
        _emit 0x36
        _emit 0xAC
        _emit 0x4D
        _emit 0xFF
        _emit 0x36
        _emit 0xAA
        _emit 0x4D
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x2B
        _emit 0xC0
        _emit 0xA3
        _emit 0xAC
        _emit 0x4D
        _emit 0xA3
        _emit 0xAA
        _emit 0x4D
        _emit 0xA3
        _emit 0xA8
        _emit 0x4D
        _emit 0xA3
        _emit 0xA6
        _emit 0x4D
        _emit 0xCB
    }
}
