extern char __near mb1D00;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_32197(int a)
{
    _asm {
        mov ax,[bp+0x8]
        or ax,ax
        jz short $+14
        dec ax
        jz short $+41
        dec ax
        jz short $+56
        dec ax
        jz short $+61
        jmp short $+64
        nop
L13:
        mov ax,0x10
        push ax
        call far ptr helper_0
        mov ax,0x2
        mov sp,bp
        push ax
        call far ptr helper_1
        mov sp,bp
        mov byte ptr mb1D00,0x0
        jmp short $+34
        nop
L31:
        mov ax,0x10
        push ax
        call far ptr helper_0
        mov sp,bp
        call far ptr helper_2
        jmp short $+15
L43:
        call far ptr helper_3
        jmp short $+8
        nop
L4B:
        call far ptr helper_4
L50:
    }
}
