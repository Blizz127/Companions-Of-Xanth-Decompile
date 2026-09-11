void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far ovl_1081(int a)
{
    _asm {
        sub sp,0x2
        push word ptr [bp+0x6]
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        call far ptr helper_0
        add sp,0x4
        sub ax,0x140
        neg ax
        cwd
        sub ax,dx
        sar ax,1
        push ax
        call far ptr helper_1
        add sp,0x4
        push word ptr [bp+0xa]
        push word ptr [bp+0x8]
        call far ptr helper_2
    }
}
