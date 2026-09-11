extern int __near mn0290;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_94469(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xbb8
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,mn0290
        sub ax,0x5
        jz short $+8
        dec ax
        jz short $+15
        jmp short $+29
        nop
L26:
        mov ax,0x5a03
        push ax
        mov ax,0x13f
        jmp short $+10
        nop
L30:
        mov ax,0x5a01
        push ax
        mov ax,0x2e1
L37:
        push ax
        call far ptr helper_2
        add sp,0x4
L40:
        xor ax,ax
        retf
    }
}
