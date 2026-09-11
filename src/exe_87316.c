void far helper_0(void);
int far exe_87316(int a)
{
    _asm {
        sub sp,0xe
        mov byte ptr [bp-0xd],0x3
        mov byte ptr [bp-0xb],0x0
        lea ax,[bp-0xe]
        push ss
        push ax
        push ss
        push ax
        mov ax,0x10
        push ax
        call far ptr helper_0
        mov al,[bp-0x7]
        sub ah,ah
        inc ax
        les bx, [bp+0xa]
        mov es:[bx],ax
        mov al,[bp-0x8]
        sub ah,ah
        inc ax
        les bx, [bp+0x6]
        mov sp,bp
        mov es:[bx],ax
    }
}
