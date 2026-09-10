char g;
void far helper_mkfp(void);
int far if15_281527(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x05
        mov ax, 170h
        _emit 0xEB
        _emit 0x24
        cmp byte ptr g, 0
        _emit 0x75
        _emit 0x09
        mov ax, 47h
        mov dx, 0F03Eh
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        xor ax, ax
        cwd
        push dx
        push ax
        mov ax, 46h
        mov dx, 0F03Eh
        push dx
        push ax
        call far ptr helper_mkfp
        xor ax, ax
    }
}
