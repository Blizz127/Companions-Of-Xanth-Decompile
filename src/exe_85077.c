void far helper_0(void);
void far helper_1(void);
int far exe_85077(int a)
{
    _asm {
        sub sp,0x6
        mov word ptr [bp-0x2],0x0
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_0
        add sp,0x4
        mov es,dx
        mov bx,ax
        mov [bp+0x6],ax
        mov word ptr [bp+0x8],es
        cmp byte ptr es:[bx],0x0
        jz short $+43
L26:
        mov ax,[bp+0x6]
        mov [bp-0x6],ax
        mov word ptr [bp-0x4],es
        mov bx,[bp-0x6]
        sub ah,ah
        mov al,es:[bx]
        push ax
        call far ptr helper_1
        add sp,0x2
        add [bp-0x2],ax
        inc word ptr [bp+0x6]
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jnz short $-39
L4F:
        mov ax,[bp-0x2]
    }
}
