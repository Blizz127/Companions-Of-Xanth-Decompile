int g0;
int g1;
void far helper1(void);
void far helper2(void);
void far exe_81180(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov es, word ptr g0
        cmp word ptr es:[0], 0
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x0B
        _emit 0x00
        cmp word ptr es:[2], 0
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x12
        _emit 0x00
        call far ptr helper1
        cmp ax, 0
        _emit 0x74
        _emit 0x03
        _emit 0xE9
        _emit 0x05
        _emit 0x00
        call far ptr helper2
        _emit 0x5F
        _emit 0x5E
    }
}
