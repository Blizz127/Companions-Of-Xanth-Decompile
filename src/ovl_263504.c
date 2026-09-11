extern int __near mn6A06;
void far helper_0(void);
int far ovl_263504(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+57
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+43
        ja short $+47
        sub al,0x8
        jz short $+10
        sub al,0xb
        jz short $+27
        sub al,0x19
        jnz short $+35
L1E:
        mov ax,0x3d
L21:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+17
        nop
L33:
        mov ax,0x3c
        jmp short $-21
        nop
L39:
        mov ax,0x3e
        jmp short $-27
        nop
L3F:
        xor ax,ax
L41:
    }
}
