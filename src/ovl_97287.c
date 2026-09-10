void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_97287(void)
{
    _asm {
        _emit 0xFF
        _emit 0x06
        _emit 0xC8
        _emit 0x02
        _emit 0xA1
        _emit 0xC8
        _emit 0x02
        _emit 0x48
        _emit 0x74
        _emit 0x0A
        _emit 0x48
        _emit 0x48
        _emit 0x74
        _emit 0x10
        _emit 0x48
        _emit 0x48
        _emit 0x74
        _emit 0x16
        _emit 0xEB
        _emit 0x29
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x66
        _emit 0x01
        _emit 0xEB
        _emit 0x17
        _emit 0x90
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x67
        _emit 0x01
        _emit 0xEB
        _emit 0x0D
        _emit 0x90
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0x1D
        _emit 0x00
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x68
        _emit 0x01
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x83
        _emit 0x3E
        _emit 0xC8
        _emit 0x02
        _emit 0x05
        _emit 0x7D
        _emit 0x12
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x1E
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x12
        _emit 0xC7
        _emit 0x06
        _emit 0xA8
        _emit 0x02
        _emit 0x13
        _emit 0x00
        _emit 0xB8
        _emit 0x5A
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xCB
    }
}
