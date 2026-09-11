extern int __near mn189E;
extern int __near mn189C;
extern int __near mn18A0;
extern char __near mb18A3;
extern char __near mb18A2;
void far helper_0(void);
int far ovl_14681(void)
{
    _asm {
        mov ax,mn189E
        or ax,mn189C
        jz short $+26
        push word ptr mn189E
        push word ptr mn189C
        call far ptr helper_0
        add sp,0x4
        sub ax,ax
        mov mn189E,ax
        mov mn189C,ax
L21:
        xor al,al
        mov word ptr mn18A0,0x0
        mov mb18A3,al
        mov mb18A2,al
        retf
    }
}
