void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_104076(int a)
{
    _asm {
        sub sp,0x14
        mov byte ptr [bp-0x14],0x0
        push word ptr [bp+0xc]
        push word ptr [bp+0xa]
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_0
        add sp,0x8
        or ax,ax
        jz short $+34
        lea ax,[bp-0x14]
        push ss
        push ax
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_1
        add sp,0x8
        lea ax,[bp-0x14]
        push ss
        push ax
        call far ptr helper_2
        mov ax,0x1
L3E:
    }
}
