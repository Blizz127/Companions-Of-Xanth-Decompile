void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
void far helper_4(void);
void far helper_5(void);
void far helper_6(void);
int far exe_121013(int a)
{
    _asm {
        sub sp,0x202
        call far ptr helper_0
        lea ax,[bp+0xa]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        lea ax,[bp-0x202]
        push ss
        push ax
        call far ptr helper_1
        add sp,0xc
        lea ax,[bp-0x202]
        push ss
        push ax
        mov ax,0xffff
        push ax
        push ax
        call far ptr helper_2
        add sp,0x8
        mov word ptr [bp-0x2],0x0
L3A:
        call far ptr helper_3
        or ax,ax
        jnz short $+25
        call far ptr helper_4
        or ax,ax
        jz short $+10
        call far ptr helper_5
        mov [bp-0x2],ax
L54:
        cmp word ptr [bp-0x2],0x0
        jz short $-30
L5A:
        call far ptr helper_6
        mov ax,[bp-0x2]
    }
}
