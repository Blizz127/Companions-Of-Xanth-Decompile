void far helper_0(void);
int far exe_36670(int a)
{
    _asm {
        sub sp,0x8
        cmp word ptr [bp+0x8],0x0
        jz short $+87
        mov word ptr [bp-0x4],0x0
        cmp word ptr [bp+0x10],0x0
        jng short $+76
        mov ax,[bp+0xe]
        add ax,ax
        add ax,ax
        add ax,[bp+0xa]
        mov dx,[bp+0xc]
        add ax,0x2
        mov [bp-0x8],ax
        mov [bp-0x6],dx
L2A:
        les bx, [bp-0x8]
        mov ax,es:[bx]
        mov [bp-0x2],ax
        or ax,ax
        jz short $+41
        mov ax,[bp+0x8]
        cmp [bp-0x2],ax
        jz short $+20
        add word ptr [bp-0x8],0x4
        mov ax,[bp+0x10]
        inc word ptr [bp-0x4]
        cmp [bp-0x4],ax
        jl short $-34
        jmp short $+16
        nop
L51:
        mov ax,[bp-0x4]
        inc ax
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_0
L5E:
    }
}
