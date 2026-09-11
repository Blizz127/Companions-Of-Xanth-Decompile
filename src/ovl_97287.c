extern int __near mn02C8;
extern char __near mb1D00;
extern int __near mn02A8;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_97287(void)
{
    _asm {
        inc word ptr mn02C8
        mov ax,mn02C8
        dec ax
        jz short $+12
        dec ax
        dec ax
        jz short $+18
        dec ax
        dec ax
        jz short $+24
        jmp short $+43
L14:
        mov ax,0x5a03
        push ax
        mov ax,0x166
        jmp short $+25
        nop
L1E:
        mov ax,0x5a03
        push ax
        mov ax,0x167
        jmp short $+15
        nop
L28:
        mov byte ptr mb1D00,0x0
        mov ax,0x5a03
        push ax
        mov ax,0x168
L34:
        push ax
        call far ptr helper_0
        add sp,0x4
L3D:
        cmp word ptr mn02C8,0x5
        jnl short $+20
        mov ax,0x1
        push ax
        mov ax,0x1e
        push ax
        call far ptr helper_1
        add sp,0x4
        jmp short $+20
L56:
        mov word ptr mn02A8,0x13
        mov ax,0x5a
        push ax
        call far ptr helper_2
        add sp,0x2
L68:
        mov ax,0x1
        retf
    }
}
