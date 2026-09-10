char g0;
char g1;
char g2;
void far helper_mkfp(void);
int far if15_195940(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x19
        cmp byte ptr g0, 0
        _emit 0x74
        _emit 0x07
        cmp byte ptr g1, 0
        _emit 0x74
        _emit 0x37
        cmp byte ptr g2, 0
        _emit 0x75
        _emit 0x30
        xor ax, ax
        _emit 0xEB
        _emit 0x2F
        cmp byte ptr g0, 0
        _emit 0x75
        _emit 0x11
        mov ax, 56h
        mov dx, 0F021h
        push dx
        push ax
        call far ptr helper_mkfp
        mov sp, bp
        _emit 0xEB
        _emit 0xE4
        cmp byte ptr g1, 0
        _emit 0x74
        _emit 0x0D
        cmp byte ptr g2, 0
        _emit 0x75
        _emit 0x06
        mov ax, 57h
        _emit 0xEB
        _emit 0xDF
        _emit 0x90
        mov ax, 102h
    }
}
