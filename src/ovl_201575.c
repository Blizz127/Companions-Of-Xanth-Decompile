extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_201575(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+85
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+76
        mov ax,0x26
L1A:
        mov dx,0xf024
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+58
L2B:
        mov ax,mn6A06
        cmp ax,0x45
        jz short $+42
        ja short $+46
        sub al,0x7
        jz short $+8
        sub al,0xc
        jz short $+10
        jmp short $+36
L3F:
        mov ax,0x25
        jmp short $-40
        nop
L45:
        mov ax,0x10e
        push ax
        mov ax,0x22
        push ax
        call far ptr helper_1
        mov sp,bp
        push dx
        push ax
        mov ax,0x23
        jmp short $-63
L5B:
        mov ax,0x24
        jmp short $-68
        nop
L61:
        xor ax,ax
L63:
    }
}
