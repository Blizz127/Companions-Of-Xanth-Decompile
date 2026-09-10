void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int near exe_4873(void)
{
    _asm {
        _emit 0xB4
        _emit 0x4A
        _emit 0xCD
        _emit 0x21
        _emit 0x36
        _emit 0x8C
        _emit 0x1E
        _emit 0xC0
        _emit 0x53
        _emit 0x16
        _emit 0x07
        _emit 0xFC
        _emit 0xBF
        _emit 0x32
        _emit 0x5C
        _emit 0xB9
        _emit 0x60
        _emit 0x6E
        _emit 0x2B
        _emit 0xCF
        _emit 0x33
        _emit 0xC0
        _emit 0xF3
        _emit 0xAA
        _emit 0x16
        _emit 0x1F
        _emit 0x8B
        _emit 0x0E
        _emit 0xF8
        _emit 0x59
        _emit 0xE3
        _emit 0x02
        _emit 0xFF
        _emit 0xD1
        call far ptr helper_0
        call far ptr helper_1
        _emit 0x33
        _emit 0xED
        call far ptr helper_2
        _emit 0x16
        _emit 0x1F
        _emit 0xFF
        _emit 0x36
        _emit 0xE8
        _emit 0x53
        _emit 0xFF
        _emit 0x36
        _emit 0xE6
        _emit 0x53
        _emit 0xFF
        _emit 0x36
        _emit 0xE4
        _emit 0x53
        _emit 0xFF
        _emit 0x36
        _emit 0xE2
        _emit 0x53
        _emit 0xFF
        _emit 0x36
        _emit 0xE0
        _emit 0x53
        call far ptr helper_3
        _emit 0x50
        _emit 0x0E
        _emit 0xE8
        _emit 0x07
        _emit 0x01
        _emit 0xC3
    }
}
