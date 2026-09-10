int g;
void far helper1(void);
void far helper2(void);
int far exe_64464(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x04
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov word ptr g, 388h
        call far ptr helper1
        mov word ptr [bp-4], ax
        call far ptr helper2
        mov ax, word ptr [bp-4]
        _emit 0xE9
        _emit 0x00
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
    }
}
