extern int __near mn69FE;
extern int __near mn0256;
extern int __near mn6A04;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
void far helper_9(void);
int far ovl_58237(int a)
{
    _asm {
        sub sp,0x2
        mov word ptr [bp-0x2],0x0
        cmp word ptr mn69FE,0x1
        jnz short $+86
        mov ax,mn0256
        cmp mn6A04,ax
        jnz short $+47
        mov ax,0x15
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+27
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xb
        jmp L1B8
        nop
L45:
        mov ax,0x1d81
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0x1d85
        push ds
        jmp L1BC
L63:
        cmp word ptr mn69FE,0x5
        jnz short $+21
        mov ax,0xc
        mov dx,0xf029
        push dx
        push ax
        call far ptr helper_2
L77:
        add sp,0x4
        jmp L1C2
L7D:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+32
        mov ax,0x1d93
        push ds
        push ax
        push word ptr mn6A04
        mov ax,0x52
        push ax
        call far ptr helper_1
        add sp,0x8
        push dx
        push ax
        mov ax,0xd
        jmp L1B8
        nop
LAF:
        mov ax,0xf
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+5
        jmp L1A3
LC6:
        mov ax,0xe
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        mov ax,0x5
        push ax
        push word ptr mn6A04
        call far ptr helper_3
        add sp,0x4
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0x1d97
        push ds
        push ax
        call far ptr helper_2
        add sp,0x8
        mov ax,0x11
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jz short $+76
        mov ax,0xd
        push ax
        push word ptr mn6A04
        call far ptr helper_0
        add sp,0x4
        or ax,ax
        jnz short $+56
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_4
        add sp,0x4
        or ax,ax
        jz short $+36
        mov ax,0x1da2
        push ds
        push ax
        call far ptr helper_2
        add sp,0x4
        mov ax,0x1
        push ax
        push word ptr mn6A04
        call far ptr helper_5
        add sp,0x4
        mov word ptr [bp-0x2],0x1
L163:
        mov ax,0x2e
        push ax
        call far ptr helper_6
        add sp,0x2
        cmp word ptr [bp-0x2],0x0
        jz short $+14
        mov ax,0x1
        push ax
        call far ptr helper_7
        add sp,0x2
L181:
        push word ptr mn6A04
        call far ptr helper_8
        add sp,0x2
        cmp ax,0x2c
        jnz short $+50
        mov ax,0x8
        push ax
        push word ptr mn6A04
        call far ptr helper_9
        jmp L77
        nop
L1A3:
        push word ptr mn6A04
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0x4
        push dx
        push ax
        mov ax,0xe
L1B8:
        mov dx,0xf029
        push dx
L1BC:
        push ax
        call far ptr helper_2
L1C2:
        mov ax,0x1
    }
}
