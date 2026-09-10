void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_32197(int a)
{
    _asm {
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x0C
        _emit 0x48
        _emit 0x74
        _emit 0x27
        _emit 0x48
        _emit 0x74
        _emit 0x36
        _emit 0x48
        _emit 0x74
        _emit 0x3B
        _emit 0xEB
        _emit 0x3E
        _emit 0x90
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0xB8
        _emit 0x02
        _emit 0x00
        _emit 0x8B
        _emit 0xE5
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xC6
        _emit 0x06
        _emit 0x00
        _emit 0x1D
        _emit 0x00
        _emit 0xEB
        _emit 0x20
        _emit 0x90
        _emit 0xB8
        _emit 0x10
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        call far ptr helper_2
        _emit 0xEB
        _emit 0x0D
        call far ptr helper_3
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        call far ptr helper_4
    }
}
