extern int __near mn4EA0;
void far helper_0(void);
void far helper_1(void);
int far exe_99815(void)
{
    _asm {
        mov word ptr mn4EA0,0x1
        call far ptr helper_0
        push ax
        call far ptr helper_1
        add sp,0x2
        mov word ptr mn4EA0,0x0
        retf
    }
}
