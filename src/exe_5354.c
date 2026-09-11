extern int __near mn5A0A;
extern int __near mn5A08;
extern int __near mn53AC;

int near exe_5354(void)
{
    _asm {
        mov cx,mn5A0A
        jcxz L0D
        mov bx,0x2
        call dword ptr mn5A08
L0D:
        push ds
        lds dx, mn53AC
        mov ax,0x2500
        int 0x21
        pop ds
        ret
    }
}
