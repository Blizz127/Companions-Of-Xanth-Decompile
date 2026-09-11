extern int __near mn02E0;
extern char __near mb378A;
void far helper_0(void);
void far helper_1(void);
int far ovl_288974(int a)
{
    _asm {
        sub sp,0x4
        inc word ptr mn02E0
        cmp word ptr mn02E0,0x4
        jl short $+11
        mov ax,0x16
        mov dx,0xf02e
        jmp short $+8
        nop
L17:
        mov ax,0x37df
        mov dx,ds
L1C:
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        push dx
        push ax
        mov ax,0x15
        mov dx,0xf02e
        push dx
        push ax
        call far ptr helper_0
        add sp,0x8
        cmp word ptr mn02E0,0x4
        jnl short $+12
        mov ax,0x2
        push ax
        mov ax,0x26
        jmp short $+10
        nop
L45:
        mov ax,0x2
        push ax
        mov ax,0x27
L4C:
        push ax
        call far ptr helper_1
        mov byte ptr mb378A,0x0
        mov ax,0x1
    }
}
