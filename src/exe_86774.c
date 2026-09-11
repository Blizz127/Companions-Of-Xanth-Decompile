extern int __near mn42E4;
extern int __near mn42E2;
void far helper_0(void);
void far helper_1(void);
int far exe_86774(void)
{
    _asm {
        xor ax,ax
        push ax
        call far ptr helper_0
        add sp,0x2
        push word ptr mn42E4
        push word ptr mn42E2
        call far ptr helper_1
        add sp,0x4
        sub ax,ax
        mov mn42E4,ax
        mov mn42E2,ax
        retf
    }
}
