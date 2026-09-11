extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_325222(int a)
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
        mov ax,0x4
L1A:
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+46
L2B:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+29
        nop
L3B:
        mov ax,0x3
        jmp short $-36
        nop
L41:
        xor ax,ax
        push ax
        mov ax,0x1f2
        push ax
        push word ptr mn6A06
        call far ptr helper_1
        mov sp,bp
        jmp short $+4
L55:
        xor ax,ax
L57:
    }
}
