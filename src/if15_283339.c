int g;
void far helper_mkfp(void);
void far helper2(void);
void far helper3(void);
int far if15_283339(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x35
        cmp word ptr g, 0Ah
        _emit 0x7D
        _emit 0x2E
        mov ax, 13h
        mov dx, 0F03Fh
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        mov ax, 1388h
        push ax
        call far ptr helper2
        mov sp, bp
        mov ax, 5A18h
        push ax
        mov ax, 3E9h
        push ax
        call far ptr helper3
        mov sp, bp
        xor ax, ax
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 174h
    }
}
