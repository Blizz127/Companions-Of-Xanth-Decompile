
int far exe_99067(int a)
{
    _asm {
        sub sp,0x14
        mov ax,0x140
        mul word ptr [bp+0xc]
        add ax,[bp+0xa]
        sub dx,dx
        sub ax,dx
        sbb dx,0x6000
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov word ptr [bp-0xe],0x10
        jmp short $+71
L21:
        mov ax,[bp-0x4]
        mov dx,[bp-0x2]
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0xc],ax
        mov [bp-0xa],dx
        mov word ptr [bp-0x10],0x10
        jmp short $+21
        nop
L41:
        les bx, [bp-0x8]
        inc word ptr [bp-0x8]
        mov al,es:[bx]
        les bx, [bp-0xc]
        inc word ptr [bp-0xc]
        mov es:[bx],al
L53:
        mov ax,[bp-0x10]
        dec word ptr [bp-0x10]
        or ax,ax
        jnz short $-26
        add word ptr [bp-0x4],0x140
        add word ptr [bp+0x6],0x10
L66:
        mov ax,[bp-0xe]
        dec word ptr [bp-0xe]
        or ax,ax
        jnz short $-77
    }
}
