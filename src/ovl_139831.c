extern int __near mn6A06;
void far helper_0(void);
int far ovl_139831(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+55
        mov ax,mn6A06
        cmp ax,0x44
        jz short $+41
        ja short $+45
        sub al,0xf
        jz short $+9
        sub al,0x4
        jz short $+25
        jmp short $+35
        nop
L1D:
        mov ax,0x1e
L20:
        mov dx,0xf010
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L31:
        mov ax,0x1c
        jmp short $-20
        nop
L37:
        mov ax,0x1d
        jmp short $-26
        nop
L3D:
        xor ax,ax
L3F:
    }
}
