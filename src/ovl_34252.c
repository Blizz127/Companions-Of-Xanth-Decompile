extern int __near mn6A10;
extern char __near mb0300;
void far helper_0(void);
void far helper_1(void);
int far ovl_34252(void)
{
    _asm {
        mov ax,0x5
        push ax
        mov ax,0x80
        push ax
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+46
        mov ax,0x80
        push ax
        mov ax,0x1
        push ax
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+14
        mov word ptr mn6A10,0x525
        mov ax,0x11
        jmp short $+42
        nop
L34:
        mov word ptr mn6A10,0x526
        mov ax,0x12
        jmp short $+30
        nop
L40:
        cmp byte ptr mb0300,0x0
        jnz short $+13
        mov word ptr mn6A10,0x527
        mov ax,0x13
        jmp short $+11
L52:
        mov word ptr mn6A10,0x528
        mov ax,0x14
L5B:
        mov dx,0xf035
        retf
    }
}
