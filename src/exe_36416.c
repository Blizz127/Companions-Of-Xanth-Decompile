void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_36416(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x39
        _emit 0x06
        _emit 0x68
        _emit 0x00
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x9D
        _emit 0x00
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_1
        _emit 0x83
        _emit 0x3E
        _emit 0x68
        _emit 0x00
        _emit 0x00
        _emit 0x74
        _emit 0x39
        _emit 0x83
        _emit 0x3E
        _emit 0x6A
        _emit 0x00
        _emit 0x00
        _emit 0x7E
        _emit 0x32
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        _emit 0xB8
        _emit 0x0F
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x36
        _emit 0x6A
        _emit 0x00
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x36
        _emit 0x68
        _emit 0x00
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        call far ptr helper_5
        _emit 0x8B
        _emit 0xE5
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x00
        _emit 0x74
        _emit 0x36
        _emit 0x83
        _emit 0x7E
        _emit 0x08
        _emit 0x00
        _emit 0x7E
        _emit 0x30
        _emit 0xB8
        _emit 0xFF
        _emit 0xFF
        _emit 0x50
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        call far ptr helper_5
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_6
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x68
        _emit 0x00
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x6A
        _emit 0x00
    }
}
