char g;
void far helper(void);
void far exe_67769(void)
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
        _emit 0x03
        _emit 0x00
        _emit 0xE9
        _emit 0x0A
        _emit 0x00
        call far ptr helper
        mov byte ptr g, 1
        _emit 0x5F
        _emit 0x5E
    }
}
