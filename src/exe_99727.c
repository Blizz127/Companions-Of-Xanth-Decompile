void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_99727(int a)
{
    _asm {
        _emit 0xC7
        _emit 0x06
        _emit 0xA0
        _emit 0x4E
        _emit 0x01
        _emit 0x00
        _emit 0xA0
        _emit 0x9E
        _emit 0x4E
        _emit 0x25
        _emit 0x01
        _emit 0x00
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xA3
        _emit 0x2C
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xA3
        _emit 0x2E
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xA3
        _emit 0x30
        _emit 0x64
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0xA3
        _emit 0x32
        _emit 0x64
        _emit 0xF6
        _emit 0x06
        _emit 0x9E
        _emit 0x4E
        _emit 0x01
        _emit 0x74
        _emit 0x18
        _emit 0xFF
        _emit 0x36
        _emit 0x2A
        _emit 0x64
        _emit 0xFF
        _emit 0x36
        _emit 0x28
        _emit 0x64
        call far ptr helper_1
        _emit 0x8B
        _emit 0xE5
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x05
        call far ptr helper_2
        _emit 0xC7
        _emit 0x06
        _emit 0xA0
        _emit 0x4E
        _emit 0x00
        _emit 0x00
    }
}
