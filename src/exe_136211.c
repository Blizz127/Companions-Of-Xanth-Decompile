extern int __near mn0056;
extern int __near mn0052;
extern int __near mn0054;
extern int __near mn000A;
extern int __near mn000C;

int far exe_136211(void)
{
    _asm {
        push ax
        mov word ptr cs:mn0056,es
        mov ax,cs:mn0052
        or ax,cs:mn0054
        jnz short $+20
        cli
        mov ax,es:mn000A
        mov cs:mn0052,ax
        mov ax,es:mn000C
        mov cs:mn0054,ax
        sti
L23:
        pop ax
        retf
    }
}
