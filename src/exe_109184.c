void far helper_0(void);
int far exe_109184(int a)
{
    _asm {
        sub sp,0x4
        mov ax,0x14
        imul word ptr [bp+0x8]
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        les bx, [bx+0x67c2]
        add bx,ax
        mov [bp-0x4],bx
        mov word ptr [bp-0x2],es
        mov al,[bp+0xa]
        mov es:[bx],al
        mov al,[bp+0xc]
        les bx, [bp-0x4]
        mov es:[bx+0x1],al
        mov ax,[bp+0xa]
        sub ax,0x3
        jz short $+7
        sub ax,0x4
        jnz short $+12
L39:
        mov ax,[bp+0xe]
        les bx, [bp-0x4]
        mov es:[bx+0xa],ax
L43:
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
    }
}
