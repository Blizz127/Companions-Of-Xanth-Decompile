void far helper_0(void);
void far helper_1(void);
int far ovl_8624(int a)
{
    _asm {
        sub sp,0x6
        lea ax,[bp-0x4]
        push ss
        push ax
        call far ptr helper_0
        add sp,0x4
        mov ax,[bp-0x4]
        mov [bp-0x6],ax
        dec ax
        jnz short $+5
        inc word ptr [bp-0x6]
L1C:
        push word ptr [bp-0x6]
        call far ptr helper_1
    }
}
