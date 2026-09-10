void far helper_0(void);
void far helper_1(void);
int far exe_100016(int a)
{
    _asm {
        _emit 0xA1
        _emit 0x28
        _emit 0x64
        _emit 0x39
        _emit 0x46
        _emit 0x06
        _emit 0x75
        _emit 0x08
        _emit 0xA1
        _emit 0x2A
        _emit 0x64
        _emit 0x39
        _emit 0x46
        _emit 0x08
        _emit 0x74
        _emit 0x31
        _emit 0xF6
        _emit 0x06
        _emit 0x9E
        _emit 0x4E
        _emit 0x01
        _emit 0x74
        _emit 0x1E
        call far ptr helper_0
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x28
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x2A
        _emit 0x64
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0xEB
        _emit 0x0C
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x28
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x2A
        _emit 0x64
    }
}
