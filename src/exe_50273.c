void far helper(void);
int far exe_50273(int a, int b)
{
    _asm {
        push word ptr a
        call far ptr helper
        mov sp, bp
        cmp ax, word ptr b
        _emit 0x75
        _emit 0x06
        mov ax, 1
        _emit 0xEB
        _emit 0x03
        _emit 0x90
        xor ax, ax
    }
}
