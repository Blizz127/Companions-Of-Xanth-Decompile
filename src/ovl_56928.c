extern char __near mb6E5C;
void far helper_0(void);
void far helper_1(void);
int far ovl_56928(void)
{
    _asm {
        cmp byte ptr mb6E5C,0x0
        jz short $+19
        mov al,mb6E5C
        sub ah,ah
        push ax
        call far ptr helper_0
        add sp,0x2
        jmp short $+18
        nop
L18:
        xor ax,ax
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
L27:
        mov ax,0x1
        retf
    }
}
