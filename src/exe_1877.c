void far helper_0(void);
int far exe_1877(void)
{
    _asm {
        _emit 0xB4
        _emit 0x94
        call far ptr helper_0
        _emit 0xFE
        _emit 0x0E
        _emit 0xEC
        _emit 0x40
        _emit 0xCB
    }
}
