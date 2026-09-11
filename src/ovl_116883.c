extern int __near mn6A06;
void far helper_0(void);
int far ovl_116883(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+97
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+88
        mov ax,0x3d
L1A:
        mov dx,0xf00c
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+70
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+54
        ja short $+58
        cmp al,0x13
        jz short $+36
        ja short $+12
        sub al,0x8
        jz short $+18
        sub al,0xa
        jz short $+20
        jmp short $+42
L45:
        sub al,0x2c
        jz short $+8
        sub al,0x18
        jz short $+22
        jmp short $+32
L4F:
        mov ax,0x39
        jmp short $-56
        nop
L55:
        mov ax,0x3c
        jmp short $-62
        nop
L5B:
        mov ax,0x38
        jmp short $-68
        nop
L61:
        mov ax,0x3a
        jmp short $-74
        nop
L67:
        mov ax,0x3b
        jmp short $-80
        nop
L6D:
        xor ax,ax
L6F:
    }
}
