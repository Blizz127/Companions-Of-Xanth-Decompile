extern int __near mn6A06;
void far helper_0(void);
void far helper_1(void);
int far ovl_263400(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x6
        jnz short $+89
        mov ax,mn6A06
        cmp ax,0x13
        jz short $+49
        ja short $+9
        sub ax,0x8
        jz short $+22
        jmp short $+72
L19:
        sub ax,0x2c
        jz short $+41
        sub ax,0x18
        jc short $+62
        sub ax,0x1
        jna short $+37
        jmp short $+55
        nop
L2B:
        mov ax,0x3b
L2E:
        mov dx,0xf028
        push dx
        push ax
        call far ptr helper_0
        mov sp,bp
        mov ax,0x1
        jmp short $+36
L3F:
        mov ax,0x39
        jmp short $-20
        nop
L45:
        mov ax,0x3a
        jmp short $-26
        nop
L4B:
        xor ax,ax
        push ax
        mov ax,0x13f
        push ax
        push word ptr mn6A06
        call far ptr helper_1
        mov sp,bp
        jmp short $+4
L5F:
        xor ax,ax
L61:
    }
}
