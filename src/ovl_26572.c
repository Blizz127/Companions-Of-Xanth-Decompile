extern char __near mb18A3;
extern char __near mb18A2;
extern int __near mn0286;
extern int __near mn0284;
extern int __near mn028A;
extern int __near mn0288;
void far helper_0(void);
void far helper_1(void);
int far ovl_26572(void)
{
    _asm {
        cmp byte ptr mb18A3,0x0
        jz short $+21
        cmp byte ptr mb18A2,0x0
        jz short $+14
        mov ax,0x3
        push ax
        call far ptr helper_0
        add sp,0x2
L1A:
        cmp byte ptr mb18A2,0x0
        jz short $+13
        push word ptr mn0286
        push word ptr mn0284
        jmp short $+11
        nop
L2C:
        push word ptr mn028A
        push word ptr mn0288
L34:
        call far ptr helper_1
        add sp,0x4
        mov ax,0xffff
        retf
    }
}
