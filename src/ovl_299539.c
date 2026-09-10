void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_299539(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x04
        _emit 0xFF
        _emit 0x06
        _emit 0xDE
        _emit 0x02
        _emit 0xA1
        _emit 0xDE
        _emit 0x02
        _emit 0x48
        _emit 0x74
        _emit 0x08
        _emit 0x48
        _emit 0x74
        _emit 0x0F
        _emit 0x48
        _emit 0x74
        _emit 0x14
        _emit 0xEB
        _emit 0x1C
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x22
        _emit 0x39
        _emit 0x8C
        _emit 0x5E
        _emit 0xFE
        _emit 0xEB
        _emit 0x12
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x21
        _emit 0x00
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        _emit 0xC7
        _emit 0x46
        _emit 0xFC
        _emit 0x22
        _emit 0x00
        _emit 0xC7
        _emit 0x46
        _emit 0xFE
        _emit 0x46
        _emit 0xF0
        _emit 0xFF
        _emit 0x76
        _emit 0xFE
        _emit 0xFF
        _emit 0x76
        _emit 0xFC
        _emit 0xB8
        _emit 0x23
        _emit 0x00
        _emit 0xBA
        _emit 0x46
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0x83
        _emit 0x3E
        _emit 0xDE
        _emit 0x02
        _emit 0x03
        _emit 0x7D
        _emit 0x13
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x24
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0xEB
        _emit 0x2B
        _emit 0x90
        _emit 0xB8
        _emit 0x0B
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x88
        _emit 0x13
        _emit 0x50
        call far ptr helper_3
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0xCA
        _emit 0x02
        _emit 0x50
        call far ptr helper_4
        _emit 0xC6
        _emit 0x06
        _emit 0x6C
        _emit 0x03
        _emit 0x01
        _emit 0xB8
        _emit 0x01
        _emit 0x00
    }
}
