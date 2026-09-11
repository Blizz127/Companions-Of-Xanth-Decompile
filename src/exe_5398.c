extern int __near mn53FA;
extern int __near mn53F8;
extern void __near nc02E0(void);

int far exe_5398(int a)
{
    _asm {
        mov ax,0xfc
        push ax
        push cs
        call nc02E0
        cmp word ptr mn53FA,0x0
        jz short $+6
        call dword ptr mn53F8
L13:
        mov ax,0xff
        push ax
        push cs
        call nc02E0
    }
}
