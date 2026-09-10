void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far exe_86559(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x06
        _emit 0x8D
        _emit 0x46
        _emit 0xFC
        _emit 0x16
        _emit 0x50
        call far ptr helper_0
        _emit 0x80
        _emit 0x7E
        _emit 0xFD
        _emit 0x04
        _emit 0x75
        _emit 0x06
        _emit 0xB8
        _emit 0xBA
        _emit 0x03
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        _emit 0xB8
        _emit 0xDA
        _emit 0x03
        _emit 0xA3
        _emit 0x4C
        _emit 0x63
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x12
        _emit 0xB8
        _emit 0xF0
        _emit 0x42
        _emit 0x1E
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        _emit 0x33
        _emit 0xC0
        _emit 0xEB
        _emit 0x49
        _emit 0x90
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x05
        _emit 0xB8
        _emit 0x0F
        _emit 0x43
        _emit 0xEB
        _emit 0xDF
        _emit 0xB8
        _emit 0x0F
        _emit 0x00
        _emit 0xA3
        _emit 0x4E
        _emit 0x63
        _emit 0xA3
        _emit 0x50
        _emit 0x63
        _emit 0x33
        _emit 0xC0
        _emit 0xA3
        _emit 0x52
        _emit 0x63
        _emit 0xA3
        _emit 0xEA
        _emit 0x42
        call far ptr helper_4
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_5
        _emit 0xC7
        _emit 0x06
        _emit 0xE0
        _emit 0x42
        _emit 0x00
        _emit 0x00
        _emit 0x2B
        _emit 0xC0
        _emit 0xA3
        _emit 0xE4
        _emit 0x42
        _emit 0xA3
        _emit 0xE2
        _emit 0x42
        _emit 0xC7
        _emit 0x06
        _emit 0xE6
        _emit 0x42
        _emit 0x00
        _emit 0xA0
        _emit 0xB8
        _emit 0x01
        _emit 0x00
    }
}
