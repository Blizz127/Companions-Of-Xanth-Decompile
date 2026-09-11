extern char __near mb0D15;
extern void __near nc0014(void);

int far exe_124664(void)
{
    _asm {
        push ax
        push es
        push cs
        call nc0014
        mov ax,0x1dc1
        mov es,ax
        mov byte ptr es:mb0D15,0x1
        pop es
        pop ax
        retf
    }
}
