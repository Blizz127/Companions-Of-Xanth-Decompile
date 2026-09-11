extern char __near mb416E;
extern char __near mb4190;
extern int __near mn4190;
extern int __near mn4194;
extern int __near mn4192;
extern int __near mn0256;
void far helper_0(void);
void far helper_1(void);
int far ovl_11802(int a)
{
    _asm {
        sub sp,0x2
        test byte ptr mb416E,0x6
        jnz short $+27
        test byte ptr mb4190,0x6
        jz short $+12
        mov ax,mn4190
        and al,0xf7
        mov [bp-0x2],ax
        jmp short $+15
L1B:
        mov word ptr [bp-0x2],0x1
        jmp short $+8
        nop
L23:
        mov word ptr [bp-0x2],0x0
L28:
        push word ptr mn4194
        push word ptr mn4192
        mov al,mb416E
        and ax,0x8
        or ax,[bp-0x2]
        push ax
        call far ptr helper_0
        add sp,0x6
        push word ptr mn0256
        call far ptr helper_1
    }
}
