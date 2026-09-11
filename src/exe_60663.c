extern int __near mn0258;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_60663(int a)
{
    _asm {
        sub sp,0x2
        xor ax,ax
        push ax
        push word ptr mn0258
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x6
        cmp ax,0x2
        jnz short $+5
        jmp LA3
L1D:
        xor ax,ax
        push ax
        push word ptr mn0258
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x6
        push word ptr [bp+0x6]
        call far ptr helper_2
        add sp,0x2
        mov [bp-0x2],ax
        or ax,ax
        jz short $+34
        xor ax,ax
        push ax
        mov cx,0x1
        push cx
        push word ptr [bp-0x2]
        call far ptr helper_3
        add sp,0x6
        xor ax,ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_4
        add sp,0x4
L61:
        mov ax,0x5
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_5
        add sp,0x4
        mov ax,0x7
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_6
        add sp,0x4
        mov ax,0xc
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_5
        add sp,0x4
        mov ax,0x6
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_5
        add sp,0x4
        mov ax,0x1
        jmp short $+5
        nop
LA3:
        xor ax,ax
LA5:
    }
}
