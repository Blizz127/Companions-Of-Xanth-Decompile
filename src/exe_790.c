extern int __near mn3FF8;
extern int __near mn3FF6;

int far exe_790(int a)
{
    _asm {
        mov dx,mn3FF8
        mov cx,0xffff
L07:
        in al,dx
        test al,0x40
        jz short $+9
        loop L07
        sub ax,ax
        jmp short $+14
        nop
L13:
        mov dx,mn3FF6
        mov al,[bp+0x6]
        out dx,al
        mov ax,0x1
L1E:
    }
}
