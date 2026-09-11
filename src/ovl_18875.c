extern char __near mb6D28;
extern int __near mn5D98;
extern int __near mn5D9A;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_18875(void)
{
    _asm {
        mov ax,0x1
        push ax
        call far ptr helper_0
        add sp,0x2
        call far ptr helper_1
        push dx
        push ax
        call far ptr helper_2
        add sp,0x4
        mov byte ptr mb6D28,0x0
        mov word ptr mn5D98,0x6d28
        mov word ptr mn5D9A,ds
        retf
    }
}
