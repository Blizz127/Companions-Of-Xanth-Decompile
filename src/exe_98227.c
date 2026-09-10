unsigned long g0;
unsigned long g1;
int g2;
void far helper1(void);
void far helper2(void);
void far helper3(void);
void far exe_98227(void)
{
    _asm {
        call far ptr helper1
        call far ptr helper2
        push word ptr g0+2
        push word ptr g0
        call far ptr helper3
        mov sp, bp
        push word ptr g1+2
        push word ptr g1
        call far ptr helper3
        mov sp, bp
        mov ax, 0
        int 33h
        mov word ptr g2, 0
    }
}
