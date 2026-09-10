void far helper_0(void);
void far helper_1(void);
int far exe_42675(void)
{
    _asm {
        _emit 0xB8
        _emit 0xB8
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x06
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x83
        _emit 0x3E
        _emit 0x56
        _emit 0x00
        _emit 0x01
        _emit 0x75
        _emit 0x06
        _emit 0xB8
        _emit 0x18
        _emit 0x00
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0x17
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xCB
    }
}
