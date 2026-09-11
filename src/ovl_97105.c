extern int __near mn02A2;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
int far ovl_97105(int a)
{
    _asm {
        sub sp,0x4
        mov ax,mn02A2
        or ax,ax
        jz short $+13
        dec ax
        jz short $+18
        dec ax
        jz short $+23
        dec ax
        jz short $+28
        jmp short $+36
L15:
        mov word ptr [bp-0x4],0x29
        jmp short $+24
        nop
L1D:
        mov word ptr [bp-0x4],0x2a
        jmp short $+16
        nop
L25:
        mov word ptr [bp-0x4],0x2b
        jmp short $+8
        nop
L2D:
        mov word ptr [bp-0x4],0x2c
L32:
        mov word ptr [bp-0x2],0xf016
L37:
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        mov ax,0x23cc
        push ds
        push ax
        call far ptr helper_0
        add sp,0x8
        inc word ptr mn02A2
        cmp word ptr mn02A2,0x3
        jng short $+76
        mov ax,0xe
        push ax
        mov ax,0x5d
        push ax
        call far ptr helper_1
        add sp,0x4
        call far ptr helper_2
        mov ax,0x3e8
        push ax
        call far ptr helper_3
        add sp,0x2
        mov ax,0x2d
        mov dx,0xf016
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,0x12
        push ax
        mov ax,0x5d
        push ax
        call far ptr helper_4
        add sp,0x4
        mov ax,0x1
        push ax
        mov ax,0x1e
        jmp short $+9
L9F:
        mov ax,0x1
        push ax
        mov ax,0x5
LA6:
        push ax
        call far ptr helper_5
        mov ax,0x1
    }
}
