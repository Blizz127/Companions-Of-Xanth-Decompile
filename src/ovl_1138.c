void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_1138(int a)
{
    _asm {
        _emit 0x83
        _emit 0xEC
        _emit 0x02
        call far ptr helper_0
        _emit 0x89
        _emit 0x46
        _emit 0xFE
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x1D
        call far ptr helper_2
        _emit 0x2D
        _emit 0x03
        _emit 0x00
        _emit 0x74
        _emit 0x0B
        _emit 0x2D
        _emit 0x18
        _emit 0x00
        _emit 0x74
        _emit 0x1A
        _emit 0xB8
        _emit 0x20
        _emit 0x00
        _emit 0xEB
        _emit 0x18
        _emit 0x90
        call far ptr helper_3
        _emit 0xEB
        _emit 0x19
        _emit 0x90
        _emit 0x83
        _emit 0x7E
        _emit 0xFE
        _emit 0x00
        _emit 0x74
        _emit 0x18
        _emit 0xF6
        _emit 0x46
        _emit 0xFE
        _emit 0x02
        _emit 0x74
        _emit 0x0C
        _emit 0xB8
        _emit 0x1B
        _emit 0x00
        _emit 0x50
        call far ptr helper_4
        _emit 0x83
        _emit 0xC4
        _emit 0x02
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        _emit 0x33
        _emit 0xC0
    }
}
