extern int __near mn07EC;
extern int __near mn07EE;
extern int __near mn07F0;
extern int __near mn07F2;
void far helper_0(void);
int far exe_61795(int a)
{
    _asm {
        sub sp,0x4
        call far ptr helper_0
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        sub ax,mn07EC
        sbb dx,mn07EE
        or dx,dx
        jl short $+21
        jg short $+7
        cmp ax,0xfa
        jna short $+14
L21:
        add word ptr mn07F0,0x32
        adc word ptr mn07F2,0x0
        jmp short $+24
L2D:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        sub ax,mn07EC
        sbb dx,mn07EE
        add mn07F0,ax
        adc mn07F2,dx
L43:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        mov mn07EC,ax
        mov mn07EE,dx
        mov ax,mn07F0
        mov dx,mn07F2
    }
}
