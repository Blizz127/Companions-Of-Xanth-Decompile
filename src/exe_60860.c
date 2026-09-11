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
int far exe_60860(int a)
{
    _asm {
        call far ptr helper_0
        jmp short $+11
L07:
        dec ax
        jz short $+23
        dec ax
        jz short $+34
        dec ax
        jz short $+39
L10:
        call far ptr helper_1
        dec ax
        jnz short $-15
        call far ptr helper_2
        jmp short $-13
L1F:
        mov ax,0x2
        push ax
        call far ptr helper_3
        add sp,0x2
        jmp short $-27
L2D:
        call far ptr helper_4
        jmp short $-34
        nop
L35:
        call far ptr helper_5
        jmp short $-42
        push bp
        mov bp,sp
        sub sp,0x2
        call far ptr helper_6
        call far ptr helper_7
        mov ax,0x1
        push ax
        call far ptr helper_8
        add sp,0x2
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_9
        add sp,0x4
        mov ax,0xc7
        push ax
        mov ax,0x13f
        push ax
        xor ax,ax
        push ax
        push ax
        call far ptr helper_10
        add sp,0x8
        cmp word ptr [bp+0x6],0x0
        jl short $+22
        push ax
        call far ptr helper_11
        add sp,0x2
        push word ptr [bp+0x6]
        call far ptr helper_12
        add sp,0x2
L96:
        mov ax,0xffff
        push ax
        call far ptr helper_13
        add sp,0x2
        cmp word ptr [bp+0x6],0x0
        jl short $+13
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_14
LB3:
    }
}
