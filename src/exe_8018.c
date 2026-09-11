void far helper_0(void);
int near exe_8018(int a)
{
    _asm {
        mov si,[bp+0x4]
        mov ax,0x200
        push ax
        call far ptr helper_0
        pop cx
        mov bx,si
        sub bx,0x5420
        add bx,0x5510
        or dx,dx
        jz short $+13
        or byte ptr [si+0xa],0x8
        mov word ptr [bx+0x2],0x200
        jmp short $+16
lbl27:
        or byte ptr [si+0xa],0x4
        mov word ptr [bx+0x2],0x1
        mov dx,ds
        lea ax,[bx+0x1]
lbl35:
        mov [si+0x2],dx
        mov [si],ax
        mov [si+0x8],dx
        mov [si+0x6],ax
        mov word ptr [si+0x4],0x0
    }
}
