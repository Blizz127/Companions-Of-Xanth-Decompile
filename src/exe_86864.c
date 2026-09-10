void far helper_0(void);
void far helper_1(void);
int far exe_86864(void)
{
    _asm {
        _emit 0x57
        _emit 0x56
        _emit 0xA1
        _emit 0xE4
        _emit 0x42
        _emit 0x0B
        _emit 0x06
        _emit 0xE2
        _emit 0x42
        _emit 0x74
        _emit 0x26
        call far ptr helper_0
        _emit 0x33
        _emit 0xC0
        _emit 0xBA
        _emit 0x00
        _emit 0xA0
        _emit 0x8B
        _emit 0x1E
        _emit 0xE2
        _emit 0x42
        _emit 0x8B
        _emit 0x36
        _emit 0xE4
        _emit 0x42
        _emit 0x1E
        _emit 0x56
        _emit 0x8B
        _emit 0xF8
        _emit 0x8B
        _emit 0xF3
        _emit 0x8E
        _emit 0xC2
        _emit 0x1F
        _emit 0xB9
        _emit 0x00
        _emit 0x7D
        _emit 0xF3
        _emit 0xA5
        _emit 0x1F
        call far ptr helper_1
        _emit 0x5E
        _emit 0x5F
        _emit 0xCB
    }
}
