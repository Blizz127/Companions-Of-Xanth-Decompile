void far helper_0(void);
int far exe_24890(int a)
{
    _asm {
        mov ax,[bp+0x8]
        mov bx,[bp+0x6]
        call far ptr helper_0
        mov dx,es
        mov ax,bx
    }
}
