extern int __near mn6A06;
void far helper_0(void);
int far ovl_148606(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+73
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+64
        mov ax,0xa
L1A:
        mov dx,0xf018
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+46
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+30
        ja short $+34
        sub al,0x13
        jz short $+12
        sub al,0x27
        jz short $+8
        sub al,0xa
        jz short $+10
        jmp short $+20
L43:
        mov ax,0x7
        jmp short $-44
        nop
L49:
        mov ax,0x8
        jmp short $-50
        nop
L4F:
        mov ax,0x9
        jmp short $-56
        nop
L55:
        xor ax,ax
L57:
    }
}
