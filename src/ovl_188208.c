extern char __near mb032F;
extern int __near mn02A8;
extern char __near mb032E;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_188208(void)
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
        mov ax,0x9ac
        push ax
        mov ax,0x149
        push ax
        call far ptr helper_2
        add sp,0x4
        cmp byte ptr mb032F,0x0
        jz short $+20
        mov word ptr mn02A8,0xb
        mov ax,0x5a
        push ax
        call far ptr helper_3
        add sp,0x2
L41:
        mov ax,0x1
        mov mb032E,al
        retf
    }
}
