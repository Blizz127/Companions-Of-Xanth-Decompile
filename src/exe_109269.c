extern int __near mn67FC;
extern int __near mn67FA;
void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
void far helper_3(void);
int far exe_109269(int a)
{
    _asm {
        sub sp,0x4
        mov bx,[bp+0x6]
        add bx,bx
        add bx,bx
        les bx, [bx+0x67c2]
        add bx,0x28
        mov [bp-0x4],bx
        mov word ptr [bp-0x2],es
        test byte ptr es:[bx+0x1],0x80
        jnz short $+103
        mov ax,0xa
        push ax
        call far ptr helper_0
        add sp,0x2
        les bx, [bp-0x4]
        push word ptr es:[bx+0x8]
        mov ax,es:[bx+0x6]
        dec ax
        push ax
        push word ptr es:[bx+0x4]
        mov ax,es:[bx+0x2]
        inc ax
        push ax
        mov ax,0x2
        push ax
        call far ptr helper_1
        add sp,0xa
        mov ax,0x1
        push ax
        push word ptr [bp+0x6]
        call far ptr helper_2
        add sp,0x4
        mov ax,[bp+0x8]
        les bx, [bp-0x4]
        sub ax,es:[bx+0x4]
        add es:[bx+0x8],ax
        mov ax,[bp+0x8]
        mov es:[bx+0x4],ax
        push ax
        push word ptr es:[bx+0x2]
        push word ptr mn67FC
        push word ptr mn67FA
        call far ptr helper_3
L83:
    }
}
