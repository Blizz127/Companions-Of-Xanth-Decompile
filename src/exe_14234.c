
int far exe_14234(int a)
{
    _asm {
        push ds
        lds si, [bp+0x6]
        xor ax,ax
        cwd
        xor bx,bx
lbl0B:
        lodsb
        cmp al,0x20
        jz short $-3
        cmp al,0x9
        jz short $-7
        push ax
        cmp al,0x2d
        jz short $+6
        cmp al,0x2b
        jnz short $+3
lbl1D:
        lodsb
lbl1E:
        cmp al,0x39
        ja short $+33
        sub al,0x30
        jc short $+29
        shl bx,1
        rcl dx,1
        mov cx,bx
        mov di,dx
        shl bx,1
        rcl dx,1
        shl bx,1
        rcl dx,1
        add bx,cx
        adc dx,di
        add bx,ax
        adc dx,0x0
        jmp short $-34
lbl41:
        pop ax
        cmp al,0x2d
        xchg ax,bx
        jnz short $+9
        neg ax
        adc dx,0x0
        neg dx
lbl4E:
        pop ds
    }
}
