void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far ovl_195812(void)
{
    _asm {
        mov ax,0xe
        push ax
        mov ax,0x12
        push ax
        call far ptr helper_0
        add sp,0x4
        push dx
        push ax
        mov ax,0x3103
        push ds
        push ax
        call far ptr helper_1
        add sp,0x8
        mov ax,0x1
        push ax
        mov ax,0x100
        push ax
        call far ptr helper_2
        add sp,0x4
        or ax,ax
        jnz short $+27
        mov ax,0x54
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        mov ax,0x1
        jmp short $+22
        nop
L4C:
        mov ax,0x55
        mov dx,0xf021
        push dx
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
L5F:
        push ax
        mov ax,0x100
        push ax
        call far ptr helper_3
        add sp,0x6
        mov ax,0x2
        push ax
        mov ax,0x1c
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x1
        retf
    }
}
