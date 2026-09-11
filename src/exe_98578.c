extern int __near mn4F20;
extern int __near mn4F22;
extern int __near mn4F24;
extern int __near mn4F26;
void far helper_0(void);
void far helper_1(void);
int far exe_98578(int a)
{
    _asm {
        call far ptr helper_0
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+30
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov mn4F20,ax
        mov mn4F22,dx
        mov ax,[bp+0xa]
        mov mn4F24,ax
        mov ax,[bp+0xc]
        mov mn4F26,ax
        jmp short $+25
        nop
L29:
        mov word ptr mn4F20,0x4ee0
        mov word ptr mn4F22,ds
        mov word ptr mn4F24,0x1
        mov word ptr mn4F26,0x0
L3F:
        call far ptr helper_1
    }
}
