extern char __near mb1D00;
extern int __near mn02A8;
extern char __near mb0783;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_265038(void)
{
    _asm {
        mov ax,0xb
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_1
        add sp,0x2
        mov byte ptr mb1D00,0x0
        mov ax,0xe19
        push ax
        mov ax,0x35f
        push ax
        call far ptr helper_2
        add sp,0x4
        call far ptr helper_3
        cmp word ptr mn02A8,0x16
        jnz short $+19
        mov byte ptr mb0783,0x1
        mov ax,0x5a
        push ax
        call far ptr helper_4
        jmp short $+12
        nop
L4A:
        mov ax,0x10
        push ax
        call far ptr helper_5
L53:
        add sp,0x2
        xor ax,ax
        retf
    }
}
