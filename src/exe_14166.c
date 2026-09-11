
int far exe_14166(int a)
{
    _asm {
        push ds
        mov cx,[bp+0xe]
        jcxz lbl2F
        mov bx,cx
        les di, [bp+0x6]
        mov si,di
        xor ax,ax
        repne scasb
        neg cx
        add cx,bx
        mov di,si
        lds si, [bp+0xa]
        repe cmpsb
        mov al,[si-0x1]
        xor cx,cx
        cmp al,es:[di-0x1]
        ja short $+6
        jz short $+6
        dec cx
        dec cx
lbl2D:
        not cx
lbl2F:
        mov ax,cx
        pop ds
    }
}
