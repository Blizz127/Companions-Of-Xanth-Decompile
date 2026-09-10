void far helper_0(void);
void far helper_1(void);
int far exe_7548(int a)
{
    _asm {
        call far ptr helper_0
        _emit 0xA0
        _emit 0xF7
        _emit 0x53
        _emit 0x0A
        _emit 0xC0
        _emit 0x74
        _emit 0x05
        call far ptr helper_1
    }
}
