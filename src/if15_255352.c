char g;
void far helper_mkfp(void);
int far if15_255352(int a)
{
    _asm {
        sub sp, 4
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x26
        cmp byte ptr g, 1
        _emit 0x75
        _emit 0x05
        xor ax, ax
        cwd
        _emit 0xEB
        _emit 0x05
        mov ax, 3490h
        mov dx, ds
        mov word ptr [bp-4], ax
        mov word ptr [bp-2], dx
        push dx
        push ax
        mov ax, 31h
        mov dx, 0F027h
        push dx
        push ax
        call far ptr helper_mkfp
        mov ax, 132h
    }
}
