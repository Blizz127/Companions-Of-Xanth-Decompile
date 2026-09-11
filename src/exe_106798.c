void far helper_0(void);
void far helper_1(void);
void far helper_2(void);
int far exe_106798(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+106
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x0
        jz short $+97
        mov ax,es:[bx+0x12]
        or ax,es:[bx+0x10]
        jz short $+57
        mov ax,es:[bx+0xc]
        mov dx,es:[bx+0xe]
        les bx, es:[bx+0x10]
        mov es:[bx+0x18],ax
        mov es:[bx+0x1a],dx
        les bx, [bp+0x6]
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        call far ptr helper_0
        les bx, [bp+0x6]
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        call far ptr helper_1
        jmp short $+26
        nop
L55:
        mov ax,es:[bx+0xe]
        or ax,es:[bx+0xc]
        jz short $+15
        push word ptr es:[bx+0xe]
        push word ptr es:[bx+0xc]
        call far ptr helper_2
L6C:
        les bx, [bp+0x6]
        mov byte ptr es:[bx],0x0
L73:
    }
}
