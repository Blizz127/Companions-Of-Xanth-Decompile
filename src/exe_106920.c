void far helper_0(void);
int far exe_106920(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+49
        cmp word ptr [bp+0xa],0x0
        jng short $+43
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x6],ax
        mov [bp-0x4],dx
        mov ax,[bp+0xa]
        mov [bp-0x8],ax
L23:
        push word ptr [bp-0x4]
        push word ptr [bp-0x6]
        call far ptr helper_0
        add sp,0x4
        add word ptr [bp-0x6],0x14
        dec word ptr [bp-0x8]
        jnz short $-21
L3A:
    }
}
