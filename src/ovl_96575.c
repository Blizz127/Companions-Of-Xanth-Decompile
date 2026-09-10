void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_96575(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x2D
        _emit 0x08
        _emit 0x00
        _emit 0x74
        _emit 0x17
        _emit 0x48
        _emit 0x7D
        _emit 0x03
        _emit 0xE9
        _emit 0x94
        _emit 0x00
        _emit 0x71
        _emit 0x03
        _emit 0xE9
        _emit 0x8F
        _emit 0x00
        _emit 0x48
        _emit 0x48
        _emit 0x7E
        _emit 0x28
        _emit 0x48
        _emit 0x48
        _emit 0x74
        _emit 0x42
        _emit 0xE9
        _emit 0x84
        _emit 0x00
        _emit 0x90
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x63
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x1F
        _emit 0x00
        _emit 0xBA
        _emit 0x16
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x63
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0x63
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0x05
        _emit 0xB8
        _emit 0x1D
        _emit 0x00
        _emit 0xEB
        _emit 0xDA
        _emit 0xB8
        _emit 0x1E
        _emit 0x00
        _emit 0xEB
        _emit 0xD5
        _emit 0x90
        _emit 0x80
        _emit 0x3E
        _emit 0x0A
        _emit 0x03
        _emit 0x00
        _emit 0x75
        _emit 0x3E
        _emit 0xB8
        _emit 0x06
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x03
        _emit 0x5A
        _emit 0x50
        _emit 0xB8
        _emit 0x14
        _emit 0x01
        _emit 0x50
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0xC6
        _emit 0x06
        _emit 0x0A
        _emit 0x03
        _emit 0x01
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0x50
        _emit 0xB9
        _emit 0x09
        _emit 0x00
        _emit 0x51
        call far ptr helper_5
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x26
        _emit 0x80
        _emit 0x50
        call far ptr helper_6
        _emit 0x33
        _emit 0xC0
    }
}
