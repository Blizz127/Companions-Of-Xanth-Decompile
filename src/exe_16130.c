void far helper_0(void);
int far exe_16130(int a)
{
    _asm {
        mov ah,0x2a
        int 0x21
        mov bx,dx
        mov si,cx
        mov ah,0x2c
        int 0x21
        mov ah,0x0
        mov al,dh
        push ax
        mov al,cl
        push ax
        mov al,ch
        push ax
        push ax
        mov ah,0x2a
        int 0x21
        cmp bx,dx
        pop ax
        jz short $+10
        cmp al,0x17
        jnz short $+6
        mov dx,bx
        mov cx,si
lbl2A:
        mov ah,0x0
        mov al,dl
        push ax
        mov al,dh
        push ax
        sub cx,0x7bc
        push cx
        call far ptr helper_0
        add sp,0xc
        cmp word ptr [bp+0x8],0x0
        jz short $+12
        les bx, [bp+0x6]
        mov es:[bx+0x2],dx
        mov es:[bx],ax
lbl4F:
    }
}
