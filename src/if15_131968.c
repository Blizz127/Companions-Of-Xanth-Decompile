char g;
int far if15_131968(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x0F
        cmp byte ptr g, 1
        sbb ax, ax
        and al, 0FDh
        add ax, 9Dh
        _emit 0xEB
        _emit 0x04
        _emit 0x90
        mov ax, 9Dh
    }
}
