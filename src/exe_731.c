extern int __near mn3FF6;
void far helper_0(void);
int far exe_731(void)
{
    _asm {
        mov ah,0xff
        call far ptr helper_0
        push ax
        mov dx,mn3FF6
        in al,dx
        pop ax
        retf
    }
}
