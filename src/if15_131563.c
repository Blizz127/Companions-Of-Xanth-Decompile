int g;
char g0;
char g1;
void far helper_mkfp(void);
int far if15_131563(int a)
{
    _asm {
        sub sp, 4
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x34
        cmp word ptr g, 1
        _emit 0x76
        _emit 0x07
        mov ax, 2796h
        mov dx, ds
        _emit 0xEB
        _emit 0x03
        xor ax, ax
        cwd
        mov word ptr [bp-4], ax
        mov word ptr [bp-2], dx
        push dx
        push ax
        mov ax, 0Dh
        mov dx, 0F00Fh
        push dx
        push ax
        call far ptr helper_mkfp
        add sp, 8
        xor al, al
        mov byte ptr g0, al
        mov byte ptr g1, al
        _emit 0xEB
        _emit 0x0D
        _emit 0x90
        cmp word ptr g, 1
        _emit 0x76
        _emit 0x05
        mov ax, 9Ch
        _emit 0xEB
        _emit 0x03
        mov ax, 98h
    }
}
