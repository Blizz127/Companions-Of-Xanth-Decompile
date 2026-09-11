
int far exe_20038(int a)
{
    _asm {
        mov cx,ds
        lds bx, [bp+0x6]
        mov dx,bx
        jmp short $+13
L09:
        sub al,0x61
        cmp al,0x1a
        jnc short $+6
        add al,0x41
        mov [bx],al
L13:
        inc bx
L14:
        mov al,[bx]
        or al,al
        jnz short $-15
        xchg ax,dx
        mov dx,ds
        mov ds,cx
    }
}
