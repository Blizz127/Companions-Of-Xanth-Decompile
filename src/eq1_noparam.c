void far helper4(void);
int far eq1_noparam(void)
{
    _asm {
        sub ax, ax
        push ax
        push ax
        push word ptr [bp+8]
        push word ptr [bp+6]
        call far ptr helper4
        mov sp, bp
        dec ax
        _emit 0x75
        _emit 0x05
        mov ax, 1
        _emit 0xEB
        _emit 0x02
        xor ax, ax
    }
}
