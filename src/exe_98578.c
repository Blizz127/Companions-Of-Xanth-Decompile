void far helper_0(void);
void far helper_1(void);
int far exe_98578(int a)
{
    _asm {
        call far ptr helper_0
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0x0B
        _emit 0x46
        _emit 0x06
        _emit 0x74
        _emit 0x1C
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0x8B
        _emit 0x56
        _emit 0x08
        _emit 0xA3
        _emit 0x20
        _emit 0x4F
        _emit 0x89
        _emit 0x16
        _emit 0x22
        _emit 0x4F
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xA3
        _emit 0x24
        _emit 0x4F
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0xA3
        _emit 0x26
        _emit 0x4F
        _emit 0xEB
        _emit 0x17
        _emit 0x90
        _emit 0xC7
        _emit 0x06
        _emit 0x20
        _emit 0x4F
        _emit 0xE0
        _emit 0x4E
        _emit 0x8C
        _emit 0x1E
        _emit 0x22
        _emit 0x4F
        _emit 0xC7
        _emit 0x06
        _emit 0x24
        _emit 0x4F
        _emit 0x01
        _emit 0x00
        _emit 0xC7
        _emit 0x06
        _emit 0x26
        _emit 0x4F
        _emit 0x00
        _emit 0x00
        call far ptr helper_1
    }
}
