extern int __near mn4DA8;
extern int __near mn4DA6;
extern int __near mn4DAC;
extern int __near mn4DAA;
void far helper_0(void);
void far helper_1(void);
int far exe_96581(void)
{
    _asm {
        push word ptr mn4DA8
        push word ptr mn4DA6
        xor ax,ax
        push ax
        push word ptr mn4DAC
        push word ptr mn4DAA
        call far ptr helper_0
        add sp,0xa
        mov ax,mn4DAC
        or ax,mn4DAA
        jz short $+18
        push word ptr mn4DAC
        push word ptr mn4DAA
        call far ptr helper_1
        add sp,0x4
L34:
        sub ax,ax
        mov mn4DAC,ax
        mov mn4DAA,ax
        mov mn4DA8,ax
        mov mn4DA6,ax
        retf
    }
}
