void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_36592(int a)
{
    _asm {
        sub sp,0x4
        lea ax,[bp-0x4]
        push ss
        push ax
        lea ax,[bp-0x2]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0xc
        or ax,ax
        jz short $+42
        call far ptr helper_1
        mov ax,0x10
        push ax
        mov ax,0xfe
        push ax
        mov ax,0x14
        push ax
        mov ax,0x18
        push ax
        push word ptr [bp-0x4]
        push word ptr [bp-0x2]
        call far ptr helper_2
        add sp,0xc
        call far ptr helper_3
L47:
    }
}
