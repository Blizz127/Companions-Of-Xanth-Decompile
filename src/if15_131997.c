int g;
char g0;
char g1;
void far helper_mkfp(void);
int far if15_131997(int a)
{
    _asm {
        sub sp, 4
        cmp word ptr a, 15
        _emit 0x75
        _emit 0x36
        cmp word ptr g, 1
        _emit 0x76
        _emit 0x07
        mov ax, 27BCh
        mov dx, ds
        _emit 0xEB
        _emit 0x03
        xor ax, ax
        cwd
        mov word ptr [bp-4], ax
        mov word ptr [bp-2], dx
        push dx
        push ax
        mov ax, 10h
        mov dx, 0F00Fh
        push dx
        push ax
        call far ptr helper_mkfp
        add sp, 8
        xor al, al
        mov byte ptr g0, al
        mov byte ptr g1, al
        mov ax, 98h
        _emit 0xEB
        _emit 0x03
        mov ax, 9Ah
    }
}
