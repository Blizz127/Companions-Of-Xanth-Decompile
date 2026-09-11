extern int __near mn5CE2;
extern int __near mn5CDE;
extern int __near mn5CE0;

int far exe_52993(void)
{
    _asm {
        mov ax,mn5CE2
        sub ax,0xcd
        jz short $+6
        xor ax,ax
        jmp short $+19
L0C:
        mov ax,mn5CDE
        mov cx,ax
        add ax,ax
        add ax,ax
        add ax,cx
        add ax,ax
        add ax,mn5CE0
L1D:
        retf
    }
}
