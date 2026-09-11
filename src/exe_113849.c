
int far exe_113849(int a)
{
    _asm {
        sub sp,0x8
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
        mov [bp-0x4],ax
        mov [bp-0x2],dx
        mov ax,[bp+0xc]
        mov dx,[bp+0xe]
        mov [bp-0x8],ax
        mov [bp-0x6],dx
        mov es,dx
        mov bx,ax
        cmp byte ptr es:[bx],0x0
        jz short $+35
L25:
        dec word ptr [bp+0xa]
        cmp word ptr [bp+0xa],0x0
        jng short $+26
        inc word ptr [bp-0x8]
        mov al,es:[bx]
        les bx, [bp-0x4]
        inc word ptr [bp-0x4]
        mov es:[bx],al
        les bx, [bp-0x8]
        cmp byte ptr es:[bx],0x0
        jnz short $-31
L46:
        les bx, [bp-0x4]
        mov byte ptr es:[bx],0x0
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
    }
}
