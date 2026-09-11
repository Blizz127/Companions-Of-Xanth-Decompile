void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_313628(int a)
{
    _asm {
        push word ptr [bp+0x6]
        mov ax,0x3
        push ax
        call far ptr helper_0
        mov sp,bp
        push dx
        push ax
        mov ax,0x3
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x4
        or ax,ax
        jz short $+8
        mov ax,0x3a15
        jmp short $+6
        nop
L29:
        mov ax,0x3a1f
L2C:
        push ds
        push ax
        mov ax,0x4
        mov dx,0xf049
        push dx
        push ax
        call far ptr helper_2
    }
}
