void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
void far helper_8(void);
int far exe_60923(int a)
{
    _asm {
        sub sp,0x2
        call far ptr helper_0
        call far ptr helper_1
        mov ax,0x1
        push ax
        call far ptr helper_2
        add sp,0x2
        mov ax,0x20
        mov cx,0x2199
        push cx
        push ax
        call far ptr helper_3
        add sp,0x4
        mov ax,0xc7
        push ax
        mov ax,0x13f
        push ax
        xor ax,ax
        push ax
        push ax
        call far ptr helper_4
        add sp,0x8
        cmp word ptr [bp+0x6],0x0
        jl short $+22
        push ax
        call far ptr helper_5
        add sp,0x2
        push word ptr [bp+0x6]
        call far ptr helper_6
        add sp,0x2
L57:
        mov ax,0xffff
        push ax
        call far ptr helper_7
        add sp,0x2
        cmp word ptr [bp+0x6],0x0
        jl short $+13
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_8
L74:
    }
}
