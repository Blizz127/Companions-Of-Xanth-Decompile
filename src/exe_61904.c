extern int __near mn69F8;
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
void far helper_10(void);
void far helper_11(void);
void far helper_12(void);
void far helper_13(void);
void far helper_14(void);
int far exe_61904(int a)
{
    _asm {
        sub sp,0x16
        mov ax,0xa
        push ax
        call far ptr helper_0
        add sp,0x2
        mov ax,0xffff
        push ax
        mov ax,0xf
        push ax
        call far ptr helper_1
        add sp,0x4
        xor ax,ax
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x7f4
        push ds
        push ax
        call far ptr helper_3
        add sp,0x4
        mov [bp-0x16],ax
        add ax,[bp+0x6]
        add ax,0xa
        cmp ax,0x13f
        jnl short $+8
        add word ptr [bp+0x6],0x5
        jmp short $+11
L4B:
        mov ax,[bp-0x16]
        add ax,0x2
        sub [bp+0x6],ax
L54:
        cmp word ptr [bp+0x8],0x6
        jnl short $+9
        add word ptr [bp+0x6],0x2
        jmp short $+27
        nop
L61:
        mov ax,[bp+0x8]
        add ax,mn69F8
        cmp ax,0xc7
        jl short $+10
        mov ax,mn69F8
        sub [bp+0x8],ax
        jmp short $+6
L75:
        sub word ptr [bp+0x8],0x4
L79:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_4
        add sp,0x4
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_5
        add sp,0x4
        push word ptr mn69F8
        push word ptr [bp-0x16]
        xor ax,ax
        push ax
        push ax
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_6
        add sp,0xc
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_7
        add sp,0x4
        call far ptr helper_8
        mov ax,0x7f4
        push ds
        push ax
        call far ptr helper_9
        add sp,0x4
        call far ptr helper_10
        mov ax,0x15e
        push ax
        call far ptr helper_11
        add sp,0x2
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_12
        add sp,0x4
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_13
        add sp,0x4
        call far ptr helper_14
        mov ax,0xffff
        push ax
        call far ptr helper_2
    }
}
