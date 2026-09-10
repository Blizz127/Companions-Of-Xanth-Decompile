void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_92781(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x0A
        _emit 0x57
        _emit 0x56
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x01
        _emit 0x1B
        _emit 0xC0
        _emit 0x25
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB1
        _emit 0x03
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xD3
        _emit 0xE0
        _emit 0x8B
        _emit 0xD0
        _emit 0x05
        _emit 0x07
        _emit 0x00
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x10
        _emit 0x03
        _emit 0x46
        _emit 0x08
        _emit 0xD3
        _emit 0xE0
        _emit 0x05
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0x52
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xD3
        _emit 0xE0
        _emit 0x8B
        _emit 0xC8
        _emit 0x2D
        _emit 0x03
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        _emit 0x8B
        _emit 0xF1
        _emit 0x8B
        _emit 0xFA
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x0A
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x01
        _emit 0xF5
        _emit 0x1B
        _emit 0xC0
        _emit 0x25
        _emit 0x0D
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x57
        _emit 0x56
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x5E
        _emit 0x5F
    }
}
