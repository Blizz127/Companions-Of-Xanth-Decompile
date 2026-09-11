void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_1138(int a)
{
    _asm {
        sub sp,0x2
        call far ptr helper_0
        mov [bp-0x2],ax
        call far ptr helper_1
        or ax,ax
        jz short $+31
        call far ptr helper_2
        sub ax,0x3
        jz short $+13
        sub ax,0x18
        jz short $+28
        mov ax,0x20
        jmp short $+26
        nop
L29:
        call far ptr helper_3
        jmp short $+27
        nop
L31:
        cmp word ptr [bp-0x2],0x0
        jz short $+26
        test byte ptr [bp-0x2],0x2
        jz short $+14
L3D:
        mov ax,0x1b
L40:
        push ax
        call far ptr helper_4
        add sp,0x2
L49:
        mov ax,0x1
        jmp short $+5
        nop
L4F:
        xor ax,ax
L51:
    }
}
