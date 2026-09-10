void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far if15_151404(int a)
{
    _asm {
        _emit 0x83
        _emit 0x7E
        _emit 0x06
        _emit 0x0F
        _emit 0x74
        _emit 0x27
        _emit 0xB8
        _emit 0xBE
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xBF
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x0E
        _emit 0x80
        _emit 0x3E
        _emit 0x5C
        _emit 0x6E
        _emit 0x01
        _emit 0x75
        _emit 0x07
        _emit 0xB8
        _emit 0xC5
        _emit 0x00
        _emit 0xE9
        _emit 0x91
        _emit 0x00
        _emit 0x90
        _emit 0xB8
        _emit 0xBE
        _emit 0x00
        _emit 0xE9
        _emit 0x8A
        _emit 0x00
        _emit 0xB8
        _emit 0xBE
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xBF
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x59
        _emit 0x80
        _emit 0x3E
        _emit 0x5C
        _emit 0x6E
        _emit 0x01
        _emit 0x75
        _emit 0x40
        _emit 0xB8
        _emit 0x0E
        _emit 0x00
        _emit 0x50
        _emit 0xB8
        _emit 0xBF
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x2D
        _emit 0xB8
        _emit 0x1D
        _emit 0x00
        _emit 0xBA
        _emit 0x19
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0x50
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x50
        call far ptr helper_3
        _emit 0x8B
        _emit 0xE5
        _emit 0xB8
        _emit 0x70
        _emit 0x17
        _emit 0x50
        call far ptr helper_4
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        call far ptr helper_5
        _emit 0xBA
        _emit 0x19
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x1D
        _emit 0x90
        _emit 0xA0
        _emit 0x5C
        _emit 0x6E
        _emit 0x2A
        _emit 0xE4
        _emit 0x50
        call far ptr helper_6
        _emit 0x8B
        _emit 0xE5
        _emit 0x52
        _emit 0x50
        _emit 0xB8
        _emit 0x1F
        _emit 0x00
        _emit 0xBA
        _emit 0x19
        _emit 0xF0
        _emit 0x52
        _emit 0x50
        call far ptr helper_2
        _emit 0x33
        _emit 0xC0
    }
}
