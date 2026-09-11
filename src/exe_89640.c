void far helper_0(void);
int far exe_89640(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x4336
        push ds
        push ax
        call far ptr helper_0
        add sp,0x4
        mov word ptr [bp-0x4],0x434a
L15:
        mov bx,[bp-0x4]
        mov word ptr [bx],0xffff
        mov ax,[bp-0x4]
        add ax,0x2
        push ds
        push ax
        call far ptr helper_0
        mov bx,[bp-0x4]
        add sp,0x4
        mov word ptr [bx+0x16],0x0
        add word ptr [bp-0x4],0x18
        cmp word ptr [bp-0x4],0x449a
        jc short $-40
    }
}
