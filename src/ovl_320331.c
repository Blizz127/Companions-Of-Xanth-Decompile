void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far ovl_320331(void)
{
    _asm {
        mov ax,0x32
        push ax
        call far ptr helper_0
        add sp,0x2
        or ax,ax
        jz short $+8
        mov ax,0x3aad
        jmp short $+6
        nop
L16:
        mov ax,0x3ab8
L19:
        push ds
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
        mov cx,0x4
        cwd
        idiv cx
        add dx,0x2
        push dx
        mov ax,0x29
        push ax
        call far ptr helper_3
        add sp,0x4
        xor ax,ax
        retf
    }
}
