void far helper(void);
int far if16_136051(int a)
{
    _asm {
        cmp word ptr a, 16
        _emit 0x75
        _emit 0x17
        call far ptr helper
        or ax, ax
        _emit 0x74
        _emit 0x06
        mov ax, 28FFh
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 2908h
        mov dx, ds
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        xor ax, ax
        cwd
    }
}
