void far helper_0(void);
void far helper_1(void);
int far exe_114295(int a)
{
    _asm {
        _emit 0x33
        _emit 0xC0
        _emit 0x50
        call far ptr helper_0
        _emit 0x8B
        _emit 0xE5
        _emit 0xB1
        _emit 0x03
        _emit 0x8B
        _emit 0x46
        _emit 0x0C
        _emit 0xD3
        _emit 0xE0
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0x0C
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x0A
        _emit 0xD3
        _emit 0xE0
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0x0A
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x08
        _emit 0xD3
        _emit 0xE0
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0x08
        _emit 0x50
        _emit 0x8B
        _emit 0x46
        _emit 0x06
        _emit 0xD3
        _emit 0xE0
        _emit 0x2D
        _emit 0x04
        _emit 0x00
        _emit 0x89
        _emit 0x46
        _emit 0x06
        _emit 0x50
        call far ptr helper_1
    }
}
