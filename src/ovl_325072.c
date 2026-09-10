void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far ovl_325072(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x3D
        _emit 0x0E
        _emit 0x00
        _emit 0x74
        _emit 0x6D
        _emit 0x76
        _emit 0x03
        _emit 0xE9
        _emit 0x80
        _emit 0x00
        _emit 0x2C
        _emit 0x08
        _emit 0x74
        _emit 0x06
        _emit 0x2C
        _emit 0x05
        _emit 0x74
        _emit 0x20
        _emit 0xEB
        _emit 0x76
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xBA
        _emit 0x4D
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0xBA
        _emit 0x4D
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_0
        _emit 0xEB
        _emit 0x58
        _emit 0xB8
        _emit 0x29
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        _emit 0xB8
        _emit 0x2B
        _emit 0x00
        _emit 0x50
        call far ptr helper_2
        _emit 0x83
        _emit 0xC4
        _emit 0x04
        call far ptr helper_3
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0x05
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x06
        _emit 0xB8
        _emit 0x88
        _emit 0x13
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xEB
        _emit 0x19
        _emit 0x90
        _emit 0xB8
        _emit 0xB8
        _emit 0x0B
        _emit 0x50
        call far ptr helper_5
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0xBA
        _emit 0x4D
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_6
        _emit 0x33
        _emit 0xC0
    }
}
