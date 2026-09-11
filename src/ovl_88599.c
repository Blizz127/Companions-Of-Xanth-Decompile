extern int __near mn6A06;
void far helper_0(void);
int far ovl_88599(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+55
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+41
        ja short $+45
        sub al,0x13
        jz short $+9
        sub al,0x19
        jz short $+25
        jmp short $+35
        nop
L1D:
        mov ax,0x33
L20:
        mov dx,0xf005
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+16
L31:
        mov ax,0x34
        jmp short $-20
        nop
L37:
        mov ax,0x35
        jmp short $-26
        nop
L3D:
        xor ax,ax
L3F:
    }
}
