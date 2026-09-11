void far helper_0(void);
void far helper_1(void);
int far exe_111574(int a)
{
    _asm {
        sub sp,0x2
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jnz short $+58
        mov ax,0x14
        cwd
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        mov es,dx
        mov bx,ax
        mov [bp+0x6],ax
        mov word ptr [bp+0x8],es
        mov word ptr es:[bx+0x8],0xffff
        mov word ptr es:[bx+0x6],0xffff
        mov word ptr es:[bx+0x4],0xffff
        mov word ptr es:[bx+0x2],0xffff
        mov word ptr [bp-0x2],0x1
        jmp short $+8
        nop
L43:
        mov word ptr [bp-0x2],0x0
L48:
        mov ax,[bp+0x8]
        or ax,[bp+0x6]
        jz short $+92
        mov ax,[bp+0xa]
        add ax,ax
        add ax,ax
        sub dx,dx
        push dx
        push ax
        call far ptr helper_0
        add sp,0x4
        les bx, [bp+0x6]
        mov es:[bx+0x10],ax
        mov es:[bx+0x12],dx
        mov ax,dx
        or ax,es:[bx+0x10]
        jz short $+29
        les bx, [bp+0x6]
        mov byte ptr es:[bx],0x3
        mov byte ptr es:[bx+0x1],0x0
        mov ax,[bp+0xa]
        mov es:[bx+0xc],ax
        mov word ptr es:[bx+0xe],0x0
        jmp short $+27
L91:
        cmp word ptr [bp-0x2],0x0
        jz short $+13
        push word ptr [bp+0x8]
        push word ptr [bp+0x6]
        call far ptr helper_1
LA2:
        sub ax,ax
        mov [bp+0x8],ax
        mov [bp+0x6],ax
LAA:
        mov ax,[bp+0x6]
        mov dx,[bp+0x8]
    }
}
