void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_76824(int a)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xA1
        _emit 0x6E
        _emit 0x41
        _emit 0x25
        _emit 0x04
        _emit 0x00
        _emit 0x3D
        _emit 0x00
        _emit 0x00
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x15
        _emit 0x00
        call far ptr helper_1
        _emit 0xB8
        _emit 0x00
        _emit 0x01
        _emit 0xBA
        _emit 0x63
        _emit 0x22
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x26
        _emit 0x6E
        _emit 0x41
        _emit 0x08
        _emit 0x5F
        _emit 0x5E
    }
}
