void far helper_0(void);
void far helper_1(void);
int far exe_48275(void)
{
    _asm {
        _emit 0x83
        _emit 0x3E
        _emit 0x38
        _emit 0x5C
        _emit 0x00
        _emit 0x74
        _emit 0x0C
        _emit 0xFF
        _emit 0x36
        _emit 0x38
        _emit 0x5C
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xC7
        _emit 0x06
        _emit 0xF4
        _emit 0x00
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0x36
        _emit 0x40
        _emit 0x5C
        _emit 0xFF
        _emit 0x36
        _emit 0x3E
        _emit 0x5C
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x36
        _emit 0x3C
        _emit 0x5C
        _emit 0xFF
        _emit 0x36
        _emit 0x3A
        _emit 0x5C
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x36
        _emit 0x58
        _emit 0x5C
        _emit 0xFF
        _emit 0x36
        _emit 0x56
        _emit 0x5C
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x36
        _emit 0x48
        _emit 0x5C
        _emit 0xFF
        _emit 0x36
        _emit 0x46
        _emit 0x5C
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xCB
    }
}
