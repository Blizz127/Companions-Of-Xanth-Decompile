void far helper_0(void);
void far helper_1(void);
int far ovl_4429(void)
{
    _asm {
        _emit 0xC7
        _emit 0x06
        _emit 0x84
        _emit 0x5D
        _emit 0x32
        _emit 0x00
        call far ptr helper_0
        call far ptr helper_1
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xF7
        _emit 0x9A
        _emit 0x5D
        _emit 0x07
        _emit 0xCB
    }
}
