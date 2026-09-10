int g;
void far helper_mkfp(void);
int far if15_127366(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x28
        cmp word ptr g, 0
        _emit 0x75
        _emit 0x14
        mov ax, 23h
        mov dx, 0F00Eh
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x11
        _emit 0x90
        mov ax, 24h
        mov dx, 0F00Eh
        push dx
        push ax
        call far ptr helper_mkfp
        mov ax, 97h
    }
}
