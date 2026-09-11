extern int __near mn02E8;
extern char __near mb036F;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_325439(int a)
{
    _asm {
        sub sp,0x4
        inc word ptr mn02E8
        cmp word ptr mn02E8,0x5
        jnl short $+91
        mov ax,mn02E8
        dec ax
        jz short $+13
        dec ax
        jz short $+18
        dec ax
        jz short $+23
        dec ax
        jz short $+28
        jmp short $+34
L1F:
        mov word ptr [bp-0x4],0x3b78
        jmp short $+24
        nop
L27:
        mov word ptr [bp-0x4],0x3b88
        jmp short $+16
        nop
L2F:
        mov word ptr [bp-0x4],0x3b96
        jmp short $+8
        nop
L37:
        mov word ptr [bp-0x4],0x3b9e
L3C:
        mov word ptr [bp-0x2],ds
L3F:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0xa
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        mov ax,0x1
        push ax
        mov ax,0x2b
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+44
L67:
        mov ax,0xb
        mov dx,0xf04d
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x1f40
        push ax
        call far ptr helper_2
        add sp,0x2
        mov byte ptr mb036F,0x1
        mov ax,0x22
        push ax
        call far ptr helper_3
L91:
        mov ax,0x1
    }
}
