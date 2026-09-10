char g;
int g2;
void far helper1(void);
void far helper2(void);
int far exe_70566(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov al, byte ptr g
        cbw
        cmp ax, 0
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x15
        _emit 0x00
        cmp word ptr g2, 0
        _emit 0x75
        _emit 0x03
        _emit 0xE9
        _emit 0x05
        _emit 0x00
        call far ptr helper1
        mov ax, 1
        _emit 0xE9
        _emit 0x0B
        _emit 0x00
        call far ptr helper2
        mov ax, 0
        _emit 0xE9
        _emit 0x00
        _emit 0x00
        _emit 0x5F
        _emit 0x5E
    }
}
