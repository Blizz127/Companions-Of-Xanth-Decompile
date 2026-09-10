char g;
void far helper_mkfp(void);
int far if15_103898(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x37
        cmp byte ptr g, 8
        _emit 0x75
        _emit 0x06
        mov ax, 24ADh
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 24B7h
        push ds
        push ax
        cmp byte ptr g, 8
        _emit 0x75
        _emit 0x06
        mov ax, 24C1h
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 24C4h
        push ds
        push ax
        mov ax, 4Dh
        mov dx, 0F009h
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x03
        mov ax, 59h
    }
}
