void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_110357(int a)
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
        cmp byte ptr es:[bx],0x5
        jnz short $+89
        les bx, es:[bx+0xa]
        cmp byte ptr es:[bx],0x0
        jz short $+79
        les bx, [bp-0x4]
        or byte ptr es:[bx+0x1],0x80
        call far ptr helper_0
        mov ax,0xa
        push ax
        call far ptr helper_1
        add sp,0x2
        les bx, [bp-0x4]
        mov ax,es:[bx+0x8]
        sub ax,0x2
        push ax
        mov ax,es:[bx+0x6]
        sub ax,0x3
        push ax
        mov ax,es:[bx+0x4]
        add ax,0x2
        push ax
        mov ax,es:[bx+0x2]
        add ax,0x3
        push ax
        mov ax,0x82
        push ax
        call far ptr helper_2
        add sp,0xa
        call far ptr helper_3
L79:
    }
}
