void far helper_0(void);
void far helper_1(void);
int far exe_90692(void)
{
    _asm {
        call far ptr helper_0
        _emit 0x0B
        _emit 0xC0
        _emit 0x74
        _emit 0x07
        call far ptr helper_1
        _emit 0xEB
        _emit 0x02
        _emit 0x33
        _emit 0xC0
        _emit 0xCB
    }
}
