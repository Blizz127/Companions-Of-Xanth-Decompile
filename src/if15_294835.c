int g;
void far helper_mkfp(void);
int far if15_294835(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x1B
        cmp word ptr g, 3
        _emit 0x7D
        _emit 0x14
        mov ax, 1Eh
        mov dx, 0F01Eh
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 18Dh
    }
}
