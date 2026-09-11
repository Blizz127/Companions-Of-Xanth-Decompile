extern char __near mb030C;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far ovl_118731(void)
{
    _asm {
        mov byte ptr mb030C,0x1
        cmp word ptr mn0256,0x80
        jz short $+5
        jmp L90
L10:
        xor ax,ax
        push ax
        push word ptr mn0256
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x6
        mov ax,0xb
        push ax
        call far ptr helper_1
        add sp,0x2
        mov ax,0x1388
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x5a0b
        push ax
        mov ax,0x281
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0x73
        push ax
        call far ptr helper_4
        add sp,0x2
        cmp ax,0x12d
        jnz short $+54
        mov ax,0xa
        push ax
        mov ax,0x80
        push ax
        call far ptr helper_5
        add sp,0x4
        or ax,ax
        jnz short $+34
        mov ax,0xa
        push ax
        mov ax,0x80
        push ax
        call far ptr helper_6
        add sp,0x4
        xor ax,ax
        push ax
        push ax
        mov ax,0x9
        push ax
        call far ptr helper_7
        add sp,0x6
L90:
        xor ax,ax
        retf
    }
}
