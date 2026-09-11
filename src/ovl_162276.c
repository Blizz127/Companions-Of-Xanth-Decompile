extern int __near mn6A06;
extern int __near mn6A04;
extern int __near mn6A02;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_162276(int a)
{
    _asm {
        mov ax,[bp+0x6]
        sub ax,0x4
        jz short $+13
        dec ax
        dec ax
        jnz short $+5
        jmp LAD
L0F:
        jmp LC9
        nop
L13:
        mov ax,mn6A06
        cmp ax,0x41
        jz short $+40
        jna short $+5
        jmp LC9
L20:
        sub al,0x19
        jz short $+9
        sub al,0x1f
        jz short $+27
        jmp LC9
L2B:
        mov ax,0x5a08
        push ax
        mov ax,0x222
        push ax
        call far ptr helper_0
L38:
        mov sp,bp
L3A:
        mov ax,0x1
        jmp LCB
        nop
L41:
        cmp word ptr mn6A04,0xfa
        jnz short $+24
        push word ptr mn6A02
        push word ptr mn6A04
        mov ax,0x19
        push ax
        call far ptr helper_1
        mov sp,bp
        jmp short $+111
        nop
L5F:
        cmp word ptr mn6A04,0x4d
        jnz short $+101
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_2
        mov sp,bp
        or ax,ax
        jz short $+18
        mov ax,0x3b
L7C:
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_3
        jmp short $-78
        nop
L89:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_4
        add sp,0x4
        push dx
        push ax
        mov ax,0x3c
        mov dx,0xf006
        push dx
        push ax
        call far ptr helper_3
        add sp,0x8
        jmp short $-113
LAD:
        mov ax,mn6A06
        sub ax,0x13
        jz short $+10
        sub ax,0x32
        jz short $+11
        jmp short $+15
        nop
LBD:
        mov ax,0x39
        jmp short $-68
        nop
LC3:
        mov ax,0x3a
        jmp short $-74
        nop
LC9:
        xor ax,ax
LCB:
    }
}
