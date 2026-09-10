void far helper_0(void);
int far exe_100203(void)
{
    _asm {
        _emit 0x50
        _emit 0x50
        _emit 0x50
        _emit 0x50
        call far ptr helper_0
        _emit 0x83
        _emit 0xC4
        _emit 0x08
        _emit 0xCB
    }
}
