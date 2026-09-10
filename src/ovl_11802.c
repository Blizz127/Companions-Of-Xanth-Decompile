void far helper_0(void);
void far helper_1(void);
int far ovl_11802(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        _emit 0xF6
        _emit 0x06
        _emit 0x6E
        _emit 0x41
        _emit 0x06
        _emit 0x75
        _emit 0x19
        _emit 0xF6
        _emit 0x06
        _emit 0x90
        _emit 0x41
        _emit 0x06
        _emit 0x74
        _emit 0x0A
        _emit 0xA1
        _emit 0x90
        _emit 0x41
        _emit 0x24
        _emit 0xF7
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        _emit 0xEB
        _emit 0x0D
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x00
        _emit 0x00
        _emit 0xFF
        _emit 0x36
        _emit 0x94
        _emit 0x41
        _emit 0xFF
        _emit 0x36
        _emit 0x92
        _emit 0x41
        _emit 0xA0
        _emit 0x6E
        _emit 0x41
        _emit 0x25
        _emit 0x08
        _emit 0x00
        _emit 0x0B
        _emit 0x46
        _emit 0xFE
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xFF
        _emit 0x36
        _emit 0x56
        _emit 0x02
        call far ptr helper_1
    }
}
