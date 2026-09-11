extern int __near mn6A06;
void far helper_0(void);
int far ovl_254862(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+9
        dec ax
        dec ax
        jz short $+33
        jmp short $+59
        nop
L0F:
        mov ax,mn6A06
        sub ax,0x38
        jnz short $+50
        mov ax,0x21
L1A:
        mov dx,0xf027
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+32
L2B:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+15
        nop
L3B:
        mov ax,0x1f
        jmp short $-36
        nop
L41:
        mov ax,0x20
        jmp short $-42
        nop
L47:
        xor ax,ax
L49:
    }
}
