unsigned long g;
void far helper(void);
void far exe_70110(void)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x06
        _emit 0x00
        _emit 0x56
        _emit 0x57
        call far ptr helper
        mov word ptr [bp-6], ax
        mov word ptr [bp-4], dx
        mov ax, word ptr [bp-6]
        mov dx, word ptr [bp-4]
        add word ptr g, ax
        _emit 0x5F
        _emit 0x5E
    }
}
