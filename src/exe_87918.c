extern int __near mn634E;
extern int __near mn42EC;
extern int __near mn42EE;
void far helper_0(void);
void far helper_1(void);
int far exe_87918(int a)
{
    _asm {
        test byte ptr [bp+0x6],0x80
        jz short $+17
        mov ax,0xa
        push ax
        push word ptr mn634E
        mov ax,0x1
        push ax
        jmp short $+15
        nop
L15:
        push word ptr mn42EC
        push word ptr mn634E
        push word ptr mn42EE
L21:
        call far ptr helper_0
        push word ptr [bp+0x8]
        push word ptr [bp+0xa]
        push word ptr [bp+0xc]
        push word ptr [bp+0xe]
        push word ptr [bp+0x6]
        call far ptr helper_1
    }
}
