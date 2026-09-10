void far helper_0(void);
void far helper_1(void);
int far exe_87918(int a)
{
    _asm {
        _emit 0xF6
        _emit 0x46
        _emit 0x06
        _emit 0x80
        _emit 0x74
        _emit 0x0F
        _emit 0xB8
        _emit 0x0A
        _emit 0x00
        _emit 0x50
        _emit 0xFF
        _emit 0x36
        _emit 0x4E
        _emit 0x63
        _emit 0xB8
        _emit 0x01
        _emit 0x00
        _emit 0x50
        _emit 0xEB
        _emit 0x0D
        _emit 0x90
        _emit 0xFF
        _emit 0x36
        _emit 0xEC
        _emit 0x42
        _emit 0xFF
        _emit 0x36
        _emit 0x4E
        _emit 0x63
        _emit 0xFF
        _emit 0x36
        _emit 0xEE
        _emit 0x42
        call far ptr helper_0
        _emit 0xFF
        _emit 0x76
        _emit 0x08
        _emit 0xFF
        _emit 0x76
        _emit 0x0A
        _emit 0xFF
        _emit 0x76
        _emit 0x0C
        _emit 0xFF
        _emit 0x76
        _emit 0x0E
        _emit 0xFF
        _emit 0x76
        _emit 0x06
        call far ptr helper_1
    }
}
