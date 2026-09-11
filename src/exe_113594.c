
int far exe_113594(int a)
{
    _asm {
        sub sp,0x4
        cmp word ptr [bp+0x6],0x0
        jnz short $+10
        mov word ptr [bp-0x2],0x0
        jmp short $+56
        nop
L11:
        mov ax,[bp+0x6]
        cwd
        xor ax,dx
        sub ax,dx
        mov cx,ax
        mov ax,[bp+0x8]
        cwd
        xor ax,dx
        sub ax,dx
        mov bx,0x64
        imul bx
        cwd
        idiv cx
        cmp ax,0x29
        jnl short $+9
        mov word ptr [bp-0x2],0x2
        jmp short $+17
L37:
        cmp ax,0xf1
        jnl short $+7
        mov ax,0x1
        jmp short $+4
L41:
        xor ax,ax
L43:
        mov [bp-0x2],ax
L46:
        cmp word ptr [bp+0x6],0x0
        jl short $+19
        cmp word ptr [bp+0x8],0x0
        jnl short $+40
        cmp word ptr [bp-0x2],0x2
        jz short $+34
        mov ax,0x4
        jmp short $+23
L5D:
        cmp word ptr [bp+0x8],0x0
        jnl short $+8
        add word ptr [bp-0x2],0x4
        jmp short $+17
L69:
        cmp word ptr [bp-0x2],0x0
        jz short $+11
        mov ax,0x8
L72:
        sub ax,[bp-0x2]
        mov [bp-0x2],ax
L78:
        mov ax,[bp-0x2]
    }
}
