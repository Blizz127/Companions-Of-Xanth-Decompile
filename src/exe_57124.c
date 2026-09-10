void far helper1(void);
void far helper2(void);
int far exe_57124(int a)
{
    _asm {
        mov ax, word ptr a
        sub ax, 19h
        _emit 0x74
        _emit 0x09
        sub ax, 1Fh
        _emit 0x74
        _emit 0x0C
        xor ax, ax
        _emit 0xEB
        _emit 0x0D
        call far ptr helper1
        _emit 0xEB
        _emit 0x06
        _emit 0x90
        call far ptr helper2
    }
}
