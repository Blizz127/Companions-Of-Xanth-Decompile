void far helper_0(void);
void far helper_1(void);
int far exe_111994(int a)
{
    _asm {
        les bx, [bp+0x6]
        cmp byte ptr es:[bx],0x3
        jz short $+8
        xor ax,ax
        jmp lblAF
        nop
lbl11:
        mov ax,es:[bx+0xe]
        cmp es:[bx+0xc],ax
        jg short $+70
        add word ptr es:[bx+0xc],0x4
        mov ax,es:[bx+0xc]
        add ax,ax
        add ax,ax
        sub dx,dx
        push dx
        push ax
        push word ptr es:[bx+0x12]
        push word ptr es:[bx+0x10]
        call far ptr helper_0
        add sp,0x8
        les bx, [bp+0x6]
        mov es:[bx+0x10],ax
        mov es:[bx+0x12],dx
        mov ax,dx
        or ax,es:[bx+0x10]
        jnz short $+18
        xor ax,ax
        les bx, [bp+0x6]
        mov es:[bx+0xe],ax
        mov es:[bx+0xc],ax
        jmp short $+83
        nop
lbl5F:
        les bx, [bp+0x6]
        les si, es:[bx+0x10]
        mov cx,es
        mov es, [bp+0x8]
        lea dx,[bx+0xe]
        mov di,bx
        mov bx,dx
        mov ax,dx
        mov bx,es:[bx]
        add bx,bx
        add bx,bx
        mov dx,es
        mov es,cx
        mov cx,[bp+0xa]
        mov es:[bx+si],cx
        mov bx,ax
        mov es,dx
        mov si,es:[bx]
        add si,si
        add si,si
        mov cx,[bp+0xc]
        les bx, es:[di+0x10]
        mov es:[bx+si+0x2],cx
        mov bx,ax
        mov es,dx
        inc word ptr es:[bx]
        push dx
        push di
        call far ptr helper_1
        add sp,0x4
        mov ax,0x1
lblAF:
    }
}
