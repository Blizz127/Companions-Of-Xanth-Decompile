extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_144882(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+61
        mov ax,mn6A06
        cmp ax,0x44
        jz short $+47
        ja short $+51
        sub al,0x13
        jz short $+9
        sub al,0x7
        jz short $+25
        jmp short $+41
        nop
L1D:
        mov ax,0x1b
L20:
        mov dx,0xf011
        push dx
        push ax
        call far ptr helper_0
L2A:
        mov sp,bp
        mov ax,0x1
        jmp short $+22
L31:
        mov ax,0x1
        push ax
        call far ptr helper_1
        jmp short $-16
        nop
L3D:
        mov ax,0x1c
        jmp short $-32
        nop
L43:
        xor ax,ax
L45:
    }
}
