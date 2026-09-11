void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
int far exe_39464(int a)
{
    _asm {
        sub sp,0xc
        call far ptr helper_0
        add ax,[bp+0x6]
        adc dx,0x0
        mov [bp-0xc],ax
        mov [bp-0xa],dx
        cmp word ptr [bp+0x6],0x0
        jz short $+9
        call far ptr helper_1
        jmp short $+7
L21:
        call far ptr helper_2
L26:
        mov word ptr [bp-0x8],0x0
L2B:
        cmp word ptr [bp+0x6],0x0
        jz short $+19
        call far ptr helper_0
        cmp dx,[bp-0xa]
        jg short $+30
        jl short $+7
        cmp ax,[bp-0xc]
        jnc short $+23
L42:
        lea ax,[bp-0x8]
        push ss
        push ax
        mov ax,0x5
        push ax
        call far ptr helper_3
        add sp,0x6
        or ax,ax
        jz short $-42
L57:
        call far ptr helper_4
        cmp word ptr [bp-0x8],0x1
        jnz short $+7
        mov ax,[bp-0x2]
        jmp short $+4
L67:
        xor ax,ax
L69:
    }
}
