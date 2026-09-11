extern int __near mn6A06;
void far helper_0(void);
int far exe_59415(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+6
        dec ax
        dec ax
        jnz short $+43
L0C:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+9
        sub ax,0x32
        jz short $+22
        jmp short $+28
L1B:
        mov ax,0x774
        push ds
L1F:
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+13
        nop
L2D:
        xor ax,ax
        mov dx,0xf007
        push dx
        jmp short $-20
L35:
        xor ax,ax
L37:
    }
}
