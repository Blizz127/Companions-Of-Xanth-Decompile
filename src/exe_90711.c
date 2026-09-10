void far helper_0(void);
int far exe_90711(void)
{
    _asm {
        call far ptr helper_0
        _emit 0x0B
        _emit 0xC0
        _emit 0x75
        _emit 0xF7
        _emit 0xCB
    }
}
