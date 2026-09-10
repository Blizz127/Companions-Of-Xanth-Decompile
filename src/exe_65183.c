char g0;
char g1;
char g2;
void far helper1(void);
void far helper2(void);
void far exe_65183(int a, int b, int c)
{
    _asm {
        _emit 0x81
        _emit 0xEC
        _emit 0x02
        _emit 0x00
        _emit 0x56
        _emit 0x57
        mov ax, word ptr a
        mov byte ptr g0, al
        mov ax, word ptr b
        mov byte ptr g1, al
        mov ax, word ptr c
        mov byte ptr g2, al
        call far ptr helper1
        call far ptr helper2
        _emit 0x5F
        _emit 0x5E
    }
}
