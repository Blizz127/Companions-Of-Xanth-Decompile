char gflag;
char gclear;
int g1;
void far helper3(void);
void far helper2(void);
void far helper1(void);
int far if15_264963(int a)
{
    _asm {
        cmp word ptr a, 15
        _emit 0x74
        _emit 0x05
        mov ax, 14Fh
        _emit 0xEB
        _emit 0x39
        cmp byte ptr gflag, 0
        _emit 0x75
        _emit 0xF4
        mov byte ptr gclear, 0
        mov ax, 0E19h
        push ax
        mov ax, 369h
        push ax
        call far ptr helper3
        mov sp, bp
        cmp word ptr g1, 16h
        _emit 0x75
        _emit 0x0C
        mov ax, 5Ah
        push ax
        call far ptr helper2
        _emit 0xEB
        _emit 0x0A
        _emit 0x90
        mov ax, 10h
        push ax
        call far ptr helper1
        xor ax, ax
    }
}
