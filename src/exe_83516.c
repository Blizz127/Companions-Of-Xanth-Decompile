void far helper4(void);
void far helper1(void);
void far exe_83516(int a)
{
    _asm {
        sub ax, ax
        push ax
        push ax
        mov ax, 2
        push ax
        push word ptr a
        call far ptr helper4
        mov sp, bp
        push word ptr a
        call far ptr helper1
    }
}
