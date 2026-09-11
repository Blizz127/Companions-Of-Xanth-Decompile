void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
void far helper_7(void);
int far exe_50057(int a)
{
    _asm {
        sub sp,0x8
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x2
        mov [bp-0x4],ax
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x2
        mov [bp-0x2],ax
        push ax
        push word ptr [bp-0x4]
        call far ptr helper_2
        add sp,0x4
        mov [bp-0x6],ax
        cmp ax,[bp+0x6]
        jnz short $+28
        push ax
        call far ptr helper_3
        add sp,0x2
        push ax
        push word ptr [bp-0x2]
        push word ptr [bp-0x4]
        call far ptr helper_4
        add sp,0x6
        jmp short $+55
L4D:
        or ax,ax
        jz short $+51
L51:
        push word ptr [bp-0x6]
        call far ptr helper_3
        add sp,0x2
        cmp ax,[bp+0x6]
        jz short $+12
        mov [bp-0x6],ax
        or ax,ax
        jnz short $-21
        jmp short $+26
        nop
L6B:
        push word ptr [bp+0x6]
        call far ptr helper_3
        add sp,0x2
        push ax
        push word ptr [bp-0x6]
        call far ptr helper_5
        add sp,0x4
L82:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_6
        add sp,0x4
        push word ptr [bp+0xa]
        push word ptr [bp+0x6]
        call far ptr helper_7
        add sp,0x4
        cmp word ptr [bp+0x8],0x0
        jz short $+47
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        call far ptr helper_2
        add sp,0x4
        mov [bp-0x6],ax
        push word ptr [bp+0x6]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        call far ptr helper_4
        add sp,0x6
        push word ptr [bp-0x6]
        push word ptr [bp+0x6]
        call far ptr helper_5
LD1:
    }
}
